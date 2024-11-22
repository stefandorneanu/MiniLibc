struct timespec
{
    long tv_sec;  // Seconds
    long tv_nsec; // Nanoseconds
};

int nanosleep(const struct timespec *duration, struct timespec *rem);
