all: build

build: main.o knights_tour.o
	g++ -Wall main.o knights_tour.o -o a.out

main.o: main.cpp knights_tour.h
	g++ -c main.cpp knights_tour.h

knights_tour.o: knights_tour.h knights_tour.cpp
	g++ -c knights_tour.h knights_tour.cpp

clean:
	rm -rf *.o a.out knights_tour.h.gch