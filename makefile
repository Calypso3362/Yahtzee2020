normal.o: normal.cpp normal.h
	g++ -c normal.cpp

creative.o: creative.cpp creative.h
	g++ -c creative.cpp

main.o: main.cpp normal.h creative.h
	g++ -c  main.cpp

main: normal.o creative.o main.o
	g++ normal.o creative.o main.o -o main

clean:
	rm -f *.o main

.PHONY: clean