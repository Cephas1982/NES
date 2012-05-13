#ifndef REGISTER_TRANSFER_OPS
#define REGISTER_TRANSFER_OPS
#include "CPU.h"
/*************** TAX FUNCTIONS ************************/
void C_CPU::TAX_AA(WORD opcode)//Implied, 2 cycles
{
	m_regX = m_regA;

	if(m_regX == 0)
	  m_flagZ = 1;

	if((m_regX & 128) == 128)
	  m_flagN = 1;

	m_cycleCount += 2;
	m_pc ++;
}

/*************** TAY FUNCTIONS ************************/
void C_CPU::TAY_A8(WORD opcode)//Implied, 2 cycles
{
	m_regY = m_regA;

	if(m_regY == 0)
	  m_flagZ = 1;

	if((m_regY & 128) == 128)
	  m_flagN = 1;

	m_cycleCount += 2;
	m_pc ++;
}

/*************** TXA FUNCTIONS ************************/
void C_CPU::TXA_8A(WORD opcode)//Implied, 2 cycles
{
	m_regA = m_regX;

	if(m_regA == 0)
	  m_flagZ = 1;

	if((m_regA & 128) == 128)
	  m_flagN = 1;

	m_cycleCount += 2;
	m_pc ++;
}

/*************** TYA FUNCTIONS ************************/
void C_CPU::TYA_98(WORD opcode)//Implied, 2 cycles
{
	m_regA = m_regY;

	if(m_regA == 0)
	  m_flagZ = 1;

	if((m_regA & 128) == 128)
	  m_flagN = 1;

	m_cycleCount += 2;
	m_pc ++;	
}
#endif