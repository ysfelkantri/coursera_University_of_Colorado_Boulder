
1.
"libraries "
static library : its linked to the executable directly m its built into the executable.

shared library : its dynamically at runtime linked to the executable, its placed in separate region than the executable , already exist in memory 
you can create one with the command gcc shared 

2.
"linking + locating"
	link : is the process of combining all object files in one executable 
	loc : map this object into specific address location 
provides one executable that can be installed in our embedded processor 

linker file : tell the locator how to map our executable into the proper address -T , is architecture dependent he knows the physical map of embedded system  

by using ld application or gcc -o

3.
"make"
is a build automation , independent to the compiler or architecture 

