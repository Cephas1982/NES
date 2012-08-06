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

#endif