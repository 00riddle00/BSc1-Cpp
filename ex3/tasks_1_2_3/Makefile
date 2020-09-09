main: main.o racionalus_sk.o
	g++ main.o racionalus_sk.o -o main

main.o: main.cpp racionalus_sk.h
	g++ main.cpp -c

racionalus_sk.o: racionalus_sk.cpp racionalus_sk.h
	g++ racionalus_sk.cpp -c

clean:
	rm main.o racionalus_sk.o main
