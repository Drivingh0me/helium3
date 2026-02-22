#include "helium3.h"

int main(int argc, char **argv)
{
    int status = -1;

    status = he3_startup();
    if (status) {
        he3_err(status);
    }

    status = he3_run_app(argc, argv);
    if (status) {
        he3_err(status);
    }

    status = he3_shutdown();
    if (status) {
        he3_err(status);
    }

    return 0;
}
