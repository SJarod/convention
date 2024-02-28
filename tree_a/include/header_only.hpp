#pragma once

#include <>

//define HEADER_ONLY_IMPLEMENTATION


// provide C linkage
// no mangled function symbols
// used for building dlls
#ifdef __cplusplus
extern "C" {
#endif


// forbidden global variables
inline static float a = 0.f;
static float b;

void my_prototype();

inline void my_inline()
{
    return;
}


#ifdef __cplusplus
}
#endif


#ifdef HEADER_ONLY_IMPLEMENTATION

// static "private" variable
// stored in compilation unit (object)
static float c = 0.f;

void my_prototype()
{
    return;
}

#endif