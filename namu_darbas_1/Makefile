CC=g++
CFLAGS=-Wall -Wextra -g -lm 

program: program.cpp helpers.o filter.o sorting.o
	$(CC) $(CFLAGS) -o program program.cpp helpers.o filter.o sorting.o 

sorting.o: database.h sorting.cpp sorting.h

filter.o: database.h filter.cpp filter.h 

helpers.o: helpers.h helpers.cpp

clean:
	rm -f program helpers.o sorting.o filter.o

rebuild: clean program

