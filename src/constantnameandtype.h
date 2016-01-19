// Class automatically generated by Dev-C++ New Class wizard

#ifndef CONSTANTNAMEANDTYPE_H
#define CONSTANTNAMEANDTYPE_H

#include "constant.h" // inheriting class's header file


class ConstantNameAndType : public Constant
{
    protected:
        u2 nameIndex;
        
		u2 signatureIndex;

		void customSerialize(JBuffer* buf, UINT& pos);

	public:
		/*! Constructor */
		ConstantNameAndType();
		
		/*! Destructor */
		~ConstantNameAndType();
		
		/*! Get Name index */
		inline u2 getNameIndex() { return nameIndex;};
		
		/*! Set Name Index */
		inline void setNameIndex(u2 x) { nameIndex = x ;};
		
		/*! Get signature index */
		inline u2 getSignatureIndex() { return signatureIndex; };
		
		/*! Set signature index */
		inline void setSignatureIndex(u2 x) { signatureIndex = x; };
};

/*!
	\class ConstantNameAndType
	Class ConstantNameAndType represent Name and type constant in java class file.
	See Java Virtual Machine Specification for more detail about java class file.
*/

#endif // CONSTANTNAMEANDTYPE_H
