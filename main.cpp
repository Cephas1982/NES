#pragma once
#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
#include <fstream>
#include <string>
#include "CPU.h"
using namespace std;
int main()
{

	//load game
	typedef char BYTE;
	typedef unsigned short int WORD;
	//HELPERS--------------
	C_CPU CPU;
	
	//RUN CPU
	bool quit = false;
	CPU.RESET();//reset vector

	//LOOPS
	while(!quit){
		//get and process opcode
		CPU.GetNextCode();
	}
	//delete[] systemMem;
	//delete[] ppuMem;


	return 0;
}
#endif


/*
	ifstream infile;
	infile.open("roms/nestest_log.txt");

	string output = "";
	string tempRead = "";
	char buffer[6];
	getline(infile, tempRead);
	int count = 0;
	while(!infile.eof())
	{
		itoa(count, buffer, 10);
		output = output + buffer + "   " + tempRead + "\n";
		getline(infile, tempRead);
		count++;
	}
	infile.close();

	ofstream outfile;
	outfile.open("roms/newLog.txt");

	
	outfile << output;
	*/