/* main.c: handles initialization of rc and command line options */

#include "common.h"
#include "print.h"
#include "hash.h"
#include "convert.h"
#include "signals.h"
#include "input.h"
#include "glom.h"
#include "status.h"
#include "builtins.h"
#include "open.h"
#include "option.h"

bool dashdee;
bool dashee;
bool dashvee;
bool dashex;
bool dashell;
bool dashEYE;
bool dasheye;
bool dashen;
bool dashpee;
bool dashess;
bool interactive;
pid_t rc_pid;

static bool dashoh;

static void assigndefault(char *name,...) {
  va_list ap;
  List *l;
  char *v;
  va_start(ap, name);
  for (l = NULL; (v = va_arg(ap, char *)) != NULL;) {
    l = append(l, word(v, NULL));
  }
  variable_assign(name, l, FALSE);
  set_exportable(name, FALSE);
  if (streq(name, "path")) {
    variable_alias(name, l, FALSE);
  }
  va_end(ap);
}

// Open an fd on /dev/null if it is inherited closed.
static void checkfd(int fd, enum redirtype r) {
  int new = rc_open("/dev/null", r);
  if (new != fd && new != -1) {
    close(new);
  }
}

static void initdefaults() {
  assigndefault("ifs", " ", "\t", "\n", (void *)0);
#ifdef DEFAULTPATH
  assigndefault("path", DEFAULTPATH, (void *)0);
#endif
  assigndefault("pid", nprint("%d", rc_pid), (void *)0);
  assigndefault("prompt", "; ", "", (void *)0);
  assigndefault("version", VERSION, 
                "$Release: @(#)" PACKAGE " " VERSION " " RELDATE " $", 
                (void *)0);
}

int main(int argc, char *argv[], char *envp[]) {
  char *dashsee[2], *dollarzero, *null[1];
  int c;
  initprint();
  dashsee[0] = dashsee[1] = NULL;
  dollarzero = argv[0];
  rc_pid = getpid();

  // Unix tradition.
  dashell = (*argv[0] == '-'); 
  while ((c = rc_getopt(argc, argv, "c:deiIlnopsvx")) != -1) {
    switch (c) {
    case 'c':
      dashsee[0] = rc_optarg;
      goto quitopts;
    case 'd':
      dashdee = TRUE;
      break;
    case 'e':
      dashee = TRUE;
      break;
    case 'I':
      dashEYE = TRUE;
      interactive = FALSE;
      break;
    case 'i':
      dasheye = interactive = TRUE;
      break;
    case 'l':
      dashell = TRUE;
      break;
    case 'n':
      dashen = TRUE;
      break;
    case 'o':
      dashoh = TRUE;
      break;
    case 'p':
      dashpee = TRUE;
      break;
    case 's':
      dashess = TRUE;
      break;
    case 'v':
      dashvee = TRUE;
      break;
    case 'x':
      dashex = TRUE;
      break;
    case '?':
      exit(1);
    }
  }

quitopts:
  argv += rc_optind;
  // Use isatty() iff neither -i nor -I is set, and iff the input is not from 
  // a script or -c flags.
  if (dasheye == FALSE && dashEYE == FALSE && dashsee[0] == NULL && 
      (dashess != FALSE || *argv == NULL)) {
    interactive = isatty(0);
  }
  
  if (dashoh == FALSE) {
    checkfd(0, rFrom);
    checkfd(1, rCreate);
    checkfd(2, rCreate);
  }

  initsignal();
  inithash();
  initparse();
  initdefaults();
  initenv(envp);
  initinput();
  null[0] = NULL;
  // Assign $0 to $*.
  variable_star_assign(dollarzero, null, FALSE); 
  inithandler();
  
  if (dashsee[0] != NULL || dashess != FALSE) {
    // Input from  -c or -s?.
    if (*argv != NULL) {
      variable_star_assign(dollarzero, argv, FALSE);
    }
    if (dashess != FALSE) {
      pushfd(0);
    } else {
      pushstring(dashsee, TRUE);
    }
  } else if (*argv != NULL) {
    // Input from from a file?
    builtin_dot(--argv);
    rc_exit(getstatus());
  } else {
    // Input from stdin.
    pushfd(0);
  }

  dasheye = FALSE;
  rc_loop(TRUE);
  rc_exit(getstatus());
  // Never really reached.
  return 0;
}

