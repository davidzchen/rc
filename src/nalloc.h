#ifndef SRC_ALLOC_H__
#define SRC_ALLOC_H__

extern void *ealloc(size_t);
extern void *erealloc(void *, size_t);
extern void efree(void *);
extern Block *newblock(void);
extern void *nalloc(size_t);
extern void nfree(void);
extern void restoreblock(Block *);

#endif /* SRC_ALLOC_H__ */
