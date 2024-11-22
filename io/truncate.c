// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	if (path == NULL)
	{
		errno = EFAULT;
		return -1;
	}
	if (length < 0)
	{
		errno = EINVAL;
		return -1;
	}
	// if (access(path, 0) == -1)
	// 	return -1;
	int shrunked = syscall(__NR_truncate, path, length);
	if (shrunked < 0)
	{
		errno = -shrunked;
		return -1;
	}
	return 0;
}
