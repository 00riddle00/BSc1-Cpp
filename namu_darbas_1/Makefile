CC=g++
CFLAGS=-Wall -Wextra -g -lm -std=c++11

#program: program.cpp helpers.o filter.o sorting.o
   # $(CC) $(CFLAGS) -o program program.cpp helpers.o filter.o sorting.o 
program: program.cpp helpers.o 
	$(CC) $(CFLAGS) -o program program.cpp helpers.o 

#sorting.o: database.h sorting.cpp sorting.h

#filter.o: database.h filter.cpp filter.h 

helpers.o: helpers.h helpers.cpp

clean:
	rm -f program helpers.o 

rebuild: clean program

