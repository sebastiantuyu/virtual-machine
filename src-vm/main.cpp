#include "stack-vm.h"
#include <bitset>

int main()
{
	StackVM vm;
std::vector<i32> prog{
					3, 4, 0x40000001, // <--- ADD 3, 4
					5, 4, 0x40000002, // <--- SUB 2, 4
					8, 4, 0x40000003,	// <--- MUL 8, 4 
					0x40000000}; 			// <--- HALT
	
	//	0x40000001 -----> ADD
	//	0x40000000 -----> HALT
	std::bitset<32> b1(0x40000001);
	std::bitset<32> b2(0x40000000);

	std::cout<<"B1: "<<b1<<std::endl;
	std::cout<<"B2: "<<b2<<std::endl<<std::endl;
	//Initialice ! 
	vm.loadProgram(prog);
	vm.run();

	return 0; 
}
