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

static void cleanup()
{
    printf("Cleaning up.\n");
}

void he3_err(int errno)
{
    if (errno < 0) {
        /* Uses ANSI escape sequence to color error message. */
        printf(RED "FATAL ERROR: %d" RESET "\n", errno);
        cleanup();
        exit(errno);
    } else {
        printf(RED "RECOVERABLE ERROR: %d BECAME FATAL. "
               "This is likely a bug." RESET "\n", errno);
        cleanup();
        exit(errno);
    }
}

static int parse_args(int argc, char **argv, he3UserCommand *command)
{
    if (argc = 1) {
        run_tui();
    }

    return 0;
}

static void he3_export()
{
    printf("Exporting.\n");
}

static int he3_run_analysis(he3Dataset data)
{
    char should_export = 0;

    if (should_export) {
        he3_export();
    }

    return 0;
}

static int he3_coalesce_data(he3UserCommand command, he3Dataset *dataset)
{
    printf("Coalescing data.\n");

    return 1;
}

int he3_startup(he3SystemInfo *sysInfo)
{
    // Check system info.
    return 0;
}

int he3_run_app(int argc, char **argv, he3SystemInfo sysInfo)
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
