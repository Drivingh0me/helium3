#include "helium3.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int length;
    int lines;
} he3Data;

typedef struct {
    unsigned int flag_len;
    unsigned int *flags;
} he3Flags;

typedef struct {
    unsigned int file_len;
    FILE **files;
} he3_Files;

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

int parse_args(int argc, char **argv, he3Flags flags, he3Files files)
{
    return 0;
}

int he3_run_analysis(he3Data data)
{
    if (should_export) {
        he3_export();
    }

    return 0:
}

int he3_startup()
{
    // Check system info.
    return 0;
}

int he3_run_app(int argc, char **argv)
{
    int status = -1;
    int *flags = NULL;

    status = parse_args(argc, argv, flags, files);
    if (status) {
        return status;
    }

    status = he3_coalesce_data(flags, files, dataset);
    if (status) {
        return status;
    }

    status = he3_run_analysis(dataset);
    if (status) {
        return status;
    }

    return 0;
}

int he3_shutdown()
{
    cleanup();

    return 0;
}
