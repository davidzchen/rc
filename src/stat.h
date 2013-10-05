#ifndef SRC_STAT_H__
#define SRC_STAT_H__

#include <sys/stat.h>

#if HAVE_LSTAT
#else
#define lstat(name, buf) (stat((name), (buf)))
#endif

#endif /* SRC_STAT_H__ */
