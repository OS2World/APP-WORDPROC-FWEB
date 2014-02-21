#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06."  \
  COMMAND LINE: "web/ftangle web/map -A -# --F -= 1.53/web/map.h" \
  RUN TIME: "Saturday, September 23, 1995 at 16:17." \
  WEB FILE:    "web/map.web" \
  CHANGE FILE: (none)
#endif
#define MAX_OUTPUT_LINE_LENGTH  100
#define LONG_OUTPUT_LINE_LENGTH  80
#define STANDARD_OUTPUT_LINE_LENGTH  72
#define MIN_OUTPUT_LINE_LENGTH  60 \

#define DEFAULT_PAREN_NEST  10
#define DEFAULT_PAREN_NUM  10
#define DEFAULT_PAREN_LEN  100 \


#ifdef _STYLE_h
#define YSET(stuff) =  stuff
#else
#define YSET(stuff)
#endif



typedef enum{S_DONE,S_CMNT,S_KEYWORD,S_STRING,S_CHAR,S_INT,S_LONG,
S_MODIFIED= 128,
S_CMNT_MOD,S_KEYWORD_MOD,S_STRING_MOD,
S_CHAR_MOD,S_INT_MOD,S_LONG_MOD}STY_TYPE;

typedef struct s_map
{
outer_char*keyword;/* Style keyword. */
STY_TYPE type;/* Type of argument. */
void*ptr;/* Where to put the argument. This is a generic pointer, \
so it can be explicitly cast depending on the argument type. */
SRTN(*init)PROTO((struct s_map HUGE*));/* Initialization \
routine. */
}S_MAP;



typedef char*CODES;

typedef struct
{
CODES Ascii_constant,
Begin_bp,
Begin_C,
Begin_FORTRAN,
Begin_meta,
Begin_RATFOR,
Begin_code,
Begin_nuweb,
Big_line_break,
Compiler_directive,
Defd_at,
Definition,
End_meta,
Force_line,
Formatt,
Implicit_reserved,
Insert_bp,
Invisible_cmnt,
Join,
Limbo_text,
Macro_def,
Math_break,
Module_name,
New_module,
New_output_file,
No_index,
No_line_break,
No_mac_expand,
Op_def,
Pseudo_colon,
Pseudo_expr,
Pseudo_semi,
Set_line_info,
Switch_math_flag,
TeX_String,
Thin_space,
Trace,
Undefinition,
Underline,
Verbatim,
WEB_Definition,
Xref_roman,
Xref_typewriter,
Xref_wildcard,
Yes_index;
}C_STYLE;

IN_STYLE C_STYLE c_style;



typedef struct
{
outer_char*name;/* Title for index. */
outer_char*preamble;/* \TeX\ string to start the index. \
(``\.{\\Winx}'') */
outer_char*postamble;/* \TeX\ string to end the index. \
(``\.{\\Wfin}'') */
outer_char*group_skip;/* \TeX\ string to insert between letter groups. */
outer_char*lethead_prefix;/* \TeX\ string to begin identifying letter \
at start of group. */
outer_char*lethead_suffix;/* \TeX\ string to insert after identifying \
letter. */
int lethead_flag;/* If~0, insert no letter. If~$> 0$, insert \
uppercase letter. If~$< 0$, insert lowercase letter. */
outer_char*item_0;/* \TeX\ command to begin an index entry. \
(``\.{\\:}'') */
outer_char*delim_0;/* String to insert after identifier. */
outer_char*delim_n;/* String to insert between two module numbers. */
outer_char*encap_prefix;/* TeX command to begin a page number. */
outer_char*encap_infix;/* Left delimiter for encapsulation. */
outer_char*encap_suffix;/* Right delimiter for encapsulation. */
outer_char*underline_prefix,*underline_suffix;/* Bracket underlined entry \
with these. (``\.{\\[}''), (``\.]'') */
outer_char*language_prefix,*language_suffix;/* Bracket language entry \
with these. (``\.{\\(}''), (``\.)'') */
outer_char*tex;/* Name of \TeX\ output file for index. \
(``\.{INDEX.tex}'') */
ASCII*collate;/* Collation order. */
}INDEX;

typedef struct
{
outer_char*preamble;/* \TeX\ string to start the module list. \
(``\.{\\Wmods}'') */
outer_char*postamble;/* \TeX\ string to end the module list. (empty) */
outer_char*tex;/* Name of \TeX\ output file for module names. \
(``\.{MODULES.tex}'') */
outer_char*info;/* The \.{\\Winfo} macro. */
}MODULES;

typedef struct
{
outer_char*tex;/* Name of \TeX\ output file for table of contents. \
(``\.{CONTENTS.tex}'') */
outer_char*preamble;/* Start the table of contents. \
(``\.{\\n\\Wcon}''). */
outer_char*postamble;/* Optional string after above. (\It{Empty}). */
}CONTENTS;

typedef struct
{
outer_char*begin,*end;
}STR_INSERT;

typedef struct
{
STR_INSERT TeX,code;
}W_META;/* For \FWEAVE. */

typedef struct
{
outer_char*def;/* Begin an \.{@d}. */
outer_char*undef;/* Begin an \.{@u}. */
}T_OUTER;

typedef struct
{
outer_char*top;/* Start the meta-comment. */
outer_char*prefx;/* Generalization of comment char. */
outer_char*bottom;/* Finish the meta-comment. */
}T_META0;

typedef struct
{
T_META0 hdr;/* For bracketing the header info at top of file. */
T_META0 msg;/* For everything else. */
}T_META;/* For \FTANGLE. */

typedef struct
{
size_t num,nest,len;/* Is the |size_t| approriate? */
}PAREN;

typedef struct
{
outer_char*macros;/* Name of the macro package. (``\.{fwebmac.sty}'') */
FORMAT format;
outer_char*doc_preamble;/* Precedes \.{\\begin\{\\document\}} or limbo \
section. */
outer_char*doc_postamble;/* Precedes \.{\\end\{\\document\}} */
outer_char*limbo_begin,*limbo_end;/* Default limbo material. */
outer_char*unnamed_preamble,*named_preamble;/* Default stuff at mod \
start. */
MARK_DEFINED mark;
outer_char*TeXindent,*codeindent;
W_META meta;
LATEX LaTeX;
outer_char*include_ext;
}W_MISC;

typedef union
{
outer_char*name;
COLOR value;
}ACOLOR;

typedef struct
{
/* The following fields are initially set to a default value like |RED|. \
Later, these are changed into actual escape sequences. */
ACOLOR ordinary;
ACOLOR program_name;
ACOLOR info,warning,error,fatal;
ACOLOR module_num,line_num;
ACOLOR in_file,out_file,include_file;
ACOLOR timing;
/* These are set to abbreviations strings for escape sequences. */
outer_char HUGE*_NORMAL;
outer_char HUGE*_RED,HUGE*_GREEN,HUGE*_BLUE,
HUGE*_YELLOW,HUGE*_ORANGE;
}COLORS;

typedef enum
{
NO_COLOR,BILEVEL,TRUE_COLOR
}COLOR_MODE;

/* Parameters common to both \FTANGLE\ and \FWEAVE. */
typedef struct
{/* Allowable input file extensions. */
outer_char HUGE*web,HUGE*change,HUGE*hweb,HUGE*hchange;
}INPUT_EXT;

typedef struct
{/* Default output file extensions. */
outer_char HUGE*C_,HUGE*Cpp_,HUGE*V_,HUGE*N_,HUGE*N90_,
HUGE*R_,HUGE*R90_,HUGE*X_;
}OUTPUT_EXT;

typedef struct
{/* Delimiters for dot constants. */
ASCII begin,end;
}DOT_DELIMITER;

typedef struct
{
outer_char*xchr;/* Translation table for scrambling |ASCII|. */
outer_char ext_delimiter;/* Delimiter for file extensions. */
INPUT_EXT input_ext;/* Default input file extensions. */
OUTPUT_EXT output_ext;/* Default output file extensions.	 */
outer_char*null_file_name;/* Name of the null file. */
outer_char*Idir;/* Standard directory to search after \.{-I}. */
DOT_DELIMITER dot_delimiter;/* Delimiters for dot constants. */
COLOR_MODE color_mode;/* Do we allow color? */
COLORS color;/* Output colors. */
}COMMON_PRMS;

typedef struct
{
INDEX indx;/* Index-related parameters. */
MODULES modules;/* Stuff for module name printout. */
CONTENTS contents;/* Stuff for table of contents. */
W_MISC misc;/* Miscellaneous parameters. */
}W_STYLE;

typedef struct
{
outer_char cchar;/* Continuation character for \Fortran. */
int output_line_length;/* Length of \Fortran's output line. */
outer_char*cdir_start[NUM_LANGUAGES];/* Insert at the beginning of \
compiler directive. */
ASCII*ASCII_fcn;/* \.{@"\dots"} is replaced by ``|ASCII_fcn|(\dots)''. \
(``\.{ASCIIstr}'') */
T_OUTER outer_start[NUM_LANGUAGES];/* Start an outer definition. */
T_META meta[NUM_LANGUAGES];/* Handle meta-comments. */
outer_char*protect_chars[NUM_LANGUAGES];/* When |protect == YES|. */
outer_char line_char[NUM_LANGUAGES];/* Begin \.{line} command. */
PAREN paren;
}T_STYLE;


#include "c_type.h"
#include "s_type.h"


IN_STYLE W_STYLE w_style
#ifdef _STYLE_h
= {
{OC("INDEX"),OC("\\Winx"),OC("\n\\Wfin"),OC("\n\\Windexspace\n"),
OC(""),OC(""),0,/* Let-heads */
OC("\\:"),/* Begin index entry */
OC(", "),OC(", "),/* Delimiters. */
OC(""),OC(""),OC(""),/* Encapsulation. */
OC("\\["),OC("]"),/* Underlining. */
OC("\\("),OC(")"),/* Language entries. */
OC("INDEX.tex"),/* |INDEX|. */
(ASCII*)" \1\2\3\4\5\6\7\10\11\12\13\14\15\16\17\
\20\21\22\23\24\25\26\27\30\31\32\33\34\35\36\37\
!\42#$%&'()*+,-./:;<=>?@[\\]^`{|}~_\
abcdefghijklmnopqrstuvwxyz0123456789"},/* Collation order. */
{OC("\\Wmods"),OC(""),OC("MODULES.tex"),OC("\\Winfo")},/* \
|MODULES|. */
{OC("CONTENTS.tex"),OC("\n\\Wcon"),OC("")},/* |CONTENTS|. */
{OC("fwebmac.sty"),/* Macro package */
{OC("\\&"),OC("\\&"),/* |reserved| */
OC("\\|"),/* |short_id| */
OC("\\\\"),OC("\\\\"),/* |id| */
OC("\\\\"),OC("\\\\"),/* |id_outer| */
OC("\\\\"),OC("\\\\"),/* |id_inner| */
OC("\\@"),/* |intrinsic| */
OC("\\."),OC("\\."),/* |keyword| */
OC("\\."),/* |typewritr| */
OC("\\9")/* |wildcrd| */
},
OC(""),OC(""),/* |doc_preamble|, |doc_postamble| */
OC(""),OC(""),/* |limbo_begin|, |limbo_end| */
OC(""),OC(""),/* |unnamed_preamble|, |named_preamble| */
{YES,NO,NO,NO,YES,NO},/* |MARK_DEFINED| */
OC("1em"),OC("1em"),/* |TeXindent|, |codeindent| */
{{OC("\\Begintt"),OC("\\Endtt")},
{OC("\\WBM\\Begintt\n"),OC("\\Endtt\\WEM")}},/* |W_META| */
{{OC(""),OC("article")},{OC(""),OC("")}},/* |LaTeX| */
OC("H")/* |include_ext| */
}/* |W_MISC|. */
}
#endif
;

IN_STYLE FORMAT*pfmt YSET(&w_style.misc.format);

/* --- Parameters common to both \FWEAVE\ and \FTANGLE. --- */



IN_STYLE COMMON_PRMS wt_style
#ifdef _STYLE_h
= {
OC("\000\001\003\004\005\006\007\
\010\011\012\013\014\015\016\017\
\020\021\022\023\024\025\026\027\
\030\031\032\033\034\035\036\037\
\040\041\042\043\044\045\046\047\
\050\051\052\053\054\055\056\057\
\060\061\062\063\064\065\066\067\
\070\071\072\073\074\075\076\077\
\100\101\102\103\104\105\106\107\
\110\111\112\113\114\115\116\117\
\120\121\122\123\124\125\126\127\
\130\131\132\133\134\135\136\137\
\140\141\142\143\144\145\146\147\
\150\151\152\153\154\155\156\157\
\160\161\162\163\164\165\166\167\
\170\171\172\173\174\175\176\002\177\
\200\201\202\203\204\205\206\207\
\210\211\212\213\214\215\216\217\
\220\221\222\223\224\225\226\227\
\230\231\232\233\234\235\236\237\
\240\241\242\243\244\245\246\247\
\250\251\252\253\254\255\256\257\
\260\261\262\263\264\265\266\267\
\270\271\272\273\274\275\276\277\
\300\301\302\303\304\305\306\307\
\310\311\312\313\314\315\316\317\
\320\321\322\323\324\325\326\327\
\330\331\332\333\334\335\336\337\
\340\341\342\343\344\345\346\347\
\350\351\352\353\354\355\356\357\
\360\361\362\363\364\365\366\367\
\370\371\372\373\374\375\376\377"
),/* Scrambled |xchr|. */
'.',/* Usual delimiter for file extensions. */
{OC("web"),OC("ch"),OC("hweb"),OC("hch")},/* Input file \
extensions. */
{OC(C_EXT),OC(Cpp_EXT),OC(M_EXT),OC(N_EXT),OC(N90_EXT),OC(R_EXT),
OC(R90_EXT),OC(X_EXT)},/* Output file extensions. */
OC(NULL_FILE_NAME),/* Name of the null file. */
OC(""),/* |Idir|. */
{'.','.'},/* Delimiters for dot constants. */
NO_COLOR /* |color_mode|. */
}
#endif
;

IN_STYLE T_STYLE t_style
#ifdef _STYLE_h
= {
CCHAR,/* Continuation character for \Fortran. */
STANDARD_OUTPUT_LINE_LENGTH,/* Length of \Fortran's output line. */
{OC("#pragma "),OC("C"),OC("C"),OC(""),OC(""),
OC("#pragma "),OC("C"),OC("C")},
/* Compiler directive prefixes.  */
(ASCII*)"ASCIIstr",/* For \.{@"\dots"} in \Fortran\ or \
\Ratfor. */
/* |outer_start| */
{{OC("#define "),OC("#undef ")},/* |C| */
{OC("define"),OC("undef")},/* |RATFOR| */
{OC("define"),OC("undef")},/* |FORTRAN| */
{OC("\\def"),OC("\\undef")},/* |TEX| */
{OC("#define"),OC("#undef")},/* |LITERAL| */
{OC("#define "),OC("#undef ")},/* |C_PLUS_PLUS| */
{OC("define"),OC("undef")},/* |RATFOR_90| */
{OC("define"),OC("undef")}},/* |FORTRAN_90| */
/*  |T_META| */
{{{OC("#if(0)"),OC(""),OC("\n#endif")},
{OC("/*"),OC(""),OC("*/")}},/* |C| */
{{OC(""),OC("C"),OC("\n")},
{OC(""),OC("C"),OC("")}},/* |RATFOR| */
{{OC(""),OC("C"),OC("\n")},
{OC(""),OC("C"),OC("")}},/* |FORTRAN| */
{{OC(""),OC("%"),OC("\n")},
{OC(""),OC("%"),OC("")}},/* |TEX| */
{{OC("#if(0)"),OC(""),OC("\n#endif")},
{OC("/*"),OC("  "),OC("\n*/")}},/* |LITERAL| */
{{OC("#if(0)"),OC(""),OC("\n#endif")},
{OC("/*"),OC(""),OC("*/")}},/* |C_PLUS_PLUS| */
{{OC(""),OC("C"),OC("\n")},
{OC(""),OC("C"),OC("")}},/* |RATFOR_90| */
{{OC(""),OC("C"),OC("\n")},
{OC(""),OC("C"),OC("")}}},/* |FORTRAN_90| */
{OC("\\"),OC(""),OC(""),OC(""),OC("\\"),OC("\\"),OC(""),OC("")},
/* |protect_chars| */
{'#','*','*','%','%','#','*','*'},/* |line_char| */
{DEFAULT_PAREN_NUM,DEFAULT_PAREN_NEST,DEFAULT_PAREN_LEN}
/* |paren| */
}
#endif
;



IN_STYLE S_MAP fweb_map[]
#ifdef _STYLE_h
= {



{OC("index_name"),S_STRING,(void*)&w_style.indx.name,set_str},

{OC("index_preamble"),S_STRING,(void*)&w_style.indx.preamble,set_str},

{OC("index_postamble"),S_STRING,(void*)&w_style.indx.postamble,set_str},

{OC("group_skip"),S_STRING,(void*)&w_style.indx.group_skip,set_str},

{OC("lethead_prefix"),S_STRING,(void*)&w_style.indx.lethead_prefix,set_str},

{OC("lethead_suffix"),S_STRING,(void*)&w_style.indx.lethead_suffix,set_str},

{OC("lethead_flag"),S_INT,(void*)&w_style.indx.lethead_flag,set_int},

{OC("item_0"),S_STRING,(void*)&w_style.indx.item_0,set_str},

{OC("delim_0"),S_STRING,(void*)&w_style.indx.delim_0,set_str},

{OC("delim_n"),S_STRING,(void*)&w_style.indx.delim_n,set_str},

{OC("encap_prefix"),S_STRING,(void*)&w_style.indx.encap_prefix,set_str},

{OC("encap_infix"),S_STRING,(void*)&w_style.indx.encap_infix,set_str},

{OC("encap_suffix"),S_STRING,(void*)&w_style.indx.encap_suffix,set_str},

{OC("underline_prefix"),S_STRING,(void*)&w_style.indx.underline_prefix,set_str},

{OC("underline_suffix"),S_STRING,(void*)&w_style.indx.underline_suffix,set_str},

{OC("language_prefix"),S_STRING,(void*)&w_style.indx.language_prefix,set_str},

{OC("language_suffix"),S_STRING,(void*)&w_style.indx.language_suffix,set_str},

{OC("index_tex"),S_STRING,(void*)&w_style.indx.tex,set_str},

{OC("collate"),S_STRING,(void*)&w_style.indx.collate,set_str}

,



{OC("modules_preamble"),S_STRING,(void*)&w_style.modules.preamble,set_str},

{OC("modules_postamble"),S_STRING,(void*)&w_style.modules.postamble,set_str},

{OC("modules_tex"),S_STRING,(void*)&w_style.modules.tex,set_str},

{OC("info"),S_STRING,(void*)&w_style.modules.info,set_str}

,



{OC("contents_tex"),S_STRING,(void*)&w_style.contents.tex,set_str},

{OC("contents_TeX"),S_STRING,(void*)&w_style.contents.tex,set_str},

{OC("contents_preamble"),S_STRING,(void*)&w_style.contents.preamble,set_str},

{OC("contents_postamble"),S_STRING,(void*)&w_style.contents.postamble,set_str}

,



{OC("macros"),S_STRING,(void*)&w_style.misc.macros,set_str},


{OC("format_reserved"),S_STRING,(void*)&w_style.misc.format.reserved,set_str},

{OC("format_RESERVED"),S_STRING,(void*)&w_style.misc.format.RESERVED,set_str},

{OC("format_identifier"),S_STRING,(void*)&w_style.misc.format.id,set_str},

{OC("format_id"),S_STRING,(void*)&w_style.misc.format.id,set_str},

{OC("format_IDENTIFIER"),S_STRING,(void*)&w_style.misc.format.ID,set_str},

{OC("format_ID"),S_STRING,(void*)&w_style.misc.format.ID,set_str},

{OC("format_short_identifier"),S_STRING,(void*)&w_style.misc.format.short_id,set_str},

{OC("format_short_id"),S_STRING,(void*)&w_style.misc.format.short_id,set_str},

{OC("format_outer_macro"),S_STRING,(void*)&w_style.misc.format.id_outer,set_str},

{OC("format_OUTER_MACRO"),S_STRING,(void*)&w_style.misc.format.ID_OUTER,set_str},

{OC("format_WEB_macro"),S_STRING,(void*)&w_style.misc.format.id_inner,set_str},

{OC("format_WEB_MACRO"),S_STRING,(void*)&w_style.misc.format.ID_INNER,set_str},

{OC("format_intrinsic"),S_STRING,(void*)&w_style.misc.format.intrinsic,set_str},

{OC("format_keyword"),S_STRING,(void*)&w_style.misc.format.keyword,set_str},

{OC("format_KEYWORD"),S_STRING,(void*)&w_style.misc.format.KEYWORD,set_str},

{OC("format_typewriter"),S_STRING,(void*)&w_style.misc.format.typewritr,set_str},

{OC("format_wildcard"),S_STRING,(void*)&w_style.misc.format.wildcrd,set_str},


{OC("doc_preamble"),S_STRING,(void*)&w_style.misc.doc_preamble,set_str},

{OC("doc_postamble"),S_STRING,(void*)&w_style.misc.doc_postamble,set_str},

{OC("preamble_doc"),S_STRING,(void*)&w_style.misc.doc_preamble,set_str},

{OC("postamble_doc"),S_STRING,(void*)&w_style.misc.doc_postamble,set_str},


{OC("unnamed_preamble"),S_STRING,(void*)&w_style.misc.unnamed_preamble,set_str},

{OC("preamble_unnamed"),S_STRING,(void*)&w_style.misc.unnamed_preamble,set_str},

{OC("named_preamble"),S_STRING,(void*)&w_style.misc.named_preamble,set_str},

{OC("preamble_named"),S_STRING,(void*)&w_style.misc.named_preamble,set_str},


{OC("limbo"),S_STRING,(void*)&w_style.misc.limbo_begin,add_str},

{OC("limbo_begin"),S_STRING,(void*)&w_style.misc.limbo_begin,add_str},

{OC("limbo_end"),S_STRING,(void*)&w_style.misc.limbo_end,add_str},


{OC("mark_defined_generic_name"),S_INT,(void*)&w_style.misc.mark.generic_name,set_int},

{OC("mark_defined_fcn_name"),S_INT,(void*)&w_style.misc.mark.fcn_name,set_int},

{OC("mark_defined_WEB_macro"),S_INT,(void*)&w_style.misc.mark.WEB_macro,set_int},

{OC("mark_defined_outer_macro"),S_INT,(void*)&w_style.misc.mark.outer_macro,set_int},

{OC("mark_defined_exp_type"),S_INT,(void*)&w_style.misc.mark.imp_reserved_name,set_int},

{OC("mark_defined_typedef_name"),S_INT,(void*)&w_style.misc.mark.typedef_name,set_int},


{OC("indent_TeX"),S_STRING,(void*)&w_style.misc.TeXindent,set_str},

{OC("indent_code"),S_STRING,(void*)&w_style.misc.codeindent,set_str},


{OC("meta_TeX_begin"),S_STRING,(void*)&w_style.misc.meta.TeX.begin,set_str},

{OC("meta_TeX_end"),S_STRING,(void*)&w_style.misc.meta.TeX.end,set_str},

{OC("meta_code_begin"),S_STRING,(void*)&w_style.misc.meta.code.begin,set_str},

{OC("meta_code_end"),S_STRING,(void*)&w_style.misc.meta.code.end,set_str},


{OC("LaTeX_options"),S_STRING,(void*)&w_style.misc.LaTeX.class.options,set_str},

{OC("LaTeX_class_options"),S_STRING,(void*)&w_style.misc.LaTeX.class.options,set_str},


{OC("LaTeX_style"),S_STRING,(void*)&w_style.misc.LaTeX.class.file,set_str},

{OC("LaTeX_class"),S_STRING,(void*)&w_style.misc.LaTeX.class.file,set_str},


{OC("LaTeX_package_options"),S_STRING,(void*)&w_style.misc.LaTeX.package.options,set_str},

{OC("LaTeX_package"),S_STRING,(void*)&w_style.misc.LaTeX.package.file,set_str},


{OC("include_ext"),S_STRING,(void*)&w_style.misc.include_ext,set_str}

,



{OC("cchar"),S_CHAR,(void*)&t_style.cchar,ini_cchar},

{OC("line_length_N"),S_INT,(void*)&t_style.output_line_length,ini_output_line_length},

{OC("ASCII_fcn"),S_STRING,(void*)&t_style.ASCII_fcn,set_str},


{OC("cdir_start_C"),S_STRING,(void*)&t_style.cdir_start[0],set_str},

{OC("cdir_start_R"),S_STRING,(void*)&t_style.cdir_start[1],set_str},

{OC("cdir_start_N"),S_STRING,(void*)&t_style.cdir_start[2],set_str},

{OC("cdir_start_X"),S_STRING,(void*)&t_style.cdir_start[3],set_str},

{OC("cdir_start_V"),S_STRING,(void*)&t_style.cdir_start[4],set_str},

{OC("cdir_start_Cpp"),S_STRING,(void*)&t_style.cdir_start[5],set_str},

{OC("cdir_start_R90"),S_STRING,(void*)&t_style.cdir_start[6],set_str},

{OC("cdir_start_N90"),S_STRING,(void*)&t_style.cdir_start[7],set_str},


{OC("outer_def_C"),S_STRING,(void*)&t_style.outer_start[0].def,set_str},

{OC("outer_def_R"),S_STRING,(void*)&t_style.outer_start[1].def,set_str},

{OC("outer_def_N"),S_STRING,(void*)&t_style.outer_start[2].def,set_str},

{OC("outer_def_X"),S_STRING,(void*)&t_style.outer_start[3].def,set_str},

{OC("outer_def_V"),S_STRING,(void*)&t_style.outer_start[4].def,set_str},

{OC("outer_def_Cpp"),S_STRING,(void*)&t_style.outer_start[5].def,set_str},

{OC("outer_def_R90"),S_STRING,(void*)&t_style.outer_start[6].def,set_str},

{OC("outer_def_N90"),S_STRING,(void*)&t_style.outer_start[7].def,set_str},


{OC("outer_undef_C"),S_STRING,(void*)&t_style.outer_start[0].undef,set_str},

{OC("outer_undef_R"),S_STRING,(void*)&t_style.outer_start[1].undef,set_str},

{OC("outer_undef_N"),S_STRING,(void*)&t_style.outer_start[2].undef,set_str},

{OC("outer_undef_X"),S_STRING,(void*)&t_style.outer_start[3].undef,set_str},

{OC("outer_undef_V"),S_STRING,(void*)&t_style.outer_start[4].undef,set_str},

{OC("outer_undef_Cpp"),S_STRING,(void*)&t_style.outer_start[5].undef,set_str},

{OC("outer_undef_R90"),S_STRING,(void*)&t_style.outer_start[6].undef,set_str},

{OC("outer_undef_N90"),S_STRING,(void*)&t_style.outer_start[7].undef,set_str},


{OC("meta_top_C"),S_STRING,(void*)&t_style.meta[0].msg.top,set_str},

{OC("meta_top_R"),S_STRING,(void*)&t_style.meta[1].msg.top,set_str},

{OC("meta_top_N"),S_STRING,(void*)&t_style.meta[2].msg.top,set_str},

{OC("meta_top_X"),S_STRING,(void*)&t_style.meta[3].msg.top,set_str},

{OC("meta_top_V"),S_STRING,(void*)&t_style.meta[4].msg.top,set_str},

{OC("meta_top_Cpp"),S_STRING,(void*)&t_style.meta[5].msg.top,set_str},

{OC("meta_top_R90"),S_STRING,(void*)&t_style.meta[6].msg.top,set_str},

{OC("meta_top_N90"),S_STRING,(void*)&t_style.meta[7].msg.top,set_str},


{OC("meta_prefix_C"),S_STRING,(void*)&t_style.meta[0].msg.prefx,set_str},

{OC("meta_prefix_R"),S_STRING,(void*)&t_style.meta[1].msg.prefx,set_str},

{OC("meta_prefix_N"),S_STRING,(void*)&t_style.meta[2].msg.prefx,set_str},

{OC("meta_prefix_X"),S_STRING,(void*)&t_style.meta[3].msg.prefx,set_str},

{OC("meta_prefix_V"),S_STRING,(void*)&t_style.meta[4].msg.prefx,set_str},

{OC("meta_prefix_Cpp"),S_STRING,(void*)&t_style.meta[5].msg.prefx,set_str},

{OC("meta_prefix_R90"),S_STRING,(void*)&t_style.meta[6].msg.prefx,set_str},

{OC("meta_prefix_N90"),S_STRING,(void*)&t_style.meta[7].msg.prefx,set_str},


{OC("meta_bottom_C"),S_STRING,(void*)&t_style.meta[0].msg.bottom,set_str},

{OC("meta_bottom_R"),S_STRING,(void*)&t_style.meta[1].msg.bottom,set_str},

{OC("meta_bottom_N"),S_STRING,(void*)&t_style.meta[2].msg.bottom,set_str},

{OC("meta_bottom_X"),S_STRING,(void*)&t_style.meta[3].msg.bottom,set_str},

{OC("meta_bottom_V"),S_STRING,(void*)&t_style.meta[4].msg.bottom,set_str},

{OC("meta_bottom_Cpp"),S_STRING,(void*)&t_style.meta[5].msg.bottom,set_str},

{OC("meta_bottom_R90"),S_STRING,(void*)&t_style.meta[6].msg.bottom,set_str},

{OC("meta_bottom_N90"),S_STRING,(void*)&t_style.meta[7].msg.bottom,set_str},


{OC("meta_top_hdr_C"),S_STRING,(void*)&t_style.meta[0].hdr.top,set_str},

{OC("meta_top_hdr_R"),S_STRING,(void*)&t_style.meta[1].hdr.top,set_str},

{OC("meta_top_hdr_N"),S_STRING,(void*)&t_style.meta[2].hdr.top,set_str},

{OC("meta_top_hdr_X"),S_STRING,(void*)&t_style.meta[3].hdr.top,set_str},

{OC("meta_top_hdr_V"),S_STRING,(void*)&t_style.meta[4].hdr.top,set_str},

{OC("meta_top_hdr_Cpp"),S_STRING,(void*)&t_style.meta[5].hdr.top,set_str},

{OC("meta_top_hdr_R90"),S_STRING,(void*)&t_style.meta[6].hdr.top,set_str},

{OC("meta_top_hdr_N90"),S_STRING,(void*)&t_style.meta[7].hdr.top,set_str},


{OC("meta_prefix_hdr_C"),S_STRING,(void*)&t_style.meta[0].hdr.prefx,set_str},

{OC("meta_prefix_hdr_R"),S_STRING,(void*)&t_style.meta[1].hdr.prefx,set_str},

{OC("meta_prefix_hdr_N"),S_STRING,(void*)&t_style.meta[2].hdr.prefx,set_str},

{OC("meta_prefix_hdr_X"),S_STRING,(void*)&t_style.meta[3].hdr.prefx,set_str},

{OC("meta_prefix_hdr_V"),S_STRING,(void*)&t_style.meta[4].hdr.prefx,set_str},

{OC("meta_prefix_hdr_Cpp"),S_STRING,(void*)&t_style.meta[5].hdr.prefx,set_str},

{OC("meta_prefix_hdr_R90"),S_STRING,(void*)&t_style.meta[6].hdr.prefx,set_str},

{OC("meta_prefix_hdr_N90"),S_STRING,(void*)&t_style.meta[7].hdr.prefx,set_str},


{OC("meta_bottom_hdr_C"),S_STRING,(void*)&t_style.meta[0].hdr.bottom,set_str},

{OC("meta_bottom_hdr_R"),S_STRING,(void*)&t_style.meta[1].hdr.bottom,set_str},

{OC("meta_bottom_hdr_N"),S_STRING,(void*)&t_style.meta[2].hdr.bottom,set_str},

{OC("meta_bottom_hdr_X"),S_STRING,(void*)&t_style.meta[3].hdr.bottom,set_str},

{OC("meta_bottom_hdr_V"),S_STRING,(void*)&t_style.meta[4].hdr.bottom,set_str},

{OC("meta_bottom_hdr_Cpp"),S_STRING,(void*)&t_style.meta[5].hdr.bottom,set_str},

{OC("meta_bottom_hdr_R90"),S_STRING,(void*)&t_style.meta[6].hdr.bottom,set_str},

{OC("meta_bottom_hdr_N90"),S_STRING,(void*)&t_style.meta[7].hdr.bottom,set_str},


{OC("protect_C"),S_STRING,(void*)&t_style.protect_chars[0],set_str},

{OC("protect_R"),S_STRING,(void*)&t_style.protect_chars[1],set_str},

{OC("protect_N"),S_STRING,(void*)&t_style.protect_chars[2],set_str},

{OC("protect_X"),S_STRING,(void*)&t_style.protect_chars[3],set_str},

{OC("protect_V"),S_STRING,(void*)&t_style.protect_chars[4],set_str},

{OC("protect_Cpp"),S_STRING,(void*)&t_style.protect_chars[5],set_str},

{OC("protect_R90"),S_STRING,(void*)&t_style.protect_chars[6],set_str},

{OC("protect_N90"),S_STRING,(void*)&t_style.protect_chars[7],set_str},


{OC("line_char_C"),S_CHAR,(void*)&t_style.line_char[0],set_char},

{OC("line_char_R"),S_CHAR,(void*)&t_style.line_char[1],set_char},

{OC("line_char_N"),S_CHAR,(void*)&t_style.line_char[2],set_char},

{OC("line_char_X"),S_CHAR,(void*)&t_style.line_char[3],set_char},

{OC("line_char_V"),S_CHAR,(void*)&t_style.line_char[4],set_char},

{OC("line_char_Cpp"),S_CHAR,(void*)&t_style.line_char[5],set_char},

{OC("line_char_R90"),S_CHAR,(void*)&t_style.line_char[6],set_char},

{OC("line_char_N90"),S_CHAR,(void*)&t_style.line_char[7],set_char},


{OC("paren_num"),S_INT,(void*)&t_style.paren.num,set_int},

{OC("paren_nest"),S_INT,(void*)&t_style.paren.nest,set_int},

{OC("paren_len"),S_INT,(void*)&t_style.paren.len,set_int}

,



{OC("xchr"),S_STRING,(void*)&wt_style.xchr,set_str},

{OC("ext_delimiter"),S_CHAR,(void*)&wt_style.ext_delimiter,set_char},

{OC("ext_web"),S_STRING,(void*)&wt_style.input_ext.web,ini_ext},

{OC("ext_change"),S_STRING,(void*)&wt_style.input_ext.change,ini_ext},

{OC("ext_hweb"),S_STRING,(void*)&wt_style.input_ext.hweb,ini_ext},

{OC("ext_hchange"),S_STRING,(void*)&wt_style.input_ext.hchange,ini_ext},

{OC("suffix_C"),S_STRING,(void*)&wt_style.output_ext.C_,set_str},

{OC("suffix_Cpp"),S_STRING,(void*)&wt_style.output_ext.Cpp_,set_str},

{OC("suffix_V"),S_STRING,(void*)&wt_style.output_ext.V_,set_str},

{OC("suffix_FORTRAN"),S_STRING,(void*)&wt_style.output_ext.N_,set_str},

{OC("suffix_N"),S_STRING,(void*)&wt_style.output_ext.N_,set_str},

{OC("suffix_FORTRAN90"),S_STRING,(void*)&wt_style.output_ext.N90_,set_str},

{OC("suffix_N90"),S_STRING,(void*)&wt_style.output_ext.N90_,set_str},

{OC("suffix_RATFOR"),S_STRING,(void*)&wt_style.output_ext.R_,set_str},

{OC("suffix_R"),S_STRING,(void*)&wt_style.output_ext.R_,set_str},

{OC("suffix_RATFOR90"),S_STRING,(void*)&wt_style.output_ext.R90_,set_str},

{OC("suffix_R90"),S_STRING,(void*)&wt_style.output_ext.R90_,set_str},

{OC("suffix_TEX"),S_STRING,(void*)&wt_style.output_ext.X_,set_str},

{OC("suffix_X"),S_STRING,(void*)&wt_style.output_ext.X_,set_str},

{OC("null_file"),S_STRING,(void*)&wt_style.null_file_name,set_str},

{OC("Idir"),S_STRING,(void*)&wt_style.Idir,set_str},

{OC("dot_constant_begin"),S_CHAR,(void*)&wt_style.dot_delimiter.begin,ini_dot},

{OC("dot_constant_end"),S_CHAR,(void*)&wt_style.dot_delimiter.end,ini_dot},

{OC("color_mode"),S_INT,(void*)&wt_style.color_mode,ini_clr},

{OC("color_ordinary"),S_STRING,(void*)&wt_style.color.ordinary.name,ini_aclr},

{OC("color_program"),S_STRING,(void*)&wt_style.color.program_name.name,ini_aclr},

{OC("color_info"),S_STRING,(void*)&wt_style.color.info.name,ini_aclr},

{OC("color_warning"),S_STRING,(void*)&wt_style.color.warning.name,ini_aclr},

{OC("color_error"),S_STRING,(void*)&wt_style.color.error.name,ini_aclr},

{OC("color_fatal"),S_STRING,(void*)&wt_style.color.fatal.name,ini_aclr},

{OC("color_module_num"),S_STRING,(void*)&wt_style.color.module_num.name,ini_aclr},

{OC("color_line_num"),S_STRING,(void*)&wt_style.color.line_num.name,ini_aclr},

{OC("color_input_file"),S_STRING,(void*)&wt_style.color.in_file.name,ini_aclr},

{OC("color_include_file"),S_STRING,(void*)&wt_style.color.include_file.name,ini_aclr},

{OC("color_output_file"),S_STRING,(void*)&wt_style.color.out_file.name,ini_aclr},

{OC("color_timing"),S_STRING,(void*)&wt_style.color.timing.name,ini_aclr},

{OC("color_default"),S_STRING,(void*)&wt_style.color._NORMAL,ini_bilevel},

{OC("color_red"),S_STRING,(void*)&wt_style.color._RED,ini_bilevel},

{OC("color_green"),S_STRING,(void*)&wt_style.color._GREEN,ini_bilevel},

{OC("color_blue"),S_STRING,(void*)&wt_style.color._BLUE,ini_bilevel},

{OC("color_yellow"),S_STRING,(void*)&wt_style.color._YELLOW,ini_bilevel},

{OC("color_orange"),S_STRING,(void*)&wt_style.color._ORANGE,ini_bilevel}

,


{OC("ascii_constant"),S_STRING,(void*)&c_style.Ascii_constant,set_str},
{OC("begin_bp"),S_STRING,(void*)&c_style.Begin_bp,set_str},
{OC("begin_C"),S_STRING,(void*)&c_style.Begin_C,set_str},
{OC("begin_FORTRAN"),S_STRING,(void*)&c_style.Begin_FORTRAN,set_str},
{OC("begin_meta"),S_STRING,(void*)&c_style.Begin_meta,set_str},
{OC("begin_RATFOR"),S_STRING,(void*)&c_style.Begin_RATFOR,set_str},
{OC("begin_code"),S_STRING,(void*)&c_style.Begin_code,set_str},
{OC("begin_nweb"),S_STRING,(void*)&c_style.Begin_nuweb,set_str},
{OC("big_line_break"),S_STRING,(void*)&c_style.Big_line_break,set_str},
{OC("compiler_directive"),S_STRING,(void*)&c_style.Compiler_directive,set_str},
{OC("defd_at"),S_STRING,(void*)&c_style.Defd_at,set_str},
{OC("definition"),S_STRING,(void*)&c_style.Definition,set_str},
{OC("end_meta"),S_STRING,(void*)&c_style.End_meta,set_str},
{OC("force_line"),S_STRING,(void*)&c_style.Force_line,set_str},
{OC("format"),S_STRING,(void*)&c_style.Formatt,set_str},
{OC("explicit_reserved"),S_STRING,(void*)&c_style.Implicit_reserved,set_str},
{OC("insert_bp"),S_STRING,(void*)&c_style.Insert_bp,set_str},
{OC("invisible_cmnt"),S_STRING,(void*)&c_style.Invisible_cmnt,set_str},
{OC("join"),S_STRING,(void*)&c_style.Join,set_str},
{OC("limbo_text"),S_STRING,(void*)&c_style.Limbo_text,set_str},
{OC("math_break"),S_STRING,(void*)&c_style.Math_break,set_str},
{OC("module_name"),S_STRING,(void*)&c_style.Module_name,set_str},
{OC("new_module"),S_STRING,(void*)&c_style.New_module,set_str},
{OC("new_output_file"),S_STRING,(void*)&c_style.New_output_file,set_str},
{OC("no_index"),S_STRING,(void*)&c_style.No_index,set_str},
{OC("no_line_break"),S_STRING,(void*)&c_style.No_line_break,set_str},
{OC("no_mac_expand"),S_STRING,(void*)&c_style.No_mac_expand,set_str},
{OC("pseudo_colon"),S_STRING,(void*)&c_style.Pseudo_colon,set_str},
{OC("pseudo_expr"),S_STRING,(void*)&c_style.Pseudo_expr,set_str},
{OC("pseudo_semi"),S_STRING,(void*)&c_style.Pseudo_semi,set_str},
{OC("set_line_info"),S_STRING,(void*)&c_style.Set_line_info,set_str},
{OC("switch_math_flag"),S_STRING,(void*)&c_style.Switch_math_flag,set_str},
{OC("TeX_string"),S_STRING,(void*)&c_style.TeX_String,set_str},
{OC("thin_space"),S_STRING,(void*)&c_style.Thin_space,set_str},
{OC("trace"),S_STRING,(void*)&c_style.Trace,set_str},
{OC("undefinition"),S_STRING,(void*)&c_style.Undefinition,set_str},
{OC("underline"),S_STRING,(void*)&c_style.Underline,set_str},
{OC("verbatim"),S_STRING,(void*)&c_style.Verbatim,set_str},
{OC("WEB_definition"),S_STRING,(void*)&c_style.WEB_Definition,set_str},
{OC("xref_roman"),S_STRING,(void*)&c_style.Xref_roman,set_str},
{OC("xref_typewriter"),S_STRING,(void*)&c_style.Xref_typewriter,set_str},
{OC("xref_wildcard"),S_STRING,(void*)&c_style.Xref_wildcard,set_str},
{OC("yes_index"),S_STRING,(void*)&c_style.Yes_index,set_str}

,
{OC("")}
}
#endif /* |_STYLE_h| */
;



IN_STYLE boolean prn_style_defaults;


