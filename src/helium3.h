#ifndef HELIUM3_H
#define HELIUM3_H

typedef struct {
    int termWidth;
    char liteRun;
} he3SystemInfo;

void he3_err(int errno);
int he3_startup(he3SystemInfo *sysInfo);
int he3_run_app(int argc, char **argv, he3SystemInfo sysInfo);
int he3_shutdown();

#endif /* HELIUM3_H */
