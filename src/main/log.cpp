
#include<stdarg.h>
#include<stdio.h>
#include "log.h"

void log_info(const char* fmt,...)
{
    va_list arg_list;
    va_start(arg_list,fmt);
    vfprintf(stdout,fmt,arg_list);
    va_end(arg_list);
}
