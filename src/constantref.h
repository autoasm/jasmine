// Class automatically generated by Dev-C++ New Class wizard

#ifndef CONSTANTREF_H
#define CONSTANTREF_H

#include "constant.h" // inheriting class's header file


class ConstantRef : public Constant
{
    protected:
        u2 classIndex;

        u2 nameAndTypeIndex;

		void customSerialize(JBuffer* buf, UINT& pos);
	public:
		/*! constructor */
		ConstantRef();

		/*! Destructor */
		~ConstantRef();

		/*! Get Class Index */
		inline u2 getClassIndex() { return classIndex;};
		
		/*! Set Class Index */
		inline void setClassIndex(u2 x) { classIndex = x ;};
		
		/*! Get Name and type index */
		inline u2 getNameAndTypeIndex() { return nameAndTypeIndex; };
		
		/*! Set name and type index */
		inline void setNameAndTypeIndex(u2 x) { nameAndTypeIndex = x; };  
			
};

/*!
	\class ConstantRef
	Class ConstantRef represent Reference constant in java class file.
	See Java Virtual Machine Specification for more detail about java class file.
*/

#endif // CONSTANTREF_H

