// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (start == MAP_FAILED)
		return NULL;

	mem_list_add(start, size);
	return start;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (start == MAP_FAILED)
		return NULL;

	mem_list_add(start, size * nmemb);
	memset(start, 0, size * nmemb);
	return start;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL)
		return;
	struct mem_list *curr_poz = mem_list_find(ptr);

	if (curr_poz == NULL)
		return;

	int del_mem = munmap(curr_poz->start, curr_poz->len);

	if (del_mem < 0)
		return;

	mem_list_del(curr_poz->start);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL)
		return NULL;

	if (size == 0)
	{
		free(ptr);
		return NULL;
	}

	struct mem_list *curr_poz = mem_list_find(ptr);

	if (curr_poz == NULL)
		return NULL;

	void *modified_alloc = mremap(ptr, curr_poz->len, size, 0);

	if (modified_alloc == MAP_FAILED)
		return NULL;

	mem_list_del(ptr);

	mem_list_add(modified_alloc, size);

	return modified_alloc;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (ptr == NULL)
		return NULL;
	if (size == 0)
	{
		free(ptr);
		return NULL;
	}

	struct mem_list *item = mem_list_find(ptr);
	if (item == NULL)
		return NULL;

	size_t len = nmemb * size;

	void *start = mremap(ptr, item->len, len, MREMAP_MAYMOVE);

	if (start == MAP_FAILED)
		return NULL;

	mem_list_del(ptr);

	return start;
}
