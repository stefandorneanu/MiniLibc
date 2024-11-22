// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement stat(). */
	if (fd < 0)
	{
		errno = EBADF;
		return -1;
	}

	int how_are_you = syscall(__NR_fstat, fd, st);
	if (how_are_you < 0)
	{
		errno = -how_are_you;
		return -1;
	}
	return 0;
}
