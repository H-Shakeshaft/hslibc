/**
 * hsl_type.h - A series of declarations for different types, with the aim of providing
 * some more decriptive capabilities in to the language. For example, a pre-C99
 * compatible rendition of fixed-width integers.
 * 
 * Notes:
 *  - this only supports 64-bit compilation targets.
 *  - assumes that you will want to used fixed-width integers from stdint if you
 * include this header.
 * 
 * Authors:
 *  - Henry Shakeshaft <henry.shakeshaft@live.co.uk>
 * 
 * Licene:
 *  See end of file.
*/
#ifndef HSLIBC_TYPES_H_
#define HSLIBC_TYPES_H_

/* TODO(HS): implement short-circuit to allow users to use non-fixed-width ints */

/*============================== Integers Start =============================*/
/* 
    NOTE(HS): this is to handle the fact C++ added support for fixed width integer
    in C++11, vs C in C99.
        - https://en.cppreference.com/w/c/preprocessor/replace
        - https://en.cppreference.com/w/cpp/preprocessor/replace
*/
#if (defined(__cplusplus) && (__cplusplus >= 201103L)) || (defined(__STDC__) && (__STDC_VERSION__ >= 199901L))
    #define HSL_USE_FIXED_WIDTH_INTS
#endif

#ifdef HSL_USE_FIXED_WIDTH_INTS
    #ifdef __cplusplus
        #include <cstdint>
    #else
        #include <stdint.h>
    #endif
#endif

/*
    TODO(HS): implement 32 bit support
        - https://sourceforge.net/p/predef/wiki/OperatingSystems/
        - https://en.cppreference.com/w/c/language/arithmetic_types
*/
#ifdef HSL_USE_FIXED_WIDTH_INTS
    typedef uint8_t  uint8;
    typedef uint16_t uint16;
    typedef uint32_t uint32;
    typedef uint64_t uint64;

    typedef int8_t  int8;
    typedef int16_t int16;
    typedef int32_t int32;
    typedef int64_t int64;
#else
    /*
        NOTE(HS): int64/uint64 undefined when no support for stdint found as support
        wasn't added until C99, or C++11 (would be `long long` otherwise):
            - https://en.cppreference.com/w/c/language/arithmetic_types
    */
    typedef unsigned char       uint8;
    typedef unsigned short      uint16;
    typedef unsigned int        uint32;

    typedef signed char         int8;
    typedef signed short        int16;
    typedef signed int          int32;
#endif
/*=============================== Integers End ==============================*/


/*============================== Booleans Start =============================*/
/*
    NOTE(HS): bool64 undefined for same reason as int64/uint64 when no support for
    stdint.h present.
*/
#ifdef HSL_USE_FIXED_WIDTH_INTS
    typedef uint8_t  bool8;
    typedef uint16_t bool16;
    typedef uint32_t bool32;
    typedef uint64_t bool64;
#else
    typedef unsigned char       bool8;
    typedef unsigned short      bool16;
    typedef unsigned int        bool32;
#endif
/*=============================== Booleans End ==============================*/


/*=============================== Floats Start ==============================*/
typedef float f32;
typedef double f64;
/*================================ Floats End ===============================*/


/*============================ Byte Aliases Start ===========================*/
/*
    NOTE(HS): aliaes for size of things in bytes - given as "classical" definition,
    e.g. `KB(10)` == `10 * 1024`, `MB(5)` == `5 * 1024 * 1024`
*/
#define B(N)  ((size_t) N << 0)
#define KB(N) ((size_t) N << 10)
#define MB(N) ((size_t) N << 20)
#define GB(N) ((size_t) N << 30)
#define TB(N) ((size_t) N << 40)

/*
    NOTE(HS): win32 API declares `BYTE` as a typedef, so to avoid confusion this
    is omitted.
*/
#define KILOBYTE(N) KB(N)
#define MEGABYTE(N) MB(N)
#define GIGABYTE(N) GB(N)
#define TERABYTE(N) TB(N)
/*============================= Byte Aliases End ============================*/


/*=========================== Static Aliases Start ==========================*/
/// defines a static function which is *internal* to the current translation unit
#define INTERNAL static

/// defines a static variable with *local* lexical scope
#define LOCAL static

/// defines a static variable with *global* lexical scope
#define GLOBAL static
/*============================ Static Aliases End ===========================*/


/*=============================== Utils Start ===============================*/
/// Provices a clear & searchable way of indicating C-style type casts; inspired
/// by the static_cast, reinterpret, etc, cast functions available in C++.
#define CAST(T, V) ((T) V)
/*================================ Utils End ================================*/

#endif // HSLIBC_TYPES_H
/*
This software is available under 2 licences - chose whichever you prefer.
-------------------------------------------------------------------------------
ALTERNATIVE A - MIT License

Copyright (c) 2024 Henry Shakeshaft

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
-------------------------------------------------------------------------------
ALTERNATIVE B - Public Domain (www.unlicense.org)

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
*/
