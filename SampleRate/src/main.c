#include "dsp.c"

int main(){
    float X[4] = {1,2,3,4};
    float H[2] = {3,4};
    float Y[5];

    //Convolute with impulse signal
    Con(
        //Signal Input
        X,
        //Signal Size
        4,
        //Impluse Input
        H,
        //Impulse Size
        2,
        //Output
        Y
        );


    //Print its values as coordinate points
    print(
          //Input Array
          Y, 
          //Number of Points
          5
        );

    return 0;
}