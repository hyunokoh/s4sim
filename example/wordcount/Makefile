#
S4SIM_HOME = ../..
CFLAGS = -g

INCLUDE=-I${S4SIM_HOME}/include
PTHREAD = ${S4SIM_HOME}/external/m5threads
CC = gcc
CPP = g++

ARMCC = arm-linux-gnueabihf-gcc-4.8
ARMFLAGS = -march=armv7-a -marm

all : wordcount wordcount_isp wordcount_par wordcount_par_isp

wordcount : wordcount.c ${S4SIM_HOME}/src/isp_socket.c
	$(CC) $(CFLAGS) -o $@ $^ -lpthread $(INCLUDE)

wordcount_isp : wordcount_isp.c ${S4SIM_HOME}/src/s4lib.c 
	$(ARMCC) ${ARMFLAGS} -o $@ $^ -static $(INCLUDE)

wordcount_par : wordcount.c ${S4SIM_HOME}/src/isp_socket.c
	$(CC) $(CFLAGS) -DPAR -o $@ $^ -lpthread $(INCLUDE)

wordcount_par_isp : wordcount_par_isp.c ${S4SIM_HOME}/src/s4lib.c ${PTHREAD}/pthread.c
	$(ARMCC) ${ARMFLAGS} -o $@ $^ -static $(INCLUDE)


clean:
	rm wordcount
	rm wordcount_par
	rm wordcount_isp
	rm wordcount_par_isp
