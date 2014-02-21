#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06." 
  COMMAND LINE: "web/ftangle web/d_type -A -# --F -= 1.53/web/d_type.h"
  RUN TIME: "Saturday, September 23, 1995 at 16:17."
  WEB FILE:    "web/d_type.web"
  CHANGE FILE: (none)
#endif


int cmpr_nd PROTO((NAME_INFO HUGE**p0,NAME_INFO HUGE**p1));
SRTN ini_tokens PROTO((LANGUAGE language0));
SRTN ini_RAT_tokens PROTO((LANGUAGE language0));
SRTN ini_reserved PROTO((LANGUAGE l));
SRTN save_id PROTO((WORD_TYPE word_type,LANGUAGE language0,
CONST outer_char HUGE**words));
SRTN save_words PROTO((LANGUAGE language0,CONST RESERVED_WORD HUGE*words));
SRTN see_reserved PROTO((CONST RSRVD HUGE*prsrvd));

