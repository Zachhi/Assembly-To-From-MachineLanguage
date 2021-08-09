//Zachary Chi

#include <iostream>
#include <cmath>
#include "assembly-disassembly/table.h"
#include "assembly-disassembly/assembler.h"
#include "assembly-disassembly/disassembler.h"
using std::cout; 
using std::endl;

int main () {
//EXAMPLES:

// Assembly
//assemble("testProgram.asm");

// Disassembly
disassemble("testProgram.hack");
return 0;
}