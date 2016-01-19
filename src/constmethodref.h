

#ifndef JASMINE_CONST_METHOD_REF_H
#define JASMINE_CONST_METHOD_REF_H

#include "constantref.h"

class ConstMethodRef : public ConstantRef {

	public:
		ConstMethodRef() : ConstantRef() {
			setTag(Constant::METHOD_REF);
		}

		virtual ~ConstMethodRef() {
		}

};

#endif  //JASMINE_CONST_METHOD_REF_H

