#ifndef SRC_SYSTEM_H__
#define SRC_SYSTEM_H__

extern void writeall(int, char *, size_t);

#if HAVE_RESTARTABLE_SYSCALLS
extern int rc_read(int, char *, size_t);
extern pid_t rc_wait(int *);
extern Jbwrap slowbuf;
extern volatile sig_atomic_t slow;

#else /* HAVE_RESTARTABLE_SYSCALLS */

#define rc_read read
#define rc_wait wait
#endif /* HAVE_RESTARTABLE_SYSCALLS */

#endif /* SRC_SYSTEM_H__ */
