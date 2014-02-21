#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06."  \
  COMMAND LINE: "web/ftangle web/reserved -A -# --F -= 1.53/web/reserved.c" \
  RUN TIME: "Saturday, September 23, 1995 at 16:17." \
  WEB FILE:    "web/reserved.web" \
  CHANGE FILE: (none)
#endif
#define normal  0 /* ordinary identifiers have |normal| ilk */
#define roman  1 /* normal index entries have |roman| ilk */
#define wildcard  2 /* user-formatted index entries have |wildcard| ilk */
#define typewriter  3 /* `typewriter type' entries have |typewriter| ilk */ \

#define is_reserved(a)(a->ilk>typewriter)/* tells if a name is a reserved word */ \

#define append_xref(c)if(xref_ptr==xmem_end) \
OVERFLW("cross-references","r"); \
else \
{ \
(++xref_ptr)->num= c; \
xref_ptr->Language= (boolean)language; \
} \

#define def_flag  ID_FLAG /* must be strictly larger than |max_modules| */ \

#define xref  equiv_or_xref /* The trouble with this is that |xref| is a \
	|xref_pointer| whereas |equiv_or_xref| is |ASCII|. This means that \
	lots of casting needs to be done to keep the compiler happy. Hence \
	the previous |typedef|. */ \

#undef expr  
#define expr  1 /* An expression, including perhaps a single identifier. */ \

#undef unop  
#define unop  2 /* A unary operator. */ \

#undef binop  
#define binop  3 /* A binary operator. */ \

#define unorbinop  4 \
/* An operator that can be unary or binary, depending on context. */
#define cast  5 /* A cast. */
#define question  6 /* A question mark and possibly the expressions flanking it. */
#define lbrace  7 /* A left brace. */
#define rbrace  8 /* A right brace. */
#define decl_hd  9 /* An incomplete declaration. */
#define comma  10 /* A comma. */
#define lpar  11 /* A left parenthesis. */
#define rpar  12 /* A right parenthesis. */
#define lbracket  13 /* A left bracket. */
#define rbracket  14 /* A right bracket. */
#define exp_op  18 /* Exponentiation. */ \

#define max_math  19 \
/* Category codes less than this can only be printed in math mode. */ \

#define struct_hd  21 /* The beginning of a structure specifier. */
#define decl  20 /* A complete declaration. */
#define label  22 /* Fortran statement label. */
#define stmt  23 /* A complete statement. */
#define functn  24 /* A complete function. */
#define fn_decl  25 /* A function declarator. */
#define else_like  26 /* The beginning of a conditional. */
#define semi  27 /* A semicolon. */
#define colon  28 /* A colon. */
#define tag  29 /* A statement label. */
#define if_hd  30 /* The beginning of a conditional. */
#define common_hd  31
#define read_hd  32
#define slashes  33
#define implicit_hd  34
#define lproc  35 /* Begins a preprocessor command. */
#define rproc  36 /* Ends a preprocessor command. */
#define ignore_scrap  37 /* A full preprocessor command. */
#define for_hd  38
#define newline  39
#define language_scrap  40 /* So we can change languages during translation. */ \

#define do_like  55 /* \&{do}. */
#define for_like  56 /* \&{for}, \&{switch}. */
#define if_like  57 /* \&{if}, \&{while},  \&{ifdef}, \&{ifndef}, \&{endif}. */
#define int_like  58 /* \&{int}, \&{char}, \&{extern}, \dots. */
#define case_like  59 /* \&{return}, \&{goto}, \&{break}, \&{continue}. */
#define sizeof_like  60 /* \&{sizeof}. */
#define struct_like  61 /* \&{struct}. */
#define typedef_like  62 /* \&{typedef}. */
#define define_like  63 /* \&{define}. */
#define common_like  64 /* \&{common}, \&{save}, \&{namelist} . */
#define read_like  65 /* \&{read}, \&{write}, \&{print}, \&{backspace}, \
	\&{rewind}, \&{open}, \&{close}, \&{endfile}, \&{inquire}, \&{decode}, \
	\&{encode}.  */
#define entry_like  66 /* \&{entry} . */
#define implicit_like  67 /* \&{implicit}. */
#define assign_like  68 /* \&{assign}. */
#define built_in  69 /* \&{changequote}, \&{define}, \&{divert}, \&{eval}, \
	\&{ifdef}, \&{ifdef}, \&{incr}, \&{len}, \&{undefine}, \&{undivert}. */
#define Rdo_like  70 /* \Ratfor\ \&{do}. */
#define endif_like  71 /* \&{endif}, \&{enddo}. */
#define end_like  72 /* \&{end}. */
#define END_like  73
#define go_like  74 /* \&{go}. */
#define no_order  75 /* \&{include}. */
#define until_like  76 /* \&{until}. */
#define IF_like  77
#define IF_top  78
#define else_hd  79
#define ELSE_like  80
#define space  81 /* For C~preprocessor. */
#define LPROC  82
#define UNOP  83 /* ``\.{{\it unop}\ }''. */
#define BINOP  84 /* ``\.{\ {\it binop}\ }''. */
#define COMMA  85 /* ``\.{\ {\it comma}\ }''. */
#define _EXPR  86 /* ``\.{\ {\it expr}}''. */
#define _EXPR_  87 /* ``\.{\ {\it expr}\ }''. */
#define EXPR_  88 /* ''\.{{\it expr}\ }''. */
#define Decl_hd  89
#define key_wd  90 /* May be unused now. */
#define program_like  91 /* |@r program|, |@r subroutine|, |@r function|. */
#define CASE_like  92
#define modifier  93 /* |const|, |volatile|. */
#define class_like  94 /* \Cpp: |class|. */
#define op_like  95 /* \Cpp: |operator|. */
#define new_like  96 /* \Cpp: |new|, |delete|. */
#define proc_like  97 /* \Fortran-90: |@r procedure|. */
#define private_like  98 /* \Fortran-90: |@r private|, |@r public|, |@r sequence|. */
#define slash_like  99 /* \Fortran: slash in |@r data| statement. */
#define fcn_hd  100 /* \Fortran: Beginning of function. */
#define END_stmt  101 /* \Fortran: |@r end;|. */
#define huge_like  102 /* For |huge|. */
#define imp_reserved  103 /* The result of~\.{@`}. */
#define extern_like  104 /* |extern|. */
#define while_do  105 /* |while| after |do|. */
#define template  106 /* |@c++ template| */
#define langle  107 /* A '\.<'. */
#define tstart  108 /* The '\.<' beginning a template list. */
#define tlist  109 /* |@c++ int<int, int>| */
#define rangle  110 /* A '\.>'. */
#define namespace  111 /* |@c++ namespace| */
#define virtual  112 /* |@c++ virtual| */
#define reference  113 /* |@c++ int& ref;| */ \

#define SAVE_ID(word_type0,language0,words) \
save_id(word_type0,language0,(CONST outer_char HUGE**)(words)) \

#define ALREADY_RESERVED(L)if(is_reservd.L)break;else is_reservd.L= YES \




#ifndef part
#define part 0 /* Standard value, when the files aren't split. */
#else
#if(part != 1 && part != 2 && part != 3)
#define part 1 /* Should issue error message here. */
#endif
#endif /* |part| */




#if(part == 0 || part == 1)
#define part1_or_extern
#define SET1(stuff)  =  stuff
#define TSET1(stuff)  =  stuff
#else
#define part1_or_extern extern
#define SET1(stuff)
#define TSET1(stuff)
#endif





#include "typedefs.h"







typedef struct xref_info0
{
sixteen_bits num;/* module number plus zero or |def_flag| */
struct xref_info0 HUGE*xlink;/* pointer to the previous \
				cross-reference */
boolean Language;/* Language in force for this module. */
}xref_info;

typedef xref_info HUGE*xref_pointer;
typedef ASCII HUGE*XREF_POINTER;/* For assignments like |name_dir->xref = \
				(XREF_POINTER)xref_ptr|. See the comment \
				immediately below about~|xref|. */




#include "c_type.h" /* Function prototypes for \.{common} (includes \
				reserved words). */




/* The shorter length here is primarily to keep the stack under control. \
Now that |N_MSGBUF| is used  dynamically, maybe this statement isn't \
necessary. */
#ifdef SMALL_MEMORY
#define N_MSGBUF 2000
#else
#define N_MSGBUF 10000
#endif





EXTERN boolean change_exists;/* has any module changed? */



#ifndef COMMON_FCNS_
IN_COMMON BUF_SIZE max_modules;/* Size allocated in \.{common.web}. */
#endif

EXTERN BUF_SIZE max_refs;
EXTERN xref_info HUGE*xmem;/* contains cross-reference information */
EXTERN xref_pointer xmem_end;

EXTERN xref_pointer xref_ptr;/* the largest occupied position in |xmem| */

EXTERN sixteen_bits xref_switch,mod_xref_switch;/* either zero or |def_flag|. */
EXTERN boolean defd_switch;/* Set by `\.{@[}'. */
EXTERN NAME_TYPE defd_type SET(NEVER_DEFINED);
EXTERN boolean typd_switch;/* Set by `\.{@]}'. */
EXTERN boolean index_short;/* Set by `\.{@+}'. */





/* For pc's, the file is split into two compilable parts using the \
compiler-line macro |part|, which must equal either~1 or~2. */
#if(part != 2)


SRTN save_words FCN((language0,words))
LANGUAGE language0 C0("The words are to be attached to this language.")
CONST RESERVED_WORD HUGE*words C1("Array of words to be stored.")
{
CONST RESERVED_WORD HUGE*r;
LANGUAGE outer_language;

outer_language= language;
language= language0;
language_num= (short)lan_num(language);
word_type= RESERVED_WD;/* Set global flag for |id_lookup|. */

for(r= words;r->type!=0;++r)
id_lookup(x_to_ASCII(OC(r->reserved_word)),NULL,
(eight_bits)CHOICE(r->type==(eight_bits)expr,normal,r->type));
/* Enter as reserved word. */

language= outer_language;
language_num= (short)lan_num(language);
}



SRTN save_id FCN((word_type0,language0,words))
WORD_TYPE word_type0 C0("|INTRINSIC_FCN| or |KEYWD|")
LANGUAGE language0 C0("They're for this language.")
CONST outer_char HUGE**words C1("Intrinsic names to be stored.")
{
CONST outer_char HUGE**i;
LANGUAGE outer_language;

outer_language= language;
language= language0;
language_num= (short)lan_num(language);
word_type= word_type0;

for(i= words;**i;i++)
id_lookup(x_to_ASCII(*i),
NULL,normal);/* Mark as intrinsic. \
				It's an ordinary identifier; will be \
				entered in index. */

language= outer_language;
language_num= (short)lan_num(language);
}



SRTN ini_special_tokens FCN((language0,tokens))
LANGUAGE language0 C0("")
SPEC HUGE*tokens C1("Array of tokens to be initialized.")
{
SPEC HUGE*s;
int n;
name_pointer np;

/* Fill in id token for keyword. */
for(s= tokens;(n= STRLEN(s->name))!=0;s++)
{
ASCII HUGE*p= x_to_ASCII(OC(s->name));

s->len= n;
*s->pid= ID_NUM_ptr(np,p,p+n);
np->expandable|= language0;
if(!np->x_translate)np->x_translate= 
(X_FCN(HUGE_FCN_PTR*HUGE*)(VOID))get_mem0(OC("x array"),
(unsigned long)(NUM_LANGUAGES),
sizeof(X_FCN(HUGE_FCN_PTR*)(VOID)));
np->x_translate[lan_num(language0)]= s->expand;
}
}



SRTN ini_out_tokens FCN((tokens))
SPEC HUGE*tokens C1("")
{
SPEC HUGE*s;

/* Fill in id token for keyword. */
for(s= tokens;(s->len= STRLEN(s->name))!=0;s++)
{
ASCII HUGE*p;
char HUGE*name,HUGE*p0,HUGE*p1;

/* We need a new memory area both in order to convert to |ASCII| and \
possibly to convert to lower case. */
name= (char HUGE*)(mod_text+1);

/* When the \.{-U} option is used, the output tokens must be converted to \
lower case. */
if(lowercase_tokens)
for(p1= name,p0= (char HUGE*)s->name;*p0;p0++)
*p1++= (ASCII)tolower(*p0);
else
STRCPY(name,s->name);

p= to_ASCII(OC(name));

*s->pid= ID_NUM(p,p+s->len);
}

}



static SPEC general_tokens[]= {
{"defined",0,NULL,&id_defined},/* For the expression evaluator. */
{"",0,NULL,NULL}
};



static RESERVED_WORD old_WEB_words[]= {
{"_A",built_in},
{"_ABS",built_in},
{"_ASSERT",built_in},
{"_COMMENT",built_in},
{"_DATE",built_in},
{"_DAY",built_in},
{"_DECR",built_in},
{"_DEFINE",built_in},
{"_DEFINED",built_in},
{"_DO",built_in},
{"_DUMPDEF",built_in},
{"_ERROR",built_in},
{"_EVAL",built_in},
{"_GETENV",built_in},
{"_HOME",built_in},
{"_IF",built_in},
{"_IFCASE",built_in},
{"_IFDEF",built_in},
{"_IFELSE",built_in},
{"_IFNDEF",built_in},
{"_INCR",built_in},
{"_INPUT_LINE",built_in},
{"_L",built_in},
{"_LANGUAGE",built_in},
{"_LANGUAGE_NUM",built_in},
{"_LEN",built_in},
{"_M",built_in},
{"_MAX",built_in},
{"_MIN",built_in},
{"_MODULES",built_in},
{"_MODULE_NAME",built_in},
{"_NARGS",built_in},
{"_OUTPUT_LINE",built_in},
{"_P",built_in},
{"_POW",built_in},
{"_ROUTINE",built_in},
{"_SECTION_NUM",built_in},
{"_SECTIONS",built_in},
{"_STRING",built_in},
{"_TIME",built_in},
{"_TRANSLIT",built_in},
{"_U",built_in},
{"_UNDEF",built_in},
{"_UNQUOTE",built_in},
{"_VERBATIM",built_in},
{"_VERSION",built_in},
{"",0}
};

static RESERVED_WORD WEB_words[]= {
{"$A",built_in},
{"$ABS",built_in},
{"$ASSERT",built_in},
{"$_BINOP_",BINOP},
{"$_COMMA_",COMMA},
{"$COMMENT",built_in},
{"$DATE",built_in},
{"$DAY",built_in},
{"$DECR",built_in},
{"$DEFINE",built_in},
{"$DEFINED",built_in},
{"defined",EXPR_},
{"$DO",built_in},
{"$DUMPDEF",built_in},
{"$ERROR",built_in},
{"$EVAL",built_in},
{"$_EXPR",_EXPR},
{"$_EXPR_",_EXPR_},
{"$EXPR_",EXPR_},
{"$GETENV",built_in},
{"$HOME",built_in},
{"$IF",built_in},
{"$IFCASE",built_in},
{"$IFDEF",built_in},
{"$IFELSE",built_in},
{"$IFNDEF",built_in},
{"$INCR",built_in},
{"$INPUT_LINE",built_in},
{"$L",built_in},
{"$LANGUAGE",built_in},
{"$LANGUAGE_NUM",built_in},
{"$LEN",built_in},
{"$M",built_in},
{"$MAX",built_in},
{"$MIN",built_in},
{"$MODULES",built_in},
{"$MODULE_NAME",built_in},
{"$NARGS",built_in},
{"$OUTPUT_LINE",built_in},
{"$P",built_in},
{"$POW",built_in},
{"$ROUTINE",built_in},
{"$SECTION_NUM",built_in},
{"$SECTIONS",built_in},
{"$STRING",built_in},
{"$TIME",built_in},
{"$TRANSLIT",built_in},
{"$UNOP_",UNOP},
{"$U",built_in},
{"$UNDEF",built_in},
{"$UNQUOTE",built_in},
{"$VERBATIM",built_in},
{"$VERSION",built_in},
{"",0}
};



SRTN save_WEB FCN((language0))
LANGUAGE language0 C1("")
{
save_words(language0,old_WEB_words);
save_words(language0,WEB_words);
}



static RESERVED_WORD M4_words[]= {
{"changequote",built_in},
{"define",built_in},
{"divert",built_in},
{"divnum",built_in},
{"dnl",built_in},
{"dumpdef",built_in},
{"errprint",built_in},
{"eval",built_in},
{"ifdef",built_in},
{"ifelse",built_in},
{"include",built_in},
{"incr",built_in},
{"index",built_in},
{"len",built_in},
{"maketemp",built_in},
{"sinclude",built_in},
{"substr",built_in},
{"syscmd",built_in},
{"translit",built_in},
{"undefine",built_in},
{"undivert",built_in},
{"",0}
};




static RESERVED_WORD C_words[]= {
{"auto",int_like},
{"break",case_like},
{"case",case_like},
{"char",int_like},
{"clock_t",int_like},/* ANSI. */
{"complex",int_like},/* EXTENSION. */
{"const",modifier},/* ANSI. */
{"continue",case_like},
{"default",case_like},
{"#define",define_like},/* (Preprocessor). */
{"div_t",int_like},/* ANSI. */
{"do",do_like},
{"double",int_like},
{"#elif",else_like},/* ANSI (Preprocessor). */
{"else",else_like},
{"#else",else_like},/* (Preprocessor). */
{"#endif",if_like},/* (Preprocessor). */
{"#error",if_like},/* ANSI (Preprocessor). */
{"extern",extern_like},
{"FILE",int_like},
{"float",int_like},
{"fortran",int_like},/* EXTENSION. */
{"fpos_t",int_like},/* ANSI. */
{"for",for_like},{"FOR",for_like},/* JAK. */
{"goto",case_like},
{"huge",huge_like},/* EXTENSION for personal computers. */
{"if",if_like},
{"#if",if_like},/* (Preprocessor). */
{"#ifdef",if_like},/* (Preprocessor). */
{"#ifndef",if_like},/* (Preprocessor). */
{"#include",if_like},/* (Preprocesor). */
{"int",int_like},
{"ldiv_t",int_like},/* ANSI. */
{"long",int_like},
{"#line",if_like},/* (Preprocessor). */
{"noalias",int_like},/* ANSI. */
{"#pragma",if_like},/* ANSI (Preprocessor). */
{"ptrdiff_t",int_like},/* ANSI. */
{"register",int_like},
{"return",case_like},
{"short",int_like},
{"sig_atomic_t",int_like},/* ANSI. */
{"signed",int_like},/* ANSI. */
{"size_t",int_like},/* ANSI. */
{"sizeof",sizeof_like},
{"static",int_like},
{"switch",for_like},
{"time_t",int_like},/* ANSI. */
{"typedef",typedef_like},
{"#undef",if_like},/* (Preprocessor). */
{"unsigned",int_like},
{"va_list",int_like},/* ANSI. */
{"volatile",modifier},/* ANSI. */
{"void",int_like},/* ANSI. */
{"wchar_t",int_like},/* ANSI. */
{"while",for_like},
{"",0}
};

static RESERVED_WORD C_words1[]= 
{
{"enum",struct_like},
{"struct",struct_like},
{"union",struct_like},
{"",0}
};



CONST char*C_intrinsics[]= {
"abort","atexit","exit","getenv","system",
"abs","div","labs","ldiv",
"acos","asin","atan","atan2","cos","sin","tan",
"asctime","ctime","gmtime","localtime","strftime","clock","difftime",
"mktime","time",
"assert",
"atof","atoi","atol","strtod","strtol","strtoul",
"bsearch","qsort",
"calloc","free","malloc","realloc",
"ceil","fabs","floor","fmod",
"fclose","fflush","fopen","freopen","setbuf","setvbuf",
"clearerr","feof","ferror","perror",
"cosh","sinh","tanh",
"exp","frexp","ldexp","log","log10","modf",
"fgetc","fgets","fprintf","fputc","fputs","fread","fscanf",
"fwrite","getc","getchar","gets","printf","putc","putchar",
"puts","scanf","sprintf","sscanf","ungetc",
"vfprintf","vprintf","vsprintf",
"fgetpos","fseek","fsetpos","ftell","rewind",
"printf","sprintf",
"isalnum","isalpha","iscntrl","isdigit","isgraph","islower",
"isprint","ispunct","isspace","isupper","isxdigit",
"localeconv","setlocale",
"longjmp","setjmp",
"mblen","mbstowcs","mbtowc","wcstombs","wctomb",
"memcmp","strcmp","strcoll","strncmp","strxfrm","strcat","strncat",
"memcpy","memmove","strcpy","strncpy",
"memset","strerror","strlen",
"memchr","strchr","strcspn","strpbrk","strrchr",
"strspn","strstr","strtok",
"offsetof",
"pow","sqrt",
"raise",
"rand","srand",
"remove","rename","tmpfile","tmpnam",
"strcpy","strcmp","strncpy","strlen",
"tolower","toupper",
"ungetc",
"va_arg","va_end","va_start",
"write",
""
};



static RESERVED_WORD Cpp_words[]= 
{
{"bool",int_like},/* ANSI. */
{"catch",expr},/* \Cpp--3.0 */
{"class",class_like},
{"const_cast",int_like},/* ANSI */
{"delete",new_like},
{"dynamic_cast",int_like},/* ANSI RTTI. */
{"friend",int_like},
{"inline",int_like},
{"mutable",int_like},/* ANSI. */
{"namespace",namespace},/* ANSI. */
{"new",new_like},
{"operator",op_like},
{"private",case_like},
{"protected",case_like},
{"public",case_like},
{"reinterpret_cast",int_like},/* ANSI */
{"static_cast",int_like},/* ANSI */
{"template",template},/* \Cpp--3.0. */
{"this",expr},
{"throw",case_like},/* \Cpp--3.0; it's like |return|. */
{"try",fn_decl},/* \Cpp--3.0 */
{"typeid",int_like},/* ANSI RTTI. */
{"using",int_like},/* ANSI namespaces. */
{"virtual",virtual},
{"",0}
};

static RESERVED_WORD Cpp_words1[]= 
{
{"enum",class_like},
{"struct",class_like},/* Overrides C ilk. */
{"union",class_like},
{"",0}
};

CONST char*Cpp_intrinsics[]= 
{
"set_new_handler",
""
};



static RESERVED_WORD F77_words[]= {
{"accept",read_like},
{"assign",assign_like},
{"backspace",read_like},
{"block",program_like},
{"blockdata",program_like},
{"call",case_like},
{"character",int_like},
{"close",read_like},
{"common",common_like},
{"complex",int_like},
{"continue",case_like},
{"data",no_order},
{"$decl_hd",decl_hd},
{"dimension",int_like},
{"do",Rdo_like},{"DO",for_like},
{"double",int_like},
{"doubleprecision",int_like},
{"else",else_like},
{"elseif",else_like},
{"end",end_like},
{"enddo",endif_like},
{"endif",endif_like},
{"endfile",read_like},
{"endfunction",end_like},
{"endprogram",end_like},
{"endsubroutine",end_like},
{"entry",entry_like},
{"equivalence",int_like},
{"external",int_like},
{"format",read_like},
{"function",program_like},
{"go",go_like},/* Can be combined with \&{to}. */
{"goto",case_like},
{"if",if_like},
{"implicit",implicit_like},
{"integer",int_like},
{"inquire",read_like},
{"intrinsic",int_like},
{"logical",int_like},
{"open",read_like},
{"parameter",int_like},
{"pause",case_like},
{"precision",int_like},
{"print",read_like},
{"program",program_like},
{"read",read_like},
{"REAL",int_like},/* EXTENSION. */
{"real",int_like},
{"return",case_like},
{"rewind",read_like},
{"save",common_like},
{"subroutine",program_like},
{"stop",case_like},
{"then",built_in},
{"to",built_in},
{"TYPE",read_like},/* Conflicts with \FORTRAN-88's |@r type| \
statement. */
{"write",read_like},
{"",0}
};



#ifdef VAXC
static RESERVED_WORD VAX_words[]= {
{"decode",read_like},
{"delete",read_like},
{"dictionary",int_like},
{"encode",read_like},
{"endmap",end_like},
{"endstructure",end_like},
{"endunion",end_like},
{"find",read_like},
{"INCLUDE",no_order},
{"map",struct_like},
{"namelist",common_like},
{"options",int_like},
{"record",common_like},
{"rewrite",read_like},
{"union",struct_like},
{"unlock",read_like},
{"virtual",int_like},
{"volatile",common_like},
{"",0}
};
#endif /* |VAXC| */



CONST char*F77_intrinsics[]= {
"abs","dabs","cabs",
"acos","dacos",
"aimag",
"aint","dint",
"amax0",
"amin0",
"anint","dnint",
"areal",
"asin","dasin",
"atan","datan",
"atan2","datan2","atan2d",
"char",
"cmplx",
"conjg",
"cos","dcos","ccos",
"cosh","dcosh",
"dble",
"dfloat",
"dim","ddim",
"dprod",
"exp","dexp","cexp",
"float",
"iabs",
"iand","ior","ieor","not",
"ichar",
"idim",
"idint","iqint",
"idnint","iqnint",
"ifix",
"int",
"isign",
"jnint",
"llt","lle","lgt","lge",
"log","alog","dlog","clog",
"log10","alog10","dlog10",
"max","amax1","dmax1",
"max0",
"max1",
"min","amin1","dmin1",
"min0",
"min1",
"mod","amod","dmod",
"Real",
"sngl",
"sign","dsign",
"sin","dsin","csin",
"sinh","dsinh",
"sqrt","dsqrt","csqrt",
"tan","dtan",
"tanh","dtanh",
"%val","%loc","%descr",
""
};



#ifdef VAXC
CONST char*VAX_intrinsics[]= {
"qsqrt","cdsqrt",
"qlog","cdlog","qlog10",
"qexp","cdexp",
"qsin","cdsin",
"sind","dsind","qsind",
"qcos","cdcod",
"cods","dcods","qcods",
"qtan",
"tand","dtand","qtand",
"qasin",
"asind","dasind","qasind",
"qacos",
"acosd","dacosd","qacosd",
"qatan",
"atand","datand","qatand",
"qatan2",
"atan2d","datan2d","qatan2d",
"qsinh","qcosh","qtanh",
"iiabs","jiabs","qabs","cdabs",
"iint","jint","iidint","jidint","iiqint","jiqint","qint",
"nint","inint","iidnnt","jidnnt","iiqnnt","jiqnnt","qnint",
"zext","izext","jzext",
"floati","floatj","snglq","dbleq",
"qext","qextd",
"iifix","jifix",
"floati","floatj",
"dfloti","dflotj",
"qfloat",
"dcmplx",
"dreal","dimag","dconjg",
"imax0","jmax0","qmax1","aimax0","ajmax0",
"imin0","jmin0","qmin1","aimin0","ajmin0",
"iidim","jidim","qdim",
"imod","jmod","qmod",
"iisign","jisign","qsign",
"iiand","jiand",
"iior","jior",
"iieor","jieor",
"inot","jnot",
"ishft","iishft","jishft",
"ibits","iibits","jibits",
"ibset","iibset","jibset",
"btest","bitest","bjtest",
"ibclr","iibclr","jibclr",
"ishftc","iishftc","jishftc",
""
};
#endif /* |VAXC| */



CONST char*F77_Keywords[]= {
"ACCESS",
"ASSOCIATEVARIABLE",
"BLANK",
"BLOCKSIZE",
"BUFFERCOUNT",
"CARRIAGECONTROL",
"DEFAULTFILE",
"DIRECT",
"DISP",
"END",
"ERR",
"EXIST",
"FILE",
"FMT",
"FORM",
"FORMATTED",
"IOSTAT",
"NAME",
"NAMED",
"NEXTREC",
"NUMBER",
"OPENED",
"RECL",
"SEQUENTIAL",
"STATUS",
"UNFORMATTED",
"UNIT",
""
};

CONST char*F77_keywords[]= {
"access",
"associatevariable",
"blank",
"blocksize",
"buffercount",
"carriagecontrol",
"defaultfile",
"direct",
"disp",
#if 0
"end",/* This has special meaning to \Fortran. */
#endif
"err",
"exist",
"file",
"fmt",
"form",
"formatted",
"iostat",
"name",
"named",
"nextrec",
"number",
"opened",
"recl",
"sequential",
"status",
"unformatted",
"unit",
""
};



#ifdef VAXC
CONST char*VAX_Keywords[]= {
"DISPOSE",
"EXTENDSIZE",
"INITIALSIZE",
"KEY",
"KEYED",
"MAXREC",
"NML",
"NOSPANBLOCKS",
"ORGANIZATION",
"READONLY",
"REC",
"RECORDSIZE","RECORDTYPE","RECORDSIZE",
"SHARED",
"TYPE",
"USEROPEN",
""
};
#endif /* |VAXC| */



static RESERVED_WORD F90_words[]= {
{"allocate",read_like},
{"allocatable",int_like},
{"assignment",op_like},
{"contains",entry_like},
{"cycle",case_like},
{"deallocate",read_like},
{"elsewhere",else_like},
{"endinterface",end_like},
{"endmodule",end_like},
{"endselect",end_like},
{"endtype",end_like},
{"endwhere",end_like},
{"exit",case_like},
{"include",no_order},
{"intent",int_like},
{"interface",struct_like},
{"module",program_like},
{"only",built_in},
{"optional",int_like},
{"nullify",read_like},
{"operator",op_like},
{"pointer",int_like},
{"private",private_like},
{"procedure",proc_like},
{"public",private_like},
{"recursive",int_like},
{"result",_EXPR},
{"save",int_like},
{"select",if_like},
{"sequence",private_like},
{"target",int_like},
{"type",struct_like},
{"use",no_order},
{"where",if_like},
{"while",for_like},
{"",0}
};



CONST char*F90_intrinsics[]= {
"achar",
"adjustl","adjustr",
"all","any",
"associated",
"bit_size",
"btest",
"ceiling",
"count",
"cshift",
"date_and_time",
"floor",
"digits",
"dotproduct",
"eoshift",
"epsilon",
"exponent","fraction",
"huge",
"iachar",
"ibclr","ibits","ibset","ishft","ishftc",
"kind",
"len_trim",
"LOGICAL",
"matmul",
"maxexponent","minexponent",
"maxloc","minloc",
"maxval","minval",
"merge",
"modulo",
"mvbits",
"nearest",
"pack",
"PRECISION",
"present",
"product",
"radix",
"random","randomseed",
"range",
"REPEAT",
"reshape",
"rrspacing",
"scale",
"scan",
"selected_int_kind","selected_real_kind",
"setexponent",
"spacing",
"spread",
"sum",
"system_clock",
"tiny",
"transfer",
"transpose",
"trim",
"ubound",
"unpack",
"verify",
""
};



CONST char*F90_Keywords[]= {
"ACTION",
"ADVANCE",
"DELIM",
"EOR",
"IN","INOUT","OUT",
"KIND",
"LEN",
"NML",
"NULLS",
"ONLY",
"PAD",
"POSITION",
"READ","READWRITE",
"REC",
"SIZE",
"STAT",
"WRITE",
""
};

CONST char*F90_keywords[]= {
"action",
"advance",
"delim",
"eor",
"in","inout","out",
"kind",
"len",
"nml",
"nulls",
"only",
"pad",
"position",
#if 0
"read",
#endif
"readwrite",
"rec",
"size",
"stat",
#if 0
"write",
#endif
""
};



static RESERVED_WORD RATFOR_words[]= {
{"break",case_like},
{"case",CASE_like},
{"default",case_like},
{"for",for_like},{"FOR",for_like},
{"next",case_like},
{"repeat",do_like},
{"switch",for_like},
{"until",until_like},
{"while",for_like},
{"",0}
};



CONST char*R77_keywords[]= {
"end",
""
};



extern RESERVED_WORD TEX_words[];



extern CONST char*TEX_intrinsics[];



typedef struct
{
boolean C,RATFOR,FORTRAN,TEX,LITERAL,C_PLUS_PLUS,RATFOR_90,FORTRAN_90;
}IS_RESERVED;

IS_RESERVED is_reservd= {NO,NO,NO,NO,NO,NO,NO,NO};

SRTN ini_reserved FCN((l))
LANGUAGE l C1("")
{
switch(l)
{
case NO_LANGUAGE:
CONFUSION("ini_reserved","Language should already be defined here");

case C:


ALREADY_RESERVED(C);

save_words(C,C_words);
save_words(C,C_words1);

save_WEB(C);

SAVE_ID(INTRINSIC_FCN,C,C_intrinsics);

ini_tokens(C)

;
break;

case C_PLUS_PLUS:


ALREADY_RESERVED(C_PLUS_PLUS);

save_words(C_PLUS_PLUS,C_words);
save_words(C_PLUS_PLUS,Cpp_words);/* Extra; don't change order here. */
save_words(C_PLUS_PLUS,Cpp_words1);

save_WEB(C_PLUS_PLUS);

SAVE_ID(INTRINSIC_FCN,C_PLUS_PLUS,C_intrinsics);
SAVE_ID(INTRINSIC_FCN,C_PLUS_PLUS,Cpp_intrinsics);/* Extra. */

ini_tokens(C_PLUS_PLUS)

;
break;

case FORTRAN:


ALREADY_RESERVED(FORTRAN);

save_words(FORTRAN,F77_words);
save_WEB(FORTRAN);

if(m4)
save_words(FORTRAN,M4_words);

SAVE_ID(INTRINSIC_FCN,FORTRAN,F77_intrinsics);
SAVE_ID(KEYWD,FORTRAN,F77_Keywords);

if(lc_keywords)
SAVE_ID(KEYWD,FORTRAN,F77_keywords);

#ifdef VAXC
save_words(FORTRAN,VAX_words);
SAVE_ID(INTRINSIC_FCN,FORTRAN,VAX_intrinsics);
SAVE_ID(KEYWD,FORTRAN,VAX_Keywords);
#endif /* |VAXC| */

ini_tokens(FORTRAN)

;
break;

case FORTRAN_90:


ALREADY_RESERVED(FORTRAN_90);

save_words(FORTRAN_90,F77_words);
save_words(FORTRAN_90,F90_words);/* Extra. */
save_WEB(FORTRAN_90);

if(m4)
save_words(FORTRAN_90,M4_words);

SAVE_ID(INTRINSIC_FCN,FORTRAN_90,F77_intrinsics);
SAVE_ID(INTRINSIC_FCN,FORTRAN_90,F90_intrinsics);/* Extra. */
SAVE_ID(KEYWD,FORTRAN_90,F77_Keywords);
SAVE_ID(KEYWD,FORTRAN_90,F90_Keywords);

if(lc_keywords)
{
SAVE_ID(KEYWD,FORTRAN_90,F77_keywords);
SAVE_ID(KEYWD,FORTRAN_90,F90_keywords);
}

#ifdef VAXC
save_words(FORTRAN_90,VAX_words);
SAVE_ID(INTRINSIC_FCN,FORTRAN_90,VAX_intrinsics);
SAVE_ID(KEYWD,FORTRAN_90,VAX_Keywords);
#endif /* |VAXC| */

ini_tokens(FORTRAN_90)

;
break;

case RATFOR:
if(!Rat_is_loaded)break;


ALREADY_RESERVED(RATFOR);

save_words(RATFOR,F77_words);
save_words(RATFOR,RATFOR_words);/* Extra. */
save_WEB(RATFOR);

if(m4)save_words(RATFOR,M4_words);

SAVE_ID(INTRINSIC_FCN,RATFOR,F77_intrinsics);
SAVE_ID(KEYWD,RATFOR,F77_Keywords);

if(lc_keywords)
{
SAVE_ID(KEYWD,RATFOR,F77_keywords);
SAVE_ID(KEYWD,RATFOR,R77_keywords);
}

#ifdef VAXC
save_words(RATFOR,VAX_words);
SAVE_ID(INTRINSIC_FCN,RATFOR,VAX_intrinsics);
SAVE_ID(KEYWD,RATFOR,VAX_Keywords);
#endif /* |VAXC| */

ini_RAT_tokens(RATFOR)

;
break;

case RATFOR_90:
if(!Rat_is_loaded)break;


ALREADY_RESERVED(RATFOR_90);

save_words(RATFOR_90,F77_words);
save_words(RATFOR_90,F90_words);
save_words(RATFOR_90,RATFOR_words);/* Extra. */
save_WEB(RATFOR_90);

if(m4)
save_words(RATFOR_90,M4_words);

SAVE_ID(INTRINSIC_FCN,RATFOR_90,F77_intrinsics);
SAVE_ID(INTRINSIC_FCN,RATFOR_90,F90_intrinsics);
SAVE_ID(KEYWD,RATFOR_90,F77_Keywords);
SAVE_ID(KEYWD,RATFOR_90,F90_Keywords);

if(lc_keywords)
{
SAVE_ID(KEYWD,RATFOR_90,F77_keywords);
SAVE_ID(KEYWD,RATFOR_90,R77_keywords);
SAVE_ID(KEYWD,RATFOR_90,F90_keywords);
}

#ifdef VAXC
save_words(RATFOR_90,VAX_words);
SAVE_ID(INTRINSIC_FCN,RATFOR_90,VAX_intrinsics);
SAVE_ID(KEYWD,RATFOR_90,VAX_Keywords);
#endif /* |VAXC| */

ini_RAT_tokens(RATFOR_90)

;
break;

case TEX:


ALREADY_RESERVED(TEX);

save_words(TEX,TEX_words);
save_WEB(TEX);

SAVE_ID(INTRINSIC_FCN,TEX,TEX_intrinsics);

ini_tokens(TEX)

;
break;

case LITERAL:


ALREADY_RESERVED(LITERAL);


;
break;

case NUWEB_OFF:
case NUWEB_ON:
CONFUSION("ini_reserved","Invalid language");
}

ini_out_tokens(general_tokens);/* For things such as |id_defined|. */
}


#endif /* Part 1 */

#if(part != 1)


RESERVED_WORD TEX_words[]= {

{"\\above",built_in},
{"\\abovedisplayshortskip",built_in},
{"\\abovedisplayskip",built_in},
{"\\abovewithdelims",built_in},
{"\\accent",built_in},
{"\\adjdemerits",built_in},
{"\\advance",built_in},
{"\\afterassignment",built_in},
{"\\aftergroup",built_in},
{"\\atop",built_in},
{"\\atopwithdelims",built_in}

,

{"\\baselineskip",built_in},
{"\\batchmode",built_in},
{"\\begingroup",built_in},
{"\\belowdisplayshortskip",built_in},
{"\\belowdisplayskip",built_in},
{"\\binoppenalty",built_in},
{"\\botmark",built_in},
{"\\box",built_in},{"\\bowmaxdepth",built_in},
{"\\brokenpenalty",built_in}

,

{"\\catcode",built_in},
{"\\char",built_in},{"\\chardef",typedef_like},
{"\\cleaders",built_in},
{"\\closein",built_in},{"\\closeout",built_in},
{"\\clubpenalty",built_in},
{"\\copy",built_in},
{"\\count",built_in},{"\\countdef",typedef_like},
{"\\cr",built_in},{"\\crcr",built_in},
{"\\csname",built_in}

,

{"\\day",built_in},/* \rm\the\day */
{"\\deadcycles",built_in},
{"\\def",typedef_like},
{"\\defaulthyphenchar",built_in},{"\\defaultskewchar",built_in},
{"\\delcode",built_in},
{"\\delimiter",built_in},{"\\delimiterfactor",built_in},
{"\\deflimitershortfall",built_in},
{"\\dimen",built_in},{"\\dimendef",typedef_like},
{"\\discretionary",built_in},
{"\\displayindent",built_in},
{"\\displaylimits",built_in},
{"\\displaystyle",built_in},
{"\\displaywidowpenalty",built_in},
{"\\displaywidth",built_in},
{"\\divide",built_in},
{"\\doublehyphendemerits",built_in},
{"\\dp",built_in},
{"\\dump",built_in}

,

{"\\edef",typedef_like},
{"\\eject",built_in},
{"\\else",built_in},
{"\\end",built_in},{"\\endcsname",built_in},
{"\\endcsname",built_in},
{"\\endgroup",built_in},
{"\\endinput",built_in},
{"\\endlinechar",built_in},
{"\\eqno",built_in},
{"\\errhelp",built_in},{"\\errmessage",built_in},
{"\\errorstopmode",built_in},
{"\\escapechar",built_in},
{"\\everycr",built_in},{"\\everydisplay",built_in},
{"\\everyhbox",built_in},{"\\everyjob",built_in},
{"\\everymath",built_in},{"\\everypar",built_in},
{"\\everyvbox",built_in},
{"\\exhyphenpenalty",built_in},
{"\\expandafter",built_in}

,

{"\\fam",built_in},
{"\\fi",built_in},
{"\\finalhyphendemerits",built_in},
{"\\firstmark",built_in},
{"\\floatingpenalty",built_in},
{"\\font",built_in},{"\\fontdimen",built_in},
{"\\fontname",built_in},
{"\\futurelet",typedef_like},
{"\\gdef",typedef_like},
{"\\global",built_in},{"\\globaldefs",built_in},
{"\\halign",built_in},
{"\\hangafter",built_in},{"\\hangindent",built_in},
{"\\hbadness",built_in},
{"\\hbox",built_in},
{"\\hfil",built_in},{"\\hfill",built_in},
{"\\hfilneg",built_in},
{"\\hfuzz",built_in},
{"\\hoffset",built_in},
{"\\hrule",built_in},
{"\\hskip",built_in},
{"\\hss",built_in},
{"\\ht",built_in},
{"\\hyphenation",built_in},
{"\\hyphenchar",built_in},{"\\hyphenpenalty",built_in}

,

{"\\if",built_in},{"\\ifcase",built_in},
{"\\ifcat",built_in},{"\\ifdim",built_in},{"\\ifeof",built_in},
{"\\iffalse",built_in},{"\\ifhbox",built_in},
{"\\ifhmode",built_in},{"\\ifinner",built_in},{"\\ifmmode",built_in},
{"\\ifnum",built_in},{"\\ifodd",built_in},
{"\\iftrue",built_in},
{"\\ifvbox",built_in},{"\\ifvmode",built_in},{"\\ifvoid",built_in},
{"\\ifx",built_in},
{"\\ignorespaces",built_in},
{"\\immediate",built_in},
{"\\indent",built_in},
{"\\input",built_in},
{"\\insert",built_in},{"\\insertpenalties",built_in},
{"\\interlinepenalty",built_in},
{"\\jobname",built_in},/* \rm \jobname */
{"\\kern",built_in}

,

{"\\lastbox",built_in},{"\\lastkern",built_in},
{"\\lastpenalty",built_in},{"\\lastskip",built_in},
{"\\lccode",built_in},
{"\\leaders",built_in},
{"\\left",built_in},
{"\\leqno",built_in},
{"\\leftskip",built_in},
{"\\let",typedef_like},
{"\\limits",built_in},
{"\\linepenalty",built_in},{"\\lineskip",built_in},
{"\\lineskiplimit",built_in},
{"\\llap",built_in},
{"\\long",built_in},
{"\\looseness",built_in},
{"\\lower",built_in},{"\\lowercase",built_in}

,

{"\\mag",built_in},
{"\\mark",built_in},
{"\\mathaccent",built_in},
{"\\mathbin",built_in},
{"\\mathchar",built_in},
{"\\mathchardef",built_in},
{"\\mathchoice",built_in},
{"\\mathclose",built_in},
{"\\mathcode",built_in},
{"\\mathinner",built_in},{"\\mathop",built_in},
{"\\mathop",built_in},{"\\mathopen",built_in},
{"\\mathord",built_in},
{"\\mathpunc",built_in},
{"\\mathrel",built_in},
{"\\mathsurround",built_in},
{"\\maxdeadcycles",built_in},
{"\\maxdepth",built_in},
{"\\meaning",built_in},
{"\\medmuskip",built_in},
{"\\message",built_in},
{"\\mkern",built_in},
{"\\month",built_in},/* \rm\the\month */
{"\\moveleft",built_in},{"\\moveright",built_in},
{"\\mskip",built_in},
{"\\multiply",built_in},
{"\\muskip",built_in},
{"\\muskipdef",built_in},
{"\\newlinechar",built_in},
{"\\noalign",built_in},
{"\\noexpand",built_in},
{"\\noindent",built_in},
{"\\nolimits",built_in},
{"\\nonscript",built_in},
{"\\nonstopmode",built_in},
{"\\nulldelimiterspace",built_in},
{"\\number",built_in}

,

{"\\omit",built_in},
{"\\openin",built_in},{"\\openout",built_in},
{"\\or",built_in},
{"\\outer",built_in},
{"\\output",built_in},{"\\outputpenalty",built_in},
{"\\over",built_in},
{"\\overfullrule",built_in},
{"\\overline",built_in},
{"\\overwithdelims",built_in}

,

{"\\pagedepth",built_in},
{"\\pagefilllstretch",built_in},{"\\pagefillstretch",built_in},
{"\\pagefilstretch",built_in},
{"\\pagegoal",built_in},
{"\\pageshrink",built_in},{"\\pagestretch",built_in},
{"\\pagetotal",built_in},
{"\\par",built_in},
{"\\parfillskip",built_in},
{"\\parindent",built_in},
{"\\parshape",built_in},{"\\parskip",built_in},
{"\\patterns",built_in},
{"\\pausing",built_in},
{"\\penalty",built_in},
{"\\postdisplaypenalty",built_in},
{"\\predisplaypenalty",built_in},
{"\\predisplaysize",built_in},
{"\\pretolerance",built_in},
{"\\prevdepth",built_in},
{"\\prevgraf",built_in},
{"\\radical",built_in},
{"\\raise",built_in},
{"\\read",built_in},
{"\\relax",built_in},
{"\\relpenalty",built_in},
{"\\right",built_in},
{"\\rightskip",built_in},
{"\\romannumeral",built_in}/* \romannumeral4 */

,

{"\\scripfont",built_in},{"\\scripscripfont",built_in},
{"\\scripscriptstyle",built_in},{"\\scriptspace",built_in},
{"\\scripstyle",built_in},
{"\\scrollmode",built_in},
{"\\setbox",built_in},
{"\\sfcode",built_in},
{"\\shipout",built_in},
{"\\show",built_in},{"\\showbox",built_in},
{"\\showboxbreadth",built_in},{"\\showboxdepth",built_in},
{"\\showhyphens",built_in},{"\\showlists",built_in},
{"\\showthe",built_in},
{"\\skewchar",built_in},
{"\\skip",built_in},{"\\skipdepth",built_in},
{"\\spacefactor",built_in},{"\\spaceskip",built_in},
{"\\span",built_in},
{"\\special",built_in},
{"\\splitbotmark",built_in},{"\\splitfirstmark",built_in},
{"\\splitmaxdepth",built_in},
{"\\splittopskip",built_in},
{"\\string",built_in},
{"\\tabskip",built_in}

,

{"\\textfont",built_in},
{"\\textstyle",built_in},
{"\\the",built_in},
{"\\thickmuskip",built_in},{"\\thinmuskip",built_in},
{"\\time",built_in},
{"\\toks",built_in},{"\\toksdef",built_in},
{"\\tolerance",built_in},
{"\\topmark",built_in},{"\\topskip",built_in},
{"\\tracingcommands",built_in},
{"\\tracinglostchars",built_in},
{"\\tracingmacros",built_in},
{"\\tracingonline",built_in},
{"\\tracingoutput",built_in},
{"\\tracingpages",built_in},
{"\\tracingparagraphs",built_in},
{"\\tracingrestores",built_in},
{"\\tracingstats",built_in}

,

{"\\ucode",built_in},{"\\uchyph",built_in},
{"\\underline",built_in},/* $\underline{\hbox{Underlined}}$ */
{"\\unhbox",built_in},
{"\\unhcopy",built_in},{"\\unkern",built_in},
{"\\unpenalty",built_in},{"\\unskip",built_in},
{"\\unvbox",built_in},{"\\unvcopy",built_in},
{"\\uppercase",built_in},/* \rm\uppercase{abc} */
{"\\vadjust",built_in},{"\\valign",built_in},
{"\\vbadness",built_in},
{"\\vbox",built_in},{"\\vcenter",built_in},
{"\\vfil",built_in},{"\\vfill",built_in},
{"\\vfilneg",built_in},
{"\\vfuzz",built_in},
{"\\voffset",built_in},
{"\\vskip",built_in},
{"\\vrule",built_in},
{"\\vsize",built_in},
{"\\vskip",built_in},
{"\\vskip",built_in},
{"\\vss",built_in},
{"\\vtop",built_in},
{"\\wd",built_in},
{"\\widowpenalty",built_in},
{"\\write",built_in},
{"\\xdef",typedef_like},
{"\\xleaders",built_in},
{"\\xspaceskip",built_in},
{"\\year",built_in}/* \rm\the\year */


,
{"",0}
};



CONST char*TEX_intrinsics[]= {

"\\aa",/*\rm \aa */
"\\AA",/*\rm \AA */
"\\active",
"\\acute",/* $\acute x$ */
"\\advancepageno",
"\\ae",/* \rm \ae */
"\\AE",/* \rm \AE */
"\\aleph",/* $\aleph$ */
"\\allowbreak",
"\\allowhyphens",
"\\alpha",/* $\alpha$ */
"\\amalg",/* $\amalg$ */
"\\angle",/* $\angle$ */
"\\approx",/* $\approx$ */
"\\arccos",/* $\arccos$ */
"\\arcsin",/* $\arcsin$ */
"\\arctan",/* $\arctan$ */
"\\arg",/* $\arg$ */
"\\arrowvert",/* $\arrowvert$ */
"\\Arrowvert",/* $\Arrowvert$ */
"\\ast",/* $\ast$ */
"\\asymp"/* $\asymp$ */

,

"\\b",/*\rm \b b */
"\\backslash",/* $\backslash$ */
"\\bar",/* $\bar x$ */
"\\beta",/* $\beta$ */
"\\bf",/* \bf boldface */
"\\bffam",
"\\bgroup",
"\\big",/* $\big[$ */
"\\Big",/* $\Big[$ */
"\\bigbreak",
"\\bigcap",/* $\bigcap$	 */
"\\bigcirc",/* $\bigcirc$ */
"\\bigcup",/* $\bigcup$ */
"\\bigg",/* $\bigg[$ */
"\\Bigg",/* $\Bigg[$ */
"\\biggl",/* $\biggl[$ */
"\\Biggl",/* $\Biggl[$ */
"\\biggm",/* $\biggm\vert$ */
"\\Biggm",/* $\Biggm\vert$ */
"\\biggr",/* $\biggr]$ */
"\\Biggr",/* $\Biggr]$ */
"\\bigl",/* $\bigl[$ */
"\\Bigl",/* $\Bigl[$ */
"\\bigm",/* $\bigm\vert$ */
"\\Bigm",/* $\Bigm\vert$ */
"\\bigodot",/* $\bigodot$ */
"\\bigoplus",/* $\bigoplus$ */
"\\bigotimes",/* $\bigotimes$ */
"\\bigr",/* $\bigr]$ */
"\\Bigr",/* $\Bigr]$ */
"\\bigskip","\\bigskipamount",
"\\bigsqcup",/* $\bigsqcup$ */
"\\bigtriangledown",/* $\bigtriangledown$ */
"\\bigtriangleup",/* $\bigtriangleup$ */
"\\biguplus",/* $\biguplus$ */
"\\bigvee",/* $\bigvee$ */
"\\bigwedge",/* $\bigwedge$ */
"\\bmod",
"\\body",/* $\bmod$ */
"\\bordermatrix",/* $\bordermatrix{&C&I&C'\cr \
				C&1&0&0\cr \
				I&b&1-b&0\cr \
				C'&0&a&1-a\cr}$ */
"\\bot",/* $\bot$ */
"\\bowtie",/* $\bowtie$ */
"\\brace",/* $n\brace k$ */
"\\braceld",/* $\braceld$ */
"\\bracelu",/* $\bracelu$ */
"\\bracerd",/* $\bracerd$ */
"\\braceru",/* $\braceru$ */
"\\bracevert",/* $\bracevert$ */
"\\brack",/* $n\brack k$ */
"\\break",
"\\breve",/* $\breve x$ */
"\\buildrel",
"\\bullet",/* $\bullet$ */
"\\bye"

,

"\\c",/* \rm\c x */
"\\cal",/* $\cal A$ */
"\\cap",/* $\cap$ */
"\\cases",/* $x = \cases{a&test\cr b&no test\cr}$ */
"\\cdot",/* $a\cdot b$ */
"\\cdotp",
"\\cdots",/* $a + \cdots$ */
"\\centering",
"\\centerline",
"\\check",/* $\check x$ */
"\\chi",/* $\chi$ */
"\\choose",/* $n\choose k$ */
"\\circ",/* $\circ$ */
"\\cleartabs",
"\\clubsuit",/* $\clubsuit$ */
"\\colon",/* $\colon$ */
"\\cong",/* $\cong$ */
"\\coprod",/* $\coprod$ */
"\\copyright",/*\rm\copyright */
"\\cos",/* $\cos$ */
"\\cosh",/* $\cosh$ */
"\\cot",/* $\cot$ */
"\\coth",/* $\coth$ */
"\\csc",/* $\csc$ */
"\\cup"/* $\cup$ */

,

"\\d",/* \rm\d x */
"\\dag",/* $\dag$ */
"\\dagger",/* $\dagger$ */
"\\dashv",/* $\dashv$ */
"\\ddag",/* $\ddag$ */
"\\ddagger",/* $\ddagger$ */
"\\ddot",/* $\ddot x$ */
"\\ddots",/* $\ddots$ */
"\\deg",/* $\deg$ */
"\\delta",/* $\delta$ */
"\\Delta",/* $\Delta$ */
"\\det",/* $\det$ */
"\\diamond",/* $\diamond$ */
"\\diamondsuit",/* $\diamondsuit$ */
"\\dim",/* $\dim$ */
"\\displaylines",
"\\div",/* $\div$ */
"\\dospecials",
"\\dosupereject",
"\\dot",/* $\dot x$ */
"\\doteq",/* $\doteq$ */
"\\dotfill",
"\\dots",/* $\dots$ */
"\\downarrow",/* $\downarrow$ */
"\\Downarrow",/* $\Downarrow$ */
"\\downbracefill"/* \hbox to 100pt{\downbracefill} */


,

"\\egroup",
"\\eject",
"\\ell",/* $\ell$ */
"\\empty",
"\\emptyset",/* $\emptyset$ */
"\\endgraf",
"\\endline",
"\\enskip","\\enspace",
"\\epsilon",/* $\epsilon$ */
"\\eqalign","\\eqalignno",
"\\equiv",/* $\equiv$ */
"\\eta",/* $\eta$ */
"\\exists",/* $\exists$ */
"\\exp"/* $\exp$ */

,

"\\filbreak",
"\\fiverm",/* \rm\fiverm Fiverm */
"\\flat",/* $\flat$ */
"\\folio",
"\\footins",
"\\footline","\\footnote","\\footnoterule",
"\\forall",/* $\forall$ */
"\\frenchspacing",/* \rm This is French spacing */
"\\frown",/* $\frown$	 */
"\\fullhsize","\\fullline",
"\\gamma",/* $\gamma$ */
"\\Gamma",/* $\Gamma$ */
"\\gcd",/* $\gcd$ */
"\\ge",/* $\ge$ */
"\\geq",/* $\geq$ */
"\\getfactor",
"\\gets",/* $\gets$ */
"\\gg",/* $\gg$ */
"\\glue",
"\\goodbreak",
"\\grave",/* $\grave x$ */
"\\hang",
"\\hat",/* $\hat x$ */
"\\hbar",/* $\hbar$ */
"\\headline",
"\\heartsuit",/* $\heartsuit$ */
"\\hglue",
"\\hideskip",
"\\hidewidth",
"\\hookleftarrow",/* $\hookleftarrow$ */
"\\hookrightarrow",/* $\hookrightarrow$ */
"\\hphantom",
"\\hrulefill"

,

"\\ialign",
"\\iff",/* $\iff$ */
"\\Im",/* $\Im$ */
"\\imath",
"\\in",/* $\in$ */
"\\inf",/* $\inf$ */
"\\infty",/* $\infty$ */
"\\int",/* $\int$ */
"\\interdisplaylinepenalty",
"\\interfootnotelinepenalty",
"\\iota",/* $\iota$ */
"\\it",/* \it Italics */
"\\item",
"\\itemitem",
"\\itfam",
"\\j",/* $\j$ */
"\\jmath",/* $\jmath$ */
"\\joinrel",
"\\jot",
"\\kappa",/* $\kappa$ */
"\\ker"/* $\ker$ */

,

"\\l",/* $\l$ */
"\\L",/* $\L$ */
"\\lambda",/* $\lambda$ */
"\\Lambda",/* $\Lambda$ */
"\\land",/* $\land$ */
"\\langle",/* $\langle$ */
"\\lbrace",/* $\lbrace$ */
"\\lbrack",/* $\lbrack$ */
"\\lceil",/* $\lceil$ */
"\\ldotp",
"\\ldots",/* $\ldots$ */
"\\le",/* $\le$ */
"\\leavevmode",
"\\leftarrow",/* $\leftarrow$ */
"\\Leftarrow",/* $\Leftarrow$ */
"\\leftarrowfill",/* \hbox to 100pt{\leftarrowfill} */
"\\leftharpoondown",/* $\leftharpoondown$ */
"\\leftharpoonup",/* $\leftharpoonup$ */
"\\leftline",
"\\leftrightarrow",/* $\leftrightarrow$ */
"\\Leftrightarrow",/* $\Leftrightarrow$ */
"\\leq",/* $\leq$ */
"\\leqalignno",
"\\lfloor",/* $\lfloor$ */
"\\lg",/* $\lg$ */
"\\lgroup",
"\\lhook",/* $\lhook$ */
"\\lim",/* $\lim$ */
"\\liminf",/* $\liminf$ */
"\\limsup",/* $\limsup$ */
"\\line",
"\\ll",/* $\ll$ */
"\\llap",
"\\lmoustache",/* $\lmoustache$ */
"\\ln",/* $\ln$ */
"\\lnot",/* $\lnot$ */
"\\log",/* $\log$ */
"\\longindentation",
"\\longleftarrow",/* $\longleftarrow$ */
"\\Longleftarrow",/* $\Longleftarrow$ */
"\\longleftrightarrow",/* $\longleftrightarrow$ */
"\\Longleftrightarrow",/* $\Longleftrightarrow$ */
"\\longmapsto",/* $\longmapsto$ */
"\\longrightarrow",/* $\longrightarrow$ */
"\\Longrightarrow",/* $\Longrightarrow$ */
"\\loop",
"\\lor",/* $\lor$ */
"\\lq"/* $\lq$ */

,

"\\magnification","\\magstep","\\magstephalf",
"\\maintoks",
"\\makefootline","\\makeheadline",
"\\mapsto",/* $\mapsto$ */
"\\mapstochar",/* $\mapstochar$ */
"\\mathhexbox",
"\\mathpalette",
"\\mathstrut",
"\\matrix",/* $\matrix{a&b\cr c&d\cr}$ */
"\\max",/* $\max$ */
"\\maxdimen",
"\\medbreak",
"\\medskip","\\medskipamount",
"\\mid",/* $\mid$ */
"\\midinsert",
"\\min",/* $\min$ */
"\\mit",/*\mit abc */
"\\models",/* $\models$ */
"\\mp",/* $\mp$ */
"\\mu",/* $\mu$ */
"\\multispan",
"\\nabla",/* $\nabla$ */
"\\narrower",
"\\natural",/* $\natural$ */
"\\ne",/* $\ne$ */
"\\nearrow",/* $\nearrow$ */
"\\neg",/* $\neg$ */
"\\negthinspace",
"\\neq",/* $\neq$ */
"\\newbox","\\newcount","\\newdimen","\\newfam",
"\\newhelp","\\newif","\\newinsert",
"\\newmuskip",
"\\newread","\\newskip","\\newtoks","\\newwrite",
"\\next",
"\\ni",
"\\ninepoint",
"\\ninerm",/*\ninerm Ninerm */
"\\nobreak",
"\\nointerlineskip",
"\\nonfrenchspacing",
"\\nopagenumbers",
"\\normalbaselines","\\normalbaselineskip",
"\\normalbottom","\\normallineskip","\\normallineskiplimit",
"\\not",/* $\not$ */
"\\notin",/* $\notin$ */
"\\nu",/* $\nu$ */
"\\null",
"\\nullfont",
"\\nwarrow"/* $\nwarrow$ */

,

"\\o",/* $\o$ */
"\\O",/* $\O$ */
"\\oalign",
"\\obeylines","\\obeyspaces",
"\\odot",/* $\odot$ */
"\\oe",/* \oe */
"\\OE",/* \OE */
"\\offinterlineskip",
"\\oint",/* $\oint$ */
"\\oldstyle",
"\\omega",/* $\omega$ */
"\\Omega",/* $\Omega$ */
"\\ominus",/* $\ominus$ */
"\\ooalign",
"\\openup",
"\\oplus",/* $\oplus$ */
"\\oslash",/* $\oslash$ */
"\\other",
"\\otimes",/* $\otimes$ */
"\\overbrace",/* $\overbrace{x+\cdots+x}^{k\rm\;times}$ */
"\\overleftarrow",/* $\overleftarrow{abc}$ */
"\\overrightarrow",/* $\overrightarrow{abc}$ */
"\\owns"/* $\owns$ */

,

"\\P",/* \P */
"\\pagebody","\\pagecontents",
"\\pageinsert","\\pageno",
"\\parallel",/* $\parallel$ */
"\\partial",/* $\partial$ */
"\\perp",/* $\perp$ */
"\\phantom",
"\\phi",/* $\phi$ */
"\\Phi",/* $\Phi$ */
"\\pi",/* $\pi$ */
"\\Pi",/* $\Pi$ */
"\\plainoutput",
"\\pm",/* $\pm$ */
"\\pmatrix",/* $\pmatrix{a&b\cr c&d\cr}$ */
"\\pmod",/* $\pmod$ */
"\\Pr",/* $\Pr$ */
"\\prec",/* $\prec$ */
"\\preceq",/* $\preceq$ */
"\\preloaded",
"\\prime",
"\\proclaim",
"\\prod",/* $\prod$ */
"\\propto",/* $\propto$ */
"\\ps",
"\\psi",/* $\psi$ */
"\\Psi",/* $\Psi$ */
"\\qquad",/* $x\qquad y$ */
"\\quad",/* $x\quad y$ */
"\\raggedbottom","\\raggedcenter","\\raggedright",
"\\rangle",/* $\rangle$ */
"\\rbrace",/* $\rbrace$ */
"\\rbrack",/* $\rbrack$ */
"\\rceil",/* $\rceil$ */
"\\Re",/* $\Re$ */
"\\relbar",/* $\relbar$ */
"\\Relbar",/* $\Relbar$ */
"\\removelastskip",
"\\repeat",
"\\rfloor",/* $\rfloor$ */
"\\rgroup",
"\\rho",/* $\rho$ */
"\\rhook",/* $\rhook$ */
"\\rightarrow",/* $\rightarrow$ */
"\\Rightarrow",/* $\Rightarrow$ */
"\\rightarrowfill",/* \hbox to 100pt{\rightarrowfill} */
"\\rightharpoondown",/* $\rightharpoondown$ */
"\\rightharpoonup",/* $\rightharpoonup$ */
"\\rightleftharpoons",/* $\rightleftharpoons$ */
"\\rightline",
"\\rlap",
"\\rm",/* \rm Roman */
"\\rmoustache",/* $\rmoustache$ */
"\\root",
"\\rq"/* $\rq$ */

,

"\\S",/* \S */
"\\sb",
"\\sc",/* \SC Small CAPS */
"\\searrow",/* $\searrow$ */
"\\sec",/* $\sec$ */
"\\setminus",/* $\setminus$ */
"\\settabs",
"\\setupverbatim",
"\\sevenrm",/* \sevenrm Sevenrm */
"\\sharp",/* $\sharp$ */
"\\sigma",/* $\sigma$ */
"\\Sigma",/* $\Sigma$ */
"\\sim",/* $\sim$ */
"\\simeq",/* $\simeq$ */
"\\sin",/* $\sin$ */
"\\sinh",/* $\sinh$ */
"\\skew",
"\\sl",/* \sl Slanted */
"\\slash",/* $\slash$ */
"\\slfam",
"\\smallbreak",
"\\smallint",/* $\smallint$ */
"\\smallskip","\\smallskipamount","\\smalltype",
"\\smash",
"\\smile",/* $\smile$ */
"\\sp",
"\\space",
"\\spadesuit",/* $\spadesuit$ */
"\\sqcap",/* $\sqcap$ */
"\\sqcup",/* $\sqcup$ */
"\\sqrt",/* $\sqrt\pi$ */
"\\sqsubseteq",/* $\sqsubseteq$ */
"\\sqsupseteq",/* $\sqsupseteq$ */
"\\ss",/* \rm\ss */
"\\star",/* $\star$ */
"\\strut","\\strutbox",
"\\subset",/* $\subset$ */
"\\subseteq",/* $\subseteq$ */
"\\succ",/* $\succ$ */
"\\succeq",/* $\succeq$ */
"\\sum",/* $\sum$ */
"\\sup",/* $\sup$ */
"\\supereject",
"\\supset",/* $\supset$ */
"\\supseteq",/* $\supseteq$ */
"\\surd",/* $\surd$ */
"\\swarrow"/* $\swarrow$ */

,

"\\t",/* \rm \t x */
"\\tabalign",
"\\tabs",
"\\tan",/* $\tan$ */
"\\tanh",/* $\tanh$ */
"\\tau",/* $\tau$ */
"\\tenex",
"\\tenpoint",
"\\tenrm",
"\\tensl",
"\\tensy",
"\\TeX",/* \TeX */
"\\textindent",
"\\theta",/* $\theta$ */
"\\Theta",/* $\Theta$ */
"\\thinspace",
"\\tilde",/* $\tilde x$ */
"\\times",/* $\times$ */
"\\to",/* $\to$ */
"\\top",/* $\top$ */
"\\topins","\\topinsert",
"\\tracingall",
"\\triangle",/* $\triangle$ */
"\\triangleleft",/* $\triangleleft$ */
"\\triangleright",/* $\triangleright$ */
"\\tt",/* \tt Typewriter */
"\\ttfam",
"\\ttglue",
"\\ttraggedright"

,

"\\u",/* \rm \u x */
"\\uncatcodespecials",
"\\undefined",
"\\underbar",/* \underbar{A} */
"\\underbrace",/* $\underbrace{x+\cdots+x}^{k\rm\;times}$ */
"\\up",
"\\uparrow",/* $\uparrow$ */
"\\Uparrow",/* $\Uparrow$ */
"\\upbracefill",/* \hbox to 100pt{\upbracefill} */
"\\updownarrow",/* $\updownarrow$ */
"\\Updownarrow",/* $\Updownarrow$ */
"\\uplus",/* $\uplus$ */
"\\upsilon",/* $\upsilon$ */
"\\Upsilon",/* $\Upsilon$ */
"\\v",/* \rm \v x */
"\\varepsilon",/* $\varepsilon$ */
"\\varphi",/* $\varphi$ */
"\\varpi",/* $\varpi$ */
"\\varrho",/* $\varrho$ */
"\\varsigma",/* $\varsigma$ */
"\\vartheta",/* $\vartheta$ */
"\\vdash",/* $\vdash$ */
"\\vdots",/* $\vdots$ */
"\\vec",/* $\vec x$	 */
"\\vee",/* $\vee$ */
"\\vert",/* $\vert$ */
"\\Vert",/* $\Vert$ */
"\\vfootnote",
"\\vglue",
"\\vphantom",
"\\wedge",/* $\wedge$ */
"\\widehat",/* $\widehat{\hbox{ab}}$ */
"\\widetilde",/* $\widetilde{\hbox{cd}}$ */
"\\wlog",
"\\wp",/* $\wp$ */
"\\wr",/* $\wr$ */
"\\xi",/* $\xi$ */
"\\Xi",/* $\Xi$ */
"\\zeta"/* $\zeta$ */

,
""
};



int cmpr_nd FCN((p0,p1))
NAME_INFO HUGE**p0 C0("")
NAME_INFO HUGE**p1 C1("")
{
switch(web_strcmp((*p0)->byte_start,(*p0+1)->byte_start,
(*p1)->byte_start,(*p1+1)->byte_start))
{
case EQUAL:
return 0;

case LESS:
case PREFIX:
return-1;

case GREATER:
case EXTENSION:
return 1;
}

return 0;
}


SRTN see_reserved FCN((prsrvd))
CONST RSRVD HUGE*prsrvd C1("")
{
CONST outer_char HUGE*pa= prsrvd->args;
unsigned n,k;
NAME_INFO HUGE**p,**p0,**p1,*nd= name_dir;
boolean all_languages= NO;

/* Note that the following stores every reserved word for every language.  This \
takes a lot of storage. */
for(k= 0;k<NUM_LANGUAGES;k++)
ini_reserved(lan_enum(k));

n= PTR_DIFF(unsigned,name_ptr,name_dir);
p= p0= p1= GET_MEM("p",n,NAME_INFO HUGE*);

for(k= 0;k<n;k++)
*p++= nd++;

QSORT(p0,n,sizeof(NAME_INFO HUGE*),cmpr_nd);

if(*pa=='*')
{
all_languages= YES;
pa++;
}

printf("Reserved words (%s)%s%s%s:\n",
all_languages?"all languages":languages[lan_num(language)],
*pa?" beginning with \"":"",(char*)pa,*pa?"\"":"");

for(p1= p0;p1<p;p1++)
{
ASCII temp[100];
size_t n= PTR_DIFF(size_t,((*p1)+1)->byte_start,(*p1)->byte_start);

/* Get the identifier. */
STRNCPY(temp,(*p1)->byte_start,n);
temp[n]= '\0';
to_outer(temp);

/* Test it and print info if required. */
if((all_languages||((*p1)->Language&language))&&
(!*pa||(STRNCMP(pa,temp,STRLEN(pa))==0)))
id_info(*p1,-1L,(outer_char*)temp,prsrvd);
}
}


#endif /* Part 2 */








