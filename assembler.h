//Zachary Chi
//628001407
//An Aggie does not lie, cheat or steal or tolerate those who do.
#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include <string>
#include <unordered_map>
using namespace std;
void assemble(string fileName); //main function that assmebles
string Ainst(string line); //returns if something is A inst
bool isAinst(string line); //returns the converted  A inst
bool isCinst(string line, unordered_map<string, string> dest, unordered_map<string, string> jump, unordered_map<string, string> comp); //returns if something is C inst
string Cinst(string line, unordered_map<string, string> dest, unordered_map<string, string> jump, unordered_map<string, string> comp); //returns converted C inst
#endif