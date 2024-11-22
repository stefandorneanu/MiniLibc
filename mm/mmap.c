// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long mapped_area = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

	if (mapped_area < 0)
	{
		errno = -mapped_area;
		return MAP_FAILED;
	}

	return (void *)mapped_area;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long modified_map = syscall(__NR_mremap, old_address, old_size, new_size, flags);

	if (modified_map < 0)
	{
		errno = -modified_map;
		return MAP_FAILED;
	}

	return (void *)modified_map;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	long deleted_map = syscall(__NR_munmap, addr, length);

	if (deleted_map < 0)
	{
		errno = deleted_map;
		return -1;
	}
	return 0;
}
