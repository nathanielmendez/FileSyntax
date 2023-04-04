CXX=g++              # C++ compiler
CXXFLAGS=-std=c++11  # C++11 standard

all: Texitor

Texitor: Texitor.o create.o parse.o
	$(CXX) -o Texitor Texitor.o create.o parse.o

create.o: create.cpp create.h
	$(CXX) -c -o create.o create.cpp

parse.o: parse.cpp parse.h
	$(CXX) -c -o parse.o parse.cpp

Texitor.o: Texitor.cpp create.h parse.h
	$(CXX) -c -o Texitor.o Texitor.cpp

clean:
	rm -f Texitor *.o