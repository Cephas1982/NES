#ifndef ADDRESS_MODES
#define ADDRESS_MODES
#include "CPU.h"

BYTE C_CPU::ZeroPage(int cycleCount)
{
	//get result using zero page
	WORD result = m_pc + 1;

	m_cycleCount += cycleCount;
	m_pc+= 2;

	return BYTE(result);
	//todo TEST
}

WORD C_CPU::ZeroPageX(int cycleCount)
{
	//stores accumulator in memory. 
	WORD result = m_pc + 1 + m_regX;
		
	m_cycleCount += cycleCount;
	m_pc+= 2;

	return result;
	//todo TEST
}

WORD C_CPU::ZeroPageY(int cycleCount)//zero page Y
{
	//stores accumulator in memory. 
	WORD result = m_pc + 1 + m_regY;
		
	m_cycleCount += cycleCount;
	m_pc+= 2;

	return result;
	//todo TEST
}

WORD C_CPU::Absolute(int cycleCount)
{
	//Trying to get 0xCCBB
	WORD BB = systemMem[m_pc + 1];
	WORD CC = systemMem[m_pc + 2];
	CC <<= 8; //0xCC00
	WORD result = CC | BB;// 0xCCBB!!!
	
	m_cycleCount += cycleCount;
	m_pc+= 3;

	return result;
	//todo TEST
}

WORD C_CPU::AbsoluteX(int cycleCount, int pagePlus)//Absolute X
{
	//stores accumulator in memory.
	WORD BB = systemMem[m_pc + 1];
	WORD CC = systemMem[m_pc + 2];
	CC <<= 8; //0xCC00
	WORD result = (CC | BB) + m_regX;// 0xCCBB!!!
	
	//check for page cross
	if(pagePlus != 0){
		if(BB + m_regX <= 255)//if the page is not crossed do not add cycles
			pagePlus = 0;
	}

	m_cycleCount += cycleCount + pagePlus;
	m_pc+= 3;
	return result;
	//todo TEST
}

WORD C_CPU::AbsoluteY(int cycleCount, int pagePlus)//Absolute Y
{
	//stores accumulator in memory.
	WORD BB = systemMem[m_pc + 1];
	WORD CC = systemMem[m_pc + 2];
	CC <<= 8; //0xCC00
	WORD result = (CC | BB) + m_regY;// 0xCCBB!!!

	//check for page cross
	if(pagePlus != 0){
		if(BB + m_regY <= 255)//if the page is not crossed do not add cycles
			pagePlus = 0;
	}

	m_cycleCount += cycleCount + pagePlus;
	m_pc+= 3;

	return result;
	//todo TEST
}

WORD C_CPU::Indirect(int cycleCount)//Indirect X
{
	//stores accumulator in memory.
	WORD BB = systemMem[m_pc + 1];
	WORD CC = systemMem[m_pc + 2];
	CC <<= 8;
	WORD CCBB = (CC | BB);

	WORD XX = CCBB;
	WORD YY = CCBB + 1;	
	YY <<= 8;
	WORD result = (YY | XX);// 0xYYXX
	
	m_cycleCount += cycleCount;
	m_pc += 3;

	return result;
	//todo TEST
}

WORD C_CPU::IndirectX(int cycleCount)//Indirect X
{
	//stores accumulator in memory.
	WORD BB = systemMem[m_pc + 1];
	WORD XX = BB;
	WORD YY = XX + 1;	
	YY <<= 8;
	WORD result = (YY | XX) + m_regX;// 0xYYXX
	
	m_cycleCount += cycleCount;
	m_pc += 2;

	return result;
	//todo TEST
}

WORD C_CPU::IndirectY(int cycleCount, int pagePlus)//Indirect Y
{
	//stores accumulator in memory.
	WORD BB = systemMem[m_pc + 1];
	WORD XX = BB;
	WORD YY = XX + 1;	
	YY <<= 8;
	WORD result = (YY | XX) + m_regY;// 0xYYXX
	
	//check for page cross
	if(pagePlus != 0){
		if(XX + m_regY <= 255)//if the page is not crossed do not add cycles
			pagePlus = 0;
	}

	m_cycleCount += cycleCount + pagePlus;
	m_pc += 2;

	return result;
	//todo TEST
	
}

WORD C_CPU::Immediate(int cycleCount)
{
	WORD result = m_pc + 1;
	
	m_cycleCount+= cycleCount;
	m_pc+= 2;//adv ance to next program instruction

	return result;
}

#endif