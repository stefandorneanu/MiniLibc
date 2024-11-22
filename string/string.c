// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	while (*source && len)
	{
		*destination = *source;
		destination++;
		source++;
		--len;
	}
	while (len)
	{
		*destination = '\0';
		++destination;
		--len;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	while (*destination)
		++destination;
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	while (*destination)
		++destination;
	while (*source && len)
	{
		*destination = *source;
		destination++;
		source++;
		--len;
	}
	*destination = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (unsigned char)(*str1) - (unsigned char)(*str2);
		str1++;
		str2++;
	}
	return (unsigned char)(*str1) - (unsigned char)(*str2);
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (len)
	{
		if (*str1 == '\0' || *str2 == '\0')
			return (unsigned char)(*str1) - (unsigned char)(*str2);

		if (*str1 != *str2)
			return (unsigned char)(*str1) - (unsigned char)(*str2);
		str1++;
		str2++;
		--len;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	if ((char)c == '\0')
		return (char *)str;
	while (*str)
	{
		if (*str == (char)c)
			return (char *)str;

		++str;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	if ((char)c == '\0')
		return (char *)str;
	const char *ptr = NULL;
	while (*str)
	{
		if (*str == (char)c)
			ptr = str;
		++str;
	}
	return (char *)ptr;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (*needle == '\0')
		return (char *)haystack;

	while (*haystack)
	{
		const char *needle_dup = needle;
		const char *haystack_dup = haystack;
		while (*haystack_dup && *needle_dup && (*needle_dup == *haystack_dup))
		{
			++haystack_dup;
			++needle_dup;
		}

		if (*needle_dup == '\0')
			return (char *)haystack;
		++haystack;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *ptr = NULL;
	if (*needle == '\0')
		return (char *)haystack;

	while (*haystack)
	{
		const char *needle_dup = needle;
		const char *haystack_dup = haystack;
		while (*haystack_dup && *needle_dup && (*needle_dup == *haystack_dup))
		{
			++haystack_dup;
			++needle_dup;
		}

		if (*needle_dup == '\0')
			ptr = (char *)haystack;
		++haystack;
	}
	return ptr;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */

	unsigned char *dest_cpy = (unsigned char *)destination;
	const unsigned char *src_cpy = (const unsigned char *)source;
	while (num--)
	{
		*dest_cpy = *src_cpy;
		++dest_cpy;
		++src_cpy;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	unsigned char *dest_cpy = (unsigned char *)destination;
	const unsigned char *src_cpy = (const unsigned char *)source;
	if (dest_cpy < src_cpy || dest_cpy >= src_cpy + num)
	{
		while (num--)
		{
			*dest_cpy = *src_cpy;
			++dest_cpy;
			++src_cpy;
		}
	} else if (dest_cpy > src_cpy) {
		dest_cpy += num;
		src_cpy += num;
		while (num--)
		{
			--dest_cpy;
			--src_cpy;
			*dest_cpy = *src_cpy;
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *cop1 = (const unsigned char *)ptr1;
	const unsigned char *cop2 = (const unsigned char *)ptr2;
	while (num--)
	{
		if (*cop1 < *cop2)
			return -1;
		if (*cop1 > *cop2)
			return 1;
		++cop1;
		++cop2;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *src_cpy = (unsigned char *)source;

	while (num--)
	{
		*src_cpy = (unsigned char)value;
		++src_cpy;
	}
	return source;
}
