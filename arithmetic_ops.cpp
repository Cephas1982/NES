#ifndef ARITHMETIC_OPS_CPP
#define ARITHMETIC_OPS_CPP
#include "CPU.h"

/*************** Arithmetic FUNCTIONS ************************/

//***************** ADC FUNCTIONS******************************************
/*
void C_CPU::ADC_69(WORD opcode)//Immediate, 2 cycles
{
	int result = m_regA + Memory(1 byte vaule) + CarryFlagBit;


	//SET C
	if(result > 255)
	  carryFlagBit = 1; //overflow is greater than 255?
	else
	  carryFlagBit = 0;	

	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET V   TODO: WTF  major problem

	//SET N
	if(bit 7 of result is set)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}


void C_CPU::ADC_65(WORD opcode)//Zero_page, 3 cycles
{
	//TODO NEED TO READ
}

void C_CPU::ADC_75(WORD opcode)//Zero_page X, 4 cycles
{
	//TODO NEED TO READ
}

void C_CPU::ADC_6D(WORD opcode)//Absolute, 4 cycles
{
	//TODO NEED TO READ
}

void C_CPU::ADC_7D(WORD opcode)//Absolute X, 4 cycles (+1 if page crossed)
{
	//TODO NEED TO READ
}

void C_CPU::ADC_79(WORD opcode)//Absolute Y, 4 cycles (+1 if page crossed)
{
	//TODO NEED TO READ
}

void C_CPU::ADC_61(WORD opcode)//Indirect X, 6 cycles
{
	//TODO NEED TO READ
}

void C_CPU::ADC_71(WORD opcode)//Indirect Y, 5 cycles (+1 if page crossed)
{
	//TODO NEED TO READ
}
*/
//***************** SBC FUNCTIONS******************************************
/*
void C_CPU::SBC_E9(WORD opcode)//Immediate, 2 cycles
{
	//TODO NEED TO READ
}


void C_CPU::SBC_E5(WORD opcode)//Zero_page, 3 cycles
{
	//TODO NEED TO READ
}

void C_CPU::SBC_F5(WORD opcode)//Zero_page X, 4 cycles
{
	//TODO NEED TO READ
}

void C_CPU::SBC_ED(WORD opcode)//Absolute, 4 cycles
{
	//TODO NEED TO READ
}

void C_CPU::SBC_FD(WORD opcode)//Absolute X, 4 cycles (+1 if page crossed)
{
	//TODO NEED TO READ
}

void C_CPU::SBC_F9(WORD opcode)//Absolute Y, 4 cycles (+1 if page crossed)
{
	//TODO NEED TO READ
}

void C_CPU::SBC_E1(WORD opcode)//Indirect X, 6 cycles
{
	//TODO NEED TO READ
}

void C_CPU::SBC_F1(WORD opcode)//Indirect Y, 5 cycles (+1 if page crossed)
{
	//TODO NEED TO READ
}
*/
//***************** CMP FUNCTIONS******************************************
void C_CPU::CMP_C9(WORD opcode)//Immediate, 2 cycles
{
	BYTE result = m_regA - Immediate(2);

	//Set C
	if(m_regA >= result)
	  m_flagC = 1;

	//Set Z
	if(m_regA == result)
	  m_flagZ = 1;

	//Set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::CMP_C5(WORD opcode)//Zero_page, 3 cycles
{
	BYTE result = m_regA - ZeroPage(3);

	//Set C
	if(m_regA >= result)
	  m_flagC = 1;

	//Set Z
	if(m_regA == result)
	  m_flagZ = 1;

	//Set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::CMP_D5(WORD opcode)//Zero_page X, 4 cycles
{
	BYTE result = m_regA - ZeroPageX(4);

	//Set C
	if(m_regA >= result)
	  m_flagC = 1;

	//Set Z
	if(m_regA == result)
	  m_flagZ = 1;

	//Set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::CMP_CD(WORD opcode)//Absolute, 4 cycles
{
	BYTE result = m_regA - Absolute(4);

	//Set C
	if(m_regA >= result)
	  m_flagC = 1;

	//Set Z
	if(m_regA == result)
	  m_flagZ = 1;

	//Set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::CMP_DD(WORD opcode)//Absolute X, 4 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition
	BYTE result = m_regA - AbsoluteX(4);

	//Set C
	if(m_regA >= result)
	  m_flagC = 1;

	//Set Z
	if(m_regA == result)
	  m_flagZ = 1;

	//Set N
	if((result & 128) == 128)
	  m_flagN = 1;

	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

void C_CPU::CMP_D9(WORD opcode)//Absolute Y, 4 cycles (+1 if page crossed)
{

	WORD before = m_pc & 0xFF00;//page before addition	
	BYTE result = m_regA - AbsoluteY(4);

	//Set C
	if(m_regA >= result)
	  m_flagC = 1;

	//Set Z
	if(m_regA == result)
	  m_flagZ = 1;

	//Set N
	if((result & 128) == 128)
	  m_flagN = 1;

	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

void C_CPU::CMP_C1(WORD opcode)//Indirect X, 6 cycles
{
	BYTE result = m_regA - IndirectX(6);

	//Set C
	if(m_regA >= result)
	  m_flagC = 1;

	//Set Z
	if(m_regA == result)
	  m_flagZ = 1;

	//Set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::CMP_D1(WORD opcode)//Indirect Y, 5 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition
	BYTE result = m_regA - IndirectY(5);

	//Set C
	if(m_regA >= result)
	  m_flagC = 1;

	//Set Z
	if(m_regA == result)
	  m_flagZ = 1;

	//Set N
	if((result & 128) == 128)
	  m_flagN = 1;

	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}
/*
//***************** CPX FUNCTIONS******************************************
void C_CPU::CPX_E0(WORD opcode)//Immediate, 2 cycles
{
	BYTE result = regX - MemoryValue;

	//Set C
	if(regX >= result)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(regX == result)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if(bit 7 of result is set)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::CPX_E4(WORD opcode)//Zero_page, 3 cycles
{
	BYTE result = regX - MemoryValue;

	//Set C
	if(regX >= result)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(regX == result)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if(bit 7 of result is set)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}
void C_CPU::CPX_EC(WORD opcode)//Absolute, 4 cycles
{
	BYTE result = regX - MemoryValue;

	//Set C
	if(regX >= result)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(regX == result)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if(bit 7 of result is set)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

//***************** CPY FUNCTIONS******************************************
void C_CPU::CPY_C0(WORD opcode)//Immediate, 2 cycles
{
	BYTE result = regY - MemoryValue;

	//Set C
	if(regY >= result)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(regY == result)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if(bit 7 of result is set)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::CPY_C4(WORD opcode)//Zero_page, 3 cycles
{
	BYTE result = regY - MemoryValue;

	//Set C
	if(regY >= result)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(regY == result)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if(bit 7 of result is set)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}
void C_CPU::CPY_CC(WORD opcode)//Absolute, 4 cycles
{
	BYTE result = regY - MemoryValue;

	//Set C
	if(regY >= result)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(regY == result)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if(bit 7 of result is set)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}
*/
#endif