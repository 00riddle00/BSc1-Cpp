CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11

tauto: tauto.o automobilis.o write_to_binary_file.o load_from_binary_file.o write_to_text_file.o load_from_text_file.o
	$(CC) $(CFLAGS) tauto.o automobilis.o write_to_binary_file.o load_from_binary_file.o write_to_text_file.o load_from_text_file.o -o tauto

tauto.o: tauto.cpp automobilis.h write_to_binary_file.h load_from_binary_file.h write_to_text_file.h load_from_text_file.h
	$(CC) $(CFLAGS) tauto.cpp -c

load_from_text_file.o: load_from_text_file.cpp load_from_text_file.h
	$(CC) $(CFLAGS) load_from_text_file.cpp -c

write_to_text_file.o: write_to_text_file.cpp write_to_text_file.h
	$(CC) $(CFLAGS) write_to_text_file.cpp -c

load_from_binary_file.o: load_from_binary_file.cpp load_from_binary_file.h
	$(CC) $(CFLAGS) load_from_binary_file.cpp -c

write_to_binary_file.o: write_to_binary_file.cpp write_to_binary_file.h
	$(CC) $(CFLAGS) write_to_binary_file.cpp -c

automobilis.o: automobilis.cpp automobilis.h
	$(CC) $(CFLAGS) automobilis.cpp -c

clean:
	rm -f automobilis.o tauto.o tauto
