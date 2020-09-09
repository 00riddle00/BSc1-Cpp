tstack: tstack.o mystack.o
	g++ tstack.o mystack.o -o tstack

tstack.o: tstack.cpp mystack.h
	g++ tstack.cpp -c

mystack.o: mystack.cpp mystack.h
	g++ mystack.cpp -c

clean:
	rm tstack.o mystack.o tstack
