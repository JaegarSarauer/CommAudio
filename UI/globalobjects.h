#ifndef GLOBALOBJECTS_H
#define GLOBALOBJECTS_H

#define WIN32_LEAN_AND_MEAN
#include "circularbuffer.h"
#include <Windows.h>

extern CircularBuffer * audioBuffer;
extern CRITICAL_SECTION bufferAccess;

#endif // GLOBALOBJECTS_H
