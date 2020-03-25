
FLAG=-g -Iinc -Wall -pedantic -std=c++0x

_start_: sorting
	./sorting

sorting: obj obj/main.o
	g++ -Wall -pedantic -std=c++0x -o sorting obj/main.o 

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Vector.hh inc/Quicksort.hh  inc/Matrix.hh inc/Mergesort.hh inc/Heapsort.hh inc/Introsort.hh 
	g++ -c ${FLAG} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o

