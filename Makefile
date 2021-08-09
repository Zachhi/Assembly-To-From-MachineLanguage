CC = g++
CXX = -std=c++17

all: main

clean: 
	rm -f *.gcov *.gcda *.gcno a.out

main: 
	$(CC) $(CXX) -o run table.cpp table.h assembler.cpp assembler.h disassembler.cpp disassembler.h main.cpp