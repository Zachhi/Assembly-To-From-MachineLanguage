CC = g++
CXX = -std=c++17

all: main

clean: 
	rm -f *.gcov *.gcda *.gcno a.out

main: 
	$(CC) $(CXX) -o run assembly-disassembly/table.cpp assembly-disassembly/table.h assembly-disassembly/assembler.cpp assembly-disassembly/assembler.h assembly-disassembly/disassembler.cpp assembly-disassembly/disassembler.h main.cpp