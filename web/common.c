#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06."  \
  COMMAND LINE: "web/ftangle web/common -A -# --F -= 1.53/web/common.c" \
  RUN TIME: "Saturday, September 23, 1995 at 16:17." \
  WEB FILE:    "web/common.web" \
  CHANGE FILE: (none)
#endif
#define _COMMON_h  
#define COMMON_FCNS_   \

#define VERSION  "1.53"
#define RELEASE  "September 23, 1995" \

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

#define def_flag  10240 /* must be strictly larger than |max_modules| */ \

#define xref  equiv_or_xref /* The trouble with this is that |xref| is a \
	|xref_pointer| whereas |equiv_or_xref| is |ASCII|. This means that \
	lots of casting needs to be done to keep the compiler happy. Hence \
	the previous |typedef|. */ \

#define app(a)*(tok_ptr++)= a /* Ordinary token */
#define APP_ID  app(id_flag+PTR_DIFF(sixteen_bits,id_lookup(id_first,id_loc,normal),name_dir))
#define app1(a)app(tok_flag+PTR_DIFF(sixteen_bits,(a)->trans,tok_start))/* Store translation \
		as token list; should translate to the following: */
#define trans  trans_plus.Trans /* translation texts of scraps */
#define no_math  2
#define yes_math  1
#define maybe_math  0 \

#define id_flag  10240 /* Signifies an identifier. */
#define res_flag  2*id_flag /* Signifies a reserved word. */
#define mod_flag  ((sixteen_bits)(3*(sixteen_bits)id_flag)) \
/* Signifies a module name. */
#define tok_flag  ((sixteen_bits)(4*(sixteen_bits)id_flag))/* signifies a token list. */
#define inner_tok_flag  ((sixteen_bits)(5*(sixteen_bits)id_flag)) \
/* Signifies a token list in `\Cb'. */ \
 \

#define freeze_text  *(++text_ptr)= tok_ptr \

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

#define STKLEN  20000U /* Borland needs this number; Microsoft requires it from \
			the compiler line. */ \

#define first_text_char  0 /* Lowest interesting value of an |outer_char|. */
#define last_text_char  0377 /* Highest interesting value of an |outer_char|. */ \

#define TOO_LONG   \
{ \
char temp[200]; \
sprintf(temp,"please use the `-ybs...' option to increase buffer size from \
its present value of %lu characters",buf_size); \
FATAL(C,"Input line too long; ",temp); \
} \

#define N_WORK  3
#define N_END  (N_WORK+2) \

#define is_point(c)(point_comments&&c=='!') \

#define MARK(type,delim,len)mark_cmnt(type,delim,len,p) \

#define BLANK_OUT(d)MEMSET((d)->pos,040,(d)->len) \

#define is_C_style_cmnt  (C_style_cmnt= ((short_cmnt= Cpp_comments&&*lp== \
057&&*(lp+1)==057))||(*lp==057&&*(lp+1)==052)) \

#define start_comment  (is_C_style_cmnt||(*lp==(char)begin_comment0) \
||(*lp==(char)begin_comment1)) \

#define start_Rcomment  ((R_style_cmnt= BOOLEAN(*lp==cmnt_char&& \
*(lp+1)!=cmnt_char&&*(lp-1)!=cmnt_char&& \
!(*(lp-1)==0100)))||is_C_style_cmnt) \

#define k0  cur0_prms->K0
#define found_at  cur0_prms->Found_at
#define at_line  cur0_prms->At_line \

#define LINES_DONT_MATCH  (change_limit-change_buffer!=limit-cur_buffer|| \
STRNCMP(cur_buffer,change_buffer,PTR_DIFF(size_t,limit,cur_buffer))) \

#define change_params  prms[incl_depth].input_params \

#define ABORT_ON_ERROR  YES
#define DONT_ABORT_ON_ERROR  NO \

#define FCLOSE(file_ptr)if(file_ptr!=stdin)fclose(file_ptr);file_ptr= NULL \

#define MAX_SIZE_T  ((BUF_SIZE)(size_t)(~(0L)))/* Maximum argument to |calloc|. */ \

#define PTR_BASE  "[%p,%p) "/* To style file? */ \

#define SHOW_MEM  0 /* Don't display by default. */ \

#define BP_MARKER  1 \

#define PROPER_END(end) \
end= (np+1)->byte_start; \
if(*end==BP_MARKER&&np!=npmax)end= ((BP*)end)->byte_start \

#define MAX_ID_LENGTH  32 /* Truncated identifiers can't be longer than this. */ \

#define hash_size  353 /* should be prime */ \

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

#define MAX_ERR_BUF  160 \

#define WEAVE_LINE0  OC("{\"")
#define TANGLE_LINE0  OC("  COMMAND LINE: \"") \

#define WEAVE_LINE1  OC("\"} ")
#define TANGLE_LINE1  OC("\"") \

#define ESCAPE_LENGTH  256 \

#define MAX_INI_ARGS  100 /* Max \# of arguments in the ini file. */
#define T_SIZE  200 /* Buffer length for |fgets|. */
#define INI_CMNT_CHAR  '%' \

#define BEFORE_CHAR  '-'
#define MIDDLE_CHAR  '0'
#define AFTER_CHAR  '&' \

#define HOME  OC("HOME")/* The Unix-standard name for the top-level directory. */
#define ENV_INI  OC("FWEB_INI")/* Default root name to use. */
#define ENV_INCLUDES  OC("FWEB_INCLUDES")/* The include path. */ \

#define AUX_LEN  200
#define MAX_MOD_NAMES  3 /* No more than this many names in one error message. */ \

#define NMOD_TEMP  200 \

#define THE_FILE_NAME  (a_file_name?pa:(outer_char HUGE*)"stdin") \

#define ARG_BUFFER_SIZE  500
#define COPY_TO_ARG_BUFFER(c)if(pa<arg_buffer_end)*pa++= c; \
else OVERFLW("arg buffer bytes","")
#define MAX_ARGS  100 \

#define STARTING_DO_NUM  UL(90000L) \

#define NOT(flag)BOOLEAN((!flag)^not) \

#define G_RATIO  2.0
#define MIN_G_RATIO  0.0 /* This value definitively turns off the computed |goto|. */ \

#define MARGINAL_CASES  5L
#define MIN_MARGINAL_CASES  1 \

#define MAX_SPREAD  UL(128L)
#define MIN_MAX_SPREAD  1 \

#define SPRM_LEN  1500 \

#define LANGUAGE_SEPARATOR  '='/* Separates language from file name. */ \

#define DFLT_FNAME_LENGTH  20 \

#define UPDATE_TERMINAL  fflush(stdout)/* Empty the terminal output buffer. */ \

#define new_line  putchar('\n')
#define putxchar  putchar \

#define TIMING_PREC  10 /* Check that |cpu <= wall| by multiplying seconds by \
				this number, then truncating. */ \




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




#ifdef ibmpc /* \.{Machine-dependent}: For initializing the stack size. */
#ifdef borland
extern unsigned _stklen= STKLEN;
#endif
#endif




IN_COMMON ASCII xord[last_text_char+1];/* Converts input chars.\ to |ASCII|. */
#ifdef scramble_ASCII
ASCII xxord[last_text_char+1];/* For scrambling. */
#endif
IN_COMMON outer_char xchr[0200];/* Converts output chars.\ from |ASCII|. */



extern DOTS dots0[],mcmds[];/* These are put into \.{typedefs.web} so we can \
				make use of the various \.{@d}s. */



IN_COMMON BUF_SIZE delta_dots;/* Expand the table in increments of this size. */
IN_COMMON BUF_SIZE ndots;/* The current total size. */
IN_COMMON DOTS HUGE*dots,HUGE*dots_end,HUGE*next_dot;/* The dynamic array. */



IN_COMMON BUF_SIZE buf_size;/* Holds input line. */

IN_COMMON ASCII HUGE*loc;
/* Points to the next character to be read from the buffer. */

typedef enum{START,END}DELIM_TYPE;
typedef enum{NO_CMNT,SHORT_CMNT,LONG_CMNT}CMNT_TYPE;

typedef struct
{
CMNT_TYPE type;
DELIM_TYPE delim;
eight_bits len;/* Length of the delimiter; either~$0$, $1$, or~$2$. */
ASCII HUGE*pos;/* Start of the delimiter. */
}CMNT_DATA;

IN_COMMON CMNT_DATA posns[50],HUGE*pcmnt CSET(posns);



IN_COMMON ASCII HUGE*pk;



IN_COMMON ASCII HUGE*lp,HUGE*semi_pos;
IN_COMMON boolean found_text,text,C_style_cmnt,short_cmnt,R_style_cmnt;



IN_COMMON ASCII HUGE*last_pos;
IN_COMMON ASCII cmnt_char;



IN_COMMON sixteen_bits module_count;/* The current module number. */

IN_COMMON BUF_SIZE max_modules;/* Greater than the total number of modules. */
IN_COMMON boolean HUGE*chngd_module;/* Dynamic array: Is the module changed? */

IN_COMMON boolean prn_where CSET(NO);
/* Tells \.{TANGLE} to print line and file info */
IN_COMMON boolean return_toggle CSET(NO);
/* Switch used for sending back an `\.{@i}' when |toggle_includes| \
	is on. */
IN_COMMON boolean toggling CSET(NO);/* In the middle of a toggle include? */
IN_COMMON boolean popped CSET(NO);/* After popping the stack? */
IN_COMMON boolean no_more_input CSET(NO);
/* Temporary replacement for |input_has_ended|. */

IN_COMMON int tracing;/* For debugging \.{WEAVE}. */



/* Ideally, the following numbers should be large enough to handle both \
\FTANGLE\ and \FWEAVE. In the comments, we show some characteristic \
statistics. */

/* \.{Machine-dependent:} Machines with limited memory. */
#if SMALL_MEMORY
#define DFLT_BYTES 10000 /* \.{fweave fweave} $\approx$ 23,300. */
#define DFLT_BUF_SIZE 1500
#define DFLT_C_BUF_SIZE 200
#define DFLT_FMT_SIZE 200
#define DFLT_MSG_SIZE 1000
#define DFLT_DELTA_DOTS 20
#define DFLT_MAX_LBLS 20
#define DFLT_LINE_LENGTH 80
#define DFLT_LONGEST_NAME 1000
#define DFLT_MAX_EXPR_CHARS 500
#define DFLT_MAX_IFILES 10
#define DFLT_MAX_INCLUDE_DEPTH 10
#define DFLT_MAX_MARGS 20
#define DFLT_MAX_MODULES 400
#define DFLT_MBUF_SIZE 32767
#define DFLT_MAX_NAMES 1000 /* \.{fweave fweave} $\approx$ 3,300. */
#define DFLT_MAX_REFS 2500 /* \.{fweave ftangle} $\approx$ 5,850. */
#define DFLT_SBUF_LEN 300
#define DFLT_STACK_SIZE_T 50
#define DFLT_STACK_SIZE_W 210 /* \.{fweave fweave} $\approx$ 200. */
#define DFLT_MAX_SCRAPS 1000 /* \.{fweave fweave} $\approx$ 900. */
#define DFLT_MAX_TOKS_T 50000L /* \.{ftangle fweave} $\approx$ 92,000. */
#define DFLT_MAX_TOKS_W 6000 /* \.{fweave fweave} $\approx$ 6,700. */
#define DFLT_MAX_DTOKS 2500
#define DFLT_MAX_TEXTS 2500 /* \.{fweave fweave} $\approx$ 4,500. */
#define DFLT_MAX_DTEXTS 100
#define DFLT_NUM_FILES 15
#define DFLT_OP_ENTRIES 147
#define DFLT_X_BUF_SIZE 80
#else /* Large limits. */
#define DFLT_BYTES 90000L
#define DFLT_BUF_SIZE 1500
#define DFLT_C_BUF_SIZE 255
#define DFLT_FMT_SIZE 500
#define DFLT_MSG_SIZE 2000
#define DFLT_DELTA_DOTS 20
#define DFLT_MAX_LBLS 20
#define DFLT_LINE_LENGTH 80
#define DFLT_LONGEST_NAME 10000
#define DFLT_MAX_EXPR_CHARS 500
#define DFLT_MAX_IFILES 100
#define DFLT_MAX_INCLUDE_DEPTH 10
#define DFLT_MAX_MARGS 20
#define DFLT_MAX_MODULES 2000
#define DFLT_MBUF_SIZE 50000L
#define DFLT_MAX_NAMES 4000
#define DFLT_MAX_REFS 20000
#define DFLT_SBUF_LEN 300
#define DFLT_STACK_SIZE_T 50
#define DFLT_STACK_SIZE_W 400
#define DFLT_MAX_SCRAPS 10000
#define DFLT_MAX_TOKS_T 150000L
#define DFLT_MAX_TOKS_W 25000
#define DFLT_MAX_DTOKS 25000
#define DFLT_MAX_TEXTS 10239
#define DFLT_MAX_DTEXTS 500
#define DFLT_NUM_FILES 15
#define DFLT_OP_ENTRIES 157
#define DFLT_X_BUF_SIZE 80
#endif /* Limited memory. */




IN_COMMON name_pointer name_ptr;/* First unused position in |byte_start|. */
IN_COMMON ASCII HUGE*byte_ptr;/* First unused position in |byte_mem|. */



IN_COMMON ASCII HUGE*pformat,HUGE*pdefault,HUGE*pdata,
HUGE*pbp,HUGE*pinclude,HUGE*ppragma,HUGE*pcontains;



IN_COMMON outer_char outp_buf[MAX_OUTPUT_LINE_LENGTH];
/* FORTRAN's output buffer. */
IN_COMMON int nbuf_length CSET(72);

IN_COMMON outer_char wbprefix[MAX_FILE_NAME_LENGTH];
/* Possible directory prefix for the web file name. */

/* Signifies the end of a directory prefix. */
IN_COMMON outer_char prefix_end_char CSET(PREFIX_END_CHAR);

IN_COMMON boolean all_std CSET(NO);/* Do we route all output to |stdout|? */



IN_COMMON STMT_LBL max_stmt CSET(STARTING_DO_NUM);
IN_COMMON int not;/* For the negations of options. */



IN_COMMON double g_ratio CSET(G_RATIO);
IN_COMMON unsigned short marginal_cases CSET(MARGINAL_CASES);
IN_COMMON CASE_TYPE max_spread CSET(MAX_SPREAD);



IN_COMMON CONST char*day[]
#if(part == 0 || part == 1)
= {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}
#endif /* |part == 1| */
;

IN_COMMON CONST char*month[]
#if(part == 0 || part == 1)
= {"January","February","March","April","May","June","July",
"August","September","October","November","December"}
#endif /* |part == 1| */
;



#if TIMING

IN_COMMON clock_t clock0;
IN_COMMON TIME_T time0;

#if NEW_DIFFTIME
double diff_time FCN((t1,t0))
TIME_T t1 C0("")
TIME_T t0 C1("")
{
#if HAVE_GETTIMEOFDAY
return(double)(t1.tv_sec-t0.tv_sec)
+1.0e-6*(double)(t1.tv_usec-t0.tv_usec);
#else
#if HAVE_SYS_TIMEB_H
return(double)t1.time-(double)t0.time
+1.0e-3*((double)t1.millitm-(double)t0.millitm);/* \
Without the casts, this line didn't work right on the DECstation. I think \
it has to do with the |unsigned short| type of |millitm|; a compiler bug \
with type promotion. */
#else
return t1-t0;
#endif /* |HAVE_SYS_TIMEB_H| */
#endif
}
#endif /* |NEW_DIFFTIME| */

#endif /* |TIMING| */




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
outer_char*secno;/* The \LaTeX\ section number. */
sixteen_bits pageno,modno0;
boolean subpage_flag;/* |YES| if more than one section per page. */
}SECT_INFO;

IN_COMMON SECT_INFO HUGE*sect_info;

IN_COMMON outer_char HUGE*HUGE*mod_names;
IN_COMMON outer_char HUGE*HUGE*next_mod_name,HUGE*HUGE*last_mod_name;




IN_COMMON long start_line CSET(1);
/* Must be |long|; a negative value is used as a flag. */
IN_COMMON long end_line CSET(LONG_MAX);



IN_COMMON int stored_line_length;
IN_COMMON ASCII HUGE*stored_line;/* Allocated dynamically. */



IN_COMMON outer_char last_include_file[MAX_FILE_NAME_LENGTH]CSET(""),
this_include_file[MAX_FILE_NAME_LENGTH]CSET("");




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



EXTERN output_state cur_state;/* |cur_end|, |cur_byte|, |cur_name|, \
	|cur_repl|, |cur_mod|, |cur_global_language|, and |cur_language|. */

EXTERN long stck_size;/* Number of simultaneous levels of macro expansion. */
EXTERN output_state HUGE*stack;/* Dynamic array: Info for non-current levels. */
EXTERN stack_pointer stck_end;/* End of |stack|. */
EXTERN stack_pointer stck_ptr;/* First unused loc.\ in the output state stack. */



IN_COMMON ASCII string_char;
IN_COMMON boolean in_char_string;



IN_COMMON INPUT_PARAMS change_params0
#if(part == 0 || part == 1)
= {FORTRAN,OUTER,NO}
#endif
;



IN_COMMON BUF_SIZE max_ifiles;
IN_COMMON int num_ifiles;
IN_COMMON outer_char**ifiles;/* Dynamic array of unique include file names. */



#ifndef C_TYPES
#include SFILE(y_type.h)
#endif /* |C_TYPES| */



IN_COMMON BUF_SIZE total_mem CSET(0);
/* Current total dynamically allocated memory. */
IN_COMMON BUF_SIZE max_mem CSET(0);/* The maximum bytes that were allocated. */



IN_COMMON boolean show_mem CSET(SHOW_MEM);
IN_COMMON BUF_SIZE show_size CSET(10000);/* Display for |nbytes >= show_size|. */



IN_COMMON MEM mem[]
#if(part == 0 || part == 1)
= {
{"b",1,
1000,DFLT_BYTES,ULONG_MAX},/* |"b"|.  |max_bytes|: the \
number of bytes in identifiers, index entries, and module names. */
{"bs",1,
500,DFLT_BUF_SIZE,2000},/* |"bs"|.  |change_buffer| etc. */
{"cb",1,
10,DFLT_C_BUF_SIZE,1000},/* |"cb"|. |C_buf_size|: see |C_putc|. */
{"cf",1,
100,DFLT_FMT_SIZE,UL(65536L)},/* |"cf"|.|cmd_fsize|: see |out_cmd|. */
{"cg",1,
100,DFLT_MSG_SIZE,UL(65536L)},/* |"cg"|. |cmd_size|: see |out_cmd| */
{"d",sizeof(DOTS),
20,DFLT_DELTA_DOTS,255},/* |"d"|.  |delta_dots|: Number of \
additional entries to reallocate for |dots| if necessary. */
{"dt",sizeof(eight_bits),
1000,DFLT_MAX_DTOKS,ULONG_MAX},/* |"dt"|.  |max_dtoks|. */
{"dx",sizeof(text),
100,DFLT_MAX_DTEXTS,10239},/* |"dx"|.  |dtexts_max|. */
{"id",sizeof(INPUT_PRMS),
1,DFLT_MAX_INCLUDE_DEPTH,100},/* |"id"|.  |prms| (open files). */
{"if",sizeof(outer_char*),
1,DFLT_MAX_IFILES,10000},/* |"if"|.  |max_ifiles|. */
{"kt",sizeof(output_state),
10,DFLT_STACK_SIZE_T,100},/* |"kt"|.  Tangle's |stck_size|. */
{"kw",sizeof(output_state),
50,DFLT_STACK_SIZE_W,1000},/* |"kw"|.  Weave's |stck_size|. */
{"lb",sizeof(BEGUN),
5,DFLT_MAX_LBLS,255},/* |"lb"|. |max_lbls|. */
{"ll",1,
60,DFLT_LINE_LENGTH,255},/* |"ll"|.  |line_length| for \
\FWEAVE's output. */
{"ln",1,
3*MAX_FILE_NAME_LENGTH,DFLT_LONGEST_NAME,UL(50000L)},
/* |"ln"|.  |longest_name|: module names and strings shouldn't be longer \
than this. */
{"lx",1,
25,DFLT_MAX_EXPR_CHARS,UL(65536L)},/* |"lx"|.  |max_expr_chars|. */
{"m",sizeof(boolean),
100,DFLT_MAX_MODULES,10239},/* |"m"|.  |max_modules|: \
larger than the max number of modules. */
{"ma",sizeof(sixteen_bits),
1,DFLT_MAX_MARGS,255},/* |"ma"|.  |max_margs|. */
{"mb",1,
5000,DFLT_MBUF_SIZE,UL(65536L)},/* |"mb"|. |mbuf_size|. */
{"n",sizeof(NAME_INFO)+sizeof(name_pointer),
500,DFLT_MAX_NAMES,10239},/* |"n"|.  |max_names|: \
number of identifiers, strings, module names; must be less than 10240. */
{"nf",sizeof(OPEN_FILE),
1,DFLT_NUM_FILES,256},/* |"nf"|.  |num_files|. */
{"op",sizeof(OPERATOR),
142,DFLT_OP_ENTRIES,256},/* |"op"|. \
|op_entries| */
{"r",sizeof(xref_info),
500,DFLT_MAX_REFS,UL(65536L)},/* |"r"|. |max_refs|: number of \
cross-references; must be less than 65536. */
{"s",sizeof(scrap),
1000,DFLT_MAX_SCRAPS,ULONG_MAX},/* |"s"|.  |max_scraps|. */
{"sb",sizeof(outer_char),
100,DFLT_SBUF_LEN,1000},/* |"sb"|.  |sbuf_len|. */
{"tt",sizeof(eight_bits),
10000,DFLT_MAX_TOKS_T,ULONG_MAX},/* |"tt"|.  Tangle's \
|max_toks|: Total for the entire code; can be big. */
{"tw",sizeof(sixteen_bits),1000,
DFLT_MAX_TOKS_W,UL(65536L)},/* |"tw"|.  Weave's |max_toks|: \
number of symbols in code texts being parsed;  must be less than 65536. */
{"x",sizeof(text),
500,DFLT_MAX_TEXTS,10239},/* |"x"|.  |max_texts|. */
{"xb",1,
10,DFLT_X_BUF_SIZE,1000},/* |"xb"|. |X_buf_size|: see |C_putc|. */
{"",0,0,0}
}
#endif /* |part == 1| */
;

IN_COMMON size_t sizeof_mem CSET(sizeof(mem));



IN_COMMON boolean info_option CSET(NO);
IN_COMMON boolean see_rsrvd CSET(NO);
IN_COMMON RSRVD rsrvd
#if(part == 0 || part == 1)
= {NULL,NO,NO,NO}
#endif /* |part == 1| */
;
IN_COMMON outer_char HUGE*style_args CSET(NULL);
IN_STYLE ASCII HUGE*at_codes;



IN_COMMON CONST char*origin_name[]
#if(part == 0 || part == 1)
= {"","COMMON","FTANGLE","FWEAVE","RATFOR","MACROS","STYLE"}
#endif /* |part == 1| */
;



IN_COMMON boolean found_web,found_change;/* Have these names been seen? */
IN_COMMON outer_char wbflnm0[MAX_FILE_NAME_LENGTH];
/* The root name of the web file. */



IN_COMMON outer_char
HUGE*ini_args[MAX_INI_ARGS],/* Arguments read from the ini file. */
HUGE*HUGE*new_args,/* The new list of all arguments; allocated \
dynamically. */
HUGE*HUGE*pn;/* Pointer to the current new argument being processed. */
IN_COMMON outer_char HUGE*HUGE*pn0;/* Marks end of ini args. */
IN_COMMON FILE*ini_file CSET(NULL);/* The ini file \.{.fweb}. */



IN_COMMON INCL_PATHS incl;



IN_COMMON outer_char style_file_name[MAX_FILE_NAME_LENGTH]
CSET(STYLE_FILE_NAME);
IN_COMMON boolean renamed_style CSET(NO);



IN_COMMON boolean doing_cmd_line;/* Command line or optional arguments? */
IN_COMMON boolean cmd_prms;/* Stuff from ini file or from command line? */



IN_COMMON ASCII HUGE*fbuffer,HUGE*flimit,HUGE*floc;/* Saved position \
				of current file. */



IN_COMMON BUF_SIZE starting_memory CSET(ULONG_MAX);
/* Set at first call to |mem_avail|. */



/* For pc's, the file is split into two compilable parts using the \
compiler-line macro |part|, which must equal either~1 or~2. */
#if(part != 2)


SRTN
common_init(VOID)
{
IN_RATFOR SRTN is_Rat_present PROTO((VOID));
struct tm*t= the_localtime();/* Initialize the time. */

#if(TRANSLATE_ASCII || DEBUG_XCHR)
translate_ASCII= YES;/* Force it for the cases that really need it. */
#endif

banner();/* Start-up banner. */

is_Rat_present();/* Find out if the \Ratfor\ package was linked on. */


{
STRNCPY(xchr,"                                 !\"#$%&'()*+,-./0123456789\
:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ ",
sizeof(xchr));

/* Interesting ``invisible'' things to output. */
xchr[tab_mark]= '\t';
xchr[012]= '\n';

/* nothing needs to be done */

;

{
int i;/* to invert the correspondence */


/* Initialize to |ASCII| blanks. */
for(i= first_text_char;i<=last_text_char;i++)
{
xord[i]= 040;
#ifdef scramble_ASCII
xxord[i]= 040;
#endif
}

/* The |NUL| and |DEL| characters are left alone! */
for(i= 1;i<0177;i++)
{
xord[(eight_bits)XCHR_[i]]= (ASCII)i;
#ifdef scramble_ASCII
xxord[(eight_bits)wt_style.xchr[i]]= i;
#endif
}

#ifdef scramble_ASCII
for(i= 0177;i<=0377;i++)
xxord[(eight_bits)wt_style.xchr[i]]= i;
#endif

#if(DEBUG_XCHR)
for(i= 0177;i<=0377;i++)
xord[(eight_bits)XCHR_[i]]= (ASCII)i;
#endif
}

;
}



{
int k;

for(k= 0;k<128;k++)
TeX[k]= TeX_other;

for(k= 0101;k<=0132;k++)
TeX[k]= TeX_letter;

for(k= 0141;k<=0172;k++)
TeX[k]= TeX_letter;

TeX[0134]= TeX_escape;
TeX[0173]= TeX_bgroup;
TeX[0175]= TeX_egroup;
TeX[044]= TeX_math_shift;
TeX[046]= TeX_alignment_tab;
TeX[012]= TeX_eol;
TeX[043]= TeX_parameter;
TeX[0136]= TeX_superscript;
TeX[0137]= TeX_subscript;
TeX[0]= TeX_ignored;
TeX[040]= TeX[tab_mark]= TeX_space;
TeX[0176]= TeX_active;
TeX[045]= TeX_comment;
TeX[0177]= TeX_invalid;
}

;

{
ALLOC(INPUT_PRMS,prms,"id",max_include_depth,1);
}



hash= GET_MEM("hash",hash_size,name_pointer);
hash_end= hash+hash_size-1;

for(h= hash;h<=hash_end;*h++= NULL);



pformat= x__to_ASCII(OC("format"));
pdata= x__to_ASCII(OC("data"));
pdefault= x__to_ASCII(OC("default"));
pbp= x__to_ASCII(OC("_BP"));
pinclude= x__to_ASCII(OC("include"));
ppragma= x__to_ASCII(OC("pragma"));

conv_bi(incl_likes);
conv_bi(WEB_incl_likes);
conv_bi(non_labels);

conv_dot(dots0);
conv_dot(mcmds);




SET_VAL(mbuf_size,"mb");

;
predefine_macros();/* Must be done before parsing the command line, so \
the user can undefine or override stuff if desired. */

{
#define FSET(flag) =  flag

active_brackets FSET(ACTIVE_BRACKETS);/* Special array handling? */
all_cmnts_verbatim FSET(ALL_CMNTS_VERBATIM);/* Should \.{TANGLE} copy \
					all comments? */
all_includes FSET(ALL_INCLUDES);/* Cross-reference all include files? */
auto_app_semi FSET(AUTO_APP_SEMI);/* For \.{WEAVE}, automatically \
append a pseudo-semi to the end of \.{WEB} macro definitions? */
auto_line FSET(AUTO_LINE);/* Auto-insert line nums after \.{@\%}? */

/* Append automatic semicolon? */
params.Auto_semi[LN(FORTRAN)]= YES;

params.Auto_semi[LN(FORTRAN_90)]
= params.Auto_semi[LN(RATFOR)]
= params.Auto_semi[LN(RATFOR_90)]
= params.Auto_semi[LN(C)]
= params.Auto_semi[LN(C_PLUS_PLUS)]
= params.Auto_semi[LN(LITERAL)]
= params.Auto_semi[LN(TEX)]
= NO;

params.Beeps FSET(BEEPS);

/* Do we label |do|s and |if|s with the block number? */
params.Block_nums[LN(C)]
= params.Block_nums[LN(C_PLUS_PLUS)]
= params.Block_nums[LN(LITERAL)]
= params.Block_nums[LN(TEX)]
= NO;

params.Block_nums[LN(FORTRAN)]
= params.Block_nums[LN(FORTRAN_90)]
= params.Block_nums[LN(RATFOR)]
= params.Block_nums[LN(RATFOR_90)]
= BLOCK_NUMS;

bslash_continued_strings FSET(BSLASH_CONTINUED_STRINGS);/* Do the \
continuations of strings require a starting backslash? */
chk_ifelse FSET(CHK_IFELSE);/* Protect parenthesized strings? */
chk_stmts FSET(CHK_STMTS);/* Check statement syntax in \Ratfor? */
compare_outfiles FSET(COMPARE_OUTFILES);/* Compare new vs.\ old output. */
compound_assignments FSET(COMPOUND_ASSIGNMENTS);/* Do we allow things \
							like \.{+=}? */
Cpp FSET(NO);/* Do we recognize \.{C++}? */

dbg_output FSET(DBG_OUTPUT);/* Print output characters? */
deferred_macros FSET(DEFERRED_MACROS);/* Allow deferred macros? */

defn_mask.outer_macros FSET(PRN_OUTER_MACROS);
defn_mask.formats FSET(PRN_fORMATS);
defn_mask.Formats FSET(PRN_FORMATS);
defn_mask.limbo FSET(PRN_LIMBO);
defn_mask.macros FSET(PRN_MACROS);
defn_mask.v FSET(PRN_V);
defn_mask.w FSET(PRN_W);

dot_constants FSET(DOT_CONSTANTS);/* Recognize dot constants? */

params.CPP_comments[LN(C)]
= params.CPP_comments[LN(C_PLUS_PLUS)]
= params.CPP_comments[LN(LITERAL)]
= params.CPP_comments[LN(TEX)]
= CPP_COMMENTS;

/* For \Fortran\ and \Ratfor, the \.{//}~is preempted for concatenation. \
Therefore, its use for short comments must be turned on explicitly. */
params.CPP_comments[LN(FORTRAN)]
= params.CPP_comments[LN(FORTRAN_90)]
= params.CPP_comments[LN(RATFOR)]
= params.CPP_comments[LN(RATFOR_90)]
= NO;

Fortran88 FSET(FORTRAN88);/* Turn on stuff for Fortran-88? */
Fortran_label FSET(FORTRAN_LABEL);/* Label on same line? */

params.Free_form_input[LN(FORTRAN)]
= params.Free_form_input[LN(FORTRAN_90)]
= params.Free_form_input[LN(LITERAL)]
= params.Free_form_input[LN(TEX)]
= NO;
params.Free_form_input[LN(RATFOR)]
= params.Free_form_input[LN(RATFOR_90)]
= params.Free_form_input[LN(C)]
= params.Free_form_input[LN(C_PLUS_PLUS)]
= YES;

keep_trailing_comments FSET(KEEP_TRAILING_COMMENTS);/* For \TeX. */

params.In_escape[LN(FORTRAN)]
= params.In_escape[LN(FORTRAN_90)]
= '&';
params.In_escape[LN(RATFOR)]
= params.In_escape[LN(RATFOR_90)]
= params.In_escape[LN(C)]
= params.In_escape[LN(C_PLUS_PLUS)]
= params.In_escape[LN(LITERAL)]
= params.In_escape[LN(TEX)]
= '\\';

in_escape FSET(IN_ESCAPE);/* Default continuation character. */
index_hidden FSET(INDEX_HIDDEN);/* Index skipped includes files. */
input_macros FSET(INPUT_MACROS);/* Generate the default ``\.{\\input \
					fwebmac.tx}'' line? */
lc_keywords FSET(LC_KEYWORDS);/* Lower-case \Fortran\ keywords? */
line_info FSET(LINE_INFO);/* Should \FTANGLE\ print out line info? */
lowercase_tokens FSET(LOWERCASE_TOKENS);/* Output lower-case tokens? */
m4 FSET(M4_);
no_xref FSET(NO_XREF);/* Should \.{WEAVE} print an index? */
number_dos FSET(NUMBER_DOS);
nuweb_mode FSET(NUWEB_MODE);/* Emulate \.{nuweb}? */
overload_ops FSET(OVERLOAD_OPS);/* Is operator overloading allowed? */

params.Point_comments[LN(C)]
= params.Point_comments[LN(C_PLUS_PLUS)]
= params.Point_comments[LN(TEX)]
= params.Point_comments[LN(LITERAL)]
= NO;
params.Point_comments[LN(FORTRAN)]
= params.Point_comments[LN(FORTRAN_90)]
= params.Point_comments[LN(RATFOR)]
= params.Point_comments[LN(RATFOR_90)]
= POINT_COMMENTS;/* Does \.! signify a Fortran comment? */

prn_contents FSET(PRN_CONTENTS);/* Print the table of contents? */
prn_index FSET(PRN_INDEX);/* Print the index? */
prn_input_lines FSET(NO);/* Used in |input_ln| to print out the \
lines sent back. */
prn_input_addresses FSET(NO);/* Print out the buffer addresses. */
prn_modules FSET(PRN_MODULES);/* Print the module list? */
prn_semis FSET(PRN_SEMIS);/* Print semicolons in \Fortran\ output? */

quoted_includes FSET(QUOTED_INCLUDES);
/* Cross-reference quoted include files? */
Ratfor77 FSET(RATFOR77);/* Expand \Ratfor\ code directly to \
\Fortran-77? */
read_iformats FSET(READ_IFORMATS);/* Read include files for formats. */
params.Reverse_indices[LN(C)]
= params.Reverse_indices[LN(C_PLUS_PLUS)]
= params.Reverse_indices[LN(TEX)]
= params.Reverse_indices[LN(LITERAL)]
= NO;
params.Reverse_indices[LN(FORTRAN)]
= params.Reverse_indices[LN(FORTRAN_90)]
= params.Reverse_indices[LN(RATFOR)]
= params.Reverse_indices[LN(RATFOR_90)]
= REVERSE_INDICES;/* C-style indexing in \Fortran? */
rmv_files FSET(RMV_FILES);/* Remove temporary files related to \.{-H}? */

skip_ifiles FSET(SKIP_IFILES);/* \.{-j} --- skip files already included. */
skip_includes FSET(SKIP_INCLUDES);/* For \.{WEAVE}, don't read in \.{@I} \
					commands. (Uppercase '\.{I}' only.) */
statistics FSET(STATISTICS);/* Print statistics about memory usage? */
stop_the_scan FSET(YES);/* */
subscript_fcns FSET(YES);/* Module references on functions? */
suppress_cmds FSET(YES);/* ??? */
toggle_includes FSET(TOGGLE_INCLUDES);/* For \.{WEAVE}, read in \
\.{@I} commands, but don't print them out. */
top_version FSET(TOP_VERSION);/* Header info at top of output? */
translate_ASCII FSET(TRANSLATE_ASCII0);/* Do we bother with the \
|xchr|--|xord| conversions? */
translate_brackets FSET(TRANSLATE_BRACKETS);/* Do we translate \
brackets to parentheses in \Fortran? */
truncate_ids FSET(NO);/* Shorten identifiers? */
try_extensions FSET(TRY_EXTENSIONS);/* Try various file names. */
TeX_processor FSET(TEX_PROCESSOR);/* Default \TeX\ processor. */
xref_unnamed FSET(XREF_UNNAMED);/* Xref unnamed stuff. */
#undef FSET

#if(TRANSLATE_ASCII || DEBUG_XCHR)
translate_ASCII= YES;/* Force it for the cases that really need it. */
#endif

/* The following ensures that |ini_language| will work right.  (It \
references |global_params|. */
global_params= params;
}




{

{
int k;

/* We initialize the \It{local} name list; it's set to global later after \
everything else is set. */
new_fname(&tex_fname,NULL,NULL);
new_fname(&fwebmac,NULL,NULL);

for(k= 0;k<NUM_LANGUAGES;k++)
new_fname(params.outp_nm+k,NULL,NULL);
}


scan_args();

/* If there's no \WEB\ file, it must be an info option. */
if(found_web)
{
ini_input_prms(WEB_FILE,(outer_char HUGE*)"",ABORT_ON_ERROR);
/* Opens both input and change file. */

{
outer_char temp1[100],temp2[1000],
full_web_name[ESCAPE_LENGTH],esc_full_web_name[ESCAPE_LENGTH],
full_change_name[ESCAPE_LENGTH],esc_full_change_name[ESCAPE_LENGTH];
int n1,n2;
BUF_SIZE old_size;


/* Run time */
n1= program==tangle?
nsprintf(temp1,OC("\n  RUN TIME: \"%s, %s at %s.\""),3,the_day(t),the_cdate(t),the_time(t))
:
nsprintf(temp1,OC(""),0);

#if(VMS)
fgetname(web_file,full_web_name);
fgetname(change_file,full_change_name);
#else
STRCPY(full_web_name,web_file_name);
STRCPY(full_change_name,change_file_name);
#endif /* |VMS| */

esc_file_name(esc_full_web_name,ESCAPE_LENGTH,full_web_name);
esc_file_name(esc_full_change_name,ESCAPE_LENGTH,full_change_name);

n2= 
nsprintf(temp2,OC(program==tangle?
"\n  WEB FILE:    \"%s\"\n  CHANGE FILE: %c%s%c":
" {\"%s\"} {%c%s%c} "),4,esc_full_web_name,*esc_full_change_name?'"':'(',*esc_full_change_name?esc_full_change_name:OC("none"),*esc_full_change_name?'"':')');

old_size= STRLEN(cmd_ln_buf)+1;
cmd_ln_buf= (outer_char HUGE*)REALLOC(cmd_ln_buf,old_size+n1+n2,old_size);
STRCAT(cmd_ln_buf,temp1);
STRCAT(cmd_ln_buf,temp2);
}

;

if(program==weave)open_tex_file();
}

/* In case no explicit language commands are given, either on the command \
line or in the file, before encountering the first module, pick a default. */
if(language==NO_LANGUAGE)
ini_language(XORD(*LANGUAGE_CODE(GLOBAL_LANGUAGE)));

global_params= params;/* Freeze the params after arguments have been read. */
}

;

/* The next two have to be done after reading the command line. */

{
DOTS HUGE*d;

ALLOC(DOTS,dots,"d",delta_dots,0);
ndots= delta_dots;/* Initialize total size. */
dots_end= dots+ndots;
next_dot= dots;/* Current pointer. */

/* Fill the table with the initial values. */
for(d= dots0;d->len!=0;d++)
{
if(dot_code(dots,d->symbol,d->symbol+d->len,d->code)!=d->code)
CONFUSION("dots allocation","Invalid dot code");
}
}


{
BUF_SIZE cur_prms_units;

alloc(OC("id"),&cur_prms_units,0,-1);/* What is current allocation? */

if(cur_prms_units!=DFLT_MAX_INCLUDE_DEPTH)
prms= (INPUT_PRMS*)REALLOC(prms,
(cur_prms_units+1)*sizeof(INPUT_PRMS),
(DFLT_MAX_INCLUDE_DEPTH+1)*sizeof(INPUT_PRMS));
}



ALLOC(boolean,chngd_module,"m",max_modules,0);


{
ALLOC(outer_char*,ifiles,"if",max_ifiles,0);
}



ALLOC(ASCII,byte_mem,"b",max_bytes,0);/* Characters of names. */
byte_end= byte_mem+max_bytes-1;/* End of |byte_mem|. */

ALLOC(NAME_INFO,name_dir,"n",max_names,0);
/* Information about names. */
name_end= name_dir+max_names-1;/* End of |name_dir|. */

ALLOC(ASCII,mod_text,"ln",longest_name,1);
mod_end= mod_text+longest_name;/* End of |mod_text|. */




ALLOC(SECT_INFO,sect_info,"m",max_modules,0);


{
if(program==tangle)
{
ALLOC(sixteen_bits,args,"ma",max_margs,1);
max_margs++;/* So the user thinks this is really the max \#. */
}
}




CAST(name_pointer,name_dir)->byte_start= byte_ptr= byte_mem;/* position zero \
			in both arrays */
name_ptr= name_dir+1;/* |name_dir[0]| will not be used */
CAST(name_pointer,name_ptr)->byte_start= byte_mem;/* this makes name 0 of \
			length zero */



root= NULL;

;

{
if(rsrvd.args)see_reserved(&rsrvd);
if(style_args)see_style(style_args,NO);

if(!found_web&&info_option&&!at_codes)
wrap_up();
}



more_includes(wt_style.Idir);

if(found_web)
read_aux();/* Process the \.{.aux} file. */
}



ASCII HUGE*
x__to_ASCII FCN((p0))
CONST outer_char HUGE*p0 C1("Character string to translate.")
{
if(translate_ASCII)
{
ASCII HUGE*buffer,HUGE*p;
CONST outer_char HUGE*q;

buffer= GET_MEM("x__to_ASCII arg",STRLEN(p0)+1,ASCII);

for(p= buffer,q= p0;*q;p++,q++)
*p= XORD(*q);
*p= '\0';

return buffer;
}
else
return(ASCII HUGE*)p0;
}



ASCII HUGE*
x_to_ASCII FCN((p0))
CONST outer_char HUGE*p0 C1("Character string to translate.")
{
static size_t bufsiz= 0;
static ASCII HUGE*buffer= NULL;

if(translate_ASCII)
{
ASCII HUGE*p;
CONST outer_char HUGE*q;

while(bufsiz<=STRLEN(p0)+1)
{
if(buffer==NULL)
buffer= GET_MEM("x_to_ASCII_buf",bufsiz= 32,ASCII);
/* Some systems don't like a |NULL| argument to |realloc|. */
else
{
buffer= (ASCII HUGE*)REALLOC(buffer,bufsiz+32,bufsiz);
bufsiz+= 32;
}

if(buffer==NULL)
FATAL(C,"!! No more memory (x_to_ASCII)","");
}

for(p= buffer,q= p0;*q;p++,q++)
*p= XORD(*q);
*p= '\0';

return buffer;
}
else
return(ASCII HUGE*)p0;
}



ASCII HUGE*
to_ASCII FCN((p0))
outer_char HUGE*p0 C1("Character string to translate.")
{
ASCII HUGE*p;

if(translate_ASCII)
for(p= (ASCII HUGE*)p0;*p;p++)*p= XORD(*p);

return(ASCII HUGE*)p0;
}



outer_char HUGE*
to_outer FCN((p0))
ASCII HUGE*p0 C1("Internal string to translate to outer world.")
{
outer_char HUGE*p;

if(translate_ASCII)
for(p= (outer_char HUGE*)p0;*p;p++)*p= XCHR(*(ASCII HUGE*)p);

return(outer_char HUGE*)p0;
}



boolean
is_include_like(VOID)
{
/* Check for \.{m4} built-in. */
if(m4&&is_in(incl_likes,id_first,id_loc))return YES;

/* The \.{WEB} functions behave as built-ins for \.{WEAVE}, but as macros \
for \.{TANGLE}. */
if(program==tangle)return NO;

if(!(*id_first==044||*id_first==0137))return NO;/* Speed up |is_in|. */
return is_in(WEB_incl_likes,id_first,id_loc);
}


SRTN conv_bi FCN((b))
BUILT_IN HUGE*b C1("")
{
for(;b->n!=0;b++)
b->name= x__to_ASCII((outer_char*)b->name);
}

SRTN
conv_dot FCN((d))
DOTS HUGE*d C1("")
{
for(;d->code!=0;d++)
d->symbol= x__to_ASCII((outer_char*)d->symbol);
}



boolean
is_in FCN((b0,p0,p1))
CONST BUILT_IN b0[]C0("Array of built-ins.")
CONST ASCII HUGE*p0 C0("Start of text.")
CONST ASCII HUGE*p1 C1("End of text.")
{
CONST BUILT_IN HUGE*b;

for(b= b0;b->n!=0;b++)
if(web_strcmp(b->name,b->name+b->n,p0,p1)==EQUAL)
return YES;

return NO;
}



ASCII HUGE*
uppercase FCN((p,n))
ASCII HUGE*p C0("Start of text.")
int n C1("Number of bytes to convert in place.")
{
int k;

for(k= 0;k<n;++k)
p[k]= A_TO_UPPER(p[k]);/* Convert $n$~bytes in place. */

return p;/* Return beginning address of string. */
}



boolean
is_dot(VOID)
{
ASCII HUGE*p;
int n;
ASCII temp[MAX_DOT_LENGTH];/* For converting the putative constant to \
				upper case. */

/* Scan to the end of the dot constant (all of which are alphabetic). */
for(p= loc,n= 0;n<MAX_DOT_LENGTH;n++,p++)
if(*p==056||!isAlpha(*p))break;

if(*p!=056||p==loc)return NO;/* It wasn't stopped by a period, or \
	the scan didn't even get started, so it \
	can't be a dot constant. */

STRNCPY(temp,loc,n);
return BOOLEAN(CHOICE(dot_code(dots,uppercase(temp,n),temp+n,dot_const),
YES,NO));
}



eight_bits
dot_code FCN((d0,p0,p1,new_code))
DOTS HUGE*d0 C0("|DOTS| array.")
CONST ASCII HUGE*p0 C0("Start of text.")
CONST ASCII HUGE*p1 C0("End of text.")
eight_bits new_code C1("May we extend the table or not?")
{
DOTS HUGE*d;

re_dot:
for(d= d0;d<next_dot;d++)
if(web_strcmp(d->symbol,d->symbol+d->len,p0,p1)==EQUAL)
{
/* Check for an overloaded operator. If so, remember the details. */
if(d->code==dot_const)
{
STRCPY(dot_op.name+1,d->symbol);
dot_op.cat= d->cat;
dot_op.num= (eight_bits)(d-dots);
}

return d->code;
}

/* Didn't find the dot constant or operator in the table. Enlarge the table \
if necessary. */
if(!new_code)return NO;/* One can add to |dots|, but not |mcmds|. */

if(next_dot==dots_end)
{
if((dots= (DOTS HUGE*)REALLOC(dots,
(ndots+delta_dots)*sizeof(DOTS),ndots*sizeof(DOTS)))==NULL)
OVERFLW("dot operators","d");

next_dot= dots+ndots;/* Next available position. */
ndots+= delta_dots;/* New total length. */
dots_end= dots+ndots;/* Upper bound. */
}

/* Add operator to table. */
next_dot->len= PTR_DIFF(short,p1,p0);
next_dot->symbol= GET_MEM("next_dot->symbol",next_dot->len+1,ASCII);
STRNCPY(next_dot->symbol,p0,next_dot->len);
next_dot->code= new_code;/* Mark as overloaded, or initialize. */
next_dot->cat= 1;/* ??? */
d0= next_dot++;
next_dot->len= 0;
goto re_dot;
}



eight_bits
is_mcmd FCN((d0,p0,p1))
DOTS HUGE*d0 C0("|DOTS| array.")
CONST ASCII HUGE*p0 C0("Start of text.")
CONST ASCII HUGE*p1 C1("End of text.")
{
DOTS HUGE*d;

for(d= d0;d->code;d++)
if(web_strcmp(d->symbol,d->symbol+d->len,p0,p1)==EQUAL)
return d->code;

return 0;/* Not a preprocessor command. */
}




boolean
input_ln FCN((p0))
INPUT_PRMS0 HUGE*p0 C1("Which structure describes the current file?")
{
cur0_prms= p0;/* Address of current parameters. */
limit= cur_buffer;/* Initialize the top to the bottom. |limit| points to \
				first unfilled position. */

cur_line++;/* A separate line count is kept for each file (including the \
		change file). */

/* |column_mode| and |parsing_mode| may be redundant. But don't mess with \
these. */
if(!nuweb_mode&&FORTRAN_LIKE(language)&&column_mode&&parsing_mode==OUTER)
switch(language)
{
case FORTRAN:
case FORTRAN_90:
if(!rd_Fortran())
return NO;
break;

case RATFOR:
case RATFOR_90:
if(!rd_Ratfor())
return NO;

if(limit==cur_buffer)
goto empty_line;
break;

default:
CONFUSION("input_ln","Invalid FORTRAN_LIKE language");
}
else
if(!rd_free_form())
return NO;

/* Take care of an empty line: kill the semicolon. (This is a bit shaky.) */
if(column_mode&&FORTRAN_LIKE(language)&&
PTR_DIFF(size_t,limit,cur_buffer)==2&&
((!auto_semi&&(cur_buffer[1]==073||cur_buffer[1]==040))||
(auto_semi&&cur_buffer[1]==073&&(cur_buffer[0]=='C'||
cur_buffer[0]==0143||cur_buffer[0]==052))))
empty_line:
limit= cur_buffer;


#if(DEBUG)

{
register ASCII HUGE*k;

if(prn_input_lines&&cur_line>=(LINE_NUMBER)start_line
&&cur_line<(LINE_NUMBER)end_line)
{
if(prn_input_addresses)
printf("%lu->%lu (%u) ",
(unsigned long)cur_buffer,(unsigned long)limit,
PTR_DIFF(unsigned,limit,cur_buffer));

printf("%c[%d%s:%u]: \"",
(language==global_language?' ':*LANGUAGE_CODE(language)),
incl_depth,
(changing?"*":""),
cur_line);

for(k= cur_buffer;k<limit;++k)
switch(*k)
{
case(ASCII)begin_comment0:
printf("</*>");
break;

case(ASCII)begin_comment1:
printf("<//>");
break;

case interior_semi:
printf("<;>");
break;

default:
putchar(XCHR(*k));
break;
}

puts("\"");
}
}

;
#endif

return YES;/* Successful read */
}



boolean
rd_free_form(VOID)
{
register int c= '\0';/* The character read. */
register ASCII HUGE*k;/* Where next character goes. */


{
if(num_in_buffer!=0)

{
STRNCPY(cur_buffer,k0,num_in_buffer);/* Move line to beginning of buffer. */
k0= cur_buffer;/* For |scan_for_cmnts| */
limit= cur_buffer+num_in_buffer-N_END;/* Reposition the end of buffer. */
num_in_buffer= 0;/* We've now cleaned out the buffer. */
}


else
{
if(feof(cur0_prms->File))
return NO;/* We have hit end-of-file. */


{
k= cur_buffer;/* beginning of buffer */


while(k<=buffer_end&&(c= getc(cur0_prms->File))!=EOF&&c!='\n')
if((*(k++)= XORD(c))!=040)limit= k;/* Update first unfilled \
position; |k|~is now pointing to next position to fill, and the last one \
wasn't blank. */

if(k>buffer_end)
if((c= getc(cur0_prms->File))!=EOF&&c!='\n')
{
ungetc(c,cur0_prms->File);loc= cur_buffer;TOO_LONG;

}

if(c==EOF&&limit==cur_buffer)
return NO;/* There was nothing after the last newline. */
}

;
}
}



return YES;
}



boolean
rd_Fortran(VOID)
{
register int c= '\0';/* The character read. */
register ASCII HUGE*k;/* Where next character goes. */
boolean first_line= YES;

/* We're starting afresh; initialize flags. */
last_was_continued= NO;
scanning_C_cmnt= NO;
string_char= '\0';
in_char_string= NO;

/* Keep reading lines until we sense a non-comment, non-continuation line. \
Leave the latter waiting in the buffer starting at~|k0|. */
for(k= limit;;k= k0= (limit+= N_END),first_line= NO,cur_line++)
if(num_in_buffer==0)

{
int i;


if(feof(cur0_prms->File))
{
if(first_line)return NO;/* We have hit end-of-file. */
else goto concatenate_cmnts;/*	Don't lose the last line. */
}

k0= limit;/* Set the start of this line to the end of the old one. */


{
while(k<=buffer_end&&(c= getc(cur0_prms->File))!=EOF&&c!='\n')
if(c=='\t'&&k<=buffer_end-6)
for(i= 0;i<6;++i)*(k++)= 040;/* Translate tab \
character. (Don't update |limit|.) */
else
{
boolean escaped_char= NO;

if(c==';')c= XCHR(interior_semi);
else if(point_comments&&(*k0!=0100)&&
(escaped_char= BOOLEAN(c=='\\')))
{
c= getc(cur0_prms->File);/* What's coming up next? */

/* If it's not an escaped point, just copy the escape sequence. */
if(c!='!')
{
ungetc(c,cur0_prms->File);
c= '\\';
}
}

/* A point that's not escaped begins a short comment. */
if((*(k++)= CHOICE(is_point(c)&&!escaped_char,
(ASCII)begin_comment1,XORD(c)))!=040)
limit= k;/* Ignore trailing blanks. */
}

if(k>buffer_end)
if((c= getc(cur0_prms->File))!=EOF&&c!='\n')
{
ungetc(c,cur0_prms->File);loc= cur_buffer;TOO_LONG;

}

if(c==EOF&&limit==cur_buffer)return NO;/* there was nothing after \
    the last newline */
}

;/* |limit| is positioned after the last char.\ read. */

/* We will allow two extra characters at the end, in case we need to put \
end-of-comment markers there; we also need two bytes for Tangle's workspace. */
MEMSET(limit,040,N_END);
num_in_buffer= 0;/* There's nothing waiting. */

/* If we've read into a |new_module| command in column~1, \
	prepare to switch out of column mode. */
at_line= BOOLEAN(*k0==0100&&*(k0+1)!=057);

if(at_line&&(*(k0+1)==052||*(k0+1)==040))found_at= YES;

/* If we were appending, then we must delay shifting out of column mode until \
we process the first part of the buffer. However, if we're actually at the \
beginning of the buffer, then we must shift out of column mode immediately. */
if(found_at&&k0==cur_buffer)goto out_of_column_mode;

if(first_line&&at_line)break;

/* Now we look at the line we just put into the buffer. Usually, we should \
look at that to see whether it's a continuation or a comment line, because if \
so we keep on reading. However, if it's a command line, or if we're in the \
middle of handling a trailing C~comment which didn't end on the previous \
line, then this line should not be treated in column mode. */
if(scanning_C_cmnt)
{
scan_for_cmnts();
continue;
}

if(!(at_line||scanning_C_cmnt))

{
boolean is_cmnt= NO,Fortran_cmnt= NO,C_cmnt= NO;

ASCII HUGE*p= k0;/* Points to the comment character. */


/* Did we get a comment line?  */
switch(*k0)
{
case 0103:
case 0143:
case 052:
case(ASCII)begin_comment0:
case(ASCII)begin_comment1:
is_cmnt= Fortran_cmnt= YES;
break;

default:
/* Skip over white space at beginning of line. */
for(;p<limit;p++)if(*p!=040)break;

if((*p==057&&(*(p+1)==052
||(*(p+1)==057&&Cpp_comments)))
||*p==(ASCII)begin_comment0
||*p==(ASCII)begin_comment1)is_cmnt= C_cmnt= YES;
break;
}

if(is_cmnt)
{
if(limit==k0+1)
{/* Null comment line. */
limit= k0;
if(!first_line)goto last_of_read;
else goto concatenate_cmnts;
}

if(k0>cur_buffer)MEMSET(k0-N_END,040,N_END);

if(Fortran_cmnt)*p= begin_comment1;

/* If the last line was empty, we don't want to read any further; leave this \
comment waiting in the buffer. */
if(last_was_empty)
{
num_in_buffer= PTR_DIFF(size_t,limit,k0)+N_END;
comment_in_buffer= YES;
limit= cur_buffer;
break;/* Break out of the |for| loop which reads lines. */
}

scan_for_cmnts();
continue;/* Go back and read more lines. */
}




/* If we're this far, it's not a comment. Check for continuation line \
(neither blank nor |'0'| in column~6). If \
so, shift it over to abut it with previous stuff in buffer. */
if(limit-k0>=5&&!(k0[5]==040||k0[5]==060))

{
register ASCII HUGE*l;
boolean stuff_in_1_5;


if(first_line)
{/* Error: Continuation line not expected. */
scan_for_cmnts();
continue;
}

/* We don't allow anything in columns 1--5 for a continuation line. That's \
a FORTRAN rule, and it helps us to catch a possible continuation of a \
C-style comment. */
stuff_in_1_5= NO;

for(l= k0;l<k0+5;++l)
if(*l!=040)
{
stuff_in_1_5= YES;
break;
}

/*  If there's stuff in columns 1--5, it's not a continuation line. \
Otherwise, it's a continuation line; abut it with the code in the previous \
line. */
if(stuff_in_1_5)goto neither_cmnt_nor_continuation;

*l= 040;/* Delete the continuation symbol. */
scan_for_cmnts();
continue;/* Keep on reading. */
}


}




/* If we get to here, it's neither a comment nor a continuation. If this line \
was the first in the buffer, we must continue to read more.  (However, \
if this line is null, then we do not read any more, because we don't want to \
concatenate a null comment to the previous line.) Otherwise, we're \
done reading and we should leave this line waiting in the buffer. */
neither_cmnt_nor_continuation:
if(first_line)
if(limit==cur_buffer)/* Quit on null first line. */
{
comment_in_buffer= NO;
num_in_buffer= 0;
break;
}
else
{
scan_for_cmnts();
continue;/* We must read some	more to see if next is \
continuation. */
}


{
last_of_read:
if(!first_line)
{
num_in_buffer= PTR_DIFF(size_t,limit,k0)+N_END;
limit= MAX(k0-N_WORK,cur_buffer);
}
else limit+= N_WORK;

concatenate_cmnts:
anlz_cmnts();/* Concatenate comments appropriately, and set |scanning_C_cmnt|. */

cur_line--;
break;/* Break out of |for| loop. */
}

;
}


else

{

{
STRNCPY(cur_buffer,k0,num_in_buffer);/* Move line to beginning of buffer. */
k0= cur_buffer;/* For |scan_for_cmnts| */
limit= cur_buffer+num_in_buffer-N_END;/* Reposition the end of buffer. */
num_in_buffer= 0;/* We've now cleaned out the buffer. */
}

;

/* If what was waiting was a control line, we must shift out of column mode. */
if(found_at)
{
out_of_column_mode:
found_at= column_mode= last_was_empty= NO;
break;/* Break out of |for| loop which reads lines. The finish-read \
			material is moot. */
}

if(at_line)
{
last_was_empty= NO;
break;
}

/* Finally, we give special treatment to empty lines. */
last_was_empty= BOOLEAN(limit==cur_buffer);
scan_for_cmnts();
}/* Go back to the |for| loop which reads lines. */



/* Except for new module, throw away all stuff after \.{@}~command in \
column~1. */
if(*cur_buffer==0100&&!(limit==cur_buffer+1||*(cur_buffer+1)==052||
*(cur_buffer+1)==040))
for(k= cur_buffer+2;k<limit;++k)
if(*k==073)
{
*k= 040;
break;
}

return YES;
}



SRTN
mark_cmnt FCN((type0,delim0,length0,pos0))
CMNT_TYPE type0 C0("")
DELIM_TYPE delim0 C0("")
eight_bits length0 C0("")
ASCII HUGE*pos0 C1("")
{
pcmnt->type= type0;
pcmnt->delim= delim0;
pcmnt->len= length0;
pcmnt->pos= pos0;

if(type0==LONG_CMNT)scanning_C_cmnt= BOOLEAN(delim0==START);

pcmnt++;
pcmnt->type= NO_CMNT;
pcmnt->delim= START;
pcmnt->len= 0;
pcmnt->pos= limit;
}



SRTN
scan_for_cmnts(VOID)
{
register ASCII HUGE*p;

for(p= k0;p<limit;p++)
switch(*p)
{
case(ASCII)begin_comment0:
if(scanning_C_cmnt)
break;

MARK(LONG_CMNT,START,1);
break;

case(ASCII)begin_comment1:
if(scanning_C_cmnt)
break;

MARK(SHORT_CMNT,START,1);
p= limit;
MARK(SHORT_CMNT,END,0);
break;

case 047:
case 042:
if(!scanning_C_cmnt)

{
if(!in_char_string)
{
in_char_string= YES;
string_char= *p;
break;
}

if(string_char==*p&&p[1]==string_char)
{
p++;
break;
}

in_char_string= NO;
}


break;

case 057:
if(in_char_string||scanning_C_cmnt)
break;

if(*(p+1)==057&&Cpp_comments)
{
MARK(SHORT_CMNT,START,2);
p= limit;
MARK(SHORT_CMNT,END,0);
}
else if(*(p+1)==052)
{
MARK(LONG_CMNT,START,2);
p++;
}

break;

case 052:
if(in_char_string)
break;

if(scanning_C_cmnt&&*(p+1)==057)
{
MARK(LONG_CMNT,END,2);
p++;
}

break;
}
}



SRTN
anlz_cmnts(VOID)
{
CMNT_DATA*d;
boolean found_text= NO;
ASCII HUGE*l;

pcmnt->pos= limit;

for(d= posns+1;d<pcmnt;d+= 2)
{
found_text= NO;

for(l= d->pos+d->len;l<(d+1)->pos;l++)
if(*l!=040)
{
found_text= YES;
break;
}

if(found_text)
{
if(d->type==SHORT_CMNT)
{
BLANK_OUT(d-1);
*((d-1)->pos)= begin_comment0;
*(d->pos)= 052;
*(d->pos+1)= 057;
}
}
else if(d->type==(d+1)->type)
{
BLANK_OUT(d);
BLANK_OUT(d+1);
d->type= (d+1)->type= NO_CMNT;
}
}


{
boolean text_after= NO;

if(pcmnt>posns)
{/* There's at least one comment. */
if(!scanning_C_cmnt)
for(l= limit-1;l>(pcmnt-1)->pos+(pcmnt-1)->len;l--)
if(*l!=040)
{/* There's text after the comment. */
text_after= YES;
*(l+1)= 073;
break;
}

if(!text_after)
{
pcmnt-= 2;

if(pcmnt<posns)
{

err0_print(ERR_C,OC("Fortran comment didn't end; missing */?"),0);
pcmnt= posns;
}

while(pcmnt->type==NO_CMNT)
{
pcmnt--;

if(pcmnt<posns)
CONFUSION("Insert an automatic semicolon",
"Invalid comment structure");
}

for(l= pcmnt->pos-1;l>=cur_buffer;l--)
{
if(*l!=040)
{/* There's text before the comment. */
semi_pos= pcmnt->pos;

{
*(semi_pos+1)= (ASCII)(((pcmnt+1)->type==LONG_CMNT?begin_comment0:
begin_comment1));/* If the comment was started by \
	|begin_comment0| or |begin_comment1|, this overwrites the character \
	after that. (We \
	have to make room for the semicolon.) If we want to cure this, we \
	must do more copying. */

if(semi_pos>cur_buffer&&*(semi_pos-1)==0100)/* A verbatim comment. */
{
*(semi_pos--)= 0100;
}

*semi_pos= 073;/* This overwrites the beginning of the comment marker, \
	or the previous~\.{@} if there was one. */



for(lp= semi_pos-1;lp>cur_buffer;lp--)
{
if(*lp==040)continue;

if(*lp==057&&*(--lp)==0100)
{
*semi_pos= 040;
*lp= 073;*(lp+1)= 0100;*(lp+2)= 057;
}
break;
}


;
}


break;
}
}
}
}
else
{/* No comments at all. */
for(l= limit-1;l>=cur_buffer;l--)
if(*l!=040)
{
*(l+1)= 073;
break;
}
}
}



pcmnt= posns;/* Reset. */
}



boolean
rd_Ratfor(VOID)
{
register int c= '\0';/* The character read. */
register ASCII HUGE*k;/* Where next character goes. */
boolean found_semi;

string_char= '\0';
in_char_string= NO;


{
if(num_in_buffer!=0)

{
STRNCPY(cur_buffer,k0,num_in_buffer);/* Move line to beginning of buffer. */
k0= cur_buffer;/* For |scan_for_cmnts| */
limit= cur_buffer+num_in_buffer-N_END;/* Reposition the end of buffer. */
num_in_buffer= 0;/* We've now cleaned out the buffer. */
}


else
{
if(feof(cur0_prms->File))
return NO;/* We have hit end-of-file. */


{
k= cur_buffer;/* beginning of buffer */


while(k<=buffer_end&&(c= getc(cur0_prms->File))!=EOF&&c!='\n')
if((*(k++)= XORD(c))!=040)limit= k;/* Update first unfilled \
position; |k|~is now pointing to next position to fill, and the last one \
wasn't blank. */

if(k>buffer_end)
if((c= getc(cur0_prms->File))!=EOF&&c!='\n')
{
ungetc(c,cur0_prms->File);loc= cur_buffer;TOO_LONG;

}

if(c==EOF&&limit==cur_buffer)
return NO;/* There was nothing after the last newline. */
}

;
}
}



/* If we've read into a |new_module| command in column~1, \
	switch out of column mode. */
if(*cur_buffer==0100&&(limit==cur_buffer+1
||*(cur_buffer+1)==052||*(cur_buffer+1)==040))
column_mode= NO;
else

{
last_was_continued= continuing_line;
continuing_line= NO;

if(limit==cur_buffer)
return YES;

limit[0]= limit[1]= limit[2]= limit[3]= 040;

cmnt_char= 043;

found_semi= found_text= text= NO;/* Start off assuming we're in comment \
mode. */
semi_pos= NULL;/* |semi_pos| will record the position of a prospective \
comment, to be begun by a semicolon. */

/* Scan the line. */
if(!free_form_input&&!(*cur_buffer==0100&&*(cur_buffer+1)==043))
{
for(lp= cur_buffer;;)
if(!skip_Rtext()||!skp_cmnt())break;

switch(*last_pos)
{
case 053:case 055:case 052:case 075:case 0173:case 0175:
case 0136:case 046:case 0174:case 050:case 072:
case 076:case 074:case 0133:case 054:case 0134:
continuing_line= YES;
break;/* Line is continued. */

/* Ratfor's continuation character. */
case 0137:
if(last_pos>cur_buffer)
{
ASCII c;

c= *(last_pos-1);
if(isAlpha(c)||isDigit(c)||
c==0137||c==044)
goto not_continuation;
}
*last_pos= 040;
continuing_line= YES;
break;

default:
not_continuation:
if(!auto_semi)break;

/* If the last construction is a comment (|!text|) and there was actually \
some text (|semi_pos!=NULL|), \
replace ``\.{\slashstar}'' by |';'| and |begin_comment0| or \
|begin_comment1|. */
if(!text&&semi_pos!=NULL)
{
*(semi_pos+1)= (ASCII)(((pcmnt+1)->type==LONG_CMNT?begin_comment0:
begin_comment1));/* If the comment was started by \
	|begin_comment0| or |begin_comment1|, this overwrites the character \
	after that. (We \
	have to make room for the semicolon.) If we want to cure this, we \
	must do more copying. */

if(semi_pos>cur_buffer&&*(semi_pos-1)==0100)/* A verbatim comment. */
{
*(semi_pos--)= 0100;
}

*semi_pos= 073;/* This overwrites the beginning of the comment marker, \
	or the previous~\.{@} if there was one. */



for(lp= semi_pos-1;lp>cur_buffer;lp--)
{
if(*lp==040)continue;

if(*lp==057&&*(--lp)==0100)
{
*semi_pos= 040;
*lp= 073;*(lp+1)= 0100;*(lp+2)= 057;
}
break;
}


;
}


else if(found_text&&limit>cur_buffer)*limit++= 073;
/* Line ended. */
break;
}
}
}

;

return YES;
}


boolean skip_Rtext(VOID)
{
static ASCII blank= 040;



if(scanning_C_cmnt)return YES;/* Make sure |skp_cmnt| is the first to be \
					executed. */

/* Start scanning at the current position. Skip over white space. */
for(;lp<limit;++lp)
if(!(*lp==040||*lp==tab_mark))break;

if(lp>=limit)return NO;/* The line was all white space. */

;

last_pos= &blank;

/* If we haven't found a comment, set mode to text. */
if(!start_Rcomment)
{
found_text= text= YES;
}

/* Scan to a comment. */
for(;lp<limit;lp++)
{
if(start_Rcomment)
{
if(R_style_cmnt)
{
*lp= cmnt_char= begin_comment0;
*limit++= 052;*limit++= 057;
}
if(++lp<limit)return YES;
}

if(*lp!=040&&*lp!=tab_mark)
last_pos= lp;/* Remember last non-blank position. */
}

return NO;
}


boolean skp_cmnt(VOID)
{
/* If the last mode was text, remember the position for a possible semi. */
if(text)semi_pos= lp-1;

text= NO;/* We're in comment mode. */
scanning_C_cmnt= NO;/* Flag used to handle the next line properly if the \
				comment runs over. */

/* Scan to end of comment. */
if(C_style_cmnt)
{
if(short_cmnt)
{
lp= limit;
return YES;
}

for(++lp;lp<limit;lp++)
{
if(*lp==(ASCII)begin_comment0||*lp==(ASCII)begin_comment1)
{
*lp= 0143;
continue;
}

if(*lp==052&&*(lp+1)==057)
{
lp+= 2;/* Position after end of comment. */
if(lp<=limit)return YES;
}
}

scanning_C_cmnt= YES;
}
else
{
for(++lp;lp<limit;lp++)
if(*lp==(ASCII)begin_comment1)
*lp= 041;

*(limit-2)= 052;*(limit-1)= 057;
}

return NO;
}



SRTN
prime_the_change_buffer(VOID)
{
INPUT_PARAMS input_params;/* Saves incoming state. */

input_params.Language= language;
input_params.Parsing_mode= parsing_mode;
input_params.Column_mode= column_mode;

language= change_params.Language;
parsing_mode= change_params.Parsing_mode;
column_mode= change_params.Column_mode;

change_limit= NULL;/* This value will be used if the change file ends. */



WHILE()
{
ASCII c;

if(!input_ln(CHANGE_FILE))
{
change_limit= NULL;
goto done_priming;
}

if(limit<cur_buffer+2)continue;
/* There can't be an \.{@}~command. */
if(cur_buffer[0]!=0100)continue;
/* Skip lines that don't start with~\.{@}. */


if((cur_buffer[1]>=0130&&cur_buffer[1]<=0132)||cur_buffer[1]==0111)
cur_buffer[1]+= 0172-0132;

;


if(cur_buffer[1]==0151)
{
loc= cur_buffer+2;

err0_print(ERR_C,OC("Sorry, no includes allowed in change file"),0);

}

;
if((c= cur_buffer[1])==0170)break;/* Found beginning of a change. */

if(c==0171||c==0172)
{
loc= cur_buffer+2;/* Skip erroneous change. */

err0_print(ERR_C,OC("Where is the matching @x?"),0);

}
else
{
if(c==0154)
if(limit==cur_buffer+2)

err0_print(ERR_C,OC("Missing language character after @L"),0);
else c= cur_buffer[2];

switch(c)
{

case 0143:case 0103

:
language= change_params.Language= 
(cur_buffer[2]==053)?C_PLUS_PLUS:C;
column_mode= change_params.Column_mode= NO;
continue;


case 0162:case 0122

:
if(!RAT_OK("Language change ignored"))continue;

language= change_params.Language= 
(cur_buffer[2]==071)?RATFOR_90:RATFOR;
continue;


case 0156:case 0116

:
language= change_params.Language= 
(cur_buffer[2]==071)?FORTRAN_90:FORTRAN;
continue;


case 0166:case 0126



:
language= change_params.Language= LITERAL;continue;


case 0170:case 0130

:
language= change_params.Language= TEX;continue;

case 0133:
column_mode= change_params.Column_mode= YES;continue;

case 0135:
column_mode= change_params.Column_mode= NO;continue;

default:
loc= cur_buffer+2;

err0_print(ERR_C,OC("Invalid @ command in change file"),0);
continue;
}
}


}

;


do
{
if(!input_ln(CHANGE_FILE))
{

err0_print(ERR_C,OC("Change file ended after @x"),0);

change_limit= NULL;
goto done_priming;
}
}
while(limit==cur_buffer);

;

done_priming:
language= input_params.Language;
parsing_mode= input_params.Parsing_mode;
column_mode= input_params.Column_mode;

/* After we're done priming the change buffer, we will next read from the \
input file. */
changing= NO;
cur0_prms= cur_prms.web;
}



SRTN
chk_change(VOID)/* Switches to |change_file| if the buffers match. */
{
int n= 0;/* The number of discrepancies found. */

if(LINES_DONT_MATCH)return;/* Didn't match a change. */

WHILE()
{
changing= YES;prn_where= YES;

if(!input_ln(CHANGE_FILE))
{

err0_print(ERR_C,OC("Change file ended before @y"),0);

change_limit= NULL;changing= NO;prn_where= YES;
return;
}



if(limit>cur_buffer+1&&cur_buffer[0]==0100)
{


if((cur_buffer[1]>=0130&&cur_buffer[1]<=0132)||cur_buffer[1]==0111)
cur_buffer[1]+= 0172-0132;

;


if(cur_buffer[1]==0151)
{
loc= cur_buffer+2;

err0_print(ERR_C,OC("Sorry, no includes allowed in change file"),0);

}

;

if(cur_buffer[1]==0170||cur_buffer[1]==0172)
{
loc= cur_buffer+2;

err0_print(ERR_C,OC("Where is the matching @y?"),0);

}
else if(cur_buffer[1]==0171)
{
if(n>0)
{
loc= cur_buffer+2;

err0_print(ERR_C,OC("Hmm... some of the preceding lines failed to match"),0);

}
return;
}
}

;
changing= NO;prn_where= YES;

while(!input_ln(INPUT_FILE))
{/* Pop the stack or quit. */
if(incl_depth==WEB_FILE)
{

err0_print(ERR_C,OC("WEB file ended during a change"),0);

input_has_ended= YES;return;
}

incl_depth--;prn_where= YES;
}

if(LINES_DONT_MATCH)n++;
}
}


#endif /* Part 1 */

#if(part != 1)


SRTN
rst_input(VOID)
{
FCLOSE(prms[WEB_FILE].web.File);
FCLOSE(prms[WEB_FILE].change.File);

ini_input_prms(WEB_FILE,(outer_char HUGE*)"",ABORT_ON_ERROR);


limit= cur_buffer;loc= cur_buffer+1;cur_buffer[0]= 040

;


{
cur0_prms= cur_prms.change;
changing= YES;
change_params= change_params0;/* Reset to default values. */
prime_the_change_buffer();


limit= cur_buffer;loc= cur_buffer+1;cur_buffer[0]= 040

;
}



incl_depth= WEB_FILE;
input_has_ended= NO;
}



boolean
ini_input_prms FCN((ilevel,path,quit_on_error))
int ilevel C0("Present level of input files.")
outer_char HUGE*path C0("Colon-delimited path list")
boolean quit_on_error C1("Abort flag.")
{
INPUT_PRMS HUGE*p= &prms[ilevel];
CUR_PRMS old_prms;
boolean web_level= BOOLEAN(ilevel==WEB_FILE);

old_prms= cur_prms;/* Save state in case of error. */

/* Initialize this here in case of error messages. */
cur_prms.web= &p->web;
cur_prms.change= &p->change;

/* Initialize both input and change files; abort if error. */
if(!(ini0_input_prms(cur_prms.web,path,OC("input"),quit_on_error,
(SEQUENCES*)(web_level?wt_style.input_ext.web:
wt_style.input_ext.hweb))&&
ini0_input_prms(cur_prms.change,path,OC("change"),quit_on_error,
(SEQUENCES*)(web_level?wt_style.input_ext.change:
wt_style.input_ext.hchange))))
{
cur_prms= old_prms;/* Restore old state if error. */
return NO;
}

/* For definiteness we set |cur0_prms| to the web input file. */
cur0_prms= cur_prms.web;
loc= cur_buffer;

/* Remember the name of the include file, for use by \WEAVE. */
STRCPY(this_include_file,web_level?
(CONST outer_char*)"":p->web.File_name);

return YES;
}



boolean
ini0_input_prms FCN((p0,path,file_type,quit_on_error,extensions))
INPUT_PRMS0 HUGE*p0 C0("")
outer_char HUGE*path C0("")
outer_char file_type[]C0("")
boolean quit_on_error C0("")
SEQUENCES*extensions C1("")
{
cur0_prms= p0;/* In case of error messages. */

/* If we've never opened this level before, allocate appropriate space. */
if(p0->Buffer==NULL)
{
ALLOC(ASCII,p0->Buffer,"bs",buf_size,0);
p0->Buffer_end= p0->Buffer+buf_size-2;
}

/* Initialize location pointers and flags. */
loc= p0->Limit= p0->Buffer;
p0->Line= 0;
p0->Num_in_buffer= 0;
p0->Scanning_C_cmnt= p0->Last_was_empty
= p0->Continuing_line= p0->Last_was_continued= NO;

/* --- Open file (but not if it's already open) --- */
if(!p0->File&&
(p0->File= xopen(p0->File_name,path,extensions,OC("r")))==NULL)
{
if(quit_on_error)
{
char temp[100];

sprintf(temp,"!! Can't open %s%s file ",
*p0->File_name?"":"(null) ",(char*)file_type);
FATAL(C,temp,*p0->File_name?p0->File_name:
wt_style.null_file_name);


}
else
{

err0_print(ERR_C,OC("Can't open include %s file \"%s\""),2,file_type,p0->File_name);
}

return NO;/* Couldn't open file. */
}

return YES;/* Opened file successfully. */
}



FILE*
xopen FCN((file_name,path,extensions,iomode))
outer_char*file_name C0("")
outer_char HUGE*path C0("")
SEQUENCES*extensions C0("")
CONST outer_char*iomode C1("")
{
outer_char HUGE*p1;
FILE*file_ptr;
outer_char total_name[2*MAX_FILE_NAME_LENGTH];
outer_char prefix_end_str[2];

if(!*file_name)
return FOPEN(wt_style.null_file_name,iomode);

if(*iomode=='r'&&STRCMP(file_name,"stdin")==0)
return stdin;
else if(*iomode=='w'&&STRCMP(file_name,"stdout")==0)
return stdout;

/* If there's no path, we just try to look in the present directory. */
if(!(path&&*path))
return x0open(file_name,extensions,iomode);

prefix_end_str[0]= prefix_end_char;
prefix_end_str[1]= '\0';

/* Hunt through the path. */
while((p1= (outer_char HUGE*)STRCHR(path,':'))!=NULL)
{
*p1= '\0';
STRCPY(total_name,path);
*p1= ':';
if(*(p1-1)!=prefix_end_char)
STRCAT(total_name,prefix_end_str);
STRCAT(total_name,file_name);
if((file_ptr= x0open(total_name,extensions,iomode))!=NULL)
return file_ptr;
path= p1+1;
}

return NULL;/* Couldn't open any file. */
}



FILE*
x0open FCN((file_name,extensions,iomode))
outer_char*file_name C0("")
SEQUENCES*extensions C0("")
CONST outer_char*iomode C1("")
{
int k;

/* If it has a dot in it, it's always interpreted literally.  If it didn't \
have a dot, then if the `\.{-e}'~option isn't in effect it will already \
have had the `\.{.web}' extension added to it, so it will now have a dot. \
(So presumably the last option of the \&{if} is redundant?) */
if(STRCHR(file_name,wt_style.ext_delimiter)!=NULL||!try_extensions)
return FOPEN(file_name,iomode);

/* At this point, the file name didn't have a dot and the `\.{-e}'~option \
is in effect.  Make trial file names from the list of extensions and try to \
open them one at a time until one matches. */
for(k= 0;k<extensions->n;k++)
{
outer_char full_name[MAX_FILE_NAME_LENGTH];
FILE*file_ptr;

if(
nsprintf(full_name,OC("%s%c%s"),3,file_name,wt_style.ext_delimiter,extensions->string[k])>=
MAX_FILE_NAME_LENGTH)OVERFLW("Extended file name","");

file_ptr= FOPEN(full_name,iomode);

if(file_ptr)
{
STRCPY(file_name,full_name);/* If we don't do this, the \
information messages aren't as informative as they could be. */
return file_ptr;/* Opened a file successfully. */
}
}

return NULL;/* Failed to open the file. */
}



boolean
get_line(VOID)
{
if(return_toggle)

{
return_toggle= NO;
if(popped&&no_more_input){input_has_ended= YES;return NO;}
STRNCPY(cur_buffer,stored_line,stored_line_length);
FREE_MEM(stored_line,"stored_line",stored_line_length,ASCII);
limit= cur_buffer+stored_line_length;
*limit= 040;
if(popped)
{
popped= NO;
goto popped_stack;
}
else if(toggling){goto push_stack;}
else goto process_line;
}



restart:
if(changing)
chngd_module[module_count]= YES;
else

{
popped= NO;

if(cur_prms.web->Line==0)
if(ignored_cmnts())goto fin_read;
else goto pop_or_quit;

while(!input_ln(INPUT_FILE))
{/* pop the stack or quit */
pop_or_quit:
prn_where= YES;

if(incl_depth==WEB_FILE){input_has_ended= YES;break;}
else
{/* Tidy up the include level we're about to leave. */
if(cur_prms.web->File!=prms[incl_depth-1].web.File)
{FCLOSE(cur_prms.web->File);}

if(cur_prms.change->File!=prms[incl_depth-1].change.File)
{FCLOSE(cur_prms.change->File);}
else prms[incl_depth-1].change= *cur_prms.change;

cur0_prms->File= NULL;
CLR_PRINTF(include_file,(")"));/* Tell the terminal we're \
finished with this web input file. */

/* Pop the stack here. */
incl_depth--;
cur_prms.web= &prms[incl_depth].web;
cur_prms.change= &prms[incl_depth].change;

if(incl_depth==WEB_FILE&&toggle_includes&&toggling)
{
toggling= NO;
return_toggle= YES;
}

STRCPY(this_include_file,(incl_depth==WEB_FILE)?
(CONST outer_char*)"":cur_file_name);

}
}

fin_read:
if(return_toggle)
{
no_more_input= input_has_ended;
input_has_ended= NO;
popped= YES;

{
return_toggle= YES;
stored_line_length= PTR_DIFF(size_t,limit,cur_buffer);
stored_line= GET_MEM("stored_line",stored_line_length+1,ASCII);/* We \
	allocate one extra so we don't have to handle the special case of a \
	zero-length line, for which |FREE_MEM| would complain. */
STRNCPY(stored_line,cur_buffer,stored_line_length);
loc= limit= cur_buffer;
*limit++= 0100;*limit++= '\001';*limit= 040;
return YES;
}


}

popped_stack:
if(!input_has_ended)
if(limit==change_limit-change_buffer+cur_buffer)
if(cur_buffer[0]==change_buffer[0])
if(change_limit>change_buffer)chk_change();
}

;

if(changing)
{

{
if(!input_ln(CHANGE_FILE))
{

err0_print(ERR_C,OC("Change file ended without @z"),0);

cur_buffer[0]= 0100;cur_buffer[1]= 0172;limit= cur_buffer+2;
}

if(limit>cur_buffer+1)/* check if the change has ended */
if(cur_buffer[0]==0100)
{


if((cur_buffer[1]>=0130&&cur_buffer[1]<=0132)||cur_buffer[1]==0111)
cur_buffer[1]+= 0172-0132;

;


if(cur_buffer[1]==0151)
{
loc= cur_buffer+2;

err0_print(ERR_C,OC("Sorry, no includes allowed in change file"),0);

}

;

if(cur_buffer[1]==0170||cur_buffer[1]==0171)
{
loc= cur_buffer+2;
err0_print(ERR_C,OC("Where is the matching @z?"),0);

}
else if(cur_buffer[1]==0172)
{
prime_the_change_buffer();prn_where= YES;
}
}
}

;

if(!changing)
{
chngd_module[module_count]= YES;goto restart;
}
}

process_line:
loc= cur_buffer;*limit= 040;

if(return_toggle)

{
return_toggle= YES;
stored_line_length= PTR_DIFF(size_t,limit,cur_buffer);
stored_line= GET_MEM("stored_line",stored_line_length+1,ASCII);/* We \
	allocate one extra so we don't have to handle the special case of a \
	zero-length line, for which |FREE_MEM| would complain. */
STRNCPY(stored_line,cur_buffer,stored_line_length);
loc= limit= cur_buffer;
*limit++= 0100;*limit++= '\001';*limit= 040;
return YES;
}



if(*cur_buffer==0100)
switch(*(cur_buffer+1))
{
case 0151:
case 0111:


if(*(cur_buffer+1)==0111&&(skip_includes||
(program==weave&&toggle_includes&&CUR_FILE==WEB_FILE)))
{
if(skip_includes)
{
loc= limit+1;/* Turn whole line into null. */
goto restart;
}
else if(toggle_includes&&CUR_FILE==WEB_FILE)
{
toggling= YES;

{
return_toggle= YES;
stored_line_length= PTR_DIFF(size_t,limit,cur_buffer);
stored_line= GET_MEM("stored_line",stored_line_length+1,ASCII);/* We \
	allocate one extra so we don't have to handle the special case of a \
	zero-length line, for which |FREE_MEM| would complain. */
STRNCPY(stored_line,cur_buffer,stored_line_length);
loc= limit= cur_buffer;
*limit++= 0100;*limit++= '\001';*limit= 040;
return YES;
}


}
}
else
{
boolean found_include;


push_stack:
loc= cur_buffer+2;/* Position after \.{@i}. */

if(++incl_depth>=(int)max_include_depth)
{
incl_depth--;

err0_print(ERR_C,OC("Too many nested includes; %d allowed.  \
Increase with `-yid'."),1,max_include_depth);

goto restart;
}

/* Look for the name of a \WEB\ file to include. */
if(!(found_include= get_fname(cur_file_name)))

err0_print(ERR_C,OC("Include file name not given"),0);

else
{/* Found a \WEB\ file name; now look for change file name. */
if(skip_ifiles)

{
int j;

for(j= 0;j<num_ifiles;j++)
if(STRCMP(ifiles[j],cur_file_name)==0)
{
incl_depth--;
goto restart;
}

if(num_ifiles==(int)max_ifiles)
OVERFLW("unique include file names","if");

if(phase==1)
{
ifiles[num_ifiles]= GET_MEM("ifile",STRLEN(cur_file_name)+1,outer_char);
STRCPY(ifiles[num_ifiles],cur_file_name);
}

num_ifiles++;
}



if(!get_fname(change_file_name))
{/* No change file name specified; obtain it from the \
last level. */
INPUT_PRMS*p_lower= &prms[incl_depth-1];
INPUT_PRMS0*p0_lower= &p_lower->change;

STRCPY(change_file_name,p0_lower->File_name);
change_file= p0_lower->File;
change_params= p_lower->input_params;
}
}

if(found_include)
{
if(ini_input_prms(CUR_FILE,incl.list,DONT_ABORT_ON_ERROR))
{
if(cur_prms.change->File!=prms[incl_depth-1].change.File)

{
cur0_prms= cur_prms.change;
changing= YES;
change_params= change_params0;/* Reset to default values. */
prime_the_change_buffer();


limit= cur_buffer;loc= cur_buffer+1;cur_buffer[0]= 040

;
}

/* New change file. */
else*cur_prms.change= prms[incl_depth-1].change;
/* Still using the old change file. */

cur_line= 0;
prn_where= YES;
CLR_PRINTF(include_file,(" (%s",(char*)cur_file_name));
/* Tell the terminal where we're reading from. */
}
else
{/* Failed to open include file. */
incl_depth--;
}
}

goto restart;
}




break;
}

return(boolean)(!input_has_ended);
}



boolean
get_fname FCN((file_name))
outer_char HUGE*file_name C1("")
{
ASCII HUGE*j;
outer_char HUGE*k;

skip_white:

/* Skip over leading white space and optional quotes. */
while(loc<=limit&&(*loc==040||*loc==011||*loc==042))loc++;

/* If we've hit the end of the buffer, we're done, and we didn't find \
anything. */
if(loc>=limit)return NO;


{
if(*loc==057)
{
if(*(loc+1)==057)
{/* Short comment */
loc= limit+1;
return NO;
}

if(*(loc+1)==052)
{/* Long comment */
for(loc+= 2;loc<=limit;loc++)
if(*loc==052&&*(loc+1)==057)
{
loc+= 2;
goto skip_white;
}


err0_print(ERR_C,OC("Can't continue comments on @i lines"),0);
}
}
}



k= file_name;j= loc;

/* Terminate scan by white space or quotes. */
while(*loc!=040&&*loc!=011&&*loc!=042)*k++= XCHR(*loc++);
TERMINATE(k,0);

/* On certain systems, underscores aren't allowed in file names. */

add_prefix(file_name);/* Attach a directory prefix. */

return YES;
}



SRTN
add_prefix FCN((file_name))
outer_char HUGE*file_name C1("")
{
outer_char temp[MAX_FILE_NAME_LENGTH];

xpnd_file_name(file_name);/* Expand possible environmental prefix. */

if(*wbprefix&&STRRCHR(file_name,prefix_end_char)==NULL)
{
if(
nsprintf(temp,OC("%s%s"),2,wbprefix,file_name)>=
MAX_FILE_NAME_LENGTH)OVERFLW("Path/file_name","");

STRCPY(file_name,temp);
}
}



SRTN
xpnd_file_name FCN((name))
outer_char HUGE*name C1("")
{
outer_char temp[MAX_FILE_NAME_LENGTH],env_prefix[MAX_FILE_NAME_LENGTH];
outer_char*pc,*px,*qx;
CONST char*separator;
int n;
boolean expanded;

#ifdef vms
return;/* VAX/VMS does its own expansions of logical names. */
#else

#if !HAVE_GETENV

err0_print(ERR_C,OC("Sorry, this machine doesn't support environment variables"),0);
return;
#else

/* Is there a logical name prefix? */
if((pc= OC(STRCHR(name,':')))==NULL)return;

/* Isolate the prefix. */
STRNCPY(env_prefix,name,n= PTR_DIFF(int,pc,name));
TERMINATE(env_prefix,n);

/* Recursively expand the prefix. |px|~will have the last non-null name. */
expanded= NO;
for(px= env_prefix;px;px= qx)
{
if((qx= GETENV(px))==NULL)break;
if(STRCMP(qx,env_prefix)==0)
{

err0_print(ERR_C,OC("Infinite recursion in definition of \
environmental variable \"%s\""),1,px= env_prefix);
expanded= NO;
break;
}
expanded= YES;/* At least one expansion of the logical name was \
made. */
}

/* If the prefix wasn't expandable, or if it turned into an infinite \
recursion, do nothing. */
if(!expanded)return;

/* Otherwise, |px|~has the last expansion of the name. */
separator= 
#ifdef ibmpc
"\\"
#else
"/"
#endif /* |ibmpc| */
;
if(
nsprintf(temp,OC("%s%s%s"),3,px,separator,pc+1)>=
MAX_FILE_NAME_LENGTH)
OVERFLW("Expandable file name","");
STRCPY(name,temp);

#endif /* |HAVE_GETENV| */
#endif /* |vms| */
}



boolean
ignored_cmnts(VOID)
{
boolean limbo_material;

/* Read the first line of file. */
if(!input_ln(INPUT_FILE))return NO;

/* Check for possible limbo material. 	If so, skip all lines up to \
an~`\.{@x}'. */
limbo_material= BOOLEAN(cur_buffer[0]==0100&&cur_buffer[1]==0172);
if(limbo_material)
do
{
if(!input_ln(INPUT_FILE))
{
CLR_PRINTF(warning,("\n! File ended during \
skip_limbo.  Limbo material that begins with @z must be terminated by \
@x."));
return NO;
}
}
while(!(cur_buffer[0]==0100&&cur_buffer[1]==0170));

/* If there was limbo material, at this point the line beginning \
with~`\.{@x}' is in the buffer.  The next operation is to read another \
line, which starts the proper part of the include file.  If there was no \
limbo material, the first line of the file is already in the buffer. Thus, \
after the following operation we'll always have the first proper line of \
the file in the buffer. */
if(limbo_material&&!input_ln(INPUT_FILE))return NO;

return YES;/* Successfully skipped comments. */
}



SRTN
chk_complete(VOID)
{
if(change_limit!=NULL)
{/* |changing| is |NO| */
STRNCPY(cur_buffer,change_buffer,
PTR_DIFF(size_t,change_limit,change_buffer)+1);
loc= limit= PTR_DIFF(size_t,change_limit,change_buffer)+cur_buffer;
changing= YES;

err0_print(ERR_C,OC("Change file entry did not match"),0);

}
}



void HUGE*
get_mem0 FCN((why,nunits,nsize))
CONST outer_char why[]C0("Reason for request")
BUF_SIZE nunits C0("Number of units to allocate.")
size_t nsize C1("Size of each unit.")
{
void HUGE*p;/* With certain compilers such as the |SGI|, |void| is \
		translated into |char|; see \.{proto.hweb}. */
BUF_SIZE nbytes;

if(nunits==0)return NULL;/* Should this ever happen? */
if(nsize==0)CONFUSION("get_mem0","Nsize = 0 requested");

#if !NON_ANSI_CALLOC
/* For ANSI, the prototype for |calloc| is |void *calloc(size_t,size_t)|. */
if(nunits>MAX_SIZE_T)
{

err0_print(ERR_C,OC("get_mem0: Can't request %lu units; used max of %lu"),2,nunits,MAX_SIZE_T);
nunits= MAX_SIZE_T;
}
#endif /* |ANSI_CALLOC| */

if((p= (void HUGE*)CALLOC(nunits,nsize))==NULL)
{
char temp[250];

sprintf(temp,"\n!!! NO MORE MEMORY (\"%s\")!!! \
[Requesting %lu unit(s) of size %lu byte(s); allocated %lu bytes so far.]  \
Try using the -y option to reduce the sizes of internal tables.",
(char*)why,nunits,(BUF_SIZE)nsize,total_mem);
FREE(byte_mem);/* Kludge to try to make it go out gracefully. */
FATAL(C,temp,"");
}

/* Keep track of total allocation. */
nbytes= nunits*nsize;
total_mem+= nbytes;
max_mem= MAX(max_mem,total_mem);

#ifdef mac
lmemset(p,0,nbytes);/* For |lmalloc|, must zero explicitly. */
#endif

if(show_mem&&nbytes>=show_size)
show_alloc('+',why,nunits,(BUF_SIZE)nsize,nbytes,p,total_mem);

return p;/* The allocated memory area. */
}



SRTN
show_alloc FCN((c,why,nunits,nsize,nbytes,p,total_mem))
outer_char c C0("Either plus or minus")
CONST outer_char why[]C0("Reason for request")
BUF_SIZE nunits C0("Number of units")
BUF_SIZE nsize C0("Size of each unit.")
BUF_SIZE nbytes C0("Bytes allocated")
void HUGE*p C0("Start of allocated area")
BUF_SIZE total_mem C1("Total bytes currently allocated")
{
printf("\"%s\": %c(%lu x %lu) = %c%lu ",
(char*)why,c,nunits,nsize,c,nbytes);
ptr_range(p,nbytes);
printf("(%lu total)\n",total_mem);
}



SRTN
ptr_range FCN((p,nbytes))
void HUGE*p C0("Start of the allocated space.")
BUF_SIZE nbytes C1("Length of the allocation")
{
static char ptr_string[]= 
#ifdef ibmpc
PTR_BASE
#else
""
#endif
;

printf(ptr_string,p,(char HUGE*)p+nbytes);
}



SRTN
free_mem0 FCN((p,why,nunits,nsize))
void HUGE*p C0("Pointer to deallocate")
CONST outer_char why[]C0("Reason for request")
BUF_SIZE nunits C0("Number of units to deallocate.")
size_t nsize C1("Size of each unit.")
{
BUF_SIZE nbytes;

/* If things are working correctly, |p|~should have been previously \
allocated. */
if(p==NULL)CONFUSION("free_mem0","Attempting to deallocate NULL pointer");

/* Keep track of total allocation. */
nbytes= nunits*nsize;
total_mem-= nbytes;

if(show_mem&&nbytes>=show_size)
show_alloc('-',why,nunits,(BUF_SIZE)nsize,nbytes,p,total_mem);

FREE(p);
}



MEM HUGE*
msearch FCN((abbrev,nunits))
CONST outer_char abbrev[]C0("Abbreviation for desired object.")
BUF_SIZE nunits C1("Value.")
{
MEM HUGE*m;

for(m= mem;*m->abbrev;m++)
if(STRCMP(m->abbrev,abbrev)==0)
{
if(nunits==0L)return m;/* Special case: just find it. */

if(nunits<m->min)
{
CLR_PRINTF(warning,
("! Warning (msearch:%s): nunits (%lu) < min (%lu); min used.\n",
(char*)abbrev,nunits,m->min));
mark_harmless;
nunits= m->min;
}
else if(nunits>m->max)
{
CLR_PRINTF(warning,
("! Warning (msearch:%s): nunits (%lu) > max (%lu); max used\n",
(char*)abbrev,nunits,m->max));
mark_harmless;
nunits= m->max;
}

m->nunits= nunits;/* Override the default value. */
return m;
}

CLR_PRINTF(warning,
("! Invalid alloc abbreviation \"%s[%lu]\"\n",(char*)abbrev,nunits));
mark_harmless;
return m;
}



void HUGE*
alloc FCN((abbrev,pnunits,nsize,dn))
CONST outer_char abbrev[]C0("Abbreviation for desired object.")
BUF_SIZE HUGE*pnunits C0("Pointer to returned \# of units.")
size_t nsize C0("Size of object.")
int dn C1("Incremental number of units to allocate.")
{
MEM HUGE*m= find_abbrev(abbrev);

*pnunits= m->nunits;

/* |dn| is used as a flag; if it's negative, we just obtain the number of \
units. */
if(dn<0)
return NULL;
else
return get_mem0(abbrev,(*pnunits)+dn,nsize);
}


MEM HUGE*find_abbrev FCN((abbrev))
CONST outer_char abbrev[]C1("")
{
MEM HUGE*m;
outer_char temp[100];

for(m= mem;*m->abbrev;m++)
if(STRCMP(m->abbrev,abbrev)==0)return m;


if(
nsprintf(temp,OC("Bad alloc abbreviation \"%s\""),1,abbrev)>=(int)(100))OVERFLW("temp","");
CONFUSION("find_abbrev",temp);
return NULL;
}


#ifdef mcc

void HUGE*
hrealloc FCN((old_ptr,new_size,old_size))
void HUGE*old_ptr C0("Old buf previously allocated with |halloc|.")
BUF_SIZE new_size C0("New size in bytes.")
BUF_SIZE old_size C1("Old size in bytes.")
{
void HUGE*new_ptr;
BUF_SIZE num_to_copy;
size_t ncopied;

new_ptr= GET_MEM("hrealloc",new_size,char);

if(new_ptr==NULL)
return NULL;

num_to_copy= MIN(old_size,new_size);
ncopied= (size_t)num_to_copy;

if((BUF_SIZE)ncopied!=num_to_copy)
CONFUSION("hrealloc","trying to copy more than size_t");

memcpy(new_ptr,old_ptr,ncopied);

FREE_MEM(old_ptr,"old_ptr",old_size,char);

return new_ptr;
}

#endif /* |mcc| */



unsigned
prn_id FCN((np))
name_pointer np C1("")
{
ASCII_write(*np->byte_start==BP_MARKER?
((BP*)np->byte_start)->Root->id:np->byte_start,Length(np));

return PTR_DIFF(unsigned,np,name_dir);
}

int
Length FCN((np))
name_pointer np C1("")
{
int n;
BP HUGE*bp;
TRUNC HUGE*s;
CONST ASCII HUGE*p0;
CONST ASCII HUGE*p1;

p0= np->byte_start;
bp= (BP*)p0;

if(*(char*)bp==BP_MARKER)
{
s= bp->Root;
n= PTR_DIFF(int,s->id_end,s->id);
}
else
{
p1= (np+1)->byte_start;
PROPER_END(p1);
n= PTR_DIFF(int,p1,p0);
}

return n;
}



name_pointer
id_lookup FCN((first,last,t))
CONST ASCII HUGE*first C0("First character of string.")
CONST ASCII HUGE*last C0("last character of string plus one.")
eight_bits t C1("The |ilk|; used by \.{WEAVE} only.")
{
CONST ASCII HUGE*i= first;/* position in |cur_buffer| */
int h;/* hash code */
int l;/* length of the given identifier */
name_pointer p;/* where the identifier is being sought */
WORD_TYPE word_type0= ORDINARY_ID;

if(last==NULL)
{
word_type0= word_type;

for(last= first;*last!='\0';last++)
;/* Find end of identifier. */
}

l= PTR_DIFF(int,last,first);/* compute the length */


h= *i;

while(++i<last)h= (h+h+*i)%hash_size;

;

p= hash[h];

while(p&&!names_match(p,first,l,t))p= p->link;

if(p==NULL)
{
p= name_ptr;/* the current identifier is new */
p->link= hash[h];hash[h]= p;/* insert |p| at beginning of hash \
						list */
}

;

if(p==name_ptr)

{
if(byte_ptr+l>byte_end)OVERFLW("bytes","b");
if(name_ptr>=name_end)OVERFLW("names","n");

STRNCPY(byte_ptr,first,l);
(++name_ptr)->byte_start= byte_ptr+= l;

if(program==weave)
ini_p(p,t);
}

;

if(!(p->Language&(boolean)language))
p->ilk= t;

p->Language|= (boolean)language;/* Record language usage. */

switch(word_type0)
{
case RESERVED_WD:
p->reserved_word|= (boolean)language;
break;

case INTRINSIC_FCN:
p->intrinsic_word|= (boolean)language;
break;

case KEYWD:
p->keyword|= (boolean)language;
break;

default:;/* Avoids warning about unused |enum|. */
}

return p;
}



sixteen_bits
find_n FCN((n))
sixteen_bits n C1("")
{
name_pointer np;
CONST ASCII HUGE*end;
outer_char HUGE*s;
size_t len;

np= name_dir+n;

if(np>=name_ptr)
{
printf("!! n = %u exceeds nmax = %u.\n",n,
PTR_DIFF(unsigned,name_ptr,name_dir)-1);
return 0;
}

PROPER_END(end);

len= PTR_DIFF(size_t,end,np->byte_start);/* Length of the $n$th identifier. */
s= GET_MEM("find_n",len+1,outer_char);/* Allocate temporary area. */

STRNCPY(s,np->byte_start,len);
TERMINATE(s,len);

/* Convert from |ASCII| to the outer world; print info about id. */
to_outer((ASCII HUGE*)s);
id_info(np,(long)n,(CONST outer_char*)s,NULL);
FREE_MEM(s,"find_n",len+1,outer_char);

return n;
}

sixteen_bits
find_s FCN((s))
CONST outer_char*s C1("")
{
int h,l;
name_pointer p;
ASCII HUGE*a;
CONST ASCII HUGE*first,HUGE*last;
CONST ASCII HUGE*i;
sixteen_bits n= 0;

l= STRLEN(s);
a= GET_MEM("find_s",l+1,ASCII);
STRCPY(a,s);
i= first= to_ASCII((outer_char*)a);
last= first+l;



h= *i;

while(++i<last)h= (h+h+*i)%hash_size;


p= hash[h];
while(p&&!(STRNCMP(first,p->byte_start,l)==0))p= p->link;

if(p==NULL)
{CLR_PRINTF(warning,("%cId \"%s\" is not in name_dir!\n",
beep(1),(char*)s));}
else
id_info(p,(long)(n= (sixteen_bits)(p-name_dir)),s,NULL);

FREE_MEM(a,"find_s",l+1,ASCII);

return n;
}




sixteen_bits
find_id FCN((a0,a1))
eight_bits a0 C0("")
eight_bits a1 C1("")
{
return find_n(IDENTIFIER(a0,a1));
}



SRTN
id_info FCN((np,n,s,prsrvd))
name_pointer np C0("")
long n C0("")
CONST outer_char*s C0("")
CONST RSRVD HUGE*prsrvd C1("")
{
if(n>=0)
printf(_Xx("Id %ld (0x%lx):"),n,n);

if(!prsrvd
||(prsrvd->reserveds&&np->reserved_word)
||(prsrvd->intrinsics&&np->intrinsic_word)
||(prsrvd->keywords&&np->keyword))
printf(" \"%s\"\n",(char*)s);

if(!prsrvd)
pr_lan("Language ",np->Language);

if(!prsrvd||prsrvd->reserveds)
pr_lan("reserved ",np->reserved_word);

if(!prsrvd||prsrvd->intrinsics)
pr_lan("intrinsic",np->intrinsic_word);

if(!prsrvd||prsrvd->keywords)
pr_lan("keyword  ",np->keyword);
}


SRTN
pr_lan FCN((name,b))
CONST char*name C0("")
boolean b C1("")
{
unsigned k;
boolean first= YES;

if(b==0)return;

printf("   %s = { ",name);

for(k= 1;k<=256;k<<= 1)
if(k&b)
{
printf("%s%s",first?"":", ",
languages[lan_num((LANGUAGE)k)]);
first= NO;
}

if(first)printf("(none)");
printf(_Xx(" } (0x%x)\n"),b);
}



BUF_SIZE
prn_nd(VOID)
{
BUF_SIZE k,n= name_ptr-name_dir;

for(k= 0;k<n;k++)
{
printf("[%lu]:  ",k);
prn_id(name_dir+k);
putchar('\n');
}

return n;
}



name_pointer
mod_lookup FCN((k,l))
CONST ASCII HUGE*k C0("First character of name.")
CONST ASCII HUGE*l C1("Last character of name.")
{
LEXI c= GREATER;/* comparison between two names */
name_pointer p= root;/* current node of the search tree */
name_pointer q= name_dir;/* father of node |p| */

while(p)
{
c= web_strcmp(k,l+1,p->byte_start,(p+1)->byte_start);
q= p;

switch(c)
{
case LESS:p= p->llink;continue;
case GREATER:p= p->rlink;continue;
case EQUAL:return p;
default:
err0_print(ERR_C,OC("Incompatible section names"),0);
return NULL;

}
}

return install_node(q,c,k,PTR_DIFF(int,l,k)+1);
}



LEXI
web_strcmp FCN((j,j1,k,k1))/* fuller comparison than |strcmp| */
CONST ASCII HUGE*j C0("Beginning of first string.")
CONST ASCII HUGE*j1 C0("End of first string plus one.")
CONST ASCII HUGE*k C0("Beginning of second string.")
CONST ASCII HUGE*k1 C1("End of second string plus one.")
{
while(k<k1&&j<j1&&*j==*k)k++,j++;

if(k==k1)if(j==j1)return EQUAL;
else return EXTENSION;
else if(j==j1)return PREFIX;
else if(*j<*k)return LESS;
else return GREATER;
}



name_pointer
install_node FCN((parent,c,j,name_len))/* install a new node in the tree */
name_pointer parent C0("Parent of new node.")
int c C0("Right or left?")
CONST ASCII HUGE*j C0("Where replacement text starts.")
int name_len C1("length of replacement text.")
{
name_pointer node= name_ptr;/* new node */
if(byte_ptr+name_len>byte_end)OVERFLW("bytes","b");
if(name_ptr==name_end)OVERFLW("names","n");

if(c==LESS)parent->llink= node;else parent->rlink= node;

node->llink= node->rlink= NULL;
ini_node(node);
STRNCPY(byte_ptr,j,name_len);
(++name_ptr)->byte_start= byte_ptr+= name_len;
return node;
}



name_pointer
prefix_lookup FCN((k,l))/* finds module name given a prefix */
CONST ASCII HUGE*k C0("First char of prefix.")
CONST ASCII HUGE*l C1("Last char of prefix.")
{
LEXI c= GREATER;/* comparison between two names */
short count= 0;/* the number of hits */
name_pointer p= root;/* current node of the search tree */
name_pointer q= NULL;
/* another place to resume the search after one is done */
name_pointer r= NULL;/* extension found */
while(p){
c= web_strcmp(k,l+1,p->byte_start,(p+1)->byte_start);

switch(c){
case LESS:p= p->llink;break;
case GREATER:p= p->rlink;break;
default:r= p;count++;q= p->rlink;p= p->llink;
}

if(p==NULL){
p= q;q= NULL;
}
}
if(count==0)
err0_print(ERR_C,OC("Name does not match"),0);

else if(count>1)
err0_print(ERR_C,OC("Ambiguous prefix"),0);


return r;/* the result will be |NULL| if there was no match */
}



unsigned
find_prefix FCN((s))
outer_char s[]C1("")
{
name_pointer r;

to_ASCII(s);
r= prefix_lookup((ASCII HUGE*)s,(ASCII HUGE*)(s+STRLEN(s)));

return r?prn_id(r):0;
}



SRTN
err0_print FCN(VA_ALIST((err_origin,fmt,n VA_ARGS)))
VA_DCL(
ERR_ORIGIN err_origin C0("Where the error came from")
CONST outer_char*fmt C0("Format of error message.")
int n C2("Number of arguments to the string."))
{
VA_LIST(arg_ptr)
ASCII HUGE*k,HUGE*l;/* pointers into |cur_buffer| */
char temp[500];
boolean prn_input_buffer;
#if(NUM_VA_ARGS == 1)
ERR_ORIGIN err_origin;
CONST outer_char*fmt;
int n;
#endif

VA_START(arg_ptr,n);

#if(NUM_VA_ARGS == 1)
err_origin= va_arg(arg_ptr,ERR_ORIGIN);
fmt= va_arg(arg_ptr,outer_char*);
va_arg(arg_ptr,int);
#endif

prn_input_buffer= BOOLEAN(err_origin!=ERR_NULL);

if(prn_input_buffer&&err_origin!=ERR_S)putchar('\n');

set_color(RED);

if(prn_input_buffer)
{
sprintf(temp,"! (%s):  %s",origin_name[err_origin],(char*)fmt);
vprintf(temp,arg_ptr);
}
else
vprintf((char*)fmt,arg_ptr);

va_end(arg_ptr);

if(prn_input_buffer)
if(err_origin==ERR_S)

{
CONST outer_char HUGE*k,HUGE*l;
IN_STYLE boolean from_sprm;

printf(".  (l. %u of %s file ",s_line,"style");
CLR_PRINTF(in_file,("%s)\n",
from_sprm?"parameter buffer":(char*)style_file_name));

l= MIN(sloc,slimit);

for(k= sbuf;k<l;k++)
putchar(*k>127?' ':(*k=='\t'?' ':*k));
/* Print the characters already read. */

putchar('\n');/* Separate already read from not yet read. */

for(k= sbuf;k<l;k++)
putchar(' ');/* Space out the next line. */

for(k= l;k<slimit;k++)
putchar(*k>127?' ':*k);/* Print the part not yet read. */

putchar('\n');
}


else

{
outer_char last_char= fmt[STRLEN(fmt)-1];

if(*fmt&&last_char!='?'&&last_char!='!')
printf(".");/* Sometimes the third argument to |fatal| is empty, \
			so the period isn't necessary. */

if(cur0_prms)
{
if(changing)
{
printf(" (l. %u of %s file ",change_line,"change");
CLR_PRINTF(in_file,("%s)\n",(char*)change_file_name));
}
else if(incl_depth==WEB_FILE)
printf(" (l. %u)\n",cur_line);
else
{
printf(" (l. %u of %s file ",cur_line,"include");
CLR_PRINTF(in_file,("%s)\n",(char*)cur_file_name));
}

l= MIN(loc,limit);

if(l>cur_buffer&&cur_buffer!=NULL)
{
if((BUF_SIZE)(l-cur_buffer)>buf_size)
{
CLR_PRINTF(error,
("! TROUBLE IN ERROR ROUTINE.  PLEASE REPORT THIS!\n"));
mark_error;

l= cur_buffer+MAX_ERR_BUF;
}

for(k= cur_buffer;k<l;k++)
if(*k==011)
putchar(' ');
else
putchar(*k>127?' ':XCHR(*k));
/* print the characters already read */

putchar('\n');/* Separate already read from not yet read. */

for(k= cur_buffer;k<l;k++)putchar(' ');/* Space out the next line. */
}

if(l!=NULL)
{
if((BUF_SIZE)(limit-l)>buf_size)
{
puts("! TROUBLE IN ERROR ROUTINE.  PLEASE REPORT THIS!");
l= limit-MAX_ERR_BUF;
}

for(k= l;k<limit;k++)
putchar(*k>127?' ':XCHR(*k));
/* print the part not yet read */
}
if(limit!=NULL)
if(*limit==0174)putchar('|');/* End of code text in module names. */

putchar(' ');/* To separate the message from future asterisks. */
err_happened= YES;
}
}



fflush(stdout);mark_error;

mfree();/* Free up any |mod_trans| allocations. */
}



int
fatal FCN((err_origin,s1,s2))
ERR_ORIGIN err_origin C0("Where the error came from")
CONST outer_char s1[]C0("Message 1.")
CONST outer_char s2[]C1("Message 2.")
{
printf("\n");
if(err_origin!=ERR_NULL)
{
CLR_PRINTF(fatal,("! (%s):  ",origin_name[err_origin]));
}
CLR_PRINTF(fatal,((char*)s1));err0_print(ERR_NULL,s2,0);
history= fatal_message;

return wrap_up();/* It never really returns, but the compiler doesn't \
			know that. */
}



int
confusion FCN((where,why))
CONST outer_char where[]C0("")
CONST outer_char why[]C1("What went wrong.")
{
outer_char temp[100];


if(
nsprintf(temp,OC("\n    At %s:  %s."),2,where,why)>=(int)(100))OVERFLW("temp","");

beep(3);

return FATAL(NULL,"\n!!! \
I'M CONFUSED; this shouldn't happen.  PLEASE REPORT THIS!!!  ",temp);
}




SRTN
overflow FCN((s,abbrev))
CONST outer_char s[]C0("Condition that caused overflow.")
CONST outer_char abbrev[]C1("Abbreviation for buffer.")
{
char temp[1000];
MEM HUGE*m;

if(*abbrev=='\0')
sprintf(temp,"%s contents too long.",(char*)s);
else
{
m= msearch(abbrev,0L);
sprintf(temp,"Too many %s: current number is %lu, absolute max is \
%lu.  Use command-line option \"-y%s...\" to override default.",
(char*)s,m->nunits,m->max,(char*)abbrev);
}

FATAL(NULL,"!! Sorry, CAPACITY EXCEEDED:  ",temp);
}




SRTN
new_sprm FCN((name,value))
CONST outer_char name[]C0("Name of parameter.")
int value C1("Integer value of parameters.")
{
char temp[100];

sprintf(temp,"Please increase style-file parameter `%s' from current value \
of %i;",name,value);
OVERFLW(temp,"");
}



#if(VMS)
#include stsdef /* Return codes. */
#endif /* |VMS| */

int
wrap_up()
{
putchar('\n');

#if TIMING
prn_time();
#endif /* |TIMING| */


{
CLR_PRINTF(info,("[%s:",program==tangle?"FTANGLE":"FWEAVE"));
printf("  ");

switch(history)
{
case spotless:
CLR_PRINTF(info,("No errors were found."));break;

case harmless_message:
CLR_PRINTF(warning,
("%cDid you see the warning message(s) above?",beep(1)));
break;

case error_message:
CLR_PRINTF(error,
("%cPardon me, but I think I spotted something wrong.",beep(1)));
break;

case fatal_message:
CLR_PRINTF(fatal,("%cThat was a fatal error, my friend.",beep(2)));
break;
}/* There are no other cases. */

CLR_PRINTF(info,("]\n"));
set_color(NORMAL);
}



{
if(cur_prms.web&&cur_prms.web->File)
fclose(cur_prms.web->File);

if(cur_prms.change&&cur_prms.change->File)
fclose(cur_prms.change->File);

cls_files();/* Do stuff specific to \FTANGLE\ or \FWEAVE. */
}



#if(VMS)
switch(history)
{
case spotless:exit(STS$K_SUCCESS|STS$M_INHIB_MSG);
case harmless_message:exit(STS$K_INFO|STS$M_INHIB_MSG);
case error_message:exit(STS$K_ERROR|STS$M_INHIB_MSG);
case fatal_message:exit(STS$K_SEVERE|STS$M_INHIB_MSG);
}
#else
switch(history)
{
case spotless:
case harmless_message:
exit(0);

default:
exit(1);
}
#endif /* |VMS| */

return-1;/* Never really does this. */
}



char
beep FCN((n))
int n C1("")
{
if(beeps)
{
for(--n;n>0;n--)
printf("\007");

return '\007';/* (Some compilers didn't understand \.{'\\a'}.) */
}
else
return '!';
}



SRTN
out_error FCN((fcn))
CONST outer_char fcn[]C1("")
{
FATAL(C,"!! Output error (no more quota?): ",fcn);
}




SRTN
scan_args(VOID)
{
outer_char wbflnm[MAX_FILE_NAME_LENGTH];

/* Build the command line in a buffer. */
cmd_ln_buf= cmd_line(argc,argv);

/* Add the arguments from the ini file \.{.fweb}. This resets |argc| and \
|argv|, and also ignores |argv[0]| from the command line. */
set_args(&argc,&argv);

/* Process all the arguments in order from left to right. */
do_args(YES,argc,argv,&found_web,wbflnm,&found_change);

if(statistics)
mem_avail(0);/* How much memory is available at start? */


{
outer_char HUGE*dot_pos;
outer_char HUGE*p= NULL;

if(STRLEN(wbflnm)>MAX_FILE_NAME_LENGTH-5)
too_long();

if(STRCMP(wbflnm,"stdin")==0)STRCPY(web_file_name,wbflnm);
else
{
p= OC(STRRCHR(wbflnm,prefix_end_char));/* Is there a path? */

if((dot_pos= OC(STRCHR(p?p+1:wbflnm,wt_style.ext_delimiter)))==NULL
&&!try_extensions)
{/* Attach ``\.{.web}'' as a default. */

if(
nsprintf(web_file_name,OC("%s%cweb"),2,wbflnm,wt_style.ext_delimiter)>=(int)(MAX_FILE_NAME_LENGTH))OVERFLW("web_file_name","");
}
else{/* There's a dot, or we're trying extensions; treat the \
name as is. */

if(
nsprintf(web_file_name,OC("%s"),1,wbflnm)>=(int)(MAX_FILE_NAME_LENGTH))OVERFLW("web_file_name","");

if(!try_extensions)
TERMINATE(dot_pos,0);/* string now ends where the \
dot was */
}
}


{
if(p)
{/* Path was specified. */
STRNCPY(wbprefix,wbflnm,
PTR_DIFF(size_t,p,(outer_char HUGE*)wbflnm)+1);/* Path. */
STRCPY(wbflnm0,p+1);/* Root name. */
}
else
{/* No path specification. */
TERMINATE(wbprefix,0);/* No path. */
STRCPY(wbflnm0,wbflnm);/* Root name. */
}
}


}




{
read_sty(style_file_name,renamed_style);/* See \.{style.web}. */


{
DOT_DELIMITER HUGE*d= &wt_style.dot_delimiter;

d->begin= XORD(d->begin);
d->end= XORD(d->end);

if(program==tangle)
{
t_style.ASCII_fcn= x__to_ASCII((outer_char*)t_style.ASCII_fcn);
}
}


}




{
int k;

/* \WEAVE's output file. */
xpn_name(&tex_fname,MAX_FILE_NAME_LENGTH,tex_fname,wbflnm0);
if(*tex_fname=='\0')new_fname(&tex_fname,wbflnm0,OC("tex"));

/* \TANGLE's output files. */
for(k= 0;k<NUM_LANGUAGES;k++)
xpn_name(params.outp_nm+k,MAX_FILE_NAME_LENGTH,
params.outp_nm[k],wbflnm0);

set_name(C,wt_style.output_ext.C_);
set_name(C_PLUS_PLUS,wt_style.output_ext.Cpp_);
set_name(LITERAL,wt_style.output_ext.V_);
set_name(FORTRAN,wt_style.output_ext.N_);
set_name(FORTRAN_90,wt_style.output_ext.N90_);
set_name(RATFOR,wt_style.output_ext.R_);
set_name(RATFOR_90,wt_style.output_ext.R90_);
set_name(TEX,wt_style.output_ext.X_);
}

;

if(!(found_web||info_option))usage("!! Missing webfile name.\n",YES);
if(!found_change)*change_file_name= '\0';/* This means null file. */
}



outer_char HUGE*
cmd_line FCN((num_args,args))
int num_args C0("Number of arguments on command line.")
outer_char*args[]C1("Array of pointers to arguments.")
{
int k,len,l0,l1;
outer_char HUGE*buf,HUGE*b,HUGE*line0,HUGE*line1;
outer_char p[ESCAPE_LENGTH];/* The escaped argument. */

if(program==tangle)
{
line0= TANGLE_LINE0;
line1= TANGLE_LINE1;
}
else
{
line0= WEAVE_LINE0;
line1= WEAVE_LINE1;
}

/* Determine required buffer length. */
for(k= 0,len= 0;k<num_args;len+= STRLEN(args[k++])+1);

l0= STRLEN(line0);
l1= STRLEN(line1);
buf= GET_MEM("buf",2*(len+l0+l1),outer_char);
STRCPY(buf,line0);
b= buf+l0;

while(num_args-->0)
{
int n= esc_file_name(p,ESCAPE_LENGTH,*(args++));

STRNCPY(b,p,n);
b+= n;
*b++= ' ';
}

STRCPY(--b,line1);/* Kill off final blank. */
return buf;
}



SRTN
set_args FCN((pargc,pargv))
int HUGE*pargc C0("Pointer to the arg count; new value returned.")
outer_char HUGE*HUGE**pargv C1("Ptr to the array of ptrs; returned.")
{
int k,n;
outer_char HUGE*buffer,HUGE*b,/* Put one line from ini file into here. */
HUGE*temp,HUGE*t,/* Extract the argument into here. */
HUGE*HUGE*a,/* The current ini arg. */
HUGE*pc;/* Pointer to possible comment character in ini line. */
boolean blank;

/* Allocate temporary buffers. */
buffer= GET_MEM("buffer",T_SIZE,outer_char);
temp= GET_MEM("temp",T_SIZE,outer_char);

/* We start by assuming there is no ini file, hence no argument. */
k= 0;


{
outer_char ini_file_name[MAX_FILE_NAME_LENGTH];
outer_char*p_root,ini_root[MAX_FILE_NAME_LENGTH];

#if HAVE_GETENV /* \.{Machine-dependent}: Understands |getenv|. */
if((p_root= GETENV(ENV_INI))==NULL)STRCPY(ini_root,OC(FWEB_INI));
else STRCPY(ini_root,p_root);

more_includes(GETENV(ENV_INCLUDES));
#else
STRCPY(ini_root,OC(FWEB_INI));
#endif /* |HAVE_GETENV| */

ini_file= FOPEN(mk_fname(ini_file_name,MAX_FILE_NAME_LENGTH,
HOME,YES,ini_root),"r");
}



/* If there is an ini file, then put the arguments into an array. */
if(ini_file)
{
for(a= ini_args;k<MAX_INI_ARGS;)
{
if(FGETS(buffer,T_SIZE,ini_file)==NULL)break;/* Read one line \
		(including newline). */

/* Extract the string, disgarding the newline. If the line is blank, do \
nothing. */
blank= YES;
for(t= temp,b= buffer;*b;)
{
if(*b=='\n')break;
if(!isspace(*b))blank= NO;
*t++= *b++;
}
*t= '\0';

if(blank)continue;

/* Kill off any trailing comment. */
if((pc= OC(STRCHR(temp,INI_CMNT_CHAR)))!=NULL)TERMINATE(pc,0);
if(pc==temp)continue;/* The line was entirely a comment. */

*a= GET_MEM("ini arg",STRLEN(temp)+1,outer_char);/* Space for the \
argument. */
STRCPY(*a++,temp);/* Store ini argument. */
k++;
}

FCLOSE(ini_file);
}

/* Allocate space for all the arguments, both ini and command-line. (We \
don't count |argv[0]| from command line.) */
pn= new_args= GET_MEM("new_args",n= *pargc-1+k,outer_char HUGE*);

acopy(BEFORE_CHAR,ini_args,k);
/* Put those starting with '\.+' or '\.-' first. */
pn0= pn;/* Mark end of the ini stuff. */

acopy(MIDDLE_CHAR,(outer_char HUGE**)(*pargv),*pargc);
/* Then the command-line arguments. */

acopy(AFTER_CHAR,ini_args,k);/* Then the rest. */

/* Return the new number and array of arguments. */
*pargc= n;
*pargv= new_args;

FREE_MEM(buffer,"buffer",T_SIZE,char);
FREE_MEM(temp,"temp",T_SIZE,char);
}



SRTN
more_includes FCN((incl_list0))
outer_char*incl_list0 C1("")
{
unsigned n;
BUF_SIZE old_size;

if(!incl_list0)
return;

/* Strip off useless opening colon. */
while(*incl_list0==':')
incl_list0++;

if((n= STRLEN(incl_list0))==0)
return;

old_size= incl.size;
incl.size+= n+2;/* Allow for trailing colon and null byte. */

if(!incl.list)
{/* List hasn't been allocated yet. */
incl.list= GET_MEM("incl_list",incl.size,outer_char);
STRCPY(incl.list,incl_list0);
}
else
{/* Add more to the list. */
incl.list= (outer_char HUGE*)REALLOC(incl.list,incl.size,old_size);

if(incl.list==NULL)
FATAL(NULL,"!! No more memory (more_includes)","");

STRCAT(incl.list,incl_list0);
}

/* Ensure list ends in a colon. */
if(incl.list[n-1]!=':')incl.list[n]= ':';
}



char*
mk_fname FCN((buffer,buf_len,env_var,print_msg,file_name))
outer_char*buffer C0("Put result here.")
unsigned buf_len C0("Length of |buffer|.")
CONST outer_char*env_var C0("Variable that holds directory name.")
boolean print_msg C0("Flag for not recognizing |env_var|.")
CONST outer_char*file_name C1("The raw file name.")
{
outer_char*directory;/* Will hold result of |getenv|. */

#if HAVE_GETENV /* \.{Machine-dependent}: Understands |getenv|. */
if((directory= GETENV(env_var))==NULL)
{
if(print_msg)
printf("! I can't find environment \
variable \"%s\", so I'll look for file \"%s\" \
in directory \"%s\".\n",
(char*)env_var,(char*)file_name,
*wbprefix?(char*)wbprefix:".");
if(buf_chk(file_name,buf_len,
STRLEN(file_name)+STRLEN(wbprefix)))
return(char*)wt_style.null_file_name;
STRCPY(buffer,wbprefix);
STRCAT(buffer,file_name);
}
else
{/* Got a directory from the environment variable. */
if(buf_chk(file_name,buf_len,
STRLEN(directory)+1+STRLEN(file_name)))
return(char*)wt_style.null_file_name;
/* For Unix, home is of the form \
\.{/u/krommes}; for VMS, it's like \.{ux3:[krommes]}. */
#if !UNIX_PATH

if(
nsprintf(buffer,OC("%s%s"),2,directory,file_name)>=(int)(buf_len))OVERFLW("buffer","");
#else

if(
nsprintf(buffer,OC("%s%c%s"),3,directory,prefix_end_char,file_name)>=(int)(buf_len))OVERFLW("buffer","");
#endif /* |!UNIX_PATH| */
}
#else /* Doesn't understand |getenv|. */
if(buf_chk(file_name,buf_len,STRLEN(file_name)))
return(char*)wt_style.null_file_name;
STRCPY(buffer,file_name);
#endif /* |CAN_GETENV| */

return(char*)buffer;
}



boolean
buf_chk FCN((file_name,buf_len,needed))
CONST outer_char*file_name C0("Raw file name")
unsigned buf_len C0("Max space available")
unsigned needed C1("Requested")
{
if(needed>=buf_len)
{
printf("\n! Buffer too small to make complete file name from \
\"%s\"; opened \"%s\"\n",(char*)file_name,(char*)wt_style.null_file_name);
return YES;
}

return NO;
}



SRTN
acopy FCN((c,a,n))
outer_char c C0("Starting symbol.")
outer_char HUGE**a C0("Old array.")
int n C1("Number of arguments to be looked at.")
{
boolean is_before= BOOLEAN(c==BEFORE_CHAR||c=='+');
boolean is_middle= BOOLEAN(c==MIDDLE_CHAR);
boolean is_after= BOOLEAN(c==AFTER_CHAR);
int k;

/* Disgard the zeroth argument from the command line. */
if(is_middle)
{
k= 1;
a++;
}
else
k= 0;

/* Look at all the arguments; copy them if appropriate. */
for(;k<n;k++,a++)
{
boolean before_entry= BOOLEAN((*a)[0]==BEFORE_CHAR||(*a)[0]=='+');

/* The following somewhat inscrutable logic puts file names and ``after'' \
entries from \.{.fweb} into the ``after'' list. */
if((!is_before&&!before_entry)||(!is_after&&before_entry))
{
*pn= GET_MEM("*pn",STRLEN(*a)+1,outer_char);
STRCPY(*pn,*a);
if((*pn)[0]=='+'||(*pn)[0]==AFTER_CHAR)
(*pn)[0]= BEFORE_CHAR;
pn++;
}
}
}



SRTN
set_name FCN((l,output_ext))
LANGUAGE l C0("")
outer_char*output_ext C1("")
{
int k;

if(*params.outp_nm[k= lan_num(l)]=='\0')
new_fname(params.outp_nm+k,wbflnm0,output_ext);
}



outer_char HUGE*
xpn_name FCN((pout_name,buf_len,in_name,wbflnm0))
outer_char HUGE*HUGE*pout_name C0("The expanded result")
int buf_len C0("Length of above buffer")
CONST outer_char*in_name C0("File name possibly having a \.\#.")
CONST outer_char wbflnm0[]C1("Basic name of the web file.")
{
size_t n;/* Length of the root name. */
outer_char HUGE*t,HUGE*t0= NULL;
boolean buffered= BOOLEAN(*pout_name==in_name);

if(buffered)t= t0= GET_MEM("xpn buffer",buf_len,outer_char);
else t= *pout_name;

for(;*in_name;in_name++)
if(*in_name=='#')
{
n= STRLEN(wbflnm0);
STRNCPY(t,wbflnm0,n);
t+= n;
}
else*t++= *in_name;

TERMINATE(t,0);

if(buffered)
{
new_fname(pout_name,t0,NULL);
FREE_MEM(t0,"xpn buffer",buf_len,outer_char);
}

return*pout_name;
}




SRTN
read_aux(VOID)
{
outer_char aux_file_name[MAX_FILE_NAME_LENGTH];
FILE*fa;
outer_char buffer[AUX_LEN];
int aline= 0;/* Counts line in the \.{.aux} file. */
sixteen_bits modno,modno0;
outer_char smodno[10],smodno0[10],spageno[10],ssecno[100];
int n;
SECT_INFO*ps;/* Points to current info structure. */
int pmcount= 1;/* Number of sections per page. */
long modno_ref= -1;/* Last reference module number.  It's |long| to deal \
	with the possibility of 16-bit integers, where |-1| would be the \
	maximum module number. */

next_mod_name= mod_names= GET_MEM("mod_names",MAX_MOD_NAMES,
outer_char HUGE*);
last_mod_name= mod_names+MAX_MOD_NAMES;

if(TeX_processor!=LaTeX_p)
return;


{
outer_char*dot_pos;/* For finding extension in file name. */

dot_pos= OC(STRCHR(tex_fname,wt_style.ext_delimiter));

if(dot_pos==NULL)
n= STRLEN(tex_fname);
else
n= PTR_DIFF(int,dot_pos,tex_fname);

STRNCPY(aux_file_name,tex_fname,n);

if(
nsprintf(aux_file_name+n,OC("%caux"),1,wt_style.ext_delimiter)>=(int)(MAX_FILE_NAME_LENGTH))OVERFLW("aux_file_name+n","");

fa= FOPEN(aux_file_name,"r");

if(!fa)
{
printf("(No %s file.)\n",(char*)aux_file_name);
return;
}
else
reading(aux_file_name,YES);

}



modno= 0;/* In case there's nothing in the \.{.aux} file. */

while(FGETS(buffer,AUX_LEN,fa))
{
aline++;

if(STRNCMP(buffer,"\\Newlabel",9)!=0)
continue;


{
#if(!ANSI_SSCANF)
{

err0_print(ERR_C,OC("Sorry, non-ANSI sscanf; can't read .aux file"),0);
return;
}
#endif

n= sscanf((char*)(buffer+9),"%*c%[^}]%*3c%[^}]%*2c%[^}]%*3c%[^}]",
(char*)smodno,(char*)ssecno,(char*)spageno,(char*)smodno0);

if(n!=4)
{

err0_print(ERR_C,OC("Invalid \\Newlabel format in %s file, line %d"),2,aux_file_name,aline);
return;
}

modno= (sixteen_bits)ATOI(smodno);

if(modno>=max_modules)
OVERFLW("sections","m");

ps= sect_info+modno;

ps->secno= GET_MEM("ps->secno",STRLEN(ssecno)+1,outer_char);
STRCPY(ps->secno,ssecno);

ps->pageno= (sixteen_bits)ATOI(spageno);
ps->modno0= modno0= (sixteen_bits)ATOI(smodno0);

/* Check to see whether there was more than one section on a page.  */
sect_info[modno-1].subpage_flag= YES;

if((long)modno0==modno_ref)
pmcount++;/* More than one section on page. */
else
{/* Start of new page. */
if(pmcount==1)
sect_info[modno-1].subpage_flag= NO;

modno_ref= (long)modno0;
pmcount= 1;
}
}


}

sect_info[modno].subpage_flag= BOOLEAN(pmcount!=1);
fclose(fa);
}



outer_char HUGE*
mod_trans FCN((prefix,modno))
outer_char*prefix C0("")
sixteen_bits modno C1("")
{
outer_char HUGE*mod_temp= GET_MEM("mod_temp",NMOD_TEMP,outer_char);
SECT_INFO*ps= sect_info+modno;

if(ps->secno)
{
outer_char letter[2];

letter[1]= '\0';

letter[0]= (ps->subpage_flag?
XCHR(modno-ps->modno0+0141-1):'\0');

if(letter[0]&&XORD(letter[0])>0172)
letter[0]= '?';


if(
nsprintf(mod_temp,OC("%s %d (sect. %s, p. %d%s)"),5,prefix,modno,ps->secno,ps->pageno,letter)>=(int)(NMOD_TEMP))OVERFLW("mod_temp","");
}
else
{

if(
nsprintf(mod_temp,OC("%s %d"),2,prefix,modno)>=(int)(NMOD_TEMP))OVERFLW("mod_temp","");
}

if(next_mod_name==last_mod_name)
CONFUSION("mod_trans","too many unfreed mod names");

return*(next_mod_name++)= mod_temp;
}



SRTN
mfree(VOID)
{
if(!mod_names)return;/* For errors happening during the command line. */

for(--next_mod_name;next_mod_name>=mod_names;next_mod_name--)
FREE(*next_mod_name);
}



int
lan_num FCN((Language))
LANGUAGE Language C1("")
{
proper_language:
switch(Language)
{
case C:return 0;
case RATFOR:return 1;
case FORTRAN:return 2;
case TEX:return 3;
case LITERAL:return 4;

case C_PLUS_PLUS:return 5;
case RATFOR_90:return 6;
case FORTRAN_90:return 7;

case NO_LANGUAGE:Language= GLOBAL_LANGUAGE;goto proper_language;
default:Language= global_language;goto proper_language;
}
}

LANGUAGE
lan_enum FCN((num))
int num C1("Integer index of the language.")
{
switch(num)
{
case 0:return C;
case 1:return RATFOR;
case 2:return FORTRAN;
case 3:return TEX;
case 4:return LITERAL;

case 5:return C_PLUS_PLUS;
case 6:return RATFOR_90;
case 7:return FORTRAN_90;

default:return NO_LANGUAGE;
}
}


int
lan_index FCN((Language))
LANGUAGE Language C1("")
{
proper_language:
switch(Language)
{
case C:return 0;

case RATFOR:
case FORTRAN:return 1;

case TEX:return 2;
case LITERAL:return 3;

case C_PLUS_PLUS:return 4;

case RATFOR_90:
case FORTRAN_90:return 5;

case NO_LANGUAGE:Language= GLOBAL_LANGUAGE;goto proper_language;
default:Language= global_language;goto proper_language;
}
}



SRTN
do_args FCN((doing_cmd_line0,argc,argv,pfound_web,wbflnm,pfound_change))
boolean doing_cmd_line0 C0("")
int argc C0("")
outer_char HUGE*argv[]C0("")
boolean HUGE*pfound_web C0("")
outer_char wbflnm[]C0("")
boolean HUGE*pfound_change C1("")
{
boolean a_file_name;/* Is an actual file name supplied from the command line? */
outer_char HUGE*dot_pos;/* Position of |'.'| (or more generally, \
			|wt_style.ext_delimiter|) in the argument */
IN_STYLE outer_char HUGE*sprm_ptr0,HUGE*sprm_ptr;

doing_cmd_line= doing_cmd_line0;
cmd_prms= NO;

*pfound_web= *pfound_change= NO;

while(argc-->0)
{
if(!cmd_prms&&argv==pn0)
{/* Note beginning of command-line parameters. */
cmd_prms= YES;
sprm_ptr0= sprm_ptr;
}

pa= *(argv++);/* Beginning of current argument string. */

/* Arguments that don't begin with a hyphen, or that are just a single \
hyphen with no trailing stuff, mean file names. */
if((a_file_name= BOOLEAN(*pa!='-'))||*(pa+1)=='\0')

{
if(doing_cmd_line)
{
if(!*pfound_web)
{
STRCPY(wbflnm,THE_FILE_NAME);
*pfound_web= YES;
}
else if(!*pfound_change)

{
if(a_file_name&&STRLEN(pa)>MAX_FILE_NAME_LENGTH-5)
too_long();

/* For VMS, should skip over brackets here. */

if(a_file_name&&(dot_pos= OC(STRCHR(pa,wt_style.ext_delimiter)))==NULL
&&!try_extensions)
{

if(
nsprintf(change_file_name,OC("%s%cch"),2,pa,wt_style.ext_delimiter)>=(int)(MAX_FILE_NAME_LENGTH))OVERFLW("change_file_name","");
}
else
{

if(
nsprintf(change_file_name,OC("%s"),1,THE_FILE_NAME)>=(int)(MAX_FILE_NAME_LENGTH))OVERFLW("change_file_name","");
}

*pfound_change= YES;
}


else

{
printf("! Warning: Ignoring multiple change file \"%s\".\n",
(char*)THE_FILE_NAME);
mark_harmless;
continue;
}

;
}
else
{
printf("\n! File name \"%s\" is not allowed as optional argument; \
ignored.\n",pa);
mark_harmless;
}
}


else

{
outer_char mc;
outer_char cmd_symbol;/* The character after the hyphen. */


pa++;/* |pa| now points to the character after the hyphen. */

if(*pa=='-')
{/* Second hyphen means negate. */
not= YES;
pa++;/* Skip second hyphen. */
}
else
not= NO;

reswitch:
switch(cmd_symbol= *pa++)
{/* |pa| now positioned after command symbol---e.g., to optional \
argument. */
case '1':
case '2':
tracing= cmd_symbol-'0';break;

case '@':

{
if(!at_codes)
{
at_codes= GET_MEM("at_codes",200,ASCII);/* 200 is KLUDGE! */
at_codes[0]= '\0';
}

STRCAT(at_codes,to_ASCII(pa));
info_option= YES;
}


break;

case 'a':
case 'A':

{
#if(TRANSLATE_ASCII || DEBUG_XCHR)
translate_ASCII= YES;/* Force it for the cases that really need it. */
#else
translate_ASCII= NOT(TRANSLATE_ASCII0);
#endif
}



break;

case 'b':

{
params.Block_nums[LN(FORTRAN)]
= params.Block_nums[LN(FORTRAN_90)]
= params.Block_nums[LN(RATFOR)]
= params.Block_nums[LN(RATFOR_90)]
= NOT(BLOCK_NUMS);
}


break;

case 'B':
beeps= NOT(BEEPS);
break;


case 'c':case 'C'

:

{

cant_negate(pa-2);



Cpp= BOOLEAN(*pa=='+');/* The commands \.{-c+} or \.{-c++} turn on \
				knowledge of \.{C++}. */
if(Cpp)while(*pa=='+')pa++;/* Skip the pluses. */

switch(*pa)
{
case '{':
set_filter(Cpp?C_PLUS_PLUS:C);
break;

case '\0':
ini_language(XORD(*LANGUAGE_CODE(C)));
break;

default:
break;
}
}



break;

case 'D':

{
if(*pa=='[')

{
for(++pa;*pa!=']';pa++)
switch(*pa)
{
case 'i':
case 'I':
rsrvd.intrinsics= YES;
break;

case 'k':
case 'K':
rsrvd.keywords= YES;
break;

case 'r':
case 'R':
rsrvd.reserveds= YES;
break;

case '\0':

err0_print(ERR_C,OC("Missing ']' inserted after optional argument \
list to `-D'"),0);
break;

default:

err0_print(ERR_C,OC("Optional argument to `-D' must be one of \
'i', 'k', or 'r'"),0);
break;
}

pa++;/* Advance past the \.{']'}. */
}


else if(!(*pa=='\0'||*pa=='*'||isalpha(*pa)))
{

err0_print(ERR_C,OC("Either nothing, a letter, '*', or '[' must follow `-D'; \
option ignored"),0);
break;
}

rsrvd.args= pa;

if(!*pa)
rsrvd.reserveds= YES;

info_option= YES;
}


break;
case 'd':
number_dos= NOT(NUMBER_DOS);/* NOTE:  falls through to next case! */

case ':':

{

cant_negate(pa-2);



max_stmt= STARTING_DO_NUM;

if(*pa)
{/* Optional starting line number specified. */
max_stmt= ATOL(pa);

if(max_stmt>99999L)

err0_print(ERR_C,OC("Starting DO number must be < 99999; assuming %lu"),1,max_stmt= STARTING_DO_NUM);
}
}



break;

case 'e':
try_extensions= NOT(TRY_EXTENSIONS);break;

case 'E':

{

cant_negate(pa-2);



if(*pa)wt_style.ext_delimiter= *pa;
else
err0_print(ERR_C,OC("Missing character after -E option; option ignored"),0);
}


break;

case 'f':
subscript_fcns= NOT(SUBSCRIPT_FCNS);break;

case 'F':
compare_outfiles= NOT(COMPARE_OUTFILES);break;

case 'g':
dbg_output= NOT(DBG_OUTPUT);break;

case 'h':

cant_negate(pa-2);


help();
break;

case 'H':

{
outer_char HUGE*p= pa;

more_H:
switch(*p++)
{
case 'r':
rmv_files= NOT(RMV_FILES);/* For debugging. */
goto more_H;

case 'x':
quoted_includes= NOT(QUOTED_INCLUDES);
goto more_H;

case 'X':
all_includes= NOT(ALL_INCLUDES);
goto more_H;

case '\0':
read_iformats= NOT(READ_IFORMATS);
break;

default:
bad_option();
break;
}
}


break;

case 'i':

{
switch(*pa)
{
case 'x':
index_hidden= NOT(INDEX_HIDDEN);/* Falls through. */

case '\0':
toggle_includes= NOT(TOGGLE_INCLUDES);break;

case '!':
skip_includes= NOT(SKIP_INCLUDES);break;

default:
bad_option();break;
}
}


break;

case 'I':
more_includes(pa);/* Add to include path list. */
break;

case 'j':
skip_ifiles= NOT(SKIP_IFILES);break;

case 'k':
lc_keywords= NOT(LC_KEYWORDS);break;

case 'l':

{
prn_input_lines= BOOLEAN(YES^not);

if(*pa)
if(isdigit(*pa)||*pa=='-')
{
outer_char*colon_pos;

start_line= ATOL(pa);
if((colon_pos= OC(STRCHR(pa,':')))==NULL)
end_line= LONG_MAX;
else end_line= ATOL(colon_pos+1);
}

else
{
printf("! Option `-l' must be followed by integer.\n");
mark_harmless;
}

/* Negative line numbers are undocumented; they're for the developer. */
if(start_line<0)
{
start_line= -start_line;
prn_input_addresses= YES;
}
}



break;

case 'L':

{
switch(*pa)
{

case 'c':case 'C'

:

case 'n':case 'N'

:

case 'r':case 'R'

:
goto reswitch;


case 'v':case 'V'



:

cant_negate(pa-2);


switch(*(pa+1))
{
case '{':
set_filter(LITERAL);
break;

case '\0':
ini_language(XORD(*LANGUAGE_CODE(LITERAL)));
break;

default:
bad_lcmd("argument",pa-2);
break;
}
break;


case 'x':case 'X'

:

cant_negate(pa-2);


switch(*(pa+1))
{
case '{':
set_filter(TEX);
break;

case '\0':
ini_language(XORD(*LANGUAGE_CODE(TEX)));
break;

default:
bad_lcmd("argument",pa-2);
break;
}
break;

default:
bad_lcmd("command",pa-2);
break;
}
}


break;

case 'm':
case 'M':

{
switch(*pa)
{
case '4':
/* Recognize \.{m4} definitions. */

cant_negate(pa-2);


m4= !M4_;
break;

case ';':
/* Automatically append pseudo-semi to \.{WEB} macro definition. */
auto_app_semi= NOT(AUTO_APP_SEMI);
break;

case '\0':

err0_print(ERR_C,OC("Missing id for 'm' option"),0);
break;

default:
if(not)goto undefine_macro;

define_macro:
mc= *pa;

if(!(isalpha(mc)||mc=='_'||mc=='$'))

err0_print(ERR_C,OC("Macro definition may not start with \
'%c'; -m option ignored"),1,mc);
else SAVE_MACRO(pa);/* Macro definition. */

break;
}
}


break;


case 'N':
nuweb_mode= NOT(NUWEB_MODE);
break;

case 'n':
FR_args(FORTRAN);
break;

case 'o':
overload_ops= NOT(OVERLOAD_OPS);
break;

case 'p':

{
IN_STYLE outer_char HUGE*sprm_buf,HUGE*sprm_ptr,HUGE*sprm_end;
int n= STRLEN(pa);
size_t nbuf,nused;

if(!sprm_buf)
{/* Allocate the style-parameter buffer. */
sprm_ptr= sprm_buf= GET_MEM("sprm_buf",SPRM_LEN,outer_char);
sprm_end= sprm_buf+SPRM_LEN;
nbuf= SPRM_LEN;
}

if(sprm_ptr+(n+2)>=sprm_end)
{/* Reallocate a larger buffer. */
BUF_SIZE old_size;

nused= PTR_DIFF(size_t,sprm_ptr,sprm_buf);
old_size= nbuf;
nbuf= PTR_DIFF(size_t,sprm_end,sprm_buf)+SPRM_LEN;

if((sprm_buf= (outer_char HUGE*)REALLOC(sprm_buf,
nbuf*sizeof(outer_char),old_size*sizeof(outer_char)))==NULL)
OVERFLW("sprm_buf",0);

sprm_ptr= sprm_buf+nused;
sprm_end= sprm_ptr+nbuf;
}

/* Add a line (terminated with space and newline). */
STRCPY(sprm_ptr,pa);
sprm_ptr+= n;
*sprm_ptr++= ' ';
*sprm_ptr++= '\n';
}


break;

case 'P':

{
switch(*pa)
{
default:

err0_print(ERR_C,OC("'%c' is invalid option for -X; must be either 'L' \
(LaTeX) or 'T' (TeX).  LaTeX is assumed"),1,*pa);/* Falls through to \LaTeX\ case. */

case '\0':
case 'L':
TeX_processor= LaTeX_p;
break;

case 'T':
TeX_processor= TeX_p;
break;
}
}



break;

case 'q':
free_form_input= NOT(FREE_FORM_INPUT);
Ratfor77= NOT(RATFOR77);
break;


case 'r':case 'R'

:
if(!RAT_OK("Language command ignored"))
break;
FR_args(RATFOR);
break;

case 's':

{
statistics= NOT(STATISTICS);

/* The format ``\.{-sm100}'' says to display memory allocations for sizes \
$>= 100$ bytes. */
if(*pa)
if(*pa=='m')
{
pa++;/* |pa| positioned to byte size. */
show_mem= NOT(SHOW_MEM);
if(isdigit(*pa))show_size= ATOL(pa);
}
else
{
printf("! Option \"%s\" is invalid.\n",(char*)(pa-2));
mark_harmless;
}
}


break;

case 't':

{

cant_negate(pa-2);


ntrunc();
}


break;

case 'T':

{
outer_char HUGE*p= pa;

while(*p)
switch(*p++)
{
case 'D':
deferred_macros= NOT(DEFERRED_MACROS);
break;

case 'v':
top_version= NOT(TOP_VERSION);
break;

case '%':
keep_trailing_comments= NOT(KEEP_TRAILING_COMMENTS);
break;

case '#':
auto_line= NOT(AUTO_LINE);
break;

default:
bad_option();
break;
}
}


break;

case 'u':

{
if(not)
goto define_macro;

undefine_macro:
if(*pa=='\0')

err0_print(ERR_C,OC("Missing identifier for `-u' option"),0);
else
save_macro(OC("#undef"),pa);
}



break;

case 'U':
lowercase_tokens= NOT(LOWERCASE_TOKENS);
break;

case 'v':
all_cmnts_verbatim= NOT(ALL_CMNTS_VERBATIM);
break;

case 'w':
if(*pa)
new_fname(&fwebmac,pa,NULL);
else
input_macros= NOT(INPUT_MACROS);

break;

case 'W':

{
outer_char HUGE*p= pa;

while(*p)
switch(*p++)
{
case '[':
active_brackets= NOT(ACTIVE_BRACKETS);
break;

case 'd':
defn_mask.outer_macros= NOT(PRN_OUTER_MACROS);
break;

case 'f':
defn_mask.formats= NOT(PRN_fORMATS);
break;

case 'F':
defn_mask.Formats= NOT(PRN_FORMATS);
break;

case 'l':
defn_mask.limbo= NOT(PRN_LIMBO);
break;

case 'm':
defn_mask.macros= NOT(PRN_MACROS);
break;

case 'v':
defn_mask.v= NOT(PRN_V);
break;

case 'w':
case 'W':
defn_mask.w= NOT(PRN_W);
break;

default:
bad_option();
break;
}
}


break;

case 'x':
flags3(BOOLEAN(not));
break;

case 'X':
flags3(BOOLEAN(!not));
break;

case 'y':

{
outer_char abbrev[80],HUGE*a;
BUF_SIZE nunits;
MEM HUGE*m,HUGE*mmin= NULL,HUGE*mmax= NULL;
boolean query_mode= NO;



cant_negate(pa-2);



if(!*pa)
{/* Query everything. */
mmin= mem;
mmax= mmin+(sizeof_mem/sizeof(MEM)-1);
query_mode= YES;
puts("Default memory allocation parameters:");
}
else
{/* Abbreviation specified. */
abbrev[0]= abbrev[1]= '\0';/* Ensure the abbreviation gets \
		terminated properly. */

for(a= abbrev;isalpha(*pa);)
*a++= *pa++;

TERMINATE(abbrev,2);/* Max of two character abbreviation. */

if(!isdigit(*pa))
{/* Assume it's a question. */
mmin= msearch(abbrev,0L);
mmax= mmin+1;
query_mode= YES;
}
}

if(query_mode)
for(m= mmin;m<mmax;m++)
printf(" \"%-s\"%s x %d byte(s):\
  min = %lu, current = %lu [%lu byte(s)], max = %lu.\n",
(char*)m->abbrev,m->abbrev[1]?"":" ",
m->bytes,
m->min,m->nunits,(m->nunits)*(m->bytes),m->max);
else
{/* Change setting. */
nunits= ATOL(pa);
msearch(abbrev,nunits);/* Set the value. */
}

info_option= YES;
}


break;

case 'z':

{

cant_negate(pa-2);



if(STRLEN(pa)<MAX_FILE_NAME_LENGTH)
{
if(STRCMP(pa,".")==0)
{/* Read default file in current directory. */
if(
nsprintf(style_file_name,OC(".%c%s"),2,PREFIX_END_CHAR,STYLE_FILE_NAME)>=
MAX_FILE_NAME_LENGTH)OVERFLW("./style_file_name","");
}
else
STRCPY(style_file_name,pa);

renamed_style= YES;
}
else
err0_print(ERR_C,OC("Style file name too long; must be less \
than %d characters"),1,MAX_FILE_NAME_LENGTH);
}



break;

case 'Z':
prn_style_defaults= BOOLEAN(!not);
style_args= pa;
info_option= YES;
break;

case '.':
dot_constants= NOT(DOT_CONSTANTS);
break;

case '\\':
bslash_continued_strings= NOT(BSLASH_CONTINUED_STRINGS);
break;

case '?':
chk_stmts= NOT(CHK_STMTS);
break;

case '[':
translate_brackets= NOT(TRANSLATE_BRACKETS);
break;

case '(':
case ')':
chk_ifelse= NOT(CHK_IFELSE);break;

case '>':
case '=':

cant_negate(pa-2);


if(doing_cmd_line||phase==2)
redirect_output();
break;

case '/':
params.CPP_comments[LN(FORTRAN)]
= params.CPP_comments[LN(FORTRAN_90)]
= params.CPP_comments[LN(RATFOR)]
= params.CPP_comments[LN(RATFOR_90)]
= BOOLEAN(YES^not);
break;

case '!':
params.Point_comments[LN(FORTRAN)]
= params.Point_comments[LN(FORTRAN_90)]
= params.Point_comments[LN(RATFOR)]
= params.Point_comments[LN(RATFOR_90)]
= BOOLEAN(YES^not);
break;

case '+':
compound_assignments= NOT(COMPOUND_ASSIGNMENTS);break;

case '#':
line_info= NOT(LINE_INFO);break;

default:
bad_option();
break;
}
}


;
}
}



SRTN
opt_args FCN((l))
ASCII l C1("")
{
ASCII arg_buffer[ARG_BUFFER_SIZE],*pa= arg_buffer,
*arg_buffer_end= arg_buffer+ARG_BUFFER_SIZE;
int argc;
outer_char HUGE*args[MAX_ARGS];

ini_language(l);/* Set language and initialize flags. */

if(!IS_WHITE(*loc))
{
if(*loc!=0133)
{/* Unbracketed command, as in \.{@c++}. */
*pa++= 055;/* Make it an honest command. */
*pa++= l;/* Don't forget the language. */

WHILE()
{
if(IS_WHITE(*loc)||*loc==0133)break;
if(*loc==0174&&parsing_mode==INNER)
{

err0_print(ERR_C,OC("WARNING:  Code mode ended during \
unbracketed optional argument.  Should there be white space after \
language command?"),0);
break;
}
COPY_TO_ARG_BUFFER(*loc++);
}
}

/* We allow bracketed commands to follow unbracketed ones. */
if(*loc==0133)
{
COPY_TO_ARG_BUFFER(040);

for(loc++;;)
{/* Skip the opening bracket; copy contents. */
if(*loc==0135)
{
loc++;/* Skip the ending bracket. */
break;
}
COPY_TO_ARG_BUFFER(*loc++);
}
}

TERMINATE(pa,0);/* Terminate |arg_buffer|. */
argc= to_args(to_outer(arg_buffer),args,MAX_ARGS);
do_args(NO,argc,args,&found_web,(outer_char*)NULL,&found_change);
}

fin_language();/* Do any further flag setup. */
}



SRTN
ini_language FCN((l))
ASCII l C1("Basic language code")
{
/* First we set the language. */
switch(l)
{

case 0143:case 0103

:
language= (Cpp?C_PLUS_PLUS:C);
break;


case 0162:case 0122

:
if(!RAT_OK("Invalid @r command; language set to C"))language= C;
else language= (Fortran88?RATFOR_90:RATFOR);
break;


case 0156:case 0116

:
language= (Fortran88?FORTRAN_90:FORTRAN);
break;


case 0166:case 0126



:
language= LITERAL;
break;


case 0170:case 0130

:
language= TEX;
break;
}

/* The following is for checking an override of the command-line language \
in the limbo section. */
if(doing_cmd_line)cmd_language= language;

ini0_language();
}



SRTN
ini0_language(VOID)
{
/* Set the output language. */
out_language= OUT_LANGUAGE(language);

/* Storing these numbers cuts down on the overhead of function calls.  It \
also enables us to use the macros in the following |switch| properly. */
language_index= (short)lan_index(language);/* Maybe no longer used. */
language_num= (short)lan_num(language);

index_flag= YES;/* Most languages will cross-reference. */

switch(language)
{
case C:
Cpp= NO;
break;

case C_PLUS_PLUS:
Cpp= YES;/* Just a shorthand for |language==CPP|. */
break;

case FORTRAN:
case FORTRAN_90:
free_form_input= global_params.Free_form_input[language_num];
/* This can be turned on by the \.{-n\\} or \.{-n\&} options. */
auto_semi= global_params.Auto_semi[language_num];
break;

case RATFOR:
case RATFOR_90:
if(nuweb_mode)

err0_print(ERR_C,OC("SORRY, but Ratfor doesn't work yet with the N \
mode!"),0);
auto_semi= global_params.Auto_semi[language_num];
if(auto_semi)free_form_input= NO;
break;

case LITERAL:
nuweb_mode= YES;
line_info= NO;
index_flag= NO;
break;

case TEX:
break;

default:
break;
}
}



SRTN
fin_language(VOID)
{
ini_reserved(language);

switch(language)
{
case C:
break;

case RATFOR:
break;

case FORTRAN:
break;

case LITERAL:
break;

case TEX:
break;

default:
break;
}

frz_params();/* Make any local parameters. */

/* Output file name.  For |program == weave|, |out_file == tex_file| by a \
macro definition in \.{typedefs.hweb}. */
if(program==tangle)
out_file= params.outp_file[lan_num(out_language)];
}



SRTN
frz_params(VOID)
{

cont_char= XORD(in_escape);/* Current continuation character (in |ASCII|). */
free_90= BOOLEAN(Fortran88&&free_form_input);
free_Fortran= BOOLEAN((language==FORTRAN_90)&&free_90);

if(is_FORTRAN_(language))
auto_semi= BOOLEAN(!free_Fortran);

if(program==tangle&&free_90)
switch(language)
{
case FORTRAN_90:
case RATFOR_90:
begin_comment_char[lan_num(FORTRAN_90)]= 
(outer_char)CHOICE(free_90,'!','C');
break;

default:;
}

}



int
to_args FCN((p,args,max_args))
outer_char HUGE*p C0("")
outer_char HUGE*args[]C0("")
int max_args C1("")
{
int n;

for(n= 0;*p;p++)
{
if(n>=max_args)
{

err0_print(ERR_C,OC("Too many command-line or optional \
arguments; must be < %d"),1,max_args);
break;
}
while(isspace(*p))p++;/* Skip leading white space. */
args[n++]= p;/* Record start and count. */

for(p++;*p;p++)
if(isspace(*p)||!*p)break;/* Find end of argument. */

if(!*p)break;/* Get out at end of line. */
TERMINATE(p,0);/* Mark end of argument. */
}

return n;/* Number of arguments found. */
}



SRTN
help(VOID)
{
puts("! For help, please see the texinfo entry for FWEB or use options\n\
 '-@' (query control codes),\n\
 '-D' (query reserved words),\n\
 '-y' (query memory allocations),\n\
 '-Z' (query style-file parameters).");

usage("",NO);/* In lieu of anything better. */
}




SRTN
FR_args FCN((Language))
LANGUAGE Language C1("")
{
int lnum;


cant_negate(pa-2);



if(isdigit(*pa))
switch(*pa++)
{/* Options \.{-n7} or \.{-n9}. */
case '7':
Fortran88= NO;
ini_language(XORD(*LANGUAGE_CODE(Language)));
break;

case '9':
Fortran88= YES;
ini_language(XORD(*LANGUAGE_CODE(Language)));
break;

default:
bad_loption(Language);break;
}
else
{
lnum= lan_num(language);/* We need to set this so that we can \
access the language arrays  properly. ??? |language| ??? Used to be |Language| */

switch(*pa++)
{
case '\\':
case '&':
/* Set the continuation character; for \Fortran, turn on \
free-form syntax. */
if(is_FORTRAN_(Language))
params.Free_form_input[lnum]= NOT(FREE_FORTRAN);
params.In_escape[lnum]= *(pa-1);/* Continuation character. */
break;

case ';':
params.Auto_semi[lnum]= BOOLEAN(YES^not);
break;

case ':':
if(is_FORTRAN_(Language))
Fortran_label= NOT(FORTRAN_LABEL);
break;

case '!':
params.Point_comments[lnum]= BOOLEAN(YES^not);
break;

case '/':
params.CPP_comments[lnum]= BOOLEAN(YES^not);
break;

case ')':
params.Reverse_indices[lnum]= BOOLEAN(YES^not);
break;

case 'b':
case 'B':
params.Block_nums[lnum]= NOT(BLOCK_NUMS);break;

case 'g':
case 'G':

{
if(is_RATFOR_(Language))
{
if(!RAT_OK("'g' command ignored"))break;

{
while(*pa)
if(isalpha(*pa))
switch(*pa++)
{
case 'r':
case 'R':
g_ratio= STRTOD(pa,&pa);
if(g_ratio<MIN_G_RATIO)
{

err0_print(ERR_C,OC(
"Invalid 'g' option: %s must be >= %.1f"),2,"g_ratio",MIN_G_RATIO);
g_ratio= G_RATIO;
};
break;
case 'm':
case 'M':
marginal_cases= 
(unsigned short)STRTOL(pa,&pa,10);
if(marginal_cases<MIN_MARGINAL_CASES)
{

err0_print(ERR_C,OC("Invalid 'g' option: %s must be >= %d"),2,"marginal_cases",MIN_MARGINAL_CASES);
marginal_cases= MARGINAL_CASES;
};
break;
case 's':
case 'S':
max_spread= STRTOL(pa,&pa,10);
if(max_spread<MIN_MAX_SPREAD)
{

err0_print(ERR_C,OC("Invalid 'g' option: %s must be >= %d"),2,"max_spread",MIN_MAX_SPREAD);
max_spread= MAX_SPREAD;
};
break;
default:

err0_print(ERR_C,OC("Invalid 'g' option: \
parameter type '%c'"),1,*(pa-1));
break;
}
}

;
}
else bad_loption(Language);
}


break;

case 'k':
suppress_cmds= BOOLEAN(YES^not);

{
if(!*pa)STRCPY(abbrev_cmds,"*");
else STRNCPY(abbrev_cmds,pa,NUM_RATFOR_CMDS);
}



break;

case 'K':
suppress_cmds= BOOLEAN(NO^not);

{
if(!*pa)STRCPY(abbrev_cmds,"*");
else STRNCPY(abbrev_cmds,pa,NUM_RATFOR_CMDS);
}



break;

case 'p':
if(is_FORTRAN_(Language))prn_semis= NOT(PRN_SEMIS);
break;

case '{':
pa--;
set_filter(Language);
break;

case '\0':
/* Specify the language.  Note that the other commands don't. */
ini_language(XORD(*LANGUAGE_CODE(Language)));
break;

default:
bad_loption(Language);
break;
}
}
}




SRTN
save_macro FCN((cmd,t))
CONST outer_char HUGE*cmd C0("Name of the ``at'' command to put first.")
outer_char HUGE*t C1("Text of the definition.")
{
eight_bits HUGE*p;
boolean replace_equals= BOOLEAN(STRCMP(cmd,"m")==0);/* For macros, if an \
	equals sign appears before a space, it will be turned into a space. */

if(program==weave)return;

p= mp;

/* Place command such as \.{@m} into buffer. */
*mp++= '@';

while(*cmd)
*mp++= *cmd++;/* Copy text of command. */

*mp++= ' ';

while(*t)
{
if(replace_equals)
if(*t=='=')
{
*t= ' ';
replace_equals= NO;
}
else if(*t==' ')replace_equals= NO;
*mp++= *t++;
}

*mp++= ' ';
*mp= '@';*(mp+1)= 'm';

/* After we've built it, convert to internal notation. */
for(;p<mp+2;p++)
*p= XORD(*p);
}



SRTN
divert FCN((buffer,end,stop))
ASCII HUGE*buffer C0("Start of the buffer.")
ASCII HUGE*end C0("End of the buffer.")
boolean stop C1("Stop when end is reached?")
{
stop_the_scan= stop;

fbuffer= cur_buffer;
flimit= limit;
floc= loc;

cur_buffer= loc= buffer;
limit= end;

from_buffer= YES;
}


SRTN undivert(VOID)
{
cur_buffer= fbuffer;
limit= flimit;
loc= floc;

from_buffer= NO;
}




SRTN
mem_avail FCN((at_end))
int at_end C1("0 for beginning, 1 for end")
{
if(at_end)
printf("\n Allocated maximum of %lu bytes dynamically; \
ended with %lu bytes.\n",max_mem,total_mem);

#if PRINT_AVAILABLE_MEMORY
printf(" Available memory: %lu bytes.\n",CORE_LEFT);
if(!at_end)
{
starting_memory= CORE_LEFT;/* Used in |smin0|. */
putchar('\n');
}
#endif
}



SRTN
stat0 FCN((name,size,num,max_num,abs_max_num,abbrev,ctrl_chars))
CONST outer_char*name C0("")
size_t size C0("")
BUF_SIZE num C0("")
BUF_SIZE max_num C0("")
BUF_SIZE abs_max_num C0("")
CONST outer_char*abbrev C0("")
CONST outer_char*ctrl_chars C1("")
{
printf("  %s [\"%s\"] x %u byte(s):  %lu [%lu byte(s)] of %lu <= %lu%s\n",
(char*)name,(char*)abbrev,(unsigned)size,num,num*size,max_num,
abs_max_num,(char*)ctrl_chars);
}



BUF_SIZE
smin0 FCN((abs_max_num))
BUF_SIZE abs_max_num C1("")
{
return MIN(starting_memory,abs_max_num);
}




SRTN
ntrunc(VOID)
{
LANGUAGE l;

truncate_ids= NO;

if(!*pa)goto bad_t_option;

while(*pa)
{
if(isdigit(*pa))
l= (language==NO_LANGUAGE)?GLOBAL_LANGUAGE:language;
else switch(*pa++)
{

case 'c':case 'C'

:
l= lcase(C,'\0',C_PLUS_PLUS,'+',&pa);
break;

case 'r':case 'R'

:
l= lcase(RATFOR,'7',RATFOR_90,'9',&pa);
break;

case 'n':case 'N'

:
l= lcase(FORTRAN,'7',FORTRAN_90,'9',&pa);
break;

case 'v':case 'V'



:
l= LITERAL;break;

case 'x':case 'X'

:
l= TEX;break;
default:
bad_t_option:

err0_print(ERR_C,OC("Invalid -t option.  Example:  `-tn=6{_}'"),0);
return;
}

/* Skip over optional equals sign. */
if(*pa==LANGUAGE_SEPARATOR)pa++;

/* Set the maximum identifier length for language~|l|. */
truncate_ids= 
BOOLEAN(CHOICE((tr_max[lan_num(l)]= (unsigned short)ATOI(pa))!=0,
YES,NO));

while(isdigit(*pa))pa++;/* Skip over the integer. */

if(*pa=='{')set_filter(l);
}
}



LANGUAGE
lcase FCN((l0,c0,l1,c1,pp))
LANGUAGE l0 C0("")
outer_char c0 C0("")
LANGUAGE l1 C0("")
outer_char c1 C0("")
outer_char HUGE*HUGE*pp C1("")
{
if(c0&&**pp==c0)
{
while(**pp==c0)(*pp)++;
return l0;
}

if(c1&&**pp==c1)
{
while(**pp==c1)(*pp)++;
return l1;
}

return l0;
}



SRTN
set_filter FCN((Language))
LANGUAGE Language C1("")
{
if(!*pa)return;/* In case there's no argument following the language cmd. */

if(*pa=='{')pa++;

filter_char[lan_num(Language)]= (char*)pa;/* Repoint to the string of \
				characters following this command. */

/* Remove the closing bracket from the list. */
for(;*pa;pa++)
if(*pa=='}')
{
*pa++= '\0';
return;
}
}




SRTN
flags3 FCN((not))
boolean not C1("")
{
prn_contents= BOOLEAN(PRN_CONTENTS^not);
prn_index= BOOLEAN(PRN_INDEX^not);
prn_modules= BOOLEAN(PRN_MODULES^not);
xref_unnamed= BOOLEAN(XREF_UNNAMED^not);

if(!(*pa))
{/* No argument.  Assume nothing is to be printed. */
*pa= '*';
*(pa+1)= '\0';
}

for(;*pa;pa++)
switch(*pa)
{
case '*':
case '/':
prn_contents= NOT(PRN_CONTENTS);
prn_index= NOT(PRN_INDEX);
prn_modules= NOT(PRN_MODULES);
break;

case 'C':
case 'c':
prn_contents= NOT(PRN_CONTENTS);
break;

case 'I':
case 'i':
prn_index= NOT(PRN_INDEX);
break;

case 'M':
case 'm':
prn_modules= NOT(PRN_MODULES);
break;

case 'u':
xref_unnamed= NOT(XREF_UNNAMED);
break;

default:

err0_print(ERR_C,OC("'%c' is invalid argument for -x; must be \
element of set {*cim}"),1,*pa);
break;
}

no_xref= BOOLEAN(!(prn_index||prn_modules));
}



SRTN
redirect_output(VOID)
{
int k;

if(*pa=='\0')
{/* Empty argument; send stuff to |stdout|. */
new_fname(&tex_fname,OC("stdout"),NULL);

for(k= 0;k<NUM_LANGUAGES;k++)
new_fname(params.outp_nm+k,OC("stdout"),NULL);
}
else if(phase==2&&program==weave)
return;
else
{
outer_char c,HUGE*pname;
outer_char HUGE*q= (outer_char HUGE*)STRCHR(pa,LANGUAGE_SEPARATOR);
/* Is there an '='? */

if(q==pa)
{/* ``\.{->=new\_name}'' */
c= LANGUAGE_SEPARATOR;
pname= q+1;/* Point to file name. */
}
else if(q)
{/* ``\.{->c=new\_name}'' */
c= *pa++;/* Language symbol. */
pname= q;/* Point to \.=. */
}
else
{/* ``\.{->new\_name}'' */
c= LANGUAGE_SEPARATOR;
pname= pa;/* Point to file name. */
}

switch(c)
{

case 'c':case 'C'

:
set_fname(lcase(C,'\0',C_PLUS_PLUS,'+',&pa),pname,YES);
break;


case 'r':case 'R'

:
if(!RAT_OK("Redirection ignored"))break;

set_fname(lcase(RATFOR,'7',RATFOR_90,'9',&pa),pname,YES);
break;


case 'n':case 'N'

:
set_fname(lcase(FORTRAN,'7',FORTRAN_90,'9',&pa),pname,YES);
break;


case 'v':case 'V'



:
set_fname(LITERAL,pname,YES);
break;


case 'x':case 'X'

:
set_fname(TEX,pname,YES);
break;

case LANGUAGE_SEPARATOR:
#if 0 /* Don't want to do this; it screws up module labeling for \FWEAVE. */
new_fname(&tex_fname,pname,NULL);
#endif

for(k= 0;k<NUM_LANGUAGES;k++)
new_fname(params.outp_nm+k,pname,NULL);

break;

default:

err0_print(ERR_C,OC("Syntax error in output redirection \
command \"->\". Language must be one of 'c', 'r', 'n', `m', or `x',  not '%c'"),1,*(pa-1));
break;
}
}
}



SRTN
set_fname FCN((l,s,check))
LANGUAGE l C0("Language")
outer_char HUGE*s C0("Remainder of command-line argument to parse")
boolean check C1("Do we check for beginning colon?")
{
if(program==weave)

err0_print(ERR_C,OC("Can't redirect FWEAVE's TeX output by individual \
languages. Use \"->\" or \"-%cname.ext\""),1,LANGUAGE_SEPARATOR);

if(check)
if(*s++!=LANGUAGE_SEPARATOR)
{

err0_print(ERR_C,OC("Expected '%c' after language in \"->\"; \
command ignored"),1,LANGUAGE_SEPARATOR);
return;
}

/* If the name begins with a '\.\#', it's filled in later with |wbflnm0|. */
new_fname(params.outp_nm+lan_num(l),*s?s:(outer_char HUGE*)"stdout",NULL);
}




SRTN
cant_negate FCN((s))
outer_char HUGE*s C1("")
{
if(not)
{
printf("! Can't negate option \"%s\"'; ignoring extra hyphen.\n",
(char*)s);
mark_harmless;
}
}



SRTN
bad_lcmd FCN((type,pa0))
CONST char*type C0("")
CONST outer_char HUGE*pa0 C1("")
{

err0_print(ERR_C,OC("Invalid language %s \"%s\""),2,type,pa0);
}



SRTN
bad_loption FCN((Language))
LANGUAGE Language C1("")
{
printf("! Invalid language option \"%s\" for %s.\n",
(char*)(pa-3),is_FORTRAN_(Language)?"Fortran":"Ratfor");
mark_harmless;
}



SRTN
usage FCN((msg,is_fatal))
CONST char*msg C0("")
boolean is_fatal C1("Fatal?")
{
outer_char temp[200];

sprintf((char*)temp,
"%s!! Usage:  %s webfile[%cweb] [changefile[%cch]] [-option...]\n",
msg,
program==tangle?"ftangle":"fweave",
wt_style.ext_delimiter,wt_style.ext_delimiter);

if(is_fatal)
FATAL(NULL,temp,"");
else
wrap_up();
}



SRTN
too_long(VOID)
{
FATAL(NULL,"!! Filename too long: ",(CONST outer_char*)pa);
}



SRTN
bad_option(VOID)
{
printf("! Unknown option \"%s\" ignored.\n",(char*)(pa-2));
mark_harmless;
}



SRTN
chk_override FCN((language0))
LANGUAGE language0 C1("")
{
if(language!=language0&&cmd_language!=NO_LANGUAGE&&cmd_language!=
language)

err0_print(ERR_C,OC("WARNING:  Command-line language %s overridden in limbo by %s"),2,languages[lan_num(cmd_language)],languages[lan_num(language)]);
}



SRTN
new_fname FCN((pname,name,ext))
outer_char HUGE*HUGE*pname C0("")
outer_char*name C0("")
outer_char*ext C1("")
{
outer_char temp[MAX_FILE_NAME_LENGTH];

/* An empty |name| means allocate some space. */
if(!name)
*pname= GET_MEM("pname",DFLT_FNAME_LENGTH+1,outer_char);
else
{/* Otherwise, we possibly allocate the space and construct the \
name. */
char ext_delimiter[2];
FILE*temp_file_ptr;

ext_delimiter[0]= (char)wt_style.ext_delimiter;
ext_delimiter[1]= '\0';


if(
nsprintf(temp,OC("%s%s%s"),3,name,ext?
ext_delimiter:"",ext?ext:(outer_char*)"")>=(int)(MAX_FILE_NAME_LENGTH))OVERFLW("temp","");

/* Previously we used to reallocate the file name here.  However, that \
leads to an egregious error, since if the block is actually moved the old \
pointers are still around on the stack and in various other hiding places. \
Now, we just allocate a new area if the name is new. */
was_opened(temp,0,pname,&temp_file_ptr);
}
}



unsigned
esc_file_name FCN((esc_name,max_length,name))
outer_char*esc_name C0("Put answer into here")
unsigned max_length C0("Maximum length of |esc_name|.")
outer_char*name C1("Put escapes into this name")
{
outer_char*pt,*pn;
unsigned n;

max_length--;/* Allow room for the final null. */

for(pt= esc_name,pn= name,n= 0;*pn;)
{
if(program==weave)
switch(*pn)
{
case '\\':case '$':case '#':case '%':
case '^':case '~':case '&':case '_':
if(n<max_length)
{
n++;
*pt++= '\\';
}
}

if(n<max_length)
{
n++;
*pt++= *pn++;
}
}

TERMINATE(pt,0);
return n;
}



SRTN
ASCII_file_write FCN((file_ptr,p0,n))
FILE*file_ptr C0("Standard file pointer.")
CONST ASCII HUGE*p0 C0("Start of the buffer.")
size_t n C1("Number of characters to write.")
{
CONST ASCII HUGE*p,HUGE*p1= p0+n;
ASCII atemp[1000],HUGE*a,HUGE*a1;
size_t n_out;

if(n==0)
return;

/* Translate any special characters into something readable. */
for(p= p0,a1= atemp;p<p1;a1++,p++)
switch(*p)
{
case interior_semi:
*a1= 073;
break;

case MACRO_ARGUMENT:
*a1++= 0133;
*a1++= 0133;
*a1++= (ASCII)(060+*(++p));
*a1++= 0135;
*a1= 0135;
break;

default:
*a1= *p;
break;
}

n= PTR_DIFF(size_t,a1,atemp);
/* Might be bigger than incoming~|n| because of macro arg. */

if(translate_ASCII)
{/* Convert to the outer world. */
outer_char temp[1000];
outer_char HUGE*t;

for(a= atemp,t= temp;a<a1;)
*t++= XCHR(*a++);

n_out= FWRITE(temp,n,file_ptr);
}
else
n_out= FWRITE(atemp,n,file_ptr);

if(n_out!=1)

{
char temp[100];
int errno0= errno;

sprintf(temp,"! WRITE ERROR: nbytes = %u, %u items written\n",
(unsigned)n,(unsigned)n_out);
FATAL(NULL,temp,strerror(errno0));
}


}



#if !HAVE_STRERROR

char*
strerror FCN((errnum))
int errnum C1("")
{
static char temp[50];

sprintf(temp,"(strerror is not available; errno = %d)",errnum);
return temp;
}

#endif /* |!HAVE_STRERROR| */



struct tm*
the_localtime(VOID)
{
time_t the_tm;
time_t time PROTO((time_t*tp));

time(&the_tm);
return localtime(&the_tm);
}



CONST outer_char*
the_day FCN((t))
CONST struct tm*t C1("")
{
return OC(day[t->tm_wday]);
}

#define NDATE 20

CONST outer_char*
the_cdate FCN((t))
CONST struct tm*t C1("")
{
static outer_char date_buf[NDATE];

if(
nsprintf(date_buf,OC("%s %d, %d"),3,month[t->tm_mon],t->tm_mday,1900+t->tm_year)>=NDATE)
OVERFLW("Date","");
return(CONST outer_char*)date_buf;
}
#undef NDATE

#define NTIME 8

CONST outer_char*
the_time FCN((t))
CONST struct tm*t C1("")
{
static outer_char time_buf[NTIME];

if(
nsprintf(time_buf,OC("%d:%02d"),2,t->tm_hour,t->tm_min)>=NTIME)
OVERFLW("Time","");

return(CONST outer_char*)time_buf;
}
#undef NTIME



#if TIMING

SRTN
ini_timer(VOID)
{
TIME(&time0);
clock0= clock();
}

#endif /* |TIMING| */



#if TIMING

SRTN
prn_time(VOID)
{
TIME_T time1;
double cpu,wall;
char less_than= NO;
char format[100];/* We build the format for the time output here. */

cpu= (clock()-clock0)/(double)(CLOCKS_PER_SEC);
TIME(&time1);

/* Because the real time is in units of seconds, we might get~0, so we'll \
be fancy and print an inequality in that case. */
if((wall= DIFFTIME(time1,time0))==0.0)
{
wall= 1.0;
less_than= YES;
}

SET_COLOR(timing);

/* --- CPU time --- */
sprintf(format,"CPU = %%.%df sec.",TIMING_WIDTH);
printf(format,cpu);
if(cpu>=60.0)printf(" (%.2f min.)",cpu/60.0);

/* --- WALL CLOCK time --- */
sprintf(format,"; REAL %%s %%.%df sec.",TIMING_WIDTH);
printf(format,less_than?"<=":"=",wall);
if(wall>=60.0)printf(" (%.2f min.).",wall/60.0);

/* --- PERCENTAGE CPU UTILIZATION --- */
printf("  CPU/REAL = %.1f%%.\n",100.0*(cpu/wall));

/* Debugging message: Check for compatibility. Because the timing routines \
may not be perfectly compatible through all decimal places, we check only \
that |cpu <= wall| to an accuracy of tenths of seconds. */

SET_COLOR(ordinary);
}

#endif /* |TIMING| */



SRTN
ini_program FCN((program0))
PROGRAM program0 C1("")
{
program= program0;/* Set global flag. */

the_system= OC(THE_SYSTEM);/* |THE_SYSTEM| is defined in \.{os.hweb}. */
local_banner= OC(LOCAL_BANNER);/* See \.{os.hweb} and \.{custom.web}. */

ini_style();/* Default style file initializations. */
}



SRTN
banner(VOID)
{

printf("This is %s",DEBUG_XCHR?"ScRaMbLeD ":"");

printf("%s",program==tangle?"FTANGLE":"FWEAVE");

printf(" [%s version %s (%s)]. %s\n",
(char*)the_system,(char*)version,(char*)release_date,
(char*)local_banner);
}



SRTN
reading FCN((in_name,emit_newline))
CONST outer_char*in_name C0("")
boolean emit_newline C1("")
{
CLR_PRINTF(info,("Reading"));putchar(' ');
CLR_PRINTF(in_file,("%s",(char*)in_name));
CLR_PRINTF(info,("..."));

if(emit_newline)
putchar('\n');
}



SRTN
writing FCN((print_write,out_name))
boolean print_write C0("")
CONST outer_char*out_name C1("")
{
if(print_write)
{CLR_PRINTF(info,("\nWriting"));putchar(' ');}
CLR_PRINTF(out_file,("%s",(char*)out_name));
CLR_PRINTF(info,("..."));
fflush(stdout);
}



SRTN
progress(VOID)
{
if(*(loc-1)==052)
{/* Found a starred section. */
if(err_happened)
{
putchar('\n');
err_happened= NO;
}
else putchar(' ');
CLR_PRINTF(module_num,("*%d",module_count));
}

UPDATE_TERMINAL;
}



int
nsprintf FCN(VA_ALIST((s,fmt,n VA_ARGS)))
VA_DCL(
outer_char*s C0("")
CONST outer_char*fmt C0("")
int n C2(""))
{
int num_char;
VA_LIST(arg_ptr)
#if(NUM_VA_ARGS == 1)
outer_char*s;
CONST outer_char*fmt;
int n;
#endif

VA_START(arg_ptr,n);

#if(NUM_VA_ARGS == 1)
s= va_arg(arg_ptr,outer_char*);
fmt= va_arg(arg_ptr,outer_char*);
va_arg(arg_ptr,int);
#endif

#if ANSI_SPRINTF
num_char= 
#endif

vsprintf((char*)s,(CONST char*)fmt,arg_ptr);

#if !ANSI_SPRINTF
num_char= (int)STRLEN(s);
#endif

va_end(arg_ptr);

return num_char;
}


#endif /* Part 2 */






