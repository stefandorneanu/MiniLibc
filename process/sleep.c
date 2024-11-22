#include <unistd.h>
#include <internal/syscall.h>
#include <internal/io.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec duration, rem;
    duration.tv_sec = seconds;
    duration.tv_nsec = 0;
    if (nanosleep(&duration, &rem) == -1)
        return rem.tv_sec;

    return 0;
}
