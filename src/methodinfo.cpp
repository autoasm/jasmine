// Class automatically generated by Dev-C++ New Class wizard

#include "methodinfo.h" // class's header file
#include "toolkit.h"
#include <string.h>
#include <assert.h>

// class constructor
MethodInfo::MethodInfo()
{
	// insert your code here
	attributes = (AttributeElement*)0;
}

// class destructor
MethodInfo::~MethodInfo()
{
	// insert your code here
	if(attributes) {
	   delete[] attributes;
    }
}

void MethodInfo::setAttributesCount(u2 _attributesCount) 
{ 
    attributesCount = _attributesCount;
    initAttributes();
}

void MethodInfo::initAttributes()
{
    attributes = new AttributeElement[attributesCount];
    memset(attributes,0,sizeof(AttributeElement)*attributesCount);
}

void MethodInfo::setAttribute(GenericAttribute* attribute,u2 pos)
{
    assert(pos < attributesCount);
    if(attributes) {
        attributes[pos] = attribute;
    }
}

GenericAttribute* MethodInfo::getAttribute(u2 pos)
{
    assert(pos < attributesCount);
    GenericAttribute* ret;
    if(attributes) {
        ret = attributes[pos];
    }
    return ret;
}

void MethodInfo::serialize(JBuffer* buf, UINT& pos) {
	ToolKit::memSetU2(buf->getBuffer(), getAccessFlags(), buf->getSize(), pos);
	ToolKit::memSetU2(buf->getBuffer(), getNameIndex(), buf->getSize(), pos);
	ToolKit::memSetU2(buf->getBuffer(), getSignatureIndex(), buf->getSize(), pos);
	ToolKit::memSetU2(buf->getBuffer(), getAttributesCount(), buf->getSize(), pos);
	for(u2 i = 0; i<getAttributesCount(); i++) {
		getAttribute(i)->serialize(buf, pos);
	}
}