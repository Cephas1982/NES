#ifndef STACK_OPERATIONS_CPP
#define STACK_OPERATIONS_CPP
#include "CPU.h"
/*************** STACK OPERATION FUNCTIONS ************************/
void C_CPU::TSX_BA(WORD opcode)//Implied, 2 cycles
{
	m_regX = m_regS; //(what stack register is pointing to)
	if(m_regX == 0)
		m_flagZ = 1;
	if(m_regX > 127)
		m_flagN = 1;

	m_cycleCount+= 2;
	m_pc++;
}

void C_CPU::TXS_9A(WORD opcode)//Implied, 2 cycles
{
	m_regS = m_regX; //(what stack register is pointing to)

	m_cycleCount+=2;
	m_pc++;
}
/*
void C_CPU::PHA_48(WORD opcode)//Implied, 3 cycles
{
	//todo: have variable m_regS hold BYTE that m_regS points to.
	//m_regS is the stack pointer
	*m_regS = Accumulator; //(m_regS points to the next free byte on stack)
	m_regS--; //post decrement stack pointer

}

void C_CPU::PHP_08(WORD opcode)//Implied, 3 cycles
{
	//todo: have variable m_regS hold BYTE that m_regS points to.
	//m_regS is the stack pointer
	*m_regS = regStatus//(m_regS points to the next free byte on stack)
	m_regS--; //post decrement stack pointer
}

void C_CPU::PLA_68(WORD opcode)//Implied, 4 cycles
{
	//todo: have variable m_regS hold BYTE that m_regS points to.
	//m_regS is the stack pointer
	Accumulator = *(m_regS - 1);//from top of stack
	m_regS++; //post increment stack pointer
	//TODO: Make stack a vector and push/pop from that instead?
}

void C_CPU::PLP_28(WORD opcode)//Implied, 4 cycles
{
	regProcStatus = *(m_regS -1);//pull 8bit value from stack and set  
					//the processor status flags
}
*/

#endif