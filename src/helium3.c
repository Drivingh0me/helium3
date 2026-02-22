#include helium3.h

typedef struct {
    int length;
    int lines;
} data;

void cleanup()
{
    free(McEverything);
}

void he3_err(int errno)
{
    /* Uses ANSI escape sequence to color error message. */
    printf("\033[31mFATAL ERROR: \033[0m&d\n", errno);
    cleanup();

    exit(errno);
}

int he3_run_analysis(he3Data data)
{
    return 0:
}

int he3_startup()
{
    // Check system info.
}

int he3_run_app(argc, argv)
{
    int status = -1;

    status = parse_args(argc, argv, flags, files);
    if (status) {
        return status;
    }

    return 0;
}

int he3_shutdown()
{
    cleanup();
}
