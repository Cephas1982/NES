#ifndef LOAD_AND_STORE_CPP
#define LOAD_AND_STORE_CPP
#include "CPU.h"

/*************** LDA FUNCTIONS ************************/
void C_CPU::LDA_A9(WORD opcode)//Immediate, 2 cycles
{
	m_regA = systemMem[Immediate(2)];
	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::LDA_A5(WORD opcode)//Zero_Page, 3 cycles
{
	m_regA = systemMem[ZeroPage(3)];
	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::LDA_B5(WORD opcode)//Zero_Page X, 4 cycles
{
	m_regA = systemMem[ZeroPageX(4)];
	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::LDA_AD(WORD opcode)//Absolute, 4 cycles
{
	m_regA = systemMem[Absolute(4)];
	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::LDA_BD(WORD opcode)//Absolute X, 4 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition

	m_regA = systemMem[AbsoluteX(4, 1)];
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

void C_CPU::LDA_B9(WORD opcode)//Absolute Y, 4 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition

	m_regA = systemMem[AbsoluteY(4, 1)];
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

void C_CPU::LDA_A1(WORD opcode)//(Indirect X), 6 cycles //indexed indrect
{
	m_regA = systemMem[IndirectX(6)];
	if(m_regA == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::LDA_B1(WORD opcode)//(Indirect)Y, 5 cycles(+1 if page crossed)//indirect Indexed
{
	WORD before = m_pc & 0xFF00;//page before addition

	m_regA = systemMem[IndirectY(5, 1)];
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

/*************** LDX FUNCTIONS ************************/

void C_CPU::LDX_A2(WORD opcode)//Immediate, 2 cycles
{
	//load one byte of (system) memory into the Xregister
	m_regX = systemMem[Immediate(2)];
	if(m_regX == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}
/*
void C_CPU::LDX_A6(WORD opcode)//Zero_Page, 3 cycles
{
	//load one byte of (system) memory into the Xregister

	m_regX = BYTE(ZeroPage(3));
	if(m_regX == 0)
	  m_flagZ = 1;
	if((m_regX & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::LDX_B6(WORD opcode)//Zero_Page Y, 4 cycles
{
	//load one byte of (system) memory into the Xregister
	m_regX = BYTE(ZeroPageY(4));
	if(m_regX == 0)
	  m_flagZ = 1;
	if((m_regX & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::LDX_AE(WORD opcode)//Absolute, 4 cycles
{
	//load one byte of (system) memory into the Xregister
	m_regX = BYTE(Absolute(4));
	if(m_regX == 0)
	  m_flagZ = 1;
	if((m_regX & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::LDX_BE(WORD opcode)//Absolute Y, 4 cycles(+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition

	//load one byte of (system) memory into the Xregister
	m_regX = BYTE(AbsoluteY(4, 1));
	if(m_regX == 0)
	  m_flagZ = 1;
	if((m_regX & 128) == 128)
	  m_flagN = 1;

	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

/*************** LDY FUNCTIONS ************************/

void C_CPU::LDY_A0(WORD opcode)//Immediate, 2 cycles
{
	//now load one byte of (system) memory into the Yregister
	m_regY = systemMem[Immediate(2)];

	if(m_regY == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	if(m_regY  & 0x80 == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}
/*
void C_CPU::LDY_A4(WORD opcode)//Zero_Page, 3 cycles
{
	//now load one byte of (system) memory into the Yregister


	if(m_regY == 0)
	  m_flagZ = 1;
	if((m_regY & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::LDY_B4(WORD opcode)//Zero_Page X, 4 cycles
{
	//now load one byte of (system) memory into the Yregister


	if(m_regY == 0)
	  m_flagZ = 1;
	if((m_regY & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::LDY_AC(WORD opcode)//Absolute, 4 cycles
{
	//now load one byte of (system) memory into the Yregister


	if(m_regY == 0)
	  m_flagZ = 1;
	if((m_regY & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::LDY_BC(WORD opcode)//Absolute X, 4 cycles(+1 if page crossed)
{
	
	WORD before = m_pc & 0xFF00;//page before addition
	//now load one byte of (system) memory into the Yregister


	if(m_regY == 0)
	  m_flagZ = 1;
	if((m_regY & 128) == 128)
	  m_flagN = 1;

	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

/*************** STA FUNCTIONS ************************/
void C_CPU::STA_85(WORD opcode)//Zero Page, 3 cycles
{
	WORD data = ZeroPage(3);
	//stores accumulator in memory.
	systemMem[data] = m_regA;
}

void C_CPU::STA_95(WORD opcode)//Zero_Page X, 4 cycles
{
	WORD data = ZeroPageX(4); 
	//stores accumulator in memory. 
	systemMem[data] = m_regA;	
}

void C_CPU::STA_8D(WORD opcode)//Absolute, 4 cycles
{
	//stores accumulator in memory.
	systemMem[Absolute(4)] = m_regA;
}

void C_CPU::STA_9D(WORD opcode)//Absolute X, 5 cycles
{
	//stores accumulator in memory.
	systemMem[AbsoluteX(5)] = m_regA;
}

void C_CPU::STA_99(WORD opcode)//Absolute Y, 5 cycles
{
	//stores accumulator in memory.
	systemMem[AbsoluteY(5)] = m_regA;
}

void C_CPU::STA_81(WORD opcode)//Indirect X, 6 cycles
{
	//stores accumulator in memory.
	systemMem[IndirectX(6)] = m_regA;
}

void C_CPU::STA_91(WORD opcode)//Indirect Y, 6 cycles
{
	//stores accumulator in memory.
	systemMem[IndirectX(6)] = m_regA;
}

/*************** STX FUNCTIONS *************************/
void C_CPU::STX_86(WORD opcode)//Zero Page, 3 cycles
{
	WORD data = ZeroPageX(3);
	//stores X register in memory
	systemMem[data] = m_regX;
}

void C_CPU::STX_96(WORD opcode)//Zero_Page Y, 4 cycles
{
	//stores X register in memory
	systemMem[ZeroPageY(4)] = m_regX;
}

void C_CPU::STX_8E(WORD opcode)//Absolute, 4 cycles
{
	//stores X register in memory
	systemMem[Absolute(4)] = m_regX;
}

/*************** STY FUNCTIONS *************************/
void C_CPU::STY_84(WORD opcode)//Zero Page, 3 cycles
{
	//stores Y register in memory
	systemMem[ZeroPage(3)] = m_regY;
}

void C_CPU::STY_94(WORD opcode)//Zero_Page X, 4 cycles
{
	//stores Y register in memory
	systemMem[ZeroPage(3)] = m_regY;
}

void C_CPU::STY_8C(WORD opcode)//Absolute, 4 cycles
{
	//stores Y register in memory
	systemMem[ZeroPage(3)] = m_regY;
}

#endif