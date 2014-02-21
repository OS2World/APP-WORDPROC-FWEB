#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06."  \
  COMMAND LINE: "web/ftangle web/style -A -# --F -= 1.53/web/style.c" \
  RUN TIME: "Saturday, September 23, 1995 at 16:17." \
  WEB FILE:    "web/style.web" \
  CHANGE FILE: (none)
#endif
#define _STYLE_h   \

#define CMNT_CHAR  '%'/* The comment character in the style file. */ \
 \

#define isodigit(c)(isdigit(c)&&(c)!='8'&&(c)!='9') \
/* An |outer_char| octal digit? */ \

#define Ctoi(c)ctoi(XCHR(c))/* For |ASCII|. */ \

#define ENV_FWEB_STY  "FWEB_STYLE_DIR"/* Environment variable that defines \
		directory of style file.  */ \

#define ignore  0 \

#define SET_ACOLOR(field,clr)wt_style.color.field.value= clr \

#define ENV_TERM  "TERM"/* Unix environment variable for terminal type. */ \

#define NUM_TEMP_PTRS  20 \



#include "typedefs.h"





#include "map.h"




typedef struct
{
CONST char*name;
COLOR value;
}CLR_MATCH;

CLR_MATCH clr_match[]= {
{"blue",BLUE},
{"default",NORMAL},
{"green",GREEN},
{"normal",NORMAL},
{"orange",ORANGE},
{"red",RED},
{"yellow",YELLOW},
{"",NORMAL}
};




/* The shorter length here is primarily to keep the stack under control. \
Now that |N_MSGBUF| is used  dynamically, maybe this statement isn't \
necessary. */
#ifdef SMALL_MEMORY
#define N_MSGBUF 2000
#else
#define N_MSGBUF 10000
#endif





#ifndef C_TYPES
#include SFILE(y_type.h)
#endif /* |C_TYPES| */



outer_char HUGE*sprm_buf,HUGE*sprm_ptr,HUGE*sprm_end;/* For \.{-p} option. */
outer_char HUGE*sprm_ptr0;/* Marks beginning of command-line \.{-p} options. */

boolean from_sprm;
static BUF_SIZE sbuf_len;/* Length of line buffer. */
static outer_char HUGE*stemp,HUGE*stemp_end,HUGE*tloc;/* Temporary \
	hold for the argument, and position in it. */
static outer_char cur_char;/* Current character after possible escape \
				translation. */
extern ASCII xord[];
extern outer_char xchr[];



static CONST outer_char*sty_file_name;
static boolean warn_if_absent;
static FILE*sty_file;
static S_MAP HUGE*map_array= fweb_map;/* Points to the common map \
	array for both \FWEAVE\ and \FTANGLE. */
jmp_buf top_of_style;/* Environment for the |setjmp|--|longjmp|. */



eight_bits ccode[128];/* Meaning of a character following '\.{@}'. */
CONST outer_char*cname[128];/* Associated names of control codes. */
CONST ASCII HUGE*at_codes;



static CC_BUF HUGE*cc_buf;


static outer_char HUGE*termcap;/* Name of termcap file. */
static outer_char HUGE*tcap_buffer;/* Allocated dynamically. */







outer_char esc_char FCN((ppc))
CONST outer_char HUGE*HUGE*ppc C1("")
{
int k;
unsigned n;
CONST outer_char HUGE*pc= *ppc;/* Pointer to first character after~'\.\\'. */

if(isodigit(*pc))

{
n= ctoi(*pc++);
for(k= 0;k<2;k++)
{
if(!isodigit(*pc))break;
n= 8*n+ctoi(*pc++);
}
}


else if(*pc=='x'&&isxdigit(*(pc+1)))

{
pc++;/* Position after \.{'x'}. */
n= ctoi(*pc++);
if(isxdigit(*pc))n= 16*n+ctoi(*pc++);
}


else
{/* Handle ordinary escaped character. */
switch(*pc)
{
case 'a':n= '\007';break;
case 'b':n= '\b';break;
case 'f':n= '\f';break;
case 'n':n= '\n';break;
case 'r':n= '\r';break;
case 't':n= '\t';break;
case 'v':n= '\v';break;
default:
n= (unsigned)(*pc);/* Unknowns, like '\.{\\m}' $\to$~'\.m'. */
break;
}
pc++;
}

*ppc= pc;
return(outer_char)n;
}


ASCII esc_achar FCN((ppc))
CONST ASCII HUGE*HUGE*ppc C1("")
{
int k;
unsigned n;
CONST ASCII HUGE*pc= *ppc;/* Pointer to first character after~'\.\\'. */

if(isOdigit(*pc))

{
n= Ctoi(*pc++);
for(k= 0;k<2;k++)
{
if(!isOdigit(*pc))break;
n= 8*n+Ctoi(*pc++);
}
}


else if(*pc==0170&&isXdigit(*(pc+1)))

{
pc++;/* Position after \.{'x'}. */
n= Ctoi(*pc++);
if(isXdigit(*pc))n= 16*n+Ctoi(*pc++);
}


else
{
switch(*pc)
{
case 0141:n= 07;break;
case 0142:n= 010;break;
case 0146:n= 014;break;
case 0156:n= 012;break;
case 0162:n= 015;break;
case 0164:n= 011;break;
case 0166:n= 013;break;
default:n= *pc;break;/* Unknowns, like '\.{\\m}' $\to$~'\.m'. */
}

#if(DEBUG_XCHR)
n= XCHR(n);
#endif
pc++;
}

*ppc= pc;/* Advance the pointer to point beyond the end of the constant. */

#if(DEBUG_XCHR)
n= xord[n];
#endif

return(ASCII)n;/* Return the value. */
}


int ctoi FCN((c))
outer_char c C1("")
{
switch(c)
{
case '0':return 0x0;case '1':return 0x1;case '2':return 0x2;case '3':return 0x3;case '4':return 0x4;case '5':return 0x5;
case '6':return 0x6;case '7':return 0x7;case '8':return 0x8;case '9':return 0x9;
case 'a':return 0xa;case 'A':return 0xA;
case 'b':return 0xb;case 'B':return 0xB;
case 'c':return 0xc;case 'C':return 0xC;
case 'd':return 0xd;case 'D':return 0xD;
case 'e':return 0xe;case 'E':return 0xE;
case 'f':return 0xf;case 'F':return 0xF;
default:return 0;
}
}


S_MAP HUGE*find_sty FCN((m,keyword))
S_MAP HUGE*m C0("Array of map variables")
CONST outer_char HUGE*keyword C1("Search for this keyword")
{
for(;*(m->keyword);m++)
if(STRCMP(keyword,m->keyword)==0)return m;

return NULL;
}


boolean sty_line(VOID)
{
typedef enum{FROM_INI,FROM_LOCAL,FROM_CMD_LINE}STYLE_MODE;

static STYLE_MODE mode= FROM_INI;

from_sprm= BOOLEAN(mode==FROM_INI||mode==FROM_CMD_LINE);

switch(mode)
{
case FROM_INI:
if(!sty0_line(sprm_ptr0))
mode++;
else
return YES;

case FROM_LOCAL:
if(!sty0_line(NULL))
mode++;
else
return YES;

case FROM_CMD_LINE:
return sty0_line(sprm_end);
}

return YES;/* Dummy. */
}

boolean sty0_line FCN((last_sprm))
outer_char HUGE*last_sprm C1("")
{
int c;/* Single character read from style file. |int| rather than |char| \
		because that's what |getc| returns. */

sloc= slimit= sbuf;/* Position to beginning of line. */

if(last_sprm)
{/* Read from the \.{-p} buffer. */
if(sprm_ptr>=last_sprm)
{/* Nothing more in the \.{-p} buffer. */
s_line= 0;
return NO;
}
else
{/* Copy line from \.{-p} buffer. */
int n;
outer_char HUGE*p;

if((p= (outer_char HUGE*)STRCHR(sprm_ptr,'\n'))==NULL)
{

err0_print(ERR_S,OC("Trouble in sty_line"),0);
return NO;
}
else n= PTR_DIFF(int,p,sprm_ptr);

STRNCPY(sloc,sprm_ptr,n);
sprm_ptr+= n+1;
slimit+= n;
s_line++;
}
}
else
{/* Read from the local style file. */
if(!sty_file)

{
outer_char full_sty_name[MAX_FILE_NAME_LENGTH];

/* If there's no style file, do nothing. */
if(!*sty_file_name)return NO;

if(warn_if_absent)
{
STRCPY(full_sty_name,sty_file_name);
add_prefix(full_sty_name);
}
else mk_fname(full_sty_name,MAX_FILE_NAME_LENGTH,
OC(ENV_FWEB_STY),NO,sty_file_name);

if((sty_file= fopen((char*)full_sty_name,"r"))==NULL)
{
if(warn_if_absent)
{

err0_print(ERR_C,OC("Can't open style file \"%s\""),1,full_sty_name);
}
return NO;
}

reading(full_sty_name,YES);
}




{
if(feof(sty_file))
return NO;

s_line++;

while((c= getc(sty_file))!=EOF&&c!='\n')
{
if(slimit==sbuf_end)
{

err0_print(ERR_S,OC("Input line too long; max is %lu characters"),1,sbuf_len);
ungetc(c,sty_file);
break;
}

*slimit++= (outer_char)c;/* Put character into buffer. */
}
}


}

return YES;
}


STY_TYPE next_sty(VOID)
{
outer_char c;/* Single character from the buffer. */

WHILE()
{
/* If we get to the end of the line or recognize a comment, read the next \
line. */
if(sloc==slimit||(c= *sloc++)==CMNT_CHAR)
{
if(!sty_line())return S_DONE;/* Get more. */
continue;
}

if(isalpha(c)||c=='_')
{
sloc--;
tloc= stemp;
while(isalpha(*sloc)||isdigit(*sloc)||*sloc=='_'||*sloc=='.')
{
cur_char= *sloc++;

{
if(tloc<stemp_end)
*tloc++= (outer_char)CHOICE(cur_char=='.','_',cur_char);
else
{

err0_print(ERR_S,OC("Buffer overflow"),0);
break;
}
}


}

*tloc= '\0';return S_KEYWORD;
}


else if(isdigit(c)||c=='-'||c=='+')
{
sloc--;
tloc= stemp;
if(*sloc=='+'||*sloc=='-'){cur_char= *sloc++;
{
if(tloc<stemp_end)*tloc++= cur_char;
else
{

err0_print(ERR_S,OC("Buffer overflow"),0);
break;
}
}

}

while(isdigit(*sloc)){cur_char= *sloc++;
{
if(tloc<stemp_end)*tloc++= cur_char;
else
{

err0_print(ERR_S,OC("Buffer overflow"),0);
break;
}
}

}

/* We allow the possibility of long integers. */
if(*sloc=='l'||*sloc=='L')
{
sloc++;/* Skip over '\.L'. */
*tloc= '\0';return S_LONG;
}

*tloc= '\0';return S_INT;
}


else if(c=='"')
{
tloc= stemp;/* Start of buffer. */

while(*sloc!='"')
{
if(*sloc=='\\')
if(++sloc==slimit)
{
sty_line();/* String is continued. */
continue;
}
else cur_char= esc_char(&sloc);
else cur_char= *sloc++;


{
if(tloc<stemp_end)*tloc++= cur_char;
else
{

err0_print(ERR_S,OC("Buffer overflow"),0);
break;
}
}


}

sloc++;/* Skip over terminating quote. */

*tloc= '\0';return S_STRING;
}


else if(c=='\'')
{
tloc= stemp;

/* If the character is escaped, turn the next character into the actual \
byte. */
if(*sloc=='\\'){sloc++;cur_char= esc_char(&sloc);}
else cur_char= *sloc++;


{
if(tloc<stemp_end)*tloc++= cur_char;
else
{

err0_print(ERR_S,OC("Buffer overflow"),0);
break;
}
}


sloc++;/* Skip over closing quote. */

*tloc= '\0';return S_CHAR;
}


else if(c==' '||c=='\t'||c=='=')continue;
else
{

err0_print(ERR_S,OC("Invalid style-file field; \
skipping remainder of file"),0);
longjmp(top_of_style,1);
}
}

DUMMY_RETURN(S_DONE);
}


SRTN read_sty FCN((sty_file_name0,warn_if_absent0))
CONST outer_char sty_file_name0[]C0("")
boolean warn_if_absent0 C1("")
{
sty_file_name= sty_file_name0;
warn_if_absent= warn_if_absent0;


{
IN_COMMON outer_char HUGE*style_args;

if(TeX_processor==LaTeX_p)
{
W_META HUGE*m= &w_style.misc.meta;
INDEX HUGE*i= &w_style.indx;

pfmt->id= pfmt->id_outer= pfmt->id_inner= OC("\\>");
pfmt->ID= pfmt->ID_OUTER= pfmt->ID_INNER= OC("\\WUC");
pfmt->RESERVED= OC("\\WRS");

m->TeX.begin= OC("\\begin{verbatim}");
m->TeX.end= OC("\\end{verbatim}");
m->code.begin= OC("\\WBM ");
m->code.end= OC("\\WEM ");

i->encap_prefix= OC("\\M");
i->encap_infix= OC("{");
i->encap_suffix= OC("}");
}

if(prn_style_defaults)
see_style(style_args,YES);
}




{
ALLOC(outer_char,sbuf,"sb",sbuf_len,0);
sbuf_end= sbuf+sbuf_len;

stemp= GET_MEM("stemp",sbuf_len,outer_char);
stemp_end= stemp+sbuf_len;

/* Reset the \.{-p} buffer. */
sprm_end= sprm_ptr;/* Actual end of material in buffer. */
sprm_ptr= sprm_buf;/* Start at beginning. */
}



if(setjmp(top_of_style)!=0)goto done_sty;

/* Read the first line of style file. If the file's empty, do nothing. */
if(!sty_line())goto done_sty;

/* Parse the file. */
WHILE()
switch(next_sty())
{
case S_CMNT:break;

case S_KEYWORD:

{
S_MAP HUGE*ps;/* Returned from |find_sty|. */
STY_TYPE type;

/* Is it a valid keyword? */
if((ps= find_sty(map_array,stemp))==NULL)
{

err0_print(ERR_S,OC("Invalid style-file keyword; skipping remainder of line"),0);
sty_line();
break;
}

/* Get the next argument. Is its type correct? */
type= ps->type&~S_MODIFIED;

if(type!=next_sty())
{

err0_print(ERR_S,OC("Argument of keyword \"%s\" has wrong type; \
conversion attempted"),1,ps->keyword);
}

switch(type)
{
case S_INT:
case S_LONG:
case S_STRING:
case S_CHAR:
break;

default:

err0_print(ERR_S,OC("Was expecting integer, double-quoted string, \
or single-quoted character here; argument not processed"),0);
goto processed;
}

/* Store the argument, check for validity, or process the result in some \
way. */
if(ps->init)
(*ps->init)(ps);
else
CONFUSION("style keyword","NULL ini fcn");

/* Flag it as modified. */
ps->type|= S_MODIFIED;

processed:;
}



break;

default:

err0_print(ERR_S,OC("Was expecting keyword or comment here; \
skipping remainder of file"),0);/* Falls through to |case S_DONE. */

case S_DONE:
done_sty:
if(sty_file)fclose(sty_file);
if(sprm_buf)FREE(sprm_buf);
FREE_MEM(stemp,"stemp",sbuf_len,outer_char);
FREE_MEM(sbuf,"sb",sbuf_len,outer_char);
return;
}
}


SRTN ini_style(VOID)
{
ini_colors(NO_COLOR);


{
link0(&wt_style.input_ext.web,OC("web"),ext_set);
link0(&wt_style.input_ext.change,OC("ch"),ext_set);
link0(&wt_style.input_ext.hweb,OC("hweb"),ext_set);
link0(&wt_style.input_ext.hchange,OC("hch"),ext_set);
}


}


SRTN set_str FCN((ps))
S_MAP HUGE*ps C1("")
{
a_str(ps->ptr,(CONST outer_char HUGE*)stemp);
}


SRTN add_str FCN((ps))
S_MAP HUGE*ps C1("")
{
outer_char HUGE*pa= *(outer_char HUGE**)ps->ptr,HUGE*pb;

if(*pa)
{
pb= GET_MEM("add_str",STRLEN(pa)+STRLEN(stemp)+2,outer_char);
STRCPY(pb,pa);
STRCAT(pb,"\n");
STRCAT(pb,stemp);
*(outer_char HUGE**)ps->ptr= pb;
}
else set_str(ps);
}


SRTN set_int FCN((ps))
S_MAP HUGE*ps C1("")
{
*((int*)ps->ptr)= ATOI(stemp);
}


SRTN set_long FCN((ps))
S_MAP HUGE*ps C1("")
{
*((long*)ps->ptr)= ATOL(stemp);
}


SRTN set_char FCN((ps))
S_MAP HUGE*ps C1("")
{
*((outer_char*)ps->ptr)= *stemp;
}


SRTN ini_aclr FCN((ps))
S_MAP HUGE*ps C1("")
{
CLR_MATCH HUGE*c;

set_str(ps);

for(c= clr_match;STRCMP(c->name,"")!=0;c++)
if(STRCMP(c->name,*(outer_char HUGE**)ps->ptr)==0)
{
*(COLOR*)ps->ptr= c->value;
return;
}

CLR_PRINTF(warning,("! Color name \"%s\" is invalid; \
replaced by \"default\"\n",(char*)ps->ptr));
mark_harmless;

*(COLOR*)ps->ptr= NORMAL;
}


SRTN ini_clr FCN((ps))
S_MAP HUGE*ps C1("")
{
set_int(ps);
ini_colors((COLOR_MODE)(*(int*)ps->ptr));
}


SRTN ini_ext FCN((ps))
S_MAP HUGE*ps C1("")
{
set_str(ps);
ext_set((CONST outer_char HUGE**)ps->ptr);
}


SRTN ini_dot FCN((ps))
S_MAP HUGE*ps C1("")
{
set_char(ps);
*(ASCII*)ps->ptr= XORD(*(outer_char*)ps->ptr);
}


SRTN ini_cchar FCN((ps))
S_MAP HUGE*ps C1("")
{
outer_char c;

set_char(ps);
c= *(outer_char*)ps->ptr;

if(!(c&&isprint(c)&&c!=' '&&c!='0'))
{
*(outer_char*)ps->ptr= CCHAR;

err0_print(ERR_S,OC("Invalid continuation character '%c'; '%c' assumed"),2,c,CCHAR);
}
}


SRTN ini_output_line_length FCN((ps))
S_MAP HUGE*ps C1("")
{
int output_line_length;

set_int(ps);
output_line_length= *(int*)ps->ptr;

if(output_line_length<MIN_OUTPUT_LINE_LENGTH||
output_line_length>MAX_OUTPUT_LINE_LENGTH)
{
*(int*)ps->ptr= STANDARD_OUTPUT_LINE_LENGTH;

err0_print(ERR_S,OC("Invalid line length; %d assumed"),1,STANDARD_OUTPUT_LINE_LENGTH);
}
}


SRTN zero_ccodes(VOID)
{
int c;/* Must be |int|, not |eight_bits|, so the |for| loop will end. */


/* Start out by initializing the array to a special flag. */
for(c= 0;c<=127;c++)
{
ccode[c]= USED_BY_NEITHER;
cname[c]= OC("?");
}


{
ccode[0100]= 0100;/* `quoted' at sign. This is so fundamental that it \
			isn't allowed to be changed by the style file. */

ccode[0173]= 0173;/* Since this is related to the C or \Ratfor\ languages, \
			it shouldn't be changed. */
ccode[0175]= 0175;/* As above. */

ccode[076]= ignore;/* This is historical, and probably dangerous.  But \
			it can't be |USED_BY_NEITHER|! */
}


}


SRTN ini_ccode FCN((keyword,defaults,code))
CONST outer_char*keyword C0("The desired keyword.")
CONST outer_char*defaults C0("String of default characters.")
eight_bits code C1("Assign this \FWEB\ universal code")
{
CONST outer_char*pc;/* Pointer to the default characters to initialize. */
CONST S_MAP HUGE*m;/* Points to map entry for requested keyword. */
boolean bad_code= NO;
eight_bits cval;
boolean override;/* Are the default values overridden by the style file? */
IN_COMMON outer_char style_file_name[];
ASCII a;/* Position in |ccode|. */

/* Search for the keyword in the map array. */
if((m= find_sty(map_array,keyword))==NULL)
override= NO;/* The keyword isn't even in the table. */
else
/* If the style file has set some values for this keyword, and the default \
  values for this code are non-zero, then use the values from the style file. \
  Otherwise, use the defaults. */
override= BOOLEAN(*(outer_char**)m->ptr!=NULL);
/* The style file is overriding. */

pc= (override&&code)?*(outer_char**)m->ptr:defaults;

/* If we're not ignoring this code completely, assign it to the relevant \
values. */
if(code!=USED_BY_NEITHER)
while(*pc)
{
if(override&&((cval= ccode[XORD(*pc)])!=USED_BY_NEITHER))
{
printf("! ccode['%c'] already filled with \"%s\"; \
not filled with \"%s\" = \"%s\".\n",
*pc,(char*)ccode_name(cval),(char*)keyword,
(char*)ccode_name(code));
bad_code= YES;
}

a= XORD(*pc++);
ccode[a]= code;
cname[a]= keyword;
}

if(bad_code)
FATAL(S,"!! Invalid control code mapping; check the style file ",
style_file_name);
}


SRTN reassign FCN((old_code,new_code))
eight_bits old_code C0("")
eight_bits new_code C1("")
{
int c;

for(c= 0;c<128;c++)
if(ccode[c]==old_code)
ccode[c]= new_code;
}


SRTN prn_codes(VOID)
{
IN_COMMON boolean found_web;
int HUGE*cc_indices;
boolean prn_all= NO;

int k;
int n= 0;/* Number of codes to print. */

if(!at_codes)
return;

puts("Control-code assignments \
([S,D,C]==`Begins [section,definition,code])':");

cc_buf= GET_MEM("cc_buf",128,CC_BUF);
cc_indices= GET_MEM("cc_indices",128,int);

if(*at_codes&&at_codes[0]==052&&at_codes[1]==052)
prn_all= YES;

if(*at_codes&&!prn_all)
{/* A specific list was given on command line. */
CONST ASCII*p;

for(p= at_codes;*p;p++)
prn0_code(*p,cc_buf,&n);
}
else
{/* Do all of them. */
ASCII a;

for(a= 0;a<128;a++)
{
if(ccode[a]==USED_BY_NEITHER&&!prn_all)
continue;

prn0_code(a,cc_buf,&n);
}
}

FREE_MEM(at_codes,"at_codes",200,ASCII);

for(k= 0;k<n;k++)
cc_indices[k]= k;

QSORT(cc_indices,n,sizeof(int),cc_cmp);

for(k= 0;k<n;k++)
STRCPY(cc_buf[k][1],cc_buf[cc_indices[k]][0]);

for(k= 0;k<n;k++)
printf("%-40s%-40s\n",cc_buf[k][0],cc_buf[k][1]);

FREE_MEM(cc_buf,"cc_buf",128,CC_BUF);
FREE_MEM(cc_indices,"cc_indices",128,int);

if(!found_web)
wrap_up();
}


int cc_cmp FCN((k0,k1))
CONST VOID*pk0 C0("")
CONST VOID*pk1 C1("")
{
char*s0,*s1;

s0= strrchr(cc_buf[*(int*)pk0][0],'-');
s1= strrchr(cc_buf[*(int*)pk1][0],'-');

return STRCMP(s0,s1);
}


SRTN prn0_code FCN((a,cc_buf,pk))
ASCII a C0("")
CC_BUF HUGE*cc_buf C0("")
int*pk C1("")
{
ASCII new_module,begin_code,formatt;
ASCII cc= ccode[a];
outer_char c;
int n;
outer_char*letter;

/* The following assumes that these particular codes never change.  This \
was easier than including the header files. */
new_module= ccode[052];
begin_code= ccode[0141];
formatt= ccode[0146];

c= XCHR(a);

if(cc==USED_BY_NEITHER)
letter= OC("   ");
else if(cc>=new_module)
letter= OC("[S]");
else if(cc>=begin_code)
letter= OC("[C]");
else if(cc>=formatt)
letter= OC("[D]");
else
letter= OC("   ");

n= 
nsprintf((outer_char*)&cc_buf[*pk][0][0],OC(isprint(c)?"  %s @%c":" %s@'0x%02x'"),2,isprint(c)?letter:OC(""),c);

switch(c)
{
case '/':
cname[c]= OC("(verbatim comment)");
break;

case '>':
cname[c]= OC("(end of module name)");
break;

case '@':
cname[c]= OC("(literal '@')");
break;
}

sprintf(&cc_buf[*pk][0][n]," --- %s",(char*)cname[c]);
(*pk)++;/* Increment array index. */
}


SRTN ini_colors FCN((color_mode))
COLOR_MODE color_mode C1("")
{

{
SET_ACOLOR(ordinary,NORMAL);
SET_ACOLOR(program_name,YELLOW);
SET_ACOLOR(info,GREEN);
SET_ACOLOR(warning,ORANGE);
SET_ACOLOR(error,RED);
SET_ACOLOR(fatal,RED);
SET_ACOLOR(module_num,ORANGE);
SET_ACOLOR(line_num,ORANGE);
SET_ACOLOR(in_file,YELLOW);
SET_ACOLOR(include_file,BLUE);
SET_ACOLOR(out_file,YELLOW);
SET_ACOLOR(timing,ORANGE);
}

/* Attach colors to fields. */

if(!(termcap= get_termcap()))wt_style.color_mode= color_mode= NO_COLOR;



link0(&wt_style.color._NORMAL,OC("me"),termset);
link0(&wt_style.color._YELLOW,OC("md"),termset);
link0(&wt_style.color._GREEN,OC("me"),termset);
link0(&wt_style.color._ORANGE,OC("me"),termset);
link0(&wt_style.color._RED,OC("mdmr"),termset);
link0(&wt_style.color._BLUE,OC("me"),termset);



switch(color_mode)
{
case NO_COLOR:
break;

case BILEVEL:
link0(&wt_style.color._YELLOW,OC("md"),termset);
link0(&wt_style.color._GREEN,OC("md"),termset);
link0(&wt_style.color._RED,OC("mdmr"),termset);
break;

case TRUE_COLOR:
link0(&wt_style.color._YELLOW,OC("md"),termset);
link0(&wt_style.color._GREEN,OC("us"),termset);
link0(&wt_style.color._BLUE,OC("md"),termset);
link0(&wt_style.color._ORANGE,OC("md"),termset);
link0(&wt_style.color._RED,OC("mdmr"),termset);
break;
}
}


SRTN ini_bilevel FCN((ps))
S_MAP HUGE*ps C1("")
{
set_str(ps);

if(termcap==NULL)return;

termset(ps->ptr);
}


SRTN link0 FCN((pp,id,fcn))
outer_char HUGE**pp C0("")
CONST outer_char HUGE*id C0("")
SRTN(HUGE_FCN_PTR*fcn)PROTO((CONST outer_char HUGE**))C1("")
{
a_str(pp,id);/* Allocate space, and store abbreviation string. */
(*fcn)((CONST outer_char HUGE**)pp);/* Replace that string by actual escape \
					sequences. */
}


SRTN a_str FCN((pp,id))
outer_char HUGE**pp C0("")
CONST outer_char HUGE*id C1("")
{
*((outer_char HUGE**)pp)= GET_MEM("map_string",STRLEN(id)+1,outer_char);
STRCPY(*((outer_char HUGE**)pp),id);
}


outer_char*get_termcap(VOID)
{
#if !HAVE_GETENV
return NULL;
#else
if((termcap= GETENV(ENV_TERM))==NULL)return NULL;

tcap_buffer= GET_MEM("tcap_buffer",1024,outer_char);

switch(tgetent(tcap_buffer,termcap))
{
case-1:
printf("! Can't open termcap file \"%s\"\n",(char*)termcap);

case 0:
return NULL;
}

return termcap;
#endif /* |HAVE_GETENV| */
}


SRTN termset FCN((pid))
CONST outer_char HUGE**pid C1("")
{
outer_char value_buf[500],*area= value_buf;/* For |tgetstr|. */
outer_char*s;
CONST outer_char HUGE*t;
outer_char id[3];
int k,n;
SEQUENCES HUGE*ps= GET_MEM("termcap struct",1,SEQUENCES);
outer_char*string[NUM_TEMP_PTRS];

if(!termcap)return;

for(t= *pid,n= 0;*t;t+= 2)
{
if(n==NUM_TEMP_PTRS)break;
while(*t==' ')t++;

/* Put the abbreviation for escape sequence into |id|. */
STRNCPY(id,t,2);
TERMINATE(id,2);

/* Get the actual escape sequence from termcap file. */
if((s= tgetstr(id,&area))==NULL)
printf("! Termcap entry \"%s\" not found \
for terminal type \"%s\".\n",(char*)id,(char*)termcap);
else string[n++]= s;
}


{
ps->n= (short)n;
ps->string= GET_MEM("termcap strings",n,outer_char*);

for(k= 0;k<n;k++)
{
ps->string[k]= GET_MEM("termcap string",
STRLEN(string[k])+1,outer_char);
STRCPY(ps->string[k],string[k]);
}

FREE((void*)(*pid));
*pid= (CONST outer_char HUGE*)ps;
}


}


SRTN ext_set FCN((pid))
CONST outer_char HUGE**pid C1("")
{
outer_char id[1000],*p,*p0;
CONST outer_char HUGE*t;
outer_char*string[NUM_TEMP_PTRS];
int k,n;
SEQUENCES HUGE*ps= GET_MEM("termcap struct",1,SEQUENCES);

t= *pid;/* Beginning of blank-separated list. */
n= 0;/* Number of fields found. */
p= id;/* Start of storage area */

while(*t)
{
if(n==NUM_TEMP_PTRS)break;
while(*t==' ')t++;/* Skip initial white space. */

p0= p;
while(*t!=' '&&*t)*p++= *t++;
TERMINATE(p,0);
p++;
string[n++]= p0;/* Remember where string is. */
}


{
ps->n= (short)n;
ps->string= GET_MEM("termcap strings",n,outer_char*);

for(k= 0;k<n;k++)
{
ps->string[k]= GET_MEM("termcap string",
STRLEN(string[k])+1,outer_char);
STRCPY(ps->string[k],string[k]);
}

FREE((void*)(*pid));
*pid= (CONST outer_char HUGE*)ps;
}


}


int put_out FCN((c))
int c C1("")
{
return putchar(c);
}


SRTN set_color FCN((clr))
COLOR clr C1("")
{
color0.last= color0.present;/* Save the incoming color, for later restore. */

if(wt_style.color_mode!=NO_COLOR)
switch(clr)
{

case NORMAL:
tput((SEQUENCES*)wt_style.color._NORMAL);
break;

case GREEN:
tput((SEQUENCES*)wt_style.color._GREEN);
break;

case RED:
tput((SEQUENCES*)wt_style.color._RED);
break;

case BLUE:
tput((SEQUENCES*)wt_style.color._BLUE);
break;

case ORANGE:
tput((SEQUENCES*)wt_style.color._ORANGE);
break;

case YELLOW:
tput((SEQUENCES*)wt_style.color._YELLOW);
break;

default:
tput((SEQUENCES*)wt_style.color._NORMAL);
break;
}

color0.present= clr;
}


SRTN tput FCN((ps))
SEQUENCES*ps C1("")
{
int k;

for(k= 0;k<ps->n;k++)
tputs(ps->string[k],1,put_out);
}


SRTN see_style FCN((pa,see_all))
CONST outer_char HUGE*pa C0("")
boolean see_all C1("")
{
S_MAP HUGE**s0,HUGE**s,HUGE**s1,HUGE*m;

s0= GET_MEM("s0",sizeof(fweb_map)/sizeof(S_MAP),S_MAP HUGE*);

/* Fill an array of pointers. */
for(s= s0,m= fweb_map;*(m->keyword);s++,m++)
*s= m;

/* Sort the array. */
QSORT(s0,s-s0,sizeof(S_MAP HUGE*),cmpr_s_map);

/* Print out the values. */
printf("%s style-file parameters%s%s%s%s:\n",
see_all?"Default":"Modified",
*pa?" beginning with \"":"",(char*)pa,*pa?"\"":"",
see_all?"\n (null or empty values for colors and \
@ command codes are misleading)":"");

if(*pa)
{/* Convert \.{'.'} to \.{'\_'}. */
outer_char HUGE*p;

for(p= (outer_char HUGE*)pa;*p;p++)
if(*p=='.')
*p= '_';
}

for(s1= s0;s1<s;s1++)
see_map(*s1,pa,see_all);

FREE_MEM(s0,"s0",sizeof(fweb_map)/sizeof(S_MAP),S_MAP);
}


int cmpr_s_map FCN((s0,s1))
S_MAP HUGE**s0 C0("")
S_MAP HUGE**s1 C1("")
{
return STRCMP((*s0)->keyword,(*s1)->keyword);
}


SRTN see_map FCN((s,pa,see_all))
S_MAP HUGE*s C0("")
CONST outer_char HUGE*pa C0("")
boolean see_all C1("")
{
if(*pa&&STRNCMP(pa,s->keyword,STRLEN(pa))!=0)return;

if(see_all)
printf(" ");
else
{/* Handled modified parameters. */
if(s->type&S_MODIFIED)
{
printf("*");
s->type&= ~S_MODIFIED;
}

else return;
}

printf(" %s = ",(char*)s->keyword);

switch(s->type)
{
case S_STRING:
see_str(*((outer_char**)s->ptr));
break;

case S_CHAR:
printf("'%c'\n",*(outer_char*)s->ptr);
break;

case S_INT:
printf("%d\n",*(int*)s->ptr);
break;

case S_LONG:
printf("%ld\n",*(long*)s->ptr);
break;

default:
break;
}
}


SRTN see_str FCN((s))
CONST outer_char HUGE*s C1("")
{
outer_char c;

if(s==NULL)
{
printf("NULL\n");
return;
}
else if(s<(outer_char HUGE*)100)
{/* Horrible kludge to handle stupid color processing. */
printf("\n");
return;
}

printf("\"");

while((c= *s++))
print_it:
if(c=='\\')printf("\\\\");
else if(isprint(c))printf("%c",c);
else
{
printf("\\");
switch(c)
{
case '\a':c= 'a';goto print_it;
case '\b':c= 'b';goto print_it;
case '\f':c= 'f';goto print_it;
case '\n':c= 'n';goto print_it;
case '\r':c= 'r';goto print_it;
case '\t':c= 't';goto print_it;
case '\v':c= 'v';goto print_it;
default:
printf("%o",c);
break;
}
}

printf("\"\n");
}


