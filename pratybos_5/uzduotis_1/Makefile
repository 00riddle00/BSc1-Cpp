main: main.o test1.o test2.o
	g++ main.o test1.o test2.o -o main

main.o: main.cpp test1.h test2.h
	g++ main.cpp -c

test2.o: test2.cpp test2.h
	g++ test2.cpp -c

test1.o: test1.cpp test1.h
	g++ test1.cpp -c

clean:
	rm main.o test1.o main
