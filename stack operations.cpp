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
	// push accumulator on stack
	m_regS--;// decrement BEFORE pushing on stack
	mStack[m_regS]=m_regA;
	
	//v_stack.push_back(m_regA);
	m_pc++;
}

void C_CPU::PHP_08(WORD opcode)//Implied, 3 cycles
{
	//pushes copy of status flags to stack

	m_regS--;// decrement BEFORE pushing on stack
	mStack[m_regS]=pStatus;
	
	//v_stack.push_back(pStatus);
	m_pc++;

	
}

void C_CPU::PLA_68(WORD opcode)//Implied, 4 cycles
{
	//Pulls an 8 bit value from the stack and into the accumulator.
	//The zero and negative flags are set as appropriate.
	
	m_regA = mStack[m_regS];
	m_regS++;// increment AFTER popped off


	//m_regA = v_stack.back();
	//v_stack.pop_back();


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
	//pull 8bit value from stack and set  
	//the processor status flags
	
	BYTE procStatus = mStack[m_regS];
	m_regS++;//increment AFTER popped off


	//BYTE procStatus = v_stack.back();
	//v_stack.pop_back();
	
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
//*  ******** I think when this is set an IRQ is triggered and other things are done. For now this will go back to zero and we'll pretend the IRQ happened
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
	m_pc++;

	
}


#endif