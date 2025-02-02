#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "basic.c"

#define SAMP_RATE 48000
#define IMPULSE 5
#define STEP (1.0 / SAMP_RATE)
#define SAMP_COUNT 48

//Generates user specified numbers samples of a sine wave of user specified frequency and fills them into a floating point array
void sine(float* arr, int size, float freq){
    
    float time;

    for(int i = 0; i < size; i++){

        //Time value increments by the sample rate
        time = STEP * i;

        //Calculates each time value based on the cmath sine function
        arr[i] = sin((2 * M_PI * freq) * time);
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
        uArr[i] = temp * 1000;
    }

}

void Con(float* x, int x_size, float* h, int h_size, float* y) {
   
    int y_size = (x_size + h_size) - 1;

    for(int i = 0; i < y_size; i++){

        y[i] = 0;

        for(int j = 0; j < h_size; j++){

            if(((i - j) < 0)) continue;
            if((i - j) > (x_size - 1)) continue;

            y[i] = y[i] + h[j] * x[i - j];

        }
    }
}