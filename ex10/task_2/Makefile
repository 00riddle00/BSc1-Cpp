CC=g++
CFLAGS=-Wall -Wextra -g -lm -std=c++11 -DNDEBUG

QuoterTest: QuoterTest.cpp Quoter.o
	$(CC) $(CFLAGS) -o QuoterTest QuoterTest.cpp Quoter.o

Quoter.o: Quoter.cpp Quoter.h
	$(CC) $(CFLAGS) Quoter.cpp -c

clean: 
	rm -rf QuoterTest Quoter.o

