#include "dsp.c"

int main(){
    float X[SAMP_COUNT];
    cosine(X, SAMP_COUNT, 1, 1000, -.00025);

    float Y[SAMP_COUNT];
    sine(Y, SAMP_COUNT, 1, 1000, 0);

    float Z[SAMP_COUNT];
    subtract(X, SAMP_COUNT, Y, SAMP_COUNT, Z);
    print(Z, SAMP_COUNT);
}