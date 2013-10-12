#ifndef SRC_COMMON_H__
#define SRC_COMMON_H__

#undef NDEBUG
#include "config.h"
#include "proto.h"

#include <assert.h>

/* datatypes */

#define ENV_SEP '\001'
#define ENV_ESC '\002'

/* braindamaged IBM header files #define true and false */
#undef FALSE
#undef TRUE

typedef enum bool {
	FALSE, TRUE
} bool;

/* macros */
#define EOF (-1)

#ifndef NULL
# define NULL 0
#endif

#define a2u(x) n2u(x, 10)
#define o2u(x) n2u(x, 8)
#define arraysize(a) ((int)(sizeof(a)/sizeof(*a)))
#define memzero(s, n) memset(s, 0, n)
#define enew(x) ((x *) ealloc(sizeof(x)))
#define ecpy(x) strcpy((char *) ealloc(strlen(x) + 1), x)
#define nnew(x) ((x *) nalloc(sizeof(x)))
#define ncpy(x) (strcpy((char *) nalloc(strlen(x) + 1), x))

#ifndef offsetof
# define offsetof(t, m) ((size_t) (((char *) &((t *) 0)->m) - (char *)0))
#endif

#define streq(x, y) (*(x) == *(y) && strcmp(x, y) == 0)
#define conststrlen(x) (sizeof (x) - 1)

/* main.c */
extern bool dashdee;
extern bool dashee;
extern bool dashvee;
extern bool dashex;
extern bool dashell;
extern bool dasheye;
extern bool dashen;
extern bool dashpee;
extern bool interactive;
extern pid_t rc_pid;
extern int lineno;

#endif /* SRC_COMMON_H__ */
