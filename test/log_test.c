#include "log.h"
#include "cJSON.h"
#include <stdio.h>

#if 0
#pragma mark -
#pragma mark 
#endif

#ifndef SYMBOL
#define SYMBOL value
#endif	// SYMBOL

#ifndef SYBMBOY
#define SYBMBOY FWF
#endif	// SYBMBOY

#ifndef _HAD
#define _HAD
#endif	// _HAD


#define STR(x) #x



typedef enum
{
    CMD_START,
    CMD_END
}cmd_t;

#define ERROR_CODES \
    ERROR_CODE(NO_ERROR) \
    ERROR_CODE(ERROR_ONE) \
    ERROR_CODE(ERROR_TWO) \
    ERROR_CODE(ERROR_THREE) \
    ERROR_CODE(ERROR_FOUR)

#define ERROR_CODE(code) code,
typedef enum { ERROR_CODES } ErrorCodes;
#undef ERROR_CODE

const char *MapError(const int errorCode)
{
#define ERROR_CODE(code) case code: return #code;   
    switch (errorCode)
    {
        ERROR_CODES
    default: return "UNKNOWN ERROR";
    };
#undef ERROR_CODE
}


int main(int argc, char const *argv[])
{
    printf("%s\n", STR(LOG__INFO));
    return 0;
}

