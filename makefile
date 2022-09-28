CC = g++
CXXFLAGS = -std=c++11 -static -g

stack: stackSpan.o
	./stackSpan.o

brute: bruteSpan.o
	./bruteSpan.o

bruteSpan.o: bruteSpan.cpp
	${CC} ${CXXFLAGS} bruteSpan.cpp -o bruteSpan.o

stackSpan.o: stackSpan.cpp
	${CC} ${CXXFLAGS} stackSpan.cpp -o stackSpan.o