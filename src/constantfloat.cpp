// Class automatically generated by Dev-C++ New Class wizard

#include "constantfloat.h" // class's header file
#include "toolkit.h"

// class constructor
ConstantFloat::ConstantFloat()
{
	// insert your code here
	setTag(Constant::FLOAT);
}

// class destructor
ConstantFloat::~ConstantFloat()
{
	// insert your code here
}

void ConstantFloat::customSerialize(JBuffer* buf, UINT& pos) {
	u4 tmpValue = 0;
	memcpy(&tmpValue, &value, sizeof(u4));
	ToolKit::memSetU4(buf->getBuffer(), tmpValue, buf->getSize(), pos);
}