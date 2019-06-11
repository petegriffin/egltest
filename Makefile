#CC=aarch64-linux-gnu-gcc
#CFLAGS=-I/usr/include/
#LDFLAGS=-L

all: hello.o
	$(CC) -o libepoxyhello hello.o -lepoxy
