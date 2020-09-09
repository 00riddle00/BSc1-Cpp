CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11


tauto: tauto.o automobilis.o
	$(CC) $(CFLAGS) tauto.o automobilis.o -o tauto

tauto.o: tauto.cpp automobilis.h
	$(CC) $(CFLAGS) tauto.cpp -c

tstack: automobilis.o tstack.o object.o mystack.o
	$(CC) $(CFLAGS) automobilis.o tstack.o object.o mystack.o -o tstack

tstack.o: automobilis.h tstack.cpp 
	$(CC) $(CFLAGS) tstack.cpp -c

object.o: object.h object.cpp
	$(CC) $(CFLAGS) object.cpp -c

#mystack.o: automobilis.o mystack.cpp mystack.h 
mystack.o: mystack.cpp mystack.h object.h
	$(CC) $(CFLAGS) mystack.cpp -c

automobilis.o: automobilis.cpp automobilis.h
	$(CC) $(CFLAGS) automobilis.cpp -c

clean:
	rm -f automobilis.o mystack.o tstack.o tstack tauto.o tauto
