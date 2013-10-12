ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

AM_MAKEFLAGS = --no-print-directory
AM_CPPFLAGS = -I${top_srcdir}/src
AM_CFLAGS = -std=gnu99

if AMC_HISTORY
man_MANS = man/rc.1 man/history.1
HISTORY = src/history
else
man_MANS = man/rc.1
endif

if AMC_NO_HASHBANG
EXECVE = src/execve.o
endif

if AMC_READLINE
READLINE = src/readline.o
endif

if AMC_RESTART
SYSTEM = src/system-bsd.o
else
SYSTEM = src/system.o
endif

bin_PROGRAMS = src/rc
noinst_PROGRAMS = src/mksignal src/mkstatval src/tripping $(HISTORY)

src_rc_SOURCES = \
		src/builtins.c \
		src/except.c \
		src/exec.c \
		src/fn.c \
		src/footobar.c \
		src/option.c \
		src/glob.c \
		src/glom.c \
		src/hash.c \
		src/heredoc.c \
		src/input.c \
		src/lex.c \
		src/list.c \
		src/main.c \
		src/match.c \
		src/nalloc.c \
		src/open.c \
		src/parse.c \
		src/print.c \
		src/redir.c \
		src/signals.c \
		src/status.c \
		src/tree.c \
		src/utils.c \
		src/var.c \
		src/wait.c \
		src/walk.c \
		src/which.c

EXTRA_src_rc_SOURCES = \
		src/addon.c \
		src/execve.c \
		src/readline.c \
		src/system.c \
		src/system-bsd.c

src_rc_DEPENDENCIES = src/sigmsgs.o $(ADDON) $(EXECVE) $(READLINE) $(SYSTEM)
src_rc_LDADD = src/sigmsgs.o $(ADDON) $(EXECVE) $(READLINE) $(SYSTEM)

noinst_HEADERS = \
	  src/getgroups.h \
		src/jbwrap.h \
		src/parse.h \
		src/proto.h \
		src/rc.h \
		src/rlimit.h \
		src/stat.h \
		src/wait.h

BUILT_SOURCES = src/sigmsgs.c

EXTRA_DIST = \
		m4 \
		EXAMPLES \
		RELDATE \
		src/addon.c \
		src/addon.h \
		man/history.1 \
		src/parse.y \
		man/rc.1 \
		scripts/trip.rc

src/sigmsgs.c src/sigmsgs.h: src/mksignal
	$(AM_V_GEN)./src/mksignal ./src

# Newer automake's buildtime dependency tracking can't seem to figure
# this one out.
src/status.o: src/statval.h

src/statval.h: src/mkstatval
	$(AM_V_GEN)./src/mkstatval > ./src/statval.h

CONFIGURE_DEPENDENCIES = RELDATE

DISTCLEANFILES = src/sigmsgs.c src/sigmsgs.h src/statval.h src/sigmsgs.o

# Of course, parse.c and parse.h depend on parse.y.  However, unless
# you're hacking on rc's grammar, it's not useful to have this
# dependency expressed, since the distributed parse.[ch] (generated with
# byacc, and lightly edited to remove a couple of gcc warnings) are
# portable (I hope).
src/parse.c src/parse.h: src/parse.y
	$(YACC) -d src/parse.y
	mv y.tab.c src/parse.c
	mv y.tab.h src/parse.h

check: src/trip

src/trip: src/rc src/tripping
	./src/rc -p < ./scripts/trip.rc

install-exec-hook:
if AMC_HISTORY
	$(INSTALL_PROGRAM) history $(bindir)/- ;\
	rm -f $(bindir)/--;  $(LN) $(bindir)/- $(bindir)/-- ;\
	rm -f $(bindir)/-p;  $(LN) $(bindir)/- $(bindir)/-p ;\
	rm -f $(bindir)/--p; $(LN) $(bindir)/- $(bindir)/--p
endif
