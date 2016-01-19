
#ifndef JASMINE_CONST_INTERFACE_METHOD_REF_H
#define JASMINE_CONST_INTERFACE_METHOD_REF_H

#include "constantref.h"

class ConstIntfMethodRef : public ConstantRef {

	public:	
		ConstIntfMethodRef() : ConstantRef() {
			setTag(Constant::INTF_METHOD_REF);
		}

		virtual ~ConstIntfMethodRef() {
		}

};



#endif  //JASMINE_CONST_INTERFACE_METHOD_REF_H