#ifndef CLASS_CONSOLE_FORMATOR_H
#define CLASS_CONSOLE_FORMATOR_H

#include "iformator.h"

class ConsoleFormator : public IFormator {
private:
	bool isUpcase;
public:
	/*! Constructor */
	ConsoleFormator(void);

	/*! Destructor */
	virtual ~ConsoleFormator(void);

	virtual void classBegin(char* className, char* superClass);
	virtual void classEnd();

	virtual void methodBegin(char* className, char* methodName);
	virtual void methodEnd();

	virtual void upcase();
	virtual void lowcase();

	virtual void addKeyWord(char* keyWord);
	virtual void addOperand(u1 operand);
	virtual void addComment(char* comment);

	virtual void enter();
	virtual void comma();

	virtual void destroy();
};
/*!
	\class ConsoleFormator
	Class ConsoleFormator is a implementation of interface IFormator.
	ConsoleFormator outputs formatted class instructions to standard output stream(console).
	\see IFormator
*/

#endif

