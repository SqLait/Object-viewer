#include "strings.h"
#include <string.h>

#define StrLit(s) (string) { s, sizeof(s) - 1 };

string StringAppend(Allocator *a, string ogStr, string appendStr) {
    u32 strLen = ogStr.len + appendStr.len;
    char *buffer = a->alloc(a, strLen + 1);
    memcpy(buffer, ogStr.str, ogStr.len);
    memcpy(buffer + ogStr.len, appendStr.str, appendStr.len);

    return (string) {
        buffer,
        strLen
    };
}

char *C_Str(string *str) {
    return "THIS FUNCTION IS NOT SAFE";
}
