proj3.x: in2post.o
	g++ -o proj3.x in2post.o

in2post.o: in2post.cpp Stack.hpp
	g++ -std=c++11 -c in2post.cpp

clean:
	-rm *.o proj3.x
