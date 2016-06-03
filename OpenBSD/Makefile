CC = gcc

RELEASEDIR = ../release
SRCHELP = ./help
DESTHELP = /usr/local/share/smit
INSTALLDIR = /usr/local
MANSRCDIR = ./man/man1
MANDESTDIR = /usr/local/man/man1
SRCDIR = ./src

openbsdsmit:
	$(CC) -Wall -std=c99 -o smit  -Iinclude \
	$(SRCDIR)/smit.c  \
	$(SRCDIR)/shared/shared.c \
	$(SRCDIR)/menu/menu.c  \
	-l ncurses



clean:
	rm *.o  smit SMITsh
#	gunzip $(MANSRCDIR)/smit.1.gz

