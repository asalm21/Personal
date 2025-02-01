#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "basic.c"

#define SAMP_RATE 48000
#define STEP (1.0 / SAMP_RATE)
#define SAMP_COUNT 120

//Generates user specified numbers samples of a sine wave of user specified frequency and fills them into a floating point array
void sine(float* arr, float freq){
    
    float time;

    for(int i = 0; i < SAMP_COUNT; i++){

        //Time value increments by the sample rate
        time = STEP * i;

        //Calculates each time value based on the cmath sine function
        arr[i] = sin((2 * M_PI * freq) * time);
    }
}

//Adds two sample arrays and places each sample in a specified output array
void add(float* A, float* B, float *C, int size){
        for(int i = 0; i < size; i++){
        C[i] = A[i] + B[i];
    }
}

//Prints each time-interleaved floating point sample as a coordinate pair
void print(float* arr, int size){
    
    float time;

    for(int i = 0; i < size; i++){
        time = STEP * i;
        printf("(%f, %f)\n", time, arr[i]);
    }
}

//Prints each time-interleaved unsigned integer sample as a coordinate pair
void uprint(uint32_t* arr, int size){
    float time;

    for(int i = 0; i < size; i++){
        time = STEP * i;
        printf("(%f, %u)\n", time, arr[i]);
    }
}

//Converts floating point samples into unsigned and places the samples in a user-specified unsigned array
void toUnsigned(float* fArr, uint32_t* uArr){
    
    //Get the smallest sample value
    float min = minFloat(fArr, SAMP_COUNT), temp;

    for(int i = 0; i < SAMP_COUNT; i++){
        
        temp = fArr[i];

        //If the smallest sample value is negative, shift all samples by its value
        if(min < 0){
            temp -= min;
        }
        
        //Shift the decimal point 6 places to retain floating-point precision 
        uArr[i] = temp * 1000000;
    }

}

int main(){

    //Create array X of user-specified sample count
    float X[SAMP_COUNT];
    uint32_t uX[SAMP_COUNT];

    //Create 1KHz sine wave
    sine(
        //Input Array 
          X,
         //Frequency
         1000
        );
    
    //Convert floating point array to unsigned
    toUnsigned(
             //Float Input
             X,
             //Unisnged Output
             uX
            );

    //Print its values as coordinate points
    uprint(
          //Input Array
          uX, 
          //Number of Points
          SAMP_COUNT
        );

    return 0;
}