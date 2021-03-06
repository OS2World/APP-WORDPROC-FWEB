#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06." 
  COMMAND LINE: "web/ftangle web/os -A -# --F -= 1.53/web/os.h"
  RUN TIME: "Saturday, September 23, 1995 at 16:17."
  WEB FILE:    "web/os.web"
  CHANGE FILE: (none)
#endif



#ifndef OS_H_
#define OS_H_

#ifdef HAVE_CONFIG_H
#include "config.h" /* \.{config.h} is generated by \.{./configure}. */
#endif /* |HAVE_CONFIG_H| */




#include "custom.h" /* Macros defined by the user. */




#if OLD_PROTOTYPES
#define PROTO(args) () /* Old-style. */
#else
#define PROTO(args) args /* New-style. */
#endif /* |PROTOTYPES| */



#if(0)
/* Sun's system is hopeless. */
#if(NUM_VA_ARGS == 1)
#undef NUM_VA_ARGS
#define NUM_VA_ARGS 2
#endif
#endif

#if VARIABLE_ARGUMENTS
#define ELLIPSIS ,... /* ANSI standard; VAX allows for old-style \
declarations. */
#define VA_ARGS
#define VA_start
#if(NUM_VA_ARGS == 1)
#define VA_ALIST(args) (va_alist) /* Sun's way. */
#define VA_DCL(args) va_dcl
#define VA_START(a,n) va_start(a)
#else
#define VA_ALIST(args) args /* ANSI way. */
#define VA_DCL(args) args
#define VA_START(a,n) va_start(a,n)
#endif
#define VA_LIST(a) va_list a;
#else
#define ELLIPSIS /* Not permitted by \.{gcc} for old-style \
declarations. */
#define VA_ARGS ,arg_ptr
#define arg_ptr arg1,arg2,arg3,arg4,arg5,arg6,\
arg7,arg8,arg9,arg10,arg11,arg12,arg13
#define VA_start outer_char *arg1,*arg2,*arg3,*arg4,*arg5,*arg6,\
*arg7,*arg8,*arg9,*arg10,*arg11,*arg12,*arg13;
#define VA_ALIST(args) args
#define VA_DCL(args) args
#define VA_LIST(a)
#define VA_START(a,n)
#ifdef va_arg
#undef va_arg
#define va_arg(a,type) (type)"KLUDGE for va_arg"
#endif
#define va_end(a)
#define vprintf printf
#define vsprintf sprintf
#endif /* ANSI variable arguments. */



#if !NO_VOID  /* \.{Machine-dependent}: For machines \
that understand about |void *| or |void fcn()|. */
#define VOID void
#define SRTN void
#else
#define VOID /* For use in function declarations. */
#define void char
#define SRTN int
#endif /* |void| stuff. */

#if KEEP_CONST
#define CONST const
#else
#define CONST
#endif



#if OLD_PROTOTYPES
/* Old-style declarations. */
#define FCN(args) args
#define C0(cmnt) ;
#define C1(cmnt) ;
#define C2(cmnt) ;VA_start
#else
/* New-style declarations.  To use these macros, function declarations \
should have form |main FCN((num_args,args))|.  See one of the \FWEB\ \
sources for examples of the use of~|C0|, |C1|, and~|C2|. */
#define FCN(args) (

#define C0(cmnt) , /* Intermediate comments. */

#define C1(cmnt) ) /* Comment on last argument. */

#define C2(cmnt) ,...) /* Variable args. */
#endif /* |PROTOTYPES| */



/* SYSTEM LOGIC based on \.{custom.h}, and additional include files. */

#ifndef ANSI_CTYPE_H
#define ANSI_CTYPE_H 0
#endif

#ifndef ANSI_SPRINTF
#define ANSI_SPRINTF 0
#endif

#ifndef ANSI_SSCANF
#define ANSI_SSCANF 0
#endif

#ifndef ANSI_SYSTEM
#define ANSI_SYSTEM 0
#endif

#ifndef DEBUG_XCHR
#define DEBUG_XCHR 0
#endif

#ifndef FCN_CALLS
#define FCN_CALLS 0
#endif

#ifndef FANCY_SPLIT
#define FANCY_SPLIT 0
#endif

#ifndef HAVE_ERROR
#define HAVE_ERROR 0
#endif

#ifndef HAVE_GETENV
#define HAVE_GETENV 0
#endif

#ifndef HAVE_GETTIMEOFDAY
#define HAVE_GETTIMEOFDAY 0
#endif

#ifndef HAVE_LIMITS_H
#define HAVE_LIMITS_H 0
#endif

#ifndef HAVE_SYS_TIMEB_H
#define HAVE_SYS_TIMEB_H 0
#endif

#ifndef HAVE_STDARG_H
#define HAVE_STDARG_H 0
#endif

#ifndef HAVE_STDDEF_H
#define HAVE_STDDEF_H 0
#endif

#ifndef HAVE_STDLIB_H
#define HAVE_STDLIB_H 0
#endif

#ifndef HAVE_STD_PROTOTYPES
#define HAVE_STD_PROTOTYPES 0
#endif

#ifndef HAVE_STRERROR
#define HAVE_STRERROR 0
#endif

#ifndef HAVE_VALUES_H
#define HAVE_VALUES_H 0
#endif

#ifndef HUGE_POINTERS
#define HUGE_POINTERS 0
#endif

#ifndef KEEP_CONST
#define KEEP_CONST 0
#endif

#ifndef NEW_DIFFTIME
#define NEW_DIFFTIME 0
#endif

#ifndef NO_VOID
#define NO_VOID 0
#endif

#ifndef NON_ANSI_CALLOC
#define NON_ANSI_CALLOC 0
#endif

#ifndef OLD_PROTOTYPES
#define OLD_PROTOTYPES 0
#endif

#ifndef PRINT_AVAILABLE_MEMORY
#define PRINT_AVAILABLE_MEMORY 0
#endif

#ifndef SIZE_T_DEFINED
#define SIZE_T_DEFINED 0
#endif

#ifndef TIMING
#define TIMING 0
#endif

#ifndef TRANSLATE_ASCII
#define TRANSLATE_ASCII 0
#endif

#ifndef UNIX_PATH
#define UNIX_PATH 0
#endif



#if HAVE_STDARG_H
#include <stdarg.h>
#else
#include <varargs.h>
#endif

#if HAVE_STDLIB_H
#include <stdlib.h>
#endif

#if !HAVE_STD_PROTOTYPES
#include "stdlib0.h"
#endif

#if HAVE_STDDEF_H
#include <stddef.h>
#endif

#if HAVE_LIMITS_H
#include <limits.h> /* ANSI: Numerical limits. */
#else
#if HAVE_VALUES_H
#define INT_MAX MAXINT
#define LONG_MAX MAXLONG
#else
#define INT_MAX 0x7FFF
#define LONG_MAX INT_MAX
#endif

#define INT_MIN (~(INT_MAX))
#define LONG_MIN (~(LONG_MAX))
#define ULONG_MAX (MAXLONG | (~(MAXLONG)))
/* E.g., |0x7FFF OR0x8000|. */
#endif

#if HAVE_FLOAT_H
#include <float.h>
#else
#ifndef DBL_DIG
#define DBL_DIG 10
#endif
#endif

#if !NON_ANSI_CALLOC
#define CALLOC calloc
#define REALLOC(old_ptr, new_size, old_size) realloc(old_ptr, new_size)
#define FREE free
#endif /* |ANSI_CALLOC| */


/* Some compilers can't handle |unsigned long| constants of the form \
|123UL|.  Thus, these constants are declared via the following macro. */

#define UL(num) ((unsigned long)(num))

#include <stdio.h> /* ANSI: STDIO routines. */
#include <errno.h>

/* We use only ANSI write routines. */
#define FWRITE(buf,len,fp) fwrite((CONST void *)(buf),(size_t)(len),\
    (size_t)(1),fp)

#define WRITE1(buf,len) \
 {\
 int _k;\
 outer_char *_p;\
 for(_p= buf,_k= (int)(len); _k>0; _k--)\
   {\
   PUTC(*_p);\
   _p++;\
   }\
 }

/* The following is courtesy of the autoconf Info file. */
#if STDC_HEADERS || HAVE_STRING_H
#include <string.h> /* ANSI: String manipulation routines. */

#if !STDC_HEADERS && HAVE_MEMORY_H
#include <memory.h>
#endif
#else
#include <strings.h>
#endif

#include <ctype.h> /* ANSI: Character classification macros. */

/* The following works only for |ASCII| machines.  Furthermore, it's slower \
than the usual procedure involving ANDing a |_ctype| array with various bit \
flags.  However, that procedure isn't portable across machines.  Caution: \
This solution evaluates |c| more than once, so watch out for side effects! */
#if !ANSI_CTYPE_H
#undef isalpha
#undef isupper
#undef islower

#define isupper(c) ('A' <= (unsigned)(c) && (unsigned)(c) <= 'Z')
#define islower(c) ('a' <= (unsigned)(c) && (unsigned)(c) <= 'z')
#define isalpha(c) (isupper(c) || islower(c))
#endif

#include <setjmp.h> /* ANSI: |longjmp| and |setjmp|. */




/* --- TIMING --- */

/* The compiler-line macro |timing_width| overrides the default format for \
the time output; it's the number of \.x's in \.{n.xx} seconds. (See \
\.{custom.web}.) */
#ifndef TIMING_WIDTH
#define TIMING_WIDTH 1 /* We ensure that it's defined to something. */
#endif /* |TIMING_WIDTH| */

#include <time.h> /* ANSI: Time-conversion routines. (For non-ANSI \
			machines, defines |struct tm|.) */

#if TIMING

/* We like wall-clock timing more precise than seconds. */

/* \.{Machine-dependent}: Non-ANSI timing: */
#if HAVE_GETTIMEOFDAY
/* uSec timing */
#include <sys/time.h>
#undef NEW_DIFFTIME
#define NEW_DIFFTIME 1
#define TIME_T struct timeval
#ifdef _COMMON_h
struct timezone tz_dummy;
#endif
int gettimeofday PROTO((struct timeval*tp,struct timezone*tzp));
#define TIME(p) gettimeofday(p, &tz_dummy)
#else
#if HAVE_SYS_TIMEB_H
/* mSec timing */
#include <sys/timeb.h>
#undef NEW_DIFFTIME
#define NEW_DIFFTIME 1
#define TIME_T struct timeb
#define TIME(p) ftime(p)
#else /* ANSI timing */
#define TIME_T time_t
#define TIME(p) time(p)
#endif /* |HAVE_SYS_TIMEB_H| */
#endif /* |HAVE_GETTIMEOFDAY| */

#if NEW_DIFFTIME
#define DIFFTIME diff_time /* We supply our own version of \
|difftime| when we don't like the ANSI version. See \.{common.web}. (We \
can't just call our new version |difftime| because if that's already been \
prototyped the compiler will complain about a prototype mismatch.) */
#else
#define DIFFTIME difftime /* Use the ANSI routine. */
#endif /* |NEW_DIFFTIME| */

clock_t clock PROTO((VOID));/* Not defined on some machines. */

#ifndef CLOCKS_PER_SEC
#ifdef CLK_TCK
#define CLOCKS_PER_SEC CLK_TCK /* Some use older name. */
#else
#define CLOCKS_PER_SEC 1000000 /* Guess at default: \
$\mu$sec timing. */
#endif /* |CLK_TCK| */
#endif /* |CLOCKS_PER_SEC| */

#endif /* |TIMING| */



#ifndef THE_SYSTEM
#define THE_SYSTEM "UNKNOWN"
#endif

#ifndef LOCAL_BANNER
#define LOCAL_BANNER ""
#endif

#ifndef NULL_FILE_NAME
#define NULL_FILE_NAME "null"
#endif

#ifndef C_EXT
#define C_EXT "c"
#endif

#ifndef M_EXT
#define M_EXT "mk"
#endif

#ifndef X_EXT
#define X_EXT "sty"
#endif

#ifndef Cpp_EXT
#define Cpp_EXT "c++"
#endif

#ifndef R_EXT
#define R_EXT "r"
#endif

#ifndef R90_EXT
#define R90_EXT "r90"
#endif

#ifndef N_EXT
#define N_EXT "f"
#endif

#ifndef N90_EXT
#define N90_EXT "f90"
#endif

#ifndef VARIABLE_ARGUMENTS
#define VARIABLE_ARGUMENTS 0
#endif

#if VARIABLE_ARGUMENTS
#ifndef NUM_VA_ARGS
#define NUM_VA_ARGS 2
#endif
#endif

#ifndef PREFIX_END_CHAR
#define PREFIX_END_CHAR '/'
#endif




#ifndef _strmac_
#include "strmac.h" /* Macros for casting calls to string routines. */
#endif /* |_strmac_| */



#define UNUSED(var) var



#define HUGE_FCN_PTR

#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE /* Otherwise, the Sun gets hopelessly confused. */
#endif

#include <math.h> /* ANSI: Declarations of mathematics functions such as |pow|. */
#ifdef HUGE
#undef HUGE /* The Sun's annoying. */
#endif

#if HUGE_POINTERS /* \.{Machine-dependent}: Force full pointer arithmetic. */
#define HUGE huge /* \It{Normalized} far pointer. */
#else
#define HUGE /* Null def'n for everything except personal computers. */
#endif /* |HUGE_POINTERS| */



#define PLUS



#define CAST(type,var) var
#define _Xx(fmt) fmt







#endif /* |OS_H_| */





