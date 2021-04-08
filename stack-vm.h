#ifndef STACK_VM
#define STACK_VM

#include <iostream>
#include <vector>

// Define variables

typedef int32_t i32;


class StackVM 
{
	// pc ---> addresses 
	i32 pc = 100;  // program counter
	i32 sp = 0;  // stack pointer
	std::vector<132> memory;
	i32 typ = 0;
	i32 dat = 0;
	i32 running = 1; // if vm still  working
	
	i32 getType(i32 instruction);
	i32 getData(i32 instructuion);

	// Main 3-functions loop, that runs forever util user stop
	void fetch();
	void decode();
	void execute();
	void doPrimitive();

	public:
		StackVM();
		void run();
		void loadProgram(std::vector<i32> prog); //Initialice memory
};

#endif 
