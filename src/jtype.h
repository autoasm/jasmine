#ifndef JTYPE_H
#define JTYPE_H

#include "jasmin-config.h"

//--------- Basic Type --------//

#if (BYTE_DEFINED == 0)
typedef unsigned char BYTE;
#endif

#if (UINT_DEFIED == 0)
typedef unsigned int  UINT;
#endif

#if (INT_DEFINED == 0)
typedef int           INT;
#endif

#if (BOOL_DEFINED == 0)
typedef bool          BOOL;
#endif

#if (LONG_DEFINED == 0)
typedef long          LONG;
#endif

typedef unsigned char  u1;
typedef unsigned short u2;
typedef unsigned long  u4;

//--------- Marcros -----------//
//#ifndef TRUE
//#define true    TRUE;
//#endif

//#ifndef FALSE
//#define false   FALSE;
//#endif


#define J_OK        1;
#define J_ERROR     0;

#endif
