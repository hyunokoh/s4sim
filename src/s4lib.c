// Smart Solid State System (S4)
// It is a socket server


#include "s4.h"

FILE *
s4_fopen(const char * filename, const char * mode)
{
        return fopen(filename,mode);
}

int
s4_fseek(FILE *stream, long offset, int whence)
{
        return fseek(stream, offset, whence);
}

void
s4_rewind(FILE *stream)
{
        (void)s4_fseek(stream, 0L, SEEK_SET);
}

size_t
s4_fread(void * ptr, size_t size, size_t nitems, FILE * stream)
{
        return fread(ptr,size,nitems,stream);
}

size_t
s4_fwrite(const void * ptr, size_t size, size_t nitems, FILE * stream)
{
        return fwrite(ptr,size,nitems,stream);
}
