
#ifndef JASMINE_CONSTANT_FIELD_REF_H
#define JASMINE_CONSTANT_FIELD_REF_H

#include "constantref.h"

class ConstFieldRef : public ConstantRef {

	public:
		ConstFieldRef() : ConstantRef() {
			setTag(Constant::FIELD_REF);
		};

		virtual ~ConstFieldRef() {
		};
};

#endif //JASMINE_CONSTANT_FILED_REF_H