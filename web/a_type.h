#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06." 
  COMMAND LINE: "web/ftangle web/a_type -A -# --F -= 1.53/web/a_type.h"
  RUN TIME: "Saturday, September 23, 1995 at 16:17."
  WEB FILE:    "web/a_type.web"
  CHANGE FILE: (none)
#endif


int tgetent PROTO((outer_char*buffer,CONST outer_char*name));
int tgetflag PROTO((CONST outer_char*id));
int tgetnum PROTO((CONST outer_char*id));
outer_char*tgetstr PROTO((CONST outer_char*id,outer_char**area));
outer_char*tgoto PROTO((CONST outer_char*cm,int destcol,int destline));
SRTN tputs PROTO((outer_char*cp,int affcnt,int(*outc)(int)));


