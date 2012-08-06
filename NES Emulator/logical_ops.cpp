#ifndef LOGICAL_OPS
#define LOGICAL_OPS
#include "CPU.h"
/*************** LOGICAL AND FUNCTIONS ************************/
void C_CPU::AND_29(WORD opcode)//Immediate, 2 cycles
{
	m_regA = m_regA & systemMem[Immediate(2)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::AND_25(WORD opcode)//Zero_page, 3 cycles
{
	m_regA = m_regA & systemMem[ZeroPage(3)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::AND_35(WORD opcode)//Zero_page X, 4 cycles
{
	m_regA = m_regA & systemMem[ZeroPageX(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::AND_2D(WORD opcode)//Absolute, 4 cycles
{
	m_regA = m_regA & systemMem[Absolute(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::AND_3D(WORD opcode)//Absolute X, 4 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition
	m_regA = m_regA & systemMem[AbsoluteX(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	
	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

void C_CPU::AND_39(WORD opcode)//Absolute Y, 4 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition
	m_regA = m_regA & systemMem[AbsoluteY(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;


	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

void C_CPU::AND_21(WORD opcode)//Indirect X, 6 cycles
{
	m_regA = m_regA & systemMem[IndirectX(6)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::AND_31(WORD opcode)//Indirect Y, 5 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition
	m_regA = m_regA & systemMem[IndirectY(5)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}


/*************** LOGICAL EOR FUNCTIONS ************************/
void C_CPU::EOR_49(WORD opcode)//Immediate, 2 cycles
{
	m_regA = m_regA ^ systemMem[Immediate(2)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::EOR_45(WORD opcode)//Zero_page, 3 cycles
{
	m_regA = m_regA ^ systemMem[ZeroPage(3)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::EOR_55(WORD opcode)//Zero_page X, 4 cycles
{
	m_regA = m_regA ^ systemMem[ZeroPageX(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::EOR_4D(WORD opcode)//Absolute, 4 cycles
{
	m_regA = m_regA ^ systemMem[Absolute(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::EOR_5D(WORD opcode)//Absolute X, 4 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition
	m_regA = m_regA ^ systemMem[AbsoluteX(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	
	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

void C_CPU::EOR_59(WORD opcode)//Absolute Y, 4 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition
	m_regA = m_regA ^ systemMem[AbsoluteY(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;


	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

void C_CPU::EOR_41(WORD opcode)//Indirect X, 6 cycles
{
	m_regA = m_regA ^ systemMem[IndirectX(6)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::EOR_51(WORD opcode)//Indirect Y, 5 cycles (+1 if page crossed)
{
	WORD before = m_pc ^ 0xFF00;//page before addition
	m_regA = m_regA & systemMem[IndirectY(5)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}


/*************** LOGICAL Inclusive OR FUNCTIONS ************************/
void C_CPU::ORA_09(WORD opcode)//Immediate, 2 cycles
{
	m_regA = m_regA | systemMem[Immediate(2)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::ORA_05(WORD opcode)//Zero_page, 3 cycles
{
	m_regA = m_regA | systemMem[ZeroPage(3)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::ORA_15(WORD opcode)//Zero_page X, 4 cycles
{
	m_regA = m_regA | systemMem[ZeroPageX(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::ORA_0D(WORD opcode)//Absolute, 4 cycles
{
	m_regA = m_regA | systemMem[Absolute(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::ORA_1D(WORD opcode)//Absolute X, 4 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition
	m_regA = m_regA | systemMem[AbsoluteX(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	
	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

void C_CPU::ORA_19(WORD opcode)//Absolute Y, 4 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition
	m_regA = m_regA | systemMem[AbsoluteY(4)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;


	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

void C_CPU::ORA_01(WORD opcode)//Indirect X, 6 cycles
{
	m_regA = m_regA | systemMem[IndirectX(6)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::ORA_11(WORD opcode)//Indirect Y, 5 cycles (+1 if page crossed)
{
	WORD before = m_pc | 0xFF00;//page before addition
	m_regA = m_regA & systemMem[IndirectY(5)];

	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

/*************** Bit Test FUNCTIONS ************************/
void C_CPU::BIT_24(WORD opcode)//Zero_page, 3 cycles
{
	BYTE mem = systemMem[ZeroPage(3)];
	BYTE result = m_regA & mem;

	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	
	//set V register to bit 6 value of mem
	if((mem & 0x40) == 0x40)
		m_flagV = 1;
	else
		m_flagV = 0;

	//set N register to bit 7 value of mem
	if((mem & 0x80) == 0x80)
		m_flagN = 1;
	else
		m_flagN = 0;
}

void C_CPU::BIT_2C(WORD opcode)//Absolute, 4 cycles
{
	BYTE mem = systemMem[Absolute(4)];
	BYTE result = m_regA & mem;

	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
		
	//set V register to bit 6 value of mem
	if((mem & 0x40) == 0x40)
		m_flagV = 0;
	else
		m_flagV = 1;

	//set N register to bit 7 value of mem
	if((mem & 0x80) == 0x80)
		m_flagN = 0x80;
	else
		m_flagN = 1;
}

#endif