#include "dsp.c"

int main(){
    uint32_t x[5] = {2,4,6,8,10};
    uint32_t h[3] = {1,3,1};
    uint32_t y[7];
    uCon(x, 5, h, 3, y);

    for(int i = 0; i < 7; i++){
        printf("%u ", y[i]);
    }

    printf("\n");
}