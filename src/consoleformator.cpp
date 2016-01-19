
#include "consoleformator.h"
#include <iostream>
#include <assert.h>
#include <string>

#ifndef NO_NAMESPACE
using namespace std;
#endif


ConsoleFormator::ConsoleFormator(void)
{
	isUpcase = true;
}

ConsoleFormator::~ConsoleFormator(void)
{
}

//---------------------------------------------------------------------

void ConsoleFormator::classBegin(char* className, char* superClass) {
	assert(className);
	cout << "class " << className;
	if(superClass) {
		cout << " : " << superClass;
	}
	cout << " {" << endl;
}

void ConsoleFormator::classEnd() {
	cout << "}" << endl;
}

void ConsoleFormator::methodBegin(char* className, char* methodName) {
	assert(methodName && className);
	cout << "\t" << className << "::" << methodName << "( ) { " << endl;
}

void ConsoleFormator::methodEnd() {
	cout << "\t}" << endl << endl;
}

void ConsoleFormator::addKeyWord(char* keyWord) {
	assert(keyWord);
	cout <<"\t\t" << keyWord << " ";
}

void ConsoleFormator::addOperand(u1 operand) {
	cout << " " << (unsigned int)operand;
}

void ConsoleFormator::addComment(char* comment) {
	//TODO: add code here
}

void ConsoleFormator::enter() {
	cout << endl;
}

void ConsoleFormator::comma() {
	cout << " ,";
}

//----------------------------------------------------------------------------------

void ConsoleFormator::destroy() {
	delete this;
}

void ConsoleFormator::upcase() {
	isUpcase = true;
}

void ConsoleFormator::lowcase() {
	isUpcase = false;
}
