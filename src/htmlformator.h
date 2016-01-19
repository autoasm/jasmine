
#ifndef JASMIN_HTMLFORMATOR_H
#define JASMIN_HTMLFORMATOR_H

#include "jobject.h"
#include "iformator.h"
#include "jfont.h"
#include "jstringbuffer.h"

#include <string>

#ifndef NO_NAMESPACE
using namespace std;
#endif

/*!
 * \class HtmlFormator
 * HtmlFormator class format java instruction into HTML format.
 */ 
class HtmlFormator : public IFormator {

  public:
    enum {
      DEFAULT_BUFFER_SIZE = 512*1024
    };

    enum {
      CLASSNAME,
      METHOD,
      KEYWORD,
      COMMENT,
      OPERAND
    };

  protected:
    JFont _fontList[OPERAND + 1];

    string _htmlString;

    StringBuffer* _buffer;

    JFont getFontByType(unsigned int type);

    JFont getDefaultFont();

    string getHtmlTextString(JFont font, string text);

    string getFaceString(JFont font);

    string getColorString(JFont font);

    string getNextLine();

	/// Add Tab 
    void addTab();

	/// Add space
    void addSpace();

	/// Add html header
    void htmlBegin();

	/// Add html end tag
    void htmlEnd();

  public:
    /*! Constructor */
    HtmlFormator();

    /*! Destructor */
    virtual ~HtmlFormator(void);
	
    virtual void classBegin(char* className, char* superClass);
    virtual void classEnd();

    virtual void methodBegin(char* className, char* methodName);
    virtual void methodEnd();

    virtual void upcase();
    virtual void lowcase();

    virtual void addKeyWord(char* keyWord);
    virtual void addOperand(u1 operand);
    virtual void addComment(char* comment);

    virtual void enter();
    virtual void comma();

    virtual void destroy();

    const char* getHtmlString();

    void setFont(JFont font, unsigned int type);

};

#endif  //JASMIN_HTMLFORMATOR_H
