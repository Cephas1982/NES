#ifndef INC_AND_DEC_OPS_CPP
#define INC_AND_DEC_OPS_CPP
#include "CPU.h"


//***************** INC FUNCTIONS******************************************

void C_CPU::INC_E6(WORD opcode)//Zero_page, 5 cycles
{
	//increment value in system memory
	WORD memLoc = ZeroPage(5);
	BYTE result = systemMem[memLoc] + 1;

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}

void C_CPU::INC_F6(WORD opcode)//Zero_page X, 6 cycles
{
	//increment value in system memory
	WORD memLoc = ZeroPageX(6);
	BYTE result = systemMem[memLoc] + 1;

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}

void C_CPU::INC_EE(WORD opcode)//Absolute, 6 cycles
{
	//increment value in system memory
	WORD memLoc = Absolute(6);
	BYTE result = systemMem[memLoc] + 1;

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}

void C_CPU::INC_FE(WORD opcode)//Absolute X, 7 cycles
{
	//increment value in system memory
	WORD memLoc = AbsoluteX(7);
	BYTE result = systemMem[memLoc] + 1;

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}

//***************** INX FUNCTIONS******************************************
void C_CPU::INX_E8(WORD opcode)//Implied, 2 cycles
{
	m_regX++;

	//Set Z
	if(m_regX  == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//set N
	if((m_regX & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	  
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
	else
	  m_flagZ = 0;

	//set N
	if((m_regY & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;


	m_cycleCount += 2;
	m_pc++;
}

//***************** DEC FUNCTIONS******************************************

void C_CPU::DEC_C6(WORD opcode)//Zero_page, 5 cycles
{
	//increment value in system memory
	WORD memLoc = ZeroPage(5);
	BYTE result = systemMem[memLoc] - 1;

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}

void C_CPU::DEC_D6(WORD opcode)//Zero_page X, 6 cycles
{
	//increment value in system memory
	WORD memLoc = ZeroPageX(6);
	BYTE result = systemMem[memLoc] - 1;

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}

void C_CPU::DEC_CE(WORD opcode)//Absolute, 6 cycles
{
	//increment value in system memory
	WORD memLoc = Absolute(6);
	BYTE result = systemMem[memLoc] - 1;

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}

void C_CPU::DEC_DE(WORD opcode)//Absolute X, 7 cycles
{
	//increment value in system memory
	WORD memLoc = AbsoluteX(7);
	BYTE result = systemMem[memLoc] - 1;

	//Set Z
	if(result  == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//set N
	if((result & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;

	//put result back in memory
	systemMem[memLoc] = result;
}

//***************** DEX FUNCTIONS******************************************
void C_CPU::DEX_CA(WORD opcode)//Implied, 2 cycles
{
	m_regX--;

	//Set Z
	if(m_regX == 0)
	  m_flagZ = 1;
	else
	  m_flagZ = 0;

	//set N
	if((m_regX & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;


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
	else
	  m_flagZ = 0;

	//set N
	if((m_regY & 0x80) == 0x80)
	  m_flagN = 1;
	else
	  m_flagN = 0;


	m_cycleCount += 2;
	m_pc++;
}

#endif