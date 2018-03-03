CC=g++
CFLAGS=-Wall -Wextra -g -lm -std=c++11

#program: program.cpp helpers.o filter.o sorting.o
   # $(CC) $(CFLAGS) -o program program.cpp helpers.o filter.o sorting.o 
program: program.cpp helpers.o write_to_binary_file.o load_from_binary_file.o
	$(CC) $(CFLAGS) -o program program.cpp helpers.o write_to_binary_file.o load_from_binary_file.o

#sorting.o: database.h sorting.cpp sorting.h

#filter.o: database.h filter.cpp filter.h 

load_from_binary_file.o: load_from_binary_file.cpp load_from_binary_file.h
	$(CC) $(CFLAGS) load_from_binary_file.cpp -c

write_to_binary_file.o: write_to_binary_file.cpp write_to_binary_file.h
	$(CC) $(CFLAGS) write_to_binary_file.cpp -c


helpers.o: helpers.h helpers.cpp
	$(CC) $(CFLAGS) helpers.cpp -c

clean:
	rm -f program helpers.o write_to_binary_file.o load_from_binary_file.o

rebuild: clean program

