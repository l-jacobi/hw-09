CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++17 -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  cities tsp

test: test.o
	$(CXX) $(LDFLAGS) -o $@ $^

test.o: test.cpp
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

test_cities: cities.o test_cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

cities: cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

tsp: cities.o tsp.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o *.out test_cities

test: all
	./test_huffman
	./test_bitio
