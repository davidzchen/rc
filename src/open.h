#ifndef SRC_OPEN_H__
#define SRC_OPEN_H__

extern int rc_open(const char *, redirtype);
extern bool makeblocking(int);
extern bool makesamepgrp(int);

#endif /* SRC_OPEN_H__ */
