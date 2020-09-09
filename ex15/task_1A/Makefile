CC=g++
CFLAGS=-Wall -Wextra -Wvla -g -lm -std=c++11 -DNDEBUG

main: main.cpp Namespace.o
	$(CC) $(CFLAGS) -o main main.cpp Namespace.o

Namespace.o: Namespace1.h Namespace2.h Namespace.cpp
	$(CC) $(CFLAGS) Namespace.cpp -c

clean: 
	rm -rf Namespace.o main

