CC=g++
CFLAGS=-Wall -Wextra -Wvla -g -lm -std=c++11 -DNDEBUG

testStack_B: testStack_B.cpp Stack.o
	$(CC) $(CFLAGS) -o testStack_B testStack_B.cpp Stack.o

testStack_A: testStack_A.cpp Stack.o
	$(CC) $(CFLAGS) -o testStack_A testStack_A.cpp Stack.o

Stack.o: Stack.h Stack.cpp
	$(CC) $(CFLAGS) Stack.cpp -c

clean: 
	rm -rf Stack.o testStack_A testStack_B

