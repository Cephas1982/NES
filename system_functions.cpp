#ifndef SYSTEM_FUNCTIONS
#define SYSTEM_FUNCTIONS
#include "CPU.h"
//***************** STATUS FLAG CHANGE FUNCTIONS*************************
void C_CPU::BRK_00(WORD opcode)//Implied, 2 cycles
{
	printf("\n\n not implemented");
	system("pause");
}

void C_CPU::NOP_EA(WORD opcode)//Implied, 2 cycles
{
	m_cycleCount += 2;
	m_pc++;//adv ance to next program instruction
}

void C_CPU::RTI_40(WORD opcode)//Implied, 2 cycles
{
	printf("\n\n not implemented");
	system("pause");
}

#endif