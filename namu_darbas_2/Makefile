CC=g++
CFLAGS=-Wall -Wextra -g -lm -std=c++11 -DNDEBUG

program: program.cpp write_to_binary_file.o load_from_binary_file.o input.o car.o connection.o Helpers.o table.o filter.o sorting.o
	$(CC) $(CFLAGS) -o program program.cpp write_to_binary_file.o load_from_binary_file.o input.o car.o connection.o Helpers.o table.o filter.o sorting.o

table.o: table.h table.cpp 
	$(CC) $(CFLAGS) table.cpp -c

connection.o: connection.h connection.cpp 
	$(CC) $(CFLAGS) connection.cpp -c

sorting.o: sorting.h sorting.cpp
	$(CC) $(CFLAGS) sorting.cpp -c

filter.o: filter.h filter.cpp
	$(CC) $(CFLAGS) filter.cpp -c

car.o: car.h car.cpp
	$(CC) $(CFLAGS) car.cpp -c

input.o: input.h input.cpp
	$(CC) $(CFLAGS) input.cpp -c

load_from_binary_file.o: load_from_binary_file.cpp load_from_binary_file.h
	$(CC) $(CFLAGS) load_from_binary_file.cpp -c

write_to_binary_file.o: write_to_binary_file.cpp write_to_binary_file.h
	$(CC) $(CFLAGS) write_to_binary_file.cpp -c

Helpers.o: Helpers.h Helpers.cpp
	$(CC) $(CFLAGS) Helpers.cpp -c

clean:
	rm -f program write_to_binary_file.o load_from_binary_file.o input.o car.o connection.o Helpers.o table.o filter.o

rebuild: clean program

