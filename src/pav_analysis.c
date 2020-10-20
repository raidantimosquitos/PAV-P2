#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    int i = 0;
    float pow = 0;
    for (i = 0; i < N; i++) {
        pow = pow + x[i]*x[i];
    }
    return 10*log10(pow/N);
}

float compute_am(const float *x, unsigned int N) {
    int i  = 0;
    float am = 0;
    for (i = 0; i < N; i++) {
        am = am + fabs(x[i]);
    }   
    return am/N;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    int i = 0;
    float zcr = 0;
    for (i = 1; i < N; i++) {
        if (x[i]*x[i-1] < 0) {
            zcr = zcr + 1;
        }       
    }   
    return (fm/2)*(zcr/(N-1));
}