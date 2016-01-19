#ifndef INTERFACE_JCLASS
#define INTERFACE_JCLASS

#include "constant.h"
#include "fieldinfo.h"
#include "methodinfo.h"
#include "attributecontainer.h"

class JClassInterface : public AttributeContainer
{
    public:
        virtual u4 getMagic()					= 0;
        virtual u2 getMinorVersion()			= 0;
        virtual u2 getMajorVersion()			= 0;
        virtual u2 getConstPoolCount()			= 0;
        virtual Constant* getConstant(u2 pos)	= 0;
        virtual u2 getAccessFlag()				= 0;
        virtual u2 getThisClass()				= 0;
        virtual u2 getSuperClass()				= 0; 
        virtual u2 getInterfaceCount()			= 0;
        virtual u2 getInterface(u2 pos)			= 0;
        virtual u2 getFieldsCount()				= 0;
        virtual FieldInfo*getField(u2 pos)		= 0;
        virtual u2 getMethodsCount()			= 0;
        virtual MethodInfo*getMethod(u2 pos)	= 0;
        virtual u2 getAttributesCount()			= 0;
};

#endif
