CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

all: calculator

calculator: Calculator.o main.o
	$(CXX) $(CXXFLAGS) -o calculator Calculator.o main.o

Calculator.o: Calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c calculator.cpp

main.o: main.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f calculator *.o

