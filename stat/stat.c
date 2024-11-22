// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	if (path == NULL)
	{
		errno = ENOENT;
		return -1;
	}

	int how_are_you = syscall(__NR_stat, path, buf);
	if (how_are_you < 0)
	{
		errno = -how_are_you;
		return -1;
	}
	return 0;
}
