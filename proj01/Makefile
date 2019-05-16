proj1.out: main.o stringArr.cc
	g++ main.cpp stringArr.cpp

main.o: main.cpp
	g++ -c main.cpp

stringArr.o: stringArr.cpp stringArr.hpp
	g++ -c stringArr.cpp

clean:
	rm *.o proj1.out
