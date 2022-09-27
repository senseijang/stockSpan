CC = g++
CXXFLAGS = -std=c++11 -static -g

brute: bruteSpan.o
	./bruteSpan.o

bruteSpan.o: bruteSpan.cpp
	${CC} ${CXXFLAGS} bruteSpan.cpp -o bruteSpan.o