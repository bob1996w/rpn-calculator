.PHONY: all
all: calculator

calculator: main.cpp *.hpp
	g++ --std=c++11 main.cpp -o output

.PHONY: clean
clean:
	rm -f *.o output