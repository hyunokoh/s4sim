// Test ARM application in ISSD

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "s4.h"
#include <stdlib.h>

// This is a just sample code.
// In an ISSD, the file access should be a page unit 
// and processing threads will read the page.

struct countWordArgument {
	char* text;
	const char* token;
	int textLen;
	int tokenLen;
};

void *countWord(void* theArg)
{
	struct countWordArgument* arg = (struct countWordArgument*)theArg;
	int count = 0;
	int i,j;
	for(i=0; i<arg->textLen; i++) {
		for(j=0; j<arg->tokenLen; j++) {
			if(arg->text[i+j] != arg->token[j])
				break;
		}
		if(j==arg->tokenLen) count++;
	}

	return (void*)count;
}

int main(int argc, const char* argv[])
{
        FILE* ifp;
	int n;

	if(argc<3) return -1;

	ifp = s4_fopen(argv[2],"r");
	//printf("%s %s\n", argv[1],argv[2]);

	// search
	int count = 0;
	int tokenLen = strlen(argv[1]);
	pthread_t p_thread[NUM_BUFFERS];
	pthread_attr_t attr;
	struct countWordArgument arg[NUM_BUFFERS];
	while((n=s4_pageread(0,NUM_BUFFERS,ifp))>0) {
		int i;
		for(i=0; i<n; i++) {
			arg[i].text = &s4Buffer[i];	
			arg[i].textLen = PAGE_SIZE;
			arg[i].token = argv[1];
			arg[i].tokenLen = tokenLen;
			pthread_create(&p_thread[i], NULL, countWord, (void *)&arg[i]);	
		}
		for(i=0; i<n; i++) {
			int result;
			pthread_join(p_thread[i], (void**)&result);
			count += result;
		}
	}

	printf("count = %d\n",count);
}
