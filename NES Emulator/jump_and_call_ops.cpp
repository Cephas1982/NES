#ifndef JUMP_AND_CALL_OPS
#define JUMP_AND_CALL_OPS
#include "CPU.h"

//***************** JMP FUNCTIONS******************************************

void C_CPU::JMP_4C(WORD opcode)//Absolute, 3 cycles
{
	m_pc = Absolute(3); //jump to return address of Absolute(3)
}

void C_CPU::JMP_6C(WORD opcode)//Indirect, 5 cycles
{
	m_pc = Indirect(5);
}

/*
TODO?? FYI: 
NB:
An original 6502 has does not correctly fetch the target address if the indirect vector falls on a
page boundary (e.g. $xxFF where xx is and value from $00 to $FF). 
In this case fetches the LSB from $xxFF as expected but takes the MSB from $xx00. 
This is fixed in some later chips like the 65SC02 so for compatibility always ensure the 
indirect vector is not at the end of the page.
*/

//***************** JSR FUNCTIONS******************************************
void C_CPU::JSR_20(WORD opcode)//Absolute, 6 cycles
{	
	WORD result = Absolute(6);
	BYTE A = (m_pc - 1) >> 8;
	BYTE B = (m_pc - 1) & 0xff;

	//decrement BEFORE to pushing onto the stack
	m_regS--;
	systemMem[0x101 + m_regS]=A;
	m_regS--;
	systemMem[0x101 + m_regS]=B;
	
	//v_stack.push_back(m_pc);//push back program counter
	m_pc = result; //JUMP to new address

	//m_regS-= 2;// decrement when pushed on
}

//***************** RTS FUNCTIONS******************************************

void C_CPU::RTS_60(WORD opcode)//Implied, 6 cycles
{
	//pulls program counter --- not advancing b/c it is implied (pc+1) and 
	//$60 requires pc-1
	
	//when pulling from the stack you increment AFTER the pull
	BYTE A = systemMem[0x101 + m_regS];
	m_regS++;
	BYTE B = systemMem[0x101 + m_regS];
	m_regS++;

	WORD returnLocation = B << 8;
	returnLocation += A;

	m_pc = returnLocation + 1;

	m_cycleCount+= 6;//implied is +2!

	//old
	//m_pc = v_stack.back();
	//v_stack.pop_back();

	//m_regS+= 2;// decrement when pushed on
}
#endif