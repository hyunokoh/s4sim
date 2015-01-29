// Test ARM application in ISSD

#include <stdio.h>
#include <string.h>
#include "s4.h"


// This is a just sample code.
// In an ISSD, the file access should be a page unit 
// and processing threads will read the page.

int main(int argc, const char* argv[])
{
        FILE* ifp;
	int n;
	char buffer[1024];

	if(argc<3) return -1;

	ifp = s4_fopen(argv[2],"r");
	printf("%s %s\n", argv[1],argv[2]);

	// search
	int count = 0;
	int tokenLen = strlen(argv[1]);
	while((n=fread(buffer,sizeof(char),1024,ifp))>0) {
		int i,j;
		for(i=0; i<n; i++) {
			for(j=0; j<tokenLen; j++) {
				if(buffer[i+j] != argv[1][j])
					break;
			}
			if(j==tokenLen) count++;
		}
	}

	printf("count = %d\n",count);
}
