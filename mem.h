//
// Created by tendo on 03.01.2022.
//

#ifndef MEM_ALLOC_MEM_H
#define MEM_ALLOC_MEM_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include <sys/mman.h>

#define HEAP_START ((void*)0x04040000)

void* _malloc( size_t query );
void  _free( void* mem );
void* heap_init( size_t initial_size );

#define DEBUG_FIRST_BYTES 4

void debug_struct_info( FILE* f, void const* address );
void debug_heap( FILE* f,  void const* ptr );

#endif //MEM_ALLOC_MEM_H