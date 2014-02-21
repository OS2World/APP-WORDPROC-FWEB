#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06." 
  COMMAND LINE: "web/ftangle web/y_type -A -# --F -= 1.53/web/y_type.h"
  RUN TIME: "Saturday, September 23, 1995 at 16:17."
  WEB FILE:    "web/y_type.web"
  CHANGE FILE: (none)
#endif


void HUGE*alloc PROTO((CONST outer_char abbrev[],BUF_SIZE HUGE*pnunits,
size_t nsize,int dn));

SRTN free_mem0 PROTO((void HUGE*p,CONST outer_char why[],BUF_SIZE nunits,
size_t nsize));

void HUGE*get_mem0 PROTO((CONST outer_char why[],BUF_SIZE nunits,
size_t nsize));
