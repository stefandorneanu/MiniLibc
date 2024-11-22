#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <string.h>

int puts(const char *str)
{
    if (write(1, str, strlen(str)) == -1 || write(1, "\n", 1) == -1)
        return -1;
    return 1;
}
