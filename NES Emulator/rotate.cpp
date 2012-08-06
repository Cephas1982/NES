#pragma once
#ifndef ROTATE_CPP
#define ROTATE_CPP
#include "CPU.h"


//Move each of the bits in either A or M one place to the right.
//Bit 7 is filled with the current value of the carry flag whilst the old bit 0 becomes the new carry flag value.

void C_CPU::ROR_6A(WORD opcode)//Accumulator 2 cycles
{
	// remember old carry flag. This will be bit 7 after shift
	bool oldCarry = m_flagC;

	// the old bit 0 becomes the new carry flag value.
	if(m_regA & 0x01)
		m_flagC = 1;
	else 
		m_flagC = 0;

	// shift right 1 place
	m_regA >>= 1;

	// set N flag if bit 7 of the result is set (since bit 7 is set to the old carry flag we can set it like this)
	if(oldCarry)
		m_flagN = 1;
	else
		m_flagN = 0;

	// set bit 7 to the carry flag (prior to shift)
	if(oldCarry)
		m_regA |= 1 << 7;
	else
		m_regA &= ~(1 << 7);

	// set Z flag if the result == 0
	if(m_regA == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// increment cycles and counter
	m_cycleCount += 2;
	m_pc++;
}
void C_CPU::ROR_66(WORD opcode)//Zero page, 5 cycles
{
	WORD memLoc = ZeroPage(5);
	WORD result = systemMem[memLoc];

	// remember old carry flag. This will be bit 7 after shift
	bool oldCarry = m_flagC;

	// the old bit 0 becomes the new carry flag value.
	if(result & 0x01)
		m_flagC = 1;
	else 
		m_flagC = 0;

	// shift right 1 place
	result >>= 1;

	// set N flag if bit 7 of the result is set (since bit 7 is set to the old carry flag we can set it like this)
	if(oldCarry)
		m_flagN = 1;
	else
		m_flagN = 0;

	// set bit 7 to the carry flag (prior to shift)
	if(oldCarry)
		result |= 1 << 7;
	else
		result &= ~(1 << 7);

	// set Z flag if the result == 0
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}
void C_CPU::ROR_76(WORD opcode)// Zero page X, 6 cycles
{
	WORD memLoc = ZeroPageX(6);
	WORD result = systemMem[memLoc];

	// remember old carry flag. This will be bit 7 after shift
	bool oldCarry = m_flagC;

	// the old bit 0 becomes the new carry flag value.
	if(result & 0x01)
		m_flagC = 1;
	else 
		m_flagC = 0;

	// shift right 1 place
	result >>= 1;

	// set N flag if bit 7 of the result is set (since bit 7 is set to the old carry flag we can set it like this)
	if(oldCarry)
		m_flagN = 1;
	else
		m_flagN = 0;

	// set bit 7 to the carry flag (prior to shift)
	if(oldCarry)
		result |= 1 << 7;
	else
		result &= ~(1 << 7);

	// set Z flag if the result == 0
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	//put result back in memory
	systemMem[memLoc] = result;

}
void C_CPU::ROR_6E(WORD opcode)// Absolute, 6 cycles
{
	WORD memLoc = Absolute(6);
	WORD result = systemMem[memLoc];

	// remember old carry flag. This will be bit 7 after shift
	bool oldCarry = m_flagC;

	// the old bit 0 becomes the new carry flag value.
	if(result & 0x01)
		m_flagC = 1;
	else 
		m_flagC = 0;

	// shift right 1 place
	result >>= 1;

	// set N flag if bit 7 of the result is set (since bit 7 is set to the old carry flag we can set it like this)
	if(oldCarry)
		m_flagN = 1;
	else
		m_flagN = 0;

	// set bit 7 to the carry flag (prior to shift)
	if(oldCarry)
		result |= 1 << 7;
	else
		result &= ~(1 << 7);

	// set Z flag if the result == 0
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	//put result back in memory
	systemMem[memLoc] = result;

}
void C_CPU::ROR_7E(WORD opcode)// Absolute X, 7 cycles
{
	WORD memLoc = AbsoluteX(7);
	WORD result = systemMem[memLoc];

	// remember old carry flag. This will be bit 7 after shift
	bool oldCarry = m_flagC;

	// the old bit 0 becomes the new carry flag value.
	if(result & 0x01)
		m_flagC = 1;
	else 
		m_flagC = 0;

	// shift right 1 place
	result >>= 1;

	// set N flag if bit 7 of the result is set (since bit 7 is set to the old carry flag we can set it like this)
	if(oldCarry)
		m_flagN = 1;
	else
		m_flagN = 0;

	// set bit 7 to the carry flag (prior to shift)
	if(oldCarry)
		result |= 1 << 7;
	else
		result &= ~(1 << 7);

	// set Z flag if the result == 0
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	//put result back in memory
	systemMem[memLoc] = result;

}
//In case of ROL - Rotate Left
//Move each of the bits in either A or M one place to the left. 
//Bit 0 is filled with the current value of the carry flag whilst the old bit 7 becomes the new carry flag value.
void C_CPU::ROL_2A(WORD opcode)//accumulator 2 cycles
{
	// remember old carry flag. This will be bit 7 after shift
	bool oldCarry = m_flagC;

	// the old bit 7 becomes the new carry flag value.
	if(m_regA & 0x80)
		m_flagC = 1;
	else 
		m_flagC = 0;

	// shift left 1 place
	m_regA <<= 1;

	// set N flag if bit 7 of the result is set
	if(m_regA & 0x80)
		m_flagN = 1;
	else
		m_flagN = 0;

	// set bit 0 to the carry flag (prior to shift)
	if(oldCarry)
		m_regA |= 1 << 0;
	else
		m_regA &= ~(1 << 0);

	// set Z flag if the result == 0
	if(m_regA == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	// increment cycles and counter
	m_cycleCount += 2;
	m_pc++;
}
void C_CPU::ROL_26(WORD opcode)// zero page, 5 cycles
{
	WORD memLoc = ZeroPage(5);
	WORD result = systemMem[memLoc];
	// remember old carry flag. This will be bit 7 after shift
	bool oldCarry = m_flagC;

	// the old bit 7 becomes the new carry flag value.
	if(m_regA & 0x80)
		m_flagC = 1;
	else 
		m_flagC = 0;

	// shift left 1 place
	result <<= 1;

	// set N flag if bit 7 of the result is set
	if(result & 0x80)
		m_flagN = 1;
	else
		m_flagN = 0;

	// set bit 0 to the carry flag (prior to shift)
	if(oldCarry)
		result |= 1 << 0;
	else
		result &= ~(1 << 0);

	// set Z flag if the result == 0
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}
void C_CPU::ROL_36(WORD opcode)//zero page X, 6 cycles
{

	WORD memLoc = ZeroPageX(6);
	WORD result = systemMem[memLoc];
	// remember old carry flag. This will be bit 7 after shift
	bool oldCarry = m_flagC;

	// the old bit 7 becomes the new carry flag value.
	if(result & 0x80)
		m_flagC = 1;
	else 
		m_flagC = 0;

	// shift left 1 place
	result <<= 1;

	// set N flag if bit 7 of the result is set
	if(result & 0x80)
		m_flagN = 1;
	else
		m_flagN = 0;

	// set bit 0 to the carry flag (prior to shift)
	if(oldCarry)
		result |= 1 << 0;
	else
		result &= ~(1 << 0);

	// set Z flag if the result == 0
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	//put result back in memory
	systemMem[memLoc] = result;

}
void C_CPU::ROL_2E(WORD opcode)// absolute, 6 cycles
{

	WORD memLoc = Absolute(6);
	WORD result = systemMem[memLoc];
	// remember old carry flag. This will be bit 7 after shift
	bool oldCarry = m_flagC;

	// the old bit 7 becomes the new carry flag value.
	if(result & 0x80)
		m_flagC = 1;
	else 
		m_flagC = 0;

	// shift left 1 place
	result <<= 1;

	// set N flag if bit 7 of the result is set
	if(result & 0x80)
		m_flagN = 1;
	else
		m_flagN = 0;

	// set bit 0 to the carry flag (prior to shift)
	if(oldCarry)
		result |= 1 << 0;
	else
		result &= ~(1 << 0);

	// set Z flag if the result == 0
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	//put result back in memory
	systemMem[memLoc] = result;

}
void C_CPU::ROL_3E(WORD opcode)// absolute X, 7 cycles
{
	WORD memLoc = AbsoluteX(7);
	WORD result = systemMem[memLoc];
	// remember old carry flag. This will be bit 7 after shift
	bool oldCarry = m_flagC;

	// the old bit 7 becomes the new carry flag value.
	if(result & 0x80)
		m_flagC = 1;
	else 
		m_flagC = 0;

	// shift left 1 place
	result <<= 1;

	// set N flag if bit 7 of the result is set
	if(result & 0x80)
		m_flagN = 1;
	else
		m_flagN = 0;

	// set bit 0 to the carry flag (prior to shift)
	if(oldCarry)
		result |= 1 << 0;
	else
		result &= ~(1 << 0);

	// set Z flag if the result == 0
	if(result == 0)
		m_flagZ = 1;
	else
		m_flagZ = 0;

	//put result back in memory
	systemMem[memLoc] = result;

}
#endif