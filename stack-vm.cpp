#include "stack-vm.h"


StackVM::StackVM()
{
	memory.reserve(1000000) // 1 000 000 million
}

i32 StackVM::getType(i32 instruction)
{
	// 32-bits ===> 8 bit = 1 byte ===> 4 bytes = 32-bit  
	// c0 00 00 00 ====> 32bit 
	//  ^------- byte 
	i32 type = 0xc 
}
