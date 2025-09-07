#ifndef STRINGS_H
#define STRINGS_H
#include "types.h"
#include "alloc.h"

#define StrLit(s) (string) { s, sizeof(s) - 1 };

string StringAppend(Allocator *a, string ogStr, string appendStr);
#endif
