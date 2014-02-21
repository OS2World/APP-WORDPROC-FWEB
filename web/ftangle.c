#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06."  \
  COMMAND LINE: "web/ftangle web/ftangle -A -# --F -= 1.53/web/ftangle.c" \
  RUN TIME: "Saturday, September 23, 1995 at 16:17." \
  WEB FILE:    "web/ftangle.web" \
  CHANGE FILE: (none)
#endif
#define _FTANGLE_h  
#define _FWEB_h   \

#define semi  01 /* Kludge! */ \

#define SILENT  (boolean)NO
#define COMPLAIN  (boolean)YES \

#define OUTER_MACRO  0xFF
#define OUTER_UNMACRO  0xFE
#define UNDEFINED_MACRO  0xFD \

#define MAX_XLEVELS  200 \

#define equiv  equiv_or_xref /* Info corresponding to names. */
#define EQUIV  ASCII HUGE*/* For casting into the above field. */ \
 \
/* Note that the following function retrieves not only regular \WEB\ \
macros, but also built-in functions. */
#define MAC_LOOKUP(cur_val)(cur_val<MODULE_NAME? \
(text_pointer)(name_dir+(cur_val))->equiv:NULL) \

#define macro  0 /* For appending a macro; distinguishes from a module. */ \
 \
 \
/* The following are the values of the |macro_type| field of \
|name_pointer|s. */
#define NOT_DEFINED  0
#define DEFERRED_MACRO  1 /* Numbers chosen so that |DEFERRED_MACRO + \
	scanning_defn| gives the two choices. */
#define IMMEDIATE_MACRO  2
#define FILE_NAME  3 /* Used to prevent truncations from affecting file names. */ \

#define MAKE_RECURSIVE  052 /* To allow a WEB macro to be recursive, preface its \
	definition by this symbol, as in `\.{@m *R R}'.  (Recursive macros \
	are not presently implemented.) */ \

#define AUTO_INSERT  0133
#define END_AUTO_INSERT  0135 \
 \
/* Guard against overflow of the macro buffer. */
#define MCHECK(n,reason)if(mp+(n)>macrobuf_end) \
mbuf_full((unsigned long)(n),(outer_char*)reason) \

#define RST_LAST_EXPR  {plast_char= last_char;last_xpr_overflowed= NO;} \

#define INDENT_SIZE  2 /* Number of columns to indent for each level of \
beautified Ratfor output. (Put into style file?) */ \

#define NO_INDENT  0
#define INDENT  2 \

#define OUT_FILE  outp_file[lan_num(out_language)]/* Output of \FTANGLE. */ \
 \
/* The next may not be used. */
#define C_printf(c,a) \
{ \
if(!out_file)open_out(OC(""),YES); \
if(fprintf(out_file,c,a)<0)out_error(OC("fprintf")); \
} \

#define NOT_CONTINUATION  0
#define CONTINUATION  1 \

#define N_STRBUF  150 \

#define send_new_line  RST_LAST_EXPR flush0();PUTC('\n') \

#define NEWLINE_TO_FORTRAN(continuation_flag) \
flush_out(YES);/* Write out the buffer. */ \
rst_out(continuation_flag)/* Reinitialize the buffer with no \
continuation character. */ \

#define TO_BUFFER(type) \
if(!nuweb_mode) \
{ \
px= t_style.meta[lan_num(language)].msg.type; \
STRCPY(outp_buf,px); \
out_pos= STRLEN(px); \
} \

#define CUR_BUF  (pai->text_buf[pai->ilevel]) \

#define module_flag  (sixteen_bits)max_texts /* Final |text_link| in module \
						replacement texts. */ \

#define cur_end  cur_state.end_field /* Current ending location in |tok_mem|. */
#define cur_byte  cur_state.byte_field /* Location of next output byte in |tok_mem|. */
#define cur_name  cur_state.name_field /* Pointer to current name being expanded. */
#define cur_repl  cur_state.repl_field /* Pointer to current replacement text. */
#define cur_mod  cur_state.mod_field /* Current module number being expanded. */ \

#define cur_language  cur_state.language /* Current language. */
#define cur_global_language  cur_state.global_params.Language \
/* Global language for this level. */ \
 \
/* Current flags. */
#define cur_params  cur_state.params /*  Local flags. */
#define cur_global_params  cur_state.global_params /*  Global flags. */ \
 \
/* Current macro buffer params. */
#define macrobuf  cur_state.macro_buf
#define macrobuf_end  cur_state.macro_buf_end \

#define UNNAMED_MODULE  0 \

#define UNNAMED_MOD  "unnamed"
#define flush_buffer()C_putc('\n') \

#define NEWLINE  puts("") \

#define BP_MARKER  1 \

#define PROPER_END(end) \
end= (np+1)->byte_start; \
if(*end==BP_MARKER&&np!=npmax)end= ((BP*)end)->byte_start \

#define MAX_ID_LENGTH  32 /* Truncated identifiers can't be longer than this. */ \

#define GLOBAL_SCOPE  YES
#define LOCAL_SCOPE  NO \

#define CHECK_OPEN  if(!out_file)open_out(OC(""),GLOBAL_SCOPE) \

#define OUT_OP(s)out_op(OC(s))
#define OUT_STR(s)out_str(OC(s)) \

#define F_OP(op77,op88)(Fortran88?op88:op77) \

#define stringg  (eight_bits)02 /* Extended ASCII alpha should not appear. (The funny \
	spelling is to avoid conflict with the VAX' \.{stdlib}.) */
#define constant  (eight_bits)03 /* Numerical constant. */
#define begin_Xmeta  or_or
#define end_Xmeta  star_star
#define cdir  (eight_bits)06 /* Brackets compiler directive.. */
#define colon_colon  (eight_bits)011 /* \Cpp\ and \Fortran--90: `$\CF$'. */ \

#define join  (eight_bits)0177 /* |ASCII| delete will not appear. */ \

#define ID0  0200 /* $128 =$ end of the 7-bit ASCII codes. */
#define TOKEN1(a)((a)<ID0)/* Is |a|~a single-byte token? */ \

#define MACRO_ARGUMENT  0377 /* See the related definition and discussion of \
				|MOD0|. */
#define BASE2  0400 /* |0xFF + 1 = 0x100 = 256| */ \

#define MODULE_NAME  10240 /* |024000= 10240 = (0250-0200)*0400| */
#define MODULE_NUM  20480 /* |050000 = 20480 = (0320-0200)*0400| */
#define LINE_NUM  53248L /* |0150000==0320*0400| */ \

#define IDENTIFIER(left,right) \
((sixteen_bits)(((left)-ID0)*BASE2+(sixteen_bits)(right))) \
/* Construct two-byte token out of its constituents. */ \

#define LEFT(a,id)((eight_bits)(((a)/BASE2+(id))))/* Make left-hand byte out of \
					|sixteen_bits|. */
#define RIGHT(a)((eight_bits)(((a)%BASE2)))/* Make right-hand byte. */ \

#define ignore  0 /* Control code of no interest to \.{TANGLE}. */ \

#define begin_comment0  (eight_bits)0376 /* Sent from |input_ln|; marker for long comment. */
#define begin_comment1  (eight_bits)0375 /* As above; marker for short comment. */ \

#define module_number  (eight_bits)0201 /* Code returned by |get_output| for mod.\ numbers. */
#define identifier  (eight_bits)0202 /* Code returned by |get_output| for identifiers. */
#define id_keyword  (eight_bits)0203 /* As above, but for expandable keyword. */ \

#define L_switch  (eight_bits)0257 /* Control code for `\.{@L}'. */
#define begin_FORTRAN  (eight_bits)0260
#define begin_RATFOR  (eight_bits)0261
#define begin_C  (eight_bits)0262
#define begin_LITERAL  (eight_bits)0263 \

#define verbatim  (eight_bits)0264 /* Can't be~|02| as for \.{fweave}, because \
				|stringg| is defined to be that. */ \

#define invisible_cmnt  (eight_bits)0265 /* Control code for `\.{@\%}'. */
#define compiler_directive  (eight_bits)0266 /* No longer used. */
#define Compiler_Directive  (eight_bits)0267 /* Control code for `\.{@?}'. */
#define no_index  (eight_bits)0300 /* Control code for `\.{@-}'. */
#define yes_index  (eight_bits)0301 /* Control code for `\.{@+}'. */ \

#define ascii_constant  (eight_bits)0302 /* Control code for `\.{@'}'. */
#define begin_vcmnt  (eight_bits)0303 /* Control code for `\.{@\slashstar}'. */
#define big_line_break  (eight_bits)0304 /* Control code for `\.{@\#}'. */ \

#define begin_bp  (eight_bits)0305
#define insert_bp  (eight_bits)0306 \

#define begin_meta  (eight_bits)017 /* Control code for |"@("|. */
#define end_meta  (eight_bits)027 \

#define TeX_string  (eight_bits)0307
#define xref_roman  (eight_bits)0310
#define xref_typewriter  (eight_bits)0311
#define xref_wildcard  (eight_bits)0312 \

#define control_text  (eight_bits)0313 /* Control code for `\.{@t}', `\.{@\^}', etc. */ \

#define begin_nuweb  (eight_bits)0314
#define no_mac_expand  (eight_bits)0315 /* Control code for `\.{@\~}' */
#define set_line_info  (eight_bits)0316 /* Expt'l control code for `\.{@Q}'. */ \

#define formatt  (eight_bits)0320 /* Control code for `\.{@f}'. */ \

#define limbo_text  (eight_bits)0323 /* Control code for `\.{@l}'. */
#define op_def  (eight_bits)0324 /* Control code for `\.{@v}'. */
#define macro_def  (eight_bits)0325 /* Control code for `\.{@W}'. */ \

#define ignore_defn  (eight_bits)0327 /* Stuff to here should be ignored when scanning defn. */ \

#define new_output_file  (eight_bits)0331 /* Control code for `\.{@o}'. */ \

#define definition  (eight_bits)0332 /* Control code for `\.{@d}'. */
#define undefinition  (eight_bits)0333 /* Control code for `\.{@u}'. */
#define WEB_definition  (eight_bits)0334 /* Control code for `\.{@m}'. */ \

#define m_ifdef  (eight_bits)0335
#define m_ifndef  (eight_bits)0336
#define m_if  (eight_bits)0337
#define m_else  (eight_bits)0340
#define m_elif  (eight_bits)0341
#define m_endif  (eight_bits)0342
#define m_for  (eight_bits)0343
#define m_endfor  (eight_bits)0344
#define m_line  (eight_bits)0345
#define m_undef  (eight_bits)0346 \

#define end_of_buffer  (eight_bits)0347 \

#define begin_code  (eight_bits)0350 /* Control code for `\.{@a}'. */
#define module_name  (eight_bits)0351 /* Control code for `\.{@<}'. */ \

#define new_module  (eight_bits)0352 /* Control code for `\.{@\ }' and `\.{@*}'. */ \

#define MAYBE_SET_OUTPUT(l)if(last_char!=0174)set_output_file(l) \

#define RETURN(pcode)return(eight_bits)pcode \

#define compress(c)if(loc++<=limit)return(eight_bits)(c)
#define Fcompress(c)if(is_FORTRAN_(language)&&loc<limit) \
return(eight_bits)(c)/* Not used. */
#define STOP  (boolean)YES
#define DONT_STOP  (boolean)NO \
 \
/* Add a token to |token_mem|. */
#define app_repl(c){if(tok_ptr==tok_m_end) \
OVERFLW("tokens","tt"); \
*tok_ptr++= (eight_bits)(c);} \

#define BP_BUF_SIZE  (13+MAX_ID_LENGTH)/* The print command below generates a \
	string of the form ``\.{\_BP(99999,"\dots")}'', where the \dots\ \
	correspond to |name_of|, whose maximum length is |MAX_ID_LENGTH|. */ \

#define N_IDBUF  100
#define MAX_LEVEL  20 \
 \
/* We have to tell |scan_text| whether or not to expand the text it is \
reading. */
#define EXPAND  YES \

#define DEF_OR_NDEF(flag) \
found_else= NO; \
if(!expand) \
{ \
to_endif(m_ifdef); \
goto next_macro_token; \
} \
else \
{ \
text_pointer m; \
if((next_control= get_next())!=identifier) \
{ \
 \
err0_print(ERR_T,OC("Expected identifier after @#ifdef \
or @#ifndef; assuming not defined"),0); \
if_switch= NO; \
} \
else if_switch=  \
BOOLEAN(flag((m= MAC_LOOKUP(ID_NUM(id_first,id_loc)))!=NULL \
&&!(m->built_in))); \
/* Is the identifier defined as a WEB macro? */ \
if(if_switch) \
{ \
GET_LINE;/* Skip possible comment at end of \
\.{@\#ifdef} or \.{@\#ifndef}. */ \
scan_text(text_type,p,if_switch); \
} \
else \
{ \
expand= NO;to_else(); \
 \
if(next_control!=m_endif) \
{ \
scanned_if= YES; \
goto next_macro_token; \
} \
else \
{ \
next_control= ignore; \
expand= YES; \
GET_LINE;/* Skip possible comment after \
\.{@\#endif}. */ \
break; \
} \
} \
} \
 \
/* The following were changed from |TRUE| and |FALSE| to avoid difficulties \
with the VAX' \.{cc}.  */
#define M_TRUE  
#define M_FALSE  ! \

#define GET_LINE   \
if(!from_buffer) \
if(language!=TEX) \
get_line() \

#define OUT_OF_ORDER(cmd)out_of_order((outer_char*)cmd) \

#define SPCS_AFTER_CMNT  1 /* For beautification of the Ratfor error messages. */ \




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







#include "map.h" /* Relations between style file keywords and internal arrays. */




/* Precedence of the various operators. */
typedef enum{BAD_TOKEN,OR_OR,AND_AND,BIT_OR,BIT_XOR,BIT_AND,LOG_EQ,LOG_LT,
BIT_SHIFT,PLUS_MINUS,TIMES,EXP,UNARY,HIGHEST_UNARY}PRECEDENCE;

/* An operator, together with its precedence. */
typedef struct
{
eight_bits token;
PRECEDENCE precedence;
}OP;

/* The actual data value. */
typedef union
{
long i;/* All integers are long, to humor the pc people. */
double d;/* We handle just one floating-point type. */
sixteen_bits id;/* An identifier token. */
OP op;
}VALUE;

/* Type of the data value. The relative order must be preserved here, \
because it is used in the type promotion routine |promote|. */
typedef enum{Int,Double,Id,Op}TYPE;

/* Complete data structure for the token; includes links to the next and \
last |VAL| structures. */
typedef struct val
{
VALUE value;/* The actual data value or operator token. */
TYPE type;/* The type of value stored in |value|. */
struct val HUGE*last,HUGE*next;/* Link to the last and next values. */
}VAL;




typedef struct
{
sixteen_bits token[MAX_XLEVELS];
int level;
}XIDS;



/* We'll manage the buffers with a structure.  That way, we can use a \
standard routine |store| to add a byte. */
typedef struct
{
outer_char HUGE*start,HUGE*pos,HUGE*end;
}TEXT_BUF;

/* One parenthesis level is described like this. */
typedef struct
{
int ilevel;/* Current buffer (index) level. */
TEXT_BUF HUGE*HUGE*text_buf;/* Temporary storage for the index tokens. */
TEXT_BUF HUGE*last_buf;/* Buffer of the previous level. */
}PAREN_LEVEL;

EXTERN PAREN_LEVEL HUGE*paren_level,HUGE*paren_level_end,HUGE*pai;

EXTERN int rparen TSET(NO);/* Was the last character a right paren? */




typedef struct
{
eight_bits HUGE*tok_start;/* Pointer into |tok_mem| (for a module or \
regular macro).  For an internal macro, points to the internal function. */
sixteen_bits text_link;/* Relates replacement texts  (0 for a macro). */
boolean Language;/* Which language referenced this name. */
eight_bits nargs;/* Number of macro arguments. */
unsigned moffset:8,/* Offset to macro replacement text from start. */
recursive:1,/* Is this macro allowed to be recursive? */
var_args:1,/* Can it have variable number of arguments? */
module_text:1,/* Distinguishes from preprocessor fragment. */
built_in:1;/* Is it a built-in function (internal macro)? */
}text;

typedef text HUGE*text_pointer;



typedef struct{
eight_bits HUGE*end_field;/* Ending location of replacement text. */
eight_bits HUGE*byte_field;/* Present location within replacement text. */
name_pointer name_field;/* |byte_start| index for text being output. */
text_pointer repl_field;/* |tok_start| index for text being output. */
sixteen_bits mod_field;/* Module number, or zero if not a module. */
PARAMS global_params,params;/* Various flags. */
eight_bits HUGE*macro_buf,HUGE*macro_buf_end;/* Current macro buffer. */
}output_state;

typedef output_state HUGE*stack_pointer;



#if(0)
IN_COMMON boolean truncate_ids;/* Truncate identifers? */
IN_COMMON unsigned short tr_max[];/* Truncate to this length. */
IN_COMMON name_pointer npmax;/* |name_ptr - 1|. */
#endif

/* Back-pointer structure points back to the original name in |name_dir|. */
typedef struct Bp
{
ASCII c;/* Dummy byte that always remains~|BP_MARKER|. */
LANGUAGE Language;
CONST ASCII HUGE*byte_start,HUGE*byte_end;/* Points to original, \
untruncated name. */
struct Bp HUGE*next;/* Links to next back-pointer structure, in \
case a truncated name came from more than one original name. */
struct Trunc HUGE*Root;
}BP;

/* Info about a truncated identifier. */
typedef struct Trunc
{
boolean Language;/* All languages associated with this name. */
size_t num[NUM_LANGUAGES];
/* \# of instances of the truncated name. */
ASCII HUGE*id,HUGE*id_end;/* Truncated variable name. */
BP HUGE*first,HUGE*last;/* First and last back-pointer structures. */
struct Trunc HUGE*next;/* Next structure in truncated chain. */
}TRUNC;



typedef struct
{
ASCII HUGE*start,HUGE*end;
}TEMPLATE;




#include "t_type.h" /* Function prototypes for \FTANGLE. */




/* The shorter length here is primarily to keep the stack under control. \
Now that |N_MSGBUF| is used  dynamically, maybe this statement isn't \
necessary. */
#ifdef SMALL_MEMORY
#define N_MSGBUF 2000
#else
#define N_MSGBUF 10000
#endif





IN_COMMON STMT_LBL max_stmt;/* See \.{common.web}. */

EXTERN sixteen_bits outp_line[NUM_LANGUAGES]
#ifdef _FTANGLE_h
#if(part == 0 || part == 1)
= {1,1,1,1,1,1,1,1}
#endif /* |part == 1| */
#endif /* |_FTANGLE_h| */
;




EXTERN int indnt_size SET(INDENT_SIZE);
/* So we can interface to \.{rat77.web}. */

EXTERN outer_char HUGE*last_char,HUGE*last_end;/* Dynamic array. */
EXTERN outer_char HUGE*plast_char;/* Current position in |last_char|. */
EXTERN BUF_SIZE max_expr_chars;/* Allocated length of |last_char|. */

EXTERN boolean last_xpr_overflowed SET(NO);

EXTERN int indent_level SET(0);/* Current state of Ratfor output. */



/* --- Output buffer for C --- */
EXTERN outer_char HUGE*C_buffer,HUGE*pC_end;/* Dynamically allocated. */
EXTERN outer_char HUGE*pC_buffer;/* Current position. */
EXTERN BUF_SIZE C_buf_size;/* Length of dynamic buffer array. */

/* --- String positions in that buffer --- */
EXTERN outer_char HUGE*split_pos;/* Current position. */

/* --- Output buffer for \TeX\ --- */
EXTERN outer_char HUGE*X_buffer,HUGE*pX_end;/* Dynamically allocated. */
EXTERN outer_char HUGE*pX_buffer;/* Current position. */
EXTERN BUF_SIZE X_buf_size;/* Length of dynamic buffer array. */



EXTERN int rst_pos SET(0);/* The position immediately after resetting. */
EXTERN int out_pos SET(0);/* Current position in \Fortran's output buffer. */
EXTERN boolean in_string SET(NO);/* Faster version of the output state. */
EXTERN boolean in_constant SET(NO);/* Ditto. */
EXTERN boolean started_vcmnt SET(NO);
EXTERN boolean meta_mode SET(NO);



IN_COMMON outer_char outp_buf[];/* \Fortran's output buffer. */
IN_COMMON int nbuf_length;/* Maximum of above, for breaking. */
EXTERN boolean out_at_beginning SET(YES);/* Flag for the output buffer. */



EXTERN long max_texts;/* Number of replacement texts, must be $< 10240$. */
EXTERN text HUGE*text_info;/* Dynamic array. */
EXTERN text_pointer text_end;/* End of above. */

EXTERN long dtexts_max;/* Number of deferred replacement texts. */
EXTERN text HUGE*txt_dinfo;/* Dynamic array. */
EXTERN text_pointer textd_end;

EXTERN text_pointer text_ptr,txt_dptr;/* First unused position in |text_info| \
					and in |txt_dinfo|. */

EXTERN long max_toks;/* Number of bytes in compressed code. */
EXTERN eight_bits HUGE*tok_mem;/* Dynamic array. */
EXTERN eight_bits HUGE*tok_m_end;

EXTERN long max_dtoks;/* Number of bytes in deferred macros. */
EXTERN eight_bits HUGE*tok_dmem;/* Dynamic array. */
EXTERN eight_bits HUGE*tokd_end;

EXTERN eight_bits HUGE*tok_ptr,HUGE*tok_dptr;/* First unused position in \
			|tok_mem| and in |tok_dmem|. */
EXTERN eight_bits HUGE*mx_tok_ptr,HUGE*mx_dtok_ptr;/* Largest value \
	assumed by |tok_ptr|  and |tok_ptrd|; for statistics. */

EXTERN text_pointer macro_text;




EXTERN text_pointer last_unnamed;/* Most recent replacement text of \
					unnamed module. */



EXTERN output_state cur_state;/* |cur_end|, |cur_byte|, |cur_name|, \
	|cur_repl|, |cur_mod|, |cur_global_language|, and |cur_language|. */

EXTERN long stck_size;/* Number of simultaneous levels of macro expansion. */
EXTERN output_state HUGE*stack;/* Dynamic array: Info for non-current levels. */
EXTERN stack_pointer stck_end;/* End of |stack|. */
EXTERN stack_pointer stck_ptr;/* First unused loc.\ in the output state stack. */



/* These harmlessly redefine stuff in \.{typedefs.web}. It's a bit shaky, but \
it seems to work. One was running out of lower-order tokens. */

#undef begin_format_stmt
#define begin_format_stmt (eight_bits)014

#undef end_format_stmt
#define end_format_stmt (eight_bits)015

EXTERN long cur_val;/* Additional information corresponding to output \
	token. This must be \It{signed} (and capable of handling a full \
	|sixteen_bits|) because of trickery involving output of the module \
	numbers. */



EXTERN eight_bits sent;



IN_RATFOR sixteen_bits id_function,id_program,id_subroutine;



EXTERN sixteen_bits cur_mod_no SET(0);



EXTERN OUTPUT_STATE out_state;/* Current status of partial output. */
EXTERN boolean protect;/* Current status of partial output. */
EXTERN boolean copying_macros SET(NO);/* Outputting outer macros? */
EXTERN boolean in_cdir SET(NO);/* Inside a compiler directive? */



EXTERN TRUNC sh;



EXTERN boolean mac_protected SET(NO);/* Are we between left quotes, so macros \
				shouldn't be expanded? */
EXTERN boolean send_rp SET(NO);/* Takes on a value only for |language == \
	RATFOR || language==FORTRAN|, when it's used to enclose the rhs of \
	an operator like \.{*=}. */

EXTERN boolean in_version SET(NO);/* For the initial header of output file. */
EXTERN T_META*pmeta;



EXTERN OPEN_FILE HUGE*open_file,HUGE*open_file_end,HUGE*last_file;
EXTERN BUF_SIZE num_files;/* Allocated length of |open_file|. */



EXTERN LINE_NUMBER nearest_line SET(0);



IN_STYLE eight_bits ccode[128];/* Meaning of a char following '\.{@}'. */



EXTERN boolean comment_continues SET(NO);/* Are we scanning a comment? */



EXTERN name_pointer cur_module SET(NULL);/* name of module just scanned */
EXTERN ASCII c;/* the current character for |get_next| */
EXTERN boolean strt_cmnt;
EXTERN boolean strt_point_cmnt;
EXTERN boolean suppress_newline;/* For scanning past invisible comments. */
EXTERN boolean eat_blank_lines;/* For `\.{@\%\%}'. */
EXTERN boolean no_expand SET(NO);/* For use with `\.{@\~}. */
EXTERN boolean insrt_line SET(NO);/* For inserting line number after \.{@\%}. */



EXTERN boolean starts_with_0,hex_constant,bin_constant,floating_constant;



EXTERN text_pointer cur_text;/* Replacement text just formed by |scan_repl|. */

EXTERN eight_bits next_control;
EXTERN boolean scanning_meta SET(NO);



EXTERN boolean breakpoints;



EXTERN int n_unique SET(0);
EXTERN boolean deferred_macro SET(NO);



EXTERN boolean is_WEB_macro SET(NO);
EXTERN boolean scanning_defn;/* Deflects verbatim comments from def'n section. */
EXTERN boolean scanning_TeX;/* To help out |scan_text| with the handling \
				of vertical bars. */
EXTERN boolean nuweb_mode1;/* In case \.{@N} appears in defn section. */

EXTERN int mlevel SET(0);/* Level of preprocessor expansion. */



EXTERN boolean found_else SET(NO);



EXTERN sixteen_bits num_distinct_modules SET(1);/* Count the unnamed module. */
EXTERN sixteen_bits num_modules;



#if SMALL_MEMORY
#define MSG_BUF_SIZE 5000
#else
#define MSG_BUF_SIZE 50000L
#endif



/* For pc's, the file is split into three compilable parts using the \
compiler-line macro |part|, which must equal either~1, 2, or~3. */
#if(part == 0 || part == 1)


int main FCN((ac,av))
int ac C0("Number of arguments.")
outer_char**av C1("Argument list.")
{
#if TIMING
ini_timer();
/* Timing statistics are printed at the end of the run; see \.{common.web}. */
#endif /* |TIMING| */

/* Remember the arguments to |main| in global variables. */
argc= ac;argv= av;

ini_program(tangle);/* Set the |program| flag etc.; see \.{common.web}. */


{

{
ALLOC(OPEN_FILE,open_file,"nf",num_files,0);
last_file= open_file;
open_file_end= open_file+num_files;
}

/* Stuff that must be used for command line. */
common_init();/* Expand the command line here. */


ALLOC(outer_char,last_char,"lx",max_expr_chars,0);
last_end= last_char+max_expr_chars;
plast_char= last_char;



/* --- Allocate C output buffer --- */
ALLOC(outer_char,C_buffer,"cb",C_buf_size,0);
pC_end= C_buffer+C_buf_size-1;/* Allow for extra backslash if necessary. */
pC_buffer= C_buffer;/* Initialize to beginning. */

#if FANCY_SPLIT

{
split_pos= C_buffer;
}


#endif /* |FANCY_SPLIT| */

/* --- Allocate \TeX\ output buffer --- */
ALLOC(outer_char,X_buffer,"xb",X_buf_size,0);
pX_end= X_buffer+X_buf_size;
pX_buffer= X_buffer;/* Initialize to beginning. */


{
paren_level= GET_MEM("paren_level",t_style.paren.nest,PAREN_LEVEL);
paren_level_end= paren_level+t_style.paren.nest;

/* Initialize each nesting level. */
for(pai= paren_level;pai<paren_level_end;pai++)
pai->text_buf= GET_MEM("pai->text_buf",t_style.paren.num,
TEXT_BUF HUGE*);

pai= paren_level;
pai->ilevel= 0;
pai->text_buf[0]= pai->last_buf= calloc(1,sizeof(TEXT_BUF));
}



alloc_Rat();/* Allocate \Ratfor\ arrays. */

ALLOC(text,text_info,"x",max_texts,0);
text_end= text_info+max_texts-1;

ALLOC(text,txt_dinfo,"dx",dtexts_max,0);
textd_end= txt_dinfo+dtexts_max-1;

ALLOC(eight_bits,tok_mem,"tt",max_toks,0);
tok_m_end= tok_mem+max_toks-1;

ALLOC(eight_bits,tok_dmem,"dt",max_dtoks,0);
tokd_end= tok_dmem+max_dtoks-1;



ALLOC(output_state,stack,"kt",stck_size,1);
stck_end= stack+stck_size;/* End of |stack|. */


{
BUF_SIZE cur_num= last_file-open_file;/* Current size of list. */

/* Obtain the new allocation size. */
alloc((outer_char*)"nf",(BUF_SIZE HUGE*)&num_files,
sizeof(*open_file),-1);

/* Reallocate and reset parameters. */
open_file= (OPEN_FILE*)REALLOC(open_file,
num_files*sizeof(OPEN_FILE),cur_num*sizeof(OPEN_FILE));
last_file= open_file+cur_num;
open_file_end= open_file+num_files;
}

/* Local dynamic memory. */


CAST(text_pointer,text_info)->tok_start= tok_ptr= tok_mem;
CAST(text_pointer,txt_dinfo)->tok_start= tok_dptr= tok_dmem;

/* This makes replacement text 0 of length zero. */
text_ptr= text_info+1;text_ptr->tok_start= tok_mem;
txt_dptr= txt_dinfo+1;txt_dptr->tok_start= tok_dmem;



CAST(name_pointer,name_dir)->equiv= (EQUIV)text_info;



last_unnamed= text_info;/* Root of the unnamed module. */
CAST(text_pointer,text_info)->text_link= 0;/* No unnamed pieces yet. */



zero_ccodes();/* See \.{style.web}. */
ccode[057]= begin_vcmnt;/* The commenting style is also fundamental, and \
	for convenience the |line_break| command is also inviolate. (For \
	\FTANGLE, this gets reassigned later.) */


{

ini_ccode((outer_char*)"new_module",(outer_char*)" \t*",new_module);


ini_ccode((outer_char*)"begin_code",(outer_char*)"aA",begin_code);

ini_ccode((outer_char*)"module_name",(outer_char*)"<",module_name);


ini_ccode((outer_char*)"definition",(outer_char*)"dD",definition);

ini_ccode((outer_char*)"undefinition",(outer_char*)"uU",undefinition);

ini_ccode((outer_char*)"WEB_definition",(outer_char*)"mM",WEB_definition);

ini_ccode((outer_char*)"formatt",(outer_char*)"fF",formatt);


ini_ccode((outer_char*)"ascii_constant",(outer_char*)"'\"",ascii_constant);

ini_ccode((outer_char*)"verbatim",(outer_char*)"=",verbatim);


ini_ccode((outer_char*)"TeX_string",(outer_char*)"tT",TeX_string);


ini_ccode((outer_char*)"L_switch",(outer_char*)"L",L_switch);

ini_ccode((outer_char*)"begin_C",(outer_char*)"cC",begin_C);

ini_ccode((outer_char*)"begin_RATFOR",(outer_char*)"rR",begin_RATFOR);

ini_ccode((outer_char*)"begin_FORTRAN",(outer_char*)"n",begin_FORTRAN);

ini_ccode((outer_char*)"begin_nuweb",(outer_char*)"N",begin_nuweb);


ini_ccode((outer_char*)"join",(outer_char*)"&",join);


ini_ccode((outer_char*)"Compiler_Directive",(outer_char*)"?",Compiler_Directive);

ini_ccode((outer_char*)"invisible_cmnt",(outer_char*)"%",invisible_cmnt);

/* The next three must be reassigned to |control_text|. */

ini_ccode((outer_char*)"xref_roman",(outer_char*)"^",xref_roman);

ini_ccode((outer_char*)"xref_typewriter",(outer_char*)".",xref_typewriter);

ini_ccode((outer_char*)"xref_wildcard",(outer_char*)"9",xref_wildcard);


ini_ccode((outer_char*)"big_line_break",(outer_char*)"#",big_line_break);


ini_ccode((outer_char*)"begin_meta",(outer_char*)"(",begin_meta);

ini_ccode((outer_char*)"end_meta",(outer_char*)")",end_meta);


ini_ccode((outer_char*)"limbo_text",(outer_char*)"l",limbo_text);

ini_ccode((outer_char*)"op_def",(outer_char*)"vV",op_def);

ini_ccode((outer_char*)"macro_def",(outer_char*)"wW",macro_def);


ini_ccode((outer_char*)"begin_bp",(outer_char*)"{",begin_bp);

ini_ccode((outer_char*)"insert_bp",(outer_char*)"}bB",insert_bp);


ini_ccode((outer_char*)"no_mac_expand",(outer_char*)"!",no_mac_expand);

ini_ccode((outer_char*)"set_line_info",(outer_char*)"q",set_line_info);


ini_ccode((outer_char*)"new_output_file",(outer_char*)"oO",new_output_file);


ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"\001",USED_BY_OTHER);/* This command is for internal use only! */

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"\\",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"_",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"[",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"`]",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"$",USED_BY_OTHER);
{
char temp[3];

sprintf(temp,";%c",XCHR(interior_semi));

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)temp,USED_BY_OTHER);
}

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"e",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)":",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)",",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"|",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"~",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"-",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"+",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"p",USED_BY_OTHER);
#if(DEBUG)

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"012",USED_BY_OTHER);
#endif /* |DEBUG| */
}



{
reassign(xref_roman,control_text);
reassign(xref_typewriter,control_text);
reassign(xref_wildcard,control_text);
reassign(TeX_string,control_text);

reassign(verbatim,stringg);
}


prn_codes();



mod_text[0]= 040;


ini_internal_fcns();/* Internal built-in function macros. */
ini_Ratfor();/* Initialize \Ratfor. */
}




;

phase1();/* Read all the user's text and compress it into |tok_mem|. */
phase2();/* Output the contents of the compressed tables. */

if(statistics)see_tstatistics();/* Optional statistical info. */

return wrap_up();/* We actually |exit| from here. */
}



SRTN rst_last(VOID)
RST_LAST_EXPR



SRTN split_C(VOID)
{
#if FANCY_SPLIT

{
/* Split strings, but not constants. */
if(in_string&&split_pos==C_buffer)
{

{
if(!meta_mode)
*pC_buffer++= '\\';/* There's always room for one more character. */

C_out(C_buffer,pC_buffer,&pC_buffer,OC("\n"),OC(""),NO_INDENT);
/* Dump out all the way to the end. */
}


return;
}

*pC_buffer= '\0';
split0_C(split_pos);
}


#else

{
if(!meta_mode)
*pC_buffer++= '\\';/* There's always room for one more character. */

C_out(C_buffer,pC_buffer,&pC_buffer,OC("\n"),OC(""),NO_INDENT);
/* Dump out all the way to the end. */
}


#endif /* |FANCY_SPLIT| */
}



#if FANCY_SPLIT

SRTN split0_C FCN((p))
outer_char*p C1("Position for the split")
{
int indent;

/* If no break has been found, force a break at the end. */
if(p==C_buffer)
{
*pC_buffer++= '\\';
p= pC_buffer;
indent= NO_INDENT;
}
else
indent= INDENT;

C_out(C_buffer,p,&pC_buffer,OC("\n"),OC(""),indent);
/* Output from |C_buffer| to~|p|. */

}
#endif /* |FANCY_SPLIT| */



SRTN C_out FCN((C_buffer,p,ppC_buffer,end_str,begin_str,indent))
outer_char HUGE*C_buffer C0("Buffer we're working with")
outer_char HUGE*p C0("End (next available pos)")
outer_char HUGE*HUGE*ppC_buffer C0("")
outer_char*end_str C0("")
CONST outer_char*begin_str C0("")
int indent C1("Should the next buffer be indented?")
{
int n= PTR_DIFF(int,*ppC_buffer,p);/* How many left in buffer. */

if(p>C_buffer)
WRITE1(C_buffer,p-C_buffer)

/* Add trailing characters if necessary. */
if(*end_str)
WRITE1(end_str,STRLEN(end_str))

/* Reset the pointer, then insert the beginning character if necessary. */
*ppC_buffer= C_buffer;

while(*begin_str)
*(*ppC_buffer)++= *begin_str++;

/* Add optional indentation (i.e., fill with blanks). */
while(indent--)
*(*ppC_buffer)++= ' ';

/* If there's still stuff in the buffer, move it to the beginning. */
if(n)
{
STRNCPY(*ppC_buffer,p,n);
*ppC_buffer+= n;/* Reset the current pointer if necessary. */
}

flush0();/* Count the lines. */

{
split_pos= C_buffer;
}


}



SRTN C_putc FCN((c))
outer_char c C1("Character to be sent to output.")
{
static CONST outer_char HUGE*prefx= OC("");

CHECK_OPEN;/* Output files are opened only when necessary. */

if(dbg_output)
printf("c = '%c' (0x%x)\n",c,c);

if(at_beginning&&meta_mode&&!nuweb_mode&&(in_string||in_version))
{/* Invoke |C_putc| recursively. */
at_beginning= NO;/* Prevent infinite recursion. */
out_pos= 0;/* For \Fortran. */
pmeta= &t_style.meta[lan_num(language)];
prefx= OUT_STR(in_version?pmeta->hdr.prefx:pmeta->msg.prefx);
}

switch(language)
{
case RATFOR:
case RATFOR_90:
if(!Ratfor77)
{
RAT_out(c);/* Old-style \Ratfor. Modern \Ratfor\ falls \
through to \Fortran. */
break;
}

case FORTRAN:
case FORTRAN_90:
if(reverse_indices
&&((pai>paren_level)||rparen||!(in_string||in_version)))

{
switch(c)
{
case '(':
if(rparen)
{/* The combination `\.{)(}' has occurred; advance the \
buffer level. */
pai->ilevel++;

if(pai->ilevel==(int)t_style.paren.num)
NEW_SPRM("paren.num",t_style.paren.num);


{
if(!CUR_BUF)
CUR_BUF= GET_MEM("CUR_BUF",1,TEXT_BUF);
}




rparen= NO;
}
else
{/* Time for a new parenthesis level.  Put the parenthesis \
into the old level.  Remember where that was, then advance the level. */
store(CUR_BUF,'(');

(pai+1)->last_buf= CUR_BUF;
pai++;

if(pai==paren_level_end)
NEW_SPRM("paren.nest",t_style.paren.nest);

pai->ilevel= 0;


{
if(!CUR_BUF)
CUR_BUF= GET_MEM("CUR_BUF",1,TEXT_BUF);
}



}

break;

case ')':
if(!rparen)
rparen= YES;
else
unwind();

break;

default:
if(rparen)
{
unwind();
rparen= NO;
}

if(in_string&&pai==paren_level)
buffer_out(c);
else
store(CUR_BUF,c);

break;
}
}


else
buffer_out(c);

break;

case LITERAL:
case TEX:

{
*pX_buffer++= c;/* Add present character to buffer. */

if(c=='\n')
C_out(X_buffer,pX_buffer,&pX_buffer,OC(""),
(outer_char HUGE*)CHOICE(meta_mode&&language==TEX,prefx,OC("")),
NO_INDENT);
else if(pX_buffer==pX_end)
split_X(prefx);
}


break;

case C:
case C_PLUS_PLUS:
default:
#ifndef mac /* \.{Machine-dependent}: Don't buffer C output. */

{
*pC_buffer++= c;/* Add present character to buffer. */

if(c=='\n')
C_out(C_buffer,pC_buffer,&pC_buffer,OC(""),OC(""),NO_INDENT);
/* Output whole buffer. */
else if(pC_buffer==pC_end)
split_C();
}


/* If the above buffering (a relatively recent addition) doesn't work, use \
the following: */
#else
if(c=='\n')
flush0();/* Count the lines. */
PUTC(c);
#endif /* |mac| */
break;
}

at_beginning= BOOLEAN(c=='\n');
}



SRTN split_X FCN((prefx))
CONST outer_char HUGE*prefx C1("")
{
outer_char HUGE*p= pX_buffer-1;

WHILE()
{
if(p==X_buffer)

{

err0_print(ERR_T,OC("Line had to be broken"),0);
C_out(X_buffer,pX_buffer,&pX_buffer,
language==TEX?OC("%\n"):OC("\n"),
OC(""),NO_INDENT);
return;
}



if(*p==' ')
{
C_out(X_buffer,p+1,&pX_buffer,OC("\n"),
(outer_char HUGE*)CHOICE(meta_mode&&language==TEX,
prefx,OC("")),
NO_INDENT);
return;
}

if(*(p--)=='\\'&&*p!='\\')
{
C_out(X_buffer,p+1,&pX_buffer,
language==TEX?OC("%\n"):OC("\n"),
(outer_char HUGE*)CHOICE(meta_mode&&language==TEX,
prefx,OC("")),
NO_INDENT);
return;
}
}
}



static outer_char last_out= '\0';/* In \Fortran, the last character output. */

/* Various flags help \Fortran\ out. */
static boolean is_label= NO;
static boolean should_continue= NO;
static continuation_line= NOT_CONTINUATION;

static STMT_LBL stmt_num[50];/* Archaic; for numbering \
			|do|s in \Fortran. Should use \Ratfor\ instead. */
static short do_level= 0;


SRTN C_sprintf FCN(VA_ALIST((fmt,n VA_ARGS)))
VA_DCL(
CONST outer_char fmt[]C0("String to be printed.")
int n C2("Number of arguments to follow."))
{
VA_LIST(arg_ptr)
outer_char temp[N_STRBUF];
outer_char HUGE*t;

VA_START(arg_ptr,n);

#if(NUM_VA_ARGS==1)
{
char*fmt0= va_arg(arg_ptr,char*);

va_arg(arg_ptr,int);
vsprintf((char*)(char*)temp,fmt0,arg_ptr);
}
#else
vsprintf((char*)temp,(CONST char*)fmt,arg_ptr);
#endif /* Length not checked now. */
va_end(arg_ptr);

for(t= temp;*t;++t)C_putc(*t);
}



SRTN RAT_out FCN((c))
outer_char c C1("Output this character to \Ratfor.")
{
switch(c)
{
case end_meta:
send_new_line;
return;

case begin_meta:
if(meta_mode)return;/* The second in a row. */
meta_mode= YES;/* NOTE: FALLS THROUGH to next case. */

case '\n':
send_new_line;
if(meta_mode)PUTC('#');/* \Ratfor\ comment. */
return;

default:
PUTC(c);
return;
}
}



SRTN buffer_out FCN((c))
outer_char c C1("Output this character to the \Fortran\ buffer.")
{
outer_char*px;/* For |in_string| |meta_mode| processing. */

/* Remember the output character, since we may want to spit it out again \
later, as in |i *= expr| $\to$ |i = i*(expr)|. Turning off the \
|compound_assignments| flag by option \.{-+} will speed things up a bit. */
if(compound_assignments&&!send_rp)
if(plast_char>=last_end)
last_xpr_overflowed= YES;
else
*plast_char++= c;



switch(c)
{
case '\0':if(!in_string)return;/* In case a null sneaks in, ignore it. */

/* Reset the verbatim comment mode. We have to remember whether we were in \
the middle of a line; if we were, we must resume continuation mode. */
if(in_string&&started_vcmnt)
{
NEWLINE_TO_FORTRAN(should_continue);
started_vcmnt= NO;
return;
}
break;

case '{':
case '}':
/* Filter out braces from \Ratfor. */
if(!in_string&&xpn_Ratfor)return;
break;

/* Ignore any blanks at beginning of line. */
case ' ':
if(out_at_beginning)return;
break;



case '\n':
if(in_cdir)
{
out_pos= 0;
}
else if(!in_string||(in_string&&started_vcmnt))
{
NEWLINE_TO_FORTRAN(NOT_CONTINUATION);

if(in_string&&started_vcmnt)
{
int k;

if(!meta_mode)
{
outp_buf[0]= begin_comment_char[lan_num(out_language)];

for(out_pos= 1,k= spcs_after_cmnt;k;k--)
outp_buf[out_pos++]= ' ';
}

nbuf_length= MAX(t_style.output_line_length,80);
out_at_beginning= NO;/* Prevents stripping off blanks at beginning of cmnt. */
}


}
else if(!started_vcmnt)
{/* Remember if  there's stuff in the buffer. If so, when \
we terminate the verbatim comment we must continue. */
should_continue= BOOLEAN(out_pos>rst_pos);

/* The next statement prevents overwriting the stuff already in the buffer. */
if(should_continue){NEWLINE_TO_FORTRAN(NOT_CONTINUATION);}
should_continue= BOOLEAN((!free_Fortran)&&should_continue);

{
int k;

if(!meta_mode)
{
outp_buf[0]= begin_comment_char[lan_num(out_language)];

for(out_pos= 1,k= spcs_after_cmnt;k;k--)
outp_buf[out_pos++]= ' ';
}

nbuf_length= MAX(t_style.output_line_length,80);
out_at_beginning= NO;/* Prevents stripping off blanks at beginning of cmnt. */
}

;
started_vcmnt= YES;
}

return;




/* Semicolons not in strings mean emit a new line (except when they were \
earlier translated into |semi| during stringizing). */
case ';':
if(!(in_string||in_constant))
{
NEWLINE_TO_FORTRAN(NOT_CONTINUATION);
return;
}
break;

case interior_semi:
case semi:
c= ';';break;

/* Handle meta-comments. */
case begin_meta:
if(!meta_mode&&last_out!='\n')flush_out(YES);
meta_mode= YES;
if(in_string)
{/* Start standard meta-comment. */
TO_BUFFER(top);
if(out_pos>0)flush_out(YES);
}
rst_out(NOT_CONTINUATION);
return;

case end_meta:
if(in_string)
{/* Finish standard meta-comment. */
TO_BUFFER(bottom);
if(out_pos>0)flush_out(YES);
started_vcmnt= NO;
}
else flush_out(YES);

rst_out(NOT_CONTINUATION);
return;
}

/* If we're still going at column 73, emit a new line and make the next \
line a continuation line. */
if(out_pos>=nbuf_length)
{
if(free_Fortran)outp_buf[out_pos++]= '&';/* Standard F--90 contin. */
flush_out(YES);
rst_out(CONTINUATION);/* Continuation. */

if(in_string&&started_vcmnt)
{
int k;

if(!meta_mode)
{
outp_buf[0]= begin_comment_char[lan_num(out_language)];

for(out_pos= 1,k= spcs_after_cmnt;k;k--)
outp_buf[out_pos++]= ' ';
}

nbuf_length= MAX(t_style.output_line_length,80);
out_at_beginning= NO;/* Prevents stripping off blanks at beginning of cmnt. */
}

;
}

if(out_at_beginning)
{
out_at_beginning= NO;

/* Statement labels require special treatment. When we sense one, we raise \
a special flag and put them into column~1. */
if(!in_string)
if(isdigit(c)&&!is_label)
{
is_label= YES;
out_pos= 0;
}
else if(c=='#')
{/* Place the \&{\#line} command in column~1. */
outp_buf[0]= t_style.line_char[lan_num(language)];
/* It's a comment. */
out_pos= 1;
return;
}
}



/* When a statement label ends, skip to column~7. */
if(is_label&&!isdigit(c))
{
is_label= NO;
out_pos= 6+indent_level*INDENT_SIZE;
if(c==':'||c==' ')return;/* Throw away the trailing colon. */
}



if(number_dos&&!continuation_line&&(language==FORTRAN||
language==FORTRAN_90||R66))
{
outer_char HUGE*do_pos;

do_pos= outp_buf+6;

if(out_pos==9)
{
if(STRNCMP(do_pos,"do ",3)==0&&!isdigit(c))
{
sprintf((char*)(do_pos+= 3),"%lu ",
stmt_num[do_level++]= max_stmt++);

while(*do_pos++!='\0')out_pos++;
}
}
else if((out_pos==10&&STRNCMP(do_pos,"endd",4)==0)||
(out_pos==11&&STRNCMP(do_pos,"end d",5)==0))
{
if(do_level==0)
{

err0_print(ERR_T,OC("Too many END DOs"),0);
*outp_buf= 'C';
}
else
{
sprintf((char*)outp_buf,"%-5lu CONTINUE",
stmt_num[--do_level]);
out_pos= 14;
return;
}
}
}



/* Can't put it off any longer: Put the character into the buffer. */
last_out= outp_buf[out_pos++]= c;

return;
}



SRTN flush_out FCN((prn_new_line))
boolean prn_new_line C1("Do we print a newline?")
{
outp_buf[out_pos]= '\0';/* Terminate the buffer. */

/* Dump it out, followed by a newline. */
WRITE1(outp_buf,out_pos)

if(prn_new_line)
{
last_out= '\n';
PUTC(last_out);
flush0();
}
}



int rst_out FCN((continuation))
boolean continuation C1("Is line a continuation?")
{
if(!continuation)RST_LAST_EXPR /* Reset the pointer so we can remember the \
					upcoming expression. */

/* Blank out the comment and label field (first five columns). */
for(out_pos= 0;out_pos<5;++out_pos)
outp_buf[out_pos]= ' ';

/* Deposit the continuation character. */
outp_buf[out_pos++]= continuation?t_style.cchar:(outer_char)' ';
continuation_line= continuation;
out_at_beginning= BOOLEAN(!continuation_line);

nbuf_length= t_style.output_line_length;

if(meta_mode)
{
if(!in_string)
{/* Error message. */
outp_buf[0]= begin_comment_char[lan_num(out_language)];
if(!xpn_Ratfor)out_pos= 1+spcs_after_cmnt;
}

nbuf_length= MAX(nbuf_length,80);
}

/* If it's not a continuation line, mark the beginning. Also, if we're in a \
loop, indent appropriately. */
if(out_at_beginning&&xpn_Ratfor)blank_out(indent_level);

return rst_pos= out_pos;
}



SRTN blank_out FCN((n))
int n C1("Number of levels to indent.")
{
outer_char HUGE*p;
int i;

for(i= 0,p= outp_buf+out_pos;i<n*INDENT_SIZE;i++)*p++= ' ';

out_pos+= i;
rst_pos= out_pos;
}



SRTN store FCN((t,c))
TEXT_BUF HUGE*t C0("")
outer_char c C1("")
{
if(pai==paren_level||t==paren_level[0].last_buf)
{/* Send directly to \Fortran's output buffer. */
buffer_out(c);
return;
}

/* Store in the indicated text buffer; initialize that if necessary. */
if(t->start==NULL)
{
t->pos= t->start= GET_MEM("t->start",t_style.paren.len,outer_char);
t->end= t->start+t_style.paren.len;
}

if(t->pos==t->end)
{
size_t len= PTR_DIFF(size_t,t->end,t->start);

t->start= (outer_char*)REALLOC(t->start,len+t_style.paren.len,len);
t->pos= t->start+len;
t->end= t->start+len+t_style.paren.len;
}

*t->pos++= c;
}



SRTN unwind(VOID)
{
int i;
TEXT_BUF HUGE*t;
outer_char HUGE*s1;

if(pai==paren_level)
{

err0_print(ERR_T,OC("Missing '('"),0);
buffer_out(')');
return;
}

for(i= pai->ilevel;i>=0;i--)
{
t= pai->text_buf[i];

for(s1= t->start;s1<t->pos;s1++)
store(pai->last_buf,*s1);

t->pos= t->start;/* Reset the buffer. */

if(i>0)
store(pai->last_buf,',');
}

store(pai->last_buf,')');
pai--;/* Decrement parenthesis level. */
}




boolean names_match FCN((p,first,l,dummy))
name_pointer p C0("Points to the proposed match.")
CONST ASCII HUGE*first C0("Position of first character of string.")
int l C0("length of identifier.")
eight_bits dummy C1("Not used here")
{
if(length(p)!=l)return NO;
return(boolean)(!STRNCMP(first,p->byte_start,l));
}



SRTN ini_node FCN((node))
CONST name_pointer node C1("")
{
node->equiv= (EQUIV)text_info;

{
/* We allocate |MOD_INFO| structures only for module names, not for \
	identifiers. */
node->mod_info= GET_MEM("mod_info",1,MOD_INFO);

node->mod_info->Ilk= expr;
node->mod_info->params= params;/* Freeze parameters at this point in time. */

node->Language= (boolean)language;/* Redundant. */
}



}



SRTN ini_p FCN((p,t))
name_pointer p C0("")
eight_bits t C1("")
{}

SRTN open_tex_file(VOID)
{}



SRTN store_two_bytes FCN((x))
sixteen_bits x C1("Two-byte token to be entered into |tok_mem|.")
{
if(tok_ptr+2>tok_m_end)OVERFLW("tokens","tt");

*tok_ptr++= (eight_bits)(x>>8);/* Store high byte. */
*tok_ptr++= (eight_bits)(x&0377);/* Store low byte. */
}




SRTN push_level FCN((p,b0,b1))
name_pointer p C0("The new replacement text.")
CONST eight_bits HUGE*b0 C0("If |p == NULL|, beginning of new \
stuff in memory.")
CONST eight_bits HUGE*b1 C1("If |p == NULL|, end of new stuff in \
memory.")
{
if(stck_ptr==stck_end)OVERFLW("stack levels","kt");

*stck_ptr= cur_state;/* Save old state. */

/* Initialize new state. */
cur_name= p;

if(p!=NULL)
{
cur_repl= (text_pointer)p->equiv;

if(cur_repl==NULL)CONFUSION("push_level","cur_repl is NULL");

cur_byte= cur_repl->tok_start;
cur_end= (cur_repl+1)->tok_start;
}
else
{
cur_repl= NULL;

cur_byte= (eight_bits HUGE*)b0;cur_end= (eight_bits HUGE*)b1;
new_mbuf();/* Allocate new macro buffer. See \.{macs.web}. */
}

/* Get the language for this module. All modules start off in the global \
language for that module. Also, the old state needs to recall the local \
language switch. */
(stck_ptr++)->params= cur_params= cur_global_params= 
(p!=NULL)?params:params;/* ??? */
set_output_file(cur_language);
cur_mod= UNNAMED_MODULE;/* Assume this until told otherwise. */
}



boolean pop_level(VOID)/* do this when |cur_byte| reaches |cur_end| */
{
if(cur_repl!=NULL&&cur_repl->text_link<module_flag)
{/* Link to a continuation---i.e., the next in the chain of \
replacement texts for this module. */
cur_repl= cur_repl->text_link+text_info;/* Stay on the same level. */
cur_byte= cur_repl->tok_start;
cur_end= (cur_repl+1)->tok_start;

/* In case we changed languages during the module, localize the change. */
if(cur_repl->module_text)
{
params= cur_params= cur_global_params;
frz_params();
set_output_file(cur_language);
}

return YES;
}

stck_ptr--;/* Go down to the previous level. */

if(stck_ptr>stack)
{
cur_state= *stck_ptr;/* Copy the current state structure. */
if(cur_language!=language)
flush_buffer();
set_output_file(cur_language);
return YES;/* Successfully descended to a lower active level. */
}

return NO;/* Already at lowest level (top of stack). */
}


eight_bits get_output(VOID)
{
sixteen_bits a;/* Value of current byte. */

restart:
if(stck_ptr==stack)
return NO;/* At top of stack; nothing more. */

if(cur_byte==cur_end)
{
cur_val= -((long)cur_mod);/* When we end a module, |cur_val| is \
set to the negative of the module number.  The cast is needed because of \
sign extension. */

if(cur_val!=ignore)
OUT_CHAR(module_number);/* Do this here so \
it gets into the right file if we're changing languages. */

pop_level();

if(cur_val==ignore)
goto restart;

return module_number;
}


{
a= *cur_byte++;

if(TOKEN1(a))/* |in_string|?? */
{

{
send_single(a);
}

;
return sent;
}
else
{
a= IDENTIFIER(a,*cur_byte++);

switch(a/MODULE_NAME)
{
case 0:
cur_val= a;

{
IN_RATFOR boolean balanced;
IN_RATFOR ASCII cur_delim;

if(!balanced&&language==RATFOR&&
(a==id_function||a==id_program||a==id_subroutine))
{

RAT_error(ERROR,OC("Inserted missing '%c' at beginning of function"),1,XCHR(cur_delim));
cur_byte-= 2;/* Process the current identifier again. */
return OUT_CHAR(cur_delim);/* Insert delimiter being searched for. */
}
}


return OUT_CHAR(identifier);

case 1:

{
name_pointer np;

a-= MODULE_NAME;

np= name_dir+a;

if(np->equiv!=(EQUIV)text_info)
push_level(np,NULL,NULL);
else if(a!=UNNAMED_MODULE)
{/* Module definition missing. */
SET_COLOR(error);
printf("\n! Not present: <");prn_id(np);
err0_print(ERR_NULL,OC(">"),0);

SET_COLOR(ordinary);

{
#define TEMP_LEN 300

eight_bits temp[TEMP_LEN],temp1[TEMP_LEN];
sixteen_bits stub;
size_t n= (size_t)length(np);

id_first= x__to_ASCII(OC("$STUB"));
stub= ID_NUM(id_first,id_first+5);

STRNCPY(temp1,np->byte_start,n);
temp1[n]= '\0';


if(
nsprintf(temp,OC("%c%c%c%c%s%c%c"),7,LEFT(stub,ID0),RIGHT(stub),050,stringg,temp1,stringg,051)>=(int)(TEMP_LEN))OVERFLW("temp","");
push_level(NULL,temp,temp+STRLEN(temp));

#undef TEMP_LEN
}


}
}


goto restart;

default:
cur_val= a-MODULE_NUM;
if(cur_val>UNNAMED_MODULE)cur_mod= (sixteen_bits)cur_val;
/* Remember the current module so it can be used in \
|out_char(module_number)| just after popping this level. */
return OUT_CHAR(module_number);/* Module number at \
beginning  of module. */
}
}
}


}



eight_bits get_saved_output FCN((stck_ptr0))
stack_pointer stck_ptr0 C1("")
{
sixteen_bits a;

restart:
if(stck_ptr==stack||stck_ptr!=stck_ptr0)return NO;

if(DONE_LEVEL)
{/* Hunt for end-of-tokens mark. */
if(!pop_level())CONFUSION("get_saved_output",
"Shouldn't encounter top level here");
return ignore;
}


{
a= *cur_byte++;

if(TOKEN1(a))/* |in_string|?? */
{

{
send_single(a);
}

;
return sent;
}
else
{
a= IDENTIFIER(a,*cur_byte++);

switch(a/MODULE_NAME)
{
case 0:
cur_val= a;

{
IN_RATFOR boolean balanced;
IN_RATFOR ASCII cur_delim;

if(!balanced&&language==RATFOR&&
(a==id_function||a==id_program||a==id_subroutine))
{

RAT_error(ERROR,OC("Inserted missing '%c' at beginning of function"),1,XCHR(cur_delim));
cur_byte-= 2;/* Process the current identifier again. */
return OUT_CHAR(cur_delim);/* Insert delimiter being searched for. */
}
}


return OUT_CHAR(identifier);

case 1:

{
name_pointer np;

a-= MODULE_NAME;

np= name_dir+a;

if(np->equiv!=(EQUIV)text_info)
push_level(np,NULL,NULL);
else if(a!=UNNAMED_MODULE)
{/* Module definition missing. */
SET_COLOR(error);
printf("\n! Not present: <");prn_id(np);
err0_print(ERR_NULL,OC(">"),0);

SET_COLOR(ordinary);

{
#define TEMP_LEN 300

eight_bits temp[TEMP_LEN],temp1[TEMP_LEN];
sixteen_bits stub;
size_t n= (size_t)length(np);

id_first= x__to_ASCII(OC("$STUB"));
stub= ID_NUM(id_first,id_first+5);

STRNCPY(temp1,np->byte_start,n);
temp1[n]= '\0';


if(
nsprintf(temp,OC("%c%c%c%c%s%c%c"),7,LEFT(stub,ID0),RIGHT(stub),050,stringg,temp1,stringg,051)>=(int)(TEMP_LEN))OVERFLW("temp","");
push_level(NULL,temp,temp+STRLEN(temp));

#undef TEMP_LEN
}


}
}


goto restart;

default:
cur_val= a-MODULE_NUM;
if(cur_val>UNNAMED_MODULE)cur_mod= (sixteen_bits)cur_val;
/* Remember the current module so it can be used in \
|out_char(module_number)| just after popping this level. */
return OUT_CHAR(module_number);/* Module number at \
beginning  of module. */
}
}
}


}



SRTN copy_out FCN((p0,p1,is_expr))
CONST eight_bits HUGE*p0 C0("Start of memory buffer.")
CONST eight_bits HUGE*p1 C0("End of memory buffer.")
boolean is_expr C1("Flag for resetting pointer to last expression.")
{
stack_pointer stck_ptr0;

/* If we're copying out an expression, reset the memory pointer. */
if(is_expr)rst_last();

push_level(NULL,p0,p1);
stck_ptr0= stck_ptr;

while(get_saved_output(stck_ptr0))
;
}



SRTN send_single FCN((a))
sixteen_bits a C1("")
{
boolean scope;

switch(a)
{
case begin_language:
/* |begin_language| escapes the actual language, which follows next. */
switch(sent= *cur_byte++)
{
case NO_LANGUAGE:/* Serves double-duty for |new_output_file|. */
scope= *cur_byte++;
a= *cur_byte++;
a= IDENTIFIER(a,*cur_byte++);
new_out(scope,a);
sent= new_output_file;
break;



case C:opn_output_file(C);break;
case C_PLUS_PLUS:opn_output_file(C_PLUS_PLUS);break;
case RATFOR:
if(!RAT_OK("(send_single)"))
CONFUSION("output default","Ratfor command during output");
opn_output_file(RATFOR);
break;
case RATFOR_90:
if(!RAT_OK("(send_single)"))
CONFUSION("output default","Ratfor command during output");
opn_output_file(RATFOR_90);
break;
case FORTRAN:opn_output_file(FORTRAN);break;
case FORTRAN_90:opn_output_file(FORTRAN_90);break;
case TEX:opn_output_file(TEX);break;
case LITERAL:opn_output_file(LITERAL);break

;

case NUWEB_OFF:
case NUWEB_ON:
nuweb_mode= BOOLEAN(0x0F&sent);
break;

case no_mac_expand:
mac_protected= no_expand= YES;
break;

case set_line_info:
line_info= *cur_byte++;
break;
}
break;

case dot_const:
cur_val= *cur_byte++;/* The relative number of the \
operator is stored in the byte following |dot_const|. */
sent= OUT_CHAR(a);
break;

default:
sent= OUT_CHAR(a);/* One-byte token. */
break;
}
}



#define TEMP_LEN (2*MAX_FILE_NAME_LENGTH)

SRTN new_out FCN((global_scope,a))
boolean global_scope C0("0 for local, 1 for global")
sixteen_bits a C1("")
{
name_pointer np= name_dir+a;
CONST ASCII HUGE*end;
size_t len;
outer_char temp_from[TEMP_LEN],temp_to[TEMP_LEN];
outer_char temp[MAX_FILE_NAME_LENGTH];

if(global_scope)
{

if(
nsprintf(temp_from,OC("\n\n  (This file was continued via @O from %s.)"),1,params.OUTPUT_FILE_NAME)>=(int)(TEMP_LEN))OVERFLW("temp_from","");
}
else
{

if(
nsprintf(temp_from,OC(" "),0)>=(int)(TEMP_LEN))OVERFLW("temp_from","");
}

/* Extract the file name from the |name_dir|. */
PROPER_END(end);
len= PTR_DIFF(size_t,end,np->byte_start);
STRNCPY(temp,np->byte_start,len);
TERMINATE(temp,len);
to_outer((ASCII HUGE*)temp);
new_fname(&params.OUTPUT_FILE_NAME,temp,NULL);


if(global_scope)
{/* Write a continuation message into the old file. */
new_fname(&global_params.OUTPUT_FILE_NAME,temp,NULL);

if(
nsprintf(temp_to,OC("  (Continued via @O to %s.)"),1,params.OUTPUT_FILE_NAME)>=(int)(TEMP_LEN))OVERFLW("temp_to","");
OUT_MSG(to_ASCII(temp_to),NULL);
close_out(out_file);
}
else
fflush(out_file);

open_out(temp_from,global_scope);
}

#undef TEMP_LEN



SRTN i_mod_name_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
int len;
name_pointer np= cur_name;
eight_bits HUGE*p;

CHK_ARGS("$MODULE_NAME",0);

if(cur_name)
cur_mod_no= (sixteen_bits)(np-name_dir);
else
cur_mod_no= 0;

len= cur_mod_no?(int)length(np):STRLEN(UNNAMED_MOD);
MCHECK(len,"current module name");

if(cur_mod_no)
for(p= np->byte_start;p<(np+1)->byte_start;)
*mp++= *p++;
else
{
STRCPY(mp,UNNAMED_MOD);
to_ASCII(mp);
mp+= len;
}
}



SRTN i_sect_num_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
num_to_mbuf(n,pargs,"$SECTION_NUM",0,"section number",cur_mod);
}



SRTN x_mod_a FCN((a))
sixteen_bits a C1("")
{

{
name_pointer np;

a-= MODULE_NAME;

np= name_dir+a;

if(np->equiv!=(EQUIV)text_info)
push_level(np,NULL,NULL);
else if(a!=UNNAMED_MODULE)
{/* Module definition missing. */
SET_COLOR(error);
printf("\n! Not present: <");prn_id(np);
err0_print(ERR_NULL,OC(">"),0);

SET_COLOR(ordinary);

{
#define TEMP_LEN 300

eight_bits temp[TEMP_LEN],temp1[TEMP_LEN];
sixteen_bits stub;
size_t n= (size_t)length(np);

id_first= x__to_ASCII(OC("$STUB"));
stub= ID_NUM(id_first,id_first+5);

STRNCPY(temp1,np->byte_start,n);
temp1[n]= '\0';


if(
nsprintf(temp,OC("%c%c%c%c%s%c%c"),7,LEFT(stub,ID0),RIGHT(stub),050,stringg,temp1,stringg,051)>=(int)(TEMP_LEN))OVERFLW("temp","");
push_level(NULL,temp,temp+STRLEN(temp));

#undef TEMP_LEN
}


}
}


}



SRTN flush0()
{
/* This routine might be called during phase~1, because error messages use \
the output buffering routines.  However, we don't want to update \
|cur_line|, which counts the input lines during phase~1. */
if(phase==1)return;

/* Give some feedback to the terminal by printing a dot every so often, and \
the line number somewhat less often. */
if(cur_line%100==0)
{
if(cur_line%500==0){CLR_PRINTF(line_num,("%u",cur_line));}
else putchar('.');

UPDATE_TERMINAL;/* Progress report. */
}

cur_line++;
OUTPUT_LINE++;
}



SRTN phase2(VOID)
{
phase= 2;

params= global_params;
frz_params();
set_output_file(global_language);

/* Get the FORTRAN output buffer ready. */
rst_out(NOT_CONTINUATION);

CLR_PRINTF(info,("\nWriting the %soutput file(s):",
compare_outfiles?"temporary ":""));
printf("  ");
UPDATE_TERMINAL;

cur_line= 1;

if(CAST(text_pointer,text_info)->text_link==0)
{/* There was no program text. */
CLR_PRINTF(warning,("\n! No program text was specified."));
mark_harmless;

}
else
{/* There is program text. */

{
name_pointer np;

npmax= name_ptr-1;/* Used in output routine. */

if(truncate_ids)
{
unsigned n= 0;/* Counts number of truncations. */

printf("\nTruncating %u identifiers...",
PTR_DIFF(unsigned,name_ptr,name_dir));

for(np= name_dir+1;np<name_ptr;np++)
n+= trunc_id(np);

printf("\n%u truncation(s) performed.",n);
}

not_unique();/* Print non-unique identifiers. */
}

;



stck_ptr= stack+1;cur_name= name_dir;
cur_repl= CAST(text_pointer,text_info)->text_link+text_info;
cur_byte= cur_repl->tok_start;cur_end= (cur_repl+1)->tok_start;
cur_mod= UNNAMED_MODULE;
params= cur_params= cur_global_params= global_params;
frz_params();

;

{
sixteen_bits a;
text_pointer cur_text;
boolean is_def;


copying_macros= YES;

for(cur_text= text_info+1;cur_text<text_ptr;cur_text++)
if(cur_text->text_link==macro)
{/* |cur_text| is the text for a macro */
cur_byte= cur_text->tok_start;
cur_end= (cur_text+1)->tok_start;

is_WEB_macro= 
BOOLEAN(!((is_def= BOOLEAN(cur_text->nargs==OUTER_MACRO))||
cur_text->nargs==OUTER_UNMACRO));/* Check special \
marker set on input. */

if(is_WEB_macro)
{
#if(0)
see_macro(cur_byte,cur_end)/* For debugging. */
#endif
;}
else

{
LANGUAGE language0;
T_OUTER*po= &t_style.outer_start[lan_num(language)];
outer_char*outer_macro;

out_state= MISCELLANEOUS;

set_output_file((LANGUAGE)cur_text->Language);/* Set the language for this \
						outer macro.  */

protect= YES;/* New-lines should be preceded by the protection character. */

outer_macro= OC(is_def?po->def:po->undef);
language0= language;

C_sprintf(outer_macro,0);

stck_ptr= stack;
push_level(NULL,cur_byte,cur_end);

WHILE()

{
if(DONE_LEVEL&&!pop_level())break;

a= *cur_byte++;

if(cur_byte==cur_end&&a==012)
continue;/* disregard a final new-line */

if(TOKEN1(a))/* |in_string|?? */

{
send_single(a);
}


else
{
a= IDENTIFIER(a,*cur_byte++);

if(a<MODULE_NAME)
{
cur_val= a;
OUT_CHAR(identifier);/* Outer macro text will be expanded here. */
}
else if(a!=MODULE_NUM)
{
CONFUSION("copy outer","Macros defs have strange char");
}
else
{
cur_mod= (sixteen_bits)(a-MODULE_NUM);
cur_val= (long)cur_mod;
OUT_CHAR(module_number);
}
/* no other cases */
}
}



set_output_file(language0);

protect= NO;
flush_buffer();
}


}

copying_macros= NO;
}

;



stck_ptr= stack+1;cur_name= name_dir;
cur_repl= CAST(text_pointer,text_info)->text_link+text_info;
cur_byte= cur_repl->tok_start;cur_end= (cur_repl+1)->tok_start;
cur_mod= UNNAMED_MODULE;
params= cur_params= cur_global_params= global_params;
frz_params();

;

while(get_output())
;/* Process each character of the output. */

flush_buffer();

if(compare_outfiles)
cmp_outfiles();/* Compare tangled output against old files. */

CLR_PRINTF(info,("\nDone."));
}
}


SRTN out_version FCN((msg))
CONST outer_char*msg C1("")
{
outer_char HUGE*temp= GET_MEM("version:temp",N_MSGBUF,outer_char);
boolean in_string0= in_string;
OUTPUT_STATE out_state0= out_state;


if(
nsprintf(temp,OC("  FTANGLE v%s, created with %s on \"%s, %s at %s.\" %s\n"),6,"1.53",the_system,"Saturday","September 23, 1995","16:17",local_banner)>=(int)(N_MSGBUF))OVERFLW("temp","");
STRCAT(temp,cmd_ln_buf);
STRCAT(temp,msg);/* Possible \.{@o} continuation message.i */
in_version= YES;
OUT_MSG(to_ASCII(temp),NULL);
FREE_MEM(temp,"version:temp",N_MSGBUF,outer_char);

in_version= NO;
in_string= in_string0;
out_state= out_state0;

if(line_info)
out_pos= 0;
else
{
started_vcmnt= NO;
rst_out(NOT_CONTINUATION);
}
}



SRTN i_version_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
CHK_ARGS("$VERSION",0);

mcopy(version);
}



SRTN i_tm_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*p;
struct tm*t;

CHK_ARGS("$TM",1);

p= pargs[0]+1;/* Should point to a single-digit constant. */

if(*p++!=constant)
{

macro_err(OC("! Argument of $TM must be numerical constant"),YES);
return;
}

t= the_localtime();/* Fill the |tm| structure and return a pointer. */

switch(*p-060)
{/* Convert digit to integer and select routine. */
case 0:
mcopy(the_day(t));
break;

case 1:
/* The date needs to be protected because of the comma. */
MCHECK(2,"the_cdate");
*mp++= 0140;
mcopy(the_cdate(t));
*mp++= 0140;
break;

case 2:
mcopy(the_time(t));
break;

default:

macro_err(OC("! Invalid case in _tm_"),YES);
break;
}
}



SRTN mcopy FCN((s))
CONST outer_char*s C1("")
{
int n= STRLEN(s);

MCHECK(n,"mcopy");
STRCPY(mp,x_to_ASCII(s));
mp+= n;
}



SRTN not_unique(VOID)
{
TRUNC HUGE*s,HUGE*HUGE*ss,HUGE*HUGE*ss0,HUGE*HUGE*ss1;
LANGUAGE Language;
int l;
size_t n;/* Counts number of non-unique variables. */
size_t num_max;/* Maximum \# of roots for any duplicate. */
BP HUGE*HUGE*bb0;
boolean found_dup= NO;

for(l= 0;l<NUM_LANGUAGES;l++)
{
Language= lan_enum(l);

/* Count the number of duplicate variables. */
n= 0;

for(s= &sh;s->next;s= s->next)
{
if(!((boolean)s->Language&(boolean)Language))continue;

if(s->num[l]>1)
{
char temp[10];
unsigned len= tr_max[l];

sprintf(temp,len?"%u":"*",len);

if(n==0)
{
printf("\n\n%c! Non-unique \
%s variables (filtered with {%s}, truncated to length %s):",
beep(1),languages[l],filter_char[l],temp);
found_dup= YES;
}
n++;
}
}

if(n==0)continue;

/* Store the pointers to the duplicates in an array. */
ss1= ss0= ss= GET_MEM("ss",n,TRUNC HUGE*);
num_max= 0;

for(s= &sh;s->next;s= s->next)
{
if(!((boolean)s->Language&(boolean)Language))continue;

if(s->num[l]>1)
{
*ss++= s;
num_max= MAX(num_max,s->num[l]);
}
}

/* Sort the array. */
QSORT(ss0,n,sizeof(TRUNC HUGE*),cmpr_trunc);

/* Print out the sorted array. */
bb0= GET_MEM("bb",num_max,BP HUGE*);

while(ss1<ss)
see_dup(*ss1++,Language,bb0);

FREE_MEM(ss0,"ss",n,TRUNC HUGE*);
FREE_MEM(bb0,"bb",num_max,BP HUGE*);
}

if(found_dup)
NEWLINE;
}

SRTN see_dup FCN((s,Language,bb0))
CONST TRUNC HUGE*s C0("")
LANGUAGE Language C0("")
BP HUGE*HUGE*bb0 C1("")
{
BP HUGE*b,HUGE*HUGE*bb,HUGE*HUGE*bb1;
int n;

NEWLINE;
printf(" ");
n= see(s->id,s->id_end);/* The truncated id. */

/* Space it out so it looks nicely lined up. */
for(n= tr_max[lan_num(Language)]+1-n;n>0;n--)printf(" ");
printf("<=");

/* Print all back references to original variables. */
for(b= s->first,bb= bb0;b!=NULL;b= b->next)
{
if(!((boolean)b->Language&(boolean)Language))continue;

*bb++= b;
}

QSORT(bb0,bb-bb0,sizeof(BP HUGE*),cmpr_bp);

for(bb1= bb0;bb1<bb;bb1++)
{
printf(" ");
see((*bb1)->byte_start,(*bb1)->byte_end);
}
}

int see FCN((c0,c1))
CONST ASCII HUGE*c0 C0("Beginning.")
CONST ASCII HUGE*c1 C1("end.")
{
int n= PTR_DIFF(int,c1,c0);

while(c0<c1)printf("%c",XCHR(*c0++));

return n;/* Length of identifier. */
}



int cmpr_trunc FCN((t0,t1))
TRUNC HUGE**t0 C0("")
TRUNC HUGE**t1 C1("")
{
switch(web_strcmp((*t0)->id,(*t0)->id_end,(*t1)->id,(*t1)->id_end))
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

int cmpr_bp FCN((bb0,bb1))
BP HUGE**bb0 C0("")
BP HUGE**bb1 C1("")
{
switch(web_strcmp((*bb0)->byte_start,(*bb0)->byte_end,
(*bb1)->byte_start,(*bb1)->byte_end))
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




BP HUGE*b_link FCN((s,Language,p0,p1))
TRUNC HUGE*s C0("")
LANGUAGE Language C0("")
CONST ASCII HUGE*p0 C0("")
CONST ASCII HUGE*p1 C1("")
{
BP HUGE*bp;

bp= GET_MEM("bp",1,BP);/* Get a back-pointer structure. */

bp->c= BP_MARKER;

/* Remember language of original variable. */
bp->Language= Language;

/* Record start and end of the original name. */
bp->byte_start= p0;
bp->byte_end= p1;

/* Link back to original |TRUNC| structure. */
bp->Root= s;
s->Language|= (boolean)Language;
s->num[lan_num(Language)]++;/* Count hits for this language. */

return bp;
}



TRUNC HUGE*s_link FCN((s,id,len))
TRUNC HUGE*s C0("Points to the current structure, to be \
filled with info.")
CONST ASCII HUGE*id C0("Truncated identifier.")
unsigned short len C1("Length of truncated identifier.")
{
/* Fill this structure with truncated variable name. */
s->id= GET_MEM("s->id",len,ASCII);/* Space for name. */
STRNCPY(s->id,id,len);/* Copy over name. */
s->id_end= s->id+len;/* End of name. */

/* Attach another (uninitialized) structure. */
s->next= GET_MEM("s->next",1,TRUNC);

return s;
}



name_pointer id0_lookup FCN((start,end,l))
CONST ASCII HUGE*start C0("Start of name.")
CONST ASCII HUGE*end C0("end of name.")
LANGUAGE l C1("")
{
name_pointer np;
CONST ASCII HUGE*p0,HUGE*p1;

for(np= name_dir+1;np<name_ptr;np++)
{
if(!(np->Language&(boolean)l)||
np->equiv!=NULL||*(p0= np->byte_start)==BP_MARKER)
continue;

PROPER_END(p1);

if(web_strcmp(p0,p1,start,end)==EQUAL)
return np;
}

return NULL;
}



unsigned trunc_id FCN((np0))
CONST name_pointer np0 C1("Points to current id structure.")
{
CONST ASCII HUGE*p,HUGE*p0,HUGE*p1;/* For original identifier. */
ASCII temp[N_IDBUF];
ASCII HUGE*t;/* For truncated identifier. */
unsigned short n;/* Length of truncated identifier. */
TRUNC HUGE*s;
name_pointer np;
unsigned short nmax;/* Truncate to this length. */
LANGUAGE Language;
int l;
unsigned count= 0;

if(np0->Language==(boolean)NO_LANGUAGE||np0->equiv!=NULL)
return 0;

for(l= 0;l<NUM_LANGUAGES;l++)
{
Language= lan_enum(l);
np= np0;

/* Don't bother with it if there's no truncation specified for this \
language, if it's not in use for this language, if it's a reserved word, \
intrinsic word, or keyword, or if it's a \WEB\ macro. */
if((nmax= tr_max[l])==0||!(np->Language&(boolean)Language)
||(np->reserved_word&(boolean)Language)
||(np->intrinsic_word&(boolean)Language)
||(np->keyword&(boolean)Language)
||(np->macro_type!=NOT_DEFINED))
continue;

/* The original name. */
p0= np->byte_start;

if(*p0==BP_MARKER)
continue;/* NEED MORE WORK HERE (variable already deflected). */

PROPER_END(p1);

/* Filter. */
for(p= p0,t= temp,n= 0;p<p1&&n<nmax;p++)
if(STRCHR(filter_char[l],(int)XCHR(*p))==NULL)
{
n++;
*t++= *p;
}

n= PTR_DIFF(unsigned short,t,temp);/* Length of truncated identifier. */

if(p1-p0==(long)n)
continue;/* Not truncated; nothing to do. */

count++;/* Count number of truncations for this identifier. */

/* Is the truncated name already in the list? */
for(s= &sh;s->next!=NULL;s= s->next)
if(s->id_end-s->id==(long)n&&
web_strcmp(s->id,s->id_end,temp,t)==EQUAL)
{
another_bp:
s->last= s->last->next= b_link(s,Language,p0,p1);
/* Remember the original variable by attaching another back reference. */
np->byte_start= (ASCII*)s->last;/* Deflect original ptr. */
goto next_language;
}

/* Add a new name to the list. */
s= s_link(s,temp,n);
s->first= s->last= b_link(s,Language,p0,p1);/* Attach first back reference. */
np->byte_start= (ASCII*)s->first;/* Deflect original ptr. */

/* If the truncated name was in the original list, not previously truncated \
from something else, put the original name into the truncated list. */
if((np= id0_lookup(temp,t,(LANGUAGE)np->Language))!=NULL)
{
p0= np->byte_start;PROPER_END(p1);
goto another_bp;
}

next_language:;
}

return count;
}



SRTN open_out FCN((msg,global_scope))
CONST outer_char*msg C0("")
boolean global_scope C1("")
{
boolean is_stdout= BOOLEAN(STRCMP(params.OUTPUT_FILE_NAME,"stdout")==0);
boolean already_opened= NO;

if(is_stdout)
out_file= params.OUT_FILE= stdout;
else
{
already_opened= was_opened(params.OUTPUT_FILE_NAME,global_scope,
NULL,&out_file);

params.OUT_FILE= out_file;/* Local output file. */

/* Write header info to the newly opened file. (We don't write it for \
|stdout|, because it clutters up the screen.) */
if(top_version&&!(already_opened||compare_outfiles))
out_version(msg);
}

/* The first time a file is opened for a particular language, its |FILE| \
pointer must be made global so it can be restored at the beginning of each \
module.  (The name was already made global in |common_init|.) */
if(global_scope)
cur_global_params.OUT_FILE= global_params.OUT_FILE= out_file;

/* The first time a file is opened, write its name to the screen. */
if(!already_opened)
{
CLR_PRINTF(out_file,("(%s)%s",(char*)params.OUTPUT_FILE_NAME,
is_stdout?"\n":""));
UPDATE_TERMINAL;
}
}



boolean was_opened FCN((file_name,global_scope,pname,pfile_ptr))
CONST outer_char HUGE*file_name C0("")
boolean global_scope C0("")
outer_char HUGE*HUGE*pname C0("")
FILE**pfile_ptr C1("")
{
OPEN_FILE HUGE*f;

if(!*file_name)
{/* Take care of special cases called by |xpn_name|. */
*pname= (outer_char HUGE*)"";
*pfile_ptr= NULL;
return NO;
}

/* Is file already in the list of previously opened? */
for(f= open_file;f<last_file;f++)
if(STRCMP(f->name,file_name)==0)
{
if(pname)
{/* Just return (to |new_fname|) some information. */
*pname= f->name;
*pfile_ptr= f->ptr;
return f->previously_opened;
}
else
goto open_it;
}


{
/* File not in list; is there room for more? */
if(last_file==open_file_end)
{
OVERFLW("previously opened files","nf");
}

last_file->name= GET_MEM("last_file",STRLEN(file_name)+1,outer_char);
STRCPY(last_file->name,file_name);
last_file++;
}



if(pname)
{/* File wasn't previously opened, and has now been added to list \
of file names. */
*pname= f->name;
f->ptr= NULL;
f->previously_opened= NO;
f->global_scope= global_scope;
}
else

{
open_it:
f->previously_opened= BOOLEAN(f->previously_opened||(f->ptr!=NULL));

if(f->previously_opened)
{/* It might have been once opened, but then closed. */
if(f->ptr==NULL)
f->ptr= FOPEN(compare_outfiles?f->tmp_name:f->name,"a");
}
else
{/* File wasn't ever opened. */
if(compare_outfiles)

{
char*buffer;
IN_COMMON outer_char wbprefix[MAX_FILE_NAME_LENGTH];

#if(HAVE_TEMPNAM)
extern char*tempnam();

if(!*wbprefix)
STRCPY(wbprefix,"./");

buffer= tempnam((char*)wbprefix,"FTMP");
/* Non-|ANSI|, but more control over directory. */
#else
buffer= tmpnam(NULL);/* |ANSI| routine. */
#endif

f->tmp_name= GET_MEM("f->tmp_name",STRLEN(buffer)+1,outer_char);

STRCPY(f->tmp_name,buffer);

f->ptr= FOPEN(f->tmp_name,"w");
}


else
f->ptr= FOPEN(f->name,"w");

if(!(f->ptr))
{/* Should upgrade this message. */
FATAL(T,"\n!! Can't open output file ",file_name);
}
}
}



*pfile_ptr= f->ptr;
return f->previously_opened;
}



SRTN close_out FCN((fp))
FILE*fp C1("")
{
OPEN_FILE*f;

for(f= open_file;f<last_file;f++)
if(f->ptr==fp)
{
close0(f);
return;
}

CONFUSION("close_out","Allegedly open file isn't in list");
}



SRTN cls_local(VOID)
{
OPEN_FILE*f;

for(f= open_file;f<last_file;f++)
if(f->ptr&&!f->global_scope)
close0(f);
}


SRTN close0 FCN((f))
OPEN_FILE*f C1("")
{
fclose(f->ptr);
f->ptr= NULL;
f->previously_opened= YES;
}



SRTN
cls_files(VOID)
{}


SRTN cmp_outfiles(VOID)
{
OPEN_FILE*f;
boolean renamed= NO;

printf("\nRenaming temporary file(s):  ");
UPDATE_TERMINAL;

for(f= open_file;f<last_file;f++)
if(f->previously_opened||f->ptr)
{
FILE*old_ptr= FOPEN(f->name,"r");

if(f->ptr)
fflush(f->ptr);

if(old_ptr)

{
int c_old,c_new;
FILE*new_ptr;

if(f->ptr)
new_ptr= freopen((CONST char*)f->tmp_name,"r",f->ptr);
else
new_ptr= FOPEN(f->tmp_name,"r");

if(!new_ptr)
FATAL(T,"\n!! Can't reopen temporary file ",f->tmp_name);

do
{
c_old= getc(old_ptr);
c_new= getc(new_ptr);
}
while(c_old==c_new&&c_old!=EOF);

fclose(old_ptr);
fclose(new_ptr);

if(c_old==c_new)
remove((CONST char*)f->tmp_name);/* Harmless if this doesn't work. */
else

{
/* Try to ensure that the following |rename| will succeed. */
remove((CONST char*)f->name);

printf("(%s",(char*)f->name);/* Echo to terminal. */

if(rename((CONST char*)f->tmp_name,(CONST char*)f->name)!=0)
{/* Rename didn't work.  Attempt to force the rename by issuing a \
\.{mv} command.  The actual name of the command is obtained from the \
preprocessor variable |MV|, which is defined on the command line and whose \
value is ultimately defined in \.{defaults.mk}. */
#if ANSI_SYSTEM
if(!system(NULL))
{/* No command processor! */

err0_print(ERR_T,OC("Couldn't rename \"%s\" to \"%s\""),2,f->tmp_name,f->name);
perror("");
}
else
#endif /* |ANSI_SYSTEM| */
{
char temp[256];

/* We put the following here in case for some reason the make file can't \
define |MV|.  This is the case with some versions of \.{nmake} on the PC. */
#ifndef MV
#ifdef ibmpc
#define MV "rename"
#else
#define MV "mv"
#endif
#endif
sprintf(temp,"%s %s %s",MV,(char*)f->tmp_name,
(char*)f->name);
system(temp);
printf("*");/* Indicate a copy was done. */
}
}

printf(")");UPDATE_TERMINAL;

renamed= YES;
}


}


else

{
/* Try to ensure that the following |rename| will succeed. */
remove((CONST char*)f->name);

printf("(%s",(char*)f->name);/* Echo to terminal. */

if(rename((CONST char*)f->tmp_name,(CONST char*)f->name)!=0)
{/* Rename didn't work.  Attempt to force the rename by issuing a \
\.{mv} command.  The actual name of the command is obtained from the \
preprocessor variable |MV|, which is defined on the command line and whose \
value is ultimately defined in \.{defaults.mk}. */
#if ANSI_SYSTEM
if(!system(NULL))
{/* No command processor! */

err0_print(ERR_T,OC("Couldn't rename \"%s\" to \"%s\""),2,f->tmp_name,f->name);
perror("");
}
else
#endif /* |ANSI_SYSTEM| */
{
char temp[256];

/* We put the following here in case for some reason the make file can't \
define |MV|.  This is the case with some versions of \.{nmake} on the PC. */
#ifndef MV
#ifdef ibmpc
#define MV "rename"
#else
#define MV "mv"
#endif
#endif
sprintf(temp,"%s %s %s",MV,(char*)f->tmp_name,
(char*)f->name);
system(temp);
printf("*");/* Indicate a copy was done. */
}
}

printf(")");UPDATE_TERMINAL;

renamed= YES;
}

/* No old file at all. */
}

if(!renamed)
printf("[no changes]");
}



SRTN out_op FCN((s))
CONST outer_char HUGE*s C1("String to translate.")
{
out_str(s);

out_state= MISCELLANEOUS;
}

CONST outer_char HUGE*out_str FCN((s0))
CONST outer_char HUGE*s0 C1("")
{
CONST outer_char HUGE*s;

for(s= s0;*s;s++)
C_putc(*s);

return s0;
}



eight_bits x_identifier FCN((cur_char))
eight_bits cur_char C1("")
{
if(!in_cdir)

{
boolean in_macro0= in_macro;
name_pointer np= name_dir+cur_val;
X_FCN(HUGE_FCN_PTR*pf)(VOID);/* Fcn.\ associated with expandable keywords. */

if(np->expandable&language)
{
expand_special:
in_macro= NO;/* Don't suppress recursive expansion of macros. */

pf= np->x_translate[lan_num(language)];

if(pf)
(*pf)();/* Expand keyword. */
else
CONFUSION("possibly expand special",
"Allegedly expandable keyword has no associated function");

in_macro= in_macro0;

cur_char= id_keyword;/* Helps \Ratfor\ know what happened. */
goto end_identifier;
}
else if(R77&&Fortran88&&!checking_label)
switch(chk_lbl())
{
case YES:goto expand_special;
case-1:goto end_identifier;
case NO:break;
}
}

;

if(is_deferred((sixteen_bits)cur_val))
return cur_char;

/* |MAC_LOOKUP| determines whether this is a WEB macro. Eventually, this \
routine will be called recursively to output the expansion. The |in_macro| \
flag prevents us from checking the expanded tokens again, since everything \
will already have been expanded. */
if(!mac_protected&&(macro_text= MAC_LOOKUP(cur_val))!=NULL)
{

{
eight_bits HUGE*p1;


in_macro= YES;/* Used as a flag to prevent |MAC_LOOKUP| on \
	recursive |out_char| output of the final translated macro. */

p1= xmacro(macro_text,&cur_byte,cur_end,macrobuf);/* Expand this \
	macro into the macro buffer. The final expansion will begin at |p1| \
	and end at~|mp|. */

/* Output final translated text, which begins at the end~|p1| of the last \
translation and ends at the current value of~|mp|. This calls |out_char| \
recursively.  */
copy_out(p1,mp,macro);
in_macro= NO;
}


return cur_char;
}
else
{/* Not a macro. */

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}



if(out_state==NUM_OR_ID&&!nuweb_mode)
C_putc(' ');


{
name_pointer np;


np= name_dir+cur_val;

if(truncate_ids)
out_trunc(np);
else
see_id(np->byte_start,(np+1)->byte_start);
}

;

if(no_expand)
no_expand= mac_protected= NO;
}

end_identifier:
out_state= in_format?MISCELLANEOUS:NUM_OR_ID;

return cur_char;
}



boolean is_deferred FCN((cur_val))
sixteen_bits cur_val C1("")
{
name_pointer np;

np= name_dir+cur_val;

if(np->macro_type==DEFERRED_MACRO)
{
text_pointer tp;
eight_bits HUGE*p0;
eight_bits a0;

tp= (text_pointer)np->equiv;/* Position in the deferred pool. */

/* Copy the tokens of the definition over into the next text. */
for(p0= tp->tok_start;p0<(tp+1)->tok_start;)
if(TOKEN1(a0= *p0++))
if(a0==043)
switch(*p0)
{
case 041:
if(*(p0+1)==MACRO_ARGUMENT)
app_repl(a0)
else

{
if(TOKEN1(*++p0))

macro_err(OC("! Macro token `#!' must be followed by identifier"),YES);
else
{
text_pointer m;

if((m= MAC_LOOKUP(IDENTIFIER(*p0,*(p0+1))))==NULL)

macro_err(OC("! Expecting macro identifier after \"#!\""),YES);
else
if(m->nargs>0)

macro_err(OC("! Macro after \"#!\" can't have arguments"),YES);
else
{
eight_bits HUGE*q0,HUGE*q1;


q0= m->tok_start+m->moffset;
q1= (m+1)->tok_start;

/* Just copy the definition without expanding. */
while(q0<q1)app_repl(*q0++);
}



p0+= 2;
}
}


break;

default:
app_repl(a0);
break;
}
else app_repl(a0)/* Single token, not special. */
else
{
app_repl(a0);
app_repl(*p0++);
}

cur_text= text_ptr;
cur_text->Language= (boolean)language;
cur_text->nargs= tp->nargs;
cur_text->moffset= tp->moffset;
cur_text->var_args= tp->var_args;
cur_text->recursive= NO;
cur_text->text_link= macro;

(++text_ptr)->tok_start= tok_ptr;

np= name_dir+IDENTIFIER(tp->tok_start[0],tp->tok_start[1]);
np->macro_type= IMMEDIATE_MACRO;/* Now the defn's been executed. */
np->equiv= (EQUIV)cur_text;

return YES;/* It's a deferred macro. */
}

return NO;/* Not a deferred macro. */
}



SRTN out_ptrunc FCN((cur_val))
sixteen_bits cur_val C1("")
{

{
name_pointer np;


np= name_dir+cur_val;

if(truncate_ids)
out_trunc(np);
else
see_id(np->byte_start,(np+1)->byte_start);
}


}



SRTN see_id FCN((start,end))
CONST ASCII HUGE*start C0("Beginning of identifier name.")
CONST ASCII HUGE*end C1("End of identifier name.")
{
CONST ASCII HUGE*j;

for(j= start;j<end;j++)C_putc(XCHR(*j));
}



int id FCN((n))
int n C1("Identifier number.")
{
printf(_Xx("Id %d (0x%x): \"%s\"\n"),n,n,(char*)name_of((sixteen_bits)n));
return n;
}



outer_char HUGE*name_of FCN((id0))
sixteen_bits id0 C1("Identifier token whose name is sought.")
{
static ASCII temp[MAX_ID_LENGTH];
int k,n;
name_pointer np;
CONST ASCII HUGE*end;

np= name_dir+id0;

/* Don't choke on bad id. */
if(np>=name_ptr)
{
STRCPY(temp,"???");
return(outer_char HUGE*)temp;
}

PROPER_END(end);

#if 0 /* This construction gives a compiler error on the IBM/6000. */
n= MIN(end-np->byte_start,MAX_ID_LENGTH-1);
#else
if(end-np->byte_start<MAX_ID_LENGTH-1)
n= PTR_DIFF(int,end,np->byte_start);
else
n= MAX_ID_LENGTH-1;
#endif

STRNCPY(temp,np->byte_start,n);

/* We must be careful when breakpointing; backslashes must be escaped. */
if(breakpoints)
for(k= 0;k<n;k++)
if(temp[k]==0134)temp[k]= 057;

temp[n]= '\0';

return to_outer(temp);
}



CONST ASCII HUGE*proper_end FCN((np))
name_pointer np C1("")
{
CONST ASCII HUGE*end;

PROPER_END(end);
return end;
}

SRTN out_trunc FCN((np))
CONST name_pointer np C1("")
{
TRUNC HUGE*s;
ASCII HUGE*pc;

pc= np->byte_start;

if(*pc!=BP_MARKER)
{/* Not truncated. */
CONST ASCII HUGE*end;

/* If the next one was truncated, recover the proper end location. */
PROPER_END(end);
see_id((CONST ASCII HUGE*)pc,end);
}
else
{/* Truncated. */
s= ((BP HUGE*)pc)->Root;
see_id(s->id,s->id_end);
}
}



SRTN prn_mod_num FCN((fmt,val))
outer_char*fmt C0("")
long val C1("")
{
int l;

if(line_info)
{
l= lan_num(R77_or_F&&!free_90?FORTRAN:language);

if(val<0)
{/* Ending a section. */
val= -val;
}

if(FORTRAN_LIKE(language))
{
if(out_pos>rst_pos)flush_out(YES);
out_pos= 0;
}

C_sprintf(fmt,3,begin_comment_char[l],val,end_comment_char[l]);
}
}



eight_bits skip_ahead FCN((last_control,skip_over_bars))
eight_bits last_control C0("Last token that was seen.")
boolean skip_over_bars C1("")
{
eight_bits cc;/* Control code found. */
int ncc= 0;/* A counter that counts the \.{@}s; \
		used to figure out whether to ignore section \
		names immediately after \.{@f}. */
ASCII last_char;
ASCII HUGE*lc;
ASCII HUGE*l1= limit+1;

WHILE()
{
if(loc>limit)
{
another_line:
if(from_buffer)
{
undivert();/* Switch back to reading from files. */
return ignore;
}
else
{
if(!get_line())
return new_module;

l1= limit+1;
}
}

*l1= 0100;/* Barrier to stop high-speed scan through line. */

more_stuff:
switch(*loc)
{
case 0100:
break;

case 0174:
if(skip_over_bars)
{
if(skip_bars()==new_module)return new_module;
/* It's now positioned after the bar. */
continue;
}

/* Otherwise, we're in limbo or scanning control text; just keep going. */

default:
loc++;
if(loc>limit)
{
ncc= 2;
goto another_line;
}
goto more_stuff;
}

*l1= 040;/* Reset line terminator. */

if(loc>limit)ncc= 2;
else
{
last_char= 040;/* Get the last non-blank character before this control code. */

for(lc= loc-1;lc>=cur_buffer;lc--)
if(*lc!=040)
{
last_char= *lc;/* This might be a vertical bar. */
break;
}

++loc;/* Position to after the~\.{@}. */
++ncc;/* Count the \.{@}s. */

switch(cc= ccode[*(loc++)])
{/* Position to after \.{@?}. */


case begin_C:
case begin_RATFOR:
case begin_FORTRAN:
case begin_LITERAL



:
loc--;/* Position to language letter; fall through. */

case L_switch:
{
if(last_char!=0174)
{

{
ASCII l= *loc++;/* The basic language letter. */

switch(l)
{

case 0143:case 0103

:
Cpp= BOOLEAN(*loc==053);
break;


case 0162:case 0122

:

case 0156:case 0116

:
Fortran88= BOOLEAN(*loc==071);
break;


case 0166:case 0126



:

case 0170:case 0130

:
break;

default:

err0_print(ERR_C,OC("! Invalid language command `@L%c' ignored"),1,XCHR(l));
break;
}

opt_args(l);/* Set the language, and parse optional arguments after \
		language command. */
}



if(module_count==0)global_params= params;
set_output_file(language);
}
continue;
}

case begin_nuweb:
nuweb_mode1= nuweb_mode= !NUWEB_MODE;

if(module_count==0)
global_params= params;

continue;

case control_text:
while((c= skip_ahead(ignore,NO))==0100);
/* only \.{@@} and \.{@>} are expected *//* Is |c| used?? */

if(*(loc-1)!=076)
err0_print(ERR_T,OC("Improper @ within control text"),0);

continue;

case compiler_directive:
case Compiler_Directive:
if(scanning_TeX)

err0_print(ERR_T,OC("Compiler directives are allowed only in code"),0);
loc= limit+1;
continue;

case invisible_cmnt:
loc= limit+1;
continue;

case module_name:
if(ncc==1&&last_control==formatt)
{
loc-= 2;
get_next();/* Scan module name to get it into table. */
continue;
}
break;

case big_line_break:/* \.{@\#} */
if(loc>=limit)continue;


{
boolean mcode;

*limit= ' ';/* Terminator for identifier search. */
id_first= loc;

while(isAlpha(*loc))loc++;/* Find end of identifier. */

if((mcode= is_mcmd(mcmds,id_first,loc))!=0)
{
while(loc<limit&&(*loc==040||*loc==tab_mark))
loc++;

return mcode;
}

loc= id_first;/* Failed to recognize preprocessor command. */
}


;/* (See \.{typedefs.web}.) */
continue;

case USED_BY_NEITHER:

err0_print(ERR_T,OC("Invalid `@%c' ignored"),1,XCHR(*(loc-1)));
continue;
}

if(cc!=ignore||(*(loc-1)==076&&(ncc!=2)&&last_control!=formatt))
return cc;/* \.{@}~code or end of module name. */
}


}

DUMMY_RETURN(ignore);
}



eight_bits skip_bars(VOID)
{
PARAMS params0;
LANGUAGE language0= language;
eight_bits ret_val;

params0= params;/* Save state. */

loc++;/* Advance past the opening bar. */

WHILE()
{
if(loc>limit&&!get_line())
{

err0_print(ERR_T,OC("Reached end of file while skipping code text %s"),1,BTRANS);
ret_val= new_module;
goto done;
}

switch(next_control= get_next())
{
case begin_bp:
case insert_bp:
case begin_meta:
case end_meta:
case formatt:
case limbo_text:
case op_def:
case macro_def:
case definition:
case undefinition:
case WEB_definition:
case m_ifdef:
case m_ifndef:
case m_else:
case m_elif:
case m_endif:
case m_for:
case m_endfor:
case m_line:
case m_undef:
case begin_code:

err0_print(ERR_T,OC("Control code not allowed within |...|; \
inserted '|' in %s"),1,MTRANS);
loc-= 2;
ret_val= 0174;
goto done;

case new_module:

err0_print(ERR_T,OC("Module%s ended while skipping code text; \
inserted '|'"),1,MTRANS0);/* Falls through to next case! */

case 0174:
ret_val= next_control;
goto done;
}
}

done:
params= params0;
frz_params();
set_output_file(language0);

return ret_val;
}


#endif /* |Part == 1| */

#if(part == 0 || part == 2)


eight_bits out_char FCN((cur_char))
eight_bits cur_char C1("Token to control or be sent to the output.")
{
switch(cur_char)
{
case ignore:
if(R77_or_F&&started_vcmnt)C_putc(cur_char);
return 040;/* KLUDGE  to prevent |get_output| from being \
terminated prematurely. */

/* In nuweb mode, tab is mapped to bell on input, and back again here. */
case bell:
return out_dflt(tab_mark);

case 054:
out_dflt(cur_char);

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


break;

case interior_semi:
if(!(Fortran88||in_string))cur_char= 073;
/* Fall through to regular semicolon. */

case 073:


if(send_rp)
{
C_putc(')');/* Not |buffer_out| because of \.{-)}. */
send_rp= NO;/* Clear the flag. */
}

;
return out_dflt(cur_char);

case cdir:
in_cdir= BOOLEAN(!in_cdir);

if(FORTRAN_LIKE(language))
{
in_string= NO;
flush_buffer();
in_string= YES;
}
break;

case 012:
if((copying_macros||!nuweb_mode)
&&(protect||out_state==VERBATIM))
{
/* Outer macros are absorbed with no explicit backslash at end of line. \
Furthermore, spaces are stripped from the start of the next line. \
Therefore, we will think of the end of line as a space.  Contrast this with \
explicit \.{\#define}'s continued with a backslash, which just abuts the \
last character of the line with the first character of the next one. */
if(copying_macros&&protect&&!in_string)
C_putc(' ');

out_str(t_style.protect_chars[lan_num(language)]);
/* Backslash at end of line. */
}


if(send_rp)
{
C_putc(')');/* Not |buffer_out| because of \.{-)}. */
send_rp= NO;/* Clear the flag. */
}

;
flush_buffer();
if(out_state!=VERBATIM)
out_state= MISCELLANEOUS;
break;


case end_format_stmt:
in_format= NO;
C_putc(';');
out_state= NUM_OR_ID;
break;

case begin_format_stmt:
in_format= YES;
OUT_OP(" format");
out_state= MISCELLANEOUS;
break;

case identifier:
cur_char= x_identifier(cur_char);
break;


;


case module_number:
if(cur_val>0)
prn_mod_num(OC("%c* %ld: *%c\n"),cur_val);/* Beginning. */
else if(cur_val<0)
prn_mod_num(OC("%c* :%ld *%c\n"),cur_val);/* End. */
else
{/* Print out the line number; remember it for error messages. */
if(line_info)
{
nearest_line= (LINE_NUMBER)(BASE2*(*cur_byte++));
nearest_line+= *cur_byte++;/* Gets the line number. */

C_sprintf(OC("%cline %u \""),2,
language==TEX?'%':'#',nearest_line);

/* Get pointer to file name. */
cur_val= BASE2*(*cur_byte++);
cur_val+= *cur_byte++;


{
name_pointer np;


np= name_dir+cur_val;

if(truncate_ids)
out_trunc(np);
else
see_id(np->byte_start,(np+1)->byte_start);
}


C_sprintf(OC("\"\n"),0);
}
else
cur_byte+= 4;
}

break;

;


case plus_plus:
if(FORTRAN_LIKE(language))
{

{
outer_char HUGE*l;


/* The left-hand side has already been output. */
C_putc('=');/* Not |buffer_out| because of \.{-)}. */
plast_char--;/* We don't want the '\.{=}' in the lhs buffer. */
out_state= MISCELLANEOUS;

/* Now output the |i|~in the above \
example again; however, in general, that could be subscripted etc. */
if(compound_assignments)
{
send_rp= YES;

if(last_xpr_overflowed)
OVERFLW("last expression","lx");

for(l= last_char;isdigit(*l)||!isalpha(*l);l++)
;

if(plast_char-l>=3&&STRNCMP(last_char,"if(",3)==0)

err0_print(ERR_T,OC("Sorry, can't expand compound assignment \
operators correctly after simple IF; use an IF...THEN construction"),0);

while(l<plast_char)
buffer_out(*l++);/* Echo the lhs. */

send_rp= NO;
}
else
FATAL(T,"!! Operators ++, --, +=, -=, *=, and /= are not allowed; \
they were turned off by option \"-+\".","");
}

;
buffer_out('+');buffer_out('1');
out_state= MISCELLANEOUS;
}
else
{
if(*(pC_buffer-1)=='+'&&!nuweb_mode)
C_putc(' ');/* Watch out for |x + ++y|. */
OUT_OP("++");
}


{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


break;

case minus_minus:
if(FORTRAN_LIKE(language))
{

{
outer_char HUGE*l;


/* The left-hand side has already been output. */
C_putc('=');/* Not |buffer_out| because of \.{-)}. */
plast_char--;/* We don't want the '\.{=}' in the lhs buffer. */
out_state= MISCELLANEOUS;

/* Now output the |i|~in the above \
example again; however, in general, that could be subscripted etc. */
if(compound_assignments)
{
send_rp= YES;

if(last_xpr_overflowed)
OVERFLW("last expression","lx");

for(l= last_char;isdigit(*l)||!isalpha(*l);l++)
;

if(plast_char-l>=3&&STRNCMP(last_char,"if(",3)==0)

err0_print(ERR_T,OC("Sorry, can't expand compound assignment \
operators correctly after simple IF; use an IF...THEN construction"),0);

while(l<plast_char)
buffer_out(*l++);/* Echo the lhs. */

send_rp= NO;
}
else
FATAL(T,"!! Operators ++, --, +=, -=, *=, and /= are not allowed; \
they were turned off by option \"-+\".","");
}

;
buffer_out('-');buffer_out('1');
out_state= MISCELLANEOUS;
}
else
{
if(*(pC_buffer-1)=='-'&&!nuweb_mode)
C_putc(' ');/* Watch out for |x - --y|. */
OUT_OP("--");
}


{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


break;

case minus_gt:OUT_OP(FORTRAN_LIKE(language)?".EQV.":"->");break;

case gt_gt:

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


OUT_OP(">>");break;

case eq_eq:

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


OUT_OP(R77_or_F?F_OP(".EQ.","=="):"==");break;

case lt_lt:

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


OUT_OP("<<");break;

case 076:
if(in_string||in_format)
out_dflt(cur_char);
else
{
OUT_OP(R77_or_F?F_OP(".GT.",">"):">");
if(language==C_PLUS_PLUS)
C_putc(' ');/* For protecting nested templates. */
}


{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


break;

case gt_eq:
OUT_OP(R77_or_F?F_OP(".GE.",">="):">=");

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


break;

case 074:
if(in_string||in_format)
out_dflt(cur_char);
else
OUT_OP(R77_or_F?F_OP(".LT.","<"):"<");


{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


break;

case lt_eq:
OUT_OP(R77_or_F?F_OP(".LE.","<="):"<=");

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


break;

case not_eq:
OUT_OP(R77_or_F?F_OP(".NE.","/="):"!=");

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


break;

case and_and:
OUT_OP(R77_or_F?".AND.":"&&");

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


break;

case or_or:
if(language==TEX)meta_mode= YES;
else
{
OUT_OP(R77_or_F?".OR.":"||");

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


}
break;

case star_star:
if(language==TEX)meta_mode= NO;
else OUT_OP(C_LIKE(language)?"^^":"**");
break;

case 041:

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


if(in_string)
return out_dflt(cur_char);
else
OUT_OP(R77_or_F?".NOT.":"!");
break;

case slash_slash:OUT_OP("//");break;

case colon_colon:
if(in_string&&!nuweb_mode)
return out_dflt(cur_char);/* The purpose of this clause \
isn't clear.  Note |colon_colon == tab_mark|.  Presently, |colon_colon| \
is active only for \Cpp. */
else
OUT_OP("::");
break;

case ellipsis:
OUT_OP(FORTRAN_LIKE(language)?".NEQV.":"...");

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


break;

case paste:OUT_OP("##");break;

case dot_const:
C_putc('.');
STRCPY(dot_op.name+1,dots[cur_val].symbol);
to_outer(dot_op.name+1);
OUT_OP(OC(dot_op.name+1));
C_putc('.');
break;

;

case 053:
case 055:
case 052:
case 057:
/* These operators are handled in \Tangle\ as two adjacent tokens; we have \
to check for that, and we dare not be in |VERBATIM| mode. */
if(!FORTRAN_LIKE(language)||
cur_byte==cur_end||*cur_byte!=075||
out_state==VERBATIM||!xpn_Ratfor)
{
if(cur_char==052&&C_LIKE(language)&&out_state!=VERBATIM
&&*(pC_buffer-1)=='/'&&!nuweb_mode)
C_putc(' ');/* Watch out for |x/ *p|; not a comment. */

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


return out_dflt(cur_char);
}

cur_byte++;/* Skip over the `\.='. */

{
outer_char HUGE*l;


/* The left-hand side has already been output. */
C_putc('=');/* Not |buffer_out| because of \.{-)}. */
plast_char--;/* We don't want the '\.{=}' in the lhs buffer. */
out_state= MISCELLANEOUS;

/* Now output the |i|~in the above \
example again; however, in general, that could be subscripted etc. */
if(compound_assignments)
{
send_rp= YES;

if(last_xpr_overflowed)
OVERFLW("last expression","lx");

for(l= last_char;isdigit(*l)||!isalpha(*l);l++)
;

if(plast_char-l>=3&&STRNCMP(last_char,"if(",3)==0)

err0_print(ERR_T,OC("Sorry, can't expand compound assignment \
operators correctly after simple IF; use an IF...THEN construction"),0);

while(l<plast_char)
buffer_out(*l++);/* Echo the lhs. */

send_rp= NO;
}
else
FATAL(T,"!! Operators ++, --, +=, -=, *=, and /= are not allowed; \
they were turned off by option \"-+\".","");
}

;
out_dflt(cur_char);
send_rp= YES;/* The enclosing right paren will be output when the \
next newline is encountered. */
C_putc('(');/* Not |buffer_out| because of \.{-)}. */
break;

;

case 075:
C_putc('=');

if(out_state!=VERBATIM)
{
if(C_LIKE(language)&&!nuweb_mode)
C_putc(' ');/* Space after ambiguous character. */

out_state= MISCELLANEOUS;
}


{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


break;

case join:out_state= UNBREAKABLE;break;

case constant:
if(out_state==VERBATIM)
out_state= in_format?MISCELLANEOUS:NUM_OR_ID;
/* End of constant. */
else
{/* Beginning of constant. */

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}



if(out_state==NUM_OR_ID&&!nuweb_mode)
C_putc(' ');

out_state= VERBATIM;
}

in_constant= BOOLEAN(!in_constant);
break;

case stringg:
if(in_string)
out_state= MISCELLANEOUS;/* End of string. */
else
{/* Begining of string. */

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}



if(out_state==NUM_OR_ID&&!nuweb_mode)
C_putc(' ');/* Strings after \
identifiers can happen in macro definitions. */

out_state= VERBATIM;
}

in_string= BOOLEAN(!in_string);
break;

case begin_meta:
/* If there are two |begin_meta|s in a row, the second one means to turn \
off the |xpn_Ratfor| flag, which among other things is used to control the \
spacing after the comment character in \Fortran\ output. */
pmeta= &t_style.meta[lan_num(language)];

switch(language)
{
outer_char*t;

case C:
case C_PLUS_PLUS:
case LITERAL:
case TEX:
if(meta_mode)
break;

if(!nuweb_mode)
{
if(in_string&&!in_version)
OUT_STR(t= pmeta->msg.top);
else
OUT_OP(t= pmeta->hdr.top);

if(*t)
OUT_STR("\n");/* Necessary???? */
}
meta_mode= YES;
break;

case RATFOR:
case RATFOR_90:
case FORTRAN:
case FORTRAN_90:
if(meta_mode)
xpn_Ratfor= NO;
C_putc(cur_char);
out_state= MISCELLANEOUS;
break;

default:
CONFUSION("out_char:begin_meta","Language not defined");
}
break;

case end_meta:
meta_mode= NO;

switch(language)
{
outer_char*t;

case C:
case C_PLUS_PLUS:
case LITERAL:
case TEX:
if(meta_mode)break;

if(!nuweb_mode)
{
if(in_string&&!in_version)
OUT_OP(t= pmeta->msg.bottom);
else
OUT_OP(t= pmeta->hdr.bottom);

if(*t)OUT_OP("\n");/* Necessary???? */
}
break;

case RATFOR:
case RATFOR_90:
case FORTRAN:
case FORTRAN_90:
xpn_Ratfor= YES;
C_putc(cur_char);
out_state= MISCELLANEOUS;
break;

default:
CONFUSION("out_char:end_meta","Language not defined");
}

break;

case 0173:
if(R77&&!in_string)

{
cp_fcn_body();/* See \.{rat77.web}. */
cur_char= 01;
}


else
{

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


return out_dflt(cur_char);
}
break;

/* The following doesn't work right when there's no |program| statement. */
case 0175:
{
if(R77&&!in_string&&brace_level==0)

RAT_error(WARNING,OC("Spurious '}' ignored, \
or missing program, module, subroutine, or function statement"),0);
else
{
out_dflt(cur_char);

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


}
}

break;

case 0133:
out_bracket(cur_char,050);
break;

case 0135:
out_bracket(cur_char,051);
break;


case 0140:
if(!(in_string||language==LITERAL))
{
mac_protected= BOOLEAN(!mac_protected);
break;
}
else
return out_dflt(cur_char);

case 046:
if(C_LIKE(language)&&out_state!=VERBATIM
&&*(pC_buffer-1)=='&'&&!nuweb_mode)
C_putc(' ');/* Handle the situation |x & &y|. */

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif /* |FANCY_SPLIT| */
}


return out_dflt(cur_char);

case 0134:
if(R66)
cur_char= 044;/* Change octal constant to \Ratfor's \
argument token. This is kludgy and obsolete. */

default:
return out_dflt(cur_char);
}

return cur_char;
}



eight_bits out_bracket FCN((cur_char,new_char))
eight_bits cur_char C0("")
eight_bits new_char C1("")
{
if(out_state!=VERBATIM&&FORTRAN_LIKE(language)&&translate_brackets)
cur_char= new_char;
return out_dflt(cur_char);
}



eight_bits out_dflt FCN((c))
eight_bits c C1("")
{
C_putc(XCHR(c));

if(out_state!=VERBATIM)
out_state= MISCELLANEOUS;

return c;
}



LANGUAGE set_output_file FCN((language0))
LANGUAGE language0 C1("")
{
language= language0;/* Set the input language. */
ini0_language();/* Set up parameters (include the |out_language|). */
out_file= params.OUT_FILE;/* Output of \.{TANGLE}. */

return language;/* Return the input language. */
}



LANGUAGE opn_output_file FCN((language0))
LANGUAGE language0 C1("")
{
set_output_file(language0);
flush_buffer();
open_out(OC(""),LOCAL_SCOPE);

return language;
}



boolean skip_comment(VOID)
{
ASCII c;/* current character */
PARSING_MODE outer_mode;

outer_mode= parsing_mode;
parsing_mode= OUTER;

if(comment_continues)loc--;/* We've already scanned over white space, so \
  |loc| is presently one position beyond the first non-blank character on the \
  continuation line. */
else if(*(loc-1)==057)loc++;/* If we're starting a comment, |loc|~is \
  positioned on the star; move past that. */

WHILE()
{
if(loc>limit)
if(!long_comment)
{
comment_continues= NO;
break;
}


else if(get_line())
{
comment_continues= YES;
break;
}
else
{

err0_print(ERR_T,OC("Input ended in middle of comment %s"),1,BTRANS);

comment_continues= NO;
break;/* We |break| out and return so |get_next| can \
return a newline. */
}

c= *(loc++);

if(c==052&&*loc==057)
{
loc++;

{
comment_continues= NO;
break;
}


}

if(c==0100)
{
if(ccode[*loc]==new_module)/* `\.{@\ }' or `\.{@*}' */
{

err0_print(ERR_T,OC("Section name ended in middle of comment %s"),1,BTRANS);
loc--;


{
comment_continues= NO;
break;
}


}
else loc++;
}
}

parsing_mode= outer_mode;
return comment_continues;
}



eight_bits get_next(VOID)/* produces the next input token */
{
GOTO_CODE pcode;/* Return code from the parse routines. */

strt_point_cmnt= suppress_newline= NO;

WHILE()
{


if(preprocessing&&at_beginning)
{
at_beginning= NO;

/* Preprocessor directives can have white space between the '\.\#' and the \
name. */
for(;loc<limit;loc++)
if(!(*loc==040||*loc==tab_mark))break;

*(loc-1)= 043;/* Now we're positioned on an identifier beginning \
with |'#'|, with no intervening blanks. */
return(eight_bits)prs_regular_code(GOTO_GET_IDENTIFIER);
}

;


if(*loc==cont_char&&loc==limit-1&&(preprocessing||free_Fortran))
{
loc+= 2;/* Force it to read another line the next time through. */
return(eight_bits)CHOICE(free_Fortran,046,cont_char);/* We \
leave the format of the input file alone. Since we're using free-form \
syntax, the compiler will continue the line correctly. */
}

;

if(loc>limit)

{
if(from_buffer)
{
undivert();/* Stop reading from buffer; go back to reading from files. */
if(stop_the_scan)
return WEB_definition;
continue;
}
else
{/* Reading from file. */
if(preprocessing&&*(limit-1)!=cont_char)
{
preprocessing= NO;
if(in_cdir)
{
id_first= id_loc= mod_text+1;
*id_loc++= cdir;
*id_loc++= '\0';
in_cdir= NO;
return stringg;
}
}
if(stop_the_scan)
return WEB_definition;
else if(!get_line())
return new_module;

if(eat_blank_lines)
{
eat_blank_lines= NO;

while(loc>=limit)
if(!get_line())
return new_module;
}

if(insrt_line)
{
ins_ln_no(0);
insrt_line= NO;
}

at_beginning= BOOLEAN(!preprocessing);

if(prn_where)
{
prn_where= NO;

if(!scanning_defn)
{
app_repl(012);
/* Ensure \&{\#line} command begins on new line. */
ins_ln_no(0)

;
}
}
else if(!suppress_newline&&
(!R77_or_F||limit==cur_buffer||free_Fortran))
return 012;

suppress_newline= NO;
}
}


else
at_beginning= BOOLEAN(!preprocessing&&(loc==cur_buffer));

if(preprocessing)

{
boolean found_white_space= NO;

do
{
if((c= *loc++)!=040||c!=tab_mark)
break;

found_white_space= YES;
}
while(loc<limit);


if(found_white_space)
return 040;
}


else

{
if(language==TEX)
c= *loc++;
else
{
ASCII HUGE*loc0= loc;/* Remember starting point for nuweb mode. */

do
{/* Skip beginning white space. */
c= *loc++;
}
while(loc<=limit&&(c==040||c==tab_mark));

if(nuweb_mode||scanning_meta)
{
if(!(c==0100&&*loc==043))
{/* Go back to beginning. */
loc= loc0;
c= *loc++;

if(loc>limit)
continue;/* Prevent space at end of line. */
}
}
}
}



strt_cmnt= NO;

switch(language)
{
case TEX:
if(!scanning_defn)
{
if((pcode= prs_TeX_code())==MORE_PARSE)
break;
else if(pcode<0)
CONFUSION("prs_TEX_code","Negative pcode");
else
RETURN(pcode);
}

default:
if((pcode= prs_regular_code(MORE_PARSE))==MORE_PARSE)
break;
else if((int)pcode<0)
CONFUSION("prs_regular_code","Negative pcode");
else
RETURN(pcode);
}
}

DUMMY_RETURN(ignore);
}


GOTO_CODE prs_TeX_code(VOID)
{
GOTO_CODE icode;/* Return code from |get_control_code|. */

if(loc>limit)
return MORE_PARSE;

if(TeX[c]==TeX_comment)

{
long_comment= NO;

if((all_cmnts_verbatim||(keep_trailing_comments&&!at_beginning))
&&!(scanning_defn&&is_WEB_macro))
{
strt_cmnt= YES;
}
else
{
loc= limit+1;/* Skip rest of line. */
suppress_newline= YES;/* Blank lines inside macro def'ns, for \
					example, can cause problems. */
return MORE_PARSE;
}
}



if(c==0100)
{
icode= get_control_code();

if(icode==MORE_PARSE)
return icode;

if((int)(icode)<0)
return prs_regular_code(icode);
else
return(eight_bits)icode;
}
else

{
loc--;
id_first= id_loc= mod_text+1;

if(strt_cmnt)
*id_loc++= begin_Xmeta;

while(loc<limit)
{
if(*loc==0100)
{
if(*(loc+1)==0100)
*id_loc++= *loc++;
}
else if(!strt_cmnt&&TeX[*loc]==TeX_comment&&*(loc-1)!=0134)
break;

*id_loc++= *loc++;
}

if(strt_cmnt)
*id_loc++= end_Xmeta;

return stringg;
}


}


GOTO_CODE prs_regular_code FCN((iswitch))
GOTO_CODE iswitch C1("")
{
GOTO_CODE icode;/* Return code from |get_control_code|. */

switch(iswitch)
{
case MORE_PARSE:break;

case GOTO_MISTAKE:goto mistake;
case GOTO_GET_IDENTIFIER:goto get_identifier;
case GOTO_GET_A_STRING:goto get_a_string;
case GOTO_SKIP_A_COMMENT:goto skip_a_comment;
}

if(language!=LITERAL)

{
switch(c)
{
case(ASCII)begin_comment0:
long_comment= strt_cmnt= YES;
break;

case(ASCII)begin_comment1:
strt_cmnt= strt_point_cmnt= YES;
long_comment= NO;
break;

case 057:
if(*loc==052)
long_comment= strt_cmnt= YES;
else if(*loc==057&&(C_LIKE(language)||(Cpp_comments&&
!in_format&&FORTRAN_LIKE(language))))
{/* Short comments are recognized in both~C and \Cpp. */
long_comment= NO;
strt_cmnt= YES;
}
break;

case 041:
/* \Fortran\ will handle the commenting style ``\.{! Comment}'' if \
|point_comments| is on, or ``\.{!! Comment}'' always. */
if((*loc==041||point_comments)&&FORTRAN_LIKE(language))
{
*(loc-1)= (ASCII)begin_comment1;/* This marker is \
necessary so the verbatim comments don't get confused with \.{@!}. */
strt_cmnt= strt_point_cmnt= YES;
long_comment= NO;
}
break;
}

if(strt_cmnt&&all_cmnts_verbatim&&!(scanning_defn&&is_WEB_macro))
{
loc--;/* Position on the '\./'. */


switch(icode= get_control_code())
{
case GOTO_MISTAKE:goto mistake;
case GOTO_GET_A_STRING:goto get_a_string;
case GOTO_GET_IDENTIFIER:goto get_identifier;
case GOTO_SKIP_A_COMMENT:goto skip_a_comment;

case m_line:
ins_ln_no(1);
suppress_newline= YES;
return MORE_PARSE;

case MORE_PARSE:
default:return icode;
}


}
else if(strt_cmnt||comment_continues)
{
skip_a_comment:
skip_comment();/* scan to end of comment or newline */

if((comment_continues)&&
!(scanning_defn&&is_WEB_macro))return 012;
else return MORE_PARSE;
}

if(loc==limit&&c==cont_char&&
(preprocessing||(auto_semi&&R77)))return MORE_PARSE;
}



/* --- ELLIPSIS --- */
if(c==056&&*loc==056&&*(loc+1)==056)
{
++loc;
compress(ellipsis);
}

/* --- DOT CONSTANT: `\.{.FALSE.}' --- */
else if(FORTRAN_LIKE(language)&&dot_constants&&
(c==wt_style.dot_delimiter.begin)&&!isDigit(*loc))


{
ASCII HUGE*p0;
int n;
eight_bits c;
ASCII dot_end= wt_style.dot_delimiter.end;


/* At this point, |loc| is positioned to the first position after the dot. */
for(p0= loc,n= 0;n<MAX_DOT_LENGTH;n++,loc++)
if(*loc==dot_end||!isAlpha(*loc))break;/* Found end of dot \
constant. */

if(*loc!=dot_end)/* Didn't find end. */
{
loc= p0;/* Reset position back to beginning. */
goto mistake;
}

c= dot_code(dots,uppercase(p0,n),loc++,dot_const);

if(c)return c;
else
{
loc= p0;
goto mistake;
}

}



/* --- CONSTANT: `\.{123}', `\.{.1}', or `\.{\\135}' --- */
else if(isDigit(c)||c==056||(c==0134&&language!=LITERAL))

{
boolean decimal_point;


if(loc==limit&&c==cont_char)
{
if(preprocessing)loc++;
return(eight_bits)c;
}

starts_with_0= hex_constant= bin_constant= floating_constant= NO;

id_first= loc-1;

if(*id_first==056&&!isDigit(*loc))goto mistake;/* not a constant */

if(*id_first==0134)
{
if(*loc==057)goto mistake;
while(isOdigit(*loc))loc++;/* octal constant */
goto found;
}
else
{
starts_with_0= BOOLEAN(*id_first==060);
if(starts_with_0)
{
hex_constant= BOOLEAN(*loc==0170||*loc==0130);

if(hex_constant)
{/* hex constant---e.g, \.{0xA1} */
loc++;while(isXdigit(*loc))loc++;goto found;
}
else if((bin_constant= BOOLEAN(*loc==0142||*loc==0102))!=0)
{/* Binary constant---e.g., |0b101|. */
loc++;
while(isBdigit(*loc))loc++;
goto found;
}
}

while(isDigit(*loc))loc++;/* Skip over digits. */
decimal_point= BOOLEAN(*loc==056);
if(decimal_point)loc++;/* Check if decimal point. */
while(isDigit(*loc))loc++;/* Skip over digits after decimal point. */

if(FORTRAN_LIKE(language))
if(*(loc-1)==056)
{
/* If the constant doesn't end with a digit, \
make sure the dot isn't the start of a dot constant. */
if(is_dot())
{
loc--;
goto found;
}
}
else if(*loc==0150||*loc==0110)

{
int l,n;


*loc++= '\0';/* Terminate string after the length \
	(temporarily overwriting the 'H'); position to actual constant. */
n= ATOI(id_first);/* Length of constant. */
*(loc-1)= 0110;/* Reconstruct the 'H'. */

for(l= 0;l<n;++l)++loc;/* Skip over the constant. */

goto found;
}



floating_constant= BOOLEAN(*loc==0145||*loc==0105||
(FORTRAN_LIKE(language)
&&(*loc==0144||*loc==0104||*loc==0161||*loc==0121)));

if(floating_constant)
{/* float constant---e.g., \.{1.0e-5}  */
if(*++loc==053||*loc==055)loc++;
while(isDigit(*loc))loc++;
}

floating_constant|= decimal_point;
}

found:
if(C_LIKE(language))
{/* Check for |unsigned|, |long|, or |float| suffix. */
boolean its_long= NO,its_unsigned= NO,its_constant= NO;

switch(*loc)
{
case 0154:
case 0114:
its_constant= its_long= YES;
break;

case 0165:
case 0125:
its_constant= its_unsigned= YES;
break;

case 0146:
case 0106:
its_constant= YES;
break;
}

if(its_constant)
{/* |long|, |float|, or |unsigned| \
constant---e.g., \.{123L} */
loc++;/* Skip over suffix. */

/* Might be a second suffix. */
if(its_long&&(*loc==0165||*loc==0125))
loc++;/* |50LU| */
else if(its_unsigned&&(*loc==0154||*loc==0114))
loc++;/* |50UL| */
}
}
else if(Fortran88)
{
if(*loc==0137)
while(is_kind(*loc))loc++;
}



id_loc= loc;
return constant;
}



/* --- IDENTIFIER --- */
else if(is_identifier(c))

{
IN_COMMON ASCII HUGE*pformat,HUGE*pdata;

get_identifier:

{
id_first= --loc;

/* Scan over subsequent elements of an identifier. */
for(++loc;isAlpha(*loc)||isDigit(*loc)
||*loc==0137||*loc==044||(in_format&&*loc==056);loc++)
;

id_loc= loc;/* End plus one of the identifier.*/
}




if(FORTRAN_LIKE(language))
{
if(web_strcmp(pformat,pformat+6,id_first,id_loc)==EQUAL)
{/* Raise special flag to say we're inside a |@r format| \
statement. */
in_format= YES;
return begin_format_stmt;
}
else if(program==weave)
{
if(web_strcmp(pdata,pdata+4,id_first,id_loc)==EQUAL)
{/* Inside a |@r data| statement. */
in_data= YES;
return identifier;
}
else if(at_beginning&&*loc==':'&&
!is_in(non_labels,id_first,id_loc))
return stmt_label;
}
}

if(is_include_like())sharp_include_line= YES;
return identifier;
}




/* --- STRING --- */
else if((c==047||c==042)
||(is_RATFOR_(language)&&sharp_include_line==YES&&c==050))
{
if(language==LITERAL)
return c;
else

get_a_string:
{
ASCII delim= c;/* what started the string */
ASCII right_delim= c;
int level;
boolean equal_delims;

id_first= mod_text+1;/* Position of delimiter. */
id_loc= mod_text;*++id_loc= delim;

if(delim==050)
{
right_delim= 051;/* For m4 |@r include|. */
sharp_include_line= NO;
}

level= 1;

equal_delims= BOOLEAN(right_delim==delim);

WHILE()
{
if(loc>=limit)
{
if((equal_delims||chk_ifelse)&&*(limit-1)!=cont_char)
/* Continuation after next line. */
{

err0_print(ERR_T,OC("String %s with '%s%c' didn't end"),3,BTRANS,delim==047?"\\":"",XCHR(delim));
loc= limit;break;

}

if(!get_line())
{

err0_print(ERR_T,OC("Input ended in middle of string \
%s with '%s%c'"),3,BTRANS,delim==047?"\\":"",XCHR(delim));
loc= cur_buffer;
break;

}
else
{
if(C_LIKE(language)&&++id_loc<=mod_end)*id_loc= 012;
/* More string to come; will print as \.{"\\\\\\n"} */

/* Now the continuation of the string is in the buffer.  If appropriate, \
skip over beginning white space and backslash. */
if(bslash_continued_strings)
{
for(;loc<limit;loc++)
if(*loc!=040&&*loc!=tab_mark)break;

if(*loc==cont_char)loc++;/* Move past the backslash. */
else
err0_print(ERR_T,OC("Inserted '%c' at beginning of continued \
string"),1,XCHR(cont_char));
}
}
}

if(!equal_delims)

if(*loc==057&&*(loc+1)==052)
for(loc+= 2;;loc++)
{
if(loc>=limit)
if(!get_line())
{

err0_print(ERR_T,OC("Input ended in middle of embedded comment %s"),1,BTRANS);
loc= cur_buffer;
goto found_string;
}

if(*loc==052&&*(loc+1)==057)
{
loc+= 2;
break;
}
}

;

if((c= *loc++)==delim)
{
level++;

if(++id_loc<=mod_end)*id_loc= c;

if(!equal_delims)continue;

if(*loc==delim&&!(C_LIKE(language)||
(is_RATFOR_(language)&&Ratfor77)))
++loc;/* Copy over repeated delimiter. */
else break;/* Found end of string. */
}

if(c==right_delim)
if(--level==0)
{
if(++id_loc<=mod_end)*id_loc= c;
break;/* Found end of string for unequal delims. */
}

/* Double the quote. */
if(R77&&c==047)
if(++id_loc<=mod_end)*id_loc= c;

if(c==cont_char)
{
if(loc>=limit&&(!is_FORTRAN_(language)||free_form_input))
continue;/* Continuation of string; throw away the \
continuation character. */

if(!is_FORTRAN_(language))
{
c= *loc++;/* Character after backslash. */

if(R77)
switch(c)
{
#if(0)
#define n c

case 060:n= '\0';break;
case 0134:n= 0134;break;
case 047:n= 047;break;
case 042:n= 042;break;
case 077:n= 077;break;/* Microsoft doesn't like. */
case 0141:n= 07;break;/* SGI didn't understand. */
case 0142:n= 010;break;
case 0146:n= 014;break;
case 0156:n= 012;break;
case 0162:n= 015;break;
case 0164:n= 011;break;
case 0166:n= 013;break;


#undef n
#endif
/* Double the quote for the direct-to-Fortran output. */
case 047:
if(++id_loc<=mod_end)*id_loc= c;
break;
}
else{if(++id_loc<=mod_end)*id_loc= 0134;}
}
}

if(++id_loc<=mod_end)*id_loc= c;/* Store the character. */
}

found_string:
if(id_loc>=mod_end){
SET_COLOR(error);
printf("\n! String too long: ");

ASCII_write(mod_text+1,25);
printf("...");mark_error;
}

id_loc++;
return stringg;
}


}

/* --- CONTROL CODE --- */
else if(c==0100)

switch(icode= get_control_code())
{
case GOTO_MISTAKE:goto mistake;
case GOTO_GET_A_STRING:goto get_a_string;
case GOTO_GET_IDENTIFIER:goto get_identifier;
case GOTO_SKIP_A_COMMENT:goto skip_a_comment;

case m_line:
ins_ln_no(1);
suppress_newline= YES;
return MORE_PARSE;

case MORE_PARSE:
default:return icode;
}



/* --- WHITE SPACE --- */
else if(c==040||c==tab_mark)
if(nuweb_mode||scanning_meta)
return(c==tab_mark?bell:c);
else
{/* Ignore spaces and tabs, unless preprocessing. */
if(!preprocessing||loc>limit)
return MORE_PARSE;
/* we don't want a blank after a final backslash */
else
return 040;/* |preprocessing && loc <= limit|. */
}

/* --- C PREPROCESSOR COMMAND --- */
else if(c==043&&at_beginning&&C_LIKE(language))
{
preprocessing= YES;
return MORE_PARSE;
}

/* --- END of |@r format| STATEMENT --- */
else if(in_format&&c==073)/* End a |@r format| statement. */
{
in_format= NO;
return end_format_stmt;
}

/* --- TWO-SYMBOL OPERATOR --- */
mistake:
if(language!=LITERAL)

switch(c)
{
case 0134:
if(FORTRAN_LIKE(language)&&!in_format&&*loc==057)
compress(slash_slash);/* \Fortran's concatenation \
operator. Multiple slashes in |format| statements are just left alone. */
break;

case 057:
if(FORTRAN_LIKE(language)&&!in_format)
{
if(*loc==057)
{
if(Cpp_comments)
break;/* In this case, the \
slashes are the \Cpp-style comments.  We'll always allow \.{\\/} as a \
synonym for concatenation. */

compress(slash_slash);/* \Fortran's concatenation \
operator. Multiple slashes in |format| statements are just left alone. */
}
else if(*loc==075&&!compound_assignments)
compress(not_eq);
}
break;
case 053:if(*loc==053)compress(plus_plus);break;

case 055:if(*loc==055){compress(minus_minus);}
else if(*loc==076)compress(minus_gt);break;

case 075:if(*loc==075)compress(eq_eq);break;

case 076:if(*loc==075){compress(gt_eq);}
else if(*loc==076){compress(gt_gt);}
break;

case 074:if(*loc==075){compress(lt_eq);}
else if(*loc==074){compress(lt_lt);}
else if(*loc==076){compress(not_eq);}/* \FORTRAN-88 */
break;

case 046:if(*loc==046)compress(and_and);break;

case 0174:if(*loc==0174)compress(or_or);break;

case 041:if(*loc==075){compress(not_eq);}break;

case 052:
if(FORTRAN_LIKE(language)&&(*loc==052))
{compress(star_star);}/* Exponentiation. */
break;

case 0136:
if(*loc==0136){compress(star_star);}
else if(FORTRAN_LIKE(language)&&(loc<limit))return star_star;
break;

case 043:
if(*loc==043){compress(paste);}
else if(*loc==074)
{
loc++;
mac_mod_name= YES;

{
ASCII HUGE*k;/* pointer into |mod_text| */
static ASCII ell[]= "\56\56\56";



{
int mlevel= 1;/* For nested module names. */
int arg_num= 0;/* Counts template arguments. */
TEMPLATE arg_ptr[10];

k= mod_text;

WHILE()
{
if(loc>limit&&!get_line())
{

err0_print(ERR_T,OC("Input ended in section name %s"),1,BTRANS);

loc= cur_buffer+1;
break;
}

c= *loc;


if(c==0100)
{
c= *(loc+1);

if(c==076)
{
if(--mlevel==0)
{
loc+= 2;
break;/* Successful; position after \.{@>}. */
}
}
else if(c==074)
mlevel++;

if(ccode[c]==new_module)
{

err0_print(ERR_T,OC("Section name %s didn't end"),1,BTRANS);

break;
}

*(++k)= 0100;
loc++;/* Now |c==*loc| again. */
}

;
loc++;

if(k<mod_end)
k++;/* Next available output position. */

switch(c)
{
case 040:
case tab_mark:
c= 040;
if(*(k-1)==040)
k--;/* Compress white space. */
break;

case 073:
c= interior_semi;
break;

case 0133:
break;
}

*k= c;/* Store the character. */
}


if(k>=mod_end)
{
SET_COLOR(warning);
printf("\n! Section name too long: ");

ASCII_write(mod_text+1,25);
printf("...");mark_harmless;
}

if(*k==040&&k>mod_text)
k--;/* Trailing blanks. */
}



if(k-mod_text>3&&STRNCMP(k-2,ell,3)==0)
cur_module= prefix_lookup(mod_text+1,k-3);
else
cur_module= mod_lookup(mod_text+1,k);

if(cur_module!=NULL)
{
set_output_file(cur_module->mod_info->language);/* Get current lang. */
}

return module_name;
}


}
break;

case 072:if(*loc==072&&language==C_PLUS_PLUS&&!scanning_meta)
compress(colon_colon);break;

}




return(eight_bits)c;
}



GOTO_CODE get_control_code(VOID)
{
eight_bits cc;/* The |ccode| value. */

c= *loc++;
SET_CASE(c);/* Set the |upper_case_code| flag. */

if(c==(ASCII)begin_comment1||c==(ASCII)begin_comment0)
{
c= *(loc-1)= 057;/* So we can handle this uniformly with C-style \
comments. */
strt_cmnt= YES;
}

switch(cc= ccode[c])
{
case ignore:return MORE_PARSE;/* Undefined control code. */

/* Languages are stored, if necessary, in two parts: |begin_language|, and \
the language itself. Here |set_output_file| sets the language, which can be \
looked at when we're appending. */


case begin_C:
case begin_RATFOR:
case begin_FORTRAN:
case begin_LITERAL



:
loc--;

case L_switch:
{

{
ASCII l= *loc++;/* The basic language letter. */

switch(l)
{

case 0143:case 0103

:
Cpp= BOOLEAN(*loc==053);
break;


case 0162:case 0122

:

case 0156:case 0116

:
Fortran88= BOOLEAN(*loc==071);
break;


case 0166:case 0126



:

case 0170:case 0130

:
break;

default:

err0_print(ERR_C,OC("! Invalid language command `@L%c' ignored"),1,XCHR(l));
break;
}

opt_args(l);/* Set the language, and parse optional arguments after \
		language command. */
}



set_output_file(language);
return begin_language;
}

case control_text:while((c= skip_ahead(ignore,NO))==0100);
/* only \.{@@} and \.{@>} are expected *//* Is |c| used?? */

if(*(loc-1)!=076)

err0_print(ERR_T,OC("Improper @ within control text %s"),1,BTRANS);


return MORE_PARSE;/* To top of loop in |get_next|. */

case module_name:/* \.{@<} */
mac_mod_name= NO;/* Used as a flag for macro processing. */

{
ASCII HUGE*k;/* pointer into |mod_text| */
static ASCII ell[]= "\56\56\56";



{
int mlevel= 1;/* For nested module names. */
int arg_num= 0;/* Counts template arguments. */
TEMPLATE arg_ptr[10];

k= mod_text;

WHILE()
{
if(loc>limit&&!get_line())
{

err0_print(ERR_T,OC("Input ended in section name %s"),1,BTRANS);

loc= cur_buffer+1;
break;
}

c= *loc;


if(c==0100)
{
c= *(loc+1);

if(c==076)
{
if(--mlevel==0)
{
loc+= 2;
break;/* Successful; position after \.{@>}. */
}
}
else if(c==074)
mlevel++;

if(ccode[c]==new_module)
{

err0_print(ERR_T,OC("Section name %s didn't end"),1,BTRANS);

break;
}

*(++k)= 0100;
loc++;/* Now |c==*loc| again. */
}

;
loc++;

if(k<mod_end)
k++;/* Next available output position. */

switch(c)
{
case 040:
case tab_mark:
c= 040;
if(*(k-1)==040)
k--;/* Compress white space. */
break;

case 073:
c= interior_semi;
break;

case 0133:
break;
}

*k= c;/* Store the character. */
}


if(k>=mod_end)
{
SET_COLOR(warning);
printf("\n! Section name too long: ");

ASCII_write(mod_text+1,25);
printf("...");mark_harmless;
}

if(*k==040&&k>mod_text)
k--;/* Trailing blanks. */
}



if(k-mod_text>3&&STRNCMP(k-2,ell,3)==0)
cur_module= prefix_lookup(mod_text+1,k-3);
else
cur_module= mod_lookup(mod_text+1,k);

if(cur_module!=NULL)
{
set_output_file(cur_module->mod_info->language);/* Get current lang. */
}

return module_name;
}



case stringg:/* \.{@=} */

{
id_first= loc;/* This used to be |loc++|, but that doesn't handle null \
		string correctly. */

*(limit+1)= 0100;*(limit+2)= 076;/* Delimiters for verbatim string. */

while(*loc!=0100||*(loc+1)!=076)
loc++;/* Verbatim string must end on same line. */

if(loc>=limit)
err0_print(ERR_T,OC("Verbatim string %s didn't end"),1,BTRANS);


id_loc= loc;
loc+= 2;/* Just after \.{@>}. */
return stringg;
}

;

case begin_vcmnt:
/* Here the |strt_cmnt| handles all comments verbatim; the last two \
cases handle~\.{@\slashstar} or~\.{@//}. */
if(strt_cmnt||*loc==052||*loc==057)
if(!(scanning_defn&&is_WEB_macro)&&!deferred_macro)
{
if(!strt_point_cmnt)long_comment= 
BOOLEAN(!(*loc==057));

{
loc--;/* Position to the beginning slash or comment marker (which has been \
		already read as part of~`\.{@/}'). */

id_first= id_loc= mod_text+1;/* A convenient place to put the verbatim \
					comment. */

if(!C_LIKE(language))
{
loc++;/* Skip the opening \.*, for beauty. */

{
if(R66)*id_loc++= 043;
else*id_loc++= 012;

}

;
}

WHILE()
{
if(loc>limit)
if(!long_comment)
{
if(C_LIKE(language))
{/* If we're not using \Cpp, we'll change short comments back to \
standard form so they can be understood by the compiler. */
if(!long_comment&&!Cpp)
{
*id_loc++= id_first[1]= 052;
*id_loc++= id_first[0]= 057;
}
}
else
{/* In \Fortran, kill off the trailing terminator. */
if(long_comment)id_loc-= 2;
}

break;
}


else if(!get_line())
{

err0_print(ERR_T,OC("Input ended in verbatim comment %s"),1,BTRANS);

loc= cur_buffer+1;
break;
}
else
{
*id_loc++= 012;/* Retain line breaks in comments. */

if(R66)
{
*id_loc++= 043;/* Special comment line. */
*id_loc++= 040;/* Space adds readability. */
}
}

if(id_loc<mod_end-3)
*id_loc++= *loc++;/* Copy over the comment. */
else
{
SET_COLOR(warning);
printf("\n! Verbatim comment too long: ");

ASCII_write(mod_text,25);
printf("...");mark_harmless;

id_loc= mod_end-3;
*id_loc++= 052;*id_loc++= 057;/* Terminate the comment \
(prematurely). */
comment_continues= YES;/* This is so |get_next| can skip \
the remainder of the comment. */
goto finish_vcmnt;
}

/* Check for end of verbatim comment. */
if(long_comment&&*loc==057&&*(loc-1)==052)
{
*id_loc++= *loc++;/* Position after end of comment. */

{
if(C_LIKE(language))
{/* If we're not using \Cpp, we'll change short comments back to \
standard form so they can be understood by the compiler. */
if(!long_comment&&!Cpp)
{
*id_loc++= id_first[1]= 052;
*id_loc++= id_first[0]= 057;
}
}
else
{/* In \Fortran, kill off the trailing terminator. */
if(long_comment)id_loc-= 2;
}

break;
}


}
}

finish_vcmnt:
if(!C_LIKE(language))
{
*id_loc++= '\0';
}
return stringg;/* Complete comment copied. */
}


/* \.{@\slashstar} */
}
else return GOTO_SKIP_A_COMMENT;
else return MORE_PARSE;/* The line-break command \.{@/} is ignored by \
\TANGLE. */

case invisible_cmnt:
/* When we sense an \.{@\%}, we throw away everything to the end of line, \
including the newline that is normally returned.  If the construction is \
\.{@\%\ we turn on the |eat_blank_lines| flags|, so we gobble up all \
subsequent blank lines in a row. */
if(*loc==045)
eat_blank_lines= YES;

/* If the \.{@\%} is beginning a line, put a \.{\#line} command in to help \
out the debugger. */
if(auto_line&&!scanning_defn&&loc==cur_buffer+2)
insrt_line= YES;

loc= limit+1;/* Force the next line to be read. */
suppress_newline= YES;
return MORE_PARSE;

case compiler_directive:
{
int n;
outer_char*s= t_style.cdir_start[language_num];

id_first= id_loc= mod_text+1;

*id_loc++= cdir;

/* Starting ``pragma'' string. */
STRCPY(id_loc,s);
to_ASCII((outer_char HUGE*)id_loc);
id_loc+= STRLEN(s);

/* Body. */
STRNCPY(id_loc,loc,n= PTR_DIFF(int,limit,loc));
id_loc+= n;

*id_loc++= cdir;
*id_loc++= '\0';

loc= limit+1;
return stringg;
}

case Compiler_Directive:
{
outer_char*s= t_style.cdir_start[language_num];

id_first= id_loc= mod_text+1;

*id_loc++= cdir;
preprocessing= in_cdir= YES;
at_beginning= NO;

/* Starting ``pragma'' string. */
STRCPY(id_loc,s);
to_ASCII((outer_char HUGE*)id_loc);
id_loc+= STRLEN(s);

return stringg;
}

case new_output_file:/* \.{@o} */

{
while(*loc==' '||*loc==tab_mark)
{
loc++;
if(loc>limit)return ignore;
}

id_first= loc;
while(*loc!=' '&&*loc!=tab_mark)loc++;/* Absorb file name. */
id_loc= loc;
if(*id_first=='"')id_first++;
if(*(id_loc-1)=='"')id_loc--;
if(id_loc-id_first>=MAX_FILE_NAME_LENGTH)
{

err0_print(ERR_T,OC("Output file name too long; allowed only %d characters"),1,MAX_FILE_NAME_LENGTH-1);
id_loc= id_first+MAX_FILE_NAME_LENGTH-1;
}
}



loc= limit+1;/* Skip rest of line. */
return cc;

case ascii_constant:/* \.{@'} or \.{@"} */
if(translate_ASCII)
{
ASCII delim= *(loc-1);/* Character that started the string. */

id_first= loc-1;/* Include the delimiter for later reference. */

while(*loc!=delim)
{
if(*loc==0134)
if(*++loc==delim)
{/* Skip over escape, and possibly escaped \
delimiter. */
loc++;
continue;
}

loc++;

if(loc>limit)
{

err0_print(ERR_T,OC("ASCII string %s didn't end"),1,BTRANS);
loc= limit-1;break;
}
}

loc++;/* Skip closing delimiter. */
return ascii_constant;
}


else
{
c= *(loc-1);/* The starting quote character. */
return GOTO_GET_A_STRING;
}

case big_line_break:/* \.{@\#}. Serves double duty as line break or \
preprocessor command. ??? GENERALIZE??? */
if(loc>=limit)return MORE_PARSE;


{
boolean mcode;

*limit= ' ';/* Terminator for identifier search. */
id_first= loc;

while(isAlpha(*loc))loc++;/* Find end of identifier. */

if((mcode= is_mcmd(mcmds,id_first,loc))!=0)
{
while(loc<limit&&(*loc==040||*loc==tab_mark))
loc++;

return mcode;
}

loc= id_first;/* Failed to recognize preprocessor command. */
}


;
return MORE_PARSE;

case set_line_info:

{
outer_char c= XCHR(*loc++);

if(!isdigit(c))
{

err0_print(ERR_T,OC("You must say `@Q0' or `@Q1', not `@Q%c'"),1,c);
loc--;
}
else
line_info= BOOLEAN((c!='0')&&global_params.Line_info);
}


return cc;

case USED_BY_NEITHER:

err0_print(ERR_T,OC("Invalid `@%c' ignored"),1,XCHR(c));
return ignore;

default:return cc;
}
}


#endif /* |part == 2| */

#if(part == 0 || part == 3)


SRTN scan_repl FCN((t,stop))
eight_bits t C0("Either |macro| or |module_name|.")
boolean stop C1("IF |YES|, stops the scan at the end of current\
line.")
{
eight_bits a0= ignore;/* the current token */
sixteen_bits a;/* An identifier number. */
LANGUAGE language0;
int ntoken= 2;
boolean auto_bp= YES;/* Breakpoints are inserted automatically, unless \
the module starts off with \.{@\lb}. */

scanning_meta= NO;
language0= language;/* Save incoming language, in case while we're \
			reading ahead we change it. */
stop_the_scan= stop;

if(t==module_name)
{
ins_ln_no(column_mode);

/* Possibly turn on nuweb mode for output. */
app_repl(begin_language);
app_repl(NUWEB_OFF|nuweb_mode);
}
else if(stop)

{
*limit= 040;
*(limit+1)= 0100;
*(limit+2)= 0155;
}



WHILE()
{
if(stop)
{
while(loc<=limit)
if(*loc!=040)break;
else loc++;

if(loc>limit)goto done;
}

/* The |ntoken| counter starts out at~2. It is used to see whether the \
first thing in the module is a left brace. If so, the |_BP| macro is \
inserted after the brace for debugging purposes. */
if(ntoken)
ntoken--;

a0= (ntoken&&nuweb_mode&&t==module_name)
?begin_meta:get_next();/* !!!!! */

reswitch:
switch(a0)
{
case 0134:
if(loc==limit&&language!=LITERAL)
{
if(!get_line())
FATAL(T,"!! Input ended while scanning \
WEB preprocessor statement","");

{
*limit= 040;
*(limit+1)= 0100;
*(limit+2)= 0155;
}


}
else
{
app_repl(a0);

if(loc==limit&&language==LITERAL)
loc++;/* Added |loc==limit|.  ??? */
}
break;

case 043:
if(t==macro&&is_WEB_macro)

{
switch(*loc)
{
case 072:

{
outer_char temp[N_IDBUF];
ASCII HUGE*t;


loc++;/* Move past the colon. */

/* Check if it's '\.0'---immediate statement number. If not, pass it \
through to the output phase. */
if(*loc!=060)
{
app_repl(043);
app_repl(072);
break;
}

loc++;/* Move past the zero.*/

if(
nsprintf(temp,OC("%lu"),1,max_stmt++)>=(int)(N_IDBUF))OVERFLW("temp","");/* Make the number. */
to_ASCII(temp);

/* Append the number, bracketed by |constant|. */
app_repl(constant);

for(t= (ASCII*)temp;*t!='\0';t++)app_repl(*t);

app_repl(constant);
}

break;

case 041:
if(scanning_defn)
{
sixteen_bits a;


loc++;/* Position to after `\.!'. */

if(get_next()!=identifier)

err0_print(ERR_M,OC("Identifier must follow #!; command ignored"),0);
else
{
text_pointer m;

/* Add the identifier to the table if necessary. */
a= ID_NUM(id_first,id_loc);

/* If it's an identifier but not a macro, it must be the construction \
`\.{\#!}|arg|'; just append that for later processing. */
if((m= MAC_LOOKUP(a))==NULL)
{
app_repl(043);
app_repl(041);

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}

;
break;
}
else
if(m->nargs>0)

err0_print(ERR_M,OC("Macro after #! may not have arguments"),0);
else
{
eight_bits HUGE*q0,HUGE*q1;


q0= m->tok_start+m->moffset;
q1= (m+1)->tok_start;

/* Just copy the definition without expanding. */
while(q0<q1)app_repl(*q0++);
}


}
}


else app_repl(043);
break;

case 047:
case 042:
app_repl(a0);
app_repl(*loc++);
break;

default:

{
sixteen_bits a;


if(isDigit(*loc)||*loc==054||*loc==046||*loc==052||*loc==056||
*loc==0133||*loc==0173)
/* It's one of the forms `\.{\#}$nnn$', `\.{\#,}', `\.{\#\&}', `\.{\#*}', \
or `\.{\#.}'; these are processed on output. */
{app_repl(043);}
else if(get_next()!=identifier)

macro_err(OC("! '#' should be followed by identifier"),YES);
else
{
a= ID_NUM(id_first,id_loc);

/* Check to see if the identifier is an already-defined macro; if not, it's \
the stringizing operation, which is processed on output; just \
append the identifier. */
if((MAC_LOOKUP(a))==NULL)
{
app_repl(043);

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}

;
break;
}

/* Asking for immediate expansion of macro. */

macro_err(OC("! Immediate expansion of macro \"%s\" not implemented"),YES,name_of(a));

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}

;
}
}


break;
}
}


else
{
app_repl(a0);
}
break;



case identifier:


a= ID_NUM(id_first,id_loc);

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}




break;

case module_name:
/* In a macro, the appearance of a module name beginning with \
	\.{@<} ends the macro and the definition section. On the other \
hand, the construction \.{\#<\dots@>} is OK in a macro. */
if(t==macro&&!mac_mod_name)
goto done;
else
{

{
}



{
ASCII HUGE*try_loc= loc;


while(*try_loc==040&&try_loc<limit)
try_loc++;

if(*try_loc==053&&try_loc<limit)
try_loc++;

while(*try_loc==040&&try_loc<limit)
try_loc++;

if(*try_loc==075)

err0_print(ERR_T,OC("Nested named modules.  Missing `@*' or `@ '?"),0);

}

;
a= (sixteen_bits)(cur_module-name_dir);
app_repl(LEFT(a,0250));
app_repl(RIGHT(a));
ins_ln_no(0);
if(nuweb_mode)
{/* !!!!! */
a0= begin_meta;
goto reswitch;
}
break;
}

case constant:
case stringg:


if(C_LIKE(language))
{
if(bin_constant&&a0==constant)

{
app_converted(btoi(id_first,id_loc));/* Start after the \.{0x}. */
}


else
copy_string(a0);
}
else if(a0==constant)
{
if(language==LITERAL)
copy_string(a0);
else if(hex_constant)

{
app_converted(xtoi(id_first,id_loc));/* Start after the \.{0x}. */
}


else if(bin_constant)

{
app_converted(btoi(id_first,id_loc));/* Start after the \.{0x}. */
}


else if(starts_with_0&&!floating_constant)

{
app_converted(otoi(id_first,id_loc));
}


else
copy_string(a0);
}
else if(R77&&a0==stringg&&!in_format)
{
if(*id_first==047)
rdc_char_constant();
else
{
/* Replace the Ratfor double quote with Fortran's single quote. Watch out \
for a verbatim comment that doesn't start with quote at all. */
if(*id_first==042)*id_first= *(id_loc-1)= 047;
copy_string(a0);
}
}
else
copy_string(a0);

break;

;

case ascii_constant:
cp_ASCII();
break;

case begin_meta:

{
app_repl(stringg);

if(!nuweb_mode)
app_repl(a0);/* |begin_meta| inside strings means to insert the \
		|meta| stuff from the style file. */

if(FORTRAN_LIKE(language))
{
column_mode= NO;
app_repl(012);
}

scanning_meta= YES;

}


break;

case end_meta:


if(FORTRAN_LIKE(language)&&!free_form_input)

{
loc= limit+1;
column_mode= YES;
parsing_mode= OUTER;
}



;
get_line();
app_repl(end_meta);
app_repl(stringg);
scanning_meta= NO;
break;

case dot_const:
app_repl(a0);
app_repl(dot_op.num);/* |dot_op| was filled by |dot_code|. */
break;

case begin_language:
switch(language)
{
case NO_LANGUAGE:
CONFUSION("scan_repl:begin_language","Language isn't defined");

case RATFOR:
case RATFOR_90:
if(!RAT_OK("(scan_repl)"))
CONFUSION("scan_repl:begin_language",
"Attempting to append @Lr");

case C:
case C_PLUS_PLUS:
case LITERAL:
column_mode= NO;
break;

case FORTRAN:
case FORTRAN_90:
case TEX:
if(!(scanning_defn||free_form_input))
{

{
loc= limit+1;
column_mode= YES;
parsing_mode= OUTER;
}


}
break;

default:
CONFUSION("app_id","Invalid language");
}

/* We append the language in two parts: |begin_language|, and the language \
itself. This is so we didn't have to tie up many non-printable |ASCII| \
tokens. See the inverse code in |get_output|. */
set_output_file(language);
if(!scanning_defn)
{app_repl(a0);app_repl((eight_bits)language);}

{
store_two_bytes((sixteen_bits)(LINE_NUM+module_count));
}


ins_ln_no(column_mode);
break;

case no_mac_expand:
app_repl(begin_language);
app_repl(a0);
break;

case set_line_info:
app_repl(begin_language);
app_repl(a0);
app_repl(line_info);
break;

case new_output_file:
if(t==macro)
goto done;
else
{
name_pointer np;

app_repl(begin_language);/* We piggy-back on |begin_language|. */
app_repl(NO_LANGUAGE);
app_repl(upper_case_code);/* Scope of file name: \
\.{@o}~means local; \.{@O}~means global. */
a= ID_NUM_ptr(np,id_first,id_loc);

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}


np->macro_type= FILE_NAME;/* To prevent truncations. */

if(nuweb_mode)
{
a0= begin_meta;
goto reswitch;
}
}
break;

case WEB_definition:
if(t==macro)
goto done;
else
{

{
#define NAME_LEN 100

name_pointer np;
eight_bits HUGE*tok_ptr0,HUGE*tok_m_end0;
text_pointer text_ptr0,text_end0;
outer_char new_name[NAME_LEN];
ASCII HUGE*nn,HUGE*b;
sixteen_bits a;

if(!deferred_macros)
{

err0_print(ERR_T,OC("Sorry, deferred WEB macros (defined in code part) are \
prohibited; use option `-TD' to permit them"),0);
continue;
}

tok_ptr0= tok_ptr;
tok_m_end0= tok_m_end;
text_ptr0= text_ptr;
text_end0= text_end;

tok_ptr= tok_dptr;
tok_m_end= tokd_end;
text_ptr= txt_dptr;
text_end= textd_end;

deferred_macro= YES;
np= app_macro(WEB_definition);
deferred_macro= NO;

tok_dptr= tok_ptr;
tok_ptr= tok_ptr0;
tok_m_end= tok_m_end0;

txt_dptr= text_ptr;
text_ptr= text_ptr0;
text_end= text_end0;

if(np==NULL)continue;

/* Create a unique name, beginning with '@'. */

if(
nsprintf(new_name,OC("@%d"),1,n_unique++)>=(int)(NAME_LEN))OVERFLW("new_name","");
to_ASCII(new_name);
for(nn= (ASCII*)new_name+STRLEN(new_name),b= np->byte_start;
b<(np+1)->byte_start;)
*nn++= *b++;

a= ID_NUM_ptr(np,(ASCII*)new_name,nn);

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}

;

np->macro_type= DEFERRED_MACRO;
np->equiv= (EQUIV)cur_text;

#undef NAME_LEN
}

;
continue;
}

case begin_nuweb:
if(t!=module_name)
{
nuweb_mode1= nuweb_mode= !NUWEB_MODE;
goto done;
}
else
{

err0_print(ERR_T,OC("@N ignored; must appear before beginning of code part"),0);
continue;
}

case formatt:
case limbo_text:case op_def:case macro_def:
case definition:case undefinition:
case begin_code:
if(t!=module_name)
goto done;
else
{

err0_print(ERR_T,OC("@d, @l, @v, @w, @u, @f, and @a \
are ignored in code text"),0);
continue;

}

case end_of_buffer:
a0= ignore;

case m_ifdef:case m_ifndef:
case m_if:case m_else:case m_elif:case m_endif:case m_undef:case m_line:
case m_for:case m_endfor:
case new_module:
goto done;




case 012:
/* As far as checking whether a left brace begins a module, we don't care \
about newlines. */
if(ntoken)ntoken++;
app_repl(a0);
break;

case 0173:
app_repl(a0);

if(ntoken&&breakpoints&&t==module_name&&auto_bp)

{
ASCII bp_cmd[BP_BUF_SIZE];

if(cur_module!=NULL)
{

if(
nsprintf(bp_cmd,OC("_BP(%d,\"%s\")"),2,module_count,name_of((sixteen_bits)(cur_module-name_dir)))>=(int)(BP_BUF_SIZE))OVERFLW("bp_cmd","");
to_ASCII(OC(bp_cmd));
divert(bp_cmd,bp_cmd+STRLEN(bp_cmd),DONT_STOP);
}
}



break;

case begin_bp:
auto_bp= NO;/* A manual insertion command is coming up. */
app_repl(0173);
break;

case insert_bp:
if(breakpoints)

{
ASCII bp_cmd[BP_BUF_SIZE];

if(cur_module!=NULL)
{

if(
nsprintf(bp_cmd,OC("_BP(%d,\"%s\")"),2,module_count,name_of((sixteen_bits)(cur_module-name_dir)))>=(int)(BP_BUF_SIZE))OVERFLW("bp_cmd","");
to_ASCII(OC(bp_cmd));
divert(bp_cmd,bp_cmd+STRLEN(bp_cmd),DONT_STOP);
}
}


break;

default:
app_repl(a0);/* Store |a0| in |tok_mem|. */
break;
}
}

done:
if(stop_the_scan&&!from_buffer)
{
stop_the_scan= NO;
next_control= ignore;
}
else next_control= 
(eight_bits)CHOICE((from_buffer&&loc>limit)||stop,
ignore,a0);

if(t==module_name)
{
/* Reset nuweb mode. */
if(scanning_meta)
{
if(!nuweb_mode)
app_repl(end_meta);

app_repl(stringg);
scanning_meta= NO;
}
app_repl(begin_language);
app_repl(NUWEB_OFF|nuweb_mode);
}


{
if(text_ptr>text_end)OVERFLW("texts","x");
cur_text= text_ptr;
(++text_ptr)->tok_start= tok_ptr;/* The next start is the present end. */
}

;
cur_text->Language= (boolean)language0;/* Use the starting language. */
}


SRTN ins_ln_no FCN((delta))
int delta C1("Increment to line number")
{
name_pointer np;

store_two_bytes((sixteen_bits)LINE_NUM);/* $\equiv$ a mod.\ \# of~0. */

id_first= x_to_ASCII(changing?change_file_name:cur_file_name);
id_loc= id_first+STRLEN(id_first);

store_two_bytes((sixteen_bits)((changing?change_line:cur_line)+delta));

store_two_bytes(ID_NUM_ptr(np,id_first,id_loc));
np->Language= (boolean)NO_LANGUAGE;/* \bfit Is this used??? */
}


SRTN copy_string FCN((a0))
eight_bits a0 C1("")
{
app_repl(a0);/* |stringg| or |constant| */

for(;id_first<id_loc;id_first++)
{
if(*id_first==0100)


if(language==TEX&&*(id_first+1)==0100)id_first++;
else
{
id_first++;/* Character after the~`\.{@}'. */

switch(ccode[*id_first])
{
case 0100:
break;/* The `\.{@}'~will be stored. */



case begin_C:
case begin_RATFOR:
case begin_FORTRAN:
case begin_LITERAL



:
case L_switch:
app_repl(0100);
break;/* Retain the character. */

default:
id_first++;/* Discard character after~`\.{@}'. */
continue;
}
}



app_repl(*id_first);
}

app_repl(a0);/* Bracket the string or constant with the id token. */
}



unsigned long xtoi FCN((b,b1))
CONST ASCII HUGE*b C0("Beginning of string.")
CONST ASCII HUGE*b1 C1("End of string.")
{
unsigned long n= 0;

for(b+= 2;b<b1;b++)
{
n*= 16;

if(isDigit(*b))n+= *b-060;
else n+= A_TO_UPPER(*b)-0101+10;
}

return n;
}


SRTN app_converted FCN((n))
unsigned long n C1("")
{
ASCII temp[N_IDBUF];
ASCII HUGE*b;


if(
nsprintf((outer_char*)(temp),OC("%lu"),1,n)>=(int)(N_IDBUF))OVERFLW("(outer_char*)(temp)","");
to_ASCII((outer_char*)(temp));

app_repl(constant);
for(b= temp;*b!='\0';b++)app_repl(*b)
app_repl(constant);
}



unsigned long otoi FCN((b,b1))
CONST ASCII HUGE*b C0("Beginning of string.")
CONST ASCII HUGE*b1 C1("End of string.")
{
unsigned long n= 0;

for(b++;b<b1;b++)
n= 8*n+*b-060;

return n;
}



unsigned long btoi FCN((b,b1))
CONST ASCII HUGE*b C0("Beginning of string.")
CONST ASCII HUGE*b1 C1("End of string.")
{
unsigned long n= 0;

for(b+= 2;b<b1;b++)
n= 2*n+*b-060;

return n;
}


SRTN rdc_char_constant(VOID)
{
int n;

if(*++id_first==0134)
switch(*++id_first)
{

case 060:n= '\0';break;
case 0134:n= 0134;break;
case 047:n= 047;break;
case 042:n= 042;break;
case 077:n= 077;break;/* Microsoft doesn't like. */
case 0141:n= 07;break;/* SGI didn't understand. */
case 0142:n= 010;break;
case 0146:n= 014;break;
case 0156:n= 012;break;
case 0162:n= 015;break;
case 0164:n= 011;break;
case 0166:n= 013;break;


default:

err0_print(ERR_T,OC("Invalid escape sequence '\\%c' \
in Ratfor character constant; null assumed"),1,XCHR(*id_first));
n= 0;
break;
}
else n= *id_first;

if(*(id_first+1)!=047)
err0_print(ERR_T,OC("Ratfor character constant longer \
than one byte; extra characters ignored"),0);

app_converted(n);
}


SRTN cp_ASCII(VOID)
{
if(*id_first++==047)
{/* Single |ASCII| character. */
if(C_LIKE(language))
app_aconst('o',YES);/* Octal (leading zero). */
else
app_aconst('d',NO);/* Decimal. */

if(*id_first!=047)

{
ASCII temp[100],HUGE*t= temp;

id_first--;

if(id_first[-1]==0134)
id_first--;

while(*id_first!=047)
*t++= *id_first++;

*t= '\0';


macro_err(OC("! $A('%c') requires just one character between \
the single quotes; did you mean $A(\"%s\")?"),NO,temp[0],temp);
}


}
else
{/* Do whole string. */
if(C_LIKE(language))
{
app_repl(042);

while(*id_first!=042)
{
app_repl(0134);
app_aconst('o',NO);/* Octal, no leading zero. */
}

app_repl(042);
}
else
{
sixteen_bits a;
ASCII delim= (ASCII)(is_RATFOR_(language)?042:047);
int n= STRLEN(t_style.ASCII_fcn);

/*  Preface by function call from style file. */
a= ID_NUM(t_style.ASCII_fcn,t_style.ASCII_fcn+n);

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}


app_repl(050);
app_repl(delim);
while(*id_first!=042)
app_repl(*id_first++);
app_repl(delim);
app_repl(051);
}
}

#if(0) /* Keep around for compilers that can't handle the above. */
/* Do whole string, essentially converting to form \
``\.{@'a',@'b',@'c'}''. */
app_repl(0173);

while(*id_first!=042)
{
app_aconst(YES);
app_repl(054);
}

app_repl(060);/* String terminator. */
app_repl(0175);
}
#endif
}



SRTN app_aconst FCN((fmt_char,leading_zero))
outer_char fmt_char C0("Either 'o' (octal) or 'd' (decimal)")
boolean leading_zero C1("For octal format")
{
eight_bits n;/* Value of the constant. */
outer_char value[10],*v;

if(*id_first==0100)
{/* The construction `\.{@'@@'}'. */
n= *id_first++;/* Advance past first~`\.{@}'. */

if(*id_first!=0100)
err0_print(ERR_T,OC("Should use double @ within \
ASCII constant"),0);
else id_first++;
}
else if(*id_first==0134)
{/* Something like `\.{@'\\040'}' or~`\.{@'\\n'}', or it could \
be an escaped delimiter. */
id_first++;/* Advance past the escape character. */

n= esc_achar((CONST ASCII HUGE*HUGE*)&id_first);

}
else n= *id_first++;/* ``Ordinary construction'' like `\.{@'a'}'. */

/* The following statement is for development while debugging the character \
set translations.  From a normal \FTANGLE, \.{touch \{ftangle,common\}.web} \
and run \.{make} with \
``\.{DEBUGGING=-mscramble\_ASCII}''.  This adds some extra code to scramble \
all the |ASCII| constants.  Then define |DEBUG_XCHR| in \
\.{custom.h} and run \.{make} with ``\.{DEBUGGING=-a}''; this scrambles the \
|ASCII| constants but also compiles using the new translation table. \
Hopefully, it should work as before. */
#ifdef scramble_ASCII
n= xxord[n];
#endif

#ifdef unscramble_ASCII
n= XCHR(n);
#endif

/* Now |n|~has the numerical value of the |ASCII| constant; in octal, it's \
something like~|0123|.  We now just append the octal representation as a \
constant. */
app_repl(constant);


if(
nsprintf(value,OC(fmt_char=='o'?"%s%o":"%s%d"),2,leading_zero?"0":"",n)>=(int)(10))OVERFLW("value","");

for(v= value;*v;v++)
app_repl(XORD(*v));

app_repl(constant);

#if(0) /* Kept around in case compiler can't understand \.{\%o}. */
int l;

if(leading_zero)app_repl(060);/* Beginning zero signifies octal constant. */

value[0]= 060+(n>>6);/* Left-most digit. */
value[1]= 060+((n-0100*(n>>6))>>3);/* Center digit. */
value[2]= 060+(n-010*(n>>3));/* Right-most digit. */

for(l= 0;l<3;l++)
if(value[l]!=060)break;/* Kill off leading zeros for beauty. */

for(;l<3;l++)
app_repl(value[l]);/* Nontrivial part. */

#endif
}



SRTN i_ascii_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
int len;/* Length to copy. */
eight_bits*start= pargs[0]+1;/* Starting address of argument. */

CHK_ARGS("$A",1);

if(translate_ASCII)
{
eight_bits HUGE*tok_ptr0= tok_ptr;/* Save starting position. */

if(*start==stringg)
id_first= (ASCII HUGE*)(start+1);
else
{

err0_print(ERR_T,OC("Argument of _A should be quoted; \
just returning argument"),0);
goto just_return;
}

cp_ASCII();/* Build result in the token area. */

len= PTR_DIFF(int,tok_ptr,tok_ptr0);
MCHECK(len,"_ascii_");
memcpy(mp,tok_ptr0,len);
tok_ptr= tok_ptr0;/* Reset position. */
}
else
{/* Just return the string argument. */
just_return:
len= PTR_DIFF(int,pargs[1],start);
MCHECK(len,"_ascii_");
STRNCPY(mp,start,len);
}

mp+= len;
}



SRTN scan_module(VOID)
{
name_pointer p= NULL;/* module name for the current module */

module_count++;

params= global_params;
frz_params();
set_output_file(global_language);

progress();


{
parsing_mode= INNER;
nuweb_mode1= nuweb_mode;

next_control= ignore;

if(module_count==1)
{
*(mp-1)= 0100;
*mp= 0155;
divert((ASCII HUGE*)macrobuf,(ASCII HUGE*)mp,STOP);/* Begin \
		reading from \
		the macro buffer, when some macros were predefined with \
		|save_macro|. |mp-1| is positioned to the blank after the \
		last definition. */
}

/* Skip \TeX\ stuff and expand the definition section. */
scanning_TeX= YES;
scan_text(macro,p,EXPAND);
scanning_TeX= NO;

if(module_count==1)
{
IN_COMMON ASCII HUGE*pbp;


breakpoints= BOOLEAN(MAC_LOOKUP(ID_NUM(pbp,pbp+3))!=NULL);
}

;

if(mlevel!=0)
{

err0_print(ERR_M,OC("Invalid preprocessor block structure (level %d). \
Missing @#endif?"),1,mlevel);
mlevel= 0;
}
}

;/* \TeX, \.{@d}, \.{@f}. */

switch(next_control)
{
case begin_code:/* \.{@a} */
{
boolean nuweb_mode0= nuweb_mode;

params= global_params;/* The unnamed module has the global state. */
nuweb_mode= nuweb_mode0;
frz_params();
set_output_file(global_language);

p= name_dir;


if(FORTRAN_LIKE(language)&&!free_form_input)

{
loc= limit+1;
column_mode= YES;
parsing_mode= OUTER;
}



;
break;
}

case module_name:/* \.{@<} */
if(cur_module)
{
p= cur_module;
params= cur_module->mod_info->params;/* Restore state. */
}
else
{/* We get here if the module name was bad. */
/* The above wasn't a good idea.  It's better to flush the module. */
while((next_control= skip_ahead(ignore,NO))!=new_module)
;
return;
}


{
}




{
while((next_control= get_next())==053)
;/* Allow optional `\.{+=}". */

if(next_control!=075&&next_control!=eq_eq)
{

err0_print(ERR_T,OC("Code text of %s flushed; = sign is missing"),1,MTRANS);


while((next_control= skip_ahead(ignore,NO))!=new_module)
;

return;
}
}

;
frz_params();


if(FORTRAN_LIKE(language)&&!free_form_input)

{
loc= limit+1;
column_mode= YES;
parsing_mode= OUTER;
}



;
break;

default:return;
}

next_control= ignore;
scan_text(module_name,p,EXPAND);/* Expand the code section. */
column_mode= NO;


;/* Code. */
}



SRTN scan_text FCN((text_type,p,expand))
int text_type C0("Either |macro| or |module_name|.")
CONST name_pointer p C0("Module name.")
boolean expand C1("Do we expand?")
{
boolean if_switch;
boolean scanned_if= NO;
boolean first_text= YES;
eight_bits HUGE*pp;
text_pointer q;

scanning_defn= BOOLEAN(text_type==macro);

if(++mlevel>=MAX_LEVEL)
FATAL(T,"!! Conditional nesting depth exceeded","");/* Increment and \
remember the incoming processing level. */

WHILE()
{
if(scanning_defn&&expand)
{
while(next_control<=ignore_defn)
{/* Skip \TeX\ stuff, \.{@f}, \.{@l}, \.{@v}, and \.{@W}. */
if((next_control= 
skip_ahead(next_control,YES))==module_name)
{/* scan the module name too */
loc-= 2;next_control= get_next();
}
}
scanning_TeX= NO;
}
else /* Process incoming code text. */
if(!expand)
{
while((next_control= 
skip_ahead(next_control,YES))==module_name)
if((next_control= skip_ahead(next_control,YES))!=ignore)

err0_print(ERR_T,OC("Expected @> after @<"),0);
}
else
{/* Process another complete fragment of code. */

{
store_two_bytes((sixteen_bits)(LINE_NUM+module_count));
}



scan_repl(module_name,stop_the_scan);/* Now |cur_text| \
points to the replacement text. */


{
}




{
if(p==name_dir||p==NULL)
{/* Unnamed module, or bad module name */
cur_text->module_text= (first_text&&mlevel==1);

/* The unnamed module begins in the global language.  However, subsequent \
language changes within one section---e.g., by preprocessing---should be \
retained. */
if(cur_text->module_text)
cur_text->Language= (boolean)global_language;

last_unnamed->text_link= (sixteen_bits)(cur_text-text_info);
/* Link the unnamed module together. */
last_unnamed= cur_text;/* Present end of the unnamed module. */
}
else if(p->equiv==(EQUIV)text_info)
{/* First module of this name. */
cur_text->module_text= YES;
p->equiv= (EQUIV)cur_text;
}
else
{/* Link on the |cur_text| to the linked list. */
LANGUAGE language0;

q= (text_pointer)p->equiv;/* Start of the chain. */
language0= (LANGUAGE)q->Language;/* Global language of this module. */

/* Each replacement text (for a module name) has the same language as the \
first in the chain.  Thus language switching works very efficiently; \
modules inherit the language of their superior.  On the other hand, \
preprocessor fragments should retain the current language, as should the \
fragment following a preprocessor fragment. */
cur_text->module_text= (first_text&&mlevel==1);

if(cur_text->module_text)
cur_text->Language= (boolean)language0;

/* Find end of list, delimited by |module_flag|.  (There's nothing \
comparable to |last_unnamed| to tell us where the end is.) */
while(q->text_link<module_flag)q= q->text_link+text_info;

q->text_link= (sixteen_bits)(cur_text-text_info);
/* Append more stuff to this module by linking in |cur_text|. */
}

/* |cur_text| has now been linked to the end of the appropriate chain.  Use \
|module_flag| as a special |text_link| to signify the end of the list. */
cur_text->text_link= module_flag;
}


first_text= NO;
}

next_macro_token:
switch(next_control)
{


case m_ifdef:
DEF_OR_NDEF(M_TRUE);
break;

case m_ifndef:
DEF_OR_NDEF(M_FALSE);
break;

case m_if:
found_else= NO;

if(!expand)
{
to_endif(m_if);
goto next_macro_token;
}
else

{

{
boolean scan0= scanning_defn;

scanning_defn= YES;
scan_repl(macro,STOP);
scanning_defn= scan0;

cur_text->nargs= UNDEFINED_MACRO;

pp= xmac_text(macrobuf,cur_text->tok_start,tok_ptr);/* See \.{macs.web}. */
if_switch= eval(pp,mp);/* See \.{eval.web}. */
}

;
GET_LINE;/* Skip possible comment at end of \.{@\#if}. */

if(if_switch)
scan_text(text_type,p,if_switch);
else

{
expand= NO;to_else();

if(next_control!=m_endif)
{
scanned_if= YES;
goto next_macro_token;
}
else
{
next_control= ignore;
expand= YES;
GET_LINE;/* Skip possible comment after \.{@\#endif} */
break;
}
}


}



break;

case m_elif:
/* The |elif| is essentially the inverse of |if|. If we were in the midst \
of an expansion, everything else must be skipped until |endif|. This is \
done via |to_endif|; we must process the |endif| again in order to return \
properly from the recursive scan in progress.  If we were not in the midst \
of an expansion, we got here via a |to_else|; we must now proceed just as \
though this were an |if|. */
next_control= ignore;

if((mlevel==1&&!scanned_if)||found_else)
{
OUT_OF_ORDER("elif");
break;
}

scanned_if= NO;

if(expand)
{
to_endif(m_elif);
goto next_macro_token;
}
else

{

{
boolean scan0= scanning_defn;

scanning_defn= YES;
scan_repl(macro,STOP);
scanning_defn= scan0;

cur_text->nargs= UNDEFINED_MACRO;

pp= xmac_text(macrobuf,cur_text->tok_start,tok_ptr);/* See \.{macs.web}. */
if_switch= eval(pp,mp);/* See \.{eval.web}. */
}

;
GET_LINE;/* Skip possible comment at end of \.{@\#if}. */

if(if_switch)
scan_text(text_type,p,if_switch);
else

{
expand= NO;to_else();

if(next_control!=m_endif)
{
scanned_if= YES;
goto next_macro_token;
}
else
{
next_control= ignore;
expand= YES;
GET_LINE;/* Skip possible comment after \.{@\#endif} */
break;
}
}


}



expand= YES;
break;

case m_else:
/* When processing an |else|, we take action based on the opposite of the \
|expand| flag currently in effect. If |expand == YES|, we must then skip \
everything else until the |endif|. This is done with |to_end|; we must \
process the |endif| again in order to return properly from the recursion in \
progress when we got here.  If |expand == NO|, we got here via a |to_else|; \
we must now expand everything until the |endif|. */
next_control= ignore;

if((mlevel==1&&!scanned_if)||found_else)
{
OUT_OF_ORDER("else");
break;
}

found_else= YES;
scanned_if= NO;

expand= BOOLEAN(!expand);

GET_LINE;/* Skip possible comment after \.{@\#else}. */

if(expand)
scan_text(text_type,p,expand);
else
{
to_endif(m_else);
expand= YES;
goto next_macro_token;
}

break;

case m_endif:
next_control= ignore;

if(mlevel==1)
{
OUT_OF_ORDER("endif");
break;
}

found_else= NO;
GET_LINE;/* Skip possible comment after \.{@\#endif}. */
mlevel--;
return;/* Ends recursion on |scan_text|. */

case m_undef:
if(!expand)
next_control= ignore;
else
{
if((next_control= get_next())!=identifier)

err0_print(ERR_M,OC("Identifier must follow @#undef"),0);
else
{
undef(ID_NUM(id_first,id_loc),SILENT);
GET_LINE;/* Skip possible comment at end of \
\.{@\#undef}. */
}
}
break;

case m_line:
CONFUSION("preprocessor cases","m_line shouldn't reach here");

case m_for:
case m_endfor:
if(!expand)next_control= ignore;
else
{

err0_print(ERR_M,OC("Sorry, preprocessor command isn't implemented yet"),0);
}
break;



case new_output_file:

err0_print(ERR_T,OC("@O and @o are allowed only in the code \
section; command ignored"),0);
next_control= ignore;
loc= limit+1;
break;

case definition:case undefinition:
case WEB_definition:
if(!expand)
next_control= ignore;
else
{
name_pointer np;
eight_bits last_control;

if((np= app_macro(last_control= next_control))
==NULL)continue;
else if(last_control==WEB_definition)
np->equiv= (EQUIV)cur_text;
}
break;


default:
if(next_control<=ignore_defn)
break;

mlevel--;
return;
}
}
}



SRTN out_of_order FCN((cmd))
CONST outer_char cmd[]C1("Name of bad preprocessor command.")
{

err0_print(ERR_M,OC("Ignored out-of-order \"@#%s\" (mlevel = %d)"),2,cmd,mlevel);
}



SRTN to_else(VOID)
{
int elevel= 0,elifs[MAX_LEVEL],elses[MAX_LEVEL],k;

for(k= 0;k<MAX_LEVEL;k++)
elifs[k]= elses[k]= 0;

WHILE()
switch(next_control= skip_ahead(next_control,NO))
{
case m_if:
case m_ifdef:
case m_ifndef:
elevel++;
break;

case m_elif:
if(elses[elevel])

err0_print(ERR_M,OC("Can't have @#elif after @#else"),0);
elifs[elevel]++;
if(elevel==0)return;
break;

case m_else:
if(elses[elevel]++)

err0_print(ERR_M,OC("Only one @#else allowed \
(scanning to @else)"),0);
if(elevel==0)
{
if(language==TEX&&!get_line())
loc= limit+1;
return;
}
break;

case m_endif:

elifs[elevel]= elses[elevel]= 0;

if(elevel--==0)
{
found_else= NO;
if(language==TEX&&!get_line())
loc= limit+1;
return;
}
break;

case new_module:

err0_print(ERR_M,OC("Section ended during scan for \
\"@#else\", \"@#elif\", or \"@#endif\". Inserted \"@#endif\". \
(elevel = %d)"),1,elevel);
if(elevel==0)
found_else= NO;

return;/* The |new_module| is turned into an |m_endif|. */
}
}



SRTN to_endif FCN((m_case))
int m_case C1("Case that called to_endif")
{
int elevel= 1,elifs[MAX_LEVEL],elses[MAX_LEVEL],k;

for(k= 0;k<MAX_LEVEL;k++)
elifs[k]= elses[k]= 0;

if(m_case==m_elif)
elifs[elevel]= 1;
else
{
if(m_case==m_else)
elses[elevel]= 1;
}

WHILE()
switch(next_control= skip_ahead(next_control,NO))
{
case m_if:
case m_ifdef:
case m_ifndef:
elevel++;
break;

case m_elif:
if(elses[elevel])

err0_print(ERR_M,OC("Can't have @#elif after @#else"),0);
elifs[elevel]++;
break;

case m_else:
if(elses[elevel]++)

err0_print(ERR_M,OC("Only one @#else allowed \
(scanning to @endif)"),0);
break;

case m_endif:

elifs[elevel]= elses[elevel]= 0;

if(--elevel==0)
{
found_else= NO;
if(language==TEX&&!get_line())
loc= limit+1;
return;
}
break;

case new_module:

err0_print(ERR_M,OC("Section ended during scan for \
\"endif\"; inserted \"endif\". (elevel = %d)"),1,elevel);
if(elevel==0)
found_else= NO;
return;
}
}



name_pointer app_macro FCN((last_control))
eight_bits last_control C1("Last token processed.")
{
sixteen_bits a;
name_pointer np= NULL;
boolean make_recursive= NO;
ASCII insert_type[6];
int insert_num= 0;
eight_bits temp[2];/* Holds the macro identifier. */
boolean nuweb_mode0= nuweb_mode;

nuweb_mode= NO;/* Don't parse the beginning of macro defn's literally. */

is_WEB_macro= BOOLEAN(last_control==WEB_definition);

if(is_WEB_macro||C_LIKE(language))
{
while((next_control= get_next())==012)
;/* Allow definition to start on  next line. */

if(is_WEB_macro)
if(next_control==MAKE_RECURSIVE)
{
make_recursive= YES;
next_control= get_next();
}
else if(next_control==AUTO_INSERT)

{
ASCII c;

while((c= *loc++)!=END_AUTO_INSERT)
{
if(*loc==040)
{

err0_print(ERR_M,OC("Found space instead of ']' after automatic \
insertion material"),0);
break;
}

if(loc==limit)break;

if(insert_num>=6)
{
if(insert_num++==6)

err0_print(ERR_M,OC("Can't have more than 6 types of automatic \
insertion material; remaining ignored"),0);
continue;
}

switch(c)
{
case 052:
STRNCPY(insert_type,"pmsfbi",insert_num= 6);
break;

case 0160:case 0120:
case 0155:case 0115:
case 0163:case 0123:
case 0146:case 0106:
case 0142:case 0102:
case 0151:case 0111:
insert_type[insert_num++]= c;
break;

default:

err0_print(ERR_M,OC("Auto insertion type must be one of \
\"ibfmps\""),0);
continue;
}
}

next_control= get_next();
}



if(next_control!=identifier)
{

err0_print(ERR_M,OC("Definition flushed in %s; must start with \
identifier"),1,MTRANS);

np= NULL;
goto done_append;
}

a= ID_NUM_ptr(np,id_first,id_loc);/* The identifier. */

/* Process auto insertion. */
temp[0]= LEFT(a,ID0);temp[1]= RIGHT(a);

{
while(insert_num-->0)
switch(insert_type[insert_num])
{
case 0160:case 0120:
if(insert.program.end>insert.program.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"program");
STRNCPY(insert.program.start,temp,2);
insert.program.end= insert.program.start+2;
break;

case 0155:case 0115:
if(insert.module.end>insert.module.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"module");
STRNCPY(insert.module.start,temp,2);
insert.module.end= insert.module.start+2;
break;

case 0163:case 0123:
if(insert.subroutine.end>insert.subroutine.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"subroutine");
STRNCPY(insert.subroutine.start,temp,2);
insert.subroutine.end= insert.subroutine.start+2;
break;

case 0146:case 0106:
if(insert.function.end>insert.function.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"function");
STRNCPY(insert.function.start,temp,2);
insert.function.end= insert.function.start+2;
break;

case 0142:case 0102:
if(insert.blockdata.end>insert.blockdata.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"blockdata");
STRNCPY(insert.blockdata.start,temp,2);
insert.blockdata.end= insert.blockdata.start+2;
break;

case 0151:case 0111:
if(insert.interface.end>insert.interface.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"interface");
STRNCPY(insert.interface.start,temp,2);
insert.interface.end= insert.interface.start+2;
break;
}
}



/* Append the lhs. */
app_repl(temp[0]);
app_repl(temp[1]);

np->macro_type= IMMEDIATE_MACRO;
/* Mark this name as a macro. |macro_type| isn't otherwise used by \Tangle. */

if(*loc!=050)
{
if(is_WEB_macro)
{app_repl(040);}
else if(C_LIKE(language))
{/* For outer macros, identifier must be separated \
from replacement text */
app_repl(stringg);app_repl(040);app_repl(stringg);
}
}
}

nuweb_mode= nuweb_mode0;
scan_repl((eight_bits)macro,(boolean)(!scanning_defn));/* Copy stuff \
			verbatim. (Also sets the language.) */

/* Finish off storing the macro. */
if(is_WEB_macro)

{
text_ptr->tok_start= tok_ptr= argize(cur_text->tok_start,tok_ptr);/* Set \
	new end by possibly stripping off newlines. */
cur_text->Language= (boolean)global_language;/* This value shouldn't matter. */
cur_text->recursive= make_recursive;
}


else
cur_text->nargs= (eight_bits)CHOICE(last_control==definition,
OUTER_MACRO,OUTER_UNMACRO);/* Mark the outer macros. */

cur_text->text_link= macro;/* |text_link=0| characterizes a macro. */

done_append:
is_WEB_macro= NO;/* Reset. */
return np;
}



SRTN app_dmacro FCN((p,p1))
CONST eight_bits HUGE*p C0("Start")
CONST eight_bits HUGE*p1 C1("End.")
{
eight_bits a0,a1;
sixteen_bits a;
name_pointer np;
boolean make_recursive= NO;

if(*p==MAKE_RECURSIVE)
{
make_recursive= YES;
p++;
}

if(p+2>p1)
{

macro_err(OC("! Invalid argument to $DEFINE"),YES);
return;
}

if(TOKEN1(a0= *p++))
{

macro_err(OC("! $DEFINE flushed; must start with identifier"),YES);
return;
}

a= IDENTIFIER(a0,a1= *p++);
app_repl(a0);
app_repl(a1);

np= name_dir+a;

np->macro_type= IMMEDIATE_MACRO;

if(*p==075){p++;app_repl(040);}/* Allow for zero-argument macro. */

while(p<p1){app_repl(*p++);}


{
if(text_ptr>text_end)OVERFLW("texts","x");
cur_text= text_ptr;
(++text_ptr)->tok_start= tok_ptr;/* The next start is the present end. */
}

;

{
text_ptr->tok_start= tok_ptr= argize(cur_text->tok_start,tok_ptr);/* Set \
	new end by possibly stripping off newlines. */
cur_text->Language= (boolean)global_language;/* This value shouldn't matter. */
cur_text->recursive= make_recursive;
}

;
cur_text->text_link= macro;
np->equiv= (EQUIV)cur_text;
}



SRTN i_define_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
CHK_ARGS("$M",1);

app_dmacro(pargs[0]+1,pargs[1]);
}



SRTN i_undef_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits a0;
eight_bits HUGE*p= pargs[0]+1;

CHK_ARGS("$UNDEF",1);

if(p+2>pargs[1])
{

macro_err(OC("! Invalid argument to $UNDEF(...)"),YES);
return;
}

if(TOKEN1(a0= *p++))
{

macro_err(OC("! $UNDEF(...) flushed; must start with identifier"),YES);
return;
}

undef(IDENTIFIER(a0,*p),NO);
}



SRTN phase1(VOID)
{
LANGUAGE language0= language;

phase= 1;
module_count= 0;
rst_input();rst_out(NOT_CONTINUATION);
reading(web_file_name,NO);

while((next_control= skip_ahead(ignore,NO))!=new_module)
;/* Skip stuff before first module.  This may reset the language. */

chk_override(language0);
fin_language();/* Make sure flags are initialized properly. */
global_params= params;/* Remember the global parameters. */
set_output_file(global_language);/* Language in force at the \
				beginning of each module. */

while(!input_has_ended)
scan_module();/* Do each module one at a time. */

chk_complete();/* Anything left in change file? */

{
name_pointer np;


for(np= name_dir;np<name_ptr;np++)
if(np->equiv!=NULL&&np->equiv!=(EQUIV)text_info
&&np->macro_type==NOT_DEFINED)
num_distinct_modules++;

num_modules= module_count;
}


}



SRTN i_modules_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
outer_char temp[50];
int m= 
nsprintf(temp,OC("%c%u%c"),3,XCHR(constant),*(pargs[0]+2)=='0'?num_distinct_modules:num_modules,XCHR(constant));

CHK_ARGS("$MODULES",1);

MCHECK(m,"_modules_");
STRCPY(mp,to_ASCII(temp));
mp+= m;
}



SRTN see_tstatistics(VOID)
{
CLR_PRINTF(info,("\n\nMEMORY USAGE STATISTICS:\n"));
STAT0("names",sizeof(*name_ptr),
SUB_PTRS(name_ptr,name_dir),max_names,smin0(MAX_VAL("n")),"n",",");

STAT0("replacement texts",sizeof(*text_ptr),
SUB_PTRS(text_ptr,text_info),max_texts,smin0(MAX_VAL("x")),"x",",");

STAT0("deferred texts",sizeof(*txt_dptr),
SUB_PTRS(txt_dptr,txt_dinfo),dtexts_max,smin0(MAX_VAL("dx")),"dx",";");

STAT0("bytes",sizeof(*byte_ptr),
SUB_PTRS(byte_ptr,byte_mem),max_bytes,smin0(MAX_VAL("b")),"b",",");

STAT0("tokens",sizeof(*tok_ptr),
SUB_PTRS((mx_tok_ptr>tok_ptr?mx_tok_ptr:tok_ptr),tok_mem),
max_toks,smin0(MAX_VAL("tt")),"tt",",");

STAT0("deferred tokens",sizeof(*tok_dptr),
SUB_PTRS((mx_dtok_ptr>tok_dptr?mx_dtok_ptr:tok_dptr),tok_dmem),
max_dtoks,smin0(MAX_VAL("dt")),"dt",".");

mem_avail(1);/* How much memory left at end of run. */
}



SRTN t_macros(VOID)
{


SAVE_MACRO("_MODULE_NAME $STRING($$MODULE_NAME)");
SAVE_MACRO("$MODULE_NAME $STRING($$MODULE_NAME)");



SAVE_MACRO("_STUB(s)$IFCASE($LANGUAGE_NUM,\
{missing_mod(#s);},{missing_mod(#s);},\
call nomod(#s),call nomod(#s),\
call nomod(#s),call nomod(#s),\
\\missingmod{s},\
%nomod(s),%nomod(s))");

SAVE_MACRO("$STUB(s)$IFCASE($LANGUAGE_NUM,\
{missing_mod(#s);},{missing_mod(#s);},\
call nomod(#s),call nomod(#s),\
call nomod(#s),call nomod(#s),\
\\missingmod{s},\
%nomod(s),%nomod(s))");



SAVE_MACRO("_VERSION $STRING($$VERSION)");
SAVE_MACRO("$VERSION $STRING($$VERSION)");



SAVE_MACRO("_DAY $TM(0)");
SAVE_MACRO("_DATE $TM(1)");
SAVE_MACRO("_TIME $TM(2)");

SAVE_MACRO("$DAY $TM(0)");
SAVE_MACRO("$DATE $TM(1)");
SAVE_MACRO("$TIME $TM(2)");

SAVE_MACRO("_TM(i)$STRING($$TM(i))");
SAVE_MACRO("$TM(i)$STRING($$TM(i))");






SAVE_MACRO("_A(s)$$ASCII(s)");
SAVE_MACRO("$A(s)$$ASCII(s)");

SAVE_MACRO("_ASCII(s)$$ASCII(s)");
SAVE_MACRO("$ASCII(s)$$ASCII(s)");



SAVE_MACRO("_INCR(N,...)$INCR0(#!N,$EVAL(N+$IFELSE(#0,0,1,#1)))");
SAVE_MACRO("$INCR(N,...)$INCR0(#!N,$EVAL(N+$IFELSE(#0,0,1,#1)))");

SAVE_MACRO("_DECR(N,...)$INCR0(#!N,$EVAL(N-$IFELSE(#0,0,1,#1)))");
SAVE_MACRO("$DECR(N,...)$INCR0(#!N,$EVAL(N-$IFELSE(#0,0,1,#1)))");

SAVE_MACRO("_INCR0(N,N1)$M(#!N N1)");
SAVE_MACRO("$INCR0(N,N1)$M(#!N N1)");



SAVE_MACRO("_MODULES $$MODULES(0)");
SAVE_MACRO("$MODULES $$MODULES(0)");

SAVE_MACRO("_SECTIONS $$MODULES(1)");
SAVE_MACRO("$SECTIONS $$MODULES(1)");



SAVE_MACRO("$DO(k,kmin,kmax,...)$UNROLL(k,kmin,kmax,$IFCASE(#0,1,#.))");

;
}



SRTN out_msg FCN((msg,msg1))
CONST ASCII*msg C0("Start of message.")
CONST ASCII*msg1 C1("See the description below.")
{
eight_bits HUGE*temp;
eight_bits HUGE*mp0= mp,
HUGE*macrobuf0= macrobuf,HUGE*macrobuf_end0= macrobuf_end;
char HUGE*new_msg;/* The translated message. */
boolean nuweb_mode0,in_string0,meta_mode0;

/* Translate the message, which may contain identifiers, into the |macrobuf|.*/
mp= macrobuf= temp= GET_MEM("out_msg:temp",MSG_BUF_SIZE,eight_bits);
macrobuf_end= temp+MSG_BUF_SIZE;

/* If |msg1 != NULL|, then it denotes the end of the array. If it is \
|NULL|, we assume it's an ordinary character string and determine the end. */
if(msg1==NULL)
msg1= msg+STRLEN(msg);

new_msg= (char HUGE*)str_to_mb((eight_bits HUGE*)msg,
(eight_bits HUGE*)msg1,NO);

/* Ship it out in the form of a meta-comment. */
spcs_after_cmnt= SPCS_AFTER_CMNT;

/* We bracket the output message by a standard set of |nuweb_mode|, \
|meta_mode|, and |in_string| in order that the top, bottom, and prefix \
fields work correctly. */
nuweb_mode0= nuweb_mode;
in_string0= in_string;
meta_mode0= meta_mode;

meta_mode= nuweb_mode= NO;

OUT_CHAR(begin_meta);
OUT_CHAR(begin_meta);/* Second one turns off |xpn_Ratfor|. */
while(*new_msg)
OUT_CHAR(*new_msg++);
OUT_CHAR(end_meta);

nuweb_mode= nuweb_mode0;
in_string= in_string0;
meta_mode= meta_mode0;

spcs_after_cmnt= 0;

FREE_MEM(temp,"out_msg:temp",MSG_BUF_SIZE,eight_bits);
macrobuf= macrobuf0;mp= mp0;macrobuf_end= macrobuf_end0;
}



static sixteen_bits id_unroll;

SPEC univ_tokens[]= {
{"_UNROLL",0,x_unroll,&id_unroll},
{"$UNROLL",0,x_unroll,&id_unroll},
{"",0,NULL,NULL}
};

SRTN ini_univ_tokens FCN((language0))
LANGUAGE language0 C1("")
{
ini_special_tokens(language0,univ_tokens);
}



SRTN ini_tokens FCN((language0))
LANGUAGE language0 C1("")
{
switch(language0)
{
case C:
break;

case C_PLUS_PLUS:
break;

case FORTRAN:
break;

case FORTRAN_90:
break;

case TEX:
break;

default:
break;
}

ini_univ_tokens(language0);
}



int get_constant FCN((e))
eight_bits HUGE*e C1("")
{
boolean positive= YES;
int i= 1;/* To prevent the increment from being~0 when an error occurs. */

if(*e==055)
{
positive= NO;
e++;
}

if(*e++!=constant)
{

err0_print(ERR_T,OC("Invalid loop constant"),0);
return i;
}

to_outer(e);
i= ATOI(e);
return(positive)?i:-i;
}




#endif /* |part == 3| */


