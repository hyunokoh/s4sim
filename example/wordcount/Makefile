#
S4SIM_HOME = ../..
CFLAGS = -g
INCLUDE=-I${S4SIM_HOME}/include
CC = gcc
CPP = g++

ARMCC = arm-linux-gnueabihf-gcc-4.8

all : wordcount wordcount_isp

wordcount : wordcount.c ${S4SIM_HOME}/src/isp_socket.c
	$(CC) $(CFLAGS) -o $@ $^ -lpthread $(INCLUDE)

wordcount_isp : wordcount_isp.c ${S4SIM_HOME}/src/s4lib.c
	$(ARMCC) -o $@ $^ -static $(INCLUDE)

clean:
	rm wordcount
