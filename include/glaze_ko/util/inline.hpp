// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

// GLZKO_DISABLE_ALWAYS_INLINE can be defined to disable forced inlining,
// reducing binary size and compilation time at the cost of peak performance.
#if !defined(GLZKO_DISABLE_ALWAYS_INLINE)
#if defined(__clang__) || defined(__GNUC__) || defined(_MSC_VER)
#ifndef GLZKO_USE_ALWAYS_INLINE
#define GLZKO_USE_ALWAYS_INLINE
#endif
#endif
#endif

// Enable always_inline when optimizing (-O1 or higher) or in release builds (NDEBUG)
// __OPTIMIZE__ is defined by GCC/Clang when any optimization level is enabled
#if defined(GLZKO_USE_ALWAYS_INLINE) && (defined(NDEBUG) || defined(__OPTIMIZE__))
#ifndef GLZKO_ALWAYS_INLINE
#if defined(_MSC_VER) && !defined(__clang__)
#define GLZKO_ALWAYS_INLINE [[msvc::forceinline]] inline
#else
#define GLZKO_ALWAYS_INLINE inline __attribute__((always_inline))
#endif
#endif
#endif

#ifndef GLZKO_ALWAYS_INLINE
#define GLZKO_ALWAYS_INLINE inline
#endif

// IMPORTANT: GLZKO_FLATTEN should only be used with extreme care
// It often adds to the binary size and greatly increases compilation times.
// It should only be applied in very specific circumstances.
// It is best to more often rely on the compiler.

#if !defined(GLZKO_DISABLE_ALWAYS_INLINE)
#if (defined(__clang__) || defined(__GNUC__)) && defined(NDEBUG)
#ifndef GLZKO_FLATTEN
#define GLZKO_FLATTEN inline __attribute__((flatten))
#endif
#endif
#endif

#ifndef GLZKO_FLATTEN
#define GLZKO_FLATTEN inline
#endif

#ifndef GLZKO_NO_INLINE
#if defined(__clang__) || defined(__GNUC__)
#define GLZKO_NO_INLINE __attribute__((noinline))
#elif defined(_MSC_VER)
#define GLZKO_NO_INLINE __declspec((noinline))
#endif
#endif
