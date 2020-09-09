main: main.o automobilis.o mystack.h
	g++ main.o automobilis.o mystack.h -o main

main.o: main.cpp automobilis.h mystack.h
	g++ main.cpp -c

automobilis.o: automobilis.cpp automobilis.h
	g++ automobilis.cpp -c

mystack.h: automobilis.h

clean:
	rm main.o automobilis.o mystack.o main
