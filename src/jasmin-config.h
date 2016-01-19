#ifndef JASMIN_CONFIG_H
#define JASMIN_CONFIG_H

#define JASMIN_PALTFORM MS_WIN32
//#define JASMIN_PALTFORM  LINUX

/* Data types */

/*!
 * \note 
 * MINGW32 defined BOOL in standard header file, so, in order to compile
 * jasmin correctly, set BOOL_DEFINED 1
 */ 

#define BYTE_DEFINED  0
#define UINT_DEFINED  0
#define INT_DEFINED   0
#define BOOL_DEFINED  0
#define LONG_DEFINED  0

/* If your compiler does not support namespace, define follow macro */
/* #define NO_NAMESPACE */




#endif  /* JASMIN_CONFIG_H */
