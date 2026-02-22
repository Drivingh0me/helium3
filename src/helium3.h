#ifndef HELIUM3_H
#define HELIUM3_H

void he3_err(int errno);
int he3_startup();
int he3_run_app(int argc, char **argv);
int he3_shutdown();

#endif /* HELIUM3_H */
