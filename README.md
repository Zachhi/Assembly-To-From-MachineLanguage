# Assembly-To-From-MachineLanguage
An assembler and disassembler for the low-level language hack assembly, which will convert hack assembly(`.asm`) files to machine language (`.hack`), and machine language files to hack assembly.

## About

This program takes hack assembly (or `.asm`) files and assembles them into machine language (`.hack`), A.K.A, binary. I used the file extension `.hack` to represent machine language code. Not to be confused with the programming language hack, the `.hack` files in my program only consist of binary, or 1's and 0's. 

The files you see that end with `.asm` or `.hack` are there pureley for testing. You can test it yourself to see the assembler/disassembler in action. You can also create your own files if you so wish. Assembling `test.asm` will result in the `test.hack` file and vice versa. The same is true for `programTest.asm` and `programTest.hack`. Of course, if you don't delete any of these, nothing will change when you run it through the program, as both the `.hack` and `.asm` files already exist, so no new files will be created.

## Demo

https://www.youtube.com/watch?v=sT9SZdZqSJE

## What is Hack Assembly? 

The Hack Assembly Language consists of 3 types of instructions. It allows us to declare symbols with a single symbol declatation. Hack assembly ignored whitespace and you can write comments with `//`. Symbols can be variables and labels

### Types of Instructions

1. A-Instruction: Addressing instructions, used with a preceding `@`
2. C-Instruction: Computation instructions, used with either `=` or `;`
3. L-Instruction: Labels (Symbols) declaration instructions, used with `(symbol)`

### Predefined Symbols

- **A**: Address Register.
- **D**: Data Register.
- **M**: Refers to the register in Main Memory whose address is currently stored in **A**.
- **R0**-**R15**: Addresses of 16 RAM Registers, mapped from 0 to 15.
- **SCREEN**: Base address of the Screen Map in Main Memory, which is equal to 16384.
- **KBD**: Keyboard Register address in Main Memory, which is equal to 24576.

For a more in depth explanation of this language, visit https://www.coursera.org/lecture/build-a-computer/unit-6-2-the-hack-assembly-language-AYPo6

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
