CC=g++
CFLAGS=-Wall -Wextra -g -lm 

program: program.cpp helpers.o binary_file.o filter.o sorting.o
	$(CC) $(CFLAGS) -o program program.cpp helpers.o binary_file.o filter.o sorting.o 

binary_file.o: helpers.o binary_file.h binary_file.cpp 

sorting.o: database.h sorting.cpp sorting.h

filter.o: database.h filter.cpp filter.h 

helpers.o: helpers.h helpers.cpp

clean:
	rm -f program helpers.o binary_file.o sorting.o filter.o

rebuild: clean program

