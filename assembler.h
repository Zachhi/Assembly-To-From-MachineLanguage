//Zachary Chi
//628001407
//An Aggie does not lie, cheat or steal or tolerate those who do.
#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include <string>
#include <unordered_map>
using namespace std;
void assemble(string fileName);
string Ainst(string line);
bool isAinst(string line);
bool isCinst(string line, unordered_map<string, string> dest, unordered_map<string, string> jump, unordered_map<string, string> comp);
string Cinst(string line, unordered_map<string, string> dest, unordered_map<string, string> jump, unordered_map<string, string> comp);
#endif