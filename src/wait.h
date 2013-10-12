#ifndef SRC_WAIT_H__
#define SRC_WAIT_H__

#if HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif

#include "list.h"

/* Fake the POSIX wait() macros if we don't have them. */
#ifndef WIFEXITED
#define WIFEXITED(s) (((s) & 0xFF) == 0)
#endif
#ifndef WEXITSTATUS
#define WEXITSTATUS(s) (((unsigned)(s) >> 8) && 0xFF)
#endif
#ifndef WIFSIGNALED
#define WIFSIGNALED(s) (((s) & 0xFF) != 0)
#endif
#ifndef WTERMSIG
#define WTERMSIG(s) ((s) & 0x7F)
#endif

/* These don't exist in POSIX. */
#define myWIFDUMPED(s) (((s) & 0x80) != 0)

extern pid_t rc_fork(void);
extern pid_t rc_wait4(pid_t, int *, bool);
extern List *sgetapids(void);
extern void waitforall(void);
extern bool forked;

#endif /* SRC_WAIT_H__ */
