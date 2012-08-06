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
	//return from interrupt. pulls processor flags followed by program counter	
	BYTE procStatus = systemMem[0x101 + m_regS];
	m_regS++;//increment AFTER popped off
	
	pStatus = 0;
	if((procStatus & fC) == fC){
		pStatus |= fC;
		m_flagC = true;
	}
	else
		m_flagC = false;

	if((procStatus & fZ) == fZ){
		pStatus |= fZ;
		m_flagZ = true;
	}
	else
		m_flagZ = false;

	if((procStatus & fI) == fI){
		pStatus |= fI;
		m_flagI = true;
	}else
		m_flagI = false;

	if((procStatus & fD) == fD){
		pStatus |= fD;
		m_flagD = true;
	}else
		m_flagD = false;
/*  ******** I think when this is set an IRQ is triggered and other things are done. For now this will go back to zero and we'll pretend the IRQ happened
	if((procStatus & fB) == fB){// The break command register can only be set by a BRK instruction or interrupt
		pStatus |= fB;
		m_flagB = true;
	}else
		m_flagB = false;

	if((procStatus & fE) == fE){
		pStatus |= fE;
		m_emptyFlag = true;
	}else
		m_emptyFlag = false;
*/
	if((procStatus & fV) == fV){
		pStatus |= fV;
		m_flagV = true;
	}else
		m_flagV = false;

	if((procStatus & fN) == fN){
		pStatus |= fN;
		m_flagN = true;
	}else
		m_flagN = false;

	//TODO: Optimize!!!
	m_cycleCount += 6;
	
	BYTE returnA = systemMem[0x101 + m_regS];
	m_regS++;// inc after popping off

	BYTE returnB = systemMem[0x101 + m_regS];
	m_regS++;// inc after popping off

	WORD returnAddress = returnB;
	returnAddress <<= 8;
	returnAddress += returnA;

	m_pc = returnAddress;
}

#endif