

output: hash.o main.o
	g++ -o output hash.o main.o

main.o: main.cpp 
	g++ -c main.cpp
hash.o: hash.cpp
	g++ -c hash.cpp

clean:
	rm -rf *.o output	
