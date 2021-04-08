#include "stack-vm.h"


StackVM::StackVM()
{
	memory.reserve(1000000); // 1 000 000 million
}

i32 StackVM::getType(i32 instruction)
{
	// 32-bits ===> 8 bit = 1 byte ===> 4 bytes = 32-bit  
	// c0 00 00 00 ====> 32bit 
	//  ^------- byte 
	i32 type = 0xc0000000;
	type = (type & instruction) >> 30;
	return type; 
}

i32 StackVM::getData(i32 instruction)
{
	i32 data = 0x32ffffff;
	data = data & instruction;
	return data;
}

void StackVM::fetch()
{
	pc++;
}

void StackVM::decode()
{
	typ = getType(memory[pc]);
	dat = getData(memory[pc]);
}

void StackVM::execute()
{
	if (typ == 0 || typ == 2)
	{
		sp++;
		memory[sp] = dat;
	} else{
		doPrimitive(); 
	}
}

void StackVM::doPrimitive()
{
	// Instruction SET
	switch(dat)
	{
		case 0:
			std::cout<<"HALT"<<std::endl;
			running = 0;
			break;
		case 1:		
			std::cout<<"ADD "<<memory[sp -1]<<" "<< memory[sp] <<std::endl;

			// Get the 2 first in stack, pop and then added into the first
			/*  |   2   |           |   5   |
			 *	|_______|           |_______|
			 *	|   3   |   ====>   |  ...  |  
			 *  |_______|           |_______|
			 *  |  ...  |            
			 *	|_______|
			 * */

			memory[sp - 1] = memory[sp - 1] + memory[sp];
			sp--;			
			break;
    					
	}						
}


void StackVM::run()
{
	pc -=1;
	while(running == 1)
	{
		fetch();
		decode();
		execute();
		std::cout<<"STACK: "<< memory[sp] << std::endl;
	}
}

void StackVM::loadProgram(std::vector<i32> prog)
{
		for(i32 i=0;i<prog.size();i++)
		{
			memory[pc + i] = prog[i];
			std::cout<<"SHOWING MEMORY: "<<std::endl;
			std::cout<<prog[i]<<std::endl;
		}
}
