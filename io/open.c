// SPDX-License-Identifier: BSD-1-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	// open function
	mode_t mode = 0;

	if (filename == NULL)
	{
		errno = EFAULT;
		return -1;
	}
	int file_descriptor;

	if (flags & O_CREAT)
	{
		va_list arg_lsit;
		va_start(arg_lsit, flags);
		mode = va_arg(arg_lsit, mode_t);
		va_end(arg_lsit);
		file_descriptor = syscall(__NR_open, filename, flags, mode);
	} else {
		file_descriptor = syscall(__NR_open, filename, flags);
	}

	if (file_descriptor < 0)
	{
		errno = -file_descriptor;
		return -1;
	}

	return file_descriptor;
}
