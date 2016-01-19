// Class automatically generated by Dev-C++ New Class wizard

#ifndef CONSTCLASS_H
#define CONSTCLASS_H

#include "constant.h" // inheriting class's header file

// No description
class ConstantClass : public Constant {

    protected:
        u2 nameIndex;

		virtual void customSerialize(JBuffer* buf, UINT& pos);

	public:
		/*! Constructor */
		ConstantClass();

		/*! Destructor */
		~ConstantClass();
		
		/*! Get Name index */
		inline u2 getNameIndex() { return nameIndex;};

		/*! Set Name index */
		inline void setNameIndex(u2 x) { nameIndex = x;};
};

/*!
	\class ConstantClass
	Class ConstantClass represent class constant in java class file.
	See Java Virtual Machine Specification for more detail about java class file.
*/

#endif // CONSTCLASS_H
