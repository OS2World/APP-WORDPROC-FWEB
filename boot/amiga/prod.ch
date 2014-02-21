This file, PROD.CH, is a change file for installing FWEB 1.53 on the
Commodore Amiga with the SAS/C++ 6.55 development system.  It was written
for PROD.WEB 1.40 by <scherer@genesis.informatik.rwth-aachen.de> (94/12/09)
and updated for PROD.WEB 1.53 by <scherer@physik.rwth-aachen.de> (95/09/25)

To make use of this change file you'll need a running FTANGLE processor.
Apply this to the original prod.web together with this change file to
receive the updated version of prod.c for the compilation process.

This produced a weird compiler error because of a "reference beyond the
array limits".  I have not the slightest idea what's wrong here.

@x l.453
app(a->trans + tok_flag - tok_start);
@y
app(a->trans - tok_start + tok_flag);
@z
