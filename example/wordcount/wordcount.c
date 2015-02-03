// Test application for ISP

#include <stdio.h>
#include <stdlib.h>
#include "isp.h"


int main(int argc, const char* argv[])
{
        isp_device_id device;
        FILE* ifp;
	int n;
	char buffer[1024];
	int cycle;

        //ispGetDeviceIDs(NULL, ISP_DEVICE_TYPE_STORAGE, 1, &device, NULL);

        // read an ISP binary file from argument
#ifndef PAR
	cycle = ispRunBinaryFile(device, "./wordcount_isp", "int wordcount_isp", "output.txt");
#else
	cycle = ispRunBinaryFile(device, "./wordcount_par_isp", "int wordcount.c", "output.txt");
#endif
	// print out the result from the ISP program
	system("cat output.txt");

	printf("ISP cycle = %d\n", cycle);
}
