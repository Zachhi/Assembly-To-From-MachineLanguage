//Zachary Chi
#include "assembler.h"
#include "disassembler.h"
#include "table.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <bitset>
#include<sstream>
#include <vector>
using namespace std;
int binaryToDecimal(int n) //converts binary number to decimal
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}
void disassemble(string fileName) //dissassembles. main function, Changes machine language to asm
{
    unordered_map<string, string> compTable;
    unordered_map<string, string> destTable;
    unordered_map<string, string> jumpTable;
    compTable = revCreateCompTable(fileName);
    destTable = revCreateDestTable(fileName);
    jumpTable = revCreateJumpTable(fileName);

    string dummy;
    ifstream file (fileName);
    if(file.is_open())
    {
        string fileNoExtension = fileName.substr(0, fileName.length()-5);
        ofstream asmOut;
        asmOut.open(fileNoExtension + ".asm");
        while(getline(file, dummy))
        {
            string compHelp = dummy;
            string destHelp = dummy;
            string jmpHelp = dummy;

            char first = dummy.at(0);

            //A inst
            if(first == '0')
            {
                string prefix = "@";
                string bit15 = dummy.substr(1, dummy.length()-1);
                int bit15i = stoi(bit15);
                int bit15final = binaryToDecimal(bit15i);
                string finalbit = to_string(bit15final);
                string answer = prefix + finalbit;
                asmOut << answer << "\n";
            }

            //C inst
            else 
            {   
                string comp = compHelp.substr(3, 7);
                string dest = destHelp.substr(10, 3);
                string jmp = jmpHelp.substr(13, 3);
                string compConv = compTable[comp];
                string destConv = destTable[dest];
                string jmpConv = jumpTable[jmp];
                string final;
                if(destConv != "null" && jmpConv != "null")
                {
                    final = destConv + "=" + compConv + ";" + jmpConv;
                }
                else if (destConv != "null")
                {
                    final = destConv + "=" + compConv;
                }
                else if (jmpConv != "null")
                {
                    final = compConv + ";" + jmpConv;
                }
                else
                {
                final = compConv;
                }
                asmOut << final << "\n";

            }

        }
        asmOut.close();
        file.close();
    }
    else
    {
        cout << "Connot open file";
        exit;
    }
}