main: main.o automobilis.o
	g++ main.o automobilis.o -o main

main.o: main.cpp automobilis.h
	g++ main.cpp -c

automobilis.o: automobilis.cpp automobilis.h
	g++ automobilis.cpp -c

clean:
	rm main.o automobilis.o main
