all: do-test clean 


5.o: 5.cpp 5.hpp
#     g++ -c 5.cpp

5test.o: 5test.cpp 5.hpp
#     g++ -c 5test.cpp

a.out: 5test.o 5.o
	g++ 5test.o 5.o

do-test: a.out
	./a.out
