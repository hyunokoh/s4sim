// Test ARM application in ISSD

#include <stdio.h>
#include <string.h>
#include "s4.h"
#include <stdlib.h>

// This is a just sample code.
// In an ISSD, the file access should be a page unit 
// and processing threads will read the page.
int countWord(const char* text, int textLen, const char* token, int tokenLen)
{
	int count = 0;
	int i,j;
	for(i=0; i<textLen-tokenLen; i++) {
		for(j=0; j<tokenLen; j++) {
			if(text[i+j] != token[j])
				break;
		}
		if(j==tokenLen) count++;
	}

	return count;
}

int main(int argc, const char* argv[])
{
        FILE* ifp;
	int n;

	s4_init_simulation();

	if(argc<3) return -1;

	ifp = s4_fopen(argv[2],"r");

	// search
	int count = 0;
	int tokenLen = strlen(argv[1]);
	while((n=s4_pageread(0,S4_NUM_BUFFERS,ifp))>0) {
		int i;
		for(i=0; i<n; i++) {
			count += countWord(&s4_buffer[i], S4_PAGE_SIZE, argv[1], tokenLen);
		}
	}

	printf("count = %d\n",count);

	s4_wrapup_simulation();
}
