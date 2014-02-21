#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06."  \
  COMMAND LINE: "web/ftangle web/fweave -A -# --F -= 1.53/web/fweave.c" \
  RUN TIME: "Saturday, September 23, 1995 at 16:17." \
  WEB FILE:    "web/fweave.web" \
  CHANGE FILE: (none)
#endif
#define _FWEAVE_h  
#define _FWEB_h   \

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

#define ignore  0 /* Control code of no interest to \WEAVE. */
#define verbatim  (eight_bits)02 /* Extended |ASCII| alpha will not appear. */
#define force_line  (eight_bits)03 /* Extended |ASCII| beta will not appear. */ \

#define begin_comment0  (eight_bits)0376 /* Sent from |input_ln|. */
#define begin_comment1  (eight_bits)0375
#define begin_comment  (eight_bits)011 /* |ASCII| tab mark will not appear. */ \

#define compound_assignment  (eight_bits)017 /* Things like `\.{*=}'. */ \
 \
/* Language codes. */
#define L_switch  (eight_bits)0200 /* The generic language switch \.{@L$l$}. */
#define begin_C  (eight_bits)0201
#define begin_RATFOR  (eight_bits)0202
#define begin_FORTRAN  (eight_bits)0203
#define begin_LITERAL  (eight_bits)0204
#define begin_TEX  (eight_bits)0205 \

#define begin_nuweb  (eight_bits)0206 /* Strictly speaking, not a language code. */ \
 \
/* More two-byte combinations that couldn't be fitted below printable \
|ASCII|. */
#define dont_expand  (eight_bits)0210 /* Control code for `\.{\#!}'. */
#define auto_label  (eight_bits)0211 /* Control code for `\.{\#:}'. */
#define all_variable_args  (eight_bits)0212 /* Control code for `\.{\#.}'. */
#define macro_module_name  (eight_bits)0213 /* Control code for `\.{\#<\dots@>}'. */
#define eq_gt  (eight_bits)0214 /* Control code for `\.{=>}'. */
#define colon_colon  (eight_bits)0215 /* Control code for `\.{::}'. */ \
 \
/* Control codes for \FWEB\ commands beginning with \.{@}. */ \
 \
/* The following two codes will be intercepted without confusion, because \
they're processed immediately after an \.{@}, not returned from \
|next_control|. */
#define switch_math_flag  (eight_bits)0175
#define underline  (eight_bits)0176 \

#define xref_roman  (eight_bits)0233 /* control code for `\.{@\^}' */
#define xref_wildcard  (eight_bits)0234 /* control code for `\.{@9}' */
#define xref_typewriter  (eight_bits)0235 /* control code for `\.{@.}' */
#define TeX_string  (eight_bits)0236 /* control code for `\.{@t}' */
#define ascii_constant  (eight_bits)0237 /* control code for `\.{@'}' */
#define join  (eight_bits)0240 /* control code for `\.{@\&}' */
#define thin_space  (eight_bits)0241 /* control code for `\.{@,}' */
#define math_break  (eight_bits)0242 /* control code for `\.{@\char'174}' */
#define line_break  (eight_bits)0243 /* control code for `\.{@/}' */ \

#define big_line_break  (eight_bits)0244 /* control code for `\.{@\#}' */
#define no_line_break  (eight_bits)0245 /* control code for `\.{@~}' */
#define pseudo_semi  (eight_bits)0246 /* control code for `\.{@;}' */
#define defd_at  (eight_bits)0247 /* Control code for `\.['. */ \

#define begin_meta  (eight_bits)0250 /* Control code for |"@("|. */
#define end_meta  (eight_bits)0251 /* Control code for |"@)"|. */ \

#define macro_space  (eight_bits)0252 /* Space token during preprocessing. */
#define copy_mode  (eight_bits)0253 /* Are we copying comments? */ \

#define toggle_output  (eight_bits)0254 /* Turns on and off Weave's output. */
#define turn_output_on  (eight_bits)0254 /* Appended to the scraps for code. */
#define turn_output_off  (eight_bits)0255
#define Turn_output_on  (eight_bits)0256
#define Turn_output_off  (eight_bits)0257 \
 \
/* 260 and 261 are elsewhere. */ \

#define compiler_directive  (eight_bits)0262 /* No longer used. */
#define Compiler_Directive  (eight_bits)0263 /* Control code for `\.{@?}' */
#define new_output_file  (eight_bits)0264 /* Control code for `\.{@o}'. */ \

#define implicit_reserved  (eight_bits)0265 /* Control code for `\.{@]}'. */ \

#define trace  (eight_bits)0266 /* control code for `\.{@0}', `\.{@1}', and `\.{@2}' */ \

#define invisible_cmnt  (eight_bits)0271 /* Control code for `\.{@\%}' */ \

#define pseudo_expr  (eight_bits)0272 /* Control code for `\.{@e}' */
#define pseudo_colon  (eight_bits)0273 /* Control code for `\.{@:}' */ \

#define begin_bp  (eight_bits)0274 /* Control code for `\.{@\lb}'. */
#define insert_bp  (eight_bits)0275 /* Control code for `\.{@b}'. */ \

#define no_index  (eight_bits)0276 /* Control code for `\.{@-}'. */
#define yes_index  (eight_bits)0277 /* Control code for `\.{@~}'. */ \

#define no_mac_expand  (eight_bits)0300 /* Control code for `\.{@!}'. */
#define protect_code  (eight_bits)0301 /* Control code for `\.{@p}'. */
#define set_line_info  (eight_bits)0302 /* Control code for `\.{@q}'. */ \
 \
/* Definition section begun by codes $\ge$~|formatt|. */
#define formatt  (eight_bits)0310 /* control code for `\.{@f}' */ \

#define limbo_text  (eight_bits)0313 /* Control code for `\.{@l}' */
#define op_def  (eight_bits)0314 /* Control code for `\.{@v}' */
#define macro_def  (eight_bits)0315 /* Control code for `\.{@w}'. */ \

#define definition  (eight_bits)0320 /* control code for `\.{@d}' */
#define undefinition  (eight_bits)0321 /* Control code for `\.{@u}'. */
#define WEB_definition  (eight_bits)0322 /* Control code for `\.{@M}' */ \
 \
/* --- Preprocessor commands --- */
#define m_ifdef  (eight_bits)0330
#define m_ifndef  (eight_bits)0331
#define m_if  (eight_bits)0332
#define m_else  (eight_bits)0333
#define m_elif  (eight_bits)0334
#define m_endif  (eight_bits)0335
#define m_for  (eight_bits)0336
#define m_endfor  (eight_bits)0337
#define m_line  (eight_bits)0340
#define m_undef  (eight_bits)0341 \
 \
/* --- Module names --- */
#define begin_code  (eight_bits)0350 /* control code for `\.{@a}' */
#define module_name  (eight_bits)0351 /* control code for `\.{@<}' */ \
 \
/* --- Beginning of new module --- */
#define new_module  (eight_bits)0352 /* control code for `\.{@\ }' and `\.{@*}' */ \
 \

#define constant  (eight_bits)0230 /* \cee\ string or \.{WEB} precomputed string */
#define stringg  (eight_bits)0231 /* \cee\ string or \.{WEB} precomputed string */
#define identifier  (eight_bits)0232 /* \cee\ identifier or reserved word */ \

#define ordinary_space  01 /* Inserted after ctrl sequences, to avoid many \
			visible spcs. */ \

#define left_preproc  (eight_bits)0260 /* Begins a preprocessor command. */
#define right_preproc  (eight_bits)0261 /* Ends a preprocessor command. */ \

#define compress(c)if(loc++<=limit)return(eight_bits)c \

#define COMPOUND(c,n)if(loc<=limit){loc+= n;assignment_token= c; \
return(eight_bits)compound_assignment;} \

#define CA_START  (eight_bits)0100 /* The index into |op| is |CA_START + assignment_token|, \
where |assignment_token| is one of the following. See |valid_op()| for \
further details. */
#define plus_eq  0
#define minus_eq  01
#define star_eq  02
#define slash_eq  03
#define mod_eq  04
#define xor_eq  05
#define and_eq  06
#define or_eq  07
#define gt_gt_eq  010
#define lt_lt_eq  011
#define or_or_or  012 \

#define BINARY_CODE  046 /* `\.{0b10101}' $\to$ `|0b10101|' */
#define OCTAL_CODE  0176 /* `\.{0377}' $\to$ `|0377|' */
#define HEX_CODE  0140 /* `\.{0xabc}' $\to$ `|0xabc|' */ \

#define CONSTANT_CODE  043 /* Various kinds of constants. */
#define FLOAT_CODE  060 /* `\.{50000F}' $\to$ `|50000F|'. */
#define LONG_CODE  061 /* `\.{50000L}' $\to$ `|50000L|' */
#define UNSIGNED_CODE  062 /* `\.{50000U}' $\to$ `|50000U|'. */
#define ULONG_CODE  063 /* `\.{50000UL}' $\to$ `|50000UL|'. */ \

#define EXP_CODE  0136 /* `\.{(x+y)\^(a+b)}' $\to$ `|@r (x+y)^(a+b)|' */
#define HOLLERITH_CODE  045 /* `\.{5Hhello}' $\to$ `|@r 5Hhello|' */ \

#define discretionary_break  (eight_bits)0177
#define NBREAK  25 /* \bf Put into style file? */ \

#define change_params  prms[incl_depth].input_params \

#define KILL_XREFS(name)no_xref|= !defn_mask.name
#define INDEX_SHORT  index_short= index_flag= YES /* Implicit \.{@~}. */ \

#define QUICK_FORMAT  056 /* The shorthand for overloading like itself. */ \

#define CHECK_OPEN  /* This is defined differently in \FTANGLE. */ \

#define OUT_FILE  tex_file
#define C_LINE_WRITE(n) \
fflush(tex_file),FWRITE(out_buf+1,n,tex_file)
#define ASCII_LINE_WRITE(n) \
fflush(tex_file),ASCII_file_write(tex_file,out_buf+1,(size_t)(n))
#define TEX_PUTXCHAR(c)PUTC(c)/* Send an |outer_char| to the \.{TEX} file. */
#define TEX_NEW_LINE  PUTC('\n')/* A newline to the \.{TEX} file. */
#define TEX_PRINTF(s)fprintf(tex_file,s)/* A string to the \.{TEX} file. */ \

#define out(c) \
{ \
if(out_ptr>=out_end) \
break_out(); \
*(++out_ptr)= (ASCII)(c); \
} \

#define OUT_STR(s)out_str(OC(s)) \

#define IDENTIFIER  YES
#define INDEX_ENTRY  NO \

#define app_tok(c){if(tok_ptr+2>tok_m_end) \
OVERFLW("tokens","tw"); \
app(c);} \

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

#define app_scrap(c,b) \
(++scrp_ptr)->cat= (eight_bits)(c); \
scrp_ptr->trans= text_ptr; \
scrp_ptr->mathness= (eight_bits)(5*(b));/* Make left and right \
		boundaries equal. */ \
freeze_text \

#define INIT_OP(op_code,op_name,lang,op_macro,cat) \
init_op((eight_bits)(op_code),OC(op_name),(int)(lang),OC(op_macro), \
NO,cat,(CONST outer_char*)NULL) \
 \
/* Initialize a compound assignment operator such as~`\.{+=}'. */
#define INIT_CA(ca_index,op_name,lang,op_macro,cat) \
assignment_token= ca_index; \
INIT_OP(compound_assignment,OC(op_name),(int)(lang),OC(op_macro),cat) \
 \
/* Initialize a dot operator such as~`\.{.NE.}'. */
#define INIT_DOT(op_name,lang,op_macro,cat) \
init_op((eight_bits)identifier,OC(op_name),(int)(lang),OC(op_macro), \
NO,cat,(CONST outer_char*)NULL) \

#define ALL_LANGUAGES  ((int)C|(int)C_PLUS_PLUS|(int)FORTRAN|(int)FORTRAN_90 \
|(int)(RATFOR)|(int)(RATFOR_90)|(int)LITERAL) \

#define ONLY_C_like  ((int)C|(int)C_PLUS_PLUS)
#define ALL_BUT_C_like  (~ONLY_C_like)
#define ALL_BUT_Cpp  ((int)C|(int)FORTRAN|(int)FORTRAN_90 \
|(int)(RATFOR)|(int)(RATFOR_90)|(int)LITERAL) \

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
#define inner  0 /* Value of |mode| for \cee\ texts within \TeX\ texts */
#define outer  1 /* Value of |mode| for \cee\ texts in modules */ \

#define cur_end  cur_state.end_field /* Current ending location in |tok_mem| */
#define cur_tok  cur_state.tok_field /* Location of next output token in |tok_mem| */
#define cur_mode  cur_state.mode_field /* Current mode of interpretation */
#define ini_stack  stck_ptr= stack;cur_mode= outer /* Initialize the stack */ \

#define res_word  (eight_bits)0201 /* Returned by |get_output| for reserved words */
#define mod_name  (eight_bits)0200 /* Returned by |get_output| for module names */ \

#define ALL_UC  (all_uc&&length(cur_name)>1) \
 \

#define language_name_ptr(l)languages[lan_num(l)]/* Points to the full \
					language name. */
#define language_symbol(l) \
(l!=global_language?LANGUAGE_CODE(l):(CONST outer_char*)"") \

#define save_position  save_line= out_line;save_place= out_ptr
#define emit_space_if_needed  if(save_line!=out_line||save_place!=out_ptr) \
{ \
OUT_STR("\\WY"); \
 \
yskipped= YES; \
} \

#define SUPPRESS(name)if(!defn_mask.name)suppress_defn= YES \

#define APP_TEMP(letter,arg)app_temp(OC(letter),OC(arg)) \

#define APP_LANG(suffix)app_lang(OC(suffix)) \

#define NEW_TeX(file_name) \
if(tex_file!=stdout) \
{ \
fclose(tex_file); \
if((tex_file= FOPEN(file_name,"w"))==NULL) \
FATAL(W,"! Can't open output file ",file_name); \
} \

#define N_CMD  1000 \

#define TO_TEMP(val)if(temp<temp_end)*temp++= val; \
else OVERFLW("Esc_buf:temp","") \

#define depth  cat /* reclaims memory that is no longer needed for parsing */
#define head  trans_plus.Head /* ditto */
#define sort_pointer  scrap_pointer /* ditto */
#define sort_ptr  scrp_ptr /* ditto */
#define max_sorts  max_scraps /* ditto */ \

#define INFTY  255 /* $\infty$ (approximately). */ \

#define NON_TEX_MACRO  '\1' \

#define ENCAP  YES
#define NO_ENCAP  NO \




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


/* Defines |part|. */


#include "typedefs.h"






#include "map.h" /* Relations between style file keywords and internal arrays. */




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


name_pointer Head;


}trans_plus;
}scrap;

typedef scrap HUGE*scrap_pointer;



typedef int mode;

typedef struct{
token_pointer end_field;/* Ending location of token list */
token_pointer tok_field;/* Present location within token list */
boolean mode_field;/* Interpretation of control tokens */
}output_state;

typedef output_state HUGE*stack_pointer;




#include "w_type.h" /* Function prototypes for \FWEAVE. */





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



IN_STYLE eight_bits ccode[128];
/* Meaning of an |ASCII| char following '\.{@}'. */



EXTERN name_pointer cur_module;/* Name of module just scanned. */
EXTERN int math_flag SET(NO);
EXTERN boolean chk_end SET(YES);/* Do we check for end of line? */
EXTERN boolean last_was_cmnt SET(NO);/* Helps with interchanging \
					semicolons and comments. */
EXTERN boolean lst_ampersand SET(NO);/* For continuations in \
		free-form syntax \Fortran-90. */
EXTERN boolean eat_blank_lines SET(NO);/* For Nuweb mode. */

EXTERN ASCII c;/* The current character for |get_next|. */



EXTERN eight_bits assignment_token;/* The particular one of the above \
			compound assignment tokens. */



EXTERN boolean insert_breaks SET(YES);/* No breaks inserted during limbo \
			text processing. */



EXTERN boolean doing_cdir SET(NO);



EXTERN eight_bits next_control;/* control code waiting to be acting upon */



IN_COMMON outer_char wbprefix[MAX_FILE_NAME_LENGTH];
EXTERN boolean do_inside;/* Cross-reference stuff inside a \&{typedef}? */
EXTERN boolean qtd_file;/* Is the include file quoted? */

#ifndef L_tmpnam
#define L_tmpnam 25
#endif

EXTERN outer_char temp_in[L_tmpnam],temp_out[L_tmpnam];
/* Names of temporary files used in |get_iformats|. */



EXTERN name_pointer lhs,rhs;/* pointers to |byte_start| for format \
				identifiers */



EXTERN boolean unnamed_section SET(NO);



EXTERN xref_pointer cur_xref;/* temporary cross-reference pointer */



EXTERN BUF_SIZE line_length;
EXTERN ASCII HUGE*out_buf;/* Assembled characters. */
EXTERN ASCII HUGE*out_end;/* End of |out_buf|. */

EXTERN ASCII HUGE*out_ptr;/* Points to last character in |out_buf|. */
EXTERN LINE_NUMBER out_line;/* number of next line to be output. */



EXTERN boolean output_on SET(YES);



EXTERN boolean strt_off SET(NO),ending_off SET(NO);



EXTERN boolean in_comment;



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



EXTERN boolean scanning_meta SET(NO);



EXTERN boolean overloaded[NUM_LANGUAGES];

EXTERN BUF_SIZE op_entries;/* Length for dynamic array. */
EXTERN OPERATOR HUGE*op,HUGE*op_end;/* Dynamic array of entries for \
			operator overloading. */
EXTERN OPERATOR HUGE*op_ptr;/* Next open position in |OP|. */



EXTERN eight_bits last_control;



EXTERN output_state cur_state;/* |cur_end|, |cur_tok|, |cur_mode| */

EXTERN BUF_SIZE stck_size;
EXTERN output_state HUGE*stack;/* Dynamic array of info for non-current \
					levels */
EXTERN stack_pointer stck_end;/* End of |stack| */

EXTERN stack_pointer stck_ptr;/* First unused location in the output \
				state stack */
EXTERN stack_pointer mx_stck_ptr;/* Largest value assumed by |stck_ptr| */



EXTERN name_pointer cur_name;



EXTERN LINE_NUMBER save_line;/* Former value of |out_line|. */
EXTERN ASCII HUGE*save_place;/* Former value of |out_ptr|. */
EXTERN boolean in_module SET(NO);/* Between \.{\\WN} and \.{\\fi}? */
EXTERN boolean yskipped SET(NO);/* Did we skip between parts? */



IN_COMMON outer_char last_include_file[],this_include_file[];



EXTERN boolean ok_to_define SET(YES);
EXTERN boolean q_protected SET(NO);/* For protecting with quotes. */
EXTERN boolean suppress_defn SET(NO);/* For masking out formats, etc. */
EXTERN boolean output_protect SET(NO);/* For writing \.{\\protect}. */



EXTERN name_pointer this_module;/* The current module name, or zero. */
EXTERN name_pointer the_module;/* The module we're working on; equal to \
	|cur_module| at the beginning of the entire module. */



EXTERN xref_pointer next_xref,this_xref,first_xref,mid_xref;
/* Pointer variables for rearranging a list */



EXTERN sixteen_bits k_module;/* Runs through the modules */



EXTERN name_pointer bucket[128];/* One for each standard |ASCII char|. */
EXTERN name_pointer next_name;/* Successor of |cur_name| when sorting */
IN_COMMON hash_pointer h;/* Index into |hash| */

IN_COMMON BUF_SIZE max_names;/* number of identifiers, strings, module names; \
  must be less than~10240 */
EXTERN name_pointer HUGE*blink;/* Links in the buckets */
EXTERN ASCII last_letter SET('\0');/* Used for separating groups in the \
					index. */



EXTERN eight_bits cur_depth;/* Depth of current buckets */
EXTERN ASCII HUGE*cur_byte;/* Index into |byte_mem| */
EXTERN sixteen_bits cur_val;/* Current cross-reference number */

EXTERN sort_pointer mx_sort_ptr;/* largest value of |sort_ptr| */



EXTERN ASCII collate[128];/* collation order. */
EXTERN int max_collate;/* Last index in |collate|. */



/* For pc's, the file is split into three compilable parts using the \
compiler-line macro |part|, which must equal either~1, 2, or~3. */
#if(part == 0 || part == 1)


int main FCN((ac,av))
int ac C0("Number of command-line arguments.")
outer_char**av C1("Array of pointers to command-line arguments.")
{
/* --- Various initializations --- */
#if TIMING
ini_timer();/* Start timing the run. */
#endif /* |TIMING| */

argc= ac;argv= av;/* Remember the arguments as global variables. */

ini_program(weave);

common_init();




ALLOC(xref_info,xmem,"r",max_refs,0);
xmem_end= xmem+max_refs-1;



ALLOC(Token,tok_mem,"tw",max_toks,1);
tok_mem++;/* In some unusual circumstances, there may be references to \
		|tok_mem[-1]|, so be sure it exists. */
tok_m_end= tok_mem+max_toks-1;/* End of |tok_mem|./ */

ALLOC(token_pointer,tok_start,"x",max_texts,0);
tok_end= tok_start+max_texts-1;/* End of |tok_start|. */



ALLOC(ASCII,out_buf,"ll",line_length,1);/* assembled \
							characters */
out_end= out_buf+line_length;/* end of |out_buf| */



ALLOC(scrap,scrp_info,"s",max_scraps,0);
scrp_end= scrp_info+max_scraps-1;/* end of |scrp_info| */


{
int l;

for(l= 0;l<NUM_LANGUAGES;l++)
overloaded[l]= NO;

ALLOC(OPERATOR,op,"op",op_entries,0);
op_end= op+op_entries;
op_ptr= op+128;/* The first 128 are for direct indexing. */



INIT_OP(041,"NOT",ALL_LANGUAGES,"\\WR",unop);/* `|!|' */
INIT_DOT("NOT",ALL_BUT_C_like,"\\WR",unop);


INIT_OP(045,"MOD",ALL_LANGUAGES,"\\MOD",binop);/* `|%|' */


INIT_OP(046,"LAND",C,"\\amp",unorbinop);/* `|&|'. */
INIT_OP(046,"LAND",C_PLUS_PLUS,"\\amp",reference);

INIT_OP(046,"LAND",ALL_BUT_C_like,"\\AND",binop);/* `|@r &|' */


INIT_OP(052,"STAR",ALL_LANGUAGES,"\\ast",unorbinop);/* `|*|' */

INIT_OP(053,"PLUS",ALL_LANGUAGES,"+",unorbinop);/* `|+|' */
INIT_OP(055,"MINUS",ALL_LANGUAGES,"-",unorbinop);/* `|-|' */
INIT_OP(057,"SLASH",ALL_LANGUAGES,"/",binop);/* `|/|' */

INIT_OP(074,"LT",ALL_BUT_Cpp,"<",binop);/* `|<|' */
INIT_OP(074,"LT",C_PLUS_PLUS,"<",langle);/* `|<|' */
INIT_DOT("LT",ALL_BUT_C_like,"<",binop);


INIT_OP(075,"EQUALS",ALL_LANGUAGES,"=",binop);/* `|=|' */

INIT_OP(076,"GT",ALL_BUT_Cpp,">",binop);/* `|>|' */
INIT_OP(076,"GT",C_PLUS_PLUS,">",rangle);/* `|>|' */
INIT_DOT("GT",ALL_BUT_C_like,">",binop);


INIT_OP(077,"QUESTION",ONLY_C_like,"\\?",question);/* `|?|' */

INIT_OP(0136,"CARET",ALL_LANGUAGES,"\\^",binop);/* `|x^y|' */


INIT_OP(0174,"OR",ALL_LANGUAGES,"\\OR",binop);/* `$\OR$' */

INIT_OP(0176,"TILDE",ONLY_C_like,"\\TLD",unop);


INIT_OP(not_eq,"NE",ALL_LANGUAGES,"\\WI",binop);/* `|!=|' */
INIT_DOT("NE",ALL_BUT_C_like,"\\WI",binop);


INIT_OP(lt_eq,"LE",ALL_LANGUAGES,"\\WL",binop);/* `|<=|' */
INIT_DOT("LE",ALL_BUT_C_like,"\\WL",binop);


INIT_OP(gt_eq,"GE",ALL_LANGUAGES,"\\WG",binop);/* `|>=|' */
INIT_DOT("GE",ALL_BUT_C_like,"\\WG",binop);


INIT_OP(eq_eq,"EQ",ALL_LANGUAGES,"\\WS",binop);/* `|==|' */
INIT_DOT("EQ",ALL_BUT_C_like,"\\WS",binop);


INIT_OP(and_and,"AND",ALL_LANGUAGES,"\\WW",binop);/* `|&&|' */
INIT_DOT("AND",ALL_BUT_C_like,"\\WW",binop);


INIT_OP(or_or,"OR",ALL_LANGUAGES,"\\WV",binop);/* `||| |' */
INIT_DOT("OR",ALL_BUT_C_like,"\\OR",binop);


INIT_OP(plus_plus,"PP",ALL_LANGUAGES,"\\PP",unop);/* `|++|' */

INIT_OP(minus_minus,"MM",ALL_LANGUAGES,"\\MM",unop);/* `|--|' */


INIT_OP(minus_gt,"EQV",ONLY_C_like,"\\MG",binop);/* `|->|' */

INIT_OP(minus_gt,"EQV",ALL_BUT_C_like,"\\EQV",binop);/* `|@r .eqv.|' */
INIT_DOT("EQV",ALL_BUT_C_like,"\\EQV",binop);


INIT_OP(gt_gt,"RSHIFT",ONLY_C_like,"\\GG",binop);/* `|>>|' */

INIT_OP(lt_lt,"LSHIFT",ONLY_C_like,"\\LL",binop);/* `|<<|' */

INIT_OP(star_star,"EE",ALL_LANGUAGES,"\\EE",exp_op);/* `\.{**}' */

INIT_OP(slash_slash,"SlSl",ALL_BUT_C_like,"\\SlSl",binop);/* `|@r \/|' */


INIT_OP(ellipsis,"NEQV",ALL_BUT_C_like,"\\NEQV",binop);/* `|@r .NEQV.|' */
INIT_DOT("NEQV",ALL_BUT_C_like,"\\NEQV",binop);
INIT_DOT("XOR",ALL_BUT_C_like,"\\NEQV",binop);


INIT_DOT("FALSE",ALL_BUT_C_like,"\\FALSE",expr);/* `|@r .false.|' */

INIT_DOT("TRUE",ALL_BUT_C_like,"\\TRUE",expr)/* `|@r .true.|' */


;


INIT_CA(plus_eq,"Wcp",ALL_LANGUAGES,"\\Wcp",binop);/* `|+=|' */

INIT_CA(minus_eq,"Wcm",ALL_LANGUAGES,"\\Wcm",binop);/* `|-=|' */

INIT_CA(star_eq,"Wcs",ALL_LANGUAGES,"\\Wcs",binop);/* `|*=|' */

INIT_CA(slash_eq,"Wcv",ALL_LANGUAGES,"\\Wcv",binop);/* `|/=|' */

INIT_CA(mod_eq,"Wcd",ONLY_C_like,"\\Wcd",binop);/* `|%=|' */

INIT_CA(xor_eq,"Wcx",ONLY_C_like,"\\Wcx",binop);/* `|^=|' */

INIT_CA(and_eq,"Wca",ONLY_C_like,"\\Wca",binop);/* `|&=|' */

INIT_CA(or_eq,"Wco",ONLY_C_like,"\\Wco",binop);/* `||=|' */

INIT_CA(gt_gt_eq,"Wcg",ONLY_C_like,"\\Wcg",binop);/* `|>>=|' */

INIT_CA(lt_lt_eq,"Wcl",ONLY_C_like,"\\Wcl",binop)/* `|<<=|' */


;
}



ALLOC(output_state,stack,"kw",stck_size,0);
stck_end= stack+stck_size-1;/* End of |stack| */



ALLOC(name_pointer,blink,"n",max_names,0);





name_dir->xref= (XREF_POINTER)(xref_ptr= xmem);
xref_switch= mod_xref_switch= defd_switch= index_short= NO;
xmem->num= 0;/* Cross-references to undefined modules. */




{
tok_ptr= tok_mem+1;
tok_start[0]= tok_start[1]= tok_ptr;
text_ptr= tok_start+1;
}


mx_tok_ptr= tok_ptr;mx_text_ptr= text_ptr;



zero_ccodes();/* See \.{style.web}. */
ccode[057]= line_break;/* The commenting style is also fundamental, and \
	for convenience the |line_break| command is also inviolate. */


{

ini_ccode((outer_char*)"new_module",(outer_char*)" \t*",new_module);/* Either space, tab, or asterisk. */


ini_ccode((outer_char*)"begin_code",(outer_char*)"aA",begin_code);

ini_ccode((outer_char*)"module_name",(outer_char*)"<",module_name);


ini_ccode((outer_char*)"definition",(outer_char*)"dD",definition);

ini_ccode((outer_char*)"undefinition",(outer_char*)"uU",undefinition);

ini_ccode((outer_char*)"WEB_definition",(outer_char*)"mM",WEB_definition);

ini_ccode((outer_char*)"formatt",(outer_char*)"fF",formatt);


ini_ccode((outer_char*)"toggle_output",(outer_char*)"\001",toggle_output);/* This command is for internal use only! */


ini_ccode((outer_char*)"ascii_constant",(outer_char*)"'\"",ascii_constant);

ini_ccode((outer_char*)"verbatim",(outer_char*)"=",verbatim);

ini_ccode((outer_char*)"line_break",(outer_char*)"\\",line_break);


ini_ccode((outer_char*)"TeX_string",(outer_char*)"tT",TeX_string);


ini_ccode((outer_char*)"L_switch",(outer_char*)"L",L_switch);

ini_ccode((outer_char*)"begin_C",(outer_char*)"cC",begin_C);

ini_ccode((outer_char*)"begin_RATFOR",(outer_char*)"rR",begin_RATFOR);

ini_ccode((outer_char*)"begin_FORTRAN",(outer_char*)"n",begin_FORTRAN);

ini_ccode((outer_char*)"begin_nuweb",(outer_char*)"N",begin_nuweb);

ini_ccode((outer_char*)"begin_TEX",(outer_char*)"xX",begin_TEX);


ini_ccode((outer_char*)"join",(outer_char*)"&",join);

ini_ccode((outer_char*)"underline",(outer_char*)"_",underline);

ini_ccode((outer_char*)"defd_at",(outer_char*)"[",defd_at);

ini_ccode((outer_char*)"implicit_reserved",(outer_char*)"`]",implicit_reserved);


ini_ccode((outer_char*)"invisible_cmnt",(outer_char*)"%",invisible_cmnt);

ini_ccode((outer_char*)"Compiler_Directive",(outer_char*)"?",Compiler_Directive);


ini_ccode((outer_char*)"switch_math_flag",(outer_char*)"$",switch_math_flag);


ini_ccode((outer_char*)"xref_roman",(outer_char*)"^",xref_roman);

ini_ccode((outer_char*)"xref_typewriter",(outer_char*)".",xref_typewriter);

ini_ccode((outer_char*)"xref_wildcard",(outer_char*)"9",xref_wildcard);

{
char temp[3];

sprintf(temp,";%c",XCHR(interior_semi));

ini_ccode((outer_char*)"pseudo_semi",(outer_char*)temp,pseudo_semi);
}


ini_ccode((outer_char*)"pseudo_expr",(outer_char*)"e",pseudo_expr);

ini_ccode((outer_char*)"pseudo_colon",(outer_char*)":",pseudo_colon);


ini_ccode((outer_char*)"limbo_text",(outer_char*)"l",limbo_text);

ini_ccode((outer_char*)"op_def",(outer_char*)"vV",op_def);

ini_ccode((outer_char*)"macro_def",(outer_char*)"wW",macro_def);


ini_ccode((outer_char*)"thin_space",(outer_char*)",",thin_space);

ini_ccode((outer_char*)"math_break",(outer_char*)"|",math_break);

ini_ccode((outer_char*)"big_line_break",(outer_char*)"#",big_line_break);

ini_ccode((outer_char*)"no_line_break",(outer_char*)"~",no_line_break);


ini_ccode((outer_char*)"begin_meta",(outer_char*)"(",begin_meta);

ini_ccode((outer_char*)"end_meta",(outer_char*)")",end_meta);


ini_ccode((outer_char*)"new_output_file",(outer_char*)"oO",new_output_file);


ini_ccode((outer_char*)"begin_bp",(outer_char*)"{",begin_bp);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"}bB",USED_BY_OTHER);

ini_ccode((outer_char*)"no_mac_expand",(outer_char*)"!",no_mac_expand);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"q",USED_BY_OTHER);


ini_ccode((outer_char*)"no_index",(outer_char*)"-",no_index);

ini_ccode((outer_char*)"yes_index",(outer_char*)"+",yes_index);


ini_ccode((outer_char*)"protect_code",(outer_char*)"p",protect_code);



#if(DEBUG)

ini_ccode((outer_char*)"trace",(outer_char*)"012",trace);
#endif /* |DEBUG| */


}


prn_codes();



mod_text[0]= 040;


{
out_ptr= out_buf;out_line= 1;

if(input_macros)
{
TEX_PRINTF("\\input ");
OUT_STR(*fwebmac?fwebmac:w_style.misc.macros);/* The command \
line overrides the style file. */
}
}



out_buf[0]= 0134;



scrp_base= scrp_info+1;

mx_scr_ptr= scrp_ptr= scrp_info;



mx_stck_ptr= stack;



mx_sort_ptr= scrp_info;




collate[0]= 0;

;

/* --- Do the processing --- */
phase1();/* read all the user's text and store the cross-references */
phase2();/* read all the text again and translate it to \TeX\ form */
phase3();/* output the cross-reference index */

/* --- Finish up --- */
if(statistics)see_wstatistics();/* Invoked by command-line option~\.{-s}. */

return wrap_up();/* We actually |exit| from here. */
}






SRTN open_tex_file(VOID)
{
if(STRCMP(tex_fname,"stdout")==0)tex_file= stdout;
else if((tex_file= FOPEN(tex_fname,"w"))==NULL)
FATAL(W,"!! Can't open output file ",tex_fname);
else
{
fprintf(tex_file,"%% FWEAVE v%s (%s)\n\n",
(char*)version,(char*)release_date);
}



}



SRTN new_xref FCN((part0,p))
PART part0 C0("")
name_pointer p C1("")
{
xref_pointer q;/* Pointer to previous cross-reference. */
sixteen_bits m,n;/* New and previous cross-reference value. */

if(index_flag==NO)
{
SET_TYPE(p,DEFINED_TYPE(p)|0x80);
index_flag= BOOLEAN(!(language==LITERAL));
}

/* Do nothing if we're not supposed to cross-reference. Also do nothing if \
we're inside a \&{format} statement. This is a bit kludgy, but it works. */
if(!index_flag||!(output_on||index_hidden)||in_format
||(unnamed_section&&!xref_unnamed))
return;/* The |output_on| flag	here prevents index entries for \
		modules skipped with~\.{-i}. */

index_flag= BOOLEAN(!(language==LITERAL));

/* Say where the identifier is defined (but not if it's a reserved word). */
if(defd_switch&&(part0==DEFINITION
||!(is_reserved(p)||is_intrinsic(p)||is_keyword(p))))
{
sixteen_bits mod_defined= p->defined_in(language);

if(mod_defined&&mod_defined!=module_count)
{

err0_print(ERR_W,OC("Identifier in %s was already explicitly \
or implicitly marked via @[ as defined in %s"),2,MOD_TRANS(module_count),MOD_TRANS(mod_defined));
mark_harmless;
}

p->defined_in(language)= module_count;
defd_switch= NO;
}

if(defd_type!=NEVER_DEFINED)
SET_TYPE(p,defd_type);/* Used to be up in previous block. */

defd_type= NEVER_DEFINED;

if(xref_switch==NO
&&(is_reserved(p)||((!index_short)&&(length(p)==1))))
return;

if(index_short)
index_short= NO;

if(no_xref)
return;/* The result of the \.{-x} flag. */

m= module_count+xref_switch;
xref_switch= NO;
q= (xref_pointer)p->xref;

if(!(do_inside||all_includes||(quoted_includes&&qtd_file)))
goto check_implicit;/* Skip if reading an include file. */

if(q!=xmem)
{/* There's already an entry. */
n= q->num;

if(n==m||n==m+def_flag)
goto check_implicit;
/* Discard duplicates within the same module. */
else if(m==n+def_flag)
{
q->num= m;/* Update the entry to be defined instead of \
just used. */
goto check_implicit;
}
}

/* There's no entry yet; make a new cross-reference. */
append_xref(m);

/* Link in; highest module number is first. */
xref_ptr->xlink= q;p->xref= (XREF_POINTER)xref_ptr;

check_implicit:
if(typd_switch)

{
NAME_INFO rs_wd;
name_pointer lhs= p,rhs= &rs_wd;

rhs->ilk= int_like;
rhs->reserved_word= rhs->Language= BOOLEAN(language);
rhs->intrinsic_word= rhs->keyword= NO;


{
lhs->ilk= rhs->ilk;

/* First turn off the old lhs bit (retaining all others), then add in the \
new bit for the current language. */
#define RST_BIT(field) lhs->field =  BOOLEAN(lhs->field & ~(boolean)language)\
  | (rhs->field & (boolean)language)

RST_BIT(reserved_word);
RST_BIT(Language);
RST_BIT(intrinsic_word);
RST_BIT(keyword);

#undef RST_BIT
}




/* Make all previous entries register as defined, not just used. */
for(q= (xref_pointer)p->xref;q>xmem;q= q->xlink)
if(q->num<def_flag)q->num+= def_flag;

typd_switch= NO;
}


}



SRTN new_mod_xref FCN((p))
name_pointer p C1("")
{
xref_pointer q,r;/* pointers to previous cross-references */


q= (xref_pointer)p->xref;r= xmem;

if(q>xmem)
{
/* ``Used in module...'' Scan past all the definitions. */
if(mod_xref_switch==NO)
while(q->num>=def_flag)
{
r= q;q= q->xlink;
}
else /* Defining...*/
if(q->num>=def_flag)
{
r= q;q= q->xlink;
}
}

/* Discard duplicate ``used in'' xref. */
if(mod_xref_switch==NO&&q->num==module_count)
return;

append_xref(module_count+mod_xref_switch);
xref_ptr->xlink= q;mod_xref_switch= NO;

if(r==xmem)
p->xref= (XREF_POINTER)xref_ptr;
else
r->xlink= xref_ptr;
}




boolean names_match FCN((p,first,l,t))
name_pointer p C0("Points to the proposed match.")
CONST ASCII HUGE*first C0("Position of first character of string.")
int l C0("Length of identifier.")
eight_bits t C1("Desired ilk.")
{
if(length(p)!=l)return NO;/* Speedy return. */

if((p->Language&(boolean)language)&&(p->ilk!=t)&&!(t==normal&&
is_reserved(p)))
return NO;

return(boolean)(!STRNCMP(first,p->byte_start,l));
}



SRTN ini_p FCN((p,t))
name_pointer p C0("")
eight_bits t C1("")
{
CONST ASCII HUGE*k;

p->ilk= t;p->xref= (XREF_POINTER)xmem;

/* Check if identifier is all upper-case. */
p->info.upper_case= NO;

for(k= p->byte_start;k<byte_ptr;k++)
if(isAlpha(*k)&&!isAupper(*k))
return;

p->info.upper_case= YES;
}

SRTN ini_node FCN((node))
CONST name_pointer node C1("")
{
node->xref= (XREF_POINTER)xmem;


{
/* We allocate |MOD_INFO| structures only for module names, not for \
	identifiers. */
node->mod_info= GET_MEM("mod_info",1,MOD_INFO);

node->mod_info->Ilk= expr;
node->mod_info->params= params;/* Freeze parameters at this point in time. */

node->Language= (boolean)language;/* Redundant. */
}



}




SRTN skip_limbo(VOID)
{
WHILE()
{
if(loc>limit&&!get_line())return;

*(limit+1)= 0100;/* Guard character. */

/* Look for '@', then skip two chars. */
while(*loc!=0100)loc++;

/* |loc| now on the \.{@}. */
if(loc++<=limit)
switch(ccode[*loc++])
{/* Process any language change \
commands; skip any other @~commands. */




case begin_C:
case begin_RATFOR:
case begin_FORTRAN:
case begin_LITERAL



:
loc--;/* Position to letter after \.{@}. Falls \
through to general case |L_switch|. */

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




if(module_count==0)
global_params= params;

ini0_language();


if(Fortran88&&auto_semi)
{
loc= limit+1;
chk_end= NO;
}



}


break;

case begin_nuweb:
nuweb_mode= !NUWEB_MODE;

if(module_count==0)
global_params= params;
break;



case invisible_cmnt:
loc= limit+1;
break;

case new_module:
return;/* End of limbo section. */
}

}
}



eight_bits skip_TeX(VOID)
{
WHILE()
{
if(loc>limit&&!get_line())return new_module;

*(limit+1)= 0100;/* Marker to curtail the scan. */

while(*loc!=0100&&*loc!=0174)loc++;

if(*loc++==0174)return 0174;/* Have hit beginning of code mode. */

if(loc<=limit)
{
SET_CASE(*loc);
return ccode[*(loc++)];
}
}

DUMMY_RETURN(0);
}



eight_bits get_next(VOID)/* produces the next input token */
{
boolean terminate= NO;
char terminator[2];
GOTO_CODE pcode;/* Return from the parsing functions.  0~means |continue|. */

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
with~|'#'|, with no intervening blanks. */
return(eight_bits)prs_regular_code(GOTO_GET_IDENTIFIER);
}

;


chk_the_end:
if(chk_end)
{
/* Continue to next line; also skip all lines that have continuation \
character in column~1. */
while(*loc==cont_char&&loc==limit-1&&(preprocessing||free_Fortran))
if(!get_line())
return new_module;/* still in preprocessor mode */

/* Now we've gotten to the end of line, but it's not continued. */
if(loc>=limit)
if(preprocessing)
{
chk_end= preprocessing= sharp_include_line= sharp_pragma_line= NO;
return right_preproc;
}
else if(Fortran88
&&parsing_mode==OUTER
&&auto_semi&&limit>cur_buffer
&&!(limit[0]==0100&&limit[1]==0155))
{
loc= limit+1;
chk_end= NO;
if(last_was_cmnt)
{/* Comment has already been appended. */
last_was_cmnt= NO;
if(lst_ampersand)
{/* Deal with continuation before comment. */
lst_ampersand= NO;
chk_end= YES;
if(!get_line())
{

err0_print(ERR_W,OC("Section ended in middle of Fortran-90 continuation"),0);
return new_module;
}
APP_STR("\\indent");
goto chk_the_end;
}
continue;
}
}
}

;

chk_end= YES;



if(loc>limit)
{
if(terminate)
{
terminator[0]= *limit;terminator[1]= *(limit+1);
}

if(!get_line())
return(new_module);

if(eat_blank_lines)
{/* Avoid empty stuff at end of module in Nuweb mode. */

{
while(loc>=limit)
if(!get_line())
{
eat_blank_lines= NO;
return(new_module);
}
}


eat_blank_lines= NO;
}

if(parsing_mode==OUTER)
at_beginning= YES;/* Start of new line. */

if(terminate)
{
*limit= terminator[0];*(limit+1)= terminator[1];
terminate= NO;
}
}
else if(parsing_mode==OUTER)at_beginning= NO;




if(preprocessing)

{
do
{
if((c= *loc++)!=040||c!=tab_mark)
break;
}
while(loc<limit);

if(c==040||c==tab_mark)
return macro_space;
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

if(nuweb_mode)
{
if(!(c==0100&&*loc==043))
{/* Go back to beginning. */
loc= loc0;
c= *loc++;
if(phase==1&&c==tab_mark)
c= 040;
}
}
}
}




if(c==cont_char&&loc==limit)
{
if(preprocessing||free_Fortran)loc--;/* IFFY */
else loc++;

terminate= YES;
continue;
}



/* Handle an (effectively) empty line. (Don't move this statement upwards.) */
if(limit==cur_buffer||(at_beginning&&loc>limit))
return big_line_break;

switch(language)
{
case TEX:
if((pcode= prs_TeX_code())==MORE_PARSE)
break;
else if((int)pcode<0)
CONFUSION("prs_TEX_code","Negative pcode");
else
goto found_something;

default:
if((pcode= prs_regular_code(MORE_PARSE))==MORE_PARSE)
break;
else if((int)pcode<0)
CONFUSION("prs_regular_code",
"Negative pcode");
else
goto found_something;
}
}

found_something:
/* We need the following stuff to handle the |INNER| parsing mode properly. \
(|at_beginning| doesn't correspond to physical beginning of line, so can't \
be reset by |get_line()|.) */
if(!preprocessing)
switch((eight_bits)pcode)
{
case begin_language:
break;

default:
at_beginning= NO;
break;
}

return(eight_bits)pcode;
}


GOTO_CODE prs_TeX_code(VOID)
{
GOTO_CODE icode;/* Return code from |get_control_code|. */

if(loc>limit)
return 073;

if(c==0100)
{/* The next call takes care of a branch to |mistake|. */
if((icode= get_control_code())==GOTO_MISTAKE)
return prs_regular_code(GOTO_MISTAKE);
else
return icode;
}
else if(TeX[c]==TeX_comment)
{
long_comment= YES;/* Since we may concatenate lines. */
return begin_comment;
}
else if(c==0174&&parsing_mode==INNER)
return 0174;
else
if(phase==1)
{
if(TeX[c]==TeX_escape)

{
id_first= id_loc= mod_text+1;

*id_loc++= *(loc-1);/* The beginning backslash. */

if(TeX[*loc]!=TeX_letter)
{/* Single-character macro, such as~`\.{\\<}'. */
if(*loc==0100)
{
if(*(loc+1)!=0100)
err0_print(ERR_W,OC("You should say `\\@@'"),0);
else loc++;
}
*id_loc++= *loc++;/* The single character. */
}
else while(TeX[*loc]==TeX_letter)
{/* Scan over the macro name. */
if(*loc==0100)
{
if(*(loc+1)!=0100)
err0_print(ERR_W,OC("You should say `@@'"),0);
else loc++;
}
*id_loc++= *loc++;
}

return identifier;
}


else
return MORE_PARSE;
}
else

{
loc--;
id_first= id_loc= mod_text+1;

while(loc<limit)
{
if(*loc==0100)
if(*(loc+1)==0100)*id_loc++= *loc++;
else break;/* Scan ended by control code. */

if(TeX[*loc]==TeX_comment)break;
if(*loc==0174&&parsing_mode==INNER)break;/* End of internal mode. */

if(TeX[*loc]==TeX_escape)
{
if(TeX[*(loc+1)]!=TeX_letter)
{/* One-character control sequence. */
if(*(loc+1)==0100)
if(*(loc+2)!=0100)

err0_print(ERR_W,OC("You should say \\@@"),0);
else*id_loc++= *loc++;

*id_loc++= *loc++;
}
else
{/* Ordinary control sequence. */
do
*id_loc++= *loc++;
while(TeX[*loc]==TeX_letter);

while(loc<limit)
{
if(TeX[*loc]!=TeX_space)break;

*id_loc++= ordinary_space;
loc++;
}

continue;
}
}

*id_loc++= *loc++;
}

return stringg;
}



}



GOTO_CODE prs_regular_code FCN((iswitch))
GOTO_CODE iswitch C1("")
{
GOTO_CODE icode;/* Return code from |get_control_code|. */

switch(iswitch)
{
case GOTO_MISTAKE:goto mistake;
case GOTO_GET_IDENTIFIER:goto get_identifier;
default:break;
}

/* --- ELLIPSIS: `\.{...}' --- */
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
int dcode;
ASCII dot_end= wt_style.dot_delimiter.end;


/* At this point, |loc| is positioned to the first position after the dot. */
for(p0= loc,n= 0;n<MAX_DOT_LENGTH;n++,loc++)
if(*loc==dot_end||!isAlpha(*loc))break;/* Found end of dot \
constant, or something not allowed. */

if(*loc!=dot_end)/* Didn't find end. */
{
loc= p0;/* Reset position back to beginning. */
goto mistake;
}

if((dcode= dot_code(dots,uppercase(p0,n),loc,dot_const))!=0)compress(dcode);
/* Search for match in table. */

/* Invalid dot constant. */
loc= p0;goto mistake;
}



/* --- CONSTANT: `\.{123}', `\.{.1}', or `\.{\\135}' --- */
else if(isDigit(c)||c==0134||c==056)
{
boolean decimal_point= NO;
ASCII prec_char;


id_first= id_loc= mod_text+1;

if(c==0134)
{/* Probably octal---e.g., `\.{\\107}' */
ASCII*loc0;

if(*loc==057)goto mistake;/* It's really `\.{\\/}'. */
*id_loc++= OCTAL_CODE;/* \.{WEBMAC} control code for octal. */
loc0= loc;
while(isOdigit(*loc))*id_loc++= *loc++;
if(loc==loc0)return(eight_bits)c;/* Not octal! */
}
else if(c==060)
{
if(*loc==0170||*loc==0130)/* Hex---e.g., `\.{0xABC}' */
{
*id_loc++= HEX_CODE;/* \.{WEBMAC} code for hex. */
loc++;
while(isXdigit(*loc))*id_loc++= *loc++;
}
else if(*loc==0142||*loc==0102)/* Binary */
{
*id_loc++= BINARY_CODE;/* \.{WEBMAC} code for binary. */
loc++;
while(isBdigit(*loc))*id_loc++= *loc++;
}
else if(isOdigit(*loc))/* Octal---e.g., `\.{011}' */
{
*id_loc++= OCTAL_CODE;
while(isOdigit(*loc))*id_loc++= *loc++;
}
else goto dec;/* decimal constant */
}


else
{
if(c==056&&!isDigit(*loc))goto mistake;/* Isn't a constant \
like~`|.1|'. */

dec:
*id_loc++= c;
while(isDigit(*loc)||*loc==056)*id_loc++= *loc++;
/* Optimistically, we'll include the decimal point with the constant. \
However, in \Fortran\ we have to check for the possibility that it's an \
integer followed by a dot constant. We do this immediately below. */

decimal_point= BOOLEAN(*(loc-1)==056);

if(FORTRAN_LIKE(language))
if(decimal_point)/* Check for dot constant. */
{
if(is_dot())/* It's an integer constant \
followed by a dot constant. */
{
id_loc--;
loc--;
return constant;
}
}
else if(*loc==0150||*loc==0110)
{
int k,n;


*id_loc= '\0';/* Temporarily make a true terminated string. */
n= ATOI(id_first);/* Convert the string to an integer constant. */
*id_loc++= HOLLERITH_CODE;/* Control character for WEB Hollerith macro. */
++loc;/* Skip the |'H'|. */

for(k= 0;k<n;++k)/* Copy the actual string. */
*id_loc++= *loc++;

return constant;
}

;

if(in_format)return constant;

prec_char= *loc;

if(prec_char==0145||prec_char==0105||(FORTRAN_LIKE(language)&&
(prec_char==0144||prec_char==0104||
prec_char==0161||prec_char==0121)))

{
*id_loc++= EXP_CODE;/* Control character for WEB power of ten. */
*id_loc++= A_TO_UPPER(prec_char);

loc++;/* Skip past the exponent character. */

if(*loc==053||*loc==055)*id_loc++= *loc++;

while(isDigit(*loc))*id_loc++= *loc++;
}


}





if(C_LIKE(language))
{
switch(*loc)
{
case 0154:
case 0114:
*id_loc++= CONSTANT_CODE;
loc++;
if(*loc==0165||*loc==0125)
{
*id_loc++= ULONG_CODE;
loc++;
}
else*id_loc++= LONG_CODE;
break;

case 0165:
case 0125:
*id_loc++= CONSTANT_CODE;
loc++;
if(*loc==0154||*loc==0114)
{
*id_loc++= ULONG_CODE;
loc++;
}
else*id_loc++= UNSIGNED_CODE;
break;

case 0146:
case 0106:
*id_loc++= CONSTANT_CODE;
*id_loc++= FLOAT_CODE;
loc++;
break;
}
}
else if(Fortran88)
{
if(*loc==0137)
while(is_kind(*loc))
*id_loc++= *loc++;
}





if(!decimal_point&&at_beginning&&
((is_FORTRAN_(language)&&!last_was_continued)||
(is_RATFOR_(language)&&*loc==072)))
return stmt_label;

return constant;
}



/* --- BOZ-CONSTANT --- */
else if(in_data&&Fortran88&&(*loc==042||*loc==047)&&
(c==0102||c==0117||c==0132))return get_string(*loc++,c);

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




/* --- STRING: `\.{"abc"}', `\.{'\\n'}', `\.{<file\_name>}' --- */
else if(c==047||c==042
||(sharp_include_line&&!in_comment&&
(c==050||(C_LIKE(language)&&c==074))))
return get_string(c,'\0');

/* --- CONTROL CODE --- */
else if(c==0100)
if((icode= get_control_code())==GOTO_MISTAKE)goto mistake;
else return icode;

/* --- WHITE SPACE --- */
/* Blanks were skipped above. */
else if(c==040||c==tab_mark)
if(nuweb_mode)
return c;else
return MORE_PARSE;/* Ignore spaces and tabs; continue. */

/* --- C PREPROCESSOR STATEMENT: `\.{\#include}' --- */
if(c==043&&at_beginning&&C_LIKE(language))

{
IN_COMMON ASCII HUGE*pinclude,HUGE*ppragma;
/* Strings for tokens |include| and |pragma|. */


preprocessing= YES;

{
/* According to ANSI, white space may be skipped at beginning of line. */
while(*loc==040||*loc==011)
loc++;

if(STRNCMP(loc,pinclude,7)==0)
sharp_include_line= YES;
else if(STRNCMP(loc,ppragma,7)==0)
sharp_pragma_line= YES;
}

;
return left_preproc;
}


/* If |'#'| is first character in line, it's a C~preprocessor statement. */

/* --- END A |@r format| STATEMENT: `\.{format(\dots);}' --- */
else if(in_format&&c==073)
{/* End a |@r format| statement. */
in_format= NO;
return end_format_stmt;
}

/* --- TWO-SYMBOL OPERATOR --- */
mistake:

switch(c)
{
case(ASCII)begin_comment0:/* Comment sent from FORTRAN or Ratfor |input_ln|. */
long_comment= YES;
return begin_comment;

case(ASCII)begin_comment1:/* As above, but short comment. */
long_comment= NO;
return begin_comment;

case 0134:
if(*loc==057&&!in_format&&FORTRAN_LIKE(language))
{
compress(slash_slash);/* `\.{\\/}' $\to$ `|@r \/|'. */
}
break;

case 057:


if(*loc==052)
{
long_comment= YES;
compress(begin_comment);/* \.{\slashstar\dots/starslash} */
}
else if(*loc==057)
{
if(C_LIKE(language)||language==TEX||(Cpp_comments&&
!in_format&&FORTRAN_LIKE(language)))
{/* Short comments are recognized in both~C and \
\Cpp, and also in |TEX|. */
long_comment= NO;/* \Cpp-style comment. */
compress(begin_comment);/* \.{//\dots} */
}
else if(!in_format)
{
compress(slash_slash);/* Concatenation \
operator~|@r \/|. Multiple slashes in |format| statements are just left \
alone. */
}
}
else if(*loc==051&&!in_format)
{compress(right_array);/* `\.{/)}' $\to$ `$\SR$'. */
}
else if(*loc==075)
{COMPOUND(slash_eq,1);/* `\.{(/}' $\to$ `$\LS$'. */
}


break;

case 050:
if(*loc==057&&!in_format)compress(left_array);
break;

case 053:
if(*loc==053){compress(plus_plus);/* `\.{++}' $\to$ `|++|'. */
}
else if(*loc==075){COMPOUND(plus_eq,1);
/* `\.{+=}' $\to$ `|+=|'. */
}
break;

case 055:
if(*loc==055){compress(minus_minus);/* `\.{--}' $\to$ `|--|'. */
}
else if(*loc==076){compress(minus_gt);
/* `\.{->}' $\to$ `|->|'. */
}
else if(*loc==075){COMPOUND(minus_eq,1);
/* `\.{-=}' $\to$ `|-=|'. */
}
break;

case 075:
if(*loc==075){compress(eq_eq);/* `\.{==}' $\to$ `|==|'. */
}
else if(*loc==076){compress(eq_gt);
/* `\.{=>}' $\to$ `$\WPtr$'. */
}/* \FORTRAN-88's pointer assignment statement. */
break;

case 076:
if(*loc==075){compress(gt_eq);/* `\.{>=}' $\to$ `|>=|'. */
}
else if(*loc==076)
if(*(loc+1)==075){COMPOUND(gt_gt_eq,2);
/* `\.{>>=}' $\to$ `|>>=|'. */
}
else{compress(gt_gt);/* `\.{>>}' $\to$ `|>>|'. */
}
break;

case 074:
if(*loc==075){compress(lt_eq);/* `\.{<=}' $\to$ `|<=|'. */
}
else if(*loc==074)
if(*(loc+1)==075)
{COMPOUND(lt_lt_eq,2);
/* `\.{<<=}' $\to$ `|<<=|'. */
}
else{compress(lt_lt);/* `\.{<<}' $\to$ `|<<|'. */
}
else if(*loc==076){compress(not_eq);
/* `\.{<>}' $\to$ `|!=|'. */
}/* \FORTRAN-88 */
break;

case 045:
if(*loc==075){COMPOUND(mod_eq,1);/* `\.{\%=}' $\to$ `|%=|'. */
}
break;

case 046:
if(*loc==046){compress(and_and);/* `\.{\&\&}' $\to$ `|&&|'. */
}
else if(*loc==075)
{
COMPOUND(and_eq,1);/* `\.{\&=}' $\to$ `|&=|'. */
}
break;

case 0174:
if(*loc==0174)
{
if(*(loc+1)==0174)
{
COMPOUND(or_or_or,2);/* `\.{\vb\vb\vb}' $\to$ `|||||'. */
}
else compress(or_or);/* `\.{\vb\vb}' $\to$ `||| |'. */
}
else if(*loc==075&&!FORTRAN_LIKE(language))
{
COMPOUND(or_eq,1);/* `\.{\vertbar=}' $\to$ `||=|'. */
}
break;

case 041:
if(!in_format&&(point_comments||*loc==041))
{
if(*loc!=041)loc--;
long_comment= NO;
compress(begin_comment);/* \.{! Comment} or \.{!! Comment}. */
}
else if(*loc==075){compress(not_eq);/* `\.{!=}' $\to$ `|!=|'. */
}
break;

case 052:
if(FORTRAN_LIKE(language)&&(*loc==052))
{compress(star_star);/* `\.{x**y}' $\to$ `|@r x**y|'. */
}/* Exponentiation. */
else if(*loc==075){COMPOUND(star_eq,1);/* `\.{*=}' $\to$ `|*=|'. */
}
break;

case 0136:
if(*loc==0136){compress(star_star);}
else if(FORTRAN_LIKE(language)&&(loc<limit))
return star_star;/* `\.{x\^y}' $\to$ `|@r x^y|'. */
else if(*loc==075){COMPOUND(xor_eq,1);/* `\.{\^=}' $\to$ `|^=|'. */
}
break;

case 072:
if(*loc==072)compress(colon_colon);/* `\.{::}' $\to$ `|::|'. */
break;

case 043:


switch(*loc)
{
case 043:
compress(paste);/* `\.{\#\#}' $\to$ token `\.{\#\#}'. */
break;

case 041:
compress(dont_expand);/* `\.{\#!}' $\to$ token `\.{\#!}'. */
break;

case 072:
compress(auto_label);/* `\.{\#:}' $\to$ token `\.{\#:}'. */
break;

case 056:
compress(all_variable_args);/* `\.{\#.}' $\to$ token `\.{\#.}'. */
break;

case 074:
loc++;
mac_mod_name= YES;

{
ASCII HUGE*k;/* Pointer into |mod_text|. */
static ASCII ell[]= "\56\56\56";
static ASCII bad_mod_name[]= "\41\41\41\40\173\134\151\164\40\111\156\143\157\155\160\141\164\151\142\154\145\175\40\41\41\41";



{
int mlevel= 1;/* For nested module names. */

k= mod_text;

WHILE()
{
if(loc>limit&&!get_line())
{

err0_print(ERR_W,OC("Input ended in section name"),0);

loc= cur_buffer+1;break;
}

c= *loc;


if(c==0100)
{
c= *(loc+1);

if(c==076)
{
if(--mlevel==0)
{
loc+= 2;break;
}
}
else if(c==074)mlevel++;

if(ccode[c]==new_module)
{

err0_print(ERR_W,OC("Section name didn't end"),0);break;

}

*(++k)= 0100;loc++;/* Now |c==*loc| again. */
}

;
loc++;

if(k<mod_end)k++;

switch(c)
{
case 040:
case tab_mark:
c= 040;if(*(k-1)==040)k--;/* Compress white space. */
break;

case 073:
c= interior_semi;
break;
}

*k= c;
}

if(k>=mod_end)
{
SET_COLOR(warning);
printf("\n! Section name too long: ");

ASCII_write(mod_text+1,25);
printf("...");mark_harmless;
}

if(*k==040&&k>mod_text)k--;/* Trailing blanks. */
}



if(k-mod_text>3&&STRNCMP(k-2,ell,3)==0)
cur_module= prefix_lookup(mod_text+1,k-3);
else cur_module= mod_lookup(mod_text+1,k);

if(!cur_module)
cur_module= mod_lookup(bad_mod_name,bad_mod_name+STRLEN(bad_mod_name)-1);

if(cur_module)
{
params= cur_module->mod_info->params;/* Restore state for this module. */
frz_params();
}

xref_switch= NO;

/* The actual return value can be either |module_name| or \
|macro_module_name| and is put in explicitly right after the use of this \
module in the code. */
}

;
return macro_module_name;

case 047:
case 042:
if(phase==1)loc++;/* Skip over so string scanner doesn't complain. */
break;
}


break;
}



return(eight_bits)c;
}



eight_bits get_string FCN((c,boz))
ASCII c C0("What started the string")
ASCII boz C1("The boz character, or 0.")
{
ASCII delim= c;/* what started the string */
ASCII right_delim= c;
int level,kount;
boolean equal_delims;

id_first= mod_text+1;
id_loc= mod_text;

/* ???? */
if(delim==047&&*(loc-2)==0100){*++id_loc= 0100;*++id_loc= 0100;}
*++id_loc= delim;


{
switch(delim)
{
case 074:
right_delim= 076;/* for file names in |#include| lines. */
break;

case 050:
right_delim= 051;/* For m4 \&{include} or related functions. */
sharp_include_line= NO;
break;

case 0133:
right_delim= 0135;/* For auto insertions in macro definitions. */
break;
}

level= 1;/* For searching for balanced delimiters. */

equal_delims= BOOLEAN(right_delim==delim);
}



kount= 0;/* How far since last discretionary line break command. */

WHILE()
{/* Scan for end of string. */
if(loc>=limit)
{
if((equal_delims||chk_ifelse)&&*(limit-1)!=cont_char)
{

err0_print(ERR_W,OC("String %s with '%s%c' didn't end"),3,BTRANS,delim==047?"\\":"",XCHR(delim));
loc= limit;break;

}

if(!get_line())
{

err0_print(ERR_W,OC("Input ended in middle of string beginning with \
'\\%c'"),1,XCHR(delim));
loc= cur_buffer;
break;

}
else
{
/* Now the continuation of the string is in the buffer.  If appropriate, \
skip over beginning white space and backslash. */
if(bslash_continued_strings)
{
for(;loc<limit;loc++)
if(*loc!=040&&*loc!=tab_mark)break;

if(*loc==cont_char)loc++;/* Move past the backslash. */
else
err0_print(ERR_W,OC("Inserted '\\%c' at beginning of continued \
string"),1,XCHR(cont_char));
}
}
}



if((c= *loc++)==delim)
{
level++;

if(++id_loc<=mod_end)*id_loc= c;

if(!equal_delims)continue;

if(FORTRAN_LIKE(language)&&(*loc==delim))
++loc;/* Copy over repeated delimiter. */
else break;/* Found end of string. */
}



if(c==right_delim)
if(--level==0)
{
if(++id_loc<=mod_end)*id_loc= c;
break;/* Found end of string for unequal delims. */
}

/* Handle a final backslash. */
if((c==cont_char)&&
(C_LIKE(language)||(is_FORTRAN_(language)&&free_form_input)))
if(loc>=limit)continue;
else if(++id_loc<=mod_end)
{
*id_loc= c;c= *loc++;
}

/* Store the character. */
if(++id_loc<=mod_end)*id_loc= c;



if(insert_breaks)
if(c==054)kount= 0;
else if(++kount>=NBREAK&&c!=0100&&++id_loc<=mod_end)
{
kount= 0;
*id_loc= discretionary_break;
}


}/* End of \&{while}. */

if(id_loc>=mod_end)
{
SET_COLOR(error);
printf("\n! String too long: ");

ASCII_write(mod_text+1,25);
printf("...");mark_error;
}

id_loc++;


{
if(FORTRAN_LIKE(language))
if(boz)

{
switch(boz)
{
case 0102:
*id_first= BINARY_CODE;
break;

case 0117:
*id_first= OCTAL_CODE;
break;

case 0132:
*id_first= HEX_CODE;
break;
}

id_loc--;
return constant;
}


else

{
if(*loc==0130||*loc==0170)
{
*id_first= HEX_CODE;/* Overwrite opening delimiter. */


loc++;/* Skip the ending signifier. */
id_loc--;/* Forget closing delimiter. */
return constant;


}
else if(*loc==0117||*loc==0157)
{
*id_first= OCTAL_CODE;/* Octal */


loc++;/* Skip the ending signifier. */
id_loc--;/* Forget closing delimiter. */
return constant;


}
}


}



return stringg;
}


GOTO_CODE get_control_code(VOID)
{
eight_bits cc;/* The |ccode| value. */


c= *loc++;
SET_CASE(c);/* Set the |upper_case_code| flag. */

/* Deflect a verbatim comment beginning with `\.{@\slashstar}'. */
if((c==057&&(*loc==052||*loc==057))||
c==(ASCII)begin_comment0||c==(ASCII)begin_comment1)
return GOTO_MISTAKE;

switch(cc= ccode[c])
{
case no_index:
index_flag= NO;
return MORE_PARSE;

case yes_index:
INDEX_SHORT;
return MORE_PARSE;

case defd_at:
if(mark_defined.generic_name)
{
defd_switch= YES;/* `\.{@[}'. */
defd_type= GENERIC_NAME;
}/*   \bf NOTE: Falls through. */

case underline:
xref_switch= def_flag;/* `\.{@\_}' */
return MORE_PARSE;

case implicit_reserved:
if(mark_defined.imp_reserved_name)
{
typd_switch= defd_switch= YES;/* `\.{@`}'. */
defd_type= IMPLICIT_RESERVED;
xref_switch= def_flag;
}
return MORE_PARSE;

case switch_math_flag:math_flag= !math_flag;/* `\.{@\$}' */
return MORE_PARSE;

#ifdef DEBUG
case trace:tracing= c-060;/* `\.{@0}', `\.{@1}', `\.{@2}' */
return MORE_PARSE;
#endif /* |DEBUG| */

/* For language switches, we set the |language|, then \
send back a single code |begin_language|. When we process this, we'll then \
append another 8-bit code with the language number itself. */



case begin_C:
case begin_RATFOR:
case begin_FORTRAN:
case begin_LITERAL



:
loc--;/* Falls through to general case below. */

case L_switch:
{

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




if(module_count==0)
global_params= params;

ini0_language();


if(Fortran88&&auto_semi)
{
loc= limit+1;
chk_end= NO;
}



}


return begin_language;/* `\.{@L$l$}' */
}

case begin_nuweb:

err0_print(ERR_W,OC("@N ignored; must appear before beginning of code part"),0);
return MORE_PARSE;

case xref_roman:case xref_wildcard:case xref_typewriter:
case TeX_string:
{
cc= ccode[*(loc-1)];/* Is this statement redundant? */
id_first= loc;*(limit+1)= 0100;

while(*loc!=0100)loc++;

id_loc= loc;

if(loc++>limit)
{

err0_print(ERR_W,OC("Control text didn't end"),0);loc= limit;return cc;

}

if(*loc++!=076)
err0_print(ERR_W,OC("Control codes are forbidden in control text"),0);


return cc;
}

/* `\.{@\^\dots@>}', \
`\.{@9\dots@>}', `\.{@.\dots@>}', and `\.{@t\dots@>}'. */

case module_name:
mac_mod_name= NO;/* Used as a flag for macro processing. */

{
ASCII HUGE*k;/* Pointer into |mod_text|. */
static ASCII ell[]= "\56\56\56";
static ASCII bad_mod_name[]= "\41\41\41\40\173\134\151\164\40\111\156\143\157\155\160\141\164\151\142\154\145\175\40\41\41\41";



{
int mlevel= 1;/* For nested module names. */

k= mod_text;

WHILE()
{
if(loc>limit&&!get_line())
{

err0_print(ERR_W,OC("Input ended in section name"),0);

loc= cur_buffer+1;break;
}

c= *loc;


if(c==0100)
{
c= *(loc+1);

if(c==076)
{
if(--mlevel==0)
{
loc+= 2;break;
}
}
else if(c==074)mlevel++;

if(ccode[c]==new_module)
{

err0_print(ERR_W,OC("Section name didn't end"),0);break;

}

*(++k)= 0100;loc++;/* Now |c==*loc| again. */
}

;
loc++;

if(k<mod_end)k++;

switch(c)
{
case 040:
case tab_mark:
c= 040;if(*(k-1)==040)k--;/* Compress white space. */
break;

case 073:
c= interior_semi;
break;
}

*k= c;
}

if(k>=mod_end)
{
SET_COLOR(warning);
printf("\n! Section name too long: ");

ASCII_write(mod_text+1,25);
printf("...");mark_harmless;
}

if(*k==040&&k>mod_text)k--;/* Trailing blanks. */
}



if(k-mod_text>3&&STRNCMP(k-2,ell,3)==0)
cur_module= prefix_lookup(mod_text+1,k-3);
else cur_module= mod_lookup(mod_text+1,k);

if(!cur_module)
cur_module= mod_lookup(bad_mod_name,bad_mod_name+STRLEN(bad_mod_name)-1);

if(cur_module)
{
params= cur_module->mod_info->params;/* Restore state for this module. */
frz_params();
}

xref_switch= NO;

/* The actual return value can be either |module_name| or \
|macro_module_name| and is put in explicitly right after the use of this \
module in the code. */
}


return module_name;/* `\.{@<\dots@>}' */

case new_output_file:

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



return cc;

case invisible_cmnt:
if(*loc==045)
eat_blank_lines= YES;
loc= limit+1;/* Skip the line. */
return MORE_PARSE;/* `\.{@\%} */

case compiler_directive:
case Compiler_Directive:
long_comment= NO;
doing_cdir= YES;
return begin_comment;/* `\.{@!}' or `\.{@?}' */

case verbatim:
{
id_first= loc++;

*(limit+1)= 0100;*(limit+2)= 076;

while(*loc!=0100||*(loc+1)!=076)loc++;

if(loc>=limit)
err0_print(ERR_W,OC("Verbatim string didn't end"),0);


id_loc= loc;loc+= 2;

return(verbatim);
}

/* `\.{@=\dots@>}' */

case ascii_constant:return get_string(c,'\0');/* `\.{@'\dots'}' */

case big_line_break:/* `\.{@\#}' */
if(loc>=limit)return cc;


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


;/* In \.{typedefs.web}. */
return cc;

case begin_bp:
return 0173;/* Ought to improve this, to mark the debugging locations. */

case USED_BY_NEITHER:
if(phase==1)

err0_print(ERR_W,OC("Invalid `@%c' ignored"),1,XCHR(c));

return ignore;

default:return cc;
}
}



SRTN phase1(VOID)
{
LANGUAGE language0= language;

phase= 1;
the_part= LIMBO;

rst_input();
reading(web_file_name,(boolean)(tex_file==stdout));
module_count= 0;
skip_limbo();/* Skip stuff before any module (but process language commands). */
change_exists= NO;

/* Remember the language to put into force at the beginning of each module. \
  |language| may have been set from the command line, by default (nothing on \
  the command line), or by explicit~\.{@c}, \.{@r}, \.{@n}, \
or~\.{@L$l$} commands  during the limbo phase. */
chk_override(language0);
fin_language();/* Make sure all flags are initialized properly. */
global_params= params;

while(!input_has_ended)

{
the_part= TEX_;

if(++module_count==(sixteen_bits)max_modules)
OVERFLW("section numbers","m");

chngd_module[module_count]= NO;/* It will become |YES| if any line changes. */

progress();

/* All modules start off in the global language. */
params= global_params;
frz_params();


{
the_part= TEX_;

WHILE()
{
switch(next_control= skip_TeX())
{


case begin_C:
case begin_RATFOR:
case begin_FORTRAN:
case begin_LITERAL



:
loc--;/* Falls through to general case below. */

case L_switch:
{

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




if(module_count==0)
global_params= params;

ini0_language();


if(Fortran88&&auto_semi)
{
loc= limit+1;
chk_end= NO;
}



}

;
continue;
}

case begin_nuweb:
nuweb_mode= !NUWEB_MODE;
continue;

case toggle_output:

{
static int outer_include_depth;

if(output_on)
{
if(phase==2)
{
flush_buffer(out_ptr,NO);
}
outer_include_depth= incl_depth;
output_on= NO;
}
else if(incl_depth<=outer_include_depth)
{
output_on= YES;
}
}


continue;

case underline:
xref_switch= def_flag;
continue;

#ifdef DEBUG
case trace:tracing= next_control-060;continue;
#endif /* |DEBUG| */

case 0174:
while(next_control<=module_name)
{
C_xref(TEX_,INNER);
if(next_control==0174||next_control==new_module)
break;
next_control= get_next();
if(next_control==0174)break;
}

break;

case xref_roman:case xref_wildcard:case xref_typewriter:
case macro_module_name:case module_name:
loc-= 2;next_control= get_next();/* Scan to \.{@>}. */

if(!(next_control==module_name||
next_control==macro_module_name))
new_xref(TEX_,id_lookup(id_first,id_loc,
(eight_bits)(next_control-identifier)));
break;

case invisible_cmnt:
loc= limit+1;
break;
}

if(next_control>=formatt)
break;
}
}

;

{
boolean no_xref0= no_xref;

the_part= DEFINITION;

while(next_control<begin_code)
{/* |formatt| or |definition| or |WEB_definition| or \.{@\#...} \
command. */
switch(next_control)
{
case WEB_definition:
if(mark_defined.WEB_macro&&lower_case_code)
defd_switch= YES;/* Implied \.{@[}. */

xref_switch= def_flag;/* Implied \.{@\_} */
defd_type= M_MACRO;

KILL_XREFS(macros);
INDEX_SHORT;
break;

case m_undef:
KILL_XREFS(macros);
INDEX_SHORT;
break;

case definition:
if(mark_defined.outer_macro&&mark_defined.outer_macro)
defd_switch= YES;/* Implied \.{@[}. */

xref_switch= def_flag;/* Implied \.{@\_} */
defd_type= D_MACRO;

KILL_XREFS(outer_macros);
INDEX_SHORT;
break;

case undefinition:
KILL_XREFS(outer_macros);
INDEX_SHORT;
break;

case m_ifdef:
case m_ifndef:
INDEX_SHORT;
break;
}

switch(next_control)
{
case formatt:
pr_format(YES,YES);
break;

case limbo_text:

{
LANGUAGE language0= language;

KILL_XREFS(limbo);

if(language==TEX)
language= C;/* In order to absorb strings properly. */

insert_breaks= NO;/* We want the string to be absorbed completely literally. */

if((next_control= get_next())!=stringg)

err0_print(ERR_W,OC("String must follow @l"),0);
else
{/* Begin by stripping off delimiting quotes. */
for(id_first++,id_loc--;id_first<id_loc;)
{
if(*id_first==0100)
{
if(*(id_first+1)==0100)
id_first++;
else

err0_print(ERR_W,OC("Double @ should be used in strings"),0);
}

/* Deal with escape sequences. */
if(*id_first==0134)
{
id_first++;
/* Splitting the following line before |HUGE| led to compiler problem with \
VAX/VMS. */
app_tok(esc_achar(
(CONST ASCII HUGE*HUGE*)&id_first))
}
else
app_tok(*id_first++);
}

freeze_text;/* We'll know we've collected stuff because |text_ptr| \
will be advanced. */
}

insert_breaks= YES;

language= language0;
}


break;

case op_def:

{
OPERATOR HUGE*p,HUGE*p1;

KILL_XREFS(v);

/* Look at the first field, which should be an operator or a dot-op. */
next_control= get_next();

if(next_control==identifier)

err0_print(ERR_W,OC("For future compatibility, please use syntax `.NAME.' for \
overloading dot operators"),0);

if(!(p= valid_op(next_control)))

err0_print(ERR_W,OC("Operator after @v is invalid"),0);
else
{
if(get_next()!=stringg)

err0_print(ERR_W,OC("Second argument (replacement text) \
of @v must be a quoted string"),0);
else
{
int k= language_num;
OP_INFO HUGE*q= p->info+k;
int n= PTR_DIFF(int,id_loc,id_first)-2;/* Don't count the \
string delimiters. */
outer_char HUGE*s;

if(q->defn)FREE_MEM(q->defn,"q->defn",STRLEN(q->defn)+1,
outer_char);
q->defn= GET_MEM("q->defn",n+1,outer_char);

*(id_loc-1)= '\0';/* Kill off terminating quote. */

for(s= q->defn,id_first++;*id_first;s++)
if(*id_first==0134)
{
id_first++;
*s= XCHR(esc_achar((CONST ASCII HUGE
*HUGE*)&id_first));
}
else*s= XCHR(*id_first++);

overloaded[k]= q->overloaded= YES;

/* There may be several representations with the same name. */
for(p1= op;p1<op_ptr;p1++)
{
if(p1==p||!p1->op_name)continue;

if(STRCMP(p1->op_name,p->op_name)==0)
{
OP_INFO HUGE*q1= p1->info+k;

if(q1->defn)FREE_MEM(q1->defn,"q1->defn",
STRLEN(q1->defn)+1,outer_char);
q1->defn= GET_MEM("q1->defn",n+1,outer_char);
STRCPY(q1->defn,q->defn);
q1->overloaded= YES;
}
}

/* Get the new category and set it.  If the last construction isn't \
recognized as a valid operator, the category is set to |expr|. */
p= valid_op(next_control= get_next());

q->cat= (p?p->info[k].cat:(eight_bits)expr);
}
}
}


break;

case macro_def:

{
if((next_control= get_next())!=identifier)

err0_print(ERR_W,OC("Identifier must follow @w"),0);
else
{
name_pointer p= id_lookup(id_first,id_loc,normal);
int n,offset;
WV_MACRO HUGE*w;
ASCII HUGE*s;
ASCII HUGE*id_first0,HUGE*id_loc0;

/* Index the identifier (but not defined).  Force short identifiers to be \
indexed. */
KILL_XREFS(w);
INDEX_SHORT;
new_xref(DEFINITION,p);

/* Remember the first identifier. */
id_first0= id_first;
id_loc0= id_loc;

switch(next_control= get_next())
{
case 0134:
if((next_control= get_next())!=identifier)
{

err0_print(ERR_W,OC("Identifier must follow '\\'"),0);
break;
}

next_control= ignore;/* We don't want to put the \
identifier into the index. */
goto quick_code;


case QUICK_FORMAT:
id_first= id_first0;
id_loc= id_loc0;

quick_code:
offset= 1;
n= PTR_DIFF(int,id_loc,id_first)+1;
*id_loc= '\0';
goto fmt_like_string;

case stringg:
{
offset= 0;
n= PTR_DIFF(int,id_loc,id_first)-2;/* Don't count quotes. */
*(id_loc-1)= '\0';
id_first++;/* Skip over opening quote. */

fmt_like_string:
p->wv_macro= w= GET_MEM("wv_macro",1,WV_MACRO);
w->text= GET_MEM("w->text",n+1,outer_char);

if(offset)*w->text= 0134;

for(s= w->text+offset;*id_first;s++)
if(*id_first==0134)
{
id_first++;
*s= esc_achar((CONST ASCII HUGE
*HUGE*)&id_first);
}
else*s= *id_first++;

w->len= PTR_DIFF(unsigned,s,w->text);

w->cat= (eight_bits)(upper_case_code?0:expr);/* Temporary */
}
break;

default:

err0_print(ERR_W,OC("Second argument (replacement text) \
of @w must be either a quoted string or '.' or have the form \\name"),0);
break;
}
}
}


break;

case invisible_cmnt:
loc= limit+1;/* Skip the line. */

default:
next_control= get_next();
break;
}

outr_xref(DEFINITION);
no_xref= no_xref0;
}
}

;

{
the_part= CODE;

if(next_control<=module_name)
{/* |begin_code| or |module_name| */
boolean beginning_module= YES;

if(next_control==begin_code)
{
boolean nuweb_mode0= nuweb_mode;

unnamed_section= YES;

params= global_params;
nuweb_mode= nuweb_mode0;
frz_params();

mod_xref_switch= NO;

if(mark_defined.fcn_name&&lower_case_code)
{
defd_switch= YES;/* Implicit \.{@[}. */
defd_type= FUNCTION_NAME;
}
}
else
{
unnamed_section= NO;
mod_xref_switch= def_flag;
}


do
{
if(next_control==module_name&&cur_module)
new_mod_xref(cur_module);

if(beginning_module)
{
if(mod_xref_switch)
next_control= get_next();
else
next_control= 075;/* For |begin_code|. */

if(next_control==075)
if(!nuweb_mode&&((FORTRAN_LIKE(language)&&!free_form_input)
||(language==TEX)))

{
loc= limit+1;/* Skip rest of line. */
chk_end= NO;
column_mode= YES;
}



beginning_module= NO;
}
else next_control= get_next();

outr_xref(CODE);
}
while(next_control<=module_name)
;/* Hunt for new module. */

column_mode= NO;/* Turn off the FORTRAN verbatim input mode. */
unnamed_section= NO;/* Don't deflect cross-references. */
}
}

;

if(chngd_module[module_count])
change_exists= YES;

typd_switch= defd_switch= NO;/* Don't propagate beyond one module. */
}

;

chngd_module[module_count]= change_exists;
/* the index changes if anything does */



mod_check(root)

;
}



SRTN C_xref FCN((part0,mode0))
PART part0 C0("")
PARSING_MODE mode0 C1("")
{
PARAMS outer_params;
PARSE_PARAMS parse_params0;
name_pointer p;/* a referenced name */

parsing_mode= mode0;

if(parsing_mode==INNER)
{
outer_params= params;/* Store whole structure. */
parse_params0= parse_params;
}

if(language==LITERAL)
next_control= begin_meta;

do_inside= YES;

while(next_control<formatt)
{
switch(next_control)
{
case begin_language:


switch(language)
{
case NO_LANGUAGE:
CONFUSION("handle possible language switch",
"Language isn't defined");

case FORTRAN:
case FORTRAN_90:
case RATFOR:
case RATFOR_90:
if(mode0==OUTER&&!free_form_input)

{
loc= limit+1;/* Skip rest of line. */
chk_end= NO;
column_mode= YES;
}


break;

case TEX:
if(mode0==OUTER)
{
loc= limit+1;/* Skip rest of line. */
chk_end= NO;
column_mode= YES;
}


break;

case C:
case C_PLUS_PLUS:
case LITERAL:
column_mode= NO;
break;

case NUWEB_OFF:
case NUWEB_ON:
CONFUSION("handle possible language switch","Invalid langage");
}



break;

case toggle_output:

{
static int outer_include_depth;

if(output_on)
{
if(phase==2)
{
flush_buffer(out_ptr,NO);
}
outer_include_depth= incl_depth;
output_on= NO;
}
else if(incl_depth<=outer_include_depth)
{
output_on= YES;
}
}


break;

case begin_meta:

{
WHILE()
{
if(!get_line())
if(language==LITERAL)
{
next_control= new_module;
goto done_meta;
}
else
{

err0_print(ERR_W,OC("Input ended during meta-comment"),0);
break;
}

if(*loc==0100)
switch(*(loc+1))
{
case 051:
get_line();

case 052:
case 040:
next_control= new_module;
goto done_meta;

case 074:
next_control= module_name;
goto done_meta;
}
}

done_meta:;
}


break;

case identifier:
case xref_roman:
case xref_wildcard:
case xref_typewriter:
p= id_lookup(id_first,id_loc,
(eight_bits)(next_control-identifier));

new_xref(part0,p);

if(part0==DEFINITION)
defd_switch= NO;/* Prevent the implicit~\.{@[} \
from propagating beyond the first identifier. */

if(next_control==identifier&&C_LIKE(language)
&&parsing_mode==OUTER)
{
if(p->ilk==typedef_like)

{
int brace_level= 0;
boolean typedefd_it= NO;

/* First, we scan over a possible |struct|. */
while((next_control= get_next())==identifier)
if((p= id_lookup(id_first,id_loc,0))->ilk!=struct_like)
{
new_xref(part0,p);/* Structure name: ``|typedef struct s''. */
next_control= get_next();/* Don't repeat the structure name. */
break;
}

while(next_control<=module_name)
{
switch(next_control)
{
case 0173:
brace_level++;
break;

case 0175:
if(brace_level--==0)
{

err0_print(ERR_W,OC("Extra '}' in typedef"),0);
goto done;
}
break;

case identifier:
p= id_lookup(id_first,id_loc,0);

if(brace_level==0&&!typedefd_it)
{
if(is_reserved(p))
break;

defd_switch= BOOLEAN(mark_defined.typedef_name);
defd_type= TYPEDEF_NAME;
typd_switch= YES;
INDEX_SHORT;
new_xref(part0,p);
}
else if(do_inside)
new_xref(part0,p);

if(brace_level==0&&!typedefd_it)
typedefd_it= YES;/* Don't do any more (e.g., array \
dimensions).  (But this means one can't yet do |BB| in |typedef int AA, BB.) */
break;

case formatt:
case limbo_text:
case op_def:
case macro_def:
case definition:
case undefinition:
case WEB_definition:
case begin_code:
case new_output_file:
case protect_code:

err0_print(ERR_W,OC("You can't do that inside a typedef"),0);
break;

case module_name:
if(cur_module)new_mod_xref(cur_module);
next_control= get_next();
if(next_control==075)
{

err0_print(ERR_W,OC("'=' not allowed after @<...@> \
inside typedef; check typedef syntax.  Inserted ';'"),0);
next_control= 073;
}
continue;

case 073:
if(brace_level==0)goto done;/* End of |typedef|. */
break;

case begin_comment:

{
int bal;/* Brace level in comment. */

bal= copy_comment(1);next_control= 0174;

doing_cdir= NO;

while(bal>0)
{/* Inside comment. */
in_comment= YES;
C_xref(part0,INNER);

if(next_control==0174)
bal= copy_comment(bal);
else
bal= 0;/* An error message will occur in phase 2. */
}
}


break;
}

next_control= get_next();
}

done:
defd_switch= typd_switch= NO;/* Just in case we screwed up. */

if(next_control==new_module)
{

err0_print(ERR_W,OC("Module ended during typedef"),0);
goto end_xref;
}
}


else if(p->ilk==class_like)

{
if((next_control= get_next())==identifier)
{
p= id_lookup(id_first,id_loc,0);

defd_switch= BOOLEAN(mark_defined.typedef_name);
defd_type= TYPEDEF_NAME;
typd_switch= YES;
INDEX_SHORT;

new_xref(part0,p);
typd_switch= NO;
}
}


}
break;

case stringg:
if(sharp_include_line&&phase==1&&read_iformats
&&C_LIKE(language))
get_iformats();

break;
}

next_control= get_next();

if(next_control==0174||next_control==begin_comment)break;
}

end_xref:
if(parsing_mode==INNER)
{
params= outer_params;
frz_params();
parse_params= parse_params0;
parsing_mode= OUTER;
}
}



SRTN
get_iformats(VOID)
{
int n,new_depth;
outer_char file_name[256],temp[100];
FILE*ftemp_in;
PART part0= CODE;

if(!temp_in[0])
mktmp(temp_in,
language==C?wt_style.output_ext.C_:wt_style.output_ext.Cpp_);

if((ftemp_in= FOPEN(temp_in,"w"))==NULL)
{
printf("\n! Can't open temporary file `%s'",temp_in);
mark_harmless;
read_iformats= NO;
return;
}

if(!temp_out[0])
mktmp(temp_out,(outer_char*)"");
/* We don't open the output file here, as \.{cpp} may not \
			write into it if it's open. */

preprocessing= sharp_include_line= NO;

/* Copy include file name, include delimiters. */
STRNCPY(file_name,id_first,n= PTR_DIFF(int,id_loc,id_first));
file_name[n]= '\0';
to_outer((ASCII HUGE*)file_name);

qtd_file= BOOLEAN(file_name[0]=='"');
/* Is this file name quoted (i.e., look locally)? */

/* Write the include file command to temporary file, so the preprocessor \
can read it. */
fprintf(ftemp_in,"#include %s\n",file_name);
fclose(ftemp_in);

/* Create a command to run the preprocessor.  We tell the preprocessor to \
look first in the |wbprefix| directory, then in the current directory. \
(Note the use of the \.{-I.} command of \.{gcc}, which looks in the \
directory current when the compiler was invoked.) */
sprintf((char*)temp,"\n%s -E -P -I%s -I. -o %s %s",
language==C?"gcc":"g++",
*wbprefix?(char*)wbprefix:".",
temp_out,temp_in);

if(!rmv_files)
puts((char*)temp);
/* Echo the |system| command that runs the preprocessor. */

system((CONST char*)temp);


{
if(++incl_depth>=(int)max_include_depth)
{
incl_depth--;

err0_print(ERR_C,OC("Too many nested includes; %d allowed.  \
Increase with `-yid'."),1,max_include_depth);

goto restore;
}

{/* No change file name specified; obtain it from the last level. */
INPUT_PRMS*p_lower= &prms[incl_depth-1];
INPUT_PRMS0*p0_lower= &p_lower->change;

STRCPY(change_file_name,p0_lower->File_name);
change_file= p0_lower->File;
change_params= p_lower->input_params;
}

STRCPY(cur_file_name,temp_out);
new_depth= incl_depth;

{
IN_COMMON INCL_PATHS incl;

if(ini_input_prms(CUR_FILE,incl.list,NO))
{
if(cur_prms.change->File!=prms[incl_depth-1].change.File)
{}
else*cur_prms.change= prms[incl_depth-1].change;
/* Still using the old change file. */

cur_line= 0;
prn_where= YES;
/* Instead of printing the names of the temporary files, we print the \
include file name itself. */
CLR_PRINTF(include_file,(" (%s",file_name));
/* Tell the terminal where we're reading from. */
}
else
{/* Failed to open include file. */
incl_depth--;
}
}
}



if(new_depth!=incl_depth||!get_line())
goto restore;/* No file, or nothing in it. */

do_inside= NO;
/* This flag says to not xref stuff inside braces of \&{typedef}. */

next_control= get_next();

/* Parse the preprocessed include file until EOF is reached and the \
|incl_depth| changes. */
while(new_depth==incl_depth)
{
name_pointer p;

switch(next_control)
{
case identifier:
p= id_lookup(id_first,id_loc,
(eight_bits)(next_control-identifier));

if(p->ilk==typedef_like)

{
int brace_level= 0;
boolean typedefd_it= NO;

/* First, we scan over a possible |struct|. */
while((next_control= get_next())==identifier)
if((p= id_lookup(id_first,id_loc,0))->ilk!=struct_like)
{
new_xref(part0,p);/* Structure name: ``|typedef struct s''. */
next_control= get_next();/* Don't repeat the structure name. */
break;
}

while(next_control<=module_name)
{
switch(next_control)
{
case 0173:
brace_level++;
break;

case 0175:
if(brace_level--==0)
{

err0_print(ERR_W,OC("Extra '}' in typedef"),0);
goto done;
}
break;

case identifier:
p= id_lookup(id_first,id_loc,0);

if(brace_level==0&&!typedefd_it)
{
if(is_reserved(p))
break;

defd_switch= BOOLEAN(mark_defined.typedef_name);
defd_type= TYPEDEF_NAME;
typd_switch= YES;
INDEX_SHORT;
new_xref(part0,p);
}
else if(do_inside)
new_xref(part0,p);

if(brace_level==0&&!typedefd_it)
typedefd_it= YES;/* Don't do any more (e.g., array \
dimensions).  (But this means one can't yet do |BB| in |typedef int AA, BB.) */
break;

case formatt:
case limbo_text:
case op_def:
case macro_def:
case definition:
case undefinition:
case WEB_definition:
case begin_code:
case new_output_file:
case protect_code:

err0_print(ERR_W,OC("You can't do that inside a typedef"),0);
break;

case module_name:
if(cur_module)new_mod_xref(cur_module);
next_control= get_next();
if(next_control==075)
{

err0_print(ERR_W,OC("'=' not allowed after @<...@> \
inside typedef; check typedef syntax.  Inserted ';'"),0);
next_control= 073;
}
continue;

case 073:
if(brace_level==0)goto done;/* End of |typedef|. */
break;

case begin_comment:

{
int bal;/* Brace level in comment. */

bal= copy_comment(1);next_control= 0174;

doing_cdir= NO;

while(bal>0)
{/* Inside comment. */
in_comment= YES;
C_xref(part0,INNER);

if(next_control==0174)
bal= copy_comment(bal);
else
bal= 0;/* An error message will occur in phase 2. */
}
}


break;
}

next_control= get_next();
}

done:
defd_switch= typd_switch= NO;/* Just in case we screwed up. */

if(next_control==new_module)
{

err0_print(ERR_W,OC("Module ended during typedef"),0);
goto end_xref;
}
}


else if(p->ilk==class_like)

{
if((next_control= get_next())==identifier)
{
p= id_lookup(id_first,id_loc,0);

defd_switch= BOOLEAN(mark_defined.typedef_name);
defd_type= TYPEDEF_NAME;
typd_switch= YES;
INDEX_SHORT;

new_xref(part0,p);
typd_switch= NO;
}
}



break;
}

next_control= get_next();
}

end_xref:
restore:
preprocessing= sharp_include_line= YES;
}



SRTN
cls_files(VOID)
{
if(read_iformats&&rmv_files)
{
remove((CONST char*)temp_in);
remove((CONST char*)temp_out);
}
}



outer_char*
mktmp FCN((file_name,ext))
outer_char*file_name C0("")
outer_char*ext C1("")
{
outer_char*buffer;

#if(HAVE_TEMPNAM)
extern char*tempnam();

if(!*wbprefix)
STRCPY(wbprefix,"./");

buffer= (outer_char*)tempnam((char*)wbprefix,"FTMP");
/* Non-|ANSI|, but more control over directory. */
#else
buffer= (outer_char*)tmpnam(NULL);/* |ANSI| routine. */
#endif

STRCPY(file_name,buffer);

if(*ext)
{
STRCAT(file_name,".");
STRCAT(file_name,ext);
}

return file_name;
}




SRTN outr_xref FCN((part0))/* extension of |C_xref| */
PART part0 C1("")
{
while(next_control<formatt)
if(next_control!=begin_comment)
C_xref(part0,OUTER);
else

{
int bal;/* Brace level in comment. */

bal= copy_comment(1);next_control= 0174;

doing_cdir= NO;

while(bal>0)
{/* Inside comment. */
in_comment= YES;
C_xref(part0,INNER);

if(next_control==0174)
bal= copy_comment(bal);
else
bal= 0;/* An error message will occur in phase 2. */
}
}


}



SRTN
pr_format FCN((xref_lhs,xref_rhs))
boolean xref_lhs C0("")
boolean xref_rhs C1("")
{
eight_bits last_control,rhs_ilk;
LANGUAGE saved_language= language;

if(upper_case_code)
KILL_XREFS(Formats);
else
KILL_XREFS(formats);

INDEX_SHORT;

if(language==TEX)
language= C;

last_control= next_control= get_next();/* Identifier or module name to be \
				formatted, or |ASCII| character. */

if(next_control==identifier||next_control==module_name)

{
if(next_control==identifier)
{
lhs= id_lookup(id_first,id_loc,normal);
lhs->ilk= normal;

if(xref_lhs)
new_xref(DEFINITION,lhs);
}
else
lhs= cur_module;

next_control= get_next();

if(next_control==identifier)
{/* Format the lhs like this one. */
rhs= id_lookup(id_first,id_loc,normal);

if(lhs!=NULL)
{
if(last_control==identifier)

{
lhs->ilk= rhs->ilk;

/* First turn off the old lhs bit (retaining all others), then add in the \
new bit for the current language. */
#define RST_BIT(field) lhs->field =  BOOLEAN(lhs->field & ~(boolean)language)\
  | (rhs->field & (boolean)language)

RST_BIT(reserved_word);
RST_BIT(Language);
RST_BIT(intrinsic_word);
RST_BIT(keyword);

#undef RST_BIT
}


else
lhs->mod_ilk= rhs->ilk;
/* We're formatting a module name. */
}

/* Take care of the possibility that the rhs may not yet have been \
encountered. */
if(xref_rhs)
{
rhs_ilk= rhs->ilk;
rhs->ilk= normal;

new_xref(DEFINITION,rhs);

rhs->ilk= rhs_ilk;
}

next_control= get_next();
}
}


else if(next_control==0140)

{
if((next_control= get_TeX())!=constant)

err0_print(ERR_W,OC("Invalid @f command:  \
One of the representations `a, `\\a, or `^^M is required"),0);
else
{
int c= TeX_char();/* Convert the |ASCII| code in |id_first|. */

next_control= get_next();/* Now expecting integer category code. */

if(next_control!=constant)
err0_print(ERR_W,OC("Invalid category code"),0);
else
{
TeX_CATEGORY cat;

TERMINATE(id_loc,0);
cat= (TeX_CATEGORY)ATOI(id_first);
/* Numerical value of new cat code. */

if((int)cat<0||(int)cat>15)

err0_print(ERR_W,OC("Category code must be between 0 and 15"),0);
else TeX[c]= cat;/* Change the category code. */

next_control= get_next();
}
}
}



if(saved_language==TEX)
language= saved_language;
}



eight_bits get_TeX(VOID)
{
if(loc>=limit)
{

err0_print(ERR_W,OC("@f line ends prematurely"),0);
return ignore;
}

id_first= id_loc= mod_text+1;

if(*loc==0134)*id_loc++= *loc++;
else if(*loc==0136&&*(loc+1)==0136)
{/* \TeX's way of representing control characters. */
*id_loc++= *loc++;*id_loc++= *loc++;
}

if(*loc==0100)
if(*(loc+1)==0100)loc++;
else
err0_print(ERR_W,OC("You should say `@@"),0);

*id_loc++= *loc++;/* Position to next non-processed character. */
*id_loc= '\0';

id_first= esc_buf(id_loc+1,mod_end,id_first,YES);
to_outer(id_first);

return constant;
}



int TeX_char(VOID)
{
int c;

while(*id_first==0134)id_first++;

if(*id_first==0136&&*(id_first+1)==0136)
{
c= *(id_first+2);
if(c>=64)c-= 64;
else c+= 64;
}
else c= *id_first;

return c;
}



SRTN mod_check FCN((p))
name_pointer p C1("Print anomalies in subtree |p|.")
{
if(p)
{
mod_check(p->llink);
cur_xref= (xref_pointer)p->xref;

if(cur_xref->num<def_flag)
{
SET_COLOR(warning);
printf("\n! Never defined: <");prn_id(p);putchar('>');
mark_harmless;

}

while(cur_xref->num>=def_flag)cur_xref= cur_xref->xlink;

if(cur_xref==xmem)
{
SET_COLOR(warning);
printf("\n! Never used: <");prn_id(p);putchar('>');
mark_harmless;

}

mod_check(p->rlink);
}
}



SRTN flush_buffer FCN((b,per_cent))
ASCII HUGE*b C0("")
boolean per_cent C1("Outputs from |out_buf+1| to |b|, \
where |b<=out_ptr|.")
{
ASCII HUGE*j;
ASCII HUGE*out_start;

if(output_on)
{
out_start= out_buf+1;
j= b;/* Pointer into |out_buffer|. */

/* Remove trailing blanks. */
if(!per_cent)
while(j>out_buf&&*j==040)
j--;

ASCII_LINE_WRITE(j-out_buf);

if(per_cent)
TEX_PUTXCHAR('%');

if(*b!=012)
TEX_NEW_LINE;/* Nuweb mode has explicit newlines. */

out_line++;

if(b<out_ptr)
{
if(*out_start==045)
out_start++;

STRNCPY(out_start,b+1,PTR_DIFF(size_t,out_ptr,b));
}

out_ptr-= b-out_start+1;
}
else
out_ptr= out_buf;
}



SRTN fin_line(VOID)/* do this at the end of a line */
{
ASCII HUGE*k;/* Pointer into |cur_buffer|. */

if(out_ptr>out_buf)
flush_buffer(out_ptr,NO);/* Something nontrivial in line. */
else
{
/* Don't output an empty line when \TeX\ source line is nonempty. */
for(k= cur_buffer;k<=limit;k++)
if(*k!=040&&*k!=tab_mark)
return;

flush_buffer(out_buf,NO);/* Empty line. */
}
}



SRTN out_del_str FCN((s,t))/* output |ASCII| characters from |s| to |t-1|.  */
token_pointer s C0("")
token_pointer t C1("")
{
if(!output_on)
return;/* Skip output. */

while(s<t)
out(*s++);
}

SRTN out_str FCN((s))/* output characters from |s| to end of string */
CONST outer_char HUGE*s C1("")
{
if(!output_on)
return;/* Skip output. */

while(*s)
out(XORD(*s++));
}



SRTN out_fname FCN((s))
CONST outer_char HUGE*s C1("File name to be written.")
{
ASCII a;

while(*s)
{
a= XORD(*s++);

switch(a)
{




case 0134:case 0173:case 0175

:

case 040:case 043:case 045:case 044:case 0136:case 0140:
case 0176:case 046:case 0137



:
out(0134);
break;
}
out(a);
}
}



SRTN break_out(VOID)/* finds a way to break the output line */
{
ASCII HUGE*k= out_ptr;/* pointer into |out_buf| */
boolean is_tex_comment= BOOLEAN(*(out_buf+1)==045);

if(nuweb_mode)
WHILE()
{
if(k==out_buf)

{
SET_COLOR(warning);
printf("\n! Line had to be broken (output l. %u):\n",out_line);

ASCII_write(out_buf+1,out_ptr-out_buf-1);
new_line;mark_harmless;
flush_buffer(out_ptr-1,YES);return;
}

;

if(*(k--)==012)
{
flush_buffer(++k,NO);
break;
}
}
else
WHILE()
{
if(k==out_buf)

{
SET_COLOR(warning);
printf("\n! Line had to be broken (output l. %u):\n",out_line);

ASCII_write(out_buf+1,out_ptr-out_buf-1);
new_line;mark_harmless;
flush_buffer(out_ptr-1,YES);return;
}

;

if(*k==040)
{
flush_buffer(k,NO);
break;
}

if(*k==012&&k[-1]!=012)
{/* Get the per-cent sign before the newline. */
*k= 045;
flush_buffer(k,NO);/* Kill off the newline. */
break;
}

if(*(k--)==0134&&*k!=0134&&*k!=012)
{/* we've decreased |k| */
flush_buffer(k,YES);
break;
}
}

if(is_tex_comment)
*(++out_ptr)= 045;
}



SRTN out_mod FCN((n,encap))
sixteen_bits n C0("Module number.")
boolean encap C1("Encapsulate?")
{
char s[100];

if(encap)
sprintf(s,"%s%s%u%s",
(char*)w_style.indx.encap_prefix,
(char*)w_style.indx.encap_infix
,n
,(char*)w_style.indx.encap_suffix);
else
sprintf(s,"%u",n);

OUT_STR(s);

if(chngd_module[n])OUT_STR("\\*");
}



SRTN out_name FCN((is_id,p))
boolean is_id C0("Flag to distinguish identifier/index entry.")
name_pointer p C1("The name to be output.")
{
ASCII HUGE*k,HUGE*k_end= (p+1)->byte_start;/* Pointers into |byte_mem|. */
boolean multi_char,non_TeX_macro;
sixteen_bits mod_defined;

if(!output_on)
return;/* Skip output. */

multi_char= BOOLEAN(k_end-p->byte_start>1);

if(multi_char)
out(0173);/* Multiple-letter identifiers are enclosed in braces. */

non_TeX_macro= BOOLEAN(is_id&&*p->byte_start==0134&&language!=TEX);

if(non_TeX_macro)
out(044);/* \Cpp\ macros (such as those like \.{\\Wcp} that would \
			arise from |@c++ operator +=()|) must be in math mode. */

for(k= p->byte_start;k<k_end;k++)
{
if(is_id)
switch(*k)
{/* Escape the special characters in identifiers. */
case 0134:
case 0173:case 0175:
/* A non-\TeX\ identifier can result from the translation of an operator \
name in \Cpp.  For that, we shouldn't escape the opening backslash.  We \
also assume that any braces following that macro should be interpreted \
literally. */
if(non_TeX_macro)
break;


case 040:case 043:case 045:case 044:case 0136:case 0140:
case 0176:case 046:case 0137

:
out(0134);
}

out(*k);
}

if(non_TeX_macro)
out(044);

if(multi_char)
out(0175);

if(p->wv_macro)

{
WV_MACRO HUGE*w= p->wv_macro;
ASCII HUGE*s= w->text;

OUT_STR("\\WTeX{");

while(*s)
out(*s++);

out(0175);
}



/* Should do all languages here. (Sorted!). */
if(subscript_fcns&&(mod_defined= p->defined_in(language)))
{
char temp[100];

if(output_protect)
OUT_STR("\\protect");

sprintf(temp,"\\WIN%d{%d}",DEFINED_TYPE(p),
mod_defined==module_count?0:mod_defined);
OUT_STR(temp);
}
}


#endif /* |Part == 1| */

#if(part == 0 || part == 2)


SRTN copy_limbo(VOID)
{
ASCII c;


{
int k;
OPERATOR*p;

/* An extra blank line after \.{\\input fwebmac.sty}. */
for(k= 0;k<NUM_LANGUAGES;k++)
if(overloaded[k])
{
flush_buffer(out_ptr,NO);
break;
}

for(k= 0;k<NUM_LANGUAGES;k++)
if(overloaded[k])
{
flush_buffer(out_ptr,NO);

OUT_STR("% --- Overloaded operator definitions from @v for '");
OUT_STR(lang_codes[k]);
OUT_STR("' ---");
flush_buffer(out_ptr,NO);

for(p= op;p<op_ptr;p++)
{
OP_INFO HUGE*q= p->info+k;

if(q->overloaded)

{
#define TEMP_LEN 1000

outer_char temp[TEMP_LEN],outer_op_name[100];

OUT_STR("\\new");

switch(q->cat)
{
case unorbinop:
case binop:
OUT_STR("binop");break;

case unop:
OUT_STR("unop");break;

default:
OUT_STR("op");break;
}

STRCPY(outer_op_name,p->op_name);to_outer((ASCII*)outer_op_name);

if(
nsprintf(temp,OC("{%s}{%s}{%s} "),3,outer_op_name,lang_codes[k],q->defn)>=(int)(TEMP_LEN))OVERFLW("temp","");
OUT_STR(temp);

#undef TEMP_LEN
}


}

flush_buffer(out_ptr,NO);
}
}



{
text_pointer t= tok_start+1;

/* Default material. */
if(*w_style.misc.limbo_begin)
{
flush_buffer(out_ptr,NO);
OUT_STR("% --- Limbo text from style-file parameter `limbo.begin' ---");
flush_buffer(out_ptr,NO);
OUT_STR(w_style.misc.limbo_begin);
flush_buffer(out_ptr,NO);
}

/* If there were any \.{@l}~commands, they were stored in phase~1; output \
them now. */
if(text_ptr>t)
{
flush_buffer(out_ptr,NO);
OUT_STR("% --- Limbo text from @l ---");/* Header line. */
flush_buffer(out_ptr,NO);
}

/* Actual text. */
for(;t<text_ptr;t++)
{
out_del_str(*t,*(t+1));
flush_buffer(out_ptr,NO);
}


{
tok_ptr= tok_mem+1;
tok_start[0]= tok_start[1]= tok_ptr;
text_ptr= tok_start+1;
}


}



OUT_STR("\n% --- Beginning of user's limbo section ---");
flush_buffer(out_ptr,NO);

WHILE()
{
if(loc>limit&&(fin_line(),!get_line()))
break;

*(limit+1)= 0100;

while(*loc!=0100)out(*(loc++));/* Copy verbatim to output. */

if(loc++<=limit)
{
c= *loc++;/* Character after `\.{@}'. */

if(ccode[c]==new_module)
break;

if(c!=0172&&c!=0132)
switch(ccode[c])
{




case begin_C:
case begin_RATFOR:
case begin_FORTRAN:
case begin_LITERAL



:
loc--;/* Position to letter after \.{@}. Falls \
through to general case |L_switch|. */

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




if(module_count==0)
global_params= params;

ini0_language();


if(Fortran88&&auto_semi)
{
loc= limit+1;
chk_end= NO;
}



}


break;

case begin_nuweb:
nuweb_mode= !NUWEB_MODE;

if(module_count==0)
global_params= params;
break;



case toggle_output:
out_skip();
break;

case invisible_cmnt:
loc= limit+1;/* Skip entire rest of line. */
break;

case 0100:
out(0100);/* $\.{@@} \to \.{@}$. */
break;

default:

err0_print(ERR_W,OC("Double @ required\
 outside of sections"),0);

}
}
}


{
if(*w_style.misc.limbo_end)
{
flush_buffer(out_ptr,NO);
OUT_STR("% --- Limbo text from style-file parameter `limbo.end' ---");
flush_buffer(out_ptr,NO);
OUT_STR(w_style.misc.limbo_end);
flush_buffer(out_ptr,NO);
}
}


}


eight_bits copy_TeX(VOID)
{
ASCII c;/* Current character being copied. */

WHILE()
{
if(loc>limit)
{

{
ASCII HUGE*b;

for(b= out_buf+1;b<=out_ptr;b++)
if(*b!=040)
break;

if(b>out_ptr)
out_ptr= out_buf;
}


fin_line();

if(!get_line())
return new_module;
}

*(limit+1)= 0100;

scan:
while((c= *(loc++))!=0174&&c!=0100)
{
if(c==interior_semi)
c= 073;
out(c);/* Copy \TeX\ verbatim to output. */

#if(0)
if(out_ptr==out_buf+1&&(c==040
||c==tab_mark
))out_ptr--;
#endif
}

if(c==0174)
return 0174;/* Beginning of code mode. */

if(loc<=limit)
{/* Found an \.{@}. */
eight_bits cc;

if(*loc==0100)
{
out(0100);
loc++;
goto scan;
}


{
ASCII HUGE*b;

for(b= out_buf+1;b<=out_ptr;b++)
if(*b!=040)
break;

if(b>out_ptr)
out_ptr= out_buf;
}



SET_CASE(*loc);

if((cc= ccode[*(loc++)])!=big_line_break)
return cc;

if(loc>=limit)
return cc;


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


;/* An `\.{@\#\dots}' command. */
return cc;/* A |big_line_break| command. */
}
}

DUMMY_RETURN(ignore);
}



int copy_comment FCN((bal))/* copies \TeX\ code in comments */
int bal C1("Brace balance.")
{
ASCII c;/** Current character being copied. */
char terminator[2];
token_pointer tok_ptr0= tok_ptr;

in_comment= YES;

terminator[0]= *limit;terminator[1]= *(limit+1);

*limit= 040;/* Space to implement continued line.  Short commands will \
			be ended by this space. */

/* Especially when it comes to stars and asterisks, we need to know when \
we're copying \TeX. Since this is actually going into token memory instead \
of being transcribed directly to the output, we append the |copy_mode| flag \
to help us know where we are. For this to work properly, one must return \
only from the bottom of this function, because we append another \
|copy_mode| at the bottom. */
if(phase==2)
app_tok(copy_mode);

WHILE()
{
if(loc>limit)

{
if(!(long_comment||language==TEX))
{/* End of short comment. */
if(auto_semi&&*(tok_ptr-2)==073&&*(tok_ptr-1)==040)
tok_ptr-= 2;

/* Strip trailing spaces. */
while(*(tok_ptr-1)==040)
tok_ptr--;

/* If the last space happened to be escaped, kill the escape. */
if(*(tok_ptr-1)==0134&&*(tok_ptr-2)!=0134)
tok_ptr--;

/* Kill the trailing end-of-comment. */
if(*(tok_ptr-2)==052&&*(tok_ptr-1)==057)
tok_ptr-= 2;



if(bal==1)
{
if(phase==2)
{
if(language==TEX)
{
token_pointer t;

for(t= tok_ptr-1;t>tok_ptr0;t--)
if(*t!=040)break;

if(t==tok_ptr0&&*(t-4)==0134&&*(t-3)==0127&&*(t-2)==0103&&
*(t-1)==0173)
*(tok_ptr0-2)= 0170;/* Change \.{\\WC} to \.{\\Wx}. */
}



app_tok(0175);
}
bal= 0;
break;
}
else
{

err0_print(ERR_W,OC("Braces don't balance in comment"),0);



app_tok(040);/* this is done in case the previous character was~`\.\\' */

while(bal-->0)app_tok(0175);

bal= 0;
break;


;
}


}

if(!get_line())
{
if(language!=TEX)

err0_print(ERR_W,OC("Input ended in mid-comment"),0);

loc= cur_buffer+1;

app_tok(040);/* this is done in case the previous character was~`\.\\' */

while(bal-->0)app_tok(0175);

bal= 0;
break;


;
}

/* For \TeX, we concatenate adjacent lines that all begin with comment \
characters. */
if(language==TEX)
{
if(loc==limit)

if(bal==1)
{
if(phase==2)
{
if(language==TEX)
{
token_pointer t;

for(t= tok_ptr-1;t>tok_ptr0;t--)
if(*t!=040)break;

if(t==tok_ptr0&&*(t-4)==0134&&*(t-3)==0127&&*(t-2)==0103&&
*(t-1)==0173)
*(tok_ptr0-2)= 0170;/* Change \.{\\WC} to \.{\\Wx}. */
}



app_tok(0175);
}
bal= 0;
break;
}
else
{

err0_print(ERR_W,OC("Braces don't balance in comment"),0);



app_tok(040);/* this is done in case the previous character was~`\.\\' */

while(bal-->0)app_tok(0175);

bal= 0;
break;


;
}



for(;loc<=limit;loc++)
if(*loc!=040&&*loc!=tab_mark)break;

if(loc>limit)continue;

if(TeX[*loc]==TeX_comment)loc++;
else
{/* Unskip the white space. */
loc= cur_buffer;


if(bal==1)
{
if(phase==2)
{
if(language==TEX)
{
token_pointer t;

for(t= tok_ptr-1;t>tok_ptr0;t--)
if(*t!=040)break;

if(t==tok_ptr0&&*(t-4)==0134&&*(t-3)==0127&&*(t-2)==0103&&
*(t-1)==0173)
*(tok_ptr0-2)= 0170;/* Change \.{\\WC} to \.{\\Wx}. */
}



app_tok(0175);
}
bal= 0;
break;
}
else
{

err0_print(ERR_W,OC("Braces don't balance in comment"),0);



app_tok(040);/* this is done in case the previous character was~`\.\\' */

while(bal-->0)app_tok(0175);

bal= 0;
break;


;
}


}
}
}



/* Get the next character.  Convert a run of tabs into one tab. */
if(language==TEX)
c= *loc++;
else do
c= *(loc++);
while(c==tab_mark);

if(c==0174)break;/* Found beginning of code mode. */

if(c==052&&*loc==057&&long_comment)
{
loc++;/* Position after `\.{\starslash}'. */



if(bal==1)
{
if(phase==2)
{
if(language==TEX)
{
token_pointer t;

for(t= tok_ptr-1;t>tok_ptr0;t--)
if(*t!=040)break;

if(t==tok_ptr0&&*(t-4)==0134&&*(t-3)==0127&&*(t-2)==0103&&
*(t-1)==0173)
*(tok_ptr0-2)= 0170;/* Change \.{\\WC} to \.{\\Wx}. */
}



app_tok(0175);
}
bal= 0;
break;
}
else
{

err0_print(ERR_W,OC("Braces don't balance in comment"),0);



app_tok(040);/* this is done in case the previous character was~`\.\\' */

while(bal-->0)app_tok(0175);

bal= 0;
break;


;
}

;
}

/* It looks better in the \.{tex} file if tabs are replaced by spaces. \
Presumably this won't harm anything else. */
if(phase==2)

switch(c)
{
case tab_mark:
if(language==TEX)
APP_STR("\\quad");
else
app_tok(040);

break;

case interior_semi:
app_tok(073);
break;

case 045:
if(language==TEX)
app_tok(0134);

app_tok(c);
break;

default:
/* Basically, we just append the present character here.  However, compiler \
directives need to be escaped. */
if(doing_cdir)
switch(c)
{




case 0134:case 0173:case 0175

:

case 040:case 043:case 045:case 044:case 0136:case 0140:
case 0176:case 046:case 0137



:
app_tok(0134);
}

app_tok(c);
break;
}





if(c==0100)
{
if(*(loc++)!=0100)
{

err0_print(ERR_W,OC("Illegal use of @ in comment"),0);

loc-= 2;

if(phase==2)
tok_ptr--;



app_tok(040);/* this is done in case the previous character was~`\.\\' */

while(bal-->0)app_tok(0175);

bal= 0;
break;


;
}
}
else if(c==0134&&*loc!=0100&&phase==2)
app_tok(*(loc++))
else if(c==0173)
bal++;
else if(c==0175)
bal--;

;
}

if(phase==2)
app_tok(copy_mode);/* Negate the copying mode. */

*limit= terminator[0];*(limit+1)= terminator[1];

if(!long_comment&&*limit==0100&&loc>limit)
loc= limit;

in_comment= NO;
return bal;
}



SRTN C_parse FCN((mode0))/* Creates scraps from \cee\ tokens */
PARSING_MODE mode0 C1("")
{
name_pointer p;/* Identifier designator. */
LANGUAGE language0= language;/* Save the incoming language. */
PARSE_PARAMS parse_params0;

parse_params0= parse_params;/* Save parsing state. */

parsing_mode= mode0;


if(parsing_mode==INNER)
{/* Start fresh for parsing interior code. */
at_beginning= YES;
preprocessing= NO;
}

while(next_control<formatt)
{
if(nuweb_mode&&parsing_mode==INNER)

{
while(loc<limit)
{
if(*loc==0174)
{
next_control= *loc++;
break;
}

app(*loc++);
}

app_scrap(ignore_scrap,no_math);
}


else
{

{
room_for(6,4,4);/* Is there enough room?  (Check and justify these numbers!!!) */

if(next_control)lst_ampersand= NO;

switch(next_control)

{
case macro_module_name:
{
if(cur_module)
app(mod_flag+PTR_DIFF(sixteen_bits,cur_module,name_dir));
app_scrap(cur_module!=NULL?cur_module->mod_ilk:expr,maybe_math);
}

break;

case stmt_label:
case stringg:case constant:case verbatim:

if(next_control==stmt_label&&!isDigit(*id_first))/* Identifier as \
				statement label. */
{
p= id_lookup(id_first,id_loc,normal);
app(id_flag+PTR_DIFF(sixteen_bits,p,name_dir));
app_scrap(label,no_math);
}
else
{
if(next_control==constant||next_control==stmt_label)
APP_STR("\\WO{");

else if(next_control==stringg)

{
APP_STR(pfmt->typewritr);
app_tok(0173);
}



else APP_STR("\\={");



{
while(id_first<id_loc)
{
switch(*id_first)
{
case 054:*id_first= 061;app(0134);break;

case ordinary_space:
*id_first= 062;app(0134);break;

case tab_mark:
*id_first= 063;app(0134);break;

case discretionary_break:*id_first= 060;/* Falls through! */





case 0134:case 0173:case 0175

:

case 040:case 043:case 045:case 044:case 0136:case 0140:
case 0176:case 046:case 0137



:
app(0134);break;

case 0100:if(*(id_first+1)==0100)id_first++;
else
err0_print(ERR_W,OC("Double @ should be used in strings"),0);

}

app_tok(*id_first++);
}

/* End the macro. */
app(0175);
}



if(next_control==stmt_label){app_scrap(label,no_math);}
else{app_scrap(expr,yes_math);}
}

;
break;

case begin_format_stmt:in_format= YES;
case identifier:

p= id_lookup(id_first,id_loc,normal);


if(p->wv_macro)
{
WV_MACRO HUGE*w= p->wv_macro;
ASCII HUGE*s= w->text;

if(w->cat)
{
APP_STR(pfmt->id);
app(0173);
}

while(*s)
app_tok(*s++);

if(w->cat)app(0175);

app_scrap(p->ilk?p->ilk:expr,w->cat?maybe_math:yes_math);
}
else if(p->reserved_word&(boolean)language)
{
app(res_flag+PTR_DIFF(sixteen_bits,p,name_dir));
app_scrap(p->ilk==normal?expr:p->ilk,maybe_math);
/* See the inverse construction in \.{reserved}:|save_words|. */
}
else
{
app(id_flag+PTR_DIFF(sixteen_bits,p,name_dir));
app_scrap(expr,maybe_math);/* Not a reserved word. */
}

;break;
case TeX_string:

APP_STR("\\hbox{");while(id_first<id_loc)app_tok(*id_first++);
app(0175);app_scrap(expr,maybe_math);

;break;
case begin_language:

switch(language)
{
case NO_LANGUAGE:
CONFUSION("append scraps for begin_language",
"Language isn't defined");

case C:
case C_PLUS_PLUS:
case LITERAL:
column_mode= NO;break;

case FORTRAN:
case FORTRAN_90:
case RATFOR:
case RATFOR_90:
if(mode0==OUTER&&!free_form_input)
{
loc= limit+1;/* Skip rest of line. */
chk_end= NO;
column_mode= YES;
}


break;

case TEX:
if(mode0==OUTER)
{
loc= limit+1;/* Skip rest of line. */
chk_end= NO;
column_mode= YES;
}


break;

case NUWEB_OFF:
case NUWEB_ON:
CONFUSION("append scraps for begin_language","Invalid language");
}

set_language(language);
break

;break;

case new_output_file:
{
APP_STR(upper_case_code?"\\WOut{":"\\Wout{");
*id_loc= '\0';
id_first= esc_buf(mod_text+1,mod_end,id_first,YES);
was_opened(id_first,upper_case_code,&params.OUTPUT_FILE_NAME,NULL);
if(upper_case_code)
was_opened(id_first,upper_case_code,
&global_params.OUTPUT_FILE_NAME,NULL);
while(*id_first)
app_tok(*id_first++);
app(0175);

app(force);

app_scrap(ignore_scrap,no_math);

if(nuweb_mode)
{/* !!!!! */
next_control= begin_meta;
continue;
}
}

break;


case toggle_output:

{
static int outer_include_depth;

if(output_on)
{
if(phase==2)
{
flush_buffer(out_ptr,NO);
}
outer_include_depth= incl_depth;
output_on= NO;
}
else if(incl_depth<=outer_include_depth)
{
output_on= YES;
}
}



{
if(output_on)app(Turn_output_on);
else
{
app(force);
app(Turn_output_off);
}

app_scrap(ignore_scrap,no_math);
}


break;


case macro_space:app(040);app_scrap(space,maybe_math);break;



case 0134:
APP_STR("\\ttBS");
app_scrap(ignore_scrap,no_math);
break;

case 012:
app(040);
app_scrap(newline,maybe_math);
break;

case 057:
if(in_format)
{
app(next_control);
app_scrap(expr,no_math);/* ``|@r format(//e10.5/f5.2)|'' */
}
else if(in_data)
{
app(0173);app(next_control);app(0175);
app_scrap(slash_like,maybe_math);
}
else
{
app_overload();/* ``|a/b|'' */
}
break;

case 056:
app(next_control);app_scrap(binop,yes_math);break;

case 053:/* Handle \FORTRAN's |@r +1.0|; now also ANSI~C: ``|x = +2.5;|'' */
case 074:
case 076:
case 075:
case 045:
case 041:
case 0176:
case 055:
case 052:
case 0174:
case 077:
case 0136:
app_overload();break;

case 046:
lst_ampersand= YES;
app_overload();break;

case 043:
switch(*loc)
{
case 047:
APP_STR("\\Nq");
loc++;
break;

case 042:
APP_STR("\\NQ");
loc++;
break;

default:
APP_STR("\\#");
break;
}

app_scrap(expr,maybe_math);
break;

case ignore:case xref_roman:case xref_wildcard:
case xref_typewriter:break;

case 050:app(next_control);app_scrap(lpar,maybe_math);break;
case 051:app(next_control);app_scrap(rpar,maybe_math);break;

case 0133:app(next_control);app_scrap(lbracket,yes_math);break;
case 0135:app(next_control);app_scrap(rbracket,yes_math);break;

case 0173:APP_STR("\\{");app_scrap(lbrace,yes_math);break;
case 0175:APP_STR("\\}");app_scrap(rbrace,yes_math);break;
case 054:app(054);app_scrap(comma,maybe_math);break;

case end_format_stmt:in_format= NO;/* Falls through to the next case, \
		which appends the semi. */
case interior_semi:
in_data= NO;
app(073);app_scrap(semi,maybe_math);break;
case 073:
in_data= NO;
if(!is_FORTRAN_(language)||prn_semis)
app(073);
app_scrap(semi,maybe_math);break;

case 072:app(072);app_scrap(colon,maybe_math);
break;
case 0140:
APP_STR("\\LA");app_scrap(expr,maybe_math);
break;




/* Overloaded operators can be defined dynamically in \FORTRAN-88. These \
are generically labelled by |dot_const|. The |dot_code| routine fills the \
structure |dot_op| with the macro name and category corresponding to the \
operator. */
case dot_const:
next_control= identifier;
id_first= dot_op.name+1;
id_loc= id_first+STRLEN(id_first);
app_overload();
break;

case eq_gt:APP_STR("\\WPtr");/* `$\WPtr$' */app_scrap(binop,yes_math);
break;


case ellipsis:
if(C_LIKE(language))
{
APP_STR("\\dots");/* `|...|' */

app_scrap(int_like,maybe_math);
}
else app_overload();

break;

case not_eq:
case lt_eq:
case gt_eq:
case eq_eq:
case and_and:
case or_or:
case plus_plus:
case minus_minus:
case minus_gt:
case gt_gt:
case lt_lt:
case star_star:
case slash_slash:
case compound_assignment:
app_overload();break;

case paste:APP_STR("\\NN");/* `|##|' */app_scrap(ignore_scrap,maybe_math);
break;


case dont_expand:APP_STR("\\NP");/* `|#!|' */
app_scrap(ignore_scrap,maybe_math);
break;


case auto_label:APP_STR("\\NC");/* `|#:|' */
app_scrap(ignore_scrap,maybe_math);
break;


case all_variable_args:
APP_STR("\\ND");/* `|#.| */
app_scrap(expr,maybe_math);
break;


case colon_colon:
if(C_LIKE(language))
{

APP_STR("\\CC");/* `|a::b|' */
app_scrap(unop,yes_math);
}
else
{
APP_STR("\\CF");/* `|@r a::b|' */

app_scrap(binop,yes_math);
}
break;

case left_array:
APP_STR("\\LS");/* `|@r (/|' */

app_scrap(lpar,yes_math);
break;

case right_array:
APP_STR("\\SR");/* `|@r /)|' */

app_scrap(rpar,yes_math);
break;




case force_line:APP_STR("\\]");app_scrap(ignore_scrap,yes_math);break;
case thin_space:APP_STR("\\,");app_scrap(ignore_scrap,yes_math);break;
case math_break:app(opt);APP_STR("0");
app_scrap(ignore_scrap,yes_math);break;
case line_break:app(force);app_scrap(ignore_scrap,no_math);break;

case left_preproc:
app(force);
if(parsing_mode==OUTER)APP_STR("\\4");/* Backspace for beauty. */
app_scrap(lproc,no_math);break;

case right_preproc:
app(force);app_scrap(rproc,no_math);break;

case no_mac_expand:
APP_STR("\\WTLD");app_scrap(expr,maybe_math);break;

case begin_meta:

{
if(!nuweb_mode)
app(force);

app(toggle_meta);
APP_STR(w_style.misc.meta.code.begin);

column_mode= NO;
scanning_meta= YES;

WHILE()
{
if(loc>=limit)/* !!!!! */
{
app(012);
if(!get_line())
break;
}

while(loc<limit)
{
if(*loc==0100)

{
switch(ccode[*(loc+1)])
{
case 0100:
loc++;
break;

case end_meta:
if(!nuweb_mode&&((FORTRAN_LIKE(language)&&!free_form_input)
||(language==TEX)))

{
loc= limit+1;/* Skip rest of line. */
chk_end= NO;
column_mode= YES;
}



get_line();
goto done_meta;

case invisible_cmnt:
if(*(loc+2)==045)
eat_blank_lines= YES;

app(012);
get_line();

if(eat_blank_lines)
{
eat_blank_lines= NO;

while(loc>=limit)
if(!get_line())
goto done_meta;
}

continue;

case new_module:
goto done_meta;/* !!!!! */

case line_break:
if(loc[2]==052||loc[2]==057)
{/* Verbatim comment. */
loc++;
break;
}

/* Falls through! */

case thin_space:
case no_line_break:case join:
case pseudo_semi:case pseudo_expr:case pseudo_colon:
case compiler_directive:case Compiler_Directive:
case no_index:case yes_index:
case begin_bp:case insert_bp:
loc+= 2;
continue;

case big_line_break:
break;/* To handle preprocessor statements easily. */

default:
if(nuweb_mode)
goto done_meta;/* !!!!! */

break;
}
}


app(*loc++);
}
}

done_meta:
APP_STR(w_style.misc.meta.code.end);
app(toggle_meta);

if(!nuweb_mode)
app(force);

app_scrap(ignore_scrap,no_math);
scanning_meta= NO;
}


break;

case end_meta:
if(!nuweb_mode&&((FORTRAN_LIKE(language)&&!free_form_input)
||(language==TEX)))

{
loc= limit+1;/* Skip rest of line. */
chk_end= NO;
column_mode= YES;
}



get_line();
APP_STR(w_style.misc.meta.code.end);
app(force);
app_scrap(ignore_scrap,no_math);
scanning_meta= NO;
break;




case big_line_break:app(big_force);app_scrap(ignore_scrap,no_math);break;
case no_line_break:app(big_cancel);APP_STR("\\ ");app(big_cancel);
app_scrap(ignore_scrap,no_math);break;

case pseudo_expr:app_scrap(expr,maybe_math);break;
case pseudo_semi:app_scrap(semi,maybe_math);break;
case pseudo_colon:app_scrap(colon,maybe_math);break;

case join:APP_STR("\\WJ");app_scrap(ignore_scrap,no_math);break;


case protect_code:

err0_print(ERR_W,OC("You can't do that in code text"),0);

break;



default:app(next_control);app_scrap(ignore_scrap,maybe_math);break;
}
}

;
next_control= get_next();
}

if(next_control==0174||next_control==begin_comment)
break;


if(next_control==begin_language&&!ok_to_define
&&parsing_mode==OUTER)
return;
}

/* If the language has changed, append stuff to restore it. */
if(language!=language0)
{
app_tok(begin_language);
app(lan_num(language0));
app_scrap(ignore_scrap,no_math);
}

if(parsing_mode==INNER)
parse_params= parse_params0;/* Restore incoming values. */
}



SRTN set_language FCN((language0))
LANGUAGE language0 C1("")
{
char language_line[50];

language= language0;

app_tok(begin_language);
app(lan_num(language));

if(parsing_mode==OUTER)
{
sprintf(language_line,"\\LANGUAGE{%s}",
(char*)LANGUAGE_CODE(language));
APP_STR(language_line);

}

app_scrap(language_scrap,no_math);
}



text_pointer C_translate(VOID)
{
text_pointer p;/* Points to the translation. */
scrap_pointer save_base;/* Holds original value of |scrp_base|. */
PARAMS outer_params;
PARSE_PARAMS parse_params0;

outer_params= params;
parse_params0= parse_params;

save_base= scrp_base;
scrp_base= scrp_ptr+1;/* Empty work space after last existing scrap. */

/* We enclose code fragments with the \TeX\ macro~\.{\\WCD\{\dots\}}. */
if(output_protect)
APP_STR("\\protect");

APP_STR("\\WCD{");app_scrap(ignore_scrap,no_math);

if(nuweb_mode)
{
APP_STR("{\\tt ");
app_scrap(ignore_scrap,no_math);
}

while(next_control<=module_name)
{
C_parse(INNER);/* Get the scraps together. */

if(next_control==0174)
break;



if(next_control<module_name)
{
switch(next_control)
{
case m_if:case m_ifdef:case m_ifndef:
case m_undef:case m_else:
case m_elif:case m_endif:
case m_for:case m_endfor:
case m_line:
case WEB_definition:
pre_scrap(next_control);
break;

default:

err0_print(ERR_W,OC("You can't do that in code text"),0);

break;
}
next_control= get_next();
}
else if(next_control==module_name)
{

{
if(cur_module)
app(mod_flag+PTR_DIFF(sixteen_bits,cur_module,name_dir));
app_scrap(cur_module!=NULL?cur_module->mod_ilk:expr,maybe_math);
}


next_control= (nuweb_mode?begin_meta:get_next());/* !!!!! */
}

;

if(next_control==0174)
break;
}

app_tok(cancel);app_scrap(ignore_scrap,maybe_math);
/* Place a |cancel| token as a final ``comment''. */

if(nuweb_mode)
app(0175);
#if 0
else
app_scrap(semi,maybe_math);/* Append a pseudo-semicolon to try to \
			force the code fragments to reduce to full statements. */
#endif

if(output_protect)
{
app(protect_code);
app_scrap(ignore_scrap,no_math);
}

app(0175);app_scrap(ignore_scrap,no_math);

if(next_control!=0174)

err0_print(ERR_W,OC("Missing '|' after code text"),0);


p= translate(INNER);/* Make the translation. */

if(scrp_ptr>mx_scr_ptr)
mx_scr_ptr= scrp_ptr;

scrp_ptr= scrp_base-1;/* Restore old |scrp_ptr|. */
scrp_base= save_base;/* Scrap the scraps. */

params= outer_params;
frz_params();

parse_params= parse_params0;

return p;
}



SRTN outr_parse(VOID)/* makes scraps from \cee\ tokens and comments */
{
int bal;/* Brace level in comment. */
text_pointer p,q;/* Partial comments.  |p|: Stuff before `\Cb'; |q|: `\Cb'. */

while(next_control<formatt)
{
if(next_control!=begin_comment)
C_parse(OUTER);
else

{/* Append a comment/compiler directive. */
if(doing_cdir)

{
outer_char HUGE*s= t_style.cdir_start[language_num];
int n= 2*STRLEN(s)+1;
/* The factor of~2 counts possible escapes, and the 1 takes care of |'\0'|. */
ASCII HUGE*temp= GET_MEM("temp_cdir",n,ASCII);
ASCII HUGE*start= GET_MEM("start_cdir",n,ASCII);

STRCPY(start,s);
to_ASCII((outer_char HUGE*)start);

room_for(9+n,3,1);/* Tokens: */

app(force);
APP_STR("\\WCDIR{");
esc_buf(temp,temp+n,start,YES);APP_STR(to_outer(temp));

FREE_MEM(temp,"temp_cdir",n,ASCII);
FREE_MEM(start,"start_cdir",n,ASCII);
}


else

{
room_for(8,3,1);/* Tokens:  `\.{;{ }\ { }\\{ }W{ }C\{{ }\}{ }\It{force}}'. */

if(Fortran88)
{
if(free_Fortran&&lst_ampersand)
{
scrp_ptr--;/* Kill off the \.{\&}. */
}
else if(!at_beginning&&auto_semi)
{
app(073);
}
last_was_cmnt= YES;
}

app(break_space);
APP_STR(long_comment?"\\WC{":"\\Wc{");/* Long/short comment. */

}



bal= copy_comment(1);/* Closing brace is inserted here. */
next_control= ignore;

if(doing_cdir&&bal>0)

err0_print(ERR_W,OC("Can't have vertical bars in @! compiler directives"),0);

doing_cdir= NO;

/* Handle code mode inside comments. */
while(bal>0)
{
in_comment= YES;
p= text_ptr;freeze_text;

q= C_translate();
/* at this point we have |tok_ptr+7<=max_toks| */
app(tok_flag+PTR_DIFF(sixteen_bits,p,tok_start));app(inner_tok_flag+PTR_DIFF(sixteen_bits,q,tok_start));

if(next_control==0174)
{
bal= copy_comment(bal);
next_control= ignore;
}
else
bal= 0;/* An error has been reported. */
}

app(force);app_scrap(ignore_scrap,no_math);/* the full comment \
					becomes a scrap */
}


}
}



SRTN push_level FCN((p))/* Suspends the current level */
text_pointer p C1("")
{
if(stck_ptr==stck_end)OVERFLW("stack levels","kw");

if(stck_ptr>stack){/* save current state */
stck_ptr->end_field= cur_end;
stck_ptr->tok_field= cur_tok;
stck_ptr->mode_field= cur_mode;
}

stck_ptr++;

if(stck_ptr>mx_stck_ptr)mx_stck_ptr= stck_ptr;

cur_tok= *p;cur_end= *(p+1);
}



SRTN pop_level(VOID)
{
cur_end= (--stck_ptr)->end_field;
cur_tok= stck_ptr->tok_field;cur_mode= stck_ptr->mode_field;
}


eight_bits get_output(VOID)/* Returns the next token of output */
{
sixteen_bits a;/* Current item read from |tok_mem| */

restart:while(cur_tok==cur_end)pop_level();/* Get back to unfinished \
		level. */

a= *(cur_tok++);

if(a>=0400)
{
cur_name= a%id_flag+name_dir;

switch(a/id_flag)
{
case 2:return res_word;/* |a==res_flag+cur_name| */
case 3:return mod_name;/* |a==mod_flag+cur_name| */
case 4:push_level(a%id_flag+tok_start);goto restart;
/* |a==tok_flag+cur_name| */
case 5:push_level(a%id_flag+tok_start);cur_mode= inner;
goto restart;
/* |a==inner_tok_flag+cur_name| */
default:return identifier;/* |a==id_flag+cur_name| */
}
}

/* If we get here, it's a single-byte token. */
return(eight_bits)a;
}



SRTN output_C(VOID)/* Outputs the current token list */
{
token_pointer save_tok_ptr;
text_pointer save_text_ptr;
eight_bits save_next_control;/* Values to be restored */
text_pointer p;/* Translation of the \cee\ text */

save_tok_ptr= tok_ptr;save_text_ptr= text_ptr;
save_next_control= next_control;

next_control= ignore;p= C_translate();
app(inner_tok_flag+PTR_DIFF(sixteen_bits,p,tok_start));
scanning_meta= NO;

make_output();/* output the list */

if(text_ptr>mx_text_ptr)mx_text_ptr= text_ptr;
if(tok_ptr>mx_tok_ptr)mx_tok_ptr= tok_ptr;

text_ptr= save_text_ptr;tok_ptr= save_tok_ptr;/* Forget the tokens */
next_control= save_next_control;/* Restore |next_control| to original \
		state */
}



SRTN phase2(VOID)
{
extern outer_char wbflnm0[];
IN_COMMON int num_ifiles;

phase= 2;/* Prepare for second phase. */
the_part= LIMBO;

params= global_params;
frz_params();

rst_input();
strt_off= ending_off= NO;
writing(YES,tex_fname);if(tex_file==stdout)putchar('\n');

fin_line();/* Write out the ``\.{\\input\ fwebmac.sty}''. */


{
#define TEMP_LEN (MAX_FILE_NAME_LENGTH + 100)
#define ARGS \
 w_style.misc.LaTeX.class.options, w_style.misc.LaTeX.package.options, \
 w_style.misc.LaTeX.class.file, w_style.misc.LaTeX.package.file, \
 w_style.misc.TeXindent, \
 w_style.misc.codeindent, \
 w_style.contents.tex, \
 pfmt->reserved, pfmt->RESERVED, \
  pfmt->short_id, \
  pfmt->id, pfmt->ID, \
  pfmt->id_outer, pfmt->ID_OUTER, \
  pfmt->id_inner, pfmt->ID_INNER, \
  pfmt->intrinsic, \
  pfmt->keyword, pfmt->KEYWORD, \
  pfmt->typewritr, \
 w_style.indx.encap_prefix, \
 w_style.misc.doc_preamble, w_style.misc.doc_postamble, \
 w_style.indx.name

outer_char temp0[TEMP_LEN];
outer_char HUGE*temp1= GET_MEM("temp1",TEMP_LEN,outer_char);


if(
nsprintf(temp0,OC("\n\\Wbegin[%s;%s]{%s;%s} {%s} {%s} {%s}\n\
{{%s%s} {%s} {%s%s} {%s%s} {%s%s} {%s} {%s%s} {%s}}\n\
{%s} {%s;%s} {%s}"),1,ARGS)>=(int)(TEMP_LEN))OVERFLW("temp0","");
OUT_STR(xpn_name(&temp1,TEMP_LEN,temp0,wbflnm0));
FREE(temp1);
fin_line();

#undef TEMP_LEN
#undef ARGS
}



module_count= 0;
num_ifiles= 0;

copy_limbo();
flush_buffer(out_buf,NO);/* Insert a blank line---it looks nice. */

math_flag= NO;

while(!input_has_ended)

{
the_part= TEX_;

/* Again, all modules start off in the global language. */
params= global_params;
frz_params();
scanning_meta= NO;/* For safety. */

module_count++;


{


if(STRCMP(last_include_file,this_include_file)!=0)
{
STRCPY(last_include_file,this_include_file);
OUT_STR("\\WIF{");out_fname(this_include_file);
OUT_STR("}");
fin_line();
}

;

if(!in_module&&output_on)
{
OUT_STR(*(loc-1)==052?"\\WN":"\\WM");


in_module= YES;

out_mod(module_count,NO_ENCAP);OUT_STR(". ");
}

progress();/* Progress report to terminal. */
}

;
save_position;

trns_TeX();
trns_defn();
trns_code();



if(this_module>name_dir)
{


first_xref= (xref_pointer)this_module->xref;
this_xref= first_xref->xlink;/* Bypass current module number */

if(this_xref->num>def_flag)
{
mid_xref= this_xref;cur_xref= 0;/* This value doesn't matter */

do
{
next_xref= this_xref->xlink;this_xref->xlink= cur_xref;
cur_xref= this_xref;this_xref= next_xref;
}
while(this_xref->num>def_flag);

first_xref->xlink= cur_xref;
}
else mid_xref= xmem;/* First list null */

cur_xref= xmem;

while(this_xref!=xmem)
{
next_xref= this_xref->xlink;this_xref->xlink= cur_xref;
cur_xref= this_xref;this_xref= next_xref;
}

if(mid_xref>xmem)mid_xref->xlink= cur_xref;
else first_xref->xlink= cur_xref;

cur_xref= first_xref->xlink;

;
footnote(def_flag);footnote(0);
}

;

{
if(in_module&&output_on)
{
outer_char temp[100];


if(
nsprintf(temp,OC("\\fi %% End of %s"),1,MOD_TRANS(module_count))>=(int)(100))OVERFLW("temp","");
OUT_STR(temp);fin_line();

mfree();
in_module= NO;

flush_buffer(out_buf,NO);/* Insert a blank line for beauty. */
}
}

;
}


}



SRTN trns_TeX(VOID)
{
the_part= TEX_;
parsing_mode= OUTER;

do
{
next_control= copy_TeX();

switch(next_control)
{




case begin_C:
case begin_RATFOR:
case begin_FORTRAN:
case begin_LITERAL



:
loc--;/* Position to letter after \.{@}. Falls \
through to general case |L_switch|. */

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




if(module_count==0)
global_params= params;

ini0_language();


if(Fortran88&&auto_semi)
{
loc= limit+1;
chk_end= NO;
}



}


break;

case begin_nuweb:
nuweb_mode= !NUWEB_MODE;

if(module_count==0)
global_params= params;
break;



case toggle_output:
out_skip();
break;

case 0174:ini_stack;output_C();break;

case math_break:
out(0174);/* Literal vertical bar. */
break;

case 0100:
out(0100);/* Literal '\.{@}'. */
break;

case invisible_cmnt:loc= limit+1;break;

case begin_meta:
OUT_STR(w_style.misc.meta.TeX.begin);
break;

case end_meta:
OUT_STR(w_style.misc.meta.TeX.end);
break;

case TeX_string:
case xref_roman:case xref_wildcard:case xref_typewriter:
case macro_module_name:case module_name:
loc-= 2;next_control= get_next();/* skip to \.{@>} */

if(next_control==TeX_string)

err0_print(ERR_W,OC("TeX string should be in code text only"),0);break;


case thin_space:
case line_break:case big_line_break:case no_line_break:case join:
case pseudo_semi:case pseudo_expr:case pseudo_colon:
case compiler_directive:case Compiler_Directive:
case no_index:
case begin_bp:case insert_bp:

err0_print(ERR_W,OC("You can't do that in TeX text"),0);break;


case protect_code:
if(*loc!=0174)

err0_print(ERR_W,OC("@p should be immediately followed by '|'"),0);

output_protect= YES;
break;

case USED_BY_NEITHER:

err0_print(ERR_W,OC("Invalid `@%c' ignored"),1,XCHR(*(loc-1)));
break;
}
}
while(next_control<formatt);

output_protect= NO;
}



SRTN trns_defn(VOID)
{
boolean overload_ops0= overload_ops;

the_part= DEFINITION;
parsing_mode= OUTER;

if(next_control<begin_code)
{/* definition part non-empty */
emit_space_if_needed;save_position;

{
if(output_on)app(Turn_output_on);
else
{
app(force);/* If we don't do this, output is turned off before the \
contents of the last line are printed. */
app(turn_output_off);
}

app_scrap(ignore_scrap,no_math);
}


}

while(next_control<begin_code)

{
eight_bits last_control= next_control;
boolean nuweb_mode0;

ini_stack;

switch(next_control)
{
case begin_comment:
case invisible_cmnt:
break;

default:

{
if(output_on)app(Turn_output_on);
else
{
app(force);/* If we don't do this, output is turned off before the \
contents of the last line are printed. */
app(turn_output_off);
}

app_scrap(ignore_scrap,no_math);
}


break;
}

nuweb_mode0= nuweb_mode;
nuweb_mode= NO;

switch(next_control)
{
case formatt:

{
LANGUAGE saved_language= language;
scrap_pointer scrp_ptr0;

if(upper_case_code)
{
SUPPRESS(Formats);
}
else
{
SUPPRESS(formats);
}

/* Mark formats that are not in the global language. */
app_proc(next_control);/* |formatt|. */
scrp_ptr0= scrp_ptr;/* Save to help check valid format. */
app_scrap(expr,maybe_math);/* this will produce `\&{format}'. The \
	macro inserts a blank after \&{format}. */


if(language==TEX)
language= C;/* This kludge ought to be removed! */

next_control= get_next();/* First field: identifier, module name, or~'\.`'. */

if(next_control==identifier||next_control==module_name)

{
if(next_control==identifier)
APP_ID;
else
app(mod_flag+PTR_DIFF(sixteen_bits,cur_module,name_dir));

APP_STR("\\ ");

next_control= get_next();/* Second field: identifier. */

if(next_control==identifier)
{
APP_ID;

{
app_scrap(expr,maybe_math);
app_scrap(semi,maybe_math);/* Pseudo-semi. */

sharp_include_line= NO;

next_control= get_next();
}


}
}


else if(next_control==0140)

{

{
APP_STR(pfmt->typewritr);
app_tok(0173);
}


app(0140);
if((next_control= get_TeX())==constant)
APP_STR((outer_char*)id_first);
app(0175);

APP_STR("\\ ");

next_control= get_next();/* Integer category code. */

if(next_control==constant)
{
APP_STR("\\WO{");

while(id_first<id_loc)
app_tok(*id_first++);

app(0175);


{
app_scrap(expr,maybe_math);
app_scrap(semi,maybe_math);/* Pseudo-semi. */

sharp_include_line= NO;

next_control= get_next();
}


}
}



if(scrp_ptr!=scrp_ptr0+3)

err0_print(ERR_W,OC("Improper format definition"),0);


/* The following doesn't work right if the format command is immediately \
followed by a language-changing command. */
if(saved_language==TEX)
language= saved_language;
}


break;

case limbo_text:

{
SUPPRESS(limbo);

app_proc(next_control);
app_scrap(expr,maybe_math);

/* First field: String. */
if((next_control= get_next())!=stringg)

err0_print(ERR_W,OC("A string must follow @l"),0);
}


break;

case op_def:

{
SUPPRESS(v);

overload_ops= NO;

app_proc(next_control);
app_scrap(expr,maybe_math);

/* First field: The operator to be overloaded. */
if(valid_op(next_control= get_next()))
{

{
switch(next_control)
{
case identifier:

err0_print(ERR_W,OC("For future compatibility, please use syntax .NAME. for \
overloading dot operators"),0);

APP_ID;
break;

case dot_const:

{
APP_STR(pfmt->typewritr);
app_tok(0173);
}


app(wt_style.dot_delimiter.begin);
app_ASCII_str(dot_op.name+1);
app(wt_style.dot_delimiter.end);
app(0175);
break;

default:
app(0173);
app_overload();
app(0175);
break;
}

app_scrap(expr,yes_math);
}



app(040);app_scrap(expr,no_math);

/* Second field: Replacement text. */
if((next_control= get_next())==stringg)
{

{
APP_STR(pfmt->typewritr);
app_tok(0173);
}



{
while(id_first<id_loc)
{
switch(*id_first)
{
case 054:*id_first= 061;app(0134);break;

case ordinary_space:
*id_first= 062;app(0134);break;

case tab_mark:
*id_first= 063;app(0134);break;

case discretionary_break:*id_first= 060;/* Falls through! */





case 0134:case 0173:case 0175

:

case 040:case 043:case 045:case 044:case 0136:case 0140:
case 0176:case 046:case 0137



:
app(0134);break;

case 0100:if(*(id_first+1)==0100)id_first++;
else
err0_print(ERR_W,OC("Double @ should be used in strings"),0);

}

app_tok(*id_first++);
}

/* End the macro. */
app(0175);
}


app_scrap(expr,yes_math);

/* Third field: Cat of this operator. */
if(valid_op(next_control= get_next()))
{
app(040);app_scrap(expr,no_math);


{
switch(next_control)
{
case identifier:

err0_print(ERR_W,OC("For future compatibility, please use syntax .NAME. for \
overloading dot operators"),0);

APP_ID;
break;

case dot_const:

{
APP_STR(pfmt->typewritr);
app_tok(0173);
}


app(wt_style.dot_delimiter.begin);
app_ASCII_str(dot_op.name+1);
app(wt_style.dot_delimiter.end);
app(0175);
break;

default:
app(0173);
app_overload();
app(0175);
break;
}

app_scrap(expr,yes_math);
}



next_control= get_next();
}
}
}
}


break;

case macro_def:

{
SUPPRESS(w);

app_proc(next_control);
app_scrap(expr,maybe_math);

/* First field:  The identifier to be overloaded. */
if((next_control= get_next())==identifier)
{
ASCII HUGE*id_first0,HUGE*id_loc0;

/* Remember first identifier. */
id_first0= id_first;
id_loc0= id_loc;

APP_ID;

app(040);app_scrap(expr,no_math);

/* Second field:  Replacement text. */
switch(next_control= get_next())
{
case 0134:
if((next_control= get_next())!=identifier)break;
goto quick_code1;

case QUICK_FORMAT:
id_first= id_first0;
id_loc= id_loc0;

quick_code1:

{
APP_STR(pfmt->typewritr);
app_tok(0173);
}


APP_STR("\\\\");
*id_loc= '\0';/* Make name into string. */
app_ASCII_str(id_first);
app(0175);
app_scrap(expr,yes_math);
next_control= get_next();
break;

case stringg:

{
APP_STR(pfmt->typewritr);
app_tok(0173);
}



{
while(id_first<id_loc)
{
switch(*id_first)
{
case 054:*id_first= 061;app(0134);break;

case ordinary_space:
*id_first= 062;app(0134);break;

case tab_mark:
*id_first= 063;app(0134);break;

case discretionary_break:*id_first= 060;/* Falls through! */





case 0134:case 0173:case 0175

:

case 040:case 043:case 045:case 044:case 0136:case 0140:
case 0176:case 046:case 0137



:
app(0134);break;

case 0100:if(*(id_first+1)==0100)id_first++;
else
err0_print(ERR_W,OC("Double @ should be used in strings"),0);

}

app_tok(*id_first++);
}

/* End the macro. */
app(0175);
}


app_scrap(expr,yes_math);
next_control= get_next();
break;
}
}
}


break;

case begin_comment:
doing_cdir= NO;
break;

case invisible_cmnt:
loc= limit+1;/* Skip the line. */
/* Skip any other extraneous material that doesn't belong in the definition \
section. */
while((next_control= get_next())<formatt
&&next_control!=begin_comment);
continue;

default:

{
LANGUAGE saved_language= language;

if(next_control==definition)
SUPPRESS(outer_macros);

if(next_control==WEB_definition)
SUPPRESS(macros);

app_proc(next_control);

if(language==TEX)
language= C;

if(((C_LIKE(language)||language==LITERAL)&&
next_control<=WEB_definition)||
next_control==WEB_definition||
next_control==m_ifdef||
next_control==m_ifndef||next_control==m_undef)
{
if((next_control= get_next())!=identifier&&next_control!=0133)
{

err0_print(ERR_W,OC("Improper macro definition: \
expected identifier"),0);

}
else
{
if(next_control==0133)

{
APP_STR("\\Wauto");
get_string(0133,'\0');
*id_loc= '\0';
app_ASCII_str(id_first);
next_control= get_next();
}



app(044);APP_ID;

if(*loc==050)

{
reswitch:
next_control= get_next();
the_switch:
switch(next_control)
{
case 050:
app(next_control);
next_control= get_next();
if(next_control==051)
{
b_app(0134);b_app(054);/* Extra thinspace for beauty. */
goto done_arg;
}
else goto the_switch;

case 054:
app(next_control);goto reswitch;

case identifier:
APP_ID;
goto reswitch;

case ellipsis:
APP_STR("\\dots");
if((next_control= get_next())!=051)
{

err0_print(ERR_M,OC("Improper macro \
definition: expected ')' after ellipsis"),0);
break;
}

case 051:
done_arg:
app(next_control);app(0176);
next_control= get_next();break;

default:

err0_print(ERR_M,OC("Improper macro definition: \
unrecognized token in argument list"),0);
break;
}
}


else
{/* Id not followed by parenthesis. */
next_control= get_next();
}

app(044);app(break_space);
app_scrap(ignore_scrap,no_math);/* scrap won't take part in \
						the parsing */
}
}
else
next_control= get_next();

if(saved_language==TEX)
language= saved_language;
}


break;
}

ok_to_define= NO;
nuweb_mode= nuweb_mode0;

outr_parse();/* Scan the definition or whatever. */

if(auto_app_semi&&last_control==WEB_definition)
{app_scrap(semi,maybe_math);}

overload_ops= overload_ops0;
fin_C();/* Finish up the definition or whatever. */
ok_to_define= YES;
}


}



SRTN fin_C(VOID)/* Finishes a definition or a \cee\ part. */
{
text_pointer p;/* Translation of the scraps. */
boolean current_output_state= output_on;

if(!suppress_defn)
{
column_mode= NO;

app_tok(force);/* Last thing in the translation. */
app_scrap(ignore_scrap,no_math);
/* The last stuff doesn't count for syntax. */

/* We've accumulated all the stuff for one part.  Translate it, then print \
it. */
p= translate(OUTER);

app(tok_flag+PTR_DIFF(sixteen_bits,p,tok_start));
make_output();/* Output the list. */

if(out_ptr>out_buf+1)

{
if(*(out_ptr-1)==0134)
{



if(*out_ptr==066)
out_ptr-= 2;/* Throw away the \.{\\6}. */
else if(*out_ptr==067)
{
out_ptr-= 2;/* Throw away the \.{\\7}\dots */
OUT_STR("\\WY");
/* and replace it with \.{\\WY}. */
}
}
}



OUT_STR("\\par");fin_line();

/* Accumulate statistics. */
if(text_ptr>mx_text_ptr)
mx_text_ptr= text_ptr;
if(tok_ptr>mx_tok_ptr)
mx_tok_ptr= tok_ptr;
if(scrp_ptr>mx_scr_ptr)
mx_scr_ptr= scrp_ptr;
}
else
suppress_defn= NO;

/* Forget the tokens and the scraps. */
tok_ptr= tok_mem+1;text_ptr= tok_start+1;scrp_ptr= scrp_info;

#if(0)
if(strt_off)output_on= strt_off= ending_off= NO;
if(ending_off)
{
strt_off= ending_off= NO;
output_on= YES;
}
#endif

output_on= current_output_state;
}



SRTN app_temp FCN((letter,arg))
CONST outer_char letter[]C0("")
CONST outer_char arg[]C1("")
{
char temp[50];

sprintf(temp,"\\W%s:%s:",(char*)letter,(char*)arg);
APP_STR(temp);
}



SRTN app_proc FCN((next_control))
eight_bits next_control C1("")
{
if(the_part==DEFINITION)
{

{
APP_STR("\\WP");

}



if(yskipped)
{

{
app_hdr("defs");
}


yskipped= NO;
}
}

switch(next_control)
{
case WEB_definition:/* ``\.{@m}'' */
APP_STR(upper_case_code?"\\WMD":"\\WMd");break;

case undefinition:/* ``\.{@u}'' */
APP_LANG("Ud");break;

case definition:/* ``\.{@d}'' */
APP_LANG(upper_case_code?"D":"d");break;

case formatt:/* ``\.{@f}'' */
APP_LANG(upper_case_code?"F":"f");break;

case limbo_text:/* ``\.{@l}'' */
APP_LANG("l");break;

case op_def:/* ``\.{@v}'' */
APP_LANG("v");break;

case macro_def:/* `\.{@w}'. */
APP_LANG(upper_case_code?"WW":"w");break;

case m_ifdef:
APP_TEMP("E","ifdef");break;

case m_ifndef:
APP_TEMP("E","ifndef");break;

case m_line:
APP_TEMP("E","line");break;

case m_undef:
APP_TEMP("E","undef");break;

case m_if:
APP_TEMP("E","if");break;

case m_elif:
APP_TEMP("E","elif");break;

case m_else:
APP_TEMP("E","else");
app_scrap(ignore_scrap,no_math);
break;

case m_for:
APP_TEMP("E","for");break;

case m_endfor:
APP_TEMP("E","endfor");
app_scrap(ignore_scrap,no_math);
break;

case m_endif:
APP_TEMP("E","endif");
app_scrap(ignore_scrap,no_math);
break;
}



}



SRTN app_lang FCN((suffix))
CONST outer_char*suffix C1("")
{
APP_TEMP(suffix,(CONST outer_char*)(language_symbol(language)));
}



SRTN trns_code(VOID)
{
the_part= CODE;
this_module= name_dir;
parsing_mode= OUTER;

if(next_control<=module_name)
{
OUT_STR("\\WY");
ini_stack;

{
if(output_on)app(Turn_output_on);
else
{
app(force);/* If we don't do this, output is turned off before the \
contents of the last line are printed. */
app(turn_output_off);
}

app_scrap(ignore_scrap,no_math);
}



{
APP_STR("\\WP");

}



if(next_control==begin_code)
{/* We've hit an \.{@a}. */
boolean nuweb_mode0= nuweb_mode;

unnamed_section= YES;
params= global_params;/* Unnamed module is in global language. */
nuweb_mode= nuweb_mode0;
frz_params();
the_module= NULL;

{
if(!nuweb_mode&&((FORTRAN_LIKE(language)&&!free_form_input)
||(language==TEX)))
{

{
loc= limit+1;/* Skip rest of line. */
chk_end= NO;
column_mode= YES;
}


next_control= ignore;
}
else
{


if(Fortran88&&auto_semi)
{
loc= limit+1;
chk_end= NO;
}



next_control= (nuweb_mode?begin_meta:get_next());/* !!!!! */
}
}




{
app_hdr("code");
}

/* !!!!! */
}
else
{/* Named module. */
unnamed_section= NO;

if(cur_module!=NULL)
{
params= cur_module->mod_info->params;
/* Restore state for this module. */
frz_params();
this_module= cur_module;
}
the_module= cur_module;

{
LANGUAGE saved_language= language;

if(language==TEX)
language= C;

/* Allow optional `\.{+=}'. */
do
next_control= get_next();
while(next_control==053);

language= saved_language;

switch(next_control)
{
case compound_assignment:
if(assignment_token!=plus_eq)
{

err0_print(ERR_W,OC("Invalid compound assignment after section \
name; please use one of `=', `==', or `+='"),0);

break;
}

/* The |plus_eq| falls through to the next case. */

case 075:
case eq_eq:

{
if(!nuweb_mode&&((FORTRAN_LIKE(language)&&!free_form_input)
||(language==TEX)))
{

{
loc= limit+1;/* Skip rest of line. */
chk_end= NO;
column_mode= YES;
}


next_control= ignore;
}
else
{


if(Fortran88&&auto_semi)
{
loc= limit+1;
chk_end= NO;
}



next_control= (nuweb_mode?begin_meta:get_next());/* !!!!! */
}
}

/* Positioned after `\.{@<\dots@>=}'. */
break;

default:

err0_print(ERR_W,OC("You need an = sign after the section name"),0);

break;
}

#if(0)
if(out_ptr>out_buf+2&&STRNCMP(out_ptr-2,"\\WY",3)==0)
#endif
{
app(backup);/* The module name will be flush left */
app(backup);
}


app(mod_flag+PTR_DIFF(sixteen_bits,this_module,name_dir));
cur_xref= (xref_pointer)this_module->xref;
APP_STR("${}");

if(cur_xref->num!=module_count+def_flag)
{
APP_STR("\\PQ");/* Module name is multiply defined, */

this_module= name_dir;/* so we won't give cross-reference info here. */
}
else
APP_STR("\\WSQ");/* Output the equivalence sign~`$\equiv$'. */


APP_STR("{}$");
app_misc(w_style.misc.named_preamble);/* Optional stuff from style file. */
app(force);/* This forces a line break unless `\.{@~}' follows. */
app_scrap(ignore_scrap,no_math);
}

;
}

/* Now scan the whole module. */
while(next_control<=module_name)
{
outr_parse();


if(next_control<module_name)
{
switch(next_control)
{
case m_if:case m_ifdef:case m_ifndef:
case m_undef:case m_else:
case m_elif:case m_endif:
case m_for:case m_endfor:
case m_line:
case WEB_definition:
pre_scrap(next_control);
break;

default:

err0_print(ERR_W,OC("You can't do that in code text"),0);

break;
}
next_control= get_next();
}
else if(next_control==module_name)
{

{
if(cur_module)
app(mod_flag+PTR_DIFF(sixteen_bits,cur_module,name_dir));
app_scrap(cur_module!=NULL?cur_module->mod_ilk:expr,maybe_math);
}


next_control= (nuweb_mode?begin_meta:get_next());/* !!!!! */
}

;
}


{
boolean nuweb_mode0= nuweb_mode;

params= (the_module==NULL?global_params:the_module->mod_info->params);
nuweb_mode= nuweb_mode0;
frz_params();
}


fin_C();
unnamed_section= NO;
}
}



SRTN app_hdr FCN((section_part))
CONST char*section_part C1("Either \"code\" or \"defs\"")
{
outer_char temp[1000],*temp_end= temp+1000,*t_first,*t_loc;

t_first= temp;
STRCPY(t_first,params.OUT_FILE_NAME);
to_ASCII(t_first);
t_first= esc_buf((ASCII HUGE*)t_first+STRLEN(t_first)+1,
(ASCII HUGE*)temp_end,(CONST ASCII HUGE*)t_first,YES);
to_outer((ASCII HUGE*)t_first);
t_loc= t_first+STRLEN(t_first)+1;
sprintf((char*)t_loc," \\Wunnamed{%s}{%s}%%\n",
section_part,(char*)t_first);
APP_STR(t_loc);
app_scrap(ignore_scrap,no_math);
}



SRTN app_misc FCN((s))
outer_char*s C1("")
{
outer_char*s0;

for(s0= s;*s;)
if(*s++=='\\')
{
if(isdigit(*s)&&*s!='0'&&*s!='8'&&*s!='9')
{
*(s-1)= '\0';/* Terminate for |app_str|. */
APP_STR(s0);

switch(*s)
{
case '1':app(indent);break;
case '2':app(outdent);break;
case '3':app(opt);break;
case '4':app(backup);break;
case '5':app(break_space);break;
case '6':app(force);break;
case '7':app(big_force);break;
}
*(s-1)= '\\';/* Put it back for the next time. */
s0= ++s;/* Skip the digit. */
}
}

APP_STR(s0);
}



SRTN pre_scrap FCN((last_control))
eight_bits last_control C1("")
{
scrap_pointer save_base;
text_pointer p,q;
LANGUAGE saved_language= language;

app(force);
app_proc(last_control);

switch(last_control)
{
case WEB_definition:

{
if((next_control= get_next())!=identifier)

err0_print(ERR_M,OC("Improper deferred macro definition: \
expected identifier"),0);

else
{
app(044);APP_ID;

if(*loc==050)
{
reswitch:switch(next_control= get_next())
{
case 050:case 054:
app(next_control);goto reswitch;
case identifier:
APP_ID;
goto reswitch;
case ellipsis:
APP_STR("\\dots");
if((next_control= get_next())!=051)
{

err0_print(ERR_M,OC("Improper deferred macro \
definition: expected ')' after ellipsis"),0);
break;
}
case 051:app(next_control);app(040);
break;
default:
err0_print(ERR_M,OC("Improper deferred macro definition: \
unrecognized token within argument list"),0);break;
}
}

app(044);app(break_space);
app_scrap(ignore_scrap,no_math);/* scrap won't take part \
					in the parsing */
}
}

;
break;
}

p= text_ptr;freeze_text;

save_base= scrp_base;
scrp_base= scrp_ptr+1;

*limit= 0100;*(limit+1)= 0155;/* Stop the |outr_parse|. */
next_control= ignore;

if(language==TEX)language= C;
outr_parse();
language= saved_language;

if(last_control==WEB_definition){app_scrap(semi,maybe_math);}

q= translate(OUTER);
scrp_ptr= scrp_base-1;
scrp_base= save_base;

app(tok_flag+PTR_DIFF(sixteen_bits,p,tok_start));
app(tok_flag+PTR_DIFF(sixteen_bits,q,tok_start));
APP_STR("\\WPs");app(force);/* Terminate preprocessor command. */
app_scrap(ignore_scrap,no_math);
}


#endif /* |part == 2| */

#if(part == 0 || part == 3)


SRTN init_op FCN((op_code,op_name,lang,op_macro,overload,cat,defn))
eight_bits op_code C0("The operator")
CONST outer_char op_name[]C0("Fortran-like name of the operator")
int lang C0("Union of all allowable languages for this def")
CONST outer_char op_macro[]C0("Default macro expansion")
boolean overload C0("Do we overload?")
eight_bits cat C0("Category code")
CONST outer_char defn[]C1("Replacement text for overloaded macro")
{
OPERATOR HUGE*p;
int k,l;

/* The dot constants won't be in the table yet. Just put them there. */
if(op_code==identifier)p= op_ptr++;/* Next free position for a dot op. */
else if(!(p= valid_op(op_code)))
{

err0_print(ERR_W,OC("Invalid op code %d"),1,op_code);
return;
}

p->op_name= GET_MEM("op name",STRLEN(op_name)+1,ASCII);
STRCPY(p->op_name,op_name);
to_ASCII((outer_char*)p->op_name);

/* Access the languages by bit-shifting with~|l|. */
for(k= 0,l= 1;k<NUM_LANGUAGES;k++,l<<= 1)
if(lang&l)
{
OP_INFO HUGE*q= p->info+k;

q->op_macro= op_macro;
overloaded[k]|= (q->overloaded= overload);
q->cat= cat;
if(defn)q->defn= (outer_char HUGE*)defn;
}
}



SRTN room_for FCN((ntokens,ntexts,nscraps))
int ntokens C0("")
int ntexts C0("")
int nscraps C1("")
{
if(tok_ptr+ntokens>tok_m_end)
{
if(tok_ptr>mx_tok_ptr)mx_tok_ptr= tok_ptr;
OVERFLW("tokens","tw");
}

if(text_ptr+ntexts>tok_end)
{
if(text_ptr>mx_text_ptr)mx_text_ptr= text_ptr;
OVERFLW("texts","x");
}

if(scrp_ptr+nscraps>scrp_end)
{
if(scrp_ptr>mx_scr_ptr)mx_scr_ptr= scrp_ptr;
OVERFLW("scraps","s");
}
}



OPERATOR HUGE*valid_op FCN((op_code))
eight_bits op_code C1("")
{
int n= 0;
OPERATOR HUGE*p;

switch(op_code)
{
case 057:
case 053:
case 074:
case 076:
case 075:
case 045:
case 041:
case 0176:
case 055:
case 052:
case 046:
case 0174:
case 077:
case 0136:
case ellipsis:
case not_eq:
case lt_eq:
case gt_eq:
case eq_eq:
case and_and:
case or_or:
case plus_plus:
case minus_minus:
case minus_gt:
case gt_gt:
case lt_lt:
case star_star:
case slash_slash:
p= op+op_code;
if(p>=op+128)CONFUSION("valid_op",
"Operator out of range");
return p;

case compound_assignment:
if(assignment_token==or_or_or)
return op+0174;

p= op+CA_START+assignment_token;
if(p>=op+128)CONFUSION("valid_op",
"Compound assignment operator out of range");
return p;

case dot_const:
if(!FORTRAN_LIKE(language))return NULL;
id_first= dot_op.name+1;
id_loc= id_first+STRLEN(id_first);

case identifier:
if(!FORTRAN_LIKE(language))return NULL;/* Can do names only in \
\Fortran. */

{
ASCII id[255];

STRNCPY(id,id_first,n= PTR_DIFF(int,id_loc,id_first));
id[n]= '\0';/* Make into proper string. */

for(p= op+128;p<op_ptr;p++)
if(STRCMP(p->op_name,id)==0)return p;

if(op_ptr>=op_end)OVERFLW("op table","op");

p->op_name= GET_MEM("op name",n+1,ASCII);
STRCPY(p->op_name,id);
op_ptr++;
return p;
}


}

return NULL;
}



SRTN app_overload(VOID)
{
int ln= language_num;
OPERATOR HUGE*p= valid_op(next_control);
OP_INFO HUGE*q= p->info+ln;
char temp[10];

if(overload_ops&&q->overloaded)
{
switch(q->cat)
{
case unorbinop:
case binop:
APP_STR("\\Wb{");break;

case unop:
APP_STR("\\Wu{");break;

default:
APP_STR(" \\Wop{");break;
}

app_ASCII_str(p->op_name);
sprintf(temp,"}{%s}",lang_codes[ln]);
APP_STR(temp);
}
else if(q->op_macro)
APP_STR(q->op_macro);
else
{

err0_print(ERR_W,OC("Unidentifiable dot constant in language %s.  Missing @v?"),1,languages[ln]);
APP_STR("\\Wunknown{");
app(wt_style.dot_delimiter.begin);
app_ASCII_str(p->op_name);
app(wt_style.dot_delimiter.end);
app(0175);
app_scrap(binop,yes_math);
return;
}

app_scrap(q->cat,yes_math);
}



SRTN make_output(VOID)/* outputs the equivalents of tokens */
{
eight_bits a;/* Current output byte. */
eight_bits b;/* Next output byte. */
int c;/* Count of |indent| and |outdent| tokens. */
boolean copying= NO;/* Are we copying the \TeX\ part of a comment? */

app(end_translation);/* Append a sentinel. */
freeze_text;push_level(text_ptr-1);

WHILE()
{
a= get_output();

reswitch:switch(a)
{
case ignore:continue;/* In case a null sneaks in. */

case begin_language:
language= lan_enum(get_output());/* The byte after \
|begin_language| contains the language number. */
continue;



case protect_code:
output_protect= BOOLEAN(!output_protect);break;

case copy_mode:
copying= BOOLEAN(!copying);break;

case turn_output_off:
output_on= NO;
break;

case turn_output_on:
output_on= YES;
break;

case Turn_output_off:
skip_file();
strt_off= YES;
output_on= NO;
break;

case Turn_output_on:
strt_off= NO;
output_on= YES;
break;



case end_translation:
return;

case identifier:case res_word:
if(output_on)

{
if(nuweb_mode)
{
ASCII HUGE*k;

for(k= cur_name->byte_start;k<(cur_name+1)->byte_start;k++)
{
out(*k);
}
}
else

{
boolean all_uc= cur_name->info.upper_case;

if(output_protect)
OUT_STR("\\protect");

if(a==identifier)
{
if(is_intrinsic(cur_name))
OUT_STR(pfmt->intrinsic);
/* Intrinsic function---e.g., |fopen|.  */

else if(is_keyword(cur_name))
OUT_STR(ALL_UC?pfmt->KEYWORD:pfmt->keyword);
/* Fortran keyword---e.g., |@r BLOCKSIZE|.  */

else if(length(cur_name)==1)
OUT_STR(pfmt->short_id);
/* One-character identifier---e.g., |a|. */

else

switch(DEFINED_TYPE(cur_name))
{
case D_MACRO:
OUT_STR(ALL_UC?pfmt->ID_OUTER:pfmt->id_outer);
/* E.g., |NON_TEX_MACRO|. */
break;

case M_MACRO:
OUT_STR(ALL_UC?pfmt->ID_INNER:pfmt->id_inner);/* E.g., |_FWEAVE_|. */
break;

default:
OUT_STR(ALL_UC?pfmt->ID:pfmt->id);
/* Longer ordinary identifier---e.g., |out|. */
break;

}


}
else
OUT_STR(ALL_UC?pfmt->RESERVED:pfmt->reserved);
/* Reserved word---e.g., |float|. */


out_name(IDENTIFIER,cur_name);
}


}



break;

case mod_name:
if(output_on)

#if FCN_CALLS
out_md_name();
#else

{
name_pointer cur_mod_name;/* name of module being output */

OUT_STR("\\WX");

cur_xref= (xref_pointer)cur_name->xref;

/* Output the module number, or zero if it was undefined */
if(cur_xref->num>=def_flag)
{
out_mod(cur_xref->num-def_flag,ENCAP);

if(phase==3)
{
cur_xref= cur_xref->xlink;

while(cur_xref->num>=def_flag)
{
OUT_STR(", ");
out_mod(cur_xref->num-def_flag,ENCAP);
cur_xref= cur_xref->xlink;
}
}
}
else out(060);

out(072);/* End the module number. */

{
ASCII HUGE*k,HUGE*k_limit;/* indices into |byte_mem| */
ASCII HUGE*j;/* index into |cur_buffer| */
ASCII HUGE*save_loc,HUGE*save_limit;/* |loc| and |limit| to be restored. */
eight_bits b;

k= cur_name->byte_start;k_limit= (cur_name+1)->byte_start;
cur_mod_name= cur_name;

while(k<k_limit)
{
b= *(k++);

if(b==0100)

if(*k++!=0100)
{
SET_COLOR(error);
printf("\n! Illegal control code in section name: <");

prn_id(cur_mod_name);printf("> ");mark_error;
}

;

if(b!=0174)out(b)
else
{

{
ASCII delim;/* first and last character of string being copied */

j= limit+1;*j= 0174;delim= 0;

WHILE()
{
if(k>=k_limit)
{
SET_COLOR(error);
printf("\n! C text in section name didn't end: <");

prn_id(cur_mod_name);printf("> ");mark_error;break;
}

b= *(k++);

if(b==0100)
{
if(j>cur_buffer+buf_size-3)OVERFLW("buffer","");

*(++j)= 0100;*(++j)= *(k++);
}


else
{
if(b==047||b==042)
if(delim==0)delim= b;
else if((eight_bits)delim==b)delim= 0;

if(b!=0174||delim!=0)
{
if(j>cur_buffer+buf_size-2)OVERFLW("buffer","");

*(++j)= b;
}
else break;
}
}
}

;
save_loc= loc;save_limit= limit;loc= limit+2;limit= j+1;
*limit= 0174;output_C();
loc= save_loc;limit= save_limit;
}
}
}

;
OUT_STR("\\X ");/* End the text. (Can't use a colon here, because \
there may be colons in the text.) */
OUT_STR(cur_xref->num>=def_flag?
language_symbol((LANGUAGE)cur_mod_name->mod_info->language):
(CONST outer_char*)"");
OUT_STR("\\X");/* End the language marker. */
}


#endif

break;

case math_bin:case math_rel:


OUT_STR(a==math_bin?"\\mathbin{":"\\mathrel{");



;break;

case toggle_meta:
scanning_meta= BOOLEAN(!scanning_meta);
break;

case cancel:
c= 0;while((a= get_output())>=indent&&a<=big_force)
{
if(a==indent)c++;if(a==outdent)c--;
}


for(;c>0;c--)OUT_STR("\\1");

for(;c<0;c++)OUT_STR("\\2");

;
goto reswitch;

case big_cancel:
c= 0;
while(((a= get_output())>=indent||a==040)&&a<=big_force)
{
if(a==indent)c++;if(a==outdent)c--;
}


for(;c>0;c--)OUT_STR("\\1");

for(;c<0;c++)OUT_STR("\\2");

;
goto reswitch;

case indent:case outdent:case opt:case backup:case break_space:
case force:case big_force:


if(a<break_space)
{
if(cur_mode==outer)
{
if(output_on)
{
out(0134);out(a-cancel+060);/* As an example, \
$|backup| = |0345| - |0341| + \.{'0'} = \.{'4'} \to \.{\\4}$. */
}
if(a==opt)
if(output_on){out(get_output());}/* |opt| is followed by a \
digit. */
else get_output();
}
else if(a==opt)b= get_output();/* Ignore digit following |opt|. */
}
else
{
boolean save_mode;/* value of |cur_mode| before a sequence of breaks */

b= a;save_mode= cur_mode;c= 0;

WHILE()
{
a= get_output();

if(a==cancel||a==big_cancel)
{


for(;c>0;c--)OUT_STR("\\1");

for(;c<0;c++)OUT_STR("\\2");

;
goto reswitch;/* |cancel| overrides everything. */
}

if((a!=040&&a<indent)||a==backup||a>big_force)
{/* Time to output something. */
if(save_mode==outer)
{
if(out_ptr>out_buf+5&&
STRNCMP(out_ptr-5,"\\WY\\WP",6)==0)
goto reswitch;


for(;c>0;c--)OUT_STR("\\1");

for(;c<0;c++)OUT_STR("\\2");

;
if(output_on)
if(strt_off)
{
if(STRNCMP(out_ptr-2,"\\WP",3)==0)
{
out_ptr= out_buf;
goto reswitch;
}
}
else
{
out(0134);out(b-cancel+060);
}
if(a!=end_translation)fin_line();
}
else if(a!=end_translation&&cur_mode==inner)
if(output_on)out(040);

goto reswitch;
}

if(a==indent)c++;
else if(a==outdent)c--;
else
/* Use only the largest. */
if(a>b)b= a;/* if |a==' '| we have |a<b| */
else if(a==opt)get_output();/* Throw away digit after \
							|opt|. */
}
}

;/* Here $a \
	\in \{|break_space|,|force|,|big_force|\}$. */

;break;

case interior_semi:
if(output_on)out(';');
break;

case 052:
if(!(copying||nuweb_mode))
{
OUT_STR("\\ast ");/* Special macro for asterisks in code mode. */

break;
}
/* If |copying|, the asterisk case falls through to the default. */

default:
if(output_on)
{
out(a);/* Otherwise |a| is an |ASCII| character. */

if(scanning_meta&&a=='\n')
flush_buffer(out_ptr,NO);
}
}
}
}


SRTN skip_file(VOID)
{
#define TEMP_LEN (MAX_FILE_NAME_LENGTH + 11)

outer_char temp[TEMP_LEN],temp1[TEMP_LEN];

esc_file_name(temp1,TEMP_LEN,prms[1].web.File_name);

if(
nsprintf(temp,OC("\\Wskipped{%s}"),1,temp1)>=(int)(TEMP_LEN))OVERFLW("temp","");
OUT_STR(temp);
fin_line();

#undef TEMP_LEN
}


SRTN out_skip(VOID)
{

{
static int outer_include_depth;

if(output_on)
{
if(phase==2)
{
flush_buffer(out_ptr,NO);
}
outer_include_depth= incl_depth;
output_on= NO;
}
else if(incl_depth<=outer_include_depth)
{
output_on= YES;
}
}

;
if(!output_on)
{
output_on= YES;
OUT_STR("\\WY\\WP");
skip_file();
output_on= NO;
}
}



#if FCN_CALLS
SRTN out_md_name(VOID)
{

{
name_pointer cur_mod_name;/* name of module being output */

OUT_STR("\\WX");

cur_xref= (xref_pointer)cur_name->xref;

/* Output the module number, or zero if it was undefined */
if(cur_xref->num>=def_flag)
{
out_mod(cur_xref->num-def_flag,ENCAP);

if(phase==3)
{
cur_xref= cur_xref->xlink;

while(cur_xref->num>=def_flag)
{
OUT_STR(", ");
out_mod(cur_xref->num-def_flag,ENCAP);
cur_xref= cur_xref->xlink;
}
}
}
else out(060);

out(072);/* End the module number. */

{
ASCII HUGE*k,HUGE*k_limit;/* indices into |byte_mem| */
ASCII HUGE*j;/* index into |cur_buffer| */
ASCII HUGE*save_loc,HUGE*save_limit;/* |loc| and |limit| to be restored. */
eight_bits b;

k= cur_name->byte_start;k_limit= (cur_name+1)->byte_start;
cur_mod_name= cur_name;

while(k<k_limit)
{
b= *(k++);

if(b==0100)

if(*k++!=0100)
{
SET_COLOR(error);
printf("\n! Illegal control code in section name: <");

prn_id(cur_mod_name);printf("> ");mark_error;
}

;

if(b!=0174)out(b)
else
{

{
ASCII delim;/* first and last character of string being copied */

j= limit+1;*j= 0174;delim= 0;

WHILE()
{
if(k>=k_limit)
{
SET_COLOR(error);
printf("\n! C text in section name didn't end: <");

prn_id(cur_mod_name);printf("> ");mark_error;break;
}

b= *(k++);

if(b==0100)
{
if(j>cur_buffer+buf_size-3)OVERFLW("buffer","");

*(++j)= 0100;*(++j)= *(k++);
}


else
{
if(b==047||b==042)
if(delim==0)delim= b;
else if((eight_bits)delim==b)delim= 0;

if(b!=0174||delim!=0)
{
if(j>cur_buffer+buf_size-2)OVERFLW("buffer","");

*(++j)= b;
}
else break;
}
}
}

;
save_loc= loc;save_limit= limit;loc= limit+2;limit= j+1;
*limit= 0174;output_C();
loc= save_loc;limit= save_limit;
}
}
}

;
OUT_STR("\\X ");/* End the text. (Can't use a colon here, because \
there may be colons in the text.) */
OUT_STR(cur_xref->num>=def_flag?
language_symbol((LANGUAGE)cur_mod_name->mod_info->language):
(CONST outer_char*)"");
OUT_STR("\\X");/* End the language marker. */
}


}
#endif



SRTN footnote FCN((flag))/* Outputs module cross-references */
sixteen_bits flag C1("")
{
xref_pointer q;/* Cross-reference pointer variable */

if(cur_xref->num<=flag)return;

fin_line();OUT_STR("\\W");



out(flag==0?0125:0101);

OUT_STR(" section");


q= cur_xref;if(q->xlink->num>flag)out(0163);/* Pluralize. */
out(0176);

WHILE()
{
out_mod(cur_xref->num-flag,ENCAP);
cur_xref= cur_xref->xlink;/* Point to the next cross-reference to output */

if(cur_xref->num<=flag)break;

if(cur_xref->xlink->num>flag||cur_xref!=q->xlink)out(054);
/* Not the last of two */

out(040);

if(cur_xref->xlink->num<=flag)OUT_STR("and~");/* the last */
}

;
out(056);
fin_line();
}



SRTN phase3(VOID)
{
language= global_language;

if(no_xref&&!prn_contents)
{
fin_line();

{
OUT_STR("\\vfill\\FWEBend");fin_line();
}


}
else
{/* Print cross-reference information. */
outer_char HUGE*temp_ndx,HUGE*temp_mds;
IN_COMMON outer_char wbflnm0[];

temp_ndx= GET_MEM("temp_ndx",MAX_FILE_NAME_LENGTH,outer_char);
temp_mds= GET_MEM("temp_mds",MAX_FILE_NAME_LENGTH,outer_char);

phase= 3;
nuweb_mode= NO;/* Force full output of identifiers. */

if(prn_index)
{
OUT_STR("\\input ");
OUT_STR(xpn_name(&temp_ndx,MAX_FILE_NAME_LENGTH,
w_style.indx.tex,wbflnm0));
fin_line();
}

if(prn_modules)
{
OUT_STR("\\input ");
OUT_STR(xpn_name(&temp_mds,MAX_FILE_NAME_LENGTH,
w_style.modules.tex,wbflnm0));
fin_line();

fin_line();


{
outer_char HUGE*temp;


temp= GET_MEM("temp",N_CMD,outer_char);

OUT_STR(w_style.modules.info);
OUT_STR(cmd_ln_buf);fin_line();

/* Print a message identifying the global language. */

if(
nsprintf(temp,OC(" {%s}"),1,language_name_ptr(global_language))>=(int)(N_CMD))OVERFLW("temp","");
OUT_STR(temp);fin_line();

FREE_MEM(temp,"temp",N_CMD,outer_char);
}


;

}

if(prn_contents)
{
outer_char temp[20];

OUT_STR(w_style.contents.preamble);


if(
nsprintf(temp,OC("{%i}"),1,module_count)>=(int)(20))OVERFLW("temp","");
OUT_STR(temp);

OUT_STR(w_style.contents.postamble);
fin_line();

}
else
{
OUT_STR("\\vfill\\FWEBend");fin_line();
}



if(prn_index)
{
writing(YES,temp_ndx);
if(tex_file==stdout)puts("");
NEW_TeX(temp_ndx);

if(change_exists)
{

{
/* Remember that the index is already marked as changed */
k_module= 0;

while(!chngd_module[++k_module]);

OUT_STR("\\Wch ");

out_mod(k_module,ENCAP);

while(k_module<module_count)
{
while(!chngd_module[++k_module]);/* Skip over \
unchanged modules. */

OUT_STR(", ");out_mod(k_module,ENCAP);
}

out(056);
}

;
fin_line();
fin_line();
}

OUT_STR(w_style.indx.preamble);fin_line();



{
int c;


for(c= 0;c<=127;c++)bucket[c]= NULL;

for(h= hash;h<=hash_end;h++)
{
next_name= *h;

while(next_name)
{
cur_name= next_name;next_name= cur_name->link;

if((xref_pointer)cur_name->xref!=xmem)
{
c= (cur_name->byte_start)[0];

c= A_TO_LOWER(c);

blink[cur_name-name_dir]= bucket[c];
bucket[c]= cur_name;
}
}
}
}

;


w_style.indx.collate= x__to_ASCII((outer_char*)w_style.indx.collate);
max_collate= STRLEN(w_style.indx.collate);
STRNCPY(collate+1,w_style.indx.collate,max_collate);

sort_ptr= scrp_info;unbucket(1);

while(sort_ptr>scrp_info)
{
cur_depth= sort_ptr->depth;

if(blink[sort_ptr->head-name_dir]==0||cur_depth==INFTY)

{
cur_name= sort_ptr->head;


{
ASCII letter= *cur_name->byte_start;

/* In some special cases in \Cpp, the identifier may be a \TeX\ macro \
beginning with~'\.\\' at this point. We must then take special precautions. \
In particular, we assign a non-null, non-printable value to |letter|. */
if(letter==0134&&cur_name->ilk==normal&&language!=TEX)
letter= NON_TEX_MACRO;
else letter= A_TO_LOWER(letter);

if(letter!=last_letter)
{
if(last_letter)OUT_STR(w_style.indx.group_skip);/* Separate groups, \
but not for the very first one. */

if(w_style.indx.lethead_flag&&letter!=NON_TEX_MACRO)
{
OUT_STR(w_style.indx.lethead_prefix);

switch(letter)
{




case 0134:case 0173:case 0175

:

case 040:case 043:case 045:case 044:case 0136:case 0140:
case 0176:case 046:case 0137



:out(0134);
}
out((w_style.indx.lethead_flag>0?A_TO_UPPER(letter):
A_TO_LOWER(letter)));

OUT_STR(w_style.indx.lethead_suffix);
}
}

last_letter= letter;
}



do
{
if(cur_name->defined_type(language)<0x80)
{/* Write index entry for one identifier. */
OUT_STR(w_style.indx.item_0);


{
boolean output_type;
boolean all_uc= cur_name->info.upper_case;


switch(cur_name->ilk)
{
case normal:
output_type= IDENTIFIER;

if(is_intrinsic(cur_name))
OUT_STR(pfmt->intrinsic);
/* E.g., |sqrt|. */
else if(is_keyword(cur_name))
OUT_STR(ALL_UC?pfmt->KEYWORD:pfmt->keyword);
/* E.g., |@r BLOCKSIZE|. */
else
if(language==TEX)
OUT_STR(pfmt->typewritr);
/* E.g., \.{\\hfill}. */
else if(length(cur_name)==1)
OUT_STR(pfmt->short_id);/* E.g., |a|. */
else

switch(DEFINED_TYPE(cur_name))
{
case D_MACRO:
OUT_STR(ALL_UC?pfmt->ID_OUTER:pfmt->id_outer);
/* E.g., |NON_TEX_MACRO|. */
break;

case M_MACRO:
OUT_STR(ALL_UC?pfmt->ID_INNER:pfmt->id_inner);/* E.g., |_FWEAVE_|. */
break;

default:
OUT_STR(ALL_UC?pfmt->ID:pfmt->id);
/* Longer ordinary identifier---e.g., |out|. */
break;

}


break;



case roman:output_type= INDEX_ENTRY;break;
case wildcard:OUT_STR(pfmt->wildcrd);output_type= INDEX_ENTRY;break;

case typewriter:OUT_STR(pfmt->typewritr);
output_type= INDEX_ENTRY;break;

default:
OUT_STR(ALL_UC?pfmt->RESERVED:pfmt->reserved);
output_type= IDENTIFIER;break;/* E.g., |int|. */

}

out_name(output_type,cur_name);
}

;




this_xref= (xref_pointer)cur_name->xref;cur_xref= xmem;

do
{
next_xref= this_xref->xlink;this_xref->xlink= cur_xref;
cur_xref= this_xref;this_xref= next_xref;
}
while(this_xref!=xmem);

;

OUT_STR(w_style.indx.delim_0);/* Immediately after identifier. */

WHILE()
{
cur_val= cur_xref->num;

if(cur_val<def_flag)out_mod(cur_val,ENCAP);
else
{
OUT_STR(w_style.indx.underline_prefix);
out_mod(cur_val-def_flag,ENCAP);
OUT_STR(w_style.indx.underline_suffix);
}


/* If the language of this module isn't the global language, mark it in the \
|w_style|. */
if((LANGUAGE)cur_xref->Language!=global_language)
{
char temp[50];

sprintf(temp,"%s%s%s",
(char*)w_style.indx.language_prefix,
(char*)language_symbol((LANGUAGE)cur_xref->Language),
(char*)w_style.indx.language_suffix);
OUT_STR(temp);
}

cur_xref= cur_xref->xlink;

if(cur_xref==xmem)break;
OUT_STR(w_style.indx.delim_n);/* Between identifiers. */
}

out(056);fin_line();

;
}

cur_name= blink[cur_name-name_dir];
}
while(cur_name);

--sort_ptr;
}


else
{
ASCII c;


next_name= sort_ptr->head;

do
{
cur_name= next_name;next_name= blink[cur_name-name_dir];
cur_byte= cur_name->byte_start+cur_depth;

if(cur_byte==(cur_name+1)->byte_start)c= 0;/* hit end of the name */
else
{
c= *cur_byte;
c= A_TO_LOWER(c);
}

blink[PTR_DIFF(size_t,cur_name,name_dir)]= bucket[c];
bucket[c]= cur_name;
}
while(next_name);

--sort_ptr;unbucket((eight_bits)(cur_depth+(eight_bits)1));
}

;
}

;

OUT_STR(w_style.indx.postamble);fin_line();

}


if(prn_modules)
{
writing(BOOLEAN(!prn_index),temp_mds);
NEW_TeX(temp_mds);

OUT_STR(w_style.modules.preamble);fin_line();


mod_print(root);

OUT_STR(w_style.modules.postamble);fin_line();
}



if(tex_file!=stdout)fclose(tex_file);
}

CLR_PRINTF(info,("\nDone."));
chk_complete();/* Was all of the change file used? */
}



ASCII HUGE*esc_buf FCN((temp,temp_end,buf,all_cases))
ASCII HUGE*temp C0("Put it into here.")
CONST ASCII HUGE*temp_end C0("End of |temp|.")
CONST ASCII HUGE*buf C0("Translate from here.")
boolean all_cases C1("")
{
ASCII HUGE*temp0= temp;

while(*buf!='\0')
{
switch(*buf)
{


case 0134:case 0173:case 0175

:
if(!all_cases)break;


case 040:case 043:case 045:case 044:case 0136:case 0140:
case 0176:case 046:case 0137

:
TO_TEMP(0134);
break;
}

TO_TEMP(*buf++);
}

TO_TEMP('\0');
return temp0;/* Return the beginning of the output buffer. */
}



SRTN unbucket FCN((d))/* Empties buckets having depth |d| */
eight_bits d C1("")
{
int c;/* Index into |bucket|. {\it Must be |int|.} */

for(c= max_collate;c>=0;c--)if(bucket[collate[c]]){
if(sort_ptr>=scrp_end)OVERFLW("sort levels","s");

sort_ptr++;

if(sort_ptr>mx_sort_ptr)mx_sort_ptr= sort_ptr;

sort_ptr->depth= (eight_bits)(c==0?INFTY:d);
sort_ptr->head= bucket[collate[c]];
bucket[collate[c]]= NULL;
}
}



SRTN mod_print FCN((p))/* Print all module names in subtree |p|. */
name_pointer p C1("")
{
if(p)
{
mod_print(p->llink);OUT_STR("\\:");

tok_ptr= tok_mem+1;text_ptr= tok_start+1;scrp_ptr= scrp_info;ini_stack;
app(mod_flag+PTR_DIFF(sixteen_bits,p,name_dir));
make_output();
footnote(0);/* |cur_xref| was set by |make_output| */
fin_line();

mod_print(p->rlink);
}
}



SRTN see_wstatistics(VOID)
{
CLR_PRINTF(info,("\n\nMEMORY USAGE STATISTICS:\n"));

STAT0("names",sizeof(*name_ptr),
SUB_PTRS(name_ptr,name_dir),max_names,smin0(MAX_VAL("n")),"n",",");

STAT0("cross-references",sizeof(*xref_ptr),
SUB_PTRS(xref_ptr,xmem),max_refs,smin0(MAX_VAL("r")),"r",",");

STAT0("bytes",sizeof(*byte_ptr),
SUB_PTRS(byte_ptr,byte_mem),max_bytes,smin0(MAX_VAL("b")),"b",";");

CLR_PRINTF(info,(" parsing required\n"));

STAT0("scraps",sizeof(*mx_scr_ptr),
SUB_PTRS(mx_scr_ptr,scrp_base),max_scraps,smin0(MAX_VAL("s")),"s",",");

STAT0("texts",sizeof(*mx_text_ptr),
SUB_PTRS(mx_text_ptr,tok_start),max_texts,smin0(MAX_VAL("x")),"x",",");

STAT0("tokens",sizeof(*mx_tok_ptr),
SUB_PTRS(mx_tok_ptr,tok_mem),max_toks,smin0(MAX_VAL("tw")),"tw",",");

STAT0("stack levels",sizeof(*mx_stck_ptr),
SUB_PTRS(mx_stck_ptr,stack),stck_size,smin0(MAX_VAL("kw")),"kw",";");

CLR_PRINTF(info,(" sorting required"));

printf(" %lu level(s).\n",SUB_PTRS(mx_sort_ptr,scrp_info));

mem_avail(1);/* How much memory left at end of run? */
}



SRTN predefine_macros(VOID)
{}

SRTN open_out(VOID)
{}

boolean was_opened FCN((name,global_scope,pname,pptr))
CONST outer_char HUGE*name C0("")
boolean global_scope C0("")
outer_char HUGE*HUGE*pname C0("")
FILE**pptr C1("")
{
*pname= GET_MEM("*pname",STRLEN(name)+1,outer_char);
STRCPY(*pname,name);

return NO;
}

SRTN ini_tokens FCN((language0))
LANGUAGE language0 C1("")
{}


#endif /* |part == 3| */





