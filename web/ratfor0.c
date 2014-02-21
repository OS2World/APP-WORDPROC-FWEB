#if(0)
  FTANGLE v1.53, created with UNIX on "Thursday, September 21, 1995 at 15:06."  \
  COMMAND LINE: "web/ftangle web/ratfor0 -A -# --F -= 1.53/web/ratfor0.c" \
  RUN TIME: "Saturday, September 23, 1995 at 16:17." \
  WEB FILE:    "web/ratfor0.web" \
  CHANGE FILE: (none)
#endif
#define BAD_CALL(fcn_name)bad_call(OC(fcn_name)) \



#include "typedefs.h"







#include "c_type.h"




/* The shorter length here is primarily to keep the stack under control. \
Now that |N_MSGBUF| is used  dynamically, maybe this statement isn't \
necessary. */
#ifdef SMALL_MEMORY
#define N_MSGBUF 2000
#else
#define N_MSGBUF 10000
#endif





sixteen_bits id_function,id_program,id_subroutine;
boolean balanced= YES;
ASCII cur_delim= '\0';








SRTN is_Rat_present(VOID)
{
Rat_is_loaded= BOOLEAN(program==weave);
}


boolean Rat_OK FCN((msg))
outer_char*msg C1("")
{
if(Rat_is_loaded)return YES;/* We might get here by a call from \
				\.{common} during \FWEAVE. */


err0_print(ERR_R,OC("Ratfor is not loaded.  %s"),1,msg);
return NO;
}


SRTN bad_call FCN((fcn_name))
outer_char*fcn_name C1("")
{
CONFUSION(fcn_name,"This function shouldn't be called");
}


SRTN alloc_Rat(VOID)
{}


SRTN ini_Ratfor(VOID)
{}


SRTN ini_RAT_tokens FCN((language0))
LANGUAGE language0 C1("")
{
if(Rat_is_loaded)return;
BAD_CALL("ini_RAT_tokens");
}


SRTN cp_fcn_body(VOID)
{
BAD_CALL("cp_fcn_body");
}


int chk_lbl(VOID)
{
BAD_CALL("chk_lbl");
return-1;/* Avoids spurious compiler warning. */
}


SRTN RAT_error(VOID)
{
BAD_CALL("RAT_error");
}


X_FCN x_unroll(VOID)
{
Rat_OK(OC("Therefore, the _DO macro cannot be used, since it relies on some \
Ratfor features (sorry)"));
}


