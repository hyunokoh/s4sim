
#ifndef _S4LIB_
#define _S4LIB_

#include <stdio.h>

// File related data structure
#define PAGE_SIZE 1024  
#define NUM_BUFFERS 1
char s4Buffer[PAGE_SIZE*NUM_BUFFERS];

// File related functions
FILE *
s4_fopen(const char * filename, const char * mode);

int
s4_fseek(FILE *stream, long offset, int whence);

void
s4_rewind(FILE *stream);

size_t
s4_fread(void * ptr, size_t size, size_t nitems, FILE * stream);

size_t
s4_pageread(size_t pageStartNumber, size_t numPages, FILE * stream);

size_t
s4_fwrite(const void * ptr, size_t size, size_t nitems, FILE * stream);
#endif
