//Zachary Chi
//628001407
//An Aggie does not lie, cheat or steal or tolerate those who do.

#include "table.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

unordered_map<string, int> createSymbolTable(string fileName)
{
    unordered_map<string, int> symbolTable;

    //declare initial values 
    symbolTable["SP"] = 0;
    symbolTable["LCL"] = 1;
    symbolTable["ARG"] = 2;
    symbolTable["THIS"] = 3;
    symbolTable["THAT"] = 4;

    for(int i = 0; i < 16; i++)
        symbolTable["R" + to_string(i)] = i;
    
    symbolTable["SCREEN"] = 16384;
    symbolTable["KBD"] = 24576;

    //open the file here
    string dummy;
    ifstream file (fileName);
    int pc = 0;
    int nextAddy = 16;
    if(file.is_open())
    {
        while(getline(file, dummy))
        {
            //remove comments and spaces for ()
            string cleaned = dummy.substr(0, dummy.find("//"));
            cleaned.erase(std::remove_if(cleaned.begin(), cleaned.end(), ::isspace), cleaned.end());

            //remove comments and spaces for @
            string cleaned2 = cleaned;

            //if cleaned is a (label)
            if(cleaned.length()!= 0 && cleaned.at(0) == '(' && cleaned.at(cleaned.length()-1) == ')')
            {
                //remove the "(" and ")"
                cleaned = cleaned.substr(1, cleaned.length()-2);

                //if "cleaned" is not in symbol table
                if(symbolTable.find(cleaned) == symbolTable.end())
                {
                    symbolTable[cleaned] = pc;
                }
            }

            //if is @"123"
            if(cleaned2.length() != 0 && cleaned2.at(0) == '@')
            {
                string Ainst = cleaned2.substr(1, cleaned2.length()-1);
                //if it is a variable
                if(!isNumber(Ainst))
                {
                    //if not in table
                    if(symbolTable.find(Ainst) == symbolTable.end())
                    {
                        symbolTable[Ainst] = nextAddy;
                        nextAddy += 1;
                    }
                }
            } 

            //if line is instruction, inc pc
            if(cleaned != "")
                pc += 1;
        }
        file.close();
    }
    else
        cout << "Cannot open file" << endl;
    
    
    return symbolTable;
}

unordered_map<string, string> createCompTable(string fileName)
{
    unordered_map<string, string> compTable;
    compTable["0"] = "0101010";
    compTable["1"] = "0111111";
    compTable["-1"] = "0111010";
    compTable["D"] = "0001100";
    compTable["A"] = "0110000";
    compTable["!D"] = "0001101";
    compTable["!A"] = "0110001";
    compTable["-D"] = "0001111";
    compTable["-A"] = "0110011";
    compTable["D+1"] = "0011111";
    compTable["A+1"] = "0110111";
    compTable["D-1"] = "0001110";
    compTable["A-1"] = "0110010";
    compTable["D+A"] = "0000010";
    compTable["D-A"] = "0010011";
    compTable["A-D"] = "0000111";
    compTable["D&A"] = "0000000";
    compTable["D|A"] = "0010101";

    compTable["M"] = "1110000";
    compTable["!M"] = "1110001";
    compTable["-M"] = "1110011";
    compTable["M+1"] = "1110111";
    compTable["M-1"] = "1110010";
    compTable["D+M"] = "1000010";
    compTable["D-M"] = "1010011";
    compTable["M-D"] = "1000111";
    compTable["D&M"] = "1000000";
    compTable["D|M"] = "1010101";  

    return compTable;
}

unordered_map<string, string> createDestTable(string fileName)
{
    unordered_map<string, string> destTable;

    destTable["null"] = "000";
    destTable["M"] = "001";
    destTable["D"] = "010";
    destTable["MD"] = "011";
    destTable["A"] = "100";
    destTable["AM"] = "101";
    destTable["AD"] = "110";
    destTable["AMD"] = "111";

    return destTable;
}
unordered_map<string, string> createJumpTable(string fileName)
{
    unordered_map<string, string> jumpTable;

    jumpTable["null"] = "000";
    jumpTable["JGT"] = "001";
    jumpTable["JEQ"] = "010";
    jumpTable["JGE"] = "011";
    jumpTable["JLT"] = "100";
    jumpTable["JNE"] = "101";
    jumpTable["JLE"] = "110";
    jumpTable["JMP"] = "111"; 

    return jumpTable;
}
unordered_map<string, string> revCreateJumpTable(string fileName)
{
    unordered_map<string, string> jumpTable;

    jumpTable["000"] = "null";
    jumpTable["001"] = "JGT";
    jumpTable["010"] = "JEQ";
    jumpTable["011"] = "JGE";
    jumpTable["100"] = "JLT";
    jumpTable["101"] = "JNE";
    jumpTable["110"] = "JLE";
    jumpTable["111"] = "JMP"; 

    return jumpTable;
}
unordered_map<string, string> revCreateDestTable(string fileName)
{
    unordered_map<string, string> destTable;

    destTable["000"] = "null";
    destTable["001"] = "M";
    destTable["010"] = "D";
    destTable["011"] = "MD";
    destTable["100"] = "A";
    destTable["101"] = "AM";
    destTable["110"] = "AD";
    destTable["111"] = "AMD";

    return destTable;
}
unordered_map<string, string> revCreateCompTable(string fileName)
{
    unordered_map<string, string> compTable;
    compTable["0101010"] = "0";     
    compTable["0111111"] = "1";
    compTable["0111010"] = "-1";
    compTable["0001100"] = "D";
    compTable["0110000"] = "A";
    compTable["0001101"] = "!D";
    compTable["0110001"] = "!A";
    compTable["0001111"] = "-D";
    compTable["0110011"] = "-A";
    compTable["0011111"] = "D+1";
    compTable["0110111"] = "A+1";
    compTable["0001110"] = "D-1";
    compTable["0110010"] = "A-1";
    compTable["0000010"] = "D+A";
    compTable["0010011"] = "D-A";
    compTable["0000111"] = "A-D";
    compTable["0000000"] = "D&A";
    compTable["0010101"] = "D|A";

    compTable["1110000"] = "M";
    compTable["1110001"] = "!M";
    compTable["1110011"] = "-M";
    compTable["1110111"] = "M+1";
    compTable["1110010"] = "M-1";
    compTable["1000010"] = "D+M";
    compTable["1010011"] = "D-M";
    compTable["1000111"] = "M-D";
    compTable["1000000"] = "D&M";
    compTable["1010101"] = "D|M";  

    return compTable;
}


