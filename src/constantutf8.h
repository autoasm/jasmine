// Class automatically generated by Dev-C++ New Class wizard

#ifndef CONSTANTUTF8_H
#define CONSTANTUTF8_H

#include "constant.h" // inheriting class's header file

// No description
class ConstantUtf8 : public Constant
{
    protected:
        u2 length;

        u1*bytes;

		void customSerialize(JBuffer* buf, UINT& pos);
	public:
		/*! class constructor */
		ConstantUtf8(u2 stringLength);

		/*! class destructor */
		~ConstantUtf8();
		
		/*! Get UTF8 string */
		u1* getBytes();
		
};

/*!
	\class ConstantUtf8
	Class ConstantUtf8 represent UTF8 string constant in java class file.
	See Java Virtual Machine Specification for more detail about java class file.
*/

#endif // CONSTANTUTF8_H

