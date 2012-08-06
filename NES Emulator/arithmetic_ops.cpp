#pragma once
#ifndef ARITHMETIC_OPS_CPP
#define ARITHMETIC_OPS_CPP
#include "CPU.h"

/*************** Arithmetic FUNCTIONS ************************/

//***************** ADC FUNCTIONS******************************************

void C_CPU::ADC_69(WORD opcode)//Immediate, 2 cycles
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[Immediate(2)];
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = old_A + BYTE(value + carryBit);
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}


void C_CPU::ADC_65(WORD opcode)//Zero_page, 3 cycles
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[ZeroPage(3)];
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = old_A + BYTE(value + carryBit);
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::ADC_75(WORD opcode)//Zero_page X, 4 cycles
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[ZeroPageX(4)];
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = old_A + BYTE(value + carryBit);
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::ADC_6D(WORD opcode)//Absolute, 4 cycles
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[Absolute(4)];
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = old_A + BYTE(value + carryBit);
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::ADC_7D(WORD opcode)//Absolute X, 4 cycles (+1 if page crossed)
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[AbsoluteX(4)];
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = old_A + BYTE(value + carryBit);
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::ADC_79(WORD opcode)//Absolute Y, 4 cycles (+1 if page crossed)
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[AbsoluteY(4)];
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = old_A + BYTE(value + carryBit);
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::ADC_61(WORD opcode)//Indirect X, 6 cycles
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[IndirectX(6)];
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = old_A + BYTE(value + carryBit);
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::ADC_71(WORD opcode)//Indirect Y, 5 cycles (+1 if page crossed)
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[IndirectY(5)];
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = old_A + BYTE(value + carryBit);
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

//***************** SBC FUNCTIONS******************************************

void C_CPU::SBC_E9(WORD opcode)//Immediate, 2 cycles
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[Immediate(2)] ^ 0xFF;
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = unsigned char(old_A) + unsigned char(value) + carryBit;
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}


void C_CPU::SBC_E5(WORD opcode)//Zero_page, 3 cycles
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[ZeroPage(3)] ^ 0xFF;
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = unsigned char(old_A) + unsigned char(value) + carryBit;
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::SBC_F5(WORD opcode)//Zero_page X, 4 cycles
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[ZeroPageX(4)] ^ 0xFF;
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = unsigned char(old_A) + unsigned char(value) + carryBit;
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::SBC_ED(WORD opcode)//Absolute, 4 cycles
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[Absolute(4)] ^ 0xFF;
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = unsigned char(old_A) + unsigned char(value) + carryBit;
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::SBC_FD(WORD opcode)//Absolute X, 4 cycles (+1 if page crossed)
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[AbsoluteX(4)] ^ 0xFF;
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = unsigned char(old_A) + unsigned char(value) + carryBit;
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::SBC_F9(WORD opcode)//Absolute Y, 4 cycles (+1 if page crossed)
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[AbsoluteY(4)] ^ 0xFF;
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = unsigned char(old_A) + unsigned char(value) + carryBit;
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::SBC_E1(WORD opcode)//Indirect X, 6 cycles
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[IndirectX(6)] ^ 0xFF;
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = unsigned char(old_A) + unsigned char(value) + carryBit;
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::SBC_F1(WORD opcode)//Indirect Y, 5 cycles (+1 if page crossed)
{
	int carryBit = 0;//TODO change flags from bools to bit, for now this figures out what the carry bit is
	if(m_flagC)
		carryBit = 1;

	signed char value = systemMem[IndirectY(5)] ^ 0xFF;
	char old_A = m_regA;

	//add A, M, C
	char result = m_regA + value + carryBit;
	

	if((old_A ^ result) & ( value ^ result) & 0x80)
		m_flagV = 1;
	else
		m_flagV = 0;

	int carryCheck = unsigned char(old_A) + unsigned char(value) + carryBit;
	if(carryCheck > 255){
		m_flagC = 1;
	}
	else
	{
		m_flagC = 0;
	}
	m_regA = result;


	//SET Z
	if(result == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;
	
	//SET N
	if((m_regA & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

//***************** CMP FUNCTIONS******************************************
void C_CPU::CMP_C9(WORD opcode)//Immediate, 2 cycles
{
	BYTE mem = systemMem[Immediate(2)];
	BYTE result = m_regA - mem;

	//Set C
	if(m_regA >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regA == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::CMP_C5(WORD opcode)//Zero_page, 3 cycles
{
	BYTE mem = systemMem[ZeroPage(3)];
	BYTE result = m_regA - mem;

	//Set C
	if(m_regA >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regA == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::CMP_D5(WORD opcode)//Zero_page X, 4 cycles
{
	BYTE mem = systemMem[ZeroPageX(4)];
	BYTE result = m_regA - mem;

	//Set C
	if(m_regA >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regA == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::CMP_CD(WORD opcode)//Absolute, 4 cycles
{
	BYTE mem = systemMem[Absolute(4)];
	BYTE result = m_regA - mem;

	//Set C
	if(m_regA >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regA == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::CMP_DD(WORD opcode)//Absolute X, 4 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition
	BYTE mem = systemMem[AbsoluteX(4)];
	BYTE result = m_regA - mem;

	//Set C
	if(m_regA >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regA == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

void C_CPU::CMP_D9(WORD opcode)//Absolute Y, 4 cycles (+1 if page crossed)
{

	WORD before = m_pc & 0xFF00;//page before addition	
	BYTE mem = systemMem[AbsoluteY(4)];
	BYTE result = m_regA - mem;

	//Set C
	if(m_regA >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regA == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

void C_CPU::CMP_C1(WORD opcode)//Indirect X, 6 cycles
{
	BYTE mem = systemMem[IndirectX(6)];
	BYTE result = m_regA - mem;

	//Set C
	if(m_regA >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regA == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::CMP_D1(WORD opcode)//Indirect Y, 5 cycles (+1 if page crossed)
{
	WORD before = m_pc & 0xFF00;//page before addition
	BYTE mem = systemMem[IndirectY(5)];
	BYTE result = m_regA - mem;

	//Set C
	if(m_regA >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regA == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	//check if page crossed
	if((m_pc & 0xFF00) != before)
		m_cycleCount ++;//1 more cycle if page crossed	
}

//***************** CPX FUNCTIONS******************************************
void C_CPU::CPX_E0(WORD opcode)//Immediate, 2 cycles
{
	BYTE mem = systemMem[Immediate(2)];
	BYTE result = m_regX - mem;

	//Set C
	if(m_regX >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regX == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::CPX_E4(WORD opcode)//Zero_page, 3 cycles
{
	BYTE mem = systemMem[ZeroPage(3)];
	BYTE result = m_regX - mem;

	//Set C
	if(m_regX >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regX == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}
void C_CPU::CPX_EC(WORD opcode)//Absolute, 4 cycles
{
	BYTE mem = systemMem[Absolute(4)];
	BYTE result = m_regX - mem;

	//Set C
	if(m_regX >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regX == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

//***************** CPY FUNCTIONS******************************************
void C_CPU::CPY_C0(WORD opcode)//Immediate, 2 cycles
{
	BYTE mem = systemMem[Immediate(2)];
	BYTE result = m_regY - mem;

	//Set C
	if(m_regY >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regY == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}

void C_CPU::CPY_C4(WORD opcode)//Zero_page, 3 cycles
{
	BYTE mem = systemMem[ZeroPage(3)];
	BYTE result = m_regY - mem;

	//Set C
	if(m_regY >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regY == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}
void C_CPU::CPY_CC(WORD opcode)//Absolute, 4 cycles
{
	BYTE mem = systemMem[Absolute(4)];
	BYTE result = m_regY - mem;

	//Set C
	if(m_regY >= mem)
	  m_flagC = 1;
	else
	  m_flagC = 0;

	//Set Z
	if(m_regY == mem)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//Set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;
}
#endif