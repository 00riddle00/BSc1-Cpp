CC=g++
CFLAGS=-Wall -Wextra -g -lm -std=c++11 -DNDEBUG

stringStackTest: stringStackTest.cpp stringStack.o MyString.o
	$(CC) $(CFLAGS) -o stringStackTest stringStackTest.cpp stringStack.o MyString.o

stringStack.o: stringStack.cpp stringStack.h MyString.h
	$(CC) $(CFLAGS) stringStack.cpp -c

MyString.o: MyString.cpp MyString.h
	$(CC) $(CFLAGS) MyString.cpp -c

clean: 
	rm -rf MyString stringStack.o MyString.o

