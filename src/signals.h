#ifndef SRC_SIGNAL_H__
#define SRC_SIGNAL_H__

extern void initsignal(void);
extern void catcher(int);
extern void sigchk(void);
extern void (*rc_signal(int, void (*)(int)))(int);
extern void (*sighandlers[])(int);


#endif /* SRC_SIGNAL_H__ */
