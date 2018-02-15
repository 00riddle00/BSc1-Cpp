main: main.o automobilis.o mystack.h
	g++ main.o automobilis.o mystack.h -o main

main.o: main.cpp automobilis.h mystack.h
	g++ main.cpp -c

automobilis.o: automobilis.cpp automobilis.h
	g++ automobilis.cpp -c

#mystack.o: mystack.cpp mystack.h
	#g++ mystack.cpp -c

clean:
	rm main.o automobilis.o mystack.o main

#tstack: tstack.o mystack.o
	#g++ tstack.o mystack.o -o tstack

#tstack.o: tstack.cpp mystack.h
	#g++ tstack.cpp -c

#clean:
	#rm tstack.o mystack.o tstack
