volatile 
extern 
__attribute__

//codes :
1.
"gcc options :"
-std=c99 or std=c89: to compile with c99 standard 
-Werror : to convert warnings to error
-c : stop befor linking 
-Wall : all warning will be enbled 
-v : verbose option to print lots of informaiton of what gcc is doing
-S : compile but stop before linking and output the code in assembly in a file called "main.s"
-g : include debug symbols
-E main.c -o main.i : stop the compilation befor preprocessing src file 
-DMSP : to define the MSP Constent like : #define MSP in c file 
objdump -S --disassemble object > obj.dump

"pragma"
#pragma GCC poison printf : to prevent the use of printf in the code 
#pragma once : to include guard 
#pragma startup func() : to execute the void func(void) befor main 

