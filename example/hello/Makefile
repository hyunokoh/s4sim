#
S4SIM_HOME = ../..
CFLAGS = -g
INCLUDE=-I${S4SIM_HOME}/include
CC = gcc
CPP = g++

all : hello

hello : hello.c ${S4SIM_HOME}/src/isp_socket.c
	$(CC) $(CFLAGS) -o $@ $^ -lpthread $(INCLUDE)

clean:
	rm hello
