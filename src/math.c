#include "math.h"

#include <gsl/gsl_fit.h>
#include <gsl/gsl_multifit_nlinear.h>

int fit(void)
{
    double c0, c1, cov00, cov01, cov11, shisq;
    gsl_fit_wlinear(x, 1, w, 1, y, 
                    1, n, &c0, &c1, &cov00, &cov01, &cov11, &chisq);
    printf("FIT: y = %gx + %g\n", c1, c0;


