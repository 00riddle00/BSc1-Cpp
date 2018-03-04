CC=g++
CFLAGS=-Wall -Wextra -g -lm -std=c++11

program: program.cpp write_to_binary_file.o load_from_binary_file.o
	$(CC) $(CFLAGS) -o program program.cpp write_to_binary_file.o load_from_binary_file.o

load_from_binary_file.o: load_from_binary_file.cpp load_from_binary_file.h
	$(CC) $(CFLAGS) load_from_binary_file.cpp -c

write_to_binary_file.o: write_to_binary_file.cpp write_to_binary_file.h
	$(CC) $(CFLAGS) write_to_binary_file.cpp -c

clean:
	rm -f program write_to_binary_file.o load_from_binary_file.o

rebuild: clean program

