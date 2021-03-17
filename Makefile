CC=gcc

TARGET=main

all:
	$(CC) -o $(TARGET) main.c array.c 