# Makefile for 580 p3 sudoku backtracking
sudoku: sudoku.o main.o
	g++ -Wall -pedantic -g -o sudoku sudoku.o main.o

main.o: main.cpp sudoku.h
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp

sudoku.o: sudoku.h sudoku.cpp
	g++ -Wall -pedantic -g -std=c++11 -c sudoku.cpp

clean:
	rm -f sudoku.o main.o sudoku sudoku.exe
