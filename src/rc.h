#ifndef SRC_RC_H__
#define SRC_RC_H__

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

typedef void builtin_t(char **);
typedef struct Block Block;
typedef struct Dup Dup;
typedef struct Estack Estack;
typedef struct rc_Function rc_Function;
typedef struct Hq Hq;
typedef struct Htab Htab;
typedef struct Jbwrap Jbwrap;
typedef struct List List;
typedef struct Node Node;
typedef struct Pipe Pipe;
typedef struct Redir Redir;
typedef struct Rq Rq;
typedef struct Variable Variable;
typedef struct Word Word;
typedef struct Format Format;
typedef union Edata Edata;

typedef enum nodetype {
	nAndalso, nAssign, nBackq, nBang, nBody, nCbody, nNowait, nBrace,
	nConcat, nCount, nElse, nFlat, nDup, nEpilog, nNewfn, nForin, nIf,
	nOrelse, nPipe, nPre, nRedir, nRmfn, nArgs, nSubshell, nCase,
	nSwitch, nMatch, nVar, nVarsub, nWhile, nWord, nLappend, nNmpipe
} nodetype;

typedef enum ecodes {
	eError, eBreak, eReturn, eVarstack, eArena, eFifo, eFd
} ecodes;

typedef enum bool {
	FALSE, TRUE
} bool;

typedef enum inputtype {
	iFd, iString
} inputtype;

typedef enum redirtype {
	rFrom, rCreate, rAppend, rHeredoc, rHerestring
} redirtype;

typedef bool (*Conv)(Format *, int);

union Edata {
	Jbwrap *jb;
	Block *b;
	char *name;
	int fd;
};

struct Estack {
	ecodes e;
	bool interactive;
	Edata data;
	Estack *prev;
};

struct List {
	char *w, *m;
	List *n;
};

struct Node {
	nodetype type;
	union {
		char *s;
		int i;
		Node *p;
	} u[4];
};

struct Pipe {
	int left, right;
};

struct Dup {
	redirtype type;
	int left, right;
};

struct Redir {
	redirtype type;
	int fd;
};

struct Word {
	char *w, *m;
	bool q;
};

struct Rq {
	Node *r;
	struct Rq *n;
};

struct rc_Function {
	Node *def;
	char *extdef;
};

struct Variable {
	List *def;
	char *extdef;
	Variable *n;
};

struct Htab {
	char *name;
	void *p;
};

struct Format {
	/* for the formatting routines */
	va_list args;
	long flags, f1, f2;
	/* for the buffer maintainence routines */
	char *buf, *bufbegin, *bufend;
	int flushed;
	void (*grow)(Format *, size_t);
	union { int n; void *p; } u;
};

/* Format->flags values */
enum {
	FMT_quad	= 1,		/* %q */
	FMT_long	= 2,		/* %l */
	FMT_unsigned	= 8,		/* %u */
	FMT_zeropad	= 16,		/* %0 */
	FMT_leftside	= 32,		/* %- */
	FMT_altform	= 64,		/* %# */
	FMT_f1set	= 128,		/* %<n> */
	FMT_f2set	= 256		/* %.<n> */
};

/* macros */
#define EOF (-1)
#ifndef NULL
#define NULL 0
#endif
#define a2u(x) n2u(x, 10)
#define o2u(x) n2u(x, 8)
#define arraysize(a) ((int)(sizeof(a)/sizeof(*a)))
#define memzero(s, n) memset(s, 0, n)
#define enew(x) ((x *) ealloc(sizeof(x)))
#define ecpy(x) strcpy((char *) ealloc(strlen(x) + 1), x)
#define lookup_fn(s) ((rc_Function *) lookup(s, fp))
#define lookup_var(s) ((Variable *) lookup(s, vp))
#define nnew(x) ((x *) nalloc(sizeof(x)))
#define ncpy(x) (strcpy((char *) nalloc(strlen(x) + 1), x))
#ifndef offsetof
#define offsetof(t, m) ((size_t) (((char *) &((t *) 0)->m) - (char *)0))
#endif
#define streq(x, y) (*(x) == *(y) && strcmp(x, y) == 0)
#define conststrlen(x) (sizeof (x) - 1)

/* rc prototypes */

/* main.c */
extern Rq *redirq;
extern bool dashdee, dashee, dashvee, dashex, dashell,
	dasheye, dashen, dashpee, interactive;
extern pid_t rc_pid;
extern int lineno;

/* parse.c (parse.y) */
extern Node *parsetree;
extern int yyparse(void);
extern void initparse(void);

#endif /* SRC_RC_H__ */
