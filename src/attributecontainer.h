#ifndef INTERFACE_ATTRIBUTE_CONTAINER
#define INTERFACE_ATTRIBUTE_CONTAINER

#include "jtype.h"
#include "genericattribute.h"

class AttributeContainer {

    public:
        virtual void setAttribute(GenericAttribute* attribute,u2 pos) = 0;
        virtual GenericAttribute* getAttribute(u2 pos) = 0;
};
/*!
    \class AttributeContainer
    Interface AttributeContainer 
*/

#endif //INTERFACE_ATTRIBUTE_CONTAINER
