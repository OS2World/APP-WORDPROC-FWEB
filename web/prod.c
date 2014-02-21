#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06."  \
  COMMAND LINE: "web/ftangle web/prod -A -# --F -= 1.53/web/prod.c" \
  RUN TIME: "Saturday, September 23, 1995 at 16:17." \
  WEB FILE:    "web/prod.web" \
  CHANGE FILE: (none)
#endif
#define _PROD_h   \

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

#define app(a)*(tok_ptr++)= a /* Ordinary token */
#define APP_ID  app(id_flag+PTR_DIFF(sixteen_bits,id_lookup(id_first,id_loc,normal),name_dir))
#define app1(a)app(tok_flag+PTR_DIFF(sixteen_bits,(a)->trans,tok_start))/* Store translation \
		as token list; should translate to the following: */
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

#define DFLUSH  if(dflush)puts(""); \

#define math_bin  (eight_bits)0345
#define math_rel  (eight_bits)0346 \

#define toggle_meta  (eight_bits)0347 \
 \
/* --- Non-math tokens (see |big_app| in \.{prod.web}) --- */
#define big_cancel  (eight_bits)0350 /* Like |cancel|; also overrides spaces. */
#define cancel  (eight_bits)0351 /* Override |backup|, |break_space|, |force|, |big_force|. */ \
 \
/* \bf The numerical order of the following must be preserved!! */
#define indent  (eight_bits)0352 /* One more tab (\.{\\1}). */
#define outdent  (eight_bits)0353 /* One less tab (\.{\\2}). */
#define opt  (eight_bits)0354 /* Optional break in mid-statement (\.{\\3}). */
#define backup  (eight_bits)0355 /* Stick out one unit to the left (\.{\\4}). */
#define break_space  (eight_bits)0356 /* Optional break between statements (\.{\\5}). */
#define force  (eight_bits)0357 /* Forced break between statements (\.{\\6}). */
#define big_force  (eight_bits)0360 /* Forced break with additional space (\.{\\7}). */ \

#define end_translation  (eight_bits)0361 /* Special sentinel token at end of list. */
#define trans  trans_plus.Trans /* translation texts of scraps */
#define no_math  2
#define yes_math  1
#define maybe_math  0 \

#define id_flag  ID_FLAG /* Signifies an identifier. */
#define res_flag  2*id_flag /* Signifies a reserved word. */
#define mod_flag  ((sixteen_bits)(3*(sixteen_bits)id_flag)) \
/* Signifies a module name. */
#define tok_flag  ((sixteen_bits)(4*(sixteen_bits)id_flag))/* signifies a token list. */
#define inner_tok_flag  ((sixteen_bits)(5*(sixteen_bits)id_flag)) \
/* Signifies a token list in `\Cb'. */ \
 \

#define freeze_text  *(++text_ptr)= tok_ptr \

#define b_app2(a)b_app1(a);b_app1(a+1)
#define b_app3(a)b_app2(a);b_app1(a+2)
#define b_app4(a)b_app3(a);b_app1(a+3) \

#define FIRST_ID(p)(((tok0= first_id(p->trans))&&tok0!=050)?name_dir+tok0- \
id_flag:name_dir)/* Ptr to actual id. */ \

#define cat0  pp->cat
#define cat1  (pp+1)->cat
#define cat2  (pp+2)->cat
#define cat3  (pp+3)->cat
#define cat4  (pp+4)->cat
#define cat5  (pp+5)->cat \

#define indent_force  b_app(indent);b_app(force) \
 \
/* Append $m$~things, followed by a space, followed by $n$~things. */
#define OPT9  APP_SPACE;app(opt);app(071) \

#define APP_SPACE  APP_STR("\\ ") \

#define INDENT  if(!indented) \
{ \
b_app(indent); \
indented= YES; \
} \

#define OUTDENT  if(indented) \
{ \
b_app(outdent); \
indented= NO; \
} \

#define MAX_OP_TOKENS  5 /* Maximum \# of tokens that could conceivably make up \
	the function name. */ \

#define REDUCE(j,k,c,d,n)reduce(j,k,(eight_bits)(c),d,(RULE_NO)(n))
#define SQUASH(j,k,c,d,n)squash(j,k,c,d,(RULE_NO)(n)) \

#define MAX_CYCLES  500
#define OUT_WIDTH  40



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





#include "map.h"




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



typedef sixteen_bits Token;
typedef Token HUGE*token_pointer;
typedef token_pointer HUGE*text_pointer;



typedef struct
{
eight_bits cat;/* Category. It would be nice to |enum| this, but \
that would turn it into an |int|, which could be as much as four times \
bigger. */
eight_bits mathness;
union
{
text_pointer Trans;



}trans_plus;
}scrap;

typedef scrap HUGE*scrap_pointer;



typedef unsigned long RULE_NO;/* Rule number for the productions. */




#include "p_type.h"





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



EXTERN long max_toks;/* number of symbols in \cee\ texts being parsed; \
  must be less than |@r 65536 == 2^16|. */
EXTERN Token HUGE*tok_mem;/* Dynamic array of tokens. */
EXTERN token_pointer tok_m_end;/* End of |tok_mem|. */

EXTERN long max_texts;/* number of phrases in \cee\ texts being parsed; \
  must be less than |ID_FLAG|. */
EXTERN token_pointer HUGE*tok_start;/* Dynamic directory into |tok_mem|. */
EXTERN text_pointer tok_end;/* End of |tok_start|. */

EXTERN token_pointer tok_ptr;/* First unused position in |tok_mem|. */
EXTERN text_pointer text_ptr;/* First unused position in |tok_start|. */

EXTERN token_pointer mx_tok_ptr;/* Largest value of |tok_ptr|. */
EXTERN text_pointer mx_text_ptr;/* Largest value of |text_ptr|. */



IN_PROD boolean dflush PSET(NO);/* Turn this on from debugger. */



EXTERN long max_scraps;/* Length of the next array. */
EXTERN scrap HUGE*scrp_info;/* Dynamic memory array for scraps */
EXTERN scrap_pointer scrp_end;/* end of |scrap_info|. */

EXTERN scrap_pointer pp;/* current position for reducing productions */
EXTERN scrap_pointer scrp_base;/* beginning of the current scrap sequence */
EXTERN scrap_pointer scrp_ptr;/* ending of the current scrap sequence */
EXTERN scrap_pointer lo_ptr;/* last scrap that has been examined */
EXTERN scrap_pointer hi_ptr;/* first scrap that has not been examined */

EXTERN scrap_pointer mx_scr_ptr;/* largest value assumed by |scrap_ptr| */



#ifndef COMMON_FCNS_
IN_COMMON int tracing;/* Can be used to show parsing details. */
#endif



IN_PROD int cur_mathness,ini_mathness,last_mathness;



IN_PROD sixteen_bits tok0;



IN_PROD PARSING_MODE translate_mode;/* Set by |translate|. */



IN_PROD boolean active_space PSET(NO);
IN_PROD boolean in_LPROC PSET(NO);
IN_PROD boolean expanded_lproc PSET(NO);



IN_PROD int in_prototype PSET(NO);
/* This is used as a numerical counter. */
IN_PROD int indented PSET(NO);



IN_PROD boolean in_function PSET(NO);



IN_PROD boolean typedefing PSET(NO);/* Are we inside a |typedef|? */






IN_PROD boolean forward_exp PSET(NO);



IN_PROD int fcn_level PSET(0);



IN_PROD text_pointer label_text_ptr[50];



IN_PROD boolean found_until PSET(NO);



IN_PROD int indent_level PSET(0);/* Indent level. */
IN_PROD int loop_num[50],max_loop_num PSET(0);



IN_PROD int containing PSET(0);



/* For pc's, the file is split into two compilable parts using the \
compiler-line macro |part|, which must equal either~1 or~2. */
#if(part != 2)

#ifdef DEBUG

SRTN
prn_cat FCN((c))
eight_bits c C1("Category.")
{
switch(c)
{
case language_scrap:printf("@L");break;
case expr:printf("expr");break;
case exp_op:printf("^^");break;
case _EXPR:printf("$_EXPR");break;case EXPR_:printf("$EXPR_");break;case _EXPR_:printf("$_EXPR_");break;
case new_like:printf("new_like");break;
case stmt:printf("stmt");break;
case decl:printf("decl");break;
case decl_hd:printf("decl_hd");break;
case Decl_hd:printf("$Decl_hd");break;
case struct_hd:printf("struct_hd");break;
case functn:printf("functn");break;
case fn_decl:printf("fn_decl");break;
case fcn_hd:printf("fcn_hd");break;
case else_like:printf("else");break;
case ELSE_like:printf("ELSE");break;
case if_hd:printf("if_hd");break;
case IF_top:printf("IF_top");break;
case else_hd:printf("else_hd");break;
case for_hd:printf("for_hd");break;
case unop:printf("unop");break;
case UNOP:printf("$UNOP_");break;
case binop:printf("binop");break;
case BINOP:printf("$_BINOP_");break;
case unorbinop:printf("unorbinop");break;
case semi:printf(";");break;
case colon:printf(":");break;
case comma:printf(",");break;
case COMMA:printf("$_COMMA_");break;
case question:printf("?");break;
case tag:printf("tag");break;
case cast:printf("cast");break;
case lpar:printf("(");break;
case rpar:printf(")");break;
case lbracket:printf("[");break;
case rbracket:printf("]");break;
case lbrace:printf("{");break;
case rbrace:printf("}");break;
case common_hd:printf("common_hd");break;
case read_hd:printf("read_hd");break;
case slash_like:printf("slash");break;
case private_like:printf("private");break;
case slashes:printf("slashes");break;
case lproc:printf("#{");break;
case LPROC:printf("LPROC");break;
case rproc:printf("#}");break;
case ignore_scrap:printf("ignore");break;

case define_like:printf("define");break;
case no_order:printf("no_order");break;
case do_like:printf("do");break;
case while_do:printf("while");break;
case Rdo_like:printf("Rdo");break;
case if_like:printf("if");break;
case IF_like:printf("IF");break;
case for_like:printf("for");break;
case program_like:printf("program");break;
case int_like:printf("int");break;
case modifier:printf("modifier");break;
case huge_like:printf("huge");break;
case CASE_like:printf("CASE");break;
case case_like:printf("case");break;
case sizeof_like:printf("sizeof");break;
case op_like:printf("op");break;
case proc_like:printf("proc");break;
case class_like:printf("class");break;
case struct_like:printf("struct");break;
case typedef_like:printf("typedef");break;
case imp_reserved:printf("imp_rsrvd");break;
case extern_like:printf("extern");break;
case common_like:printf("common");break;
case read_like:printf("read");break;
case entry_like:printf("entry");break;
case implicit_like:printf("implicit");break;
case implicit_hd:printf("implicit_hd");break;
case built_in:printf("built_in");break;
case endif_like:printf("endif");break;
case end_like:printf("end");break;
case END_like:printf("END");break;
case END_stmt:printf("END_stmt");break;
case go_like:printf("go");break;
case newline:printf("\n");break;
case label:printf("label");break;
case space:printf("space");break;
case until_like:printf("until");break;
case template:printf("template");break;
case langle:printf("langle");break;
case rangle:printf("rangle");break;
case tstart:printf("tstart");break;
case tlist:printf("tlist");break;
case namespace:printf("namespace");break;
case virtual:printf("virtual");break;
case reference:printf("ref");break;

case 0:printf("zero");break;
default:printf("UNKNOWN");break;
}

DFLUSH;
}

#endif /* |DEBUG| */



#ifdef DEBUG

SRTN
prn_text FCN((p))
text_pointer p C1("The token list.")
{
token_pointer j;/* index into |tok_mem| */
sixteen_bits r;/* remainder of token after the flag has been stripped off */

if(p>=text_ptr)printf("BAD");
else for(j= *p;j<*(p+1);j++)
{
r= (sixteen_bits)(*j%id_flag);

switch(*j/id_flag)
{
case 1:printf("\\\\{");prn_id((name_dir+r));printf("}");break;
/* |id_flag| */
case 2:printf("\\&{");prn_id((name_dir+r));printf("}");break;
/* |res_flag| */
case 3:printf("<");prn_id((name_dir+r));printf(">");break;
/* |mod_flag| */
case 4:printf("[[%d]]",r);break;/* |tok_flag| */
case 5:printf("|[[%d]]|",r);break;/* |inner_tok_flag| */
default:

switch(r)
{
case math_bin:printf("\\mathbin}");break;
case math_rel:printf("\\mathrel}");break;
case big_cancel:printf("[ccancel]");break;
case cancel:printf("[cancel]");break;
case indent:printf("[indent]");break;
case outdent:printf("[outdent]");break;
case backup:printf("[backup]");break;
case opt:printf("[opt]");break;
case break_space:printf("[break]");break;
case force:printf("[force]");break;
case big_force:printf("[fforce]");break;
case end_translation:printf("[quit]");break;
default:putxchar(XCHR(r));
}

;
}
}

DFLUSH;
}

#endif /* |DEBUG| */



SRTN
app_str FCN((s))
CONST outer_char HUGE*s C1("String to be appended.")
{
while(*s)app(XORD(*(s++)));
}

SRTN
app_ASCII_str FCN((s))
CONST ASCII HUGE*s C1("")
{
while(*s)app(*s++);
}



SRTN
b_app FCN((a))
Token a C1("Token to be appended.")
{
if(a==040||(a>=big_cancel&&a<=big_force))
{/* Appending a non-math token, including a space. */
if(cur_mathness==maybe_math)ini_mathness= no_math;
else if(cur_mathness==yes_math)app(044);/* End math	mode. */

cur_mathness= last_mathness= no_math;
}
else
{/* Append a math token. (Tokens can't be |maybe_math|.) */
if(cur_mathness==maybe_math)ini_mathness= yes_math;
else if(cur_mathness==no_math)app(044);/* Begin math mode. */

cur_mathness= last_mathness= yes_math;
}

app(a);
}



SRTN
b_app1 FCN((a))
scrap_pointer a C1("Scrap to be appended.")
{
switch(a->mathness%4)
{/* Left boundary (|ini_mathness|) of the current scrap. */
case no_math:
if(cur_mathness==maybe_math)
ini_mathness= no_math;
else if(cur_mathness==yes_math)
APP_STR("{}$");/* End math mode. (The braces take care of \
ending the math part with something like a~$+$.) */

cur_mathness= last_mathness= a->mathness/4;
/* Right boundary (|last_mathness|) */
break;

case yes_math:
if(cur_mathness==maybe_math)
ini_mathness= yes_math;
else if(cur_mathness==no_math)
APP_STR("${}");/* Begin math mode.  (The braces take care \
of beginning the math part with something like a~$+$.) */

cur_mathness= last_mathness= a->mathness/4;
/* Right boundary (|last_mathness|) */
break;

case maybe_math:
break;/* No changes */
}

app(a->trans+tok_flag-tok_start);
}


int
get_language FCN((xp))
text_pointer xp C1("")
{
token_pointer tp,tp1;

tp= *xp;
tp1= *(xp+1)-1;/* The |-1| is because we should always have the \
	combination |begin_language| followed by the language number. */

while(tp<tp1)
if(*tp++==begin_language)return*tp;

return CONFUSION("get_language",
"Can't find |begin_language| token in language_scrap");
}



SRTN
C_productions(VOID)
{
switch(pp->cat)
{
case ignore_scrap:

#if FCN_CALLS
C_ignore_scrap();
#else

{
switch(cat1)
{
case stmt:
case functn:
SQUASH(pp,2,cat1,0,1);
break;
}
}


#endif

break;
case built_in:
#if FCN_CALLS
R_built_in();
#else

{
b_app1(pp);

{
b_app(0134);b_app(054);
}

;
REDUCE(pp,1,expr,-2,9998);
}


#endif

break;
case expr:
#if FCN_CALLS
C_expr();
#else

{
if(cat1==lbrace||((!Cpp)&&cat1==int_like))
{/* ``|f(x) {}|'' or ``|f(x) float x;|'' (old-style) */
defined_at(make_underlined(pp));/* Recognized function name; \
remember current module number. */
in_function= YES;
SQUASH(pp,1,fn_decl,0,111);
}
else if(cat1==unop)
SQUASH(pp,2,expr,-2,2);/* ``|x--|'' */
else if(cat1==binop)
{
if(cat2==expr)
SQUASH(pp,3,expr,-2,3);/* ``|x + y|'' */
else if(cat2==decl_hd)
SQUASH(pp,3,tstart,0,6061);
/* Trap for ``|@c++ A<int>|'', with |A| undefined. */
}
else if(cat1==unorbinop&&cat2==expr)
{
sixteen_bits*s= *(pp+1)->trans;
b_app1(pp);

/* If the translation of the next scrap begins with an escape character, we \
assume we're seeing \.{\\amp}. */
if((s[0]==(sixteen_bits)0134)&&s[1]==(sixteen_bits)0141
&&s[2]==(sixteen_bits)0155)
{
APP_SPACE;b_app1(pp+1);APP_SPACE;/* ``|x & y|'' */
}
else b_app1(pp+1);/* ``|x*y|'' */

b_app1(pp+2);
REDUCE(pp,3,expr,-2,3000);
}
else if(cat1==comma)
{
if((cat2==expr||cat2==int_like))/* ``|x,y|'' or ``|x,char|''  */
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,cat2,-2,4);
}
else if(cat2==space)
SQUASH(pp,3,expr,-2,88);/* Macros. */
}
else if(cat1==expr)
SQUASH(pp,2,expr,-2,5);/* ``|f(x)|'' */
else if(cat1==semi)
SQUASH(pp,2,stmt,-1,6);/* ``|x;|'' */
else if(cat1==colon)/* ``|label:|'' */
{
if(!Cpp||in_function)
{/* Ordinary C tag. */
make_underlined(pp);/* Label name. */
SQUASH(pp,2,tag,0,7);
}
else if(cat2==expr)
{/* Put the spaces in explicitly in case we're not in math \
mode at the time. */
b_app1(pp);b_app(040);b_app1(pp+1);b_app(040);
b_app1(pp+2);
REDUCE(pp,3,expr,-2,701);
/* \Cpp: ``|@c++ derived() : base()|'' */
}
}
else if(cat1==space)
SQUASH(pp,2,expr,-2,8);/* For use in macros. */
}


#endif

break;
case exp_op:
#if FCN_CALLS
R_exp_op();
#else

{
if(cat1==lpar)SQUASH(pp,1,exp_op,PLUS 1,2995);/* ``|@r x^(a+b)|'' */
else if(cat1==expr)
if(cat2==lpar)SQUASH(pp,1,exp_op,PLUS 2,2996);/* Expand array \
argument. */
else if(cat2==expr)SQUASH(pp,1,exp_op,PLUS 1,2997);/* The expr is \
the result of expanding the array argument. */
else
{/* It's now of the form |@r x^expr|; insert braces around \
argument so \TeX\ understands. */
b_app1(pp);
b_app(0173);b_app1(pp+1);b_app(0175);
REDUCE(pp,2,expr,-1,2998);
}
}


#endif

break;
case _EXPR:
#if FCN_CALLS
C__E();
#else

{
APP_SPACE;b_app1(pp);
REDUCE(pp,1,expr,-2,4446);
}


#endif

break;
case _EXPR_:
#if FCN_CALLS
C__E_();
#else

{


APP_SPACE;b_app1(pp);APP_SPACE;

;
REDUCE(pp,1,expr,-2,4447);
}


#endif

break;
case EXPR_:
#if FCN_CALLS
C_E_();
#else

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,expr,-2,4448);
}


#endif

break;
case new_like:
#if FCN_CALLS
C_new_like();
#else

{
if(cat1==decl_hd||cat1==expr)
{/* \Cpp: |@c++ new int| or |@c++ new class(20)| */
b_app1(pp);b_app(040);b_app1(pp+1);
if(cat1==decl_hd)
{
OUTDENT;
}
REDUCE(pp,2,expr,-2,909);
}
}


#endif

break;
case lpar:
#if FCN_CALLS
C_lpar();
#else

{
if(cat2==rpar&&(cat1==expr||cat1==unorbinop))
SQUASH(pp,3,expr,-2,120);/* ``|(x)|''  or ``|(*)|''*/
else if(cat1==rpar)
{/* ``|()|''. This looks better with a bit of extra space between \
		the parens. */
b_app1(pp);
{
b_app(0134);b_app(073);
}

;b_app1(pp+1);
REDUCE(pp,2,expr,-2,121);
}
else if((cat1==decl_hd)&&cat2==rpar)
{/* Function prototype or cast, like ``|typedef (*T)|'' where |T| \
		was |typedef|d on the first pass. */
b_app3(pp);

OUTDENT;

if(in_prototype)
in_prototype--;

REDUCE(pp,3,cast,-1,122);
}
else if(cat1==stmt)
{/* ``|for(x;y;z)|'' */
b_app2(pp);b_app(040);REDUCE(pp,2,lpar,0,123);
}
else if(cat1==for_like&&cat2==rpar)
SQUASH(pp,3,expr,-2,1201);/* Macros: |(for)| */
}


#endif

break;
case lbracket:
#if FCN_CALLS
C_lbracket();
#else

{
if(active_brackets)
{
b_app(0134);
APP_STR("WXA{");
}
else b_app1(pp);

REDUCE(pp,1,lpar,0,5000);
}


#endif

break;
case rbracket:
#if FCN_CALLS
C_rbracket();
#else

{
if(active_brackets)
{
text_pointer t= indirect(pp->trans);

if(**t==0135)**t= 0175;
}

b_app1(pp);

REDUCE(pp,1,rpar,-3,5001);
}


#endif

break;
case question:
#if FCN_CALLS
C_question();
#else

{
if(cat1==expr&&cat2==colon)SQUASH(pp,3,binop,-2,30);/* ``|i==1 ? YES : \
					NO|'' */
}


#endif

break;
case unop:
#if FCN_CALLS
C__unop();
#else

{
if(cat1==expr)
SQUASH(pp,2,expr,-2,140);/* ``|!x|'' or ``|++x|'' */
else if(cat1==int_like)
SQUASH(pp,2,int_like,0,141);/* \Cpp\ destructor: \
			``|@c++ ~base|'' */
}


#endif

break;
case UNOP:
#if FCN_CALLS
C_UNOP();
#else

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,unop,-1,4443);
}


#endif

break;
case unorbinop:
#if FCN_CALLS
C_unorbinop();
#else

{
if(cat1==expr||(cat1==int_like&&!(cat2==lpar||cat2==unop)))
{/* ``|*p|'' or ``|&x|''; ``|typedef \
		(*T)|'' where |T| was |typedef|d on the first pass.  Not \
\Cpp:  ``|@c++ x + int(i)|'' or ``|@c++ x + base::y|''. */
b_app(0173);b_app1(pp);b_app(0175);
b_app1(pp+1);
REDUCE(pp,2,cat1,-2,150);
}
else if(cat1==binop)

{
b_app(math_bin);
b_app1(pp);
b_app(0173);b_app1(pp+1);b_app(0175);
b_app(0175);/* End |math_bin| */
REDUCE(pp,2,binop,-1,151);
}


}


#endif

break;
case binop:
#if FCN_CALLS
C__binop();
#else

{
if(cat1==binop)

{
b_app(math_bin);b_app1(pp);
b_app(0173);b_app1(pp+1);b_app(0175);
b_app(0175);/* End |math_bin| */
REDUCE(pp,2,binop,-1,180);
}

/* ``|+=|'' */
else if(cat1==space)
{
b_app1(pp);/* We eat the space in this macro situation. */
REDUCE(pp,2,binop,-1,181);/* |#if(a == b)|. */
}
else if(Cpp&&cat1==decl_hd)
SQUASH(pp,2,tstart,0,6063);
/* Trap for ``|@c++ A<int>|'', with |A| undefined.  See \
			also Rule 6061. */
}


#endif

break;
case BINOP:
#if FCN_CALLS
C_BINOP();
#else

{


APP_SPACE;b_app1(pp);APP_SPACE;

;
REDUCE(pp,1,binop,-1,4444);
}


#endif

break;
case COMMA:
#if FCN_CALLS
C_COMMA();
#else

{


APP_SPACE;b_app1(pp);APP_SPACE;

;
REDUCE(pp,1,comma,-1,4445);
}


#endif

break;
case cast:
#if FCN_CALLS
C_cast();
#else

{
if(cat1==expr)/* ``|(int *)p|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
REDUCE(pp,2,expr,-2,160);
}
else if(cat1==unorbinop||cat1==reference)
SQUASH(pp,1,cast,PLUS 1,162);/* ``|(int *)&prms|''. */
else
SQUASH(pp,1,expr,-2,161);/* Turn function prototype into expression. */
}


#endif

break;
case sizeof_like:
#if FCN_CALLS
C_sizeof_like();
#else

{
if(cat1==cast)
SQUASH(pp,2,expr,-2,170);/* ``|sizeof (int *)|'' */
else if(cat1==expr)
SQUASH(pp,2,expr,-2,171);/* ``|sizeof(x)|'' */
}


#endif

break;
case int_like:
#if FCN_CALLS
C_int_like();
#else

{
if(cat1==unop)
{
if(cat2==expr||cat2==int_like)
SQUASH(pp,3,expr,-2,35);/* \Cpp: |@c++ class::f| or \
			constructor: |@c++ class::class| */
else if(cat2==op_like)
SQUASH(pp,1,int_like,PLUS 2,36);/* \Cpp: Expand |@c++ operator| \
			construction. */
}
else if(cat1==int_like||cat1==struct_like)
{/* ``|extern int|'' or ``|@c++ typedef int bool|''. */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,cat1,0,40);
}
else if(cat1==reference)
SQUASH(pp,2,int_like,-2,43);/* |@c++ int &ref;| */
else if(cat1==expr||cat1==unorbinop||cat1==semi)
{/* ``|int i|'' or ``|int *|'' */
b_app1(pp);

if(cat1!=semi)
b_app(040);

INDENT;/* Start long declaration. (Note: Whenever we leave \
			|decl_hd|, we must |OUTDENT|.) */

REDUCE(pp,1,decl_hd,-1,41);
}
else if(cat1==comma)
{
b_app1(pp);
INDENT;
REDUCE(pp,1,decl_hd,-2,42);/* Function prototype: |int,|. */
}
else if(cat1==rpar)
{
b_app1(pp);
INDENT;
REDUCE(pp,1,decl_hd,-2,502);
}
else if(Cpp&&cat1==lpar&&!in_prototype)
{/* The \Cpp\ is a KLUDGE. Consider ``|int (*f)()|''. */
b_app1(pp);

{
b_app(0134);b_app(054);
}


REDUCE(pp,1,expr,-2,5021);/* \Cpp\ constructor: ``|@c++ base()|''; \
					or ``|@c++ int(x)|''. */
}
else if(cat1==binop&&cat2==expr)
SQUASH(pp,3,int_like,-2,5022);/* \Cpp\ initializer: |@c++ base = 0| */
else if(cat1==langle)
SQUASH(pp,1,int_like,PLUS 1,5997);/* |@c++ int<24>| */
else if(cat1==rangle)
{
b_app1(pp);
INDENT;
REDUCE(pp,1,decl_hd,-2,5998);
}
else if(cat1==class_like)
{/* \Cpp:  |@c++ friend class|. */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,class_like,0,5995);
}
else if(cat1==tlist)
SQUASH(pp,2,int_like,-2,5999);
else if(cat1==namespace)
{/* |@c++ using namespace| */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,namespace,0,5996);
}
}


#endif

break;
case extern_like:
#if FCN_CALLS
C_ext_like();
#else

{
if(Cpp&&cat1==expr)
{/* |@c++ extern "C"| */
b_app1(pp);b_app(040);b_app1(pp+1);
if(cat2==lbrace)
REDUCE(pp,2,fn_decl,0,5025);/* ``|@c++ extern "C" {}|''. */
else
REDUCE(pp,2,int_like,0,5023);
/* ``|@c++ extern "C" int fcn();|'' */
}
else
SQUASH(pp,1,int_like,0,5024);
}


#endif

break;
case modifier:
#if FCN_CALLS
C_modifier();
#else

{
if(cat1==int_like)
SQUASH(pp,1,int_like,-2,503);
else if(pp==lo_ptr)
SQUASH(pp,1,expr,0,5040);
else if(cat1==semi||cat1==lbrace)
SQUASH(pp,1,_EXPR,0,5042);
/* |@c++ int f() const;| or |@c++ int f() const {}|. */
else
SQUASH(pp,1,EXPR_,0,5041);
}


#endif

break;
case huge_like:
#if FCN_CALLS
C_huge_like();
#else

{
if(cat1==unorbinop)
{
b_app1(pp);APP_SPACE;b_app1(pp+1);
REDUCE(pp,2,unorbinop,-1,505);
}
}


#endif

break;
case decl_hd:
#if FCN_CALLS
C_decl_hd();
#else

{
if(cat1==rpar)
{
if((pp-1)->cat==lpar)
SQUASH(pp,1,decl_hd,-1,4990);/* ``|(int i)|''. */
else if((pp-2)->cat==decl_hd)
SQUASH(pp,1,decl_hd,-2,4991);/* ``|(int i, int j)|''. */
else if((pp-3)->cat==decl_hd)
SQUASH(pp,1,decl_hd,-3,4992);
}
else if(cat1==decl_hd)
SQUASH(pp,2,decl_hd,0,50);/* ``|(int,int)|'' */
else if(cat1==comma)
{
if(cat2==decl_hd)
{/* For function prototype. */
b_app2(pp);OPT9;
b_app1(pp+2);
REDUCE(pp,3,decl_hd,0,501);
}
else if(cat2==ignore_scrap&&cat3==decl_hd)
{/* For function prototype with comment. */
b_app2(pp);OPT9;
b_app2(pp+2);
REDUCE(pp,4,decl_hd,0,504);
}
#if 0
else if(Cpp&&(cat2==decl||cat2==stmt))
SQUASH(pp,3,stmt,-2,508);
/* ``|@c++ for(int i=0, int j=0;;)|'' or ``|@c++ \
				for(int i=0, int j=0, int k=0;;)|''. */
#endif
else
{/* ``|int i,|'' */
if(cat2==ignore_scrap&&(cat3==int_like||cat3==struct_like||
cat3==modifier))
{/* Function prototype, with intervening comment. */
b_app1(pp);
if((pp-3)->cat!=decl_hd&&(pp-2)->cat!=decl_hd
&&cat3!=modifier)
in_prototype++;
REDUCE(pp,1,decl_hd,PLUS 3,5221);
}
else if(cat2==int_like||cat2==struct_like||cat2==modifier)
{/* Function prototype. */
b_app1(pp);
if((pp-3)->cat!=decl_hd&&(pp-2)->cat!=decl_hd
&&cat2!=modifier)
in_prototype++;/* The |modifier| clause is to \
prevent a situation like |(int, const int)| from thinking it's two levels \
of prototypes. */
REDUCE(pp,1,decl_hd,PLUS 2,52);
}
else
{/* Expecting list of something. */
b_app2(pp);b_app(040);

#if 0
if(Cpp)
REDUCE(pp,2,decl_hd,-2,540);
/* ``|@c++ int i=0, int j=0|'' (e.g., in |for|) */
else
#endif
REDUCE(pp,2,decl_hd,-1,54);/* ``|int i,j|'' */
}
}
}
else if(cat1==unorbinop)/* ``|int **p|'' */
{
b_app1(pp);
b_app1(pp+1);
REDUCE(pp,2,decl_hd,-1,55);
}
else if(cat1==expr)/* ``|int i|'' or ``|int i, j|'' */
{
make_underlined(pp+1);
SQUASH(pp,2,decl_hd,-1,56);/* The |-1| is to pick up a left \
					paren for function prototype. */
}
else if((cat1==binop||cat1==colon
||cat1==expr /* (for initializations) */
)&&cat2==expr&&(cat3==comma||cat3==semi||cat3==rpar))
#if 0
if(cat1==binop)
{
b_app1(pp);b_app(040);b_app2(pp+1);
REDUCE(pp,3,decl_hd,-1,5660);
}
else
#endif
SQUASH(pp,3,decl_hd,-1,5661);
else if(cat1==int_like&&(cat2==unop||cat2==langle))
SQUASH(pp,1,decl_hd,PLUS 1,5662);
/* \Cpp:  ``|@c++ void *int::fcn()|'' or ``|@c++ void \
		*int<int>::fcn()|'' */
else if(cat1==lbrace||(cat1==int_like&&
((pp-1)->trans==NULL||**(pp-1)->trans!=050)))/* \
Recognize beginning of function: ``|float f() {}|'' or ``|float f(x) float \
x|'' */
{
b_app1(pp);
OUTDENT;
in_function= YES;
defined_at(FIRST_ID(pp));
REDUCE(pp,1,fn_decl,0,58);
}
else if(cat1==semi)
{/* ``|int i;|'' */
b_app2(pp);
OUTDENT;/* Finish long declaration. */
#if 0
if(Cpp)
REDUCE(pp,2,decl,-2,594);
/* ``|@c++ for(int i=0, int j=0;;)|'' */
else
#endif
REDUCE(pp,2,decl,-1,59);
}
else if(Cpp&&cat1==int_like&&cat2==unop)
SQUASH(pp,1,decl_hd,PLUS 1,590);/* \Cpp: |@c++ void *class::f| */
else if(Cpp&&cat1==rangle)
SQUASH(pp,1,decl_hd,-2,591);/* \Cpp:  end of template. */
else if(Cpp&&cat1==struct_like)
SQUASH(pp,2,decl_hd,-1,593);
/* \Cpp: |@c++ template<class C1, class C2>|. */
}


#endif

break;
case decl:
#if FCN_CALLS
C_decl();
#else

{
if(Cpp)
{
if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,functn,-1,61);
}
else
SQUASH(pp,1,stmt,-1,611);/* E.g., ``|@c++ for(int i=0;;)|'' */
}
else
{
if(cat1==decl)
{/* ``|int i; float x;|'' */
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,60);
}
else if(cat1==stmt||cat1==functn)
{/* ``|int i; x=0;|'' or ``|int i; f(){}|'' */
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,cat1,-1,61);
}
}
}


#endif

break;
case typedef_like:
#if FCN_CALLS
C_typedef_like();
#else

{
if(cat1==decl_hd&&(cat2==expr||cat2==int_like))
{
make_underlined(pp+2);make_reserved(pp+2);/* NEEDS TO BE IMPROVED! */
b_app2(pp+1);
REDUCE(pp+1,2,decl_hd,0,90);
}
else if(cat1==decl)
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,decl,-1,91);
}
else if(cat1==semi)
SQUASH(pp,2,stmt,-1,94);
/* ``|typedef|''. */
else if(cat1==stmt)
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,stmt,-1,95);
/* ``|typedef int I[3]|''. (|I| is defined in first pass.) */
}

}


#endif

break;
case imp_reserved:
#if FCN_CALLS
C_imp_reserved();
#else

{
if(typedefing)SQUASH(pp,1,expr,-2,92);
else SQUASH(pp,1,int_like,-2,93);
}


#endif

break;
case op_like:
#if FCN_CALLS
C_op_like();
#else

{
short n;
/* The actual number of tokens that make up the effective function name. */

if((cat1==lpar&&cat2==rpar)||(cat1==lbracket&&cat2==rbracket))
{/* |@c++ operator ()()|  is a special case because it begins with \
left paren.  |@c++ operator []()| is handled as a special case because we \
now have the categories |lbracket| and |rbracket|, and |lbracket| doesn't \
regress when it's reduced to |lpar|. */
b_app1(pp);b_app(040);b_app1(pp+1);

{
b_app(0134);b_app(054);
}


b_app1(pp+2);
n= 3;
}
else
{/* We'll search for the obligatory left paren that indicates the \
argument list. */
scrap_pointer q;
int k;/* Counter. */

/* If the paren is missing, we could end up appending the entire rest of \
the code, so we limit the search. */
for(q= pp+1;q<=scrp_ptr&&q-pp<=MAX_OP_TOKENS;q++)
if(q->cat==lpar)break;

n= (q->cat==lpar)?PTR_DIFF(short,q,pp):0;

/* Append all the tokens between |operator| and left paren. */
if(n>0)
{
text_pointer xp;
token_pointer tp,tp1;

b_app1(pp);b_app(040);/* |operator| */
b_app(0173);/* Braces prevent possible spurious blanks \
before the left paren. */

id_first= id_loc= mod_text+1;

for(k= 1;k<n;k++)
{
b_app1(pp+k);

xp= indirect((pp+k)->trans);
tp= *xp;
tp1= *(xp+1);
while(tp<tp1)
*id_loc++= (ASCII)(*tp++);
}

underline_xref(id_lookup(id_first,id_loc,0));

b_app(0175);
}
}

if(n>0)
REDUCE(pp,n,expr,-2,6666);
}


#endif

break;
case class_like:
#if FCN_CALLS
C_class_like();
#else

{
if(cat1==expr||cat1==int_like)
{/* \Cpp: |@c++ class A| */
make_underlined(pp+1);make_reserved(pp+1);

b_app1(pp);b_app(040);b_app1(pp+1);

if((pp-1)->cat==tstart||(pp-1)->cat==decl_hd)
REDUCE(pp,2,decl_hd,-1,8998);
else
REDUCE(pp,2,struct_like,0,8999);
}
else if(cat1==lbrace)
SQUASH(pp,1,struct_like,0,8987);
/* |@c++ class{}| or |@c++ struct{}|. */
}


#endif

break;
case struct_like:
#if FCN_CALLS
C_struct_like();
#else

{
if(cat1==lbrace)
{/* ``|struct {int i;} S;|'' or \Cpp: ``|@c++ class A{int i;};|'' */
b_app1(pp);indent_force;
b_app1(pp+1);REDUCE(pp,2,struct_hd,0,100);
}
else if(cat1==expr)
{/* Structure name: ``|struct s|'' */
if(cat2==lbrace)/* ``|struct s {}|'' */
{
/* In \Cpp, this construction defines a new type. */
if(Cpp)
{make_underlined(pp+1);make_reserved(pp+1);}

b_app1(pp);b_app(040);b_app1(pp+1);
indent_force;
b_app1(pp+2);
REDUCE(pp,3,struct_hd,0,101);
}
else /* ``|struct s ss|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,int_like,-1,102);
}
}
else if(cat1==colon&&cat2==int_like&&Cpp)
{/* |@c++ class A: base| */
if(cat3==langle)
SQUASH(pp,1,struct_like,PLUS 3,1023);
else
{
b_app1(pp);b_app(040);b_app1(pp+1);b_app(040);
b_app1(pp+2);
REDUCE(pp,3,struct_like,0,1021);
}
}
else if(cat1==comma&&cat2==int_like&&Cpp)
{/* |@c++ class A: base, base | */
if(cat3==langle)
SQUASH(pp,1,struct_like,PLUS 3,1024);
else
{
b_app2(pp);b_app(040);b_app1(pp+2);
REDUCE(pp,3,struct_like,0,1022);
}
}
else if(cat1==tlist)
SQUASH(pp,2,struct_like,0,1025);/* \Cpp: |@c++ class A<int>|. */
else if(cat1==semi)
SQUASH(pp,2,decl,-1,103);/* \Cpp: |@c++ class base;| */
else if(cat1==rangle)
SQUASH(pp,1,decl_hd,-2,592);/* \Cpp:  end of template. */
}


#endif

break;
case struct_hd:
#if FCN_CALLS
C_str_hd();
#else

{
if((cat1==decl||cat1==stmt
||cat1==expr /*  (For enum) */
||cat1==functn /* \Cpp */
)&&cat2==rbrace)
{
b_app1(pp);/* ``|struct {|'' */
b_app(force);b_app1(pp+1);/* Body */
b_app(force);b_app1(pp+2);/* ``|}|'' */
b_app(outdent);
REDUCE(pp,3,int_like,-1,110);
}
else if(cat1==rbrace)
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,int_like,-1,1101);
}
}


#endif

break;
case fn_decl:
#if FCN_CALLS
C_fn_decl();
#else

{
if(cat1==semi&&Cpp)
{/* |@c++ using namespace X;| */
b_app2(pp);
REDUCE(pp,2,stmt,-1,72);
}
else if(cat1==decl)/* ``|f(x) float x;|'' */
{
b_app1(pp);
b_app(indent);indent_force;
b_app1(pp+1);/* Accrete old-style declarations. */
b_app(outdent);b_app(outdent);
REDUCE(pp,2,fn_decl,0,70);
}
else if(cat1==stmt)/* ``|f(){}|'' */
{
#if(0)
b_app(backup);/* Beginning of function. */
#endif
b_app1(pp);b_app(force);
b_app(indent);
b_app1(pp+1);/* Function body */
b_app(outdent);
in_function= NO;
REDUCE(pp,2,functn,-1,71);
}
}


#endif

break;
case functn:
#if FCN_CALLS
C_functn();
#else

{
if(cat1==functn||cat1==decl||cat1==stmt)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,-1,80);/* |-1| for \Cpp */
}
}


#endif

break;
case lbrace:
#if FCN_CALLS
C_lbrace();
#else

{
if(cat1==rbrace)/* ``|{}|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
REDUCE(pp,2,stmt,-1,130);
}
else if((cat1==stmt||cat1==decl||cat1==functn)&&cat2==rbrace)
/* ``|{x;}|''  or \dots\ or \Cpp:  |@c++ main(){try{}catch(){}}| */
{
b_app(force);
b_app1(pp);/* ``|{|'' */
b_app(force);
b_app1(pp+1);/* Body */
b_app(force);
b_app1(pp+2);/* ``|}|'' */
REDUCE(pp,3,stmt,-1,131);
}
else if(cat1==expr)
{
if(cat2==rbrace)
SQUASH(pp,3,expr,-2,132);/* ``|enum{red}|'' */
else if(cat2==comma&&cat3==rbrace)
SQUASH(pp,4,expr,-2,132);
}
}


#endif

break;
case do_like:
#if FCN_CALLS
C_do_like();
#else

{
if(cat1==stmt)
if(cat2==for_like)
{
cat2= while_do;
SQUASH(pp,1,do_like,PLUS 2,191);
}
else if(cat2==expr&&cat3==semi)
{/* ``|do {} while(flag);|'' */
b_app1(pp);/* ``\&{do}'' */
indent_force;
b_app1(pp+1);/* stmt */
b_app(outdent);
b_app(force);
b_app2(pp+2);/* ``\&{while}\dots'' */
REDUCE(pp,4,stmt,-1,190);
}
}


#endif

break;
case while_do:
#if FCN_CALLS
C_wh_do();
#else

{
b_app1(pp);

{
b_app(0134);b_app(054);
}

;
REDUCE(pp,1,expr,0,192);
}


#endif

break;
case if_like:
#if FCN_CALLS
C_if_like();
#else

{
if(cat1==lpar&&cat2==expr&&cat3==rpar)/* ``|if(x)|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app3(pp+1);
#if(0)
cmnt_after_IF= (cat4==ignore_scrap);/* Comment coming up? */
#endif
REDUCE(pp,4,IF_like,0,220);
}
}


#endif

break;
case IF_like:
#if FCN_CALLS
C_IF();
#else

{
if(cat1==stmt
||cat1==lbrace||cat1==if_like||cat1==for_like||cat1==do_like
||cat1==Rdo_like
#if(0)
||cmnt_after_IF
#endif
)
SQUASH(pp,1,if_hd,0,230);/* |if_hd| does the indenting. */
#if(0)
else if(cat1==stmt)
{/* Attach simple statement. */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,IF_top,-1,231);
}
#endif
}


#endif

break;
case IF_top:
#if FCN_CALLS
C_IF_top();
#else

{
if(cat1==else_like||cat1==else_hd)
SQUASH(pp,1,IF_top,1,242);/* Expand ahead. */
else if(cat1==IF_top)
{
b_app1(pp);/* \&{if}\dots */
b_app(force);
b_app1(pp+1);/* \&{else if}\dots */
REDUCE(pp,2,IF_top,-1,238);
}
else if(cat1==ELSE_like)
{
b_app1(pp);/* \&{if} */
b_app(force);
b_app1(pp+1);/* \&{else} */
REDUCE(pp,2,stmt,-1,239);
}
else if(cat1==IF_like&&(cat2==expr||cat2==stmt))
SQUASH(pp,1,IF_top,1,241);
else
SQUASH(pp,1,stmt,-1,240);
}


#endif

break;
case for_like:
#if FCN_CALLS
C_for_like();
#else

{
if(cat1==expr)
{/* ``\&{for}\dots'' */
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
b_app(040);

if(cat2==semi)
{/* ``|for(;;);|'' */
if(!auto_semi||(auto_semi&&cat3==semi))
{
indent_force;
b_app1(pp+2);/* Semi on separate line. */
b_app(outdent);
REDUCE(pp,3,stmt,-2,200);/*  The $-2$ is for the \
\&{do} case. Also get here from Ratfor's \&{until}. */
}
else
REDUCE(pp,3,for_hd,0,2011);/* Eat the |auto_semi|. */
}
else
REDUCE(pp,2,for_hd,0,201);/* Eat the arguments. */
}
else if(cat1!=lpar)
SQUASH(pp,1,expr,0,2010);/* Default possiblity. */
}


#endif

break;
case for_hd:
#if FCN_CALLS
C_forhd();
#else

{
if(cat1==stmt)
{/* ``|for(;;) x;|'' */
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,stmt,-1,210);
}
}


#endif

break;
case else_like:
#if FCN_CALLS
C_else();
#else

{
if(cat1==if_like)/* ``|else if|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,if_like,0,235);
}
else if(cat1==stmt||cat1==lbrace||cat1==for_like||cat1==do_like)
SQUASH(pp,1,else_hd,0,236);/* ``|else {}|'' */
#if 0 /* The following puts simple statement on same line. */
else if(cat1==stmt)/* ``|else z;|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,ELSE_like,-1,237);
}
#endif
}


#endif

break;
case if_hd:
#if FCN_CALLS
C_if_hd();
#else

{
if(cat1==stmt)/* ``|if(x) {}|'' */
{
b_app1(pp);/* ``|if(x)|'' */
indent_force;
b_app1(pp+1);/* ``|{}|'' */
b_app(outdent);
REDUCE(pp,2,IF_top,-1,233);
}
else if(cat1==IF_top&&cat2==else_like)
SQUASH(pp,1,if_hd,2,234);
}


#endif

break;
case else_hd:
#if FCN_CALLS
C_els_hd();
#else

{
if(cat1==stmt)/* ``|if(x) {}|'' */
{
b_app1(pp);/* ``|if(x)|'' */
indent_force;
b_app1(pp+1);/* ``|{}|'' */
b_app(outdent);
REDUCE(pp,2,ELSE_like,-1,241);
}
}


#endif

break;
case case_like:
#if FCN_CALLS
C_case_like();
#else

{
if(cat1==semi)
SQUASH(pp,2,stmt,-1,260);/* |return;| */
else if(cat1==colon)
SQUASH(pp,2,tag,-1,261);/* |default:| or \Cpp: |@c++ public:| */
else if(cat1==expr)
{
if(cat2==semi)/* |return x;| */
{
b_app1(pp);b_app(040);b_app2(pp+1);
REDUCE(pp,3,stmt,-1,262);
}
else if(cat2==colon)/* |case one:| */
{
b_app1(pp);b_app(040);b_app2(pp+1);
REDUCE(pp,3,tag,-1,263);
}
}
else if(cat1==int_like)
{/* \Cpp: |@c++ public base| */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,int_like,-2,264);
}
}


#endif

break;
case stmt:
#if FCN_CALLS
C_stmt();
#else

{
if(cat1==stmt||(Cpp&&cat1==decl))/* ``|x; y;|'' */
{
b_app1(pp);b_app(force);
b_app1(pp+1);REDUCE(pp,2,stmt,-1,250);
}
else if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-1,251);
}
}


#endif

break;
case tag:
#if FCN_CALLS
C_tag();
#else

{
if(cat1==tag)/* ``|case one: case two:|'' */
{
b_app1(pp);
b_app(force);
b_app(backup);
b_app1(pp+1);REDUCE(pp,2,tag,-1,270);
}
else if(cat1==stmt||cat1==decl||cat1==functn)/* ``|case one: \
		break;|'' or \Cpp: ``|@c++ public: int constructor();|''  */
{
b_app(big_force);
b_app(backup);b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,cat1,-1,271);
}
}


#endif

break;
case semi:
#if FCN_CALLS
C_semi();
#else

{
b_app(040);b_app1(pp);
REDUCE(pp,1,stmt,-1,280);
}


#endif

break;
case lproc:
#if FCN_CALLS
C_lproc();
#else

{
expanded_lproc= YES;

if(!in_LPROC)
active_space= YES;

if(cat1==define_like)
make_underlined(pp+3);/* ``\.{\#\ define\ M}'' */

if(cat1==else_like||cat1==if_like||cat1==define_like)
SQUASH(pp,2,lproc,0,10);/* ``\.{\#\ define}'' $\to$ \
``\.{\#define}'' */
else if(cat1==rproc)
{
expanded_lproc= active_space= in_LPROC= NO;
SQUASH(pp,2,ignore_scrap,-1,11);
}
else if(cat1==expr)
SQUASH(pp,1,LPROC,0,12);/* ``|#if(0)|'' */
else if(cat1==space)
{
if(cat2==lpar)
SQUASH(pp,1,lproc,PLUS 2,1332);/* \.{if\ (x)} */
/* Following stuff for \&{\#define}. \
Absorb the identifier: ``\&{\#define M}'' */
else if(cat3==lpar)
SQUASH(pp,1,lproc,PLUS 3,1333);/* Expand the parens. */
else if(cat3==expr)
SQUASH(pp,4,LPROC,0,13);/* |expr| should be \
			``|()|''; get them too. */
else if(cat3==space||cat3==ignore_scrap||cat3==rproc)
SQUASH(pp,3,LPROC,0,14);/* Just the identifier. */
}
expanded_lproc= NO;
}


#endif

break;
case LPROC:
#if FCN_CALLS
C_LPRC();
#else

{
active_space= NO;in_LPROC= YES;

if(cat1==space)
{
b_app1(pp);
b_app(040);
REDUCE(pp,2,LPROC,0,20);
}
else if(cat1==rproc)
{
in_LPROC= NO;
SQUASH(pp,2,ignore_scrap,-1,21);
}
else if(cat2==rproc)
{
in_LPROC= NO;
SQUASH(pp,3,ignore_scrap,-1,22);
}

#if(0)
if(cat3==lpar&&cat4==expr&&cat5==rpar)
if(cat2==rproc)
{
b_app1(pp);b_app(040);b_app2(pp+1);
REDUCE(pp,3,ignore_scrap,-1,53);
}
else if(cat2==expr&&cat3==rproc)
{
b_app1(pp);b_app(040);b_app1(pp+1);b_app(040);
b_app2(pp+2);REDUCE(pp,4,ignore_scrap,-1,53);
}
#endif
}


#endif

break;
case space:
#if FCN_CALLS
C_space();
#else

{
if(active_space)
{
if(expanded_lproc)
SQUASH(pp,1,space,-1,5336);
else
SQUASH(pp,1,space,1,5335);
}
else
REDUCE(pp,1,ignore_scrap,-1,5334);
}


#endif

break;

case template:
#if FCN_CALLS
C_template();
#else

{
if(cat1==langle)
SQUASH(pp,1,template,PLUS 1,6000);
else if(cat1==tlist)
{
b_app1(pp);b_app(040);b_app1(pp+1);b_app(force);
REDUCE(pp,2,int_like,0,6001);
}
}


#endif

break;
case langle:
#if FCN_CALLS
C_langle();
#else

{
if((pp-1)->cat==template||(pp-1)->cat==int_like||(pp-1)->cat==
struct_like)
{
b_app(0134);
APP_STR("WLA ");/* \.{\\WLA} $\equiv$ `$\WLA$'. */
REDUCE(pp,1,tstart,0,6050);/* Begining of template parameter list. */
}
else
SQUASH(pp,1,binop,-1,6051);
}


#endif

break;
case rangle:
#if FCN_CALLS
C_rangle();
#else

{
SQUASH(pp,1,binop,-1,6052);
}


#endif

break;
case tstart:
#if FCN_CALLS
C_tstart();
#else

{
if(cat2==rangle&&(cat1==int_like||cat1==decl_hd||cat1==expr
||cat1==unorbinop))
{
b_app2(pp);
b_app(0134);
APP_STR("WRA ");/* Closing of template. */
OUTDENT;
REDUCE(pp,3,tlist,-1,6060);
}
}


#endif

break;
case tlist:
#if FCN_CALLS
C_tlist();
#else



#endif

break;

case virtual:
#if FCN_CALLS
C_virtual();
#else

{
b_app1(pp);

if(cat1==unop)
APP_SPACE;/* |@c++ virtual ~base();| */

REDUCE(pp,1,int_like,0,506);
}


#endif

break;
case reference:
#if FCN_CALLS
C_reference();
#else

{
SQUASH(pp,1,unorbinop,-1,507);
}


#endif

break;
case namespace:
#if FCN_CALLS
C_namespace();
#else

{
if(cat1==expr||cat1==int_like)
{/* \Cpp: |@c++ namespace A| */
make_underlined(pp+1);make_reserved(pp+1);

b_app1(pp);b_app(040);b_app1(pp+1);

REDUCE(pp,2,fn_decl,0,7901);
}
else if(cat1==lbrace)
SQUASH(pp,1,fn_decl,0,7902);/* |@c++ namespace{}| */
}


#endif

break;
}
}



SRTN
make_reserved FCN((p))/* Make the first identifier in |p->trans| like \
				|int| */
scrap_pointer p C1("")
{
sixteen_bits tok_value= first_id(p->trans);
/* The first identifier, plus its flag. */
name_pointer pname= name_dir+tok_value-id_flag;

if(!tok_value||tok_value==050)
return;/* Emergency return; no	identifier found. */

if(DEFINED_TYPE(pname)==M_MACRO||DEFINED_TYPE(pname)==D_MACRO)
return;/* Don't |typedef| macro names. */

/* Change categories of all future occurrences of the identifier. */
for(;p<=scrp_ptr;p++)
{
if(p->cat==expr)
{
if(**(p->trans)==tok_value)
{
p->cat= int_like;
**(p->trans)+= res_flag-id_flag;/* Mark as reserved. */
}
}
}

pname->ilk= int_like;
pname->reserved_word|= (boolean)language;

if(mark_defined.typedef_name)
{
pname->defined_in(language)= module_count;
SET_TYPE(pname,TYPEDEF_NAME);
}
}



sixteen_bits
first_id FCN((t))
text_pointer t C1("Pointer to start of token list")
{
token_pointer pk= *t;/* Start of end. */
token_pointer pk1= *(t+1);/* End of list. */
sixteen_bits tok_value;/* Current element. */

for(;pk<pk1;pk++)
{
tok_value= *pk;

if(tok_value>inner_tok_flag)tok_value-= (inner_tok_flag-
tok_flag);

if(tok_value<=tok_flag)
{/* It's an ordinary (non-flagged) token. */
if(tok_value>=id_flag&&tok_value<res_flag)
return tok_value;/* Found identifier. */
else if(tok_value==050)return tok_value;/* STOP!!! */
}
else
{/* Flagged token; use indirection. */
t= tok_start+(int)(tok_value-tok_flag);/* Flagged token \
corresponds to a |text_pointer|; |*t|~points to beginning of translation. */
tok_value= first_id(t);/* Check that translation recursively. */
if(tok_value)return tok_value;
}
}

return 0;/* Really couldn't find anything! */
}



name_pointer
make_underlined FCN((p))/* underline the entry for the first \
				identifier in |p->trans| */
scrap_pointer p C1("")
{
sixteen_bits tok_value;/* the name of this identifier, plus its flag */

tok_value= **(p->trans);

if(tok_value>inner_tok_flag)tok_value-= (inner_tok_flag-tok_flag);

if(tok_value>tok_flag){
do
{/* Follow an indirection chain to a real identifier. {\bf \
Watch the 16-bit arithmetic!} */
tok_value= **(tok_start+
(int)(tok_value-tok_flag));/* {\bf Don't \
remove the parens!} */
}
while(tok_value>tok_flag);

if(tok_value<id_flag||tok_value>=res_flag)return NULL;/* shouldn't \
happen */

xref_switch= def_flag;underline_xref(tok_value-id_flag+name_dir);
}

if(tok_value<id_flag||tok_value>=res_flag)return NULL;
/* shouldn't happen! */

xref_switch= def_flag;return underline_xref(tok_value-id_flag+name_dir);
}



name_pointer
underline_xref FCN((p))
name_pointer p C1("")
{
xref_pointer q= (xref_pointer)p->xref;/* Pointer to cross-reference \
being examined */
xref_pointer r;/* Temporary pointer for permuting cross-references */
sixteen_bits m;/* Cross-reference value to be installed */
sixteen_bits n;/* Cross-reference value being examined */
extern boolean strt_off;

if(no_xref||(strt_off&&!index_hidden))
return p;

xref_switch= def_flag;
m= (sixteen_bits)(module_count+xref_switch);

while(q!=xmem)
{
n= q->num;

if(n==m)return p;/* Same status; need to do nothing. */
else if(m==n+def_flag)/* Module numbers match; update to \
				defined. */
{
q->num= m;return p;
}
else if(n>=def_flag&&n<m)break;

q= q->xlink;
}



append_xref(0);/* This number doesn't matter */
xref_ptr->xlink= (xref_pointer)p->xref;
r= xref_ptr;p->xref= (ASCII*)xref_ptr;

while(r->xlink!=q){r->num= r->xlink->num;r= r->xlink;}

r->num= m;/* Everything from |q| on is left undisturbed */

;

return p;
}



SRTN
defined_at FCN((p))
name_pointer p C1("")
{
extern boolean ok_to_define;

if(ok_to_define&&translate_mode==OUTER&&p>name_dir)
{
sixteen_bits mod_defined= p->defined_in(language);

if(mod_defined&&mod_defined!=module_count)
{
printf("\n! (FWEAVE):  Implicit phase 2 declaration of `");
prn_id(p);
printf("' at %s \
repeats or conflicts with previous declaration at %s.\n",
(char*)MOD_TRANS(module_count),
(char*)MOD_TRANS(mod_defined));
mfree();
mark_harmless;
}
else if(mark_defined.fcn_name)
{
p->defined_in(language)= module_count;
SET_TYPE(p,FUNCTION_NAME);
}
}
}



#if FCN_CALLS
SRTN C_ignore_scrap(VOID)
{

{
switch(cat1)
{
case stmt:
case functn:
SQUASH(pp,2,cat1,0,1);
break;
}
}


}
#endif


#if FCN_CALLS
SRTN C_expr(VOID)
{

{
if(cat1==lbrace||((!Cpp)&&cat1==int_like))
{/* ``|f(x) {}|'' or ``|f(x) float x;|'' (old-style) */
defined_at(make_underlined(pp));/* Recognized function name; \
remember current module number. */
in_function= YES;
SQUASH(pp,1,fn_decl,0,111);
}
else if(cat1==unop)
SQUASH(pp,2,expr,-2,2);/* ``|x--|'' */
else if(cat1==binop)
{
if(cat2==expr)
SQUASH(pp,3,expr,-2,3);/* ``|x + y|'' */
else if(cat2==decl_hd)
SQUASH(pp,3,tstart,0,6061);
/* Trap for ``|@c++ A<int>|'', with |A| undefined. */
}
else if(cat1==unorbinop&&cat2==expr)
{
sixteen_bits*s= *(pp+1)->trans;
b_app1(pp);

/* If the translation of the next scrap begins with an escape character, we \
assume we're seeing \.{\\amp}. */
if((s[0]==(sixteen_bits)0134)&&s[1]==(sixteen_bits)0141
&&s[2]==(sixteen_bits)0155)
{
APP_SPACE;b_app1(pp+1);APP_SPACE;/* ``|x & y|'' */
}
else b_app1(pp+1);/* ``|x*y|'' */

b_app1(pp+2);
REDUCE(pp,3,expr,-2,3000);
}
else if(cat1==comma)
{
if((cat2==expr||cat2==int_like))/* ``|x,y|'' or ``|x,char|''  */
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,cat2,-2,4);
}
else if(cat2==space)
SQUASH(pp,3,expr,-2,88);/* Macros. */
}
else if(cat1==expr)
SQUASH(pp,2,expr,-2,5);/* ``|f(x)|'' */
else if(cat1==semi)
SQUASH(pp,2,stmt,-1,6);/* ``|x;|'' */
else if(cat1==colon)/* ``|label:|'' */
{
if(!Cpp||in_function)
{/* Ordinary C tag. */
make_underlined(pp);/* Label name. */
SQUASH(pp,2,tag,0,7);
}
else if(cat2==expr)
{/* Put the spaces in explicitly in case we're not in math \
mode at the time. */
b_app1(pp);b_app(040);b_app1(pp+1);b_app(040);
b_app1(pp+2);
REDUCE(pp,3,expr,-2,701);
/* \Cpp: ``|@c++ derived() : base()|'' */
}
}
else if(cat1==space)
SQUASH(pp,2,expr,-2,8);/* For use in macros. */
}


}
#endif


#if FCN_CALLS
SRTN C_UNOP(VOID)
{

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,unop,-1,4443);
}


}
#endif


#if FCN_CALLS
SRTN C_BINOP(VOID)
{

{


APP_SPACE;b_app1(pp);APP_SPACE;

;
REDUCE(pp,1,binop,-1,4444);
}


}
#endif


#if FCN_CALLS
SRTN C_COMMA(VOID)
{

{


APP_SPACE;b_app1(pp);APP_SPACE;

;
REDUCE(pp,1,comma,-1,4445);
}


}
#endif


#if FCN_CALLS
SRTN C__E(VOID)
{

{
APP_SPACE;b_app1(pp);
REDUCE(pp,1,expr,-2,4446);
}


}
#endif


#if FCN_CALLS
SRTN C__E_(VOID)
{

{


APP_SPACE;b_app1(pp);APP_SPACE;

;
REDUCE(pp,1,expr,-2,4447);
}


}
#endif


#if FCN_CALLS
SRTN C_E_(VOID)
{

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,expr,-2,4448);
}


}
#endif


#if FCN_CALLS
SRTN C_new_like(VOID)
{

{
if(cat1==decl_hd||cat1==expr)
{/* \Cpp: |@c++ new int| or |@c++ new class(20)| */
b_app1(pp);b_app(040);b_app1(pp+1);
if(cat1==decl_hd)
{
OUTDENT;
}
REDUCE(pp,2,expr,-2,909);
}
}


}
#endif


#if FCN_CALLS
SRTN C_lproc(VOID)
{

{
expanded_lproc= YES;

if(!in_LPROC)
active_space= YES;

if(cat1==define_like)
make_underlined(pp+3);/* ``\.{\#\ define\ M}'' */

if(cat1==else_like||cat1==if_like||cat1==define_like)
SQUASH(pp,2,lproc,0,10);/* ``\.{\#\ define}'' $\to$ \
``\.{\#define}'' */
else if(cat1==rproc)
{
expanded_lproc= active_space= in_LPROC= NO;
SQUASH(pp,2,ignore_scrap,-1,11);
}
else if(cat1==expr)
SQUASH(pp,1,LPROC,0,12);/* ``|#if(0)|'' */
else if(cat1==space)
{
if(cat2==lpar)
SQUASH(pp,1,lproc,PLUS 2,1332);/* \.{if\ (x)} */
/* Following stuff for \&{\#define}. \
Absorb the identifier: ``\&{\#define M}'' */
else if(cat3==lpar)
SQUASH(pp,1,lproc,PLUS 3,1333);/* Expand the parens. */
else if(cat3==expr)
SQUASH(pp,4,LPROC,0,13);/* |expr| should be \
			``|()|''; get them too. */
else if(cat3==space||cat3==ignore_scrap||cat3==rproc)
SQUASH(pp,3,LPROC,0,14);/* Just the identifier. */
}
expanded_lproc= NO;
}


}
#endif


#if FCN_CALLS
SRTN C_LPRC(VOID)
{

{
active_space= NO;in_LPROC= YES;

if(cat1==space)
{
b_app1(pp);
b_app(040);
REDUCE(pp,2,LPROC,0,20);
}
else if(cat1==rproc)
{
in_LPROC= NO;
SQUASH(pp,2,ignore_scrap,-1,21);
}
else if(cat2==rproc)
{
in_LPROC= NO;
SQUASH(pp,3,ignore_scrap,-1,22);
}

#if(0)
if(cat3==lpar&&cat4==expr&&cat5==rpar)
if(cat2==rproc)
{
b_app1(pp);b_app(040);b_app2(pp+1);
REDUCE(pp,3,ignore_scrap,-1,53);
}
else if(cat2==expr&&cat3==rproc)
{
b_app1(pp);b_app(040);b_app1(pp+1);b_app(040);
b_app2(pp+2);REDUCE(pp,4,ignore_scrap,-1,53);
}
#endif
}


}
#endif


#if FCN_CALLS
SRTN C_space(VOID)
{

{
if(active_space)
{
if(expanded_lproc)
SQUASH(pp,1,space,-1,5336);
else
SQUASH(pp,1,space,1,5335);
}
else
REDUCE(pp,1,ignore_scrap,-1,5334);
}


}
#endif


#if FCN_CALLS
SRTN C_question(VOID)
{

{
if(cat1==expr&&cat2==colon)SQUASH(pp,3,binop,-2,30);/* ``|i==1 ? YES : \
					NO|'' */
}


}
#endif


#if FCN_CALLS
SRTN C_int_like(VOID)
{

{
if(cat1==unop)
{
if(cat2==expr||cat2==int_like)
SQUASH(pp,3,expr,-2,35);/* \Cpp: |@c++ class::f| or \
			constructor: |@c++ class::class| */
else if(cat2==op_like)
SQUASH(pp,1,int_like,PLUS 2,36);/* \Cpp: Expand |@c++ operator| \
			construction. */
}
else if(cat1==int_like||cat1==struct_like)
{/* ``|extern int|'' or ``|@c++ typedef int bool|''. */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,cat1,0,40);
}
else if(cat1==reference)
SQUASH(pp,2,int_like,-2,43);/* |@c++ int &ref;| */
else if(cat1==expr||cat1==unorbinop||cat1==semi)
{/* ``|int i|'' or ``|int *|'' */
b_app1(pp);

if(cat1!=semi)
b_app(040);

INDENT;/* Start long declaration. (Note: Whenever we leave \
			|decl_hd|, we must |OUTDENT|.) */

REDUCE(pp,1,decl_hd,-1,41);
}
else if(cat1==comma)
{
b_app1(pp);
INDENT;
REDUCE(pp,1,decl_hd,-2,42);/* Function prototype: |int,|. */
}
else if(cat1==rpar)
{
b_app1(pp);
INDENT;
REDUCE(pp,1,decl_hd,-2,502);
}
else if(Cpp&&cat1==lpar&&!in_prototype)
{/* The \Cpp\ is a KLUDGE. Consider ``|int (*f)()|''. */
b_app1(pp);

{
b_app(0134);b_app(054);
}


REDUCE(pp,1,expr,-2,5021);/* \Cpp\ constructor: ``|@c++ base()|''; \
					or ``|@c++ int(x)|''. */
}
else if(cat1==binop&&cat2==expr)
SQUASH(pp,3,int_like,-2,5022);/* \Cpp\ initializer: |@c++ base = 0| */
else if(cat1==langle)
SQUASH(pp,1,int_like,PLUS 1,5997);/* |@c++ int<24>| */
else if(cat1==rangle)
{
b_app1(pp);
INDENT;
REDUCE(pp,1,decl_hd,-2,5998);
}
else if(cat1==class_like)
{/* \Cpp:  |@c++ friend class|. */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,class_like,0,5995);
}
else if(cat1==tlist)
SQUASH(pp,2,int_like,-2,5999);
else if(cat1==namespace)
{/* |@c++ using namespace| */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,namespace,0,5996);
}
}


}
#endif


#if FCN_CALLS
SRTN C_ext_like(VOID)
{

{
if(Cpp&&cat1==expr)
{/* |@c++ extern "C"| */
b_app1(pp);b_app(040);b_app1(pp+1);
if(cat2==lbrace)
REDUCE(pp,2,fn_decl,0,5025);/* ``|@c++ extern "C" {}|''. */
else
REDUCE(pp,2,int_like,0,5023);
/* ``|@c++ extern "C" int fcn();|'' */
}
else
SQUASH(pp,1,int_like,0,5024);
}


}
#endif


#if FCN_CALLS
SRTN C_modifier(VOID)
{

{
if(cat1==int_like)
SQUASH(pp,1,int_like,-2,503);
else if(pp==lo_ptr)
SQUASH(pp,1,expr,0,5040);
else if(cat1==semi||cat1==lbrace)
SQUASH(pp,1,_EXPR,0,5042);
/* |@c++ int f() const;| or |@c++ int f() const {}|. */
else
SQUASH(pp,1,EXPR_,0,5041);
}


}
#endif


#if FCN_CALLS
SRTN C_huge_like(VOID)
{

{
if(cat1==unorbinop)
{
b_app1(pp);APP_SPACE;b_app1(pp+1);
REDUCE(pp,2,unorbinop,-1,505);
}
}


}
#endif


#if FCN_CALLS
SRTN C_virtual(VOID)
{

{
b_app1(pp);

if(cat1==unop)
APP_SPACE;/* |@c++ virtual ~base();| */

REDUCE(pp,1,int_like,0,506);
}


}
#endif


#if FCN_CALLS
SRTN C_reference(VOID)
{

{
SQUASH(pp,1,unorbinop,-1,507);
}


}
#endif


#if FCN_CALLS
SRTN C_decl_hd(VOID)
{

{
if(cat1==rpar)
{
if((pp-1)->cat==lpar)
SQUASH(pp,1,decl_hd,-1,4990);/* ``|(int i)|''. */
else if((pp-2)->cat==decl_hd)
SQUASH(pp,1,decl_hd,-2,4991);/* ``|(int i, int j)|''. */
else if((pp-3)->cat==decl_hd)
SQUASH(pp,1,decl_hd,-3,4992);
}
else if(cat1==decl_hd)
SQUASH(pp,2,decl_hd,0,50);/* ``|(int,int)|'' */
else if(cat1==comma)
{
if(cat2==decl_hd)
{/* For function prototype. */
b_app2(pp);OPT9;
b_app1(pp+2);
REDUCE(pp,3,decl_hd,0,501);
}
else if(cat2==ignore_scrap&&cat3==decl_hd)
{/* For function prototype with comment. */
b_app2(pp);OPT9;
b_app2(pp+2);
REDUCE(pp,4,decl_hd,0,504);
}
#if 0
else if(Cpp&&(cat2==decl||cat2==stmt))
SQUASH(pp,3,stmt,-2,508);
/* ``|@c++ for(int i=0, int j=0;;)|'' or ``|@c++ \
				for(int i=0, int j=0, int k=0;;)|''. */
#endif
else
{/* ``|int i,|'' */
if(cat2==ignore_scrap&&(cat3==int_like||cat3==struct_like||
cat3==modifier))
{/* Function prototype, with intervening comment. */
b_app1(pp);
if((pp-3)->cat!=decl_hd&&(pp-2)->cat!=decl_hd
&&cat3!=modifier)
in_prototype++;
REDUCE(pp,1,decl_hd,PLUS 3,5221);
}
else if(cat2==int_like||cat2==struct_like||cat2==modifier)
{/* Function prototype. */
b_app1(pp);
if((pp-3)->cat!=decl_hd&&(pp-2)->cat!=decl_hd
&&cat2!=modifier)
in_prototype++;/* The |modifier| clause is to \
prevent a situation like |(int, const int)| from thinking it's two levels \
of prototypes. */
REDUCE(pp,1,decl_hd,PLUS 2,52);
}
else
{/* Expecting list of something. */
b_app2(pp);b_app(040);

#if 0
if(Cpp)
REDUCE(pp,2,decl_hd,-2,540);
/* ``|@c++ int i=0, int j=0|'' (e.g., in |for|) */
else
#endif
REDUCE(pp,2,decl_hd,-1,54);/* ``|int i,j|'' */
}
}
}
else if(cat1==unorbinop)/* ``|int **p|'' */
{
b_app1(pp);
b_app1(pp+1);
REDUCE(pp,2,decl_hd,-1,55);
}
else if(cat1==expr)/* ``|int i|'' or ``|int i, j|'' */
{
make_underlined(pp+1);
SQUASH(pp,2,decl_hd,-1,56);/* The |-1| is to pick up a left \
					paren for function prototype. */
}
else if((cat1==binop||cat1==colon
||cat1==expr /* (for initializations) */
)&&cat2==expr&&(cat3==comma||cat3==semi||cat3==rpar))
#if 0
if(cat1==binop)
{
b_app1(pp);b_app(040);b_app2(pp+1);
REDUCE(pp,3,decl_hd,-1,5660);
}
else
#endif
SQUASH(pp,3,decl_hd,-1,5661);
else if(cat1==int_like&&(cat2==unop||cat2==langle))
SQUASH(pp,1,decl_hd,PLUS 1,5662);
/* \Cpp:  ``|@c++ void *int::fcn()|'' or ``|@c++ void \
		*int<int>::fcn()|'' */
else if(cat1==lbrace||(cat1==int_like&&
((pp-1)->trans==NULL||**(pp-1)->trans!=050)))/* \
Recognize beginning of function: ``|float f() {}|'' or ``|float f(x) float \
x|'' */
{
b_app1(pp);
OUTDENT;
in_function= YES;
defined_at(FIRST_ID(pp));
REDUCE(pp,1,fn_decl,0,58);
}
else if(cat1==semi)
{/* ``|int i;|'' */
b_app2(pp);
OUTDENT;/* Finish long declaration. */
#if 0
if(Cpp)
REDUCE(pp,2,decl,-2,594);
/* ``|@c++ for(int i=0, int j=0;;)|'' */
else
#endif
REDUCE(pp,2,decl,-1,59);
}
else if(Cpp&&cat1==int_like&&cat2==unop)
SQUASH(pp,1,decl_hd,PLUS 1,590);/* \Cpp: |@c++ void *class::f| */
else if(Cpp&&cat1==rangle)
SQUASH(pp,1,decl_hd,-2,591);/* \Cpp:  end of template. */
else if(Cpp&&cat1==struct_like)
SQUASH(pp,2,decl_hd,-1,593);
/* \Cpp: |@c++ template<class C1, class C2>|. */
}


}
#endif


#if FCN_CALLS
SRTN C_decl(VOID)
{

{
if(Cpp)
{
if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,functn,-1,61);
}
else
SQUASH(pp,1,stmt,-1,611);/* E.g., ``|@c++ for(int i=0;;)|'' */
}
else
{
if(cat1==decl)
{/* ``|int i; float x;|'' */
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,60);
}
else if(cat1==stmt||cat1==functn)
{/* ``|int i; x=0;|'' or ``|int i; f(){}|'' */
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,cat1,-1,61);
}
}
}


}
#endif


#if FCN_CALLS
SRTN C_fn_decl(VOID)
{

{
if(cat1==semi&&Cpp)
{/* |@c++ using namespace X;| */
b_app2(pp);
REDUCE(pp,2,stmt,-1,72);
}
else if(cat1==decl)/* ``|f(x) float x;|'' */
{
b_app1(pp);
b_app(indent);indent_force;
b_app1(pp+1);/* Accrete old-style declarations. */
b_app(outdent);b_app(outdent);
REDUCE(pp,2,fn_decl,0,70);
}
else if(cat1==stmt)/* ``|f(){}|'' */
{
#if(0)
b_app(backup);/* Beginning of function. */
#endif
b_app1(pp);b_app(force);
b_app(indent);
b_app1(pp+1);/* Function body */
b_app(outdent);
in_function= NO;
REDUCE(pp,2,functn,-1,71);
}
}


}
#endif


#if FCN_CALLS
SRTN C_functn(VOID)
{

{
if(cat1==functn||cat1==decl||cat1==stmt)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,-1,80);/* |-1| for \Cpp */
}
}


}
#endif


#if FCN_CALLS
SRTN C_typedef_like(VOID)
{

{
if(cat1==decl_hd&&(cat2==expr||cat2==int_like))
{
make_underlined(pp+2);make_reserved(pp+2);/* NEEDS TO BE IMPROVED! */
b_app2(pp+1);
REDUCE(pp+1,2,decl_hd,0,90);
}
else if(cat1==decl)
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,decl,-1,91);
}
else if(cat1==semi)
SQUASH(pp,2,stmt,-1,94);
/* ``|typedef|''. */
else if(cat1==stmt)
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,stmt,-1,95);
/* ``|typedef int I[3]|''. (|I| is defined in first pass.) */
}

}


}
#endif


#if FCN_CALLS
SRTN C_imp_reserved(VOID)
{

{
if(typedefing)SQUASH(pp,1,expr,-2,92);
else SQUASH(pp,1,int_like,-2,93);
}


}
#endif


#if FCN_CALLS
SRTN C_op_like(VOID)
{

{
short n;
/* The actual number of tokens that make up the effective function name. */

if((cat1==lpar&&cat2==rpar)||(cat1==lbracket&&cat2==rbracket))
{/* |@c++ operator ()()|  is a special case because it begins with \
left paren.  |@c++ operator []()| is handled as a special case because we \
now have the categories |lbracket| and |rbracket|, and |lbracket| doesn't \
regress when it's reduced to |lpar|. */
b_app1(pp);b_app(040);b_app1(pp+1);

{
b_app(0134);b_app(054);
}


b_app1(pp+2);
n= 3;
}
else
{/* We'll search for the obligatory left paren that indicates the \
argument list. */
scrap_pointer q;
int k;/* Counter. */

/* If the paren is missing, we could end up appending the entire rest of \
the code, so we limit the search. */
for(q= pp+1;q<=scrp_ptr&&q-pp<=MAX_OP_TOKENS;q++)
if(q->cat==lpar)break;

n= (q->cat==lpar)?PTR_DIFF(short,q,pp):0;

/* Append all the tokens between |operator| and left paren. */
if(n>0)
{
text_pointer xp;
token_pointer tp,tp1;

b_app1(pp);b_app(040);/* |operator| */
b_app(0173);/* Braces prevent possible spurious blanks \
before the left paren. */

id_first= id_loc= mod_text+1;

for(k= 1;k<n;k++)
{
b_app1(pp+k);

xp= indirect((pp+k)->trans);
tp= *xp;
tp1= *(xp+1);
while(tp<tp1)
*id_loc++= (ASCII)(*tp++);
}

underline_xref(id_lookup(id_first,id_loc,0));

b_app(0175);
}
}

if(n>0)
REDUCE(pp,n,expr,-2,6666);
}


}
#endif


#if FCN_CALLS
SRTN C_class_like(VOID)
{

{
if(cat1==expr||cat1==int_like)
{/* \Cpp: |@c++ class A| */
make_underlined(pp+1);make_reserved(pp+1);

b_app1(pp);b_app(040);b_app1(pp+1);

if((pp-1)->cat==tstart||(pp-1)->cat==decl_hd)
REDUCE(pp,2,decl_hd,-1,8998);
else
REDUCE(pp,2,struct_like,0,8999);
}
else if(cat1==lbrace)
SQUASH(pp,1,struct_like,0,8987);
/* |@c++ class{}| or |@c++ struct{}|. */
}


}
#endif


#if FCN_CALLS
SRTN C_struct_like(VOID)
{

{
if(cat1==lbrace)
{/* ``|struct {int i;} S;|'' or \Cpp: ``|@c++ class A{int i;};|'' */
b_app1(pp);indent_force;
b_app1(pp+1);REDUCE(pp,2,struct_hd,0,100);
}
else if(cat1==expr)
{/* Structure name: ``|struct s|'' */
if(cat2==lbrace)/* ``|struct s {}|'' */
{
/* In \Cpp, this construction defines a new type. */
if(Cpp)
{make_underlined(pp+1);make_reserved(pp+1);}

b_app1(pp);b_app(040);b_app1(pp+1);
indent_force;
b_app1(pp+2);
REDUCE(pp,3,struct_hd,0,101);
}
else /* ``|struct s ss|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,int_like,-1,102);
}
}
else if(cat1==colon&&cat2==int_like&&Cpp)
{/* |@c++ class A: base| */
if(cat3==langle)
SQUASH(pp,1,struct_like,PLUS 3,1023);
else
{
b_app1(pp);b_app(040);b_app1(pp+1);b_app(040);
b_app1(pp+2);
REDUCE(pp,3,struct_like,0,1021);
}
}
else if(cat1==comma&&cat2==int_like&&Cpp)
{/* |@c++ class A: base, base | */
if(cat3==langle)
SQUASH(pp,1,struct_like,PLUS 3,1024);
else
{
b_app2(pp);b_app(040);b_app1(pp+2);
REDUCE(pp,3,struct_like,0,1022);
}
}
else if(cat1==tlist)
SQUASH(pp,2,struct_like,0,1025);/* \Cpp: |@c++ class A<int>|. */
else if(cat1==semi)
SQUASH(pp,2,decl,-1,103);/* \Cpp: |@c++ class base;| */
else if(cat1==rangle)
SQUASH(pp,1,decl_hd,-2,592);/* \Cpp:  end of template. */
}


}
#endif


#if FCN_CALLS
SRTN C_str_hd(VOID)
{

{
if((cat1==decl||cat1==stmt
||cat1==expr /*  (For enum) */
||cat1==functn /* \Cpp */
)&&cat2==rbrace)
{
b_app1(pp);/* ``|struct {|'' */
b_app(force);b_app1(pp+1);/* Body */
b_app(force);b_app1(pp+2);/* ``|}|'' */
b_app(outdent);
REDUCE(pp,3,int_like,-1,110);
}
else if(cat1==rbrace)
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,int_like,-1,1101);
}
}


}
#endif


#if FCN_CALLS
SRTN C_lpar(VOID)
{

{
if(cat2==rpar&&(cat1==expr||cat1==unorbinop))
SQUASH(pp,3,expr,-2,120);/* ``|(x)|''  or ``|(*)|''*/
else if(cat1==rpar)
{/* ``|()|''. This looks better with a bit of extra space between \
		the parens. */
b_app1(pp);
{
b_app(0134);b_app(073);
}

;b_app1(pp+1);
REDUCE(pp,2,expr,-2,121);
}
else if((cat1==decl_hd)&&cat2==rpar)
{/* Function prototype or cast, like ``|typedef (*T)|'' where |T| \
		was |typedef|d on the first pass. */
b_app3(pp);

OUTDENT;

if(in_prototype)
in_prototype--;

REDUCE(pp,3,cast,-1,122);
}
else if(cat1==stmt)
{/* ``|for(x;y;z)|'' */
b_app2(pp);b_app(040);REDUCE(pp,2,lpar,0,123);
}
else if(cat1==for_like&&cat2==rpar)
SQUASH(pp,3,expr,-2,1201);/* Macros: |(for)| */
}


}
#endif


#if FCN_CALLS
SRTN C_lbracket(VOID)
{

{
if(active_brackets)
{
b_app(0134);
APP_STR("WXA{");
}
else b_app1(pp);

REDUCE(pp,1,lpar,0,5000);
}


}
#endif


#if FCN_CALLS
SRTN C_rbracket(VOID)
{

{
if(active_brackets)
{
text_pointer t= indirect(pp->trans);

if(**t==0135)**t= 0175;
}

b_app1(pp);

REDUCE(pp,1,rpar,-3,5001);
}


}
#endif


#if FCN_CALLS
SRTN C_lbrace(VOID)
{

{
if(cat1==rbrace)/* ``|{}|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
REDUCE(pp,2,stmt,-1,130);
}
else if((cat1==stmt||cat1==decl||cat1==functn)&&cat2==rbrace)
/* ``|{x;}|''  or \dots\ or \Cpp:  |@c++ main(){try{}catch(){}}| */
{
b_app(force);
b_app1(pp);/* ``|{|'' */
b_app(force);
b_app1(pp+1);/* Body */
b_app(force);
b_app1(pp+2);/* ``|}|'' */
REDUCE(pp,3,stmt,-1,131);
}
else if(cat1==expr)
{
if(cat2==rbrace)
SQUASH(pp,3,expr,-2,132);/* ``|enum{red}|'' */
else if(cat2==comma&&cat3==rbrace)
SQUASH(pp,4,expr,-2,132);
}
}


}
#endif


#if FCN_CALLS
SRTN C__unop(VOID)
{

{
if(cat1==expr)
SQUASH(pp,2,expr,-2,140);/* ``|!x|'' or ``|++x|'' */
else if(cat1==int_like)
SQUASH(pp,2,int_like,0,141);/* \Cpp\ destructor: \
			``|@c++ ~base|'' */
}


}
#endif


#if FCN_CALLS
SRTN C_unorbinop(VOID)
{

{
if(cat1==expr||(cat1==int_like&&!(cat2==lpar||cat2==unop)))
{/* ``|*p|'' or ``|&x|''; ``|typedef \
		(*T)|'' where |T| was |typedef|d on the first pass.  Not \
\Cpp:  ``|@c++ x + int(i)|'' or ``|@c++ x + base::y|''. */
b_app(0173);b_app1(pp);b_app(0175);
b_app1(pp+1);
REDUCE(pp,2,cat1,-2,150);
}
else if(cat1==binop)

{
b_app(math_bin);
b_app1(pp);
b_app(0173);b_app1(pp+1);b_app(0175);
b_app(0175);/* End |math_bin| */
REDUCE(pp,2,binop,-1,151);
}


}


}
#endif


#if FCN_CALLS
SRTN C_cast(VOID)
{

{
if(cat1==expr)/* ``|(int *)p|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
REDUCE(pp,2,expr,-2,160);
}
else if(cat1==unorbinop||cat1==reference)
SQUASH(pp,1,cast,PLUS 1,162);/* ``|(int *)&prms|''. */
else
SQUASH(pp,1,expr,-2,161);/* Turn function prototype into expression. */
}


}
#endif


#if FCN_CALLS
SRTN C_sizeof_like(VOID)
{

{
if(cat1==cast)
SQUASH(pp,2,expr,-2,170);/* ``|sizeof (int *)|'' */
else if(cat1==expr)
SQUASH(pp,2,expr,-2,171);/* ``|sizeof(x)|'' */
}


}
#endif


#if FCN_CALLS
SRTN C__binop(VOID)
{

{
if(cat1==binop)

{
b_app(math_bin);b_app1(pp);
b_app(0173);b_app1(pp+1);b_app(0175);
b_app(0175);/* End |math_bin| */
REDUCE(pp,2,binop,-1,180);
}

/* ``|+=|'' */
else if(cat1==space)
{
b_app1(pp);/* We eat the space in this macro situation. */
REDUCE(pp,2,binop,-1,181);/* |#if(a == b)|. */
}
else if(Cpp&&cat1==decl_hd)
SQUASH(pp,2,tstart,0,6063);
/* Trap for ``|@c++ A<int>|'', with |A| undefined.  See \
			also Rule 6061. */
}


}
#endif


#if FCN_CALLS
SRTN C_do_like(VOID)
{

{
if(cat1==stmt)
if(cat2==for_like)
{
cat2= while_do;
SQUASH(pp,1,do_like,PLUS 2,191);
}
else if(cat2==expr&&cat3==semi)
{/* ``|do {} while(flag);|'' */
b_app1(pp);/* ``\&{do}'' */
indent_force;
b_app1(pp+1);/* stmt */
b_app(outdent);
b_app(force);
b_app2(pp+2);/* ``\&{while}\dots'' */
REDUCE(pp,4,stmt,-1,190);
}
}


}
#endif


#if FCN_CALLS
SRTN C_wh_do(VOID)
{

{
b_app1(pp);

{
b_app(0134);b_app(054);
}

;
REDUCE(pp,1,expr,0,192);
}


}
#endif


#if FCN_CALLS
SRTN C_for_like(VOID)
{

{
if(cat1==expr)
{/* ``\&{for}\dots'' */
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
b_app(040);

if(cat2==semi)
{/* ``|for(;;);|'' */
if(!auto_semi||(auto_semi&&cat3==semi))
{
indent_force;
b_app1(pp+2);/* Semi on separate line. */
b_app(outdent);
REDUCE(pp,3,stmt,-2,200);/*  The $-2$ is for the \
\&{do} case. Also get here from Ratfor's \&{until}. */
}
else
REDUCE(pp,3,for_hd,0,2011);/* Eat the |auto_semi|. */
}
else
REDUCE(pp,2,for_hd,0,201);/* Eat the arguments. */
}
else if(cat1!=lpar)
SQUASH(pp,1,expr,0,2010);/* Default possiblity. */
}


}
#endif


#if FCN_CALLS
SRTN C_forhd(VOID)
{

{
if(cat1==stmt)
{/* ``|for(;;) x;|'' */
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,stmt,-1,210);
}
}


}
#endif


#if FCN_CALLS
SRTN C_if_like(VOID)
{

{
if(cat1==lpar&&cat2==expr&&cat3==rpar)/* ``|if(x)|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app3(pp+1);
#if(0)
cmnt_after_IF= (cat4==ignore_scrap);/* Comment coming up? */
#endif
REDUCE(pp,4,IF_like,0,220);
}
}


}
#endif


#if FCN_CALLS
SRTN C_IF(VOID)
{

{
if(cat1==stmt
||cat1==lbrace||cat1==if_like||cat1==for_like||cat1==do_like
||cat1==Rdo_like
#if(0)
||cmnt_after_IF
#endif
)
SQUASH(pp,1,if_hd,0,230);/* |if_hd| does the indenting. */
#if(0)
else if(cat1==stmt)
{/* Attach simple statement. */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,IF_top,-1,231);
}
#endif
}


}
#endif


#if FCN_CALLS
SRTN C_if_hd(VOID)
{

{
if(cat1==stmt)/* ``|if(x) {}|'' */
{
b_app1(pp);/* ``|if(x)|'' */
indent_force;
b_app1(pp+1);/* ``|{}|'' */
b_app(outdent);
REDUCE(pp,2,IF_top,-1,233);
}
else if(cat1==IF_top&&cat2==else_like)
SQUASH(pp,1,if_hd,2,234);
}


}
#endif


#if FCN_CALLS
SRTN C_els_hd(VOID)
{

{
if(cat1==stmt)/* ``|if(x) {}|'' */
{
b_app1(pp);/* ``|if(x)|'' */
indent_force;
b_app1(pp+1);/* ``|{}|'' */
b_app(outdent);
REDUCE(pp,2,ELSE_like,-1,241);
}
}


}
#endif


#if FCN_CALLS
SRTN C_else(VOID)
{

{
if(cat1==if_like)/* ``|else if|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,if_like,0,235);
}
else if(cat1==stmt||cat1==lbrace||cat1==for_like||cat1==do_like)
SQUASH(pp,1,else_hd,0,236);/* ``|else {}|'' */
#if 0 /* The following puts simple statement on same line. */
else if(cat1==stmt)/* ``|else z;|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,ELSE_like,-1,237);
}
#endif
}


}
#endif


#if FCN_CALLS
SRTN C_ELS(VOID)
{



}
#endif


#if FCN_CALLS
SRTN C_IF_top(VOID)
{

{
if(cat1==else_like||cat1==else_hd)
SQUASH(pp,1,IF_top,1,242);/* Expand ahead. */
else if(cat1==IF_top)
{
b_app1(pp);/* \&{if}\dots */
b_app(force);
b_app1(pp+1);/* \&{else if}\dots */
REDUCE(pp,2,IF_top,-1,238);
}
else if(cat1==ELSE_like)
{
b_app1(pp);/* \&{if} */
b_app(force);
b_app1(pp+1);/* \&{else} */
REDUCE(pp,2,stmt,-1,239);
}
else if(cat1==IF_like&&(cat2==expr||cat2==stmt))
SQUASH(pp,1,IF_top,1,241);
else
SQUASH(pp,1,stmt,-1,240);
}


}
#endif


#if FCN_CALLS
SRTN C_stmt(VOID)
{

{
if(cat1==stmt||(Cpp&&cat1==decl))/* ``|x; y;|'' */
{
b_app1(pp);b_app(force);
b_app1(pp+1);REDUCE(pp,2,stmt,-1,250);
}
else if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-1,251);
}
}


}
#endif


#if FCN_CALLS
SRTN C_case_like(VOID)
{

{
if(cat1==semi)
SQUASH(pp,2,stmt,-1,260);/* |return;| */
else if(cat1==colon)
SQUASH(pp,2,tag,-1,261);/* |default:| or \Cpp: |@c++ public:| */
else if(cat1==expr)
{
if(cat2==semi)/* |return x;| */
{
b_app1(pp);b_app(040);b_app2(pp+1);
REDUCE(pp,3,stmt,-1,262);
}
else if(cat2==colon)/* |case one:| */
{
b_app1(pp);b_app(040);b_app2(pp+1);
REDUCE(pp,3,tag,-1,263);
}
}
else if(cat1==int_like)
{/* \Cpp: |@c++ public base| */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,int_like,-2,264);
}
}


}
#endif


#if FCN_CALLS
SRTN C_tag(VOID)
{

{
if(cat1==tag)/* ``|case one: case two:|'' */
{
b_app1(pp);
b_app(force);
b_app(backup);
b_app1(pp+1);REDUCE(pp,2,tag,-1,270);
}
else if(cat1==stmt||cat1==decl||cat1==functn)/* ``|case one: \
		break;|'' or \Cpp: ``|@c++ public: int constructor();|''  */
{
b_app(big_force);
b_app(backup);b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,cat1,-1,271);
}
}


}
#endif


#if FCN_CALLS
SRTN C_semi(VOID)
{

{
b_app(040);b_app1(pp);
REDUCE(pp,1,stmt,-1,280);
}


}
#endif


#if FCN_CALLS
SRTN C_template(VOID)
{

{
if(cat1==langle)
SQUASH(pp,1,template,PLUS 1,6000);
else if(cat1==tlist)
{
b_app1(pp);b_app(040);b_app1(pp+1);b_app(force);
REDUCE(pp,2,int_like,0,6001);
}
}


}
#endif


#if FCN_CALLS
SRTN C_langle(VOID)
{

{
if((pp-1)->cat==template||(pp-1)->cat==int_like||(pp-1)->cat==
struct_like)
{
b_app(0134);
APP_STR("WLA ");/* \.{\\WLA} $\equiv$ `$\WLA$'. */
REDUCE(pp,1,tstart,0,6050);/* Begining of template parameter list. */
}
else
SQUASH(pp,1,binop,-1,6051);
}


}
#endif


#if FCN_CALLS
SRTN C_rangle(VOID)
{

{
SQUASH(pp,1,binop,-1,6052);
}


}
#endif


#if FCN_CALLS
SRTN C_tstart(VOID)
{

{
if(cat2==rangle&&(cat1==int_like||cat1==decl_hd||cat1==expr
||cat1==unorbinop))
{
b_app2(pp);
b_app(0134);
APP_STR("WRA ");/* Closing of template. */
OUTDENT;
REDUCE(pp,3,tlist,-1,6060);
}
}


}
#endif


#if FCN_CALLS
SRTN C_tlist(VOID)
{



}
#endif


#if FCN_CALLS
SRTN C_namespace(VOID)
{

{
if(cat1==expr||cat1==int_like)
{/* \Cpp: |@c++ namespace A| */
make_underlined(pp+1);make_reserved(pp+1);

b_app1(pp);b_app(040);b_app1(pp+1);

REDUCE(pp,2,fn_decl,0,7901);
}
else if(cat1==lbrace)
SQUASH(pp,1,fn_decl,0,7902);/* |@c++ namespace{}| */
}


}
#endif


#endif /* Part 1 */

#if(part != 1)


SRTN
R_productions(VOID)
{
switch(pp->cat)
{
case ignore_scrap:

#if FCN_CALLS
C_ignore_scrap();
#else

{
switch(cat1)
{
case stmt:
case functn:
SQUASH(pp,2,cat1,0,1);
break;
}
}


#endif

break;
case expr:
#if FCN_CALLS
R_expr();
#else

{
if(cat1==unop)SQUASH(pp,2,expr,-2,2);
else if((cat1==binop||cat1==unorbinop||cat1==colon)&&cat2==expr)
/* Here we have to worry about constructions such as `|@r #:0|'. */
if(cat1==colon&&(*pp->trans)[1]==(sixteen_bits)043)
{
b_app1(pp);
APP_STR("\\Colon");
b_app1(pp+2);
REDUCE(pp,3,expr,-2,3333);
}
else SQUASH(pp,3,expr,-2,3);/* ``|@r x = y|'' or ``|@r x + y|'' or \
				``|@r dimension a(0:100)|'' */
else if(cat1==comma&&(cat2==expr||cat2==end_like))/* Note |end_like|; \
					keyword in I/O. */
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,expr,-2,4);
}
else if(cat1==expr)SQUASH(pp,2,expr,-2,5);/* ``|@r f(x)|'' */
else if(cat1==semi)SQUASH(pp,2,stmt,-2,6);/* ``|@r x=y;|'' */
else if(cat1==colon&&cat2==unorbinop&&
(cat3==rpar||(active_brackets&&cat3==rbracket)))
SQUASH(pp,3,expr,-2,299);/* ``|@r 0:*|'' */
else if(cat1==colon&&cat2!=lpar)/* label */
{
make_underlined(pp);SQUASH(pp,2,tag,0,7);
}
else if(cat1==comma&&cat2==int_like)/* For macro usage. */
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,int_like,-2,4444);
}
}


#endif

break;
case key_wd:
#if FCN_CALLS
R_key_wd();
#else

{
SQUASH(pp,1,expr,-2,4445);
}


#endif

break;
case exp_op:
#if FCN_CALLS
R_exp_op();
#else

{
if(cat1==lpar)SQUASH(pp,1,exp_op,PLUS 1,2995);/* ``|@r x^(a+b)|'' */
else if(cat1==expr)
if(cat2==lpar)SQUASH(pp,1,exp_op,PLUS 2,2996);/* Expand array \
argument. */
else if(cat2==expr)SQUASH(pp,1,exp_op,PLUS 1,2997);/* The expr is \
the result of expanding the array argument. */
else
{/* It's now of the form |@r x^expr|; insert braces around \
argument so \TeX\ understands. */
b_app1(pp);
b_app(0173);b_app1(pp+1);b_app(0175);
REDUCE(pp,2,expr,-1,2998);
}
}


#endif

break;
case _EXPR:
#if FCN_CALLS
C__E();
#else

{
APP_SPACE;b_app1(pp);
REDUCE(pp,1,expr,-2,4446);
}


#endif

break;
case _EXPR_:
#if FCN_CALLS
C__E_();
#else

{


APP_SPACE;b_app1(pp);APP_SPACE;

;
REDUCE(pp,1,expr,-2,4447);
}


#endif

break;
case EXPR_:
#if FCN_CALLS
C_E_();
#else

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,expr,-2,4448);
}


#endif

break;
case lpar:
#if FCN_CALLS
R_lpar();
#else


if(cat1==expr&&cat2==rpar)SQUASH(pp,3,expr,-2,120);/* ``|@r (x)|'' */
else if(cat1==expr&&cat2==colon&&cat3==rpar)/* ``|@r (lower:)|'' */
{
b_app3(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+3);
REDUCE(pp,4,expr,-2,9120);
}
else if(cat1==colon&&cat2!=comma)/* ``|@r (:x)|''; watch out for \
			deferred-shape-spec-lists.  */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
REDUCE(pp,2,lpar,0,9121);
}
else if(cat1==rpar)/* ``|@r ()|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
REDUCE(pp,2,expr,-2,121);
}
else if(cat1==stmt)/* `` |@r for(x;y;z)|'' */
{
b_app2(pp);b_app(040);REDUCE(pp,2,lpar,0,123);
}


#endif

break;
case lbracket:
#if FCN_CALLS
C_lbracket();
#else

{
if(active_brackets)
{
b_app(0134);
APP_STR("WXA{");
}
else b_app1(pp);

REDUCE(pp,1,lpar,0,5000);
}


#endif

break;
case rbracket:
#if FCN_CALLS
C_rbracket();
#else

{
if(active_brackets)
{
text_pointer t= indirect(pp->trans);

if(**t==0135)**t= 0175;
}

b_app1(pp);

REDUCE(pp,1,rpar,-3,5001);
}


#endif

break;
case unop:
#if FCN_CALLS
R_unop();
#else


if(cat1==expr)SQUASH(pp,2,expr,-2,33);/* ``|@r !flag|'' */


#endif

break;
case UNOP:
#if FCN_CALLS
C_UNOP();
#else

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,unop,-1,4443);
}


#endif

break;
case unorbinop:
#if FCN_CALLS
R_unorbinop();
#else


if(cat1==expr)/* ``|@r +1.0|'' */
{
b_app(0173);b_app1(pp);b_app(0175);
b_app1(pp+1);
REDUCE(pp,2,expr,-2,140);
}
else if(cat1==binop)
{
b_app(math_bin);
b_app1(pp);
b_app(0173);b_app1(pp+1);b_app(0175);
b_app(0175);/* End |math_bin| */
REDUCE(pp,2,binop,-1,151);
}


else if(cat1==comma||cat1==rpar)SQUASH(pp,1,expr,-2,141);/* ``|@r \
*,|'' or ``|@r *)|'' */


#endif

break;
case binop:
#if FCN_CALLS
R_binop();
#else


if(cat1==binop)/* ``|@r / /|'' */
{
sixteen_bits tok;

tok= **pp->trans;

if(tok==(sixteen_bits)057&&(**(pp+1)->trans==tok))

{
b_app(0173);
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
b_app(0175);
REDUCE(pp,2,slashes,-1,180);
}


else
{
b_app(math_bin);b_app1(pp);
b_app(0173);b_app1(pp+1);b_app(0175);
b_app(0175);/* End |math_bin| */
REDUCE(pp,2,binop,-1,180);
}


}
else if(cat1==expr&&cat2==binop)/* ``|@r /dia/|'' */
{
sixteen_bits tok;

tok= **pp->trans;

if(tok==(sixteen_bits)057&&(**(pp+2)->trans==tok))

{
b_app(0173);
b_app1(pp);/* |'/'| */
b_app(0175);

make_underlined(pp+1);/* Index common block name. */
b_app1(pp+1);/* expr */

b_app(0173);
b_app1(pp+2);/* |'/'| */
b_app(0175);

REDUCE(pp,3,slashes,-1,9181);
}


}


#endif

break;
case BINOP:
#if FCN_CALLS
C_BINOP();
#else

{


APP_SPACE;b_app1(pp);APP_SPACE;

;
REDUCE(pp,1,binop,-1,4444);
}


#endif

break;
case slash_like:
#if FCN_CALLS
R_slash_like();
#else

if(cat1==slash_like)
{/* The slash already has braces around it (appended by \FWEAVE).ac */
b_app1(pp);

{
b_app(0134);b_app(054);
}

;
b_app1(pp+1);
REDUCE(pp,2,slashes,-1,1801);
}
else if(cat1==expr&&cat2==slash_like)
SQUASH(pp,3,slashes,-1,1802);


#endif

break;
case colon:
#if FCN_CALLS
R_colon();
#else


if(cat1==expr||cat1==unorbinop)SQUASH(pp,2,expr,-2,9500);/* ``|@r \
(:upper)|'' */
else if(cat1==comma&&cat2==colon)SQUASH(pp,3,expr,-2,9502);
/* Deferred-shape-spec-list: |@r (:,:)| */
else SQUASH(pp,1,expr,0,9501);/* |@r (:)| */


#endif

break;
case program_like:
#if FCN_CALLS
R_program_like();
#else


if(is_FORTRAN_(language))
{
if(cat1==expr&&cat2==semi)
{
fcn_level++;
b_app1(pp);b_app(040);
b_app(indent);b_app2(pp+1);b_app(outdent);
defined_at(make_underlined(pp+1));
REDUCE(pp,3,fcn_hd,-1,2999);
}
else if(cat1==no_order)
{/* |@r block data| */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,program_like,0,2997);
}
else if(cat1==semi)
{/* |@r block data;| */
fcn_level++;
b_app1(pp);
REDUCE(pp,2,fcn_hd,-1,2996);
}
}
else
{
fcn_level++;
SQUASH(pp,1,int_like,-1,2998);
}


#endif

break;
case struct_like:
#if FCN_CALLS
R_struct_like();
#else

if(cat1==lpar)
{
b_app1(pp);
#if(0)

{
b_app(0134);b_app(054);
}

/* Looks nicer with a bit of space. */
#endif
REDUCE(pp,1,int_like,0,9075);/* \FORTRAN-88 declaration: \
``|@r9 type(triangle)|''. */
}
else if(cat1==comma&&cat2==int_like)
{
b_app2(pp);b_app(040);b_app1(pp+2);
REDUCE(pp,3,struct_like,0,90750);/* ``|@r9 type, private|'' */
}
else if(cat1==binop&&**(pp+1)->trans!=(sixteen_bits)057)
SQUASH(pp,2,struct_like,0,90751);/* ``|@r9 type, public::|''  The \
		|!=| precluded the VAX |@n9 structure /stuff/| declaration. */
else if(cat1==expr||cat1==slashes||cat1==struct_like)
{/* ``|@r9 type person|'', ``|@r9 type /vaxstruct/|'', or ``|@r9 \
			interface operator|'' */
b_app1(pp);b_app(040);b_app1(pp+1);
make_underlined(pp+1);
REDUCE(pp,2,language==FORTRAN_90?struct_hd:struct_like,0,9076);
}
else if(cat1==semi)
SQUASH(pp,1,struct_hd,0,9077);/* |@r9 interface| */
else if(cat1==lbrace)/* ``|@r9 type person {integer i;};|'' */
{
b_app1(pp);indent_force;
b_app1(pp+1);REDUCE(pp,2,struct_hd,0,100);
}


#endif

break;
case struct_hd:
#if FCN_CALLS
R_str_hd();
#else

if(is_FORTRAN_(language))
{
if(cat1==expr)
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

b_app1(pp+1);/* ``|@r9 \
interface operator(.not.)|'' */
REDUCE(pp,2,struct_hd,0,90760);
}
else if(cat1==semi)
{
fcn_level++;
b_app2(pp);
b_app(indent);
REDUCE(pp,2,struct_hd,0,90770);
}
else if(cat1==decl||cat1==functn)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,struct_hd,0,9078);
}
else if(cat1==END_stmt)
{
b_app1(pp);
b_app(outdent);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,9079);
}
}
else
{
if((cat1==decl||cat1==stmt
||cat1==expr /*  (For enum) */
||cat1==functn /* \Cpp */
)&&cat2==rbrace)
{
b_app1(pp);/* ``|struct {|'' */
b_app(force);b_app1(pp+1);/* Body */
b_app(force);b_app1(pp+2);/* ``|}|'' */
b_app(outdent);
REDUCE(pp,3,int_like,-1,110);
}
else if(cat1==rbrace)
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,int_like,-1,1101);
}
}




#endif

break;
case op_like:
#if FCN_CALLS
R_op_like();
#else

{
short n;

if(cat1==lpar)
{/* We'll search for the obligatory right paren that terminates \
the list. */
scrap_pointer q;
int k;/* Counter. */

/* If the paren is missing, we could end up appending the entire rest of \
the code, so we limit the search. */
for(q= pp+2;q<=scrp_ptr&&q-pp<MAX_OP_TOKENS;q++)
if(q->cat==rpar)break;

n= (q->cat==rpar)?PTR_DIFF(short,q,pp):0;

if(n>0)
{
b_app1(pp);b_app(040);/* |@r9 operator| */
b_app1(pp+1);/* Left paren. */
b_app(0173);
APP_STR("\\optrue");

for(k= 2;k<n;k++)
b_app1(pp+k);

APP_STR("\\opfalse");/* We need this here in case we \
encounter an operator that \FWEAVE\ doesn't know how to overload. */
b_app(0175);
b_app1(pp+k);

REDUCE(pp,n+1,expr,-2,6667);
}
}
}


#endif

break;
case proc_like:
#if FCN_CALLS
R_proc_like();
#else


if(fcn_level==0){/* Error message */}
else fcn_level--;

SQUASH(pp,1,int_like,-1,2989);


#endif

break;
case private_like:
#if FCN_CALLS
R_private_like();
#else

{
if(cat1==(eight_bits)(language==FORTRAN_90?semi:colon))
{
app(backup);
b_app2(pp);
REDUCE(pp,2,decl,-1,2988);
}
else SQUASH(pp,1,int_like,-2,2987);
}


#endif

break;
case int_like:
#if FCN_CALLS
R_int_like();
#else

{
if(cat1==lbrace)
{
b_app(indent);
b_app1(pp);
REDUCE(pp,1,decl_hd,0,940);/* ``|@r block data{}|'' */
}
else if(cat1==unorbinop&&cat2==expr)/* ``|@r character*(*)|'' */
{
b_app1(pp);
b_app(0173);b_app2(pp+1);b_app(0175);
REDUCE(pp,3,int_like,-1,941);
}
else if(cat1==int_like||cat1==no_order)/* ``|@r double precision|'' or \
		F88 things like ``|@r integer, pointer|''; |no_order| takes \
		care of \&{data} in |@r block data|. */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,cat0,0,40);
}
else if(cat1==comma)
SQUASH(pp,2,int_like,0,9001);/* F88: ``|@r logical,|'' */
else if(cat1==binop)/* F88: ``|@r integer :: i|'' */
{
b_app2(pp);
b_app(indent);
REDUCE(pp,2,decl_hd,0,9002);
}
else if(cat1==slashes)
{
b_app1(pp);
b_app(040);
b_app(indent);
REDUCE(pp,1,decl_hd,0,9002);
}
else if(cat1==expr&&**indirect((pp+1)->trans)==050)
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

b_app1(pp+1);
REDUCE(pp,2,int_like,0,9003);/* ``|@r integer (KIND=4)|'' */
}
else if(cat1==expr||cat1==semi)
{
b_app1(pp);

if(cat1!=semi)b_app(040);

b_app(indent);/* Start long declaration. */

REDUCE(pp,1,decl_hd,0,41);/* JAK: -1 changed to 0 */
}
else if(cat1==rbrace)
SQUASH(pp,1,decl,-1,411);
/* See \.{ratfor} example |@r9 module procedure element;|. */
}


#endif

break;
case decl_hd:
#if FCN_CALLS
R_dcl_hd();
#else

if(cat1==comma)
{/* ``|@r integer i,j|'' */
b_app2(pp);b_app(040);REDUCE(pp,2,decl_hd,0,54);
}
else if(cat1==expr)
{
make_underlined(pp+1);

if(**(pp+2)->trans==(sixteen_bits)075)
{/* Initialization coming up. */
SQUASH(pp,1,decl_hd,PLUS 1,55);
}
else
{
SQUASH(pp,2,decl_hd,0,56);
}
}
else if(cat1==slashes)
{/* |@r integer i/1/| */
SQUASH(pp,2,decl_hd,0,57);
}
else if(cat1==lbrace||cat1==int_like||cat1==implicit_like)
/* |@r subroutine f {}| or |@r function f(x) real x;| or |@r \
program main implicit none;|  */
{
b_app1(pp);
b_app(outdent);/* Turn off |indent|. */
defined_at(FIRST_ID(pp));
REDUCE(pp,1,fn_decl,0,58);
}
else if(cat1==semi&&(!auto_semi||(auto_semi&&cat2!=lbrace)))
{
b_app2(pp);
b_app(outdent);/* Finish long declaration. */
REDUCE(pp,2,
(eight_bits)(intermingle?(intermingle= NO,ignore_scrap):decl),
-1,59);
}
else if(cat1==built_in)
{/* |@r9 use a, only| */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,decl_hd,0,5901);
}
#if(0)
else if(cat1==lpar&&cat2==expr)make_underlined(pp+2);/* For \
						|$decl_hd|. */
#endif


#endif

break;
case decl:
#if FCN_CALLS
R_decl();
#else

if(is_FORTRAN_(language)&&cat1==END_like)SQUASH(pp,1,stmt,-1,960);
/* `` |@r program main; end;|'' */
else if(cat1==decl)
{
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,60);
}
else if(cat1==stmt||cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,-1,61);
}


#endif

break;
case fn_decl:
#if FCN_CALLS
C_fn_decl();
#else

{
if(cat1==semi&&Cpp)
{/* |@c++ using namespace X;| */
b_app2(pp);
REDUCE(pp,2,stmt,-1,72);
}
else if(cat1==decl)/* ``|f(x) float x;|'' */
{
b_app1(pp);
b_app(indent);indent_force;
b_app1(pp+1);/* Accrete old-style declarations. */
b_app(outdent);b_app(outdent);
REDUCE(pp,2,fn_decl,0,70);
}
else if(cat1==stmt)/* ``|f(){}|'' */
{
#if(0)
b_app(backup);/* Beginning of function. */
#endif
b_app1(pp);b_app(force);
b_app(indent);
b_app1(pp+1);/* Function body */
b_app(outdent);
in_function= NO;
REDUCE(pp,2,functn,-1,71);
}
}


#endif

break;
case fcn_hd:
#if FCN_CALLS
R_fcn_hd();
#else

{
if(cat1==END_stmt)
{
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,functn,-1,7172);
}
else if(cat1==stmt&&cat2==END_stmt)
{
b_app1(pp);b_app(force);
b_app(indent);
b_app1(pp+1);/* Body */

if(fcn_level==0)
{
if(containing)b_app(big_force);
while(containing)
{
#if(0)
b_app(outdent);
#endif
containing--;
}
}

b_app(outdent);
b_app(force);

b_app1(pp+2);
REDUCE(pp,3,functn,-1,7171);
}
}


#endif

break;
case functn:
#if FCN_CALLS
R_functn();
#else


if(cat1==functn||(is_RATFOR_(language)&&(cat1==decl||cat1==stmt)))
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,0,80);
}
#if(0)
else if(cat1==END_like)
{
b_app1(pp);
REDUCE(pp,1,stmt,-1,9050);
}
#endif


#endif

break;
case lbrace:
#if FCN_CALLS
R_lbrace();
#else

if(cat1==rbrace)/* ``|@r {}|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
REDUCE(pp,2,stmt,-2,130);
}
else if((cat1==stmt||cat1==decl)&&cat2==rbrace)/* ``|@r {x;}|'' */
{
b_app(force);
b_app1(pp);b_app(force);
b_app1(pp+1);b_app(force);
b_app1(pp+2);
REDUCE(pp,3,stmt,-2,131);
}


#endif

break;
case do_like:
#if FCN_CALLS
R_do_like();
#else


if(cat1==stmt)
{
if(cat2==until_like)
{
found_until= YES;
SQUASH(pp,1,do_like,PLUS 2,9190);/* ``|@r repeat \
{} until ;|''; expand the \&{until}. */
}
else
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
b_app(force);

if(found_until&&cat2==stmt)/* Get here by expanding the \
\&{until}. */
{
found_until= NO;
b_app1(pp+2);REDUCE(pp,3,stmt,-2,9191);
}
else REDUCE(pp,2,stmt,-2,9192);/* ``|@r repeat {}|''; \
no bottom. */
}
}


#endif

break;
case until_like:
#if FCN_CALLS
R_until_like();
#else


SQUASH(pp,1,for_like,0,9195);


#endif

break;
case Rdo_like:
#if FCN_CALLS
R_Rdo_like();
#else


if(is_FORTRAN_(language))
{
if(cat1==for_like)/* \&{do} \&{while} */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,Rdo_like,0,9600);
}
else if(cat1==expr&&((cat2==expr&&cat3==binop)||cat2==if_like))
/* ``|@r do 10 i='' */
{
label_text_ptr[indent_level]= (pp+1)->trans;/* Pointer to \
			a |token_pointer|---namely, index into |tok_start|. */
b_app1(pp);
b_app(040);
b_app1(pp+1);/* Loop number. */
REDUCE(pp,2,Rdo_like,0,9601);/* Swallow only the loop number. */
}
else if(cat1==stmt)/* ``|@r do i=1,10;|'' */
{
loop_num[indent_level++]= ++max_loop_num;

b_app1(pp);/* \&{do} */
b_app(040);
b_app1(pp+1);/* $i=1,10;$ */
app_loop_num(max_loop_num);

b_app(indent);
REDUCE(pp,2,stmt,-2,9602);
}
}
/* \Ratfor. */
else if(cat1==stmt||(cat1==expr&&cat2==lbrace))/* ``|@r do i=1,10;|'' \
or ``|@r do i=1,10{|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,for_hd,0,9603);
}


#endif

break;
case if_like:
#if FCN_CALLS
R_if_like();
#else


if(cat1==CASE_like)
{
b_app1(pp);b_app(040);b_app1(pp+1);/* |@r9 select case| */
REDUCE(pp,2,if_like,0,9196);
}
else
if(is_FORTRAN_(language))
{
if(cat1==expr)
{
boolean if_form;

if((if_form= BOOLEAN(cat2==built_in&&cat3==semi))||cat2==semi)
{/* ``|@n if(x) then;|''  or ``|@n where(x); |'' */
short n;/* Number to append. Things are annoying because the |@n if| \
and |@n where| statements aren't completely symmetrical. */

loop_num[indent_level++]= ++max_loop_num;

b_app1(pp);/* \&{if} */

{
b_app(0134);b_app(054);
}

;
b_app1(pp+1);/* $(x)$ */
b_app(040);

if(if_form)
{
n= 4;
b_app2(pp+2);/* \&{then}; */
}
else
{/* |@n where| */
n= 3;
b_app1(pp+2);/* semi */
}

app_loop_num(max_loop_num);
b_app(indent);
REDUCE(pp,n,stmt,-2,9800);
}
else if(cat2==stmt)/* ``|@n if(x) a=b;|'' */
{
b_app1(pp);/* \&{if} */

{
b_app(0134);b_app(054);
}

;
b_app1(pp+1);/* $(x)$ */
app(040);
b_app(cancel);
b_app1(pp+2);/* Statement */
REDUCE(pp,3,stmt,-2,9801);
}
else
{
b_app1(pp);

{
b_app(0134);b_app(054);
}

;
b_app1(pp+1);
REDUCE(pp,2,if_hd,0,9802);
}
}
}
/* RATFOR\ */
else
{
if(cat1==lpar&&cat2==expr&&cat3==rpar)/* ``|if(x)|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app3(pp+1);
#if(0)
cmnt_after_IF= (cat4==ignore_scrap);/* Comment coming up? */
#endif
REDUCE(pp,4,IF_like,0,220);
}
}





#endif

break;
case IF_like:
#if FCN_CALLS
C_IF();
#else

{
if(cat1==stmt
||cat1==lbrace||cat1==if_like||cat1==for_like||cat1==do_like
||cat1==Rdo_like
#if(0)
||cmnt_after_IF
#endif
)
SQUASH(pp,1,if_hd,0,230);/* |if_hd| does the indenting. */
#if(0)
else if(cat1==stmt)
{/* Attach simple statement. */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,IF_top,-1,231);
}
#endif
}


#endif

break;/* The C form serves \
both. */
case IF_top:
#if FCN_CALLS
C_IF_top();
#else

{
if(cat1==else_like||cat1==else_hd)
SQUASH(pp,1,IF_top,1,242);/* Expand ahead. */
else if(cat1==IF_top)
{
b_app1(pp);/* \&{if}\dots */
b_app(force);
b_app1(pp+1);/* \&{else if}\dots */
REDUCE(pp,2,IF_top,-1,238);
}
else if(cat1==ELSE_like)
{
b_app1(pp);/* \&{if} */
b_app(force);
b_app1(pp+1);/* \&{else} */
REDUCE(pp,2,stmt,-1,239);
}
else if(cat1==IF_like&&(cat2==expr||cat2==stmt))
SQUASH(pp,1,IF_top,1,241);
else
SQUASH(pp,1,stmt,-1,240);
}


#endif

break;
case endif_like:
#if FCN_CALLS
R_endif_like();
#else

{
short n;
boolean no_construct_name;

if((no_construct_name= BOOLEAN(cat1==semi))||(cat1==expr&&cat2==semi))
{
b_app(outdent);
b_app(force);

if(no_construct_name)
{
n= 2;
b_app2(pp);/* \&{endif}; or \&{enddo}; */
}
else
{/* Include \It{if-construct-name} */
n= 3;
b_app1(pp);b_app(040);b_app2(pp+1);
}

if(--indent_level<0)
indent_level= 0;

app_loop_num(loop_num[indent_level]);
REDUCE(pp,n,stmt,-2,9880);
}
}


#endif

break;
case end_like:
#if FCN_CALLS
R_end_like();
#else

if(cat1==Rdo_like||cat1==if_like)/* ``|@r end do|'' or ``|@r end if|'' */
{
b_app1(pp);/* \&{end} */
b_app(040);
b_app1(pp+1);/* \&{do} or \&{if} */
REDUCE(pp,2,endif_like,0,9860);/* Now turned into \&{enddo} or \
\&{endif} */
}
else
{
fcn_level--;
SQUASH(pp,1,END_like,-1,9861);/* \&{end} of function. */
}


#endif

break;
case END_like:
#if FCN_CALLS
R_END();
#else

{
if(cat1==program_like||cat1==struct_like)
{
b_app1(pp);b_app(040);b_app1(pp+1);

if(cat2==expr)
{
b_app(040);b_app1(pp+2);
REDUCE(pp,3,END_like,0,9860);
}
else
REDUCE(pp,2,END_like,0,9861);
}
else if(cat1==semi)
SQUASH(pp,2,END_stmt,-2,9862);
}


#endif

break;
case go_like:
#if FCN_CALLS
R_go_like();
#else


if(cat1==built_in)/* ``|@r go to|'' */
{
b_app1(pp);/* \&{go} */
b_app(040);
b_app1(pp+1);/* \&{to} */
REDUCE(pp,2,case_like,0,9850);/* \&{goto} */
}
else SQUASH(pp,1,expr,-2,9851);


#endif

break;
case for_like:
#if FCN_CALLS
C_for_like();
#else

{
if(cat1==expr)
{/* ``\&{for}\dots'' */
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
b_app(040);

if(cat2==semi)
{/* ``|for(;;);|'' */
if(!auto_semi||(auto_semi&&cat3==semi))
{
indent_force;
b_app1(pp+2);/* Semi on separate line. */
b_app(outdent);
REDUCE(pp,3,stmt,-2,200);/*  The $-2$ is for the \
\&{do} case. Also get here from Ratfor's \&{until}. */
}
else
REDUCE(pp,3,for_hd,0,2011);/* Eat the |auto_semi|. */
}
else
REDUCE(pp,2,for_hd,0,201);/* Eat the arguments. */
}
else if(cat1!=lpar)
SQUASH(pp,1,expr,0,2010);/* Default possiblity. */
}


#endif

break;
case for_hd:
#if FCN_CALLS
C_forhd();
#else

{
if(cat1==stmt)
{/* ``|for(;;) x;|'' */
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,stmt,-1,210);
}
}


#endif

break;/* C serves both. */
case else_like:
#if FCN_CALLS
R_else_like();
#else


if(is_FORTRAN_(language))
{
if(cat1==if_like)/* ``|@n else if|'' */
{
b_app1(pp);/* \&{else} */
b_app(040);
b_app1(pp+1);/* \&{if} */
REDUCE(pp,2,else_like,0,9910);/* \&{elseif} */
}
else if(cat1==semi)/* \&{else}; */
{
b_app(outdent);
b_app(force);
b_app2(pp);/* \&{else} or \&{elseif} */
app_loop_num(loop_num[indent_level-1]);
b_app(indent);
REDUCE(pp,2,stmt,-2,9911);
}
else if(cat1==expr&&cat2==built_in&&cat3==semi)/* ``|@n else if(x) \
then;|'' */
{
b_app(outdent);
b_app(force);

b_app1(pp);/* \&{elseif} */

{
b_app(0134);b_app(054);
}

;
b_app1(pp+1);/* $(x)$ */
b_app(040);
b_app2(pp+2);/* \&{then}; */
app_loop_num(loop_num[indent_level-1]);

b_app(indent);
REDUCE(pp,4,stmt,-2,9912);
}
}
/* \Ratfor\ */
else
{
if(cat1==if_like)/* ``|else if|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,if_like,0,235);
}
else if(cat1==stmt||cat1==lbrace||cat1==for_like||cat1==do_like)
SQUASH(pp,1,else_hd,0,236);/* ``|else {}|'' */
#if 0 /* The following puts simple statement on same line. */
else if(cat1==stmt)/* ``|else z;|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,ELSE_like,-1,237);
}
#endif
}




#endif

break;
case else_hd:
#if FCN_CALLS
C_els_hd();
#else

{
if(cat1==stmt)/* ``|if(x) {}|'' */
{
b_app1(pp);/* ``|if(x)|'' */
indent_force;
b_app1(pp+1);/* ``|{}|'' */
b_app(outdent);
REDUCE(pp,2,ELSE_like,-1,241);
}
}


#endif

break;
case if_hd:
#if FCN_CALLS
R_if_hd();
#else


if(is_FORTRAN_(language))
{
if(cat1==stmt)
{
b_app1(pp);b_app(break_space);b_app1(pp+1);
REDUCE(pp,2,stmt,-2,9900);
}
}
else
{
if(cat1==stmt)/* ``|if(x) {}|'' */
{
b_app1(pp);/* ``|if(x)|'' */
indent_force;
b_app1(pp+1);/* ``|{}|'' */
b_app(outdent);
REDUCE(pp,2,IF_top,-1,233);
}
else if(cat1==IF_top&&cat2==else_like)
SQUASH(pp,1,if_hd,2,234);
}




#endif

break;
case CASE_like:
#if FCN_CALLS
R_CASE();
#else


if(is_FORTRAN_(language))
{
b_app(backup);
b_app1(pp);
REDUCE(pp,1,case_like,0,9258);
}
else SQUASH(pp,1,case_like,0,9259);


#endif

break;
case case_like:
#if FCN_CALLS
R_case_like();
#else

if(cat1==read_like)/* ``|@r call open|'' */
{
b_app1(pp);/* \&{call} */
b_app(040);
b_app1(pp+1);/* \&{close}, \&{open}, etc. */
REDUCE(pp,2,case_like,0,9260);
}
else if(cat1==semi)SQUASH(pp,2,stmt,-2,260);/* ``|@r return;|'' */
else if(cat1==colon)
{
b_app1(pp);APP_STR("\\Colon\\ ");
REDUCE(pp,2,tag,-1,261);
}


else if(cat1==expr&&cat2==semi)
{/* ``|@r return 1;|'' */
b_app1(pp);b_app(040);b_app2(pp+1);
REDUCE(pp,3,stmt,-2,262);
}
else if((cat1==expr||cat1==label)&&cat2==colon)
{/* ``|@r case 1:|'' */
b_app1(pp);b_app(040);b_app1(pp+1);
APP_STR("\\Colon\\ ");
REDUCE(pp,3,tag,-1,263);
}


#endif

break;
case stmt:
#if FCN_CALLS
R_stmt();
#else


if(is_FORTRAN_(language)&&cat1==program_like)SQUASH(pp,1,functn,
PLUS 1,9960);
else if(cat1==stmt)
{
b_app1(pp);
b_app(break_space);
b_app(force);

b_app1(pp+1);REDUCE(pp,2,stmt,-2,250);
}
else if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-2,251);
}


#endif

break;
case tag:
#if FCN_CALLS
R_tag();
#else


if(cat1==tag)/* ``|@r case 1: case 2:|'' */
{
b_app1(pp);b_app(force);
b_app(backup);
b_app1(pp+1);REDUCE(pp,2,tag,-1,270);
}
else if(cat1==stmt||cat1==END_like)/* ``|@r 10 continue;|'' */
{
boolean end_of_loop;

end_of_loop= NO;

/* Unwind indent levels for labeled loops. */
while(indent_level>0&&
compare_text(pp->trans,label_text_ptr[indent_level-1]))
{
--indent_level;
b_app(outdent);
end_of_loop= YES;
}

if(is_FORTRAN_(language)&&Fortran_label)
{/* ``|@n EXIT: continue'' */
b_app(force);
APP_STR("\\Wlbl{");b_app1(pp);app(0175);

}
else
{/* Label on separate line. */
b_app(big_force);
b_app(backup);
b_app1(pp);/* Tag (Includes colon.) */
b_app(force);
}

b_app1(pp+1);/* Stmt. */

if(end_of_loop)
app_loop_num(loop_num[indent_level]);

REDUCE(pp,2,cat1,-2,271);
}



#endif

break;
case label:
#if FCN_CALLS
R_label();
#else

if(cat1==colon)
{
b_app1(pp);
REDUCE(pp,2,label,0,9270);/* Swallow the colon. (Numerical \
statement labels won't have any.) Then, for all labels, we put a colon in \
during the next block. */
}
else if(cat1==stmt||cat1==END_like)
{
b_app1(pp);APP_STR("\\Colon\\ ");

if(is_FORTRAN_(language)&&Fortran_label)
b_app(cancel);

REDUCE(pp,1,tag,0,9271);/* Convert the label into a tag. Don't \
					swallow the statement. */
}


#endif

break;
case semi:
#if FCN_CALLS
R_semi();
#else

if(is_RATFOR_(language)&&auto_semi)
{/* Just throw away semi. */
text_pointer t;

t= indirect(pp->trans);

if(**t==073)**t= 0;
SQUASH(pp,1,ignore_scrap,-1,9280);
}
else
{
b_app(040);b_app1(pp);REDUCE(pp,1,stmt,-2,280);
}


#endif

break;

case common_like:
#if FCN_CALLS
R_common_like();
#else

if(cat1==expr||cat1==slashes||cat1==semi)
/* ``|@r common x| or |@r common/dia/|'' */
{
b_app1(pp);
if(cat1!=semi)b_app(040);
b_app(indent);
REDUCE(pp,1,common_hd,0,9950);
}


#endif

break;
case common_hd:
#if FCN_CALLS
R_cmn_hd();
#else


if(cat1==expr)SQUASH(pp,2,common_hd,0,9951);/* ``|@r common x|'' */
else if(cat1==slashes)/* ``|@r common/dia/|'' */
{
b_app1(pp);
b_app(040);
b_app1(pp+1);
b_app(040);
REDUCE(pp,2,common_hd,0,9952);
}
else if(cat1==comma)/* ``|@r common x,y|'' */
{
b_app2(pp);
b_app(040);
REDUCE(pp,2,common_hd,0,9953);
}
else if(cat1==semi)
{
b_app2(pp);
b_app(outdent);
REDUCE(pp,2,decl,-1,9954);/* ``|@r common x;|'' */
}


#endif

break;
case read_like:
#if FCN_CALLS
R_read_like();
#else


if(cat1==lpar&&cat2==expr&&cat3==rpar)/* |@r read(6,100)| */
{
b_app1(pp);

{
b_app(0134);b_app(054);
}

;
b_app3(pp+1);
b_app(040);
REDUCE(pp,4,read_hd,0,9960);
}
else if(cat1==expr&&cat2==comma)/* ``|@r TYPE 100, i'' */
{
b_app1(pp);
b_app(040);
b_app2(pp+1);
b_app(040);
REDUCE(pp,3,read_hd,0,9961);
}
else if(cat1==expr||cat1==unorbinop)/* ``|@r TYPE *|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);

if(cat2==expr)b_app(040);/* Takes care of |"TYPE 100 i"|. */

REDUCE(pp,2,read_hd,0,9962);
}
else if(cat1==semi)SQUASH(pp,1,read_hd,0,9963);



#endif

break;
case read_hd:
#if FCN_CALLS
R_rd_hd();
#else

if(cat1==comma)/* ``|@r read(6,100),|'' */
{
b_app2(pp);
b_app(040);
REDUCE(pp,2,read_hd,0,9965);
}
else if(cat1==expr)
{
if(cat2==comma||cat2==semi)
SQUASH(pp,2,read_hd,0,9966);/* ``|@r write(6,100) i,j'' */
}
else if(cat1==semi&&cat2==read_like)/* Two I/O statements back-to-back. */
{
b_app1(pp);
b_app1(pp+1);
b_app(force);
b_app1(pp+2);
REDUCE(pp,3,read_like,0,9967);
}
else if(cat1==semi)
{
b_app1(pp);
b_app1(pp+1);
REDUCE(pp,2,stmt,-2,9968);
}


#endif

break;
case entry_like:
#if FCN_CALLS
R_entry_like();
#else

if(cat1==expr&&cat2==semi)/* ``|@r entry E(x);|'' */
{
b_app(big_force);
b_app(backup);b_app1(pp);b_app(040);b_app2(pp+1);b_app(force);
REDUCE(pp,3,stmt,-2,9990);
}
else if(cat1==(eight_bits)(language==FORTRAN_90?semi:colon))
{/* ``|@r9 contains:|'' */
b_app(big_force);
b_app(backup);b_app2(pp);b_app(force);

containing++;
#if(0)
b_app(indent);
#endif
REDUCE(pp,2,stmt,-2,9991);
}


#endif

break;
case implicit_like:
#if FCN_CALLS
R_implicit_like();
#else

if(cat1==int_like||cat1==expr)/* ``|@r implicit integer|'' or \
					``|@r implicit none|'' */
{
b_app1(pp);
b_app(040);
b_app(indent);/* Start possible long declaration. */
REDUCE(pp,1,implicit_hd,0,9970);
}
else if(cat1==semi)/* ``|@r implicit_none;|''. */
{
b_app1(pp);
b_app(indent);
REDUCE(pp,1,implicit_hd,0,99700);
}


#endif

break;
case implicit_hd:
#if FCN_CALLS
R_imp_hd();
#else

if(cat1==unorbinop&&cat2==expr)
{/* ``|@r implicit real*8|'' */
b_app1(pp);
b_app(0173);b_app2(pp+1);b_app(0175);

{
b_app(0134);b_app(054);
}

;
REDUCE(pp,3,implicit_hd,0,9971);
}
else if(cat1==expr)SQUASH(pp,2,implicit_hd,0,9972);/* ``|@r implicit \
	integer(a-h)|'' */
else if(cat1==comma||cat1==int_like)
{
b_app2(pp);

if(cat2!=unorbinop)
if(cat2==int_like)b_app(040);/* ``|@r implicit real x, \
integer i|'' */
else
{
b_app(0134);b_app(054);
}

;

REDUCE(pp,2,implicit_hd,0,9973);
}
else if(cat1==semi)SQUASH(pp,1,decl_hd,0,9974);/* ``|@r implicit \
	integer(a-h);|'' */


#endif

break;
case assign_like:
#if FCN_CALLS
R_assign_like();
#else

if(cat1==expr&&cat2==built_in&&cat3==expr)/* ``|@r assign 100 to k|'' */
{
b_app1(pp);
b_app(040);
b_app1(pp+1);
b_app(040);
b_app1(pp+2);
b_app(040);
b_app1(pp+3);
REDUCE(pp,4,expr,0,9980);
}


#endif

break;
case define_like:
#if FCN_CALLS
R_define_like();
#else

if(cat1==expr)
{
b_app(force);
b_app(backup);b_app2(pp);b_app(force);
REDUCE(pp,2,ignore_scrap,-1,9995);
}


#endif

break;
case built_in:
#if FCN_CALLS
R_built_in();
#else

{
b_app1(pp);

{
b_app(0134);b_app(054);
}

;
REDUCE(pp,1,expr,-2,9998);
}


#endif

break;
case no_order:
#if FCN_CALLS
R_no_order();
#else

intermingle= YES;
b_app(force);
b_app1(pp);b_app(040);
REDUCE(pp,1,int_like,0,9996);



#endif

break;
case newline:
#if FCN_CALLS
R_newline();
#else

SQUASH(pp,1,ignore_scrap,-1,9999);


#endif

break;
case COMMA:
#if FCN_CALLS
C_COMMA();
#else

{


APP_SPACE;b_app1(pp);APP_SPACE;

;
REDUCE(pp,1,comma,-1,4445);
}


#endif

break;

}
}


#if FCN_CALLS
SRTN R_expr(VOID)
{

{
if(cat1==unop)SQUASH(pp,2,expr,-2,2);
else if((cat1==binop||cat1==unorbinop||cat1==colon)&&cat2==expr)
/* Here we have to worry about constructions such as `|@r #:0|'. */
if(cat1==colon&&(*pp->trans)[1]==(sixteen_bits)043)
{
b_app1(pp);
APP_STR("\\Colon");
b_app1(pp+2);
REDUCE(pp,3,expr,-2,3333);
}
else SQUASH(pp,3,expr,-2,3);/* ``|@r x = y|'' or ``|@r x + y|'' or \
				``|@r dimension a(0:100)|'' */
else if(cat1==comma&&(cat2==expr||cat2==end_like))/* Note |end_like|; \
					keyword in I/O. */
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,expr,-2,4);
}
else if(cat1==expr)SQUASH(pp,2,expr,-2,5);/* ``|@r f(x)|'' */
else if(cat1==semi)SQUASH(pp,2,stmt,-2,6);/* ``|@r x=y;|'' */
else if(cat1==colon&&cat2==unorbinop&&
(cat3==rpar||(active_brackets&&cat3==rbracket)))
SQUASH(pp,3,expr,-2,299);/* ``|@r 0:*|'' */
else if(cat1==colon&&cat2!=lpar)/* label */
{
make_underlined(pp);SQUASH(pp,2,tag,0,7);
}
else if(cat1==comma&&cat2==int_like)/* For macro usage. */
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,int_like,-2,4444);
}
}


}
#endif


#if FCN_CALLS
SRTN R_key_wd(VOID)
{

{
SQUASH(pp,1,expr,-2,4445);
}


}
#endif


#if FCN_CALLS
SRTN R_exp_op(VOID)
{

{
if(cat1==lpar)SQUASH(pp,1,exp_op,PLUS 1,2995);/* ``|@r x^(a+b)|'' */
else if(cat1==expr)
if(cat2==lpar)SQUASH(pp,1,exp_op,PLUS 2,2996);/* Expand array \
argument. */
else if(cat2==expr)SQUASH(pp,1,exp_op,PLUS 1,2997);/* The expr is \
the result of expanding the array argument. */
else
{/* It's now of the form |@r x^expr|; insert braces around \
argument so \TeX\ understands. */
b_app1(pp);
b_app(0173);b_app1(pp+1);b_app(0175);
REDUCE(pp,2,expr,-1,2998);
}
}


}
#endif


#if FCN_CALLS
SRTN R_program_like(VOID)
{


if(is_FORTRAN_(language))
{
if(cat1==expr&&cat2==semi)
{
fcn_level++;
b_app1(pp);b_app(040);
b_app(indent);b_app2(pp+1);b_app(outdent);
defined_at(make_underlined(pp+1));
REDUCE(pp,3,fcn_hd,-1,2999);
}
else if(cat1==no_order)
{/* |@r block data| */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,program_like,0,2997);
}
else if(cat1==semi)
{/* |@r block data;| */
fcn_level++;
b_app1(pp);
REDUCE(pp,2,fcn_hd,-1,2996);
}
}
else
{
fcn_level++;
SQUASH(pp,1,int_like,-1,2998);
}


}
#endif


#if FCN_CALLS
SRTN R_fcn_hd(VOID)
{

{
if(cat1==END_stmt)
{
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,functn,-1,7172);
}
else if(cat1==stmt&&cat2==END_stmt)
{
b_app1(pp);b_app(force);
b_app(indent);
b_app1(pp+1);/* Body */

if(fcn_level==0)
{
if(containing)b_app(big_force);
while(containing)
{
#if(0)
b_app(outdent);
#endif
containing--;
}
}

b_app(outdent);
b_app(force);

b_app1(pp+2);
REDUCE(pp,3,functn,-1,7171);
}
}


}
#endif


#if FCN_CALLS
SRTN R_proc_like(VOID)
{


if(fcn_level==0){/* Error message */}
else fcn_level--;

SQUASH(pp,1,int_like,-1,2989);


}
#endif


#if FCN_CALLS
SRTN R_private_like(VOID)
{

{
if(cat1==(eight_bits)(language==FORTRAN_90?semi:colon))
{
app(backup);
b_app2(pp);
REDUCE(pp,2,decl,-1,2988);
}
else SQUASH(pp,1,int_like,-2,2987);
}


}
#endif


#if FCN_CALLS
SRTN R_int_like(VOID)
{

{
if(cat1==lbrace)
{
b_app(indent);
b_app1(pp);
REDUCE(pp,1,decl_hd,0,940);/* ``|@r block data{}|'' */
}
else if(cat1==unorbinop&&cat2==expr)/* ``|@r character*(*)|'' */
{
b_app1(pp);
b_app(0173);b_app2(pp+1);b_app(0175);
REDUCE(pp,3,int_like,-1,941);
}
else if(cat1==int_like||cat1==no_order)/* ``|@r double precision|'' or \
		F88 things like ``|@r integer, pointer|''; |no_order| takes \
		care of \&{data} in |@r block data|. */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,cat0,0,40);
}
else if(cat1==comma)
SQUASH(pp,2,int_like,0,9001);/* F88: ``|@r logical,|'' */
else if(cat1==binop)/* F88: ``|@r integer :: i|'' */
{
b_app2(pp);
b_app(indent);
REDUCE(pp,2,decl_hd,0,9002);
}
else if(cat1==slashes)
{
b_app1(pp);
b_app(040);
b_app(indent);
REDUCE(pp,1,decl_hd,0,9002);
}
else if(cat1==expr&&**indirect((pp+1)->trans)==050)
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

b_app1(pp+1);
REDUCE(pp,2,int_like,0,9003);/* ``|@r integer (KIND=4)|'' */
}
else if(cat1==expr||cat1==semi)
{
b_app1(pp);

if(cat1!=semi)b_app(040);

b_app(indent);/* Start long declaration. */

REDUCE(pp,1,decl_hd,0,41);/* JAK: -1 changed to 0 */
}
else if(cat1==rbrace)
SQUASH(pp,1,decl,-1,411);
/* See \.{ratfor} example |@r9 module procedure element;|. */
}


}
#endif


#if FCN_CALLS
SRTN R_struct_like(VOID)
{

if(cat1==lpar)
{
b_app1(pp);
#if(0)

{
b_app(0134);b_app(054);
}

/* Looks nicer with a bit of space. */
#endif
REDUCE(pp,1,int_like,0,9075);/* \FORTRAN-88 declaration: \
``|@r9 type(triangle)|''. */
}
else if(cat1==comma&&cat2==int_like)
{
b_app2(pp);b_app(040);b_app1(pp+2);
REDUCE(pp,3,struct_like,0,90750);/* ``|@r9 type, private|'' */
}
else if(cat1==binop&&**(pp+1)->trans!=(sixteen_bits)057)
SQUASH(pp,2,struct_like,0,90751);/* ``|@r9 type, public::|''  The \
		|!=| precluded the VAX |@n9 structure /stuff/| declaration. */
else if(cat1==expr||cat1==slashes||cat1==struct_like)
{/* ``|@r9 type person|'', ``|@r9 type /vaxstruct/|'', or ``|@r9 \
			interface operator|'' */
b_app1(pp);b_app(040);b_app1(pp+1);
make_underlined(pp+1);
REDUCE(pp,2,language==FORTRAN_90?struct_hd:struct_like,0,9076);
}
else if(cat1==semi)
SQUASH(pp,1,struct_hd,0,9077);/* |@r9 interface| */
else if(cat1==lbrace)/* ``|@r9 type person {integer i;};|'' */
{
b_app1(pp);indent_force;
b_app1(pp+1);REDUCE(pp,2,struct_hd,0,100);
}


}
#endif


#if FCN_CALLS
SRTN R_str_hd(VOID)
{

if(is_FORTRAN_(language))
{
if(cat1==expr)
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

b_app1(pp+1);/* ``|@r9 \
interface operator(.not.)|'' */
REDUCE(pp,2,struct_hd,0,90760);
}
else if(cat1==semi)
{
fcn_level++;
b_app2(pp);
b_app(indent);
REDUCE(pp,2,struct_hd,0,90770);
}
else if(cat1==decl||cat1==functn)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,struct_hd,0,9078);
}
else if(cat1==END_stmt)
{
b_app1(pp);
b_app(outdent);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,9079);
}
}
else
{
if((cat1==decl||cat1==stmt
||cat1==expr /*  (For enum) */
||cat1==functn /* \Cpp */
)&&cat2==rbrace)
{
b_app1(pp);/* ``|struct {|'' */
b_app(force);b_app1(pp+1);/* Body */
b_app(force);b_app1(pp+2);/* ``|}|'' */
b_app(outdent);
REDUCE(pp,3,int_like,-1,110);
}
else if(cat1==rbrace)
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,int_like,-1,1101);
}
}




}
#endif


#if FCN_CALLS
SRTN R_op_like(VOID)
{

{
short n;

if(cat1==lpar)
{/* We'll search for the obligatory right paren that terminates \
the list. */
scrap_pointer q;
int k;/* Counter. */

/* If the paren is missing, we could end up appending the entire rest of \
the code, so we limit the search. */
for(q= pp+2;q<=scrp_ptr&&q-pp<MAX_OP_TOKENS;q++)
if(q->cat==rpar)break;

n= (q->cat==rpar)?PTR_DIFF(short,q,pp):0;

if(n>0)
{
b_app1(pp);b_app(040);/* |@r9 operator| */
b_app1(pp+1);/* Left paren. */
b_app(0173);
APP_STR("\\optrue");

for(k= 2;k<n;k++)
b_app1(pp+k);

APP_STR("\\opfalse");/* We need this here in case we \
encounter an operator that \FWEAVE\ doesn't know how to overload. */
b_app(0175);
b_app1(pp+k);

REDUCE(pp,n+1,expr,-2,6667);
}
}
}


}
#endif


#if FCN_CALLS
SRTN R_dcl_hd(VOID)
{

if(cat1==comma)
{/* ``|@r integer i,j|'' */
b_app2(pp);b_app(040);REDUCE(pp,2,decl_hd,0,54);
}
else if(cat1==expr)
{
make_underlined(pp+1);

if(**(pp+2)->trans==(sixteen_bits)075)
{/* Initialization coming up. */
SQUASH(pp,1,decl_hd,PLUS 1,55);
}
else
{
SQUASH(pp,2,decl_hd,0,56);
}
}
else if(cat1==slashes)
{/* |@r integer i/1/| */
SQUASH(pp,2,decl_hd,0,57);
}
else if(cat1==lbrace||cat1==int_like||cat1==implicit_like)
/* |@r subroutine f {}| or |@r function f(x) real x;| or |@r \
program main implicit none;|  */
{
b_app1(pp);
b_app(outdent);/* Turn off |indent|. */
defined_at(FIRST_ID(pp));
REDUCE(pp,1,fn_decl,0,58);
}
else if(cat1==semi&&(!auto_semi||(auto_semi&&cat2!=lbrace)))
{
b_app2(pp);
b_app(outdent);/* Finish long declaration. */
REDUCE(pp,2,
(eight_bits)(intermingle?(intermingle= NO,ignore_scrap):decl),
-1,59);
}
else if(cat1==built_in)
{/* |@r9 use a, only| */
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,decl_hd,0,5901);
}
#if(0)
else if(cat1==lpar&&cat2==expr)make_underlined(pp+2);/* For \
						|$decl_hd|. */
#endif


}
#endif


#if FCN_CALLS
SRTN R_decl(VOID)
{

if(is_FORTRAN_(language)&&cat1==END_like)SQUASH(pp,1,stmt,-1,960);
/* `` |@r program main; end;|'' */
else if(cat1==decl)
{
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,60);
}
else if(cat1==stmt||cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,-1,61);
}


}
#endif


#if FCN_CALLS
SRTN R_functn(VOID)
{


if(cat1==functn||(is_RATFOR_(language)&&(cat1==decl||cat1==stmt)))
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,0,80);
}
#if(0)
else if(cat1==END_like)
{
b_app1(pp);
REDUCE(pp,1,stmt,-1,9050);
}
#endif


}
#endif


#if FCN_CALLS
SRTN R_lpar(VOID)
{


if(cat1==expr&&cat2==rpar)SQUASH(pp,3,expr,-2,120);/* ``|@r (x)|'' */
else if(cat1==expr&&cat2==colon&&cat3==rpar)/* ``|@r (lower:)|'' */
{
b_app3(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+3);
REDUCE(pp,4,expr,-2,9120);
}
else if(cat1==colon&&cat2!=comma)/* ``|@r (:x)|''; watch out for \
			deferred-shape-spec-lists.  */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
REDUCE(pp,2,lpar,0,9121);
}
else if(cat1==rpar)/* ``|@r ()|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
REDUCE(pp,2,expr,-2,121);
}
else if(cat1==stmt)/* `` |@r for(x;y;z)|'' */
{
b_app2(pp);b_app(040);REDUCE(pp,2,lpar,0,123);
}


}
#endif


#if FCN_CALLS
SRTN R_colon(VOID)
{


if(cat1==expr||cat1==unorbinop)SQUASH(pp,2,expr,-2,9500);/* ``|@r \
(:upper)|'' */
else if(cat1==comma&&cat2==colon)SQUASH(pp,3,expr,-2,9502);
/* Deferred-shape-spec-list: |@r (:,:)| */
else SQUASH(pp,1,expr,0,9501);/* |@r (:)| */


}
#endif


#if FCN_CALLS
SRTN R_lbrace(VOID)
{

if(cat1==rbrace)/* ``|@r {}|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
REDUCE(pp,2,stmt,-2,130);
}
else if((cat1==stmt||cat1==decl)&&cat2==rbrace)/* ``|@r {x;}|'' */
{
b_app(force);
b_app1(pp);b_app(force);
b_app1(pp+1);b_app(force);
b_app1(pp+2);
REDUCE(pp,3,stmt,-2,131);
}


}
#endif


#if FCN_CALLS
SRTN R_unop(VOID)
{


if(cat1==expr)SQUASH(pp,2,expr,-2,33);/* ``|@r !flag|'' */


}
#endif


#if FCN_CALLS
SRTN R_unorbinop(VOID)
{


if(cat1==expr)/* ``|@r +1.0|'' */
{
b_app(0173);b_app1(pp);b_app(0175);
b_app1(pp+1);
REDUCE(pp,2,expr,-2,140);
}
else if(cat1==binop)
{
b_app(math_bin);
b_app1(pp);
b_app(0173);b_app1(pp+1);b_app(0175);
b_app(0175);/* End |math_bin| */
REDUCE(pp,2,binop,-1,151);
}


else if(cat1==comma||cat1==rpar)SQUASH(pp,1,expr,-2,141);/* ``|@r \
*,|'' or ``|@r *)|'' */


}
#endif


#if FCN_CALLS
SRTN R_slash_like(VOID)
{

if(cat1==slash_like)
{/* The slash already has braces around it (appended by \FWEAVE).ac */
b_app1(pp);

{
b_app(0134);b_app(054);
}

;
b_app1(pp+1);
REDUCE(pp,2,slashes,-1,1801);
}
else if(cat1==expr&&cat2==slash_like)
SQUASH(pp,3,slashes,-1,1802);


}
#endif


#if FCN_CALLS
SRTN R_binop(VOID)
{


if(cat1==binop)/* ``|@r / /|'' */
{
sixteen_bits tok;

tok= **pp->trans;

if(tok==(sixteen_bits)057&&(**(pp+1)->trans==tok))

{
b_app(0173);
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app1(pp+1);
b_app(0175);
REDUCE(pp,2,slashes,-1,180);
}


else
{
b_app(math_bin);b_app1(pp);
b_app(0173);b_app1(pp+1);b_app(0175);
b_app(0175);/* End |math_bin| */
REDUCE(pp,2,binop,-1,180);
}


}
else if(cat1==expr&&cat2==binop)/* ``|@r /dia/|'' */
{
sixteen_bits tok;

tok= **pp->trans;

if(tok==(sixteen_bits)057&&(**(pp+2)->trans==tok))

{
b_app(0173);
b_app1(pp);/* |'/'| */
b_app(0175);

make_underlined(pp+1);/* Index common block name. */
b_app1(pp+1);/* expr */

b_app(0173);
b_app1(pp+2);/* |'/'| */
b_app(0175);

REDUCE(pp,3,slashes,-1,9181);
}


}


}
#endif



text_pointer
indirect FCN((t))
text_pointer t C1("")
{
Token tok_value;

if(t==NULL)return t;

tok_value= **t;

if(tok_value<=tok_flag)return t;

if(tok_value>inner_tok_flag)tok_value-= (inner_tok_flag-tok_flag);

if(tok_value>tok_flag)
do
{
Token tok_value0= tok_value;

t= tok_start+(int)(tok_value-tok_flag);
tok_value= **t;

if(tok_value==tok_value0)return t;/* Emergency return; \
otherwise infinite loop. */
}
while(tok_value>tok_flag);

return t;
}


boolean
compare_text FCN((t0,t1))
text_pointer t0 C0("")
text_pointer t1 C1("")
{
token_pointer p0,p0_end,p1;

if(t0==NULL||t1==NULL)return NO;

t0= indirect(t0);t1= indirect(t1);

p0= *t0;p0_end= *(t0+1);
p1= *t1;

while(p0<p0_end)
{
if(*p0==072)return YES;/* Ends label */
if(*p0++!=*p1++)return NO;
}

return YES;
}


sixteen_bits
tok_val FCN((p))
scrap_pointer p C1("")
{
sixteen_bits tok_value;

tok_value= **(p->trans);

if(tok_value>inner_tok_flag)
tok_value-= (inner_tok_flag-tok_flag);

if(tok_value>tok_flag)
do
{
tok_value= **(tok_start+(int)(tok_value-tok_flag));
}
while(tok_value>tok_flag);

return tok_value;
}


#if FCN_CALLS
SRTN R_Rdo_like(VOID)
{


if(is_FORTRAN_(language))
{
if(cat1==for_like)/* \&{do} \&{while} */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,Rdo_like,0,9600);
}
else if(cat1==expr&&((cat2==expr&&cat3==binop)||cat2==if_like))
/* ``|@r do 10 i='' */
{
label_text_ptr[indent_level]= (pp+1)->trans;/* Pointer to \
			a |token_pointer|---namely, index into |tok_start|. */
b_app1(pp);
b_app(040);
b_app1(pp+1);/* Loop number. */
REDUCE(pp,2,Rdo_like,0,9601);/* Swallow only the loop number. */
}
else if(cat1==stmt)/* ``|@r do i=1,10;|'' */
{
loop_num[indent_level++]= ++max_loop_num;

b_app1(pp);/* \&{do} */
b_app(040);
b_app1(pp+1);/* $i=1,10;$ */
app_loop_num(max_loop_num);

b_app(indent);
REDUCE(pp,2,stmt,-2,9602);
}
}
/* \Ratfor. */
else if(cat1==stmt||(cat1==expr&&cat2==lbrace))/* ``|@r do i=1,10;|'' \
or ``|@r do i=1,10{|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,for_hd,0,9603);
}


}
#endif


#if FCN_CALLS
SRTN R_do_like(VOID)
{


if(cat1==stmt)
{
if(cat2==until_like)
{
found_until= YES;
SQUASH(pp,1,do_like,PLUS 2,9190);/* ``|@r repeat \
{} until ;|''; expand the \&{until}. */
}
else
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
b_app(force);

if(found_until&&cat2==stmt)/* Get here by expanding the \
\&{until}. */
{
found_until= NO;
b_app1(pp+2);REDUCE(pp,3,stmt,-2,9191);
}
else REDUCE(pp,2,stmt,-2,9192);/* ``|@r repeat {}|''; \
no bottom. */
}
}


}
#endif


#if FCN_CALLS
SRTN R_until_like(VOID)
{


SQUASH(pp,1,for_like,0,9195);


}
#endif


#if FCN_CALLS
SRTN R_if_like(VOID)
{


if(cat1==CASE_like)
{
b_app1(pp);b_app(040);b_app1(pp+1);/* |@r9 select case| */
REDUCE(pp,2,if_like,0,9196);
}
else
if(is_FORTRAN_(language))
{
if(cat1==expr)
{
boolean if_form;

if((if_form= BOOLEAN(cat2==built_in&&cat3==semi))||cat2==semi)
{/* ``|@n if(x) then;|''  or ``|@n where(x); |'' */
short n;/* Number to append. Things are annoying because the |@n if| \
and |@n where| statements aren't completely symmetrical. */

loop_num[indent_level++]= ++max_loop_num;

b_app1(pp);/* \&{if} */

{
b_app(0134);b_app(054);
}

;
b_app1(pp+1);/* $(x)$ */
b_app(040);

if(if_form)
{
n= 4;
b_app2(pp+2);/* \&{then}; */
}
else
{/* |@n where| */
n= 3;
b_app1(pp+2);/* semi */
}

app_loop_num(max_loop_num);
b_app(indent);
REDUCE(pp,n,stmt,-2,9800);
}
else if(cat2==stmt)/* ``|@n if(x) a=b;|'' */
{
b_app1(pp);/* \&{if} */

{
b_app(0134);b_app(054);
}

;
b_app1(pp+1);/* $(x)$ */
app(040);
b_app(cancel);
b_app1(pp+2);/* Statement */
REDUCE(pp,3,stmt,-2,9801);
}
else
{
b_app1(pp);

{
b_app(0134);b_app(054);
}

;
b_app1(pp+1);
REDUCE(pp,2,if_hd,0,9802);
}
}
}
/* RATFOR\ */
else
{
if(cat1==lpar&&cat2==expr&&cat3==rpar)/* ``|if(x)|'' */
{
b_app1(pp);
{
b_app(0134);b_app(054);
}

;b_app3(pp+1);
#if(0)
cmnt_after_IF= (cat4==ignore_scrap);/* Comment coming up? */
#endif
REDUCE(pp,4,IF_like,0,220);
}
}





}
#endif



SRTN
app_loop_num FCN((n))
int n C1("Loop number.")
{
char loop_id[100];

if(!block_nums)return;/* We're not supposed to number the blocks/loops. */

sprintf(loop_id,"\\Wblock{%d}",n);/* Output the block number. */

APP_STR(loop_id);
}


#if FCN_CALLS
SRTN R_go_like(VOID)
{


if(cat1==built_in)/* ``|@r go to|'' */
{
b_app1(pp);/* \&{go} */
b_app(040);
b_app1(pp+1);/* \&{to} */
REDUCE(pp,2,case_like,0,9850);/* \&{goto} */
}
else SQUASH(pp,1,expr,-2,9851);


}
#endif


#if FCN_CALLS
SRTN R_end_like(VOID)
{

if(cat1==Rdo_like||cat1==if_like)/* ``|@r end do|'' or ``|@r end if|'' */
{
b_app1(pp);/* \&{end} */
b_app(040);
b_app1(pp+1);/* \&{do} or \&{if} */
REDUCE(pp,2,endif_like,0,9860);/* Now turned into \&{enddo} or \
\&{endif} */
}
else
{
fcn_level--;
SQUASH(pp,1,END_like,-1,9861);/* \&{end} of function. */
}


}
#endif


#if FCN_CALLS
SRTN R_END(VOID)
{

{
if(cat1==program_like||cat1==struct_like)
{
b_app1(pp);b_app(040);b_app1(pp+1);

if(cat2==expr)
{
b_app(040);b_app1(pp+2);
REDUCE(pp,3,END_like,0,9860);
}
else
REDUCE(pp,2,END_like,0,9861);
}
else if(cat1==semi)
SQUASH(pp,2,END_stmt,-2,9862);
}


}
#endif


#if FCN_CALLS
SRTN R_endif_like(VOID)
{

{
short n;
boolean no_construct_name;

if((no_construct_name= BOOLEAN(cat1==semi))||(cat1==expr&&cat2==semi))
{
b_app(outdent);
b_app(force);

if(no_construct_name)
{
n= 2;
b_app2(pp);/* \&{endif}; or \&{enddo}; */
}
else
{/* Include \It{if-construct-name} */
n= 3;
b_app1(pp);b_app(040);b_app2(pp+1);
}

if(--indent_level<0)
indent_level= 0;

app_loop_num(loop_num[indent_level]);
REDUCE(pp,n,stmt,-2,9880);
}
}


}
#endif


#if FCN_CALLS
SRTN R_if_hd(VOID)
{


if(is_FORTRAN_(language))
{
if(cat1==stmt)
{
b_app1(pp);b_app(break_space);b_app1(pp+1);
REDUCE(pp,2,stmt,-2,9900);
}
}
else
{
if(cat1==stmt)/* ``|if(x) {}|'' */
{
b_app1(pp);/* ``|if(x)|'' */
indent_force;
b_app1(pp+1);/* ``|{}|'' */
b_app(outdent);
REDUCE(pp,2,IF_top,-1,233);
}
else if(cat1==IF_top&&cat2==else_like)
SQUASH(pp,1,if_hd,2,234);
}




}
#endif


#if FCN_CALLS
SRTN R_else_like(VOID)
{


if(is_FORTRAN_(language))
{
if(cat1==if_like)/* ``|@n else if|'' */
{
b_app1(pp);/* \&{else} */
b_app(040);
b_app1(pp+1);/* \&{if} */
REDUCE(pp,2,else_like,0,9910);/* \&{elseif} */
}
else if(cat1==semi)/* \&{else}; */
{
b_app(outdent);
b_app(force);
b_app2(pp);/* \&{else} or \&{elseif} */
app_loop_num(loop_num[indent_level-1]);
b_app(indent);
REDUCE(pp,2,stmt,-2,9911);
}
else if(cat1==expr&&cat2==built_in&&cat3==semi)/* ``|@n else if(x) \
then;|'' */
{
b_app(outdent);
b_app(force);

b_app1(pp);/* \&{elseif} */

{
b_app(0134);b_app(054);
}

;
b_app1(pp+1);/* $(x)$ */
b_app(040);
b_app2(pp+2);/* \&{then}; */
app_loop_num(loop_num[indent_level-1]);

b_app(indent);
REDUCE(pp,4,stmt,-2,9912);
}
}
/* \Ratfor\ */
else
{
if(cat1==if_like)/* ``|else if|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,if_like,0,235);
}
else if(cat1==stmt||cat1==lbrace||cat1==for_like||cat1==do_like)
SQUASH(pp,1,else_hd,0,236);/* ``|else {}|'' */
#if 0 /* The following puts simple statement on same line. */
else if(cat1==stmt)/* ``|else z;|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);
REDUCE(pp,2,ELSE_like,-1,237);
}
#endif
}




}
#endif


#if FCN_CALLS
SRTN R_stmt(VOID)
{


if(is_FORTRAN_(language)&&cat1==program_like)SQUASH(pp,1,functn,
PLUS 1,9960);
else if(cat1==stmt)
{
b_app1(pp);
b_app(break_space);
b_app(force);

b_app1(pp+1);REDUCE(pp,2,stmt,-2,250);
}
else if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-2,251);
}


}
#endif


#if FCN_CALLS
SRTN R_CASE(VOID)
{


if(is_FORTRAN_(language))
{
b_app(backup);
b_app1(pp);
REDUCE(pp,1,case_like,0,9258);
}
else SQUASH(pp,1,case_like,0,9259);


}
#endif


#if FCN_CALLS
SRTN R_case_like(VOID)
{

if(cat1==read_like)/* ``|@r call open|'' */
{
b_app1(pp);/* \&{call} */
b_app(040);
b_app1(pp+1);/* \&{close}, \&{open}, etc. */
REDUCE(pp,2,case_like,0,9260);
}
else if(cat1==semi)SQUASH(pp,2,stmt,-2,260);/* ``|@r return;|'' */
else if(cat1==colon)
{
b_app1(pp);APP_STR("\\Colon\\ ");
REDUCE(pp,2,tag,-1,261);
}


else if(cat1==expr&&cat2==semi)
{/* ``|@r return 1;|'' */
b_app1(pp);b_app(040);b_app2(pp+1);
REDUCE(pp,3,stmt,-2,262);
}
else if((cat1==expr||cat1==label)&&cat2==colon)
{/* ``|@r case 1:|'' */
b_app1(pp);b_app(040);b_app1(pp+1);
APP_STR("\\Colon\\ ");
REDUCE(pp,3,tag,-1,263);
}


}
#endif


#if FCN_CALLS
SRTN R_tag(VOID)
{


if(cat1==tag)/* ``|@r case 1: case 2:|'' */
{
b_app1(pp);b_app(force);
b_app(backup);
b_app1(pp+1);REDUCE(pp,2,tag,-1,270);
}
else if(cat1==stmt||cat1==END_like)/* ``|@r 10 continue;|'' */
{
boolean end_of_loop;

end_of_loop= NO;

/* Unwind indent levels for labeled loops. */
while(indent_level>0&&
compare_text(pp->trans,label_text_ptr[indent_level-1]))
{
--indent_level;
b_app(outdent);
end_of_loop= YES;
}

if(is_FORTRAN_(language)&&Fortran_label)
{/* ``|@n EXIT: continue'' */
b_app(force);
APP_STR("\\Wlbl{");b_app1(pp);app(0175);

}
else
{/* Label on separate line. */
b_app(big_force);
b_app(backup);
b_app1(pp);/* Tag (Includes colon.) */
b_app(force);
}

b_app1(pp+1);/* Stmt. */

if(end_of_loop)
app_loop_num(loop_num[indent_level]);

REDUCE(pp,2,cat1,-2,271);
}



}
#endif


#if FCN_CALLS
SRTN R_label(VOID)
{

if(cat1==colon)
{
b_app1(pp);
REDUCE(pp,2,label,0,9270);/* Swallow the colon. (Numerical \
statement labels won't have any.) Then, for all labels, we put a colon in \
during the next block. */
}
else if(cat1==stmt||cat1==END_like)
{
b_app1(pp);APP_STR("\\Colon\\ ");

if(is_FORTRAN_(language)&&Fortran_label)
b_app(cancel);

REDUCE(pp,1,tag,0,9271);/* Convert the label into a tag. Don't \
					swallow the statement. */
}


}
#endif


#if FCN_CALLS
SRTN R_semi(VOID)
{

if(is_RATFOR_(language)&&auto_semi)
{/* Just throw away semi. */
text_pointer t;

t= indirect(pp->trans);

if(**t==073)**t= 0;
SQUASH(pp,1,ignore_scrap,-1,9280);
}
else
{
b_app(040);b_app1(pp);REDUCE(pp,1,stmt,-2,280);
}


}
#endif


#if FCN_CALLS
SRTN R_common_like(VOID)
{

if(cat1==expr||cat1==slashes||cat1==semi)
/* ``|@r common x| or |@r common/dia/|'' */
{
b_app1(pp);
if(cat1!=semi)b_app(040);
b_app(indent);
REDUCE(pp,1,common_hd,0,9950);
}


}
#endif


#if FCN_CALLS
SRTN R_cmn_hd(VOID)
{


if(cat1==expr)SQUASH(pp,2,common_hd,0,9951);/* ``|@r common x|'' */
else if(cat1==slashes)/* ``|@r common/dia/|'' */
{
b_app1(pp);
b_app(040);
b_app1(pp+1);
b_app(040);
REDUCE(pp,2,common_hd,0,9952);
}
else if(cat1==comma)/* ``|@r common x,y|'' */
{
b_app2(pp);
b_app(040);
REDUCE(pp,2,common_hd,0,9953);
}
else if(cat1==semi)
{
b_app2(pp);
b_app(outdent);
REDUCE(pp,2,decl,-1,9954);/* ``|@r common x;|'' */
}


}
#endif


#if FCN_CALLS
SRTN R_read_like(VOID)
{


if(cat1==lpar&&cat2==expr&&cat3==rpar)/* |@r read(6,100)| */
{
b_app1(pp);

{
b_app(0134);b_app(054);
}

;
b_app3(pp+1);
b_app(040);
REDUCE(pp,4,read_hd,0,9960);
}
else if(cat1==expr&&cat2==comma)/* ``|@r TYPE 100, i'' */
{
b_app1(pp);
b_app(040);
b_app2(pp+1);
b_app(040);
REDUCE(pp,3,read_hd,0,9961);
}
else if(cat1==expr||cat1==unorbinop)/* ``|@r TYPE *|'' */
{
b_app1(pp);b_app(040);b_app1(pp+1);

if(cat2==expr)b_app(040);/* Takes care of |"TYPE 100 i"|. */

REDUCE(pp,2,read_hd,0,9962);
}
else if(cat1==semi)SQUASH(pp,1,read_hd,0,9963);



}
#endif


#if FCN_CALLS
SRTN R_rd_hd(VOID)
{

if(cat1==comma)/* ``|@r read(6,100),|'' */
{
b_app2(pp);
b_app(040);
REDUCE(pp,2,read_hd,0,9965);
}
else if(cat1==expr)
{
if(cat2==comma||cat2==semi)
SQUASH(pp,2,read_hd,0,9966);/* ``|@r write(6,100) i,j'' */
}
else if(cat1==semi&&cat2==read_like)/* Two I/O statements back-to-back. */
{
b_app1(pp);
b_app1(pp+1);
b_app(force);
b_app1(pp+2);
REDUCE(pp,3,read_like,0,9967);
}
else if(cat1==semi)
{
b_app1(pp);
b_app1(pp+1);
REDUCE(pp,2,stmt,-2,9968);
}


}
#endif


#if FCN_CALLS
SRTN R_implicit_like(VOID)
{

if(cat1==int_like||cat1==expr)/* ``|@r implicit integer|'' or \
					``|@r implicit none|'' */
{
b_app1(pp);
b_app(040);
b_app(indent);/* Start possible long declaration. */
REDUCE(pp,1,implicit_hd,0,9970);
}
else if(cat1==semi)/* ``|@r implicit_none;|''. */
{
b_app1(pp);
b_app(indent);
REDUCE(pp,1,implicit_hd,0,99700);
}


}
#endif


#if FCN_CALLS
SRTN R_imp_hd(VOID)
{

if(cat1==unorbinop&&cat2==expr)
{/* ``|@r implicit real*8|'' */
b_app1(pp);
b_app(0173);b_app2(pp+1);b_app(0175);

{
b_app(0134);b_app(054);
}

;
REDUCE(pp,3,implicit_hd,0,9971);
}
else if(cat1==expr)SQUASH(pp,2,implicit_hd,0,9972);/* ``|@r implicit \
	integer(a-h)|'' */
else if(cat1==comma||cat1==int_like)
{
b_app2(pp);

if(cat2!=unorbinop)
if(cat2==int_like)b_app(040);/* ``|@r implicit real x, \
integer i|'' */
else
{
b_app(0134);b_app(054);
}

;

REDUCE(pp,2,implicit_hd,0,9973);
}
else if(cat1==semi)SQUASH(pp,1,decl_hd,0,9974);/* ``|@r implicit \
	integer(a-h);|'' */


}
#endif


#if FCN_CALLS
SRTN R_assign_like(VOID)
{

if(cat1==expr&&cat2==built_in&&cat3==expr)/* ``|@r assign 100 to k|'' */
{
b_app1(pp);
b_app(040);
b_app1(pp+1);
b_app(040);
b_app1(pp+2);
b_app(040);
b_app1(pp+3);
REDUCE(pp,4,expr,0,9980);
}


}
#endif


#if FCN_CALLS
SRTN R_entry_like(VOID)
{

if(cat1==expr&&cat2==semi)/* ``|@r entry E(x);|'' */
{
b_app(big_force);
b_app(backup);b_app1(pp);b_app(040);b_app2(pp+1);b_app(force);
REDUCE(pp,3,stmt,-2,9990);
}
else if(cat1==(eight_bits)(language==FORTRAN_90?semi:colon))
{/* ``|@r9 contains:|'' */
b_app(big_force);
b_app(backup);b_app2(pp);b_app(force);

containing++;
#if(0)
b_app(indent);
#endif
REDUCE(pp,2,stmt,-2,9991);
}


}
#endif


#if FCN_CALLS
SRTN R_define_like(VOID)
{

if(cat1==expr)
{
b_app(force);
b_app(backup);b_app2(pp);b_app(force);
REDUCE(pp,2,ignore_scrap,-1,9995);
}


}
#endif


#if FCN_CALLS
SRTN R_no_order(VOID)
{

intermingle= YES;
b_app(force);
b_app1(pp);b_app(040);
REDUCE(pp,1,int_like,0,9996);



}
#endif


#if FCN_CALLS
SRTN R_built_in(VOID)
{

{
b_app1(pp);

{
b_app(0134);b_app(054);
}

;
REDUCE(pp,1,expr,-2,9998);
}


}
#endif


#if FCN_CALLS
SRTN R_newline(VOID)
{

SQUASH(pp,1,ignore_scrap,-1,9999);


}
#endif


SRTN
V_productions(VOID)
{
switch(pp->cat)
{
case expr:

break;
case stmt:

break;
}
}


SRTN
X_productions(VOID)
{
switch(pp->cat)
{
case expr:
{
if(cat1==expr)SQUASH(pp,2,expr,0,5);
else if(cat1==semi)
{
b_app1(pp);
REDUCE(pp,2,stmt,-1,6);
}
}

break;
case stmt:
{
if(cat1==stmt)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-1,250);
}
}

break;
}
}


SRTN
reduce FCN((j,k,c,d,n))
scrap_pointer j C0("")
short k C0("Number of items to be reduced.")
eight_bits c C0("Reduce to this type.")
short d C0("Move by this amount.")
RULE_NO n C1("Rule number.")
{
scrap_pointer i,i1;/* Pointers into scrap memory */

/* Store the translation. */
j->cat= c;j->trans= text_ptr;
j->mathness= (eight_bits)(4*last_mathness+ini_mathness);
freeze_text;

/* More stuff to the left, overwriting the $k$~items that have been \
reduced. */
if(k>1)
{
for(i= j+k,i1= j+1;i<=lo_ptr;i++,i1++)
{
i1->cat= i->cat;i1->trans= i->trans;
i1->mathness= i->mathness;
}

lo_ptr= lo_ptr-k+1;
}



if(pp+d>=scrp_base)pp= pp+d;
else pp= scrp_base;

;

#ifdef DEBUG

{
scrap_pointer k;/* pointer into |scrap_info| */



{
static RULE_NO last_rule= ULONG_MAX;
static int ncycles= 0;

if(n&&n==last_rule)
{
if(ncycles++>MAX_CYCLES)
{
outer_char temp[MAX_CYCLES];


if(
nsprintf(temp,OC("Infinite production loop, rule %lu"),1,n)>=(int)(MAX_CYCLES))OVERFLW("temp","");
CONFUSION("reduce",temp);
}
}
else
{
last_rule= n;
ncycles= 0;
}
}



if(tracing==2)
{
printf("%5lu",n);/* The rule number. */

if(in_prototype)
printf(".%i",in_prototype);

printf(": ");

for(k= scrp_base;k<=lo_ptr;k++)
{
if(k==pp)putxchar('*');else putxchar(' ');

if(k->mathness%4==yes_math)putxchar('+');
else if(k->mathness%4==no_math)putxchar('-');

prn_cat(k->cat);

if(k->mathness/4==yes_math)putxchar('+');
else if(k->mathness/4==no_math)putxchar('-');
}

if(hi_ptr<=scrp_ptr)printf("...");/* indicate that more is \
			coming */


{
printf(" ==\"");
if(lo_ptr>scrp_base)
{/* The second-to-last scrap. */
prn_text(indirect((lo_ptr-1)->trans));
printf("\" \"");
}
prn_text(indirect(lo_ptr->trans));/* Last scrap. */
puts("\"");
}



}
}

;
#endif /* |DEBUG| */

pp--;/* we next say |pp++| */
}


SRTN
squash FCN((j,k,c,d,n))
scrap_pointer j C0("")
short k C0("Number to be squashed.")
eight_bits c C0("Make it this type.")
short d C0("Move by this amount.")
RULE_NO n C1("Rule number.")
{
scrap_pointer i;/* pointers into scrap memory */

if(k==1)
{
j->cat= c;

if(pp+d>=scrp_base)pp= pp+d;
else pp= scrp_base;

;

#ifdef DEBUG

{
scrap_pointer k;/* pointer into |scrap_info| */



{
static RULE_NO last_rule= ULONG_MAX;
static int ncycles= 0;

if(n&&n==last_rule)
{
if(ncycles++>MAX_CYCLES)
{
outer_char temp[MAX_CYCLES];


if(
nsprintf(temp,OC("Infinite production loop, rule %lu"),1,n)>=(int)(MAX_CYCLES))OVERFLW("temp","");
CONFUSION("reduce",temp);
}
}
else
{
last_rule= n;
ncycles= 0;
}
}



if(tracing==2)
{
printf("%5lu",n);/* The rule number. */

if(in_prototype)
printf(".%i",in_prototype);

printf(": ");

for(k= scrp_base;k<=lo_ptr;k++)
{
if(k==pp)putxchar('*');else putxchar(' ');

if(k->mathness%4==yes_math)putxchar('+');
else if(k->mathness%4==no_math)putxchar('-');

prn_cat(k->cat);

if(k->mathness/4==yes_math)putxchar('+');
else if(k->mathness/4==no_math)putxchar('-');
}

if(hi_ptr<=scrp_ptr)printf("...");/* indicate that more is \
			coming */


{
printf(" ==\"");
if(lo_ptr>scrp_base)
{/* The second-to-last scrap. */
prn_text(indirect((lo_ptr-1)->trans));
printf("\" \"");
}
prn_text(indirect(lo_ptr->trans));/* Last scrap. */
puts("\"");
}



}
}

;
#endif /* |DEBUG| */

pp--;/* we next say |pp++| */
return;
}

for(i= j;i<j+k;i++)b_app1(i);

reduce(j,k,c,d,n);
}


text_pointer
translate FCN((mode0))
PARSING_MODE mode0 C1("")
{
LANGUAGE saved_language= language;
scrap_pointer i,/* index into |cat| */
j;/* runs through final scraps */

translate_mode= mode0;

pp= scrp_base;lo_ptr= pp-1;hi_ptr= pp;


#ifdef DEBUG
if(tracing==2)
{
CLR_PRINTF(warning,
("\nTracing after l. %u (language = %s):  ",
cur_line,languages[lan_num(language)]));
mark_harmless;

if(loc>=cur_buffer+OUT_WIDTH)
{
printf("...");
ASCII_write(loc-OUT_WIDTH,OUT_WIDTH);
}
else ASCII_write(cur_buffer,loc-cur_buffer);

puts("");
}
#endif /* |DEBUG| */

;

{
in_prototype= indented= NO;

WHILE()
{


if(lo_ptr<pp+3)
{
while(hi_ptr<=scrp_ptr&&lo_ptr!=pp+3)
{
(++lo_ptr)->cat= hi_ptr->cat;lo_ptr->mathness= (hi_ptr)->mathness;
lo_ptr->trans= (hi_ptr++)->trans;
}

for(i= lo_ptr+1;i<=pp+3;i++)i->cat= 0;
}

;

if(tok_ptr+8>tok_m_end)
{
if(tok_ptr>mx_tok_ptr)mx_tok_ptr= tok_ptr;
OVERFLW("tokens","tw");
}

if(text_ptr+4>tok_end)
{
if(text_ptr>mx_text_ptr)mx_text_ptr= text_ptr;
OVERFLW("texts","x");
}

if(pp>lo_ptr)
break;


{
if(cat0==language_scrap)
{
language= lan_enum(get_language(pp->trans));/* Get language from \
language~\#. */
ini0_language();/* Reset params like |auto_semi|. */
SQUASH(pp,1,ignore_scrap,-1,0);
}
else if(cat1==ignore_scrap)SQUASH(pp,2,cat0,-2,0);/*Gobble an |ignore_scrap|. */
else switch(language)
{
case NO_LANGUAGE:
CONFUSION("match production","Language isn't defined");

case C:
case C_PLUS_PLUS:
C_productions();
break;

case RATFOR:
case RATFOR_90:
if(!RAT_OK("(translate)"))
CONFUSION("match production",
"Language shouldn't be Ratfor here");

case FORTRAN:
case FORTRAN_90:
R_productions();
break;

case LITERAL:
V_productions();
break;

case TEX:
X_productions();
break;

case NUWEB_OFF:
case NUWEB_ON:
CONFUSION("match a production","Invalid language");
}

pp++;/* if no match was found, we move to the right and try again. */
}

;
ini_mathness= cur_mathness= last_mathness= maybe_math;
}
}



{
EXTERN int math_flag;



#ifdef DEBUG
{
scrap_pointer scrap0= scrp_base;

while(scrap0->cat==ignore_scrap)scrap0++;

if(lo_ptr>scrap0&&tracing==1)
{
CLR_PRINTF(warning,
("\nIrreducible scrap sequence in %s:",
MOD_TRANS(module_count)));
mfree();
mark_harmless;

for(j= scrap0;j<=lo_ptr;j++)
{
printf(" ");prn_cat(j->cat);
}
}
}
#endif /* |DEBUG| */

;

for(j= scrp_base;j<=lo_ptr;j++)
{
if(j!=scrp_base)app(040);/* Separate scraps by blanks. */

if((j->mathness%4==yes_math)&&math_flag==NO)app(044);

if((j->mathness%4==no_math)&&math_flag==YES)
{app(040);app(044);}

app1(j);

if((j->mathness/4==yes_math)&&math_flag==NO)app(044);

if((j->mathness/4==no_math)&&math_flag==YES)
{app(044);app(040);}

if(tok_ptr+6>tok_m_end)OVERFLW("tokens","tw");
}

freeze_text;
}

;

language= saved_language;
return text_ptr-1;
}


#endif /* Part 2 */








