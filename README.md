This is release rc-1.7.1.

See COPYING for copying information.  All files are

   Copyright 1991, 2001, 2002, 2003 Byron Rakitzis.

See INSTALL for build and installation information.

[![Build Status](https://travis-ci.org/davidzchen/rc.png?branch=master)](https://travis-ci.org/davidzchen/rc)

BUGS

Send bug reports to <tjg@star.le.ac.uk>.  If a core dump is generated,
sending a backtrace will help a great deal.  You can get a backtrace
like this.

	; gdb rc core
	(gdb) where
	<<<BACKTRACE INFO>>>
	(gdb)

Also, always report the machine, OS (`uname -a'), and compiler used to
make rc; this information is extremely valuable.


FEEPING CREATURISM

See the end of the man page, under "INCOMPATIBILITIES" for (known?)
differences from the "real" rc.  Most of these changes were necessary
to get rc to work in a reasonable fashion on a real (i.e. commercial,
non-Labs) Unix system; a few were changes motivated by concern about
some inadequacies in the original design.


WWW

More information on releases of rc can be found at this web page.

    http://www.star.le.ac.uk/~tjg/rc/
