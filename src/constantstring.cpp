// Class automatically generated by Dev-C++ New Class wizard

#include "constantstring.h" // class's header file
#include "toolkit.h"

// class constructor
ConstantString::ConstantString()
{
	// insert your code here
	setTag(Constant::STRING);
}

// class destructor
ConstantString::~ConstantString()
{
	// insert your code here
}

void ConstantString::customSerialize(JBuffer* buf, UINT& pos) {
	ToolKit::memSetU2(buf->getBuffer(), stringIndex, buf->getSize(), pos);
}