Instructions for program:

1. compile program. 
    
    You can use: g++ assembler.h assembler.cpp table.cpp table.h main.cpp disassembler.h disassembler.cpp -o a.out
    And then to run it:    ./a.out

or compile to your liking.

2. add .txt or .hack or .asm file (whatever is being used to test) to repository

3. go to main.cpp function, this will be all you need.
4. for assembly, just call: assemble("testfilename.whatever")
5. for disassembly, just call: disassemble("testFileName.whatever")

6. after writing the functions, run the program with ./a.out or with whatever you like

7. these will automatically create .hack and .asm files with the result of the output

# Assembly-To-From-MachineLanguage
Implementation of every main data structure, as well as Dijkstra's and Prim's algorithm.

## About

Once you execute, a menu will show up. Click 1-9 depending on what you want. Each one will show a different data structure. If you wish to use the data structures, or test your own values, simply go into the structures.cpp file. There will be functions for each data structure. In the function for the data structure you want, you can create your own object and test your own values if you wish. 

Right now, running the program only shows testing for each data structure. This is meant to show that each data structure/algorithm works as intended. In the future, I plan on making this program visual and interactive, allowing the user to add/remove their own values, and allowing the user to use any functions that the data structure has without having to actually edit the code. All of this will be laid out visually, helping the user to visualize each data structure. Once this is all said and done, I plan on positing it to a website to help newcomers understand data structures better.

## Demo


### Dependencies

* Some way to compile and execute c++ code
* GNU Make (Not required, but makes executing easier)

### Installing and Executing

* Download the source code from github, or clone the repository into Visual Studio
* Compile code how you like, or, run the command `make`
* After running `make`', execute by running the command `run` or `run.exe`

## Authors

Zachary Chi
zachchi@tamu.edu

## License

This project is licensed under the MIT License - see the LICENSE.md file for details
