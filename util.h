//
// Created by tendo on 03.01.2022.
//

#ifndef MEM_ALLOC_UTIL_H
#define MEM_ALLOC_UTIL_H

#include <stddef.h>

inline size_t size_max( size_t x, size_t y ) { return (x >= y)? x : y ; }

_Noreturn void err( const char* msg, ... );


#endif //MEM_ALLOC_UTIL_H
