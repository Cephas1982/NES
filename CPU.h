#ifndef CPU_H
#define CPU_H
#define HEADER 16 //header size in bytes
#include <iostream>
typedef unsigned short int WORD;
typedef unsigned char BYTE;


class C_CPU{

private:
	//CPU-----------------------------------------------------------------------------
	int m_cycleCount;//track clock cycles
	WORD m_pc;//program counter - Pointer to track where to read from____
	//stackPointer TODO <- this
	BYTE m_regA, m_regX, m_regY, m_regS; //Accumulator register -128 to 127, x register, y register, stack register(0-255 no overflow)
	//Carry, Zero, Interrupt Disable, Decimal Mode, Break cmd, Overflow, Negative
	bool m_flagC, m_flagZ, m_flagI, m_flagD, m_flagB, m_flagV, m_flagN;

	//MEMORY-------------------------
	BYTE header[16];
	BYTE systemMem[0xFFFF +1];
	BYTE ppuMem[0xFFFF +1];

public:
	C_CPU();
	~C_CPU();

	void RESET();//TODO init for now / reset button
	void GetNextCode();
	void ProcessOpcode(WORD);

	//Address modes
	BYTE ZeroPage(int cycleCount);
	BYTE ZeroPageX(int cycleCount);
	BYTE ZeroPageY(int cycleCount);
	BYTE Absolute(int cycleCount);
	BYTE AbsoluteX(int cycleCount, int extra_cycles_if_page_crossed = 0);
	BYTE AbsoluteY(int cycleCount, int extra_cycles_if_page_crossed = 0);
	BYTE IndirectX(int cycleCount);
	BYTE IndirectY(int cycleCount, int extra_cycles_if_page_crossed = 0);
	BYTE Immediate(int cycleCount);



	//OP CODES FUNCTIONS**************************
	//status flag changes
	void CLC_18(WORD);
	void CLD_D8(WORD);
	void CLI_58(WORD);
	void CLV_B8(WORD);
	void SEC_38(WORD);
	void SED_F8(WORD);
	void SEI_78(WORD);
	//load and store-----------------------
	void LDA_A9(WORD);
	void LDA_A5(WORD);
	void LDA_B5(WORD);
	void LDA_AD(WORD);
	void LDA_BD(WORD);
	void LDA_B9(WORD);
	void LDA_A1(WORD);
	void LDA_B1(WORD);

	void LDX_A2(WORD);
	void LDX_A6(WORD);
	void LDX_B6(WORD);
	void LDX_AE(WORD);
	void LDX_BE(WORD);

	void LDY_A0(WORD);
	void LDY_A4(WORD);
	void LDY_B4(WORD);
	void LDY_AC(WORD);
	void LDY_BC(WORD);

	void STA_85(WORD);
	void STA_95(WORD);
	void STA_8D(WORD);
	void STA_9D(WORD);
	void STA_99(WORD);
	void STA_81(WORD);
	void STA_91(WORD);

	void STX_86(WORD);
	void STX_96(WORD);
	void STX_8E(WORD);

	void STY_84(WORD);
	void STY_94(WORD);
	void STY_8C(WORD);
	//Stack operations-----------------------
	void TSX_BA(WORD);
	void TXS_9A(WORD);
	void PHA_48(WORD);
	void PHP_08(WORD);
	void PLA_68(WORD);
	void PLP_28(WORD);
	//Branch operations----------------------
	void BCC_90(WORD);
	void BCS_B0(WORD);
	void BEQ_F0(WORD);
	void BMI_30(WORD);
	void BNE_D0(WORD);
	void BPL_10(WORD);
	void BVC_50(WORD);
	void BVS_70(WORD);
	//Arithmetic operations------------------
	//ADC functions here
	//SBC
	void CMP_C9(WORD);
	void CMP_C5(WORD);
	void CMP_D5(WORD);
	void CMP_CD(WORD);
	void CMP_DD(WORD);
	void CMP_D9(WORD);
	void CMP_C1(WORD);
	void CMP_D1(WORD);
	//CPX
	//CPY
	//Increment and decrement operations-------------
	void INC_E6(WORD);
	void INC_F6(WORD);
	void INC_EE(WORD);
	void INC_FE(WORD);

	void INX_E8(WORD);
	void INY_C8(WORD);

	void DEC_C6(WORD);
	void DEC_D6(WORD);
	void DEC_CE(WORD);
	void DEC_DE(WORD);

	void DEX_CA(WORD);
	void DEY_88(WORD);
};
#endif