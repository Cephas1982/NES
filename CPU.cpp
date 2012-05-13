#ifndef CPU_CPP
#define CPU_CPP

#include "CPU.h"

C_CPU::C_CPU()
{
	//temp set stuff... todo: move to reset function?
	m_flagC = false;
	m_flagZ = false; 
	m_flagI = false;
	m_flagD = false;
	m_flagB = false;
	m_flagV = false;
	m_flagN = false;

	m_regA = 0;
	m_regX = 0;
	m_regY = 0;

	count = 0;
}

C_CPU::~C_CPU()
{
	//cleanup
//	fclose(infile);
}

void C_CPU::GetNextCode()
{
	WORD opcode = systemMem[m_pc] & 0x00FF;
	printf("count: %d  ", count++);printf("parsing opcode:  %#X  ", opcode); printf("   programCounter:  %#X  \n", m_pc);
//	system("pause");
		ProcessOpcode(opcode);


}

void C_CPU::RESET()
{
	//load game
	FILE *infile;

	infile = fopen("roms/smb.nes", "rb");
	
	
	//load rom header
	int PRG_ROM_BANKS = 0; // count of 16KB rom banks
	int CHR_ROM_BANKS = 0; // count of 8KB chr-rom/vrom banks
	int ROM_CONTROL_BYTE_1 = 0;//see docs - bit dependant
	int ROM_CONTROL_BYTE_2 = 0;

	fread(&header[0], 1, 16, infile);
	PRG_ROM_BANKS = header[4];
	CHR_ROM_BANKS = header[5];
	ROM_CONTROL_BYTE_1 = header[6];
	ROM_CONTROL_BYTE_2 = header[7];

	//load the rest of rom  prg-rom count * 1024 * 16 + (chr-rom * 1024 * 8)
	//GET SIZE OF GAME
	fseek(infile, 0, SEEK_END);
	int gameSize = ftell(infile);
	rewind(infile);
	//cout << "game size: " << gameSize << endl;

	BYTE * gameMemory = new BYTE[gameSize]; //new BYTE[(PRG_ROM_BANKS * 0x4000) + (CHR_ROM_BANKS * 0x2000)];
	//set game mem to zero
	memset(gameMemory, 0, sizeof(gameMemory));
	memset(systemMem, 0, sizeof(systemMem));
	memset(ppuMem, 0, sizeof(ppuMem));
	m_cycleCount = 0;

	//seek past header
	//fseek(infile, 16, SEEK_SET);
	int bytesToRead = (PRG_ROM_BANKS * 0x4000) + (CHR_ROM_BANKS * 0x2000) + HEADER;
	int result = fread(gameMemory, 1, bytesToRead, infile); //load everything from the file to game memory (prg / chr roms)
	//cout << endl << "size of gamMemory: " << sizeof(gameMemory) << "  read result: " << result << endl;

	//0x4000 = 16KB
	//LOAD PROGRAM ROM
	memcpy(&systemMem[0x8000], gameMemory + HEADER, 0x4000*2 ); //copy 16KB *2  b/c there are 2 prg rom banks
	//LOAD VIDEO ROM
	memcpy(&ppuMem[0x0000], gameMemory + 0x4000 * 2 + HEADER, 0x2000); //copy 8KB of video rom to the ppu

	//RESET VECTOR IS  $FFFC/$FFFD
	WORD first = systemMem[0xFFFC];
	WORD second = systemMem[0xFFFD];
	second <<= 8;
	//second |= first;
	WORD resetVector = second | first;


	//SET STUFF
	m_pc = resetVector;
	WORD opcode = systemMem[resetVector];

	//ProcessOpcode(opcode);
	//reference__http://www.obelisk.demon.co.uk/6502/instructions.html
}

void C_CPU::ProcessOpcode(WORD opcode)
{
	int i = 1;//temp for debug

	switch(opcode){
	/*** LOAD AND STORE Operations--------------------------------
	//In case of LDA - Load Accumulator opcodes */
	case 0xA9: LDA_A9(opcode); break; 
	case 0xA5: LDA_A5(opcode); break;
	case 0xB5: LDA_B5(opcode); break;
	case 0xAD: LDA_AD(opcode); break;
	case 0xBD: LDA_BD(opcode); break;
	case 0xB9: LDA_B9(opcode); break;
	case 0xA1: LDA_A1(opcode); break;
	case 0xB1: LDA_B1(opcode); break;

	//In case of LDX - Load X Register opcodes*/
	case 0xA2: LDX_A2(opcode); break;/*
	case 0xA6: LDX_A6(opcode); break;
	case 0xB6: LDX_B6(opcode); break;
	case 0xAE: LDX_AE(opcode); break;
	case 0xBE: LDX_BE(opcode); break;

	//In case of LDY - Load Y Register opcodes
*/	case 0xA0: LDY_A0(opcode); break; /*
	case 0xA4: LDY_A4(opcode); break;
	case 0xB4: LDY_B4(opcode); break;
	case 0xAC: LDY_AC(opcode); break;
	case 0xBC: LDY_BC(opcode); break;

	*///In case of STA - Store Accumulator opcodes
	case 0x85: STA_85(opcode); break;
	case 0x95: STA_95(opcode); break;  
	case 0x8D: STA_8D(opcode); break; 
	case 0x9D: STA_9D(opcode); break;
	case 0x99: STA_99(opcode); break;
	case 0x81: STA_81(opcode); break;
	case 0x91: STA_91(opcode); break;

	//In case of STX - Store X register
	case 0x86: STX_86(opcode); break;
	case 0x96: STX_96(opcode); break;
	case 0x8E: STX_8E(opcode); break;

	//In case of STY - Store Y register
	case 0x84: STY_84(opcode); break;
	case 0x94: STY_94(opcode); break;
	case 0x8C: STY_8C(opcode); break;

	/*** Register transfers --------------------------------*/
	//In case of TAX - Transfer accumulator to X
	case 0xAA: TAX_AA(opcode); break;

	//In case of TAY - Transfer accumulator to Y
	case 0xA8: TAY_A8(opcode); break;

	//In case of TXA - Transfer X to accumulator
	case 0x8A: TXA_8A(opcode); break;

	//In case of TYA - Transfer Y to accumulator
	case 0x98: TYA_98(opcode); break;

	/*** Stack Operations --------------------------------*/
	//In case of TSX - Transfer stack pointer to X
	case 0xBA: TSX_BA(opcode); break;
	
	//In case of TXS - Transfer X to stack pointer
	case 0x9A: TXS_9A(opcode); break;
	/*
	//In case of PHA - Push accumulator on stack
	case 0x48: PHA_48(opcode); break;

	//In case of PHP - Push processor status on accumulator
	case 0x08: PHA_08(opcode); break;

	//In case of PLA - Pull accumulator from stack
	case 0x68: PLA_68(opcode); break;

	//In case of PLP - Pull processor status from stack
	case 0x28: PLP_28(opcode); break;

	/*** Logical operations --------------------------------
*/	//In case of AND - Logical AND
	case 0x29: AND_29(opcode); break;
	case 0x25: AND_25(opcode); break;
	case 0x35: AND_35(opcode); break;
	case 0x2D: AND_2D(opcode); break;
	case 0x3D: AND_3D(opcode); break;
	case 0x39: AND_39(opcode); break;
	case 0x21: AND_21(opcode); break;
	case 0x31: AND_31(opcode); break;

	//In case of EOR - Logical EOR
	case 0x49: EOR_49(opcode); break;
	case 0x45: EOR_45(opcode); break;
	case 0x55: EOR_55(opcode); break;
	case 0x4D: EOR_4D(opcode); break;
	case 0x5D: EOR_5D(opcode); break;
	case 0x59: EOR_59(opcode); break;
	case 0x41: EOR_41(opcode); break;
	case 0x51: EOR_51(opcode); break;

	//In case of ORA - Logical inclusive 
	case 0x09: ORA_09(opcode); break;
	case 0x05: ORA_05(opcode); break;
	case 0x15: ORA_05(opcode); break;
	case 0x0D: ORA_0D(opcode); break;
	case 0x1D: ORA_1D(opcode); break;
	case 0x19: ORA_19(opcode); break;
	case 0x01: ORA_01(opcode); break;
	case 0x11: ORA_11(opcode); break;

	//In case of BIT - Bit test 
	case 0x24: BIT_24(opcode); break;
	case 0x2C: BIT_2C(opcode); break;

	/*** Arithmetic operations --------------------------------
	//*************************TODO FIX THESE*******************
	//In case of ADC - Add with carry 
	case 0x69: ADC_69(opcode); break;
	case 0x65: ADC_65(opcode); break;
	case 0x75: ADC_75(opcode); break;
	case 0x6D: ADC_6D(opcode); break;
	case 0x7D: ADC_7D(opcode); break;
	case 0x79: ADC_79(opcode); break;
	case 0x61: ADC_61(opcode); break;
	case 0x71: ADC_71(opcode); break;

	//In case of SBC - Subtract with carry 
	case 0xE9: SBC_E9(opcode); break;
	case 0xE5: SBC_E5(opcode); break;
	case 0xF5: SBC_F5(opcode); break;
	case 0xED: SBC_ED(opcode); break;
	case 0xFD: SBC_FD(opcode); break;
	case 0xF9: SBC_F9(opcode); break;
	case 0xE1: SBC_E1(opcode); break;
	case 0xF1: SBC_F1(opcode); break;

	//In case of CMP - Compare
*/	case 0xC9: CMP_C9(opcode); break;
	case 0xC5: CMP_C5(opcode); break;
	case 0xD5: CMP_D5(opcode); break;
	case 0xCD: CMP_CD(opcode); break;
	case 0xDD: CMP_DD(opcode); break;
	case 0xD9: CMP_D9(opcode); break;
	case 0xC1: CMP_C1(opcode); break;
	case 0xD1: CMP_D1(opcode); break;

	//In case of CPX - Compare X register
	case 0xE0: CPX_E0(opcode); break;
	case 0xE4: CPX_E4(opcode); break;
	case 0xEC: CPX_EC(opcode); break;

	//In case of CPY - Compare Y register
	case 0xC0: CPY_C0(opcode); break;
	case 0xC4: CPY_C4(opcode); break;
	case 0xCC: CPY_CC(opcode); break;


	/*** Increments and Decrements --------------------------------
	*/
	//In case of INC - Increment a memory location
	case 0xE6: INC_E6(opcode); break;
	case 0xF6: INC_F6(opcode); break;
	case 0xEE: INC_EE(opcode); break;
	case 0xFE: INC_FE(opcode); break;

	//In case of INX - Increment the X register
	case 0xE8: INX_E8(opcode); break;


	//In case of INY - Increment the Y register
	case 0xC8: INY_C8(opcode); break;

	//In case of DEC - Decrement a memory location
	case 0xC6: DEC_C6(opcode); break;
	case 0xD6: DEC_D6(opcode); break;
	case 0xCE: DEC_CE(opcode); break;
	case 0xDE: DEC_DE(opcode); break;

	//In case of DEX - Decrement the X register
	case 0xCA: DEX_CA(opcode); break;
	
	//In case of DEY - Decrement the Y register
	case 0x88: DEY_88(opcode); break;

	/*** Shifts --------------------------------
	//In case of ASL - Arithmetic Shift Left
	case 0x0A: ASL_0A(opcode); break;
	case 0x06: ASL_06(opcode); break;
	case 0x16: ASL_16(opcode); break;
	case 0x0E: ASL_0E(opcode); break;
	case 0x1E: ASL_1E(opcode); break;

	//In case of LSR - Arithmetic Shift Right
	case 0x4A: LSR_4A(opcode); break;
	case 0x46: LSR_46(opcode); break;
	case 0x56: LSR_56(opcode); break;
	case 0x4E: LSR_4E(opcode); break;
	case 0x5E: LSR_5E(opcode); break;

	//In case of ROL - Rotate Left
	case 0x2A: ROL_2A(opcode); break;
	case 0x26: ROL_26(opcode); break;
	case 0x36: ROL_36(opcode); break;
	case 0x2E: ROL_2E(opcode); break;
	case 0x3E: ROL_3E(opcode); break;

	//In case of ROR - Rotate Right
	case 0x6A: ROR_6A(opcode); break;
	case 0x66: ROR_66(opcode); break;
	case 0x76: ROR_76(opcode); break;
	case 0x6E: ROR_6E(opcode); break;
	case 0x7E: ROR_7E(opcode); break;


	/*** Jumps and Calls-------------------------------- */
	//In case of JMP - Jump to another location
	case 0x4C: JMP_4C(opcode); break;
	case 0x6C: JMP_6C(opcode); break;

	//In case of JSR - Jump to a subroutine
	case 0x20: JSR_20(opcode); break;

	//In case of RTS - Return from subroutine
	case 0x60: RTS_60(opcode); break;


	/*** Branches --------------------------------*/
	//In case of BCC - Branch if carry flag clear
	case 0x90: BCC_90(opcode); break;

	//In case of BCS - Branch if carry flag set
	case 0xB0: BCS_B0(opcode); break;

	//In case of BEQ - Branch if zero flag set
	case 0xF0: BEQ_F0(opcode); break;

	//In case of BMI - Branch if negative flag set
	case 0x30: BMI_30(opcode); break;

	//In case of BNE - Branch if zero flag clear
	case 0xD0: BNE_D0(opcode); break;

	//In case of BPL - Branch if negative flag clear
	case 0x10: BPL_10(opcode); break;

	//In case of BVC - Branch if overflow flag clear
	case 0x50: BVC_50(opcode); break;

	//In case of BVS - Branch if overflow flag set
	case 0x70: BVS_70(opcode); break;

	/*** Status flags --------------------------------*/
	//In case of CLC - Clear carry flag
	case 0X18: CLC_18(opcode); break;

	//In case of CLD - Clear decimal mode flag
	case 0XD8: CLD_D8(opcode); break;

	//In case of CLI - Clear interrupt disable flag
	case 0X58: CLI_58(opcode); break;

	//In case of CLV - Clear overflow flag
	case 0XB8: CLV_B8(opcode); break;

	//In case of SEC - Set carry flag
	case 0X38: SEC_38(opcode); break;

	//In case of SED - Set decimal mode flag
	case 0XF8: SED_F8(opcode); break;

	//In case of SEI - Set interrupt disable flag
	case 0X78: SEI_78(opcode); break;

	
	/*** System Functions --------------------------------
	//In case of BRK - Force an interrupt
	case 0x00: BRK_00(opcode); break;

	//In case of NOP - Force an interrupt
	case 0xEA: NOP_EA(opcode); break;

	//In case of RTI - Force an interrupt
	case 0x40: RTI_40(opcode); break;

	*/
	default: printf("opcode |  %#X  | not found! \n", opcode);
				system("pause");
				return;

	}//end switch

}
//---------------------------------------------------------------


#endif