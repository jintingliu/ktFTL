#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>

#ifndef U8
#define U8     unsigned  char
#endif

#ifndef U16
#define U16    unsigned  short
#endif

#ifndef U32
#define U32    unsigned  long
#endif

#ifndef U64
#define U64    unsigned  long  long
#endif

#define LOG_ERROR(format, ...)      printf(format, __VA_ARGS__); while(1);
#define LOG_DEBUG(format, ...)      printf(format, __VA_ARGS__)
#define LOG_WARN(format, ...)       printf(format, __VA_ARGS__)

#endif

