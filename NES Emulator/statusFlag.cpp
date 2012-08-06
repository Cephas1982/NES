#ifndef STATUSFLAG_CPP
#define STATUSFLAG_CPP
#include "CPU.h"
//***************** STATUS FLAG CHANGE FUNCTIONS*************************
void C_CPU::CLC_18(WORD opcode)//Implied, 2 cycles
{
	m_flagC = 0;

	m_cycleCount += 2;
	m_pc++;//adv ance to next program instruction
}

void C_CPU::CLD_D8(WORD opcode)//Implied, 2 cycles
{
	m_flagD = 0;

	m_cycleCount += 2;
	m_pc++;//adv ance to next program instruction

}
/*
NB: TODO???
The state of the decimal flag is uncertain when the CPU is powered up and it is not reset when an interrupt is generated. In both cases you should include an explicit CLD to ensure that the flag is cleared before performing addition or subtraction.
*/

void C_CPU::CLI_58(WORD opcode)//Implied, 2 cycles
{
	m_flagI = 0;

	m_cycleCount += 2;
	m_pc++;//adv ance to next program instruction
}

void C_CPU::CLV_B8(WORD opcode)//Implied, 2 cycles
{
	m_flagV = 0;

	m_cycleCount += 2;
	m_pc++;//adv ance to next program instruction
}

void C_CPU::SEC_38(WORD opcode)//Implied, 2 cycles
{
	m_flagC = 1;

	m_cycleCount += 2;
	m_pc++;//adv ance to next program instruction
}

void C_CPU::SED_F8(WORD opcode)//Implied, 2 cycles
{
	m_flagD = 1;

	m_cycleCount += 2;
	m_pc++;//adv ance to next program instruction
}

void C_CPU::SEI_78(WORD opcode)//Implied, 2 cycles
{
	m_flagI = 1;

	m_cycleCount += 2;
	m_pc++;//adv ance to next program instruction
}

#endif