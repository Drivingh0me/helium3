#include "helium3.h"

#include "math.h"
#include "outFiles.h"
#include "tui.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int length;
    int lines;
    double *data;
} he3Data;

typedef struct {
    int length;
    int lines;
    float *data;
} he3DataLite;

typedef struct {
    int sets;
    he3Data *data_arr;
} he3Dataset;

typedef struct {
    int sets;
    he3DataLite data_arr;
} he3DatasetLite;

typedef struct {
    char *flag_info; /* flag, files index, number of files */
    unsigned short flag_len;
    unsigned char *flags;
    unsigned int files_len;
    FILE **files;
} he3UserCommand;

void cleanup()
{
    printf("Cleaning up.\n");
}

void he3_err(int errno)
{
    if (errno < 0) {
        /* Uses ANSI escape sequence to color error message. */
        printf("\033[31mFATAL ERROR: %d\033[0m\n", errno);
        cleanup();
        exit(errno);
    } else {
        printf("\033[31mRECOVERABLE ERROR: %d BECAME FATAL. "
               "This is likely a bug.\033[0m\n", errno);
        cleanup();
        exit(errno);
    }
}

int parse_args(int argc, char **argv, he3UserCommand *command)
{
    return 0;
}

void he3_export()
{
    printf("Exporting.\n");
}

int he3_run_analysis(he3Dataset data)
{
    char should_export = 0;

    if (should_export) {
        he3_export();
    }

    return 0;
}

int he3_coalesce_data(he3UserCommand command, he3Dataset *dataset)
{
    printf("Coalescing data.\n");

    return 0;
}

int he3_startup()
{
    // Check system info.
    return 0;
}

int he3_run_app(int argc, char **argv)
{
    int status = -1;
    he3UserCommand userCommand;
    he3Dataset dataset;

    status = parse_args(argc, argv, &userCommand);
    if (status) {
        return status;
    }

    status = he3_coalesce_data(userCommand, &dataset);
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
