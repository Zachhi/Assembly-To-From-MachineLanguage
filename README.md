# Assembly-To-From-MachineLanguage
An assembler and disassembler for the low-level language assembly, which will convert assembly files to machine language, and machine language files to assembly.

## About

This program takes assembly (or `.asm`) files and assembles them into machine language, A.K.A, binary. I used the file extension `.hack` to represent machine language code. Not to be confused with the programming language hack, the `.hack` files in my program only consist of binary, or 1's and 0's. 

The files you see that end with `.asm` or `.hack` are there pureley for testing. You can test it yourself to see the assembler/disassembler in action. You can also create your own files if you so wish. Assembling `test.asm` will result in the `test.hack` file and vice versa. The same is true for `programTest.asm` and `programTest.hack`. Of course, if you don't delete any of these, nothing will change when you run it through the program, as both the `.hack` and `.asm` files already exist, so no new files will be created.

## Demo

https://www.youtube.com/watch?v=sT9SZdZqSJE

### Dependencies

* Some way to compile and execute c++ code
* GNU Make (Not required, but makes executing easier)

### Installing and Executing

* Download the source code from github, or clone the repository into Visual Studio
* If you wish to assemble a `.asm` to machine language code:
  * Add, or create the `.asm` file in the project folder with the assembly code in it.
  * Go to `main.cpp` and call the function `assemble(file.asm);`
* If you wish to disassemble machine language code to a `.asm` file:
  * Add, or create the `.hack` file in the project folder with machine language code (binary) in it. (I decided to use the `.hack` file extension to represent machine language code...not to be confused with the hack programming language)
  * Go to `main.cpp` and call the function `disassemble(file.hack);`
* You can dissassemble and assemble at the same time if you wish to do so
* Change directory to `<path/to/projectFolder/src>`
* Compile code how you like, or, run the command `make`
* After running `make`', execute by running the executeable `run` or `run.exe`
* The assembled `.hack` file and/or the disassembled `.asm` file will automatically be created in your project folder

## Authors

Zachary Chi
zachchi@tamu.edu

## License

This project is licensed under the MIT License - see the LICENSE.md file for details
