CC=g++
CFLAGS=-Wall -Wextra -Wvla -g -lm -std=c++11 -DNDEBUG

testTime: testTime.cpp time.o
	$(CC) $(CFLAGS) -o testTime testTime.cpp time.o

time.o: time.h time.cpp
	$(CC) $(CFLAGS) time.cpp -c

clean: 
	rm -rf time.o testTime

