//Zachary Chi
//628001407
//An Aggie does not lie, cheat or steal or tolerate those who do.
#include "assembler.h"
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

bool isAinst(string line)
{
    if(line.at(0)!='@')
        return false;

    string Ainst = line.substr(1, line.length()-1);
    if(isNumber(Ainst))
        return true;
    if(isdigit(Ainst.at(0)))
        return false;
    return true;
}
string Ainst(string line, unordered_map<string, int> symbolTable)
{
    string Ainst = line.substr(1, line.length()-1);

    if(isNumber(Ainst))
    {
        string bin = bitset<15>(stoi(Ainst)).to_string();
        line = '0' + bin;
        return line;
    }

    int addr = symbolTable[Ainst];
    string bin = bitset<15>(addr).to_string();
    line = '0' + bin;
    return line;
}

bool isCinst(string line, unordered_map<string, string> dest, unordered_map<string, string> jump, unordered_map<string, string> comp)
{
    int n = std::count(line.begin(), line.end(), '=');
    int m = std::count(line.begin(), line.end(), ';');
    
    string tokens = line;
    replace(tokens.begin(), tokens.end(), ';', ' ');
    replace(tokens.begin(), tokens.end(), '=', ' ');
    stringstream ss(tokens);
    vector<string> array;
    string temp;
    while(ss >> temp)
    {
        array.push_back(temp);
    }
    if(array.size() == 1 && comp.find(array[0]) != comp.end())
    {
        return true;
    }

    if(m!=1 && n!=1 )
        return false;

    if(array.size() != 2 && array.size() != 3)
        return false;

    if(array.size() == 2)
    {
        if(n == 1)
            {
                if(dest.find(array[0]) == dest.end())
                    return false;
                if(comp.find(array[1]) == comp.end())
                    return false;
            }
        else
        {

            if(comp.find(array[0]) == comp.end())
                return false;
            if(jump.find(array[1])==jump.end())
                return false;
        }
    }
    else
    {
        if(dest.find(array[0])==dest.end())
            return false;
        if(comp.find(array[1])==comp.end())
            return false;
        if(jump.find(array[2])==jump.end())
            return false;
    }
    return true;
}

string Cinst(string line, unordered_map<string, string> dest, unordered_map<string, string> jump, unordered_map<string, string> comp)
{
    string tokens = line;
    replace(tokens.begin(), tokens.end(), ';', ' ');
    replace(tokens.begin(), tokens.end(), '=', ' ');
    stringstream ss(tokens);
    vector<string> array;
    string temp;
    while(ss >> temp)
        array.push_back(temp);
    
    int n = std::count(line.begin(), line.end(), '=');
    int m = std::count(line.begin(), line.end(), ';');
    string prefix = "111";
    string destx = "";
    string compx = "";
    string jumpx = "";
    if(array.size() == 1 && comp.find(array[0]) != comp.end())
    {
        destx = "000";
        jumpx = "000";
        compx = comp[array[0]];
        string final = prefix + compx + destx + jumpx;
        return final;
    }
    else
        exit;


    if(array.size() == 2)
    {
        if(n == 1)
        {
            destx = dest[array[0]];
            compx = comp[array[1]];
            jumpx = "000";
            if(destx == "null" || compx == "null")
                exit;
        }
        else
        {
            destx = "000";
            compx = comp[array[0]];
            jumpx = jump[array[1]];

            if(compx == "null" || jumpx == "null")
                exit;
        }

    }
    else
    {
        destx = dest[array[0]];
        compx = comp[array[1]];
        jumpx = jump[array[2]];

        if(compx == "null" || jumpx == "null" || destx == "null" )
            exit;
    }
    string final = prefix + compx + destx + jumpx;
    return final;

}
void assemble(string fileName) {

    //create tables here
    unordered_map<string, int> symbolTable;
    unordered_map<string, string> compTable;
    unordered_map<string, string> destTable;
    unordered_map<string, string> jumpTable;
    symbolTable = createSymbolTable(fileName);
    compTable = createCompTable(fileName);
    destTable = createDestTable(fileName);
    jumpTable = createJumpTable(fileName);

    string dummy;
    ifstream file (fileName);
    if(file.is_open())
    {
        string fileNoExtension = fileName.substr(0, fileName.length()-4);
        ofstream binaryOut;
        binaryOut.open(fileNoExtension + ".hack");
        while(getline(file, dummy))
        {
            string cleaned = dummy.substr(0, dummy.find("//"));
            cleaned.erase(std::remove_if(cleaned.begin(), cleaned.end(), ::isspace), cleaned.end());

            if(cleaned != "")
            {
                if(cleaned.length() != 0 && isAinst(cleaned))
                {
                    string bin = Ainst(cleaned, symbolTable);
                    binaryOut << bin << "\n";
                }
                else if(cleaned.length() != 0 && isCinst(cleaned, destTable, jumpTable, compTable))
                {
                    string bin = Cinst(cleaned, destTable, jumpTable, compTable);
                    binaryOut << bin << "\n";
                }
                else
                {
                    exit;
                }
            }
        }
        binaryOut.close();
        file.close();
    }
    else
    {
        cout << "Connot open file";
        exit;
    }
}