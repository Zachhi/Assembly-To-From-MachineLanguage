//Zachary Chi
//628001407
//An Aggie does not lie, cheat or steal or tolerate those who do.
#ifndef TABLE_H
#define TABLE_H

#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> createSymbolTable(string fileName);
bool isNumber(const string& str);
unordered_map<string, string> createCompTable(string fileName);
unordered_map<string, string> createDestTable(string fileName);
unordered_map<string, string> createJumpTable(string fileName);
unordered_map<string, string> revCreateCompTable(string fileName);
unordered_map<string, string> revCreateDestTable(string fileName);
unordered_map<string, string> revCreateJumpTable(string fileName);
#endif