// Class automatically generated by Dev-C++ New Class wizard

#ifndef CLASSLOADER_H
#define CLASSLOADER_H

#include "jtype.h"
#include "jclass.h" // inheriting class's header file
#include "attributecontainer.h"
#include <string>

#ifndef _NO_NAMESPACE_
using namespace std;
#endif


/*! Ext name of class file */
#ifndef CLASS_EXT	
#define CLASS_EXT			".class"
#endif

// Java Class Loader
class ClassLoader {

    protected:
        BYTE* classBuf;
        UINT  classBufSize;
        
        /*! Load Class File Into Buffer */
        BOOL loadClassIntoBuf(string classFile);
        
        /*! Handle the Constant Pool of Class */
        UINT handleConstantPool(JClass*javaClass,UINT constantCount,UINT&index);
        
        /*! Process Constant UTF8 */
        UINT onConstantUtf8(JClass*javaClass,UINT&index);
        
        /*! Process Constant Unicode */
        UINT onConstantUnicode(JClass*javaClass,UINT&index);
        
        /*! Process Constant String */
        UINT onConstantString(JClass*javaClass,UINT&index);
        
        /*! Process Constant Integer */
        UINT onConstantInteger(JClass*javaClass,UINT&index);
        
        /*! Process Constant Long */
        UINT onConstantLong(JClass*javaClass,UINT&index);
        
        /*! Process Constant Float */
        UINT onConstantFloat(JClass*javaClass,UINT&index);
        
        /*! Process Constant Double */
        UINT onConstantDouble(JClass*javaClass,UINT&index);
        
        /*! Process Constant Reference */
        UINT onConstantReference(JClass*javaClass, UINT&index, u1 constantTag);
        
        /*! Process Constant Class */
        UINT onConstantClass(JClass*javaClass,UINT&index);
        
        /*! Process Constant Name And Type */
        UINT onConstantNameAndType(JClass*javaClass,UINT&index);
        
        /*! Handle Interfaces */
        UINT handleInterfaces(JClass*javaClass,u2 intfCount,UINT&index);
        
        /*! Handle Fields */
        UINT handleFields(JClass*javaClass,u2 fieldsCount, UINT&index);
        
        /*! Handle Attributes */
        UINT handleAttribute(AttributeContainer*owner, u2 attributesCount, UINT&index);
        
        /*! Handle Methods */
        UINT handleMethods(JClass*javaClass,u2 methodsCount, UINT&index);
        
	public:
		/*! ext name of class file */ 
		const char*classFileExt;
	    
	    /*!
            Load class from file and returns an object that represent the java class. 
			\param className Name of class file that to be loaded.
	    */
	    JClass* loadClass(string className);
		
        /*! class constructor */
		ClassLoader();

		/*! class destructor */
		~ClassLoader();
};
/*!
    \class ClassLoader
    The major goal of Class ClassLoader is load and parseing java class file.
	After parsing, ClassLoader returns a JClass object that represent this java class.
*/

#endif // CLASSLOADER_H

