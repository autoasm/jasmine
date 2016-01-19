#ifndef INTERFACE_FORMATOR_H
#define INTERFACE_FORMATOR_H

#include "jtype.h"

class IFormator {
public:

	/*! Output begin of class */
	virtual void classBegin(char* className, char* superClass) = 0;
	/*! Output end of class   */
	virtual void classEnd()	= 0;

	/*! Output begin of method */
	virtual void methodBegin(char* className, char* methodName) = 0;
	/*! Output end of method */
	virtual void methodEnd() = 0;

	/*! Upcase instruction output  */
	virtual void upcase()	= 0;
	/*! Lowcase instruction output */
	virtual void lowcase()	= 0;

	/*! add instruction/keyword into output stream */
	virtual void addKeyWord(char* keyWord)	= 0;
	/*! add operand into output stream */
	virtual void addOperand(u1 operand)		= 0;
	/*! add comment into output stream */
	virtual void addComment(char* comment)	= 0;

	/*! add CRLF into output stream */
	virtual void enter()	= 0;
	/*! add comma into output stream */
	virtual void comma()	= 0;

	/*! destroy formator object */
	virtual void destroy()	= 0;
};

/*!
	\class IFormator
	Interface IFormator defines some methods for formatted output of java instruction.
*/

#endif

