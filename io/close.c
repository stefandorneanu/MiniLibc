// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	if (fd < 0)
	{
		errno = EBADF;
		return -1;
	}
	int closed_fd = syscall(__NR_close, fd);
	if (closed_fd == -1)
		return -1;
	return closed_fd;
}
