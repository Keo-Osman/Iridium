#pragma once
#include <stdint.h>
// Unsigned int types.

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef float f32;
typedef double f64;

#if defined(__clang__) || defined(__GNUC__)
/** @brief Static assertion */
#define STATIC_ASSERT _Static_assert
#else

#define STATIC_ASSERT static_assert
#endif


STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");
STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");
STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");

#if defined(IRD_PLATFORM_WINDOWS)
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#elif defined(IRD_PLATFORM_LINUX)
// Linux OS
#define IRD_PLATFORM_LINUX 1
#if defined(__ANDROID__)
#error "Platform NOT Supported"
#endif
#else
#error "Platform NOT Supported"
#endif

#define GIBIBYTES(amount) ((amount)*1024ULL * 1024ULL * 1024ULL)
#define MEBIBYTES(amount) ((amount)*1024ULL * 1024ULL)
#define KIBIBYTES(amount) ((amount)*1024ULL)

#define GIGABYTES(amount) ((amount)*1000ULL * 1000ULL * 1000ULL)
#define MEGABYTES(amount) ((amount)*1000ULL * 1000ULL)
#define KILOBYTES(amount) ((amount)*1000ULL)

#define IRD_MIN(x, y) (x < y ? x : y)
#define IRD_MAX(x, y) (x > y ? x : y)

#define _BIT_IN_PLACE(x) (1 << x)