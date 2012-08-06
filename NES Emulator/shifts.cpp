#pragma once
#ifndef SHIFTS_CPP
#define SHIFTS_CPP
#include "cpu.h"

//LSR - logical shift right.  
//What was bit 0 is moved to the carry flag. 
//bit 7 is set to 0;
//Z flag is set if result is zero
void C_CPU::LSR_4A(WORD opcode)//accumulator 2cycles
{
	//carry flag is bit 0 before shift
	if(m_regA & 0x01)
		m_flagC = 1;
	else
		m_flagC = 0;
	
	// shift right
	m_regA >>= 1; 

	// if result is zero set the Z flag
	if(m_regA == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// this will never be set b/c bit 7 is always 0 after shift
	m_flagN = 0;

	// increment counter  (todo:  just one cycle ??????)
	m_pc++;
	m_cycleCount+= 2;
}
void C_CPU::LSR_46(WORD opcode)//zero page 5cycles
{
	//carry flag is bit 0 before shift
	WORD memLoc = ZeroPage(5);
	WORD result = systemMem[memLoc];
	if(result & 0x01)
		m_flagC = 1;
	else
		m_flagC = 0;
	
	// shift right
	result >>= 1; 

	// if result is zero set the Z flag
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// this will never be set b/c bit 7 is always 0 after shift
	m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}
void C_CPU::LSR_56(WORD opcode)//zero pageX 6cycles
{
	//carry flag is bit 0 before shift
	WORD memLoc = ZeroPageX(6);
	WORD result = systemMem[memLoc];
	if(result & 0x01)
		m_flagC = 1;
	else
		m_flagC = 0;
	
	// shift right
	result >>= 1; 

	// if result is zero set the Z flag
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// this will never be set b/c bit 7 is always 0 after shift
	m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
} 
void C_CPU::LSR_4E(WORD opcode)//absolute 6cycles
{
	//carry flag is bit 0 before shift
	WORD memLoc = Absolute(6);
	WORD result = systemMem[memLoc];
	if(result & 0x01)
		m_flagC = 1;
	else
		m_flagC = 0;
	
	// shift right
	result >>= 1; 

	// if result is zero set the Z flag
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// this will never be set b/c bit 7 is always 0 after shift
	m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}
void C_CPU::LSR_5E(WORD opcode)//absoluteX 7cycles
{
	//carry flag is bit 0 before shift
	WORD memLoc = AbsoluteX(7);
	WORD result = systemMem[memLoc];
	if(result & 0x01)
		m_flagC = 1;
	else
		m_flagC = 0;
	
	// shift right
	result >>= 1; 

	// if result is zero set the Z flag
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// this will never be set b/c bit 7 is always 0 after shift
	m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}

//ASL - Arithmetic Shift Left
//A,Z,C,N = M*2 or M,Z,C,N = M*2
//This operation shifts all the bits of the accumulator or memory contents one bit left. Bit 0 is set to 0 and bit 7 is placed in the carry flag. 
//The effect of this operation is to multiply the memory contents by 2 (ignoring 2's complement considerations), 
//setting the carry if the result will not fit in 8 bits.

void C_CPU::ASL_0A(WORD opcode)//accumulator 2 cycles
{
	// carry flag is bit 7 before shift
	if(m_regA & 0x80)
		m_flagC = 1;
	else
		m_flagC = 0;
	
	// shift left
	m_regA <<= 1; 

	// if result is zero set the Z flag
	if(m_regA == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// set N flag if bit 7 is set
	if(m_regA & 0x80)
		m_flagN = 1;
	else
		m_flagN = 0;

	// increment counter  (todo:  just one cycle ??????)
	m_pc++;
	m_cycleCount+= 2;
}

void C_CPU::ASL_06(WORD opcode)//zero page, 5cycles
{
	WORD memLoc = ZeroPage(5);
	WORD result = systemMem[memLoc];

	// carry flag is bit 7 before shift	
	if(result & 0x80)
		m_flagC = 1;
	else
		m_flagC = 0;
	
	// shift left
	result <<= 1; 

	// if result is zero set the Z flag
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// set N flag if bit 7 is set
	if(result & 0x80)
		m_flagN = 1;
	else
		m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}
void C_CPU::ASL_16(WORD opcode)// zero page X, 6 cycles
{
	WORD memLoc = ZeroPageX(6);
	WORD result = systemMem[memLoc];

	// carry flag is bit 7 before shift	
	if(result & 0x80)
		m_flagC = 1;
	else
		m_flagC = 0;
	
	// shift left
	result <<= 1; 

	// if result is zero set the Z flag
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// set N flag if bit 7 is set
	if(result & 0x80)
		m_flagN = 1;
	else
		m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}
void C_CPU::ASL_0E(WORD opcode)// absolute, 6 cycles
{
	WORD memLoc = Absolute(6);
	WORD result = systemMem[memLoc];

	// carry flag is bit 7 before shift	
	if(result & 0x80)
		m_flagC = 1;
	else
		m_flagC = 0;
	
	// shift left
	result <<= 1; 

	// if result is zero set the Z flag
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// set N flag if bit 7 is set
	if(result & 0x80)
		m_flagN = 1;
	else
		m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}
void C_CPU::ASL_1E(WORD opcode)// absolute X, 7 cycles
{
	WORD memLoc = AbsoluteX(6);
	WORD result = systemMem[memLoc];

	// carry flag is bit 7 before shift	
	if(result & 0x80)
		m_flagC = 1;
	else
		m_flagC = 0;
	
	// shift left
	result <<= 1; 

	// if result is zero set the Z flag
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// set N flag if bit 7 is set
	if(result & 0x80)
		m_flagN = 1;
	else
		m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}
#endif