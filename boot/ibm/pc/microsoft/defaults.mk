# Generated automatically from defaults.mk.in and pc.microsoft.ini by FWEB_configure.
# --- START of SYSTEM CONFIGURATION SECTION ---
# Parameter settings from pc.ini.

# --- Supporting VPATH ---
top_srcdir = ./..
srcdir = .
VPATH = .

# --- Names of system commands --- 
# (Used in the Makefile and possibly internally to FWEB.)
MAKE = nmake
MV = rename
RM = del
TOUCH = $(MAKE) -t

# --- COMPILING ---

# --- Compiler name ---
CC = cl

# An FWEB flag, either CC or GCC.  This flag isn't used for bootstrapping; it
# is required for properly regenerating custom.h by tangling custom.web.  If
# you're on the Sun and working with gcc, say ``COMPILER = GCC''.
COMPILER = CC

# --- Compiler options ---
# Debugging and optimization options for the C compiler.
CFLAGS = /AH /F 5000 /Gt32 /NT$* /W4 /J

# Header file search directory (-Idir) and any other miscellaneous options
# for the C preprocessor and compiler.
CPPFLAGS = /I. /Id:c700include

# (Compiler macro definitions.  In addition, see the discussion of PARTn
# below.)  
DEFS = /Dibmpc /Dmcc 

# --- The actual compile command used by the Makefile.  ---
COMPILE = $(CC) /c $(CFLAGS) $(CPPFLAGS) $(DEFS) /Fo$*



# --- LINKING ---

# --- Extensions for object files ---
# $(O) is used for targets in the Makefile. $(OBJ) is the suffix used in
# the link line.  (Sometimes $(OBJ) can be null if the compiler understands
# defaults and the length of the command line is an issue, as it is on some
# personal computers.)
O = obj
OBJ = 

# TERMCAP0 is either a file name, or null.  Generally you should use the stub
# termcap0.$(O).  If you are going to use the system termcap library (only
# relevant for color, an experiment that isn't completed yet) make
# TERMCAP0 null and include ``-ltermcap'' in the LIBS line below.
TERMCAP0 = termcap0.$(O)

# --- Linker options ---

# Stripping (-s) and other miscellaneous options for the linker.
LDFLAGS = /AH /F 5000

# Library options -l and -L to pass to the linker.
LIBS = 

# --- The actual link command used by the Makefile.  ---
# TRY NOT TO CHANGE THIS LINE.
LINK = $(CC) $(LDFLAGS)  /Fe$*$(LOAD_RATFOR)



# --- MISCELLANEOUS ---

# --- How to print a dvi file ---
ECHO = echo # Use this to prevent actual printing.
PRINT_DVI  = $(ECHO) lpr -d

# --- FWEB flags indicating type of machine on which you're tangling
# (HOME_MACHINE) and for which machine you're generating C code. ---
HOME_MACHINE = IBMPC
MACHINE = IBMPC

# --- FWEB file suffixes ---
# (For IBM-PC, shorten to ``hwe'')
HWEB = hwe

# --- Splitting FTANGLE & FWEAVE into several parts, especially for small
# compilers on personal computers.  Here's an example for the IBM-PC,
# Microsoft compiler ---
# ---------------------------------------------------------------------------
#PART1 = /Dpart=1
#PART2 = /Dpart=2
#PART3 = /Dpart=3

#FTANGLE2 = ftangle2.$(O)
#FTANGLE3 = ftangle3.$(O)

#FWEAVE2 = fweave2.$(O)
#FWEAVE3 = fweave3.$(O)

#PROD2 = prod2.$(O)
#RATFOR2 = ratfor2.$(O)
#RESERVED2 = reservd2.$(O)
#COMMON2 = common2.$(O)
# ---------------------------------------------------------------------------

# The PARTn macros are compiler options that define the macro |part|
#to be n, for example ``-Dpart=2''
PART1 = /Dpart=1
PART2 = /Dpart=2
PART3 = /Dpart=3

# Here are the names of the second and third parts of the object files.
FTANGLE2 = ftangle2.$(O)
FTANGLE3 = ftangle3.$(O)

FWEAVE2 = fweave2.$(O)
FWEAVE3 = fweave3.$(O)

PROD2 = prod2.$(O)
RATFOR2 = ratfor2.$(O)
RESERVED2 = reservd2.$(O)
COMMON2 = common2.$(O)


# --- INSTALLATION INFORMATION ---
INSTALL = copy
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA = $(INSTALL)

# Top-level path for executable binaries (usually /usr/local):
exec_prefix = /usr/local

# Where the processors go:
bindir = $(exec_prefix)/bin

# Top-level path for everything else (usually /usr/local)
prefix = /usr/local
doc_prefix = $(prefix)

# Where the Unix man pages go:
manext = 1
mandir = $(doc_prefix)/man/man$(manext)

# Where the emacs info* files go:
infodir = $(doc_prefix)/info

# Where the source file fweb.texinfo goes:
texinfodir = $(infodir)

# Where the fwebmac.sty macro package used by FWEAVE goes, as well as the
# file fweb.tex needed for weaving the FWEB source code, go:
texdir = $(prefix)/lib/tex/inputs

# --- END of SYSTEM CONFIGURATION SECTION ---

