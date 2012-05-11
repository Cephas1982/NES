#include"CPU.h"

//***************** BRANCH FUNCTIONS*************************************
void C_CPU::BCC_90(WORD opcode)//Relative, 2(+1 if branch succeeds, +2 if to a new page)
{
//If the carry flag is clear then add the relative displacement to the
//program counter to cause a branch to a new location.

	//TODO: wtf
}

void C_CPU::BCS_B0(WORD opcode)//Relative, 2(+1 if branch succeeds, +2 if to a new page)
{
//If the carry flag is set then add the relative displacement to 
//the program counter to cause a branch to a new location.

	//TODO: wtf
}

void C_CPU::BEQ_F0(WORD opcode)//Relative, 2(+1 if branch succeeds, +2 if to a new page)
{
//If the zero flag is set then add the relative displacement to the
//program counter to cause a branch to a new location.

	//TODO: wtf
}

void C_CPU::BMI_30(WORD opcode)//Relative, 2(+1 if branch succeeds, +2 if to a new page)
{
//If the negative flag is set then add the relative displacement to the 
//program counter to cause a branch to a new location.

	//TODO: wtf
}

void C_CPU::BNE_D0(WORD opcode)//Relative, 2(+1 if branch succeeds, +2 if to a new page)
{
//If the zero flag is clear then add the relative displacement to the 
//program counter to cause a branch to a new location.

	//TODO: wtf
}

void C_CPU::BPL_10(WORD opcode)//Relative, 2(+1 if branch succeeds, +2 if to a new page)
{
//If the negative flag is clear then add the relative displacement to 
//the program counter to cause a branch to a new location.

	//TODO: wtf
}

void C_CPU::BVC_50(WORD opcode)//Relative, 2(+1 if branch succeeds, +2 if to a new page)
{
//If the overflow flag is clear then add the relative displacement to 
//the program counter to cause a branch to a new location.

	//TODO: wtf
}

void C_CPU::BVS_70(WORD opcode)//Relative, 2(+1 if branch succeeds, +2 if to a new page)
{
//If the overflow flag is set then add the relative displacement to 
//the program counter to cause a branch to a new location.

	//TODO: wtf
}

/*
Branch instructions use relative address to identify the target instruction if they are executed. As relative addresses are stored using a signed 8 bit byte the target instruction must be within 126 bytes before the branch or 128 bytes after the branch.
*/

