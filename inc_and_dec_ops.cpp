#ifndef INC_AND_DEC_OPS_CPP
#define INC_AND_DEC_OPS_CPP
#include "CPU.h"


//***************** INC FUNCTIONS******************************************

void C_CPU::INC_E6(WORD opcode)//Zero_page, 5 cycles
{
	//increment value in system memory (todo: rewrite functions to make more clear
	systemMem[m_pc + 1] += 1;

	//get result using zero page
	BYTE result = systemMem[ZeroPage(5)];

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;

	//set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::INC_F6(WORD opcode)//Zero_page X, 6 cycles
{
	//increment value in system memory (todo: rewrite functions to make more clear
	systemMem[m_pc + 1 + m_regX] += 1;

	//get the result
	BYTE result = systemMem[ZeroPageX(6)];

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;

	//set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::INC_EE(WORD opcode)//Absolute, 6 cycles
{
	//increment value in system memory (todo: rewrite functions to make more clear
	WORD BB = systemMem[m_pc + 1];
	WORD CC = systemMem[m_pc + 2];
	CC <<= 8; //0xCC00
	WORD ZZ = CC | BB;// 0xCCBB!!!
	systemMem[ZZ] += 1;

	//get the result
	BYTE result = systemMem[Absolute(6)];

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;

	//set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::INC_FE(WORD opcode)//Absolute X, 7 cycles
{
	//increment value in system memory (todo: rewrite functions to make more clear
	WORD BB = systemMem[m_pc + 1];
	WORD CC = systemMem[m_pc + 2];
	CC <<= 8; //0xCC00
	WORD ZZ = (CC | BB) + m_regX;// 0xCCBB!!!
	systemMem[ZZ] += 1;

	//get the result
	BYTE result = systemMem[AbsoluteX(7)];

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;

	//set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

//***************** INX FUNCTIONS******************************************
void C_CPU::INX_E8(WORD opcode)//Implied, 2 cycles
{
	m_regX++;

	//Set Z
	if(m_regX  == 0)
	  m_flagZ = 1;

	//set N
	if((m_regX & 128) == 128)
	  m_flagN = 1;
	  
	m_cycleCount += 2;
	m_pc++;
}

//***************** INY FUNCTIONS******************************************
void C_CPU::INY_C8(WORD opcode)//Implied, 2 cycles
{
	m_regY++;

	//Set Z
	if(m_regY == 0)
	  m_flagZ = 1;

	//set N
	if((m_regY & 128) == 128)
	  m_flagN = 1;

	m_cycleCount += 2;
	m_pc++;
}

//***************** DEC FUNCTIONS******************************************

void C_CPU::DEC_C6(WORD opcode)//Zero_page, 5 cycles
{
	//decrement value in system memory (todo: rewrite functions to make more clear
	systemMem[m_pc + 1] -= 1;

	//get result using zero page
	BYTE result = systemMem[ZeroPage(5)];

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;

	//set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::DEC_D6(WORD opcode)//Zero_page X, 6 cycles
{
	//decrement value in system memory (todo: rewrite functions to make more clear
	systemMem[m_pc + 1 + m_regX] -= 1;

	//get the result
	BYTE result = systemMem[ZeroPageX(6)];

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;

	//set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::DEC_CE(WORD opcode)//Absolute, 6 cycles
{
	//decrement value in system memory (todo: rewrite functions to make more clear
	WORD BB = systemMem[m_pc + 1];
	WORD CC = systemMem[m_pc + 2];
	CC <<= 8; //0xCC00
	WORD ZZ = CC | BB;// 0xCCBB!!!
	systemMem[ZZ] -= 1;

	//get the result
	BYTE result = systemMem[Absolute(6)];

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;

	//set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

void C_CPU::DEC_DE(WORD opcode)//Absolute X, 7 cycles
{
	//decrement value in system memory (todo: rewrite functions to make more clear
	WORD BB = systemMem[m_pc + 1];
	WORD CC = systemMem[m_pc + 2];
	CC <<= 8; //0xCC00
	WORD ZZ = (CC | BB) + m_regX;// 0xCCBB!!!
	systemMem[ZZ] -= 1;

	//get the result
	BYTE result = systemMem[AbsoluteX(7)];

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;

	//set N
	if((result & 128) == 128)
	  m_flagN = 1;
}

//***************** DEX FUNCTIONS******************************************
void C_CPU::DEX_CA(WORD opcode)//Implied, 2 cycles
{
	m_regX--;

	//Set Z
	if(m_regX == 0)
	  m_flagZ = 1;

	//set N
	if((m_regX & 128) == 128)
	  m_flagN = 1;

	m_cycleCount += 2;
	m_pc++;
}

//***************** DEY FUNCTIONS******************************************
void C_CPU::DEY_88(WORD opcode)//Implied, 2 cycles
{
	m_regY--;

	//Set Z
	if(m_regY == 0)
	  m_flagZ = 1;

	//set N
	if((m_regY & 128) == 128)
	  m_flagN = 1;

	m_cycleCount += 2;
	m_pc++;
}

#endif