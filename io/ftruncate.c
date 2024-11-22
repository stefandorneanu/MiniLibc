// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	if (fd < 0)
	{
		errno = EBADF;
		return -1;
	}

	if (length < (off_t)0)
	{
		errno = EINVAL;
		return -1;
	}

	int result = syscall(__NR_ftruncate, fd, length);
	if (result < 0)
	{
		errno = -result;
		return -1;
	}
	return result;
}
