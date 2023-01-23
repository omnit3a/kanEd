CC=gcc
CCFLAGS=-I$(HDRDIR) -O2

HDRDIR=include/

OUTDIR=bin/
OUTFILE=kanEd

SRCDIR=src/
SRCFILE=*.c

all:
	clear
	$(CC) -o $(OUTDIR)$(OUTFILE) $(SRCDIR)$(SRCFILE) $(CCFLAGS)
