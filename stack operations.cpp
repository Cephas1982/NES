#ifndef STACK_OPERATIONS_CPP
#define STACK_OPERATIONS_CPP
#include "CPU.h"
/*************** STACK OPERATION FUNCTIONS ************************/
/*************** TSX FUNCTIONS ************************/
void C_CPU::TSX_BA(WORD opcode)//Implied, 2 cycles
{
	m_regX = m_regS;

	if(m_regX == 0)
	  m_flagZ = 1;

	if((m_regX & 0x80 == 0x80))
	  m_flagN = 1;

	m_cycleCount += 2;
	m_pc ++;	
}
/*************** TXS FUNCTIONS ************************/
void C_CPU::TXS_9A(WORD opcode)//Implied, 2 cycles
{
	m_regS = m_regX;

	m_cycleCount += 2;
	m_pc ++;
}

void C_CPU::PHA_48(WORD opcode)//Implied, 3 cycles
{
	//todo: have variable m_regS hold BYTE that m_regS points to.
	//m_regS is the stack pointer
	//m_regS = Accumulator; //(m_regS points to the next free byte on stack)
	//m_regS--; //post decrement stack pointer

}

void C_CPU::PHP_08(WORD opcode)//Implied, 3 cycles
{
	//pushes copy of status flags to stack
	//m_regS is the stack pointer
	

	v_stack.push_back(pStatus);
	m_pc++;
}

void C_CPU::PLA_68(WORD opcode)//Implied, 4 cycles
{
	//Pulls an 8 bit value from the stack and into the accumulator.
	//The zero and negative flags are set as appropriate.
	m_regA = v_stack.back();
	v_stack.pop_back();


	if(m_regA == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	if(m_regA & 0x80 == 80)
		m_flagN = 1;
	else
		m_flagN = 0;

	m_pc++;
}

void C_CPU::PLP_28(WORD opcode)//Implied, 4 cycles
{
	//regProcStatus = *(m_regS -1);//pull 8bit value from stack and set  
					//the processor status flags
}


#endif