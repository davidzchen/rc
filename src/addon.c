/*
   This file is NOT BUILT by default.  Together with addon.h, it
   provides an example of how to add new builtins to rc.
*/

#include "common.h"
#include "addon.h"

void builtin_sum(char **av) {
	long sum = 0;

	while (*++av)
		sum += atol(*av);
	fprint(1, "%ld\n", sum);
	set(TRUE);
}

void builtin_prod(char **av) {
	long sum = 1;

	while (*++av)
		sum *= atol(*av);
	fprint(1, "%ld\n", sum);
	set(TRUE);
}
