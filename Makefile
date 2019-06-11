CC=gcc
CFLAGS=-I/usr/include/

all: hello.o
	$(CC) -o libepoxyhello hello.o -lepoxy
