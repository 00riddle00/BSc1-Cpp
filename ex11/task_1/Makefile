CC=g++
CFLAGS=-Wall -Wextra -Wvla -g -lm -std=c++11 -DNDEBUG

testArray: testArray.cpp Array.o
	$(CC) $(CFLAGS) -o testArray testArray.cpp Array.o

Array.o: Array.h Array.cpp
	$(CC) $(CFLAGS) Array.cpp -c

clean: 
	rm -rf Array.o

