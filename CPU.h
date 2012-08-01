#ifndef CPU_H
#define CPU_H
#define HEADER 16 //header size in bytes
#include <iostream>
#include <vector>
typedef unsigned short int WORD;
typedef unsigned char BYTE;


class C_CPU{

private:
	int count; //track for debugging
	//CPU-----------------------------------------------------------------------------
	int m_cycleCount;//track clock cycles
	WORD m_pc;//program counter - Pointer to track where to read from____
	//stackPointer TODO <- this
	BYTE m_regA, m_regX, m_regY;  //Accumulator register -128 to 127, x register, y register
	WORD m_regS; //stack pointer register --- made 16bit so it's easier (decrements when byte is pushed, and increments when byte is pulled)
	std::vector<WORD>v_stack;
	//Carry, Zero, Interrupt Disable, Decimal Mode, Break cmd, Overflow, Negative
	bool m_flagC, m_flagZ, m_flagI, m_flagD, m_flagB, m_emptyFlag, m_flagV, m_flagN;

	BYTE mStack[256];


	//need to improve below
	BYTE pStatus;
	#define fC  0x1
	#define fZ  0x2
	#define fI  0x4
	#define fD  0x8
	#define fB  0x10
	#define fE  0x20
	#define fV  0x40
	#define fN  0x80
	//std::vector<WORD> v_stack;//this handles push/pop for stack purposes

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

	//Address modes ---- these functions return the next memory address
	BYTE ZeroPage(int cycleCount);
	WORD ZeroPageX(int cycleCount);
	WORD ZeroPageY(int cycleCount);
	WORD Absolute(int cycleCount);
	WORD AbsoluteX(int cycleCount, int extra_cycles_if_page_crossed = 0);
	WORD AbsoluteY(int cycleCount, int extra_cycles_if_page_crossed = 0);
	WORD Indirect(int cycleCount);
	WORD IndirectX(int cycleCount);
	WORD IndirectY(int cycleCount, int extra_cycles_if_page_crossed = 0);
	WORD Immediate(int cycleCount);



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
	
	void CPX_E0(WORD);
	void CPX_E4(WORD);
	void CPX_EC(WORD);

	void CPY_C0(WORD);
	void CPY_C4(WORD);
	void CPY_CC(WORD);

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
	//Jump and call operations---------------
	void JMP_4C(WORD);
	void JMP_6C(WORD);

	void JSR_20(WORD);
	void RTS_60(WORD);
	//Logical operations----------------------
	void AND_29(WORD);
	void AND_25(WORD);
	void AND_35(WORD);
	void AND_2D(WORD);
	void AND_3D(WORD);
	void AND_39(WORD);
	void AND_21(WORD);
	void AND_31(WORD);

	void EOR_49(WORD);
	void EOR_45(WORD);
	void EOR_55(WORD);
	void EOR_4D(WORD);
	void EOR_5D(WORD);
	void EOR_59(WORD);
	void EOR_41(WORD);
	void EOR_51(WORD);

	void ORA_09(WORD);
	void ORA_05(WORD);
	void ORA_15(WORD);
	void ORA_0D(WORD);
	void ORA_1D(WORD);
	void ORA_19(WORD);
	void ORA_01(WORD);
	void ORA_11(WORD);

	void BIT_24(WORD);
	void BIT_2C(WORD);
	//Register transfers------------------
	void TAX_AA(WORD);
	void TAY_A8(WORD);
	void TXA_8A(WORD);
	void TYA_98(WORD);


	// System functions
	void BRK_00(WORD);
	void NOP_EA(WORD);
	void RTI_40(WORD);

};
#endif