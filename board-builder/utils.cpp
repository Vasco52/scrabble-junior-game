#include "utils.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

//----------------------------------------------------------------------
// Convertion Functions - DECLARATION 
//----------------------------------------------------------------------

Position strToPosition(string position) {
	Position posi�ao;
	posi�ao.row = position[0] - 65;
	posi�ao.column = position[1] - 97;
	return posi�ao;
}

string positionToStr(Position position)
{
	string posi�ao = "";
	char linha = position.row + 65;
	char coluna = position.column + 97;
	posi�ao += toupper(linha);
	posi�ao += coluna;
	return posi�ao;
}

string upperWord(string str) {
	transform(str.begin(), str.end(), str.begin(), toupper);
	return str;
}

string lowerWord(string str) {
	transform(str.begin(), str.end(), str.begin(), tolower);
	return str;
}

//----------------------------------------------------------------------
// Input Functions - DECLARATION
//----------------------------------------------------------------------

Instruction readInstruction() {
	stringstream ss;
	string instructionString;
	Instruction instruction;
	// Input variables
	string initialPosition;
	char orientation;
	string word;
	// Get user input
	getline(cin, instructionString);
	ss << instructionString;
	ss >> initialPosition >> orientation >> word;
	// Store user input
	//instruction.initialPosition = strToPosition(initialPosition);
	instruction.orientation = orientation;
	instruction.word = word;
	return instruction;
}

//----------------------------------------------------------------------
// Output Functions - DECLARATION 
//----------------------------------------------------------------------

void setColor(unsigned int color, unsigned int background_color) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (background_color == BLACK)
		SetConsoleTextAttribute(hCon, color);
	else
		SetConsoleTextAttribute(hCon, color | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}