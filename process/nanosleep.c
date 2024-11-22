#include <unistd.h>
#include <internal/syscall.h>
#include <internal/io.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *duration, struct timespec *rem)
{
    int zzzz = syscall(__NR_nanosleep, duration, rem);

    if (zzzz < 0)
    {
        errno = -zzzz;
        return -1;
    }

    return 0;
}
