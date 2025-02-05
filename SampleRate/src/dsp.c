#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "basic.c"

#define SAMP_RATE 48000
#define IMPULSE 5
#define STEP (1.0 / SAMP_RATE)
#define SAMP_COUNT 48

/////////////////////
//Basic Operations//
////////////////////

//Adds the samples in array A and array B (or vice versa) and places each sample in array C
void add(float* A, int A_size, float* B, int B_size, float *C){
       //The number of samples of the output matches whichever input has more samples
        int C_size = (A_size > B_size) ? A_size : B_size;
        int last_index = ((A_size < B_size) ? A_size : B_size) - 1;

        for(int i = 0; i < C_size; i++){
            
            //Begin duplicating samples once all unique terms have been combined
            if ((i > last_index) && (C_size == A_size)) {
                C[i] = A[i];
                continue;
            }

            if((i > last_index) && (C_size == B_size)) {
                C[i] = B[i];
                continue;
            }

            C[i] = A[i] + B[i];
        }
}

//Subtracts the samples of array B from array A and places each sample in array C
void subtract(float* A, int A_size, float* B, int B_size, float *C){
       //The number of samples of the output matches whichever input has more samples
        int C_size = (A_size > B_size) ? A_size : B_size;
        int last_index = ((A_size < B_size) ? A_size : B_size) - 1;

        for(int i = 0; i < C_size; i++){
            
            //Begin duplicating samples once all unique terms have been combined
            if ((i > last_index) && (C_size == A_size)) {
                C[i] = A[i];
                continue;
            }

            if((i > last_index) && (C_size == B_size)) {
                C[i] = B[i];
                continue;
            }

            C[i] = A[i] - B[i];
        }
}

//Multiplies the samples of array A by array B and places each sample in array C
void multiply(float* A, int A_size, float* B, int B_size, float *C){
       //The number of samples of the output matches whichever input has more samples
        int C_size = (A_size > B_size) ? A_size : B_size;
        int last_index = ((A_size < B_size) ? A_size : B_size) - 1;

        for(int i = 0; i < C_size; i++){
            
            //Begin duplicating samples once all unique terms have been combined
            if ((i > last_index) && (C_size == A_size)) {
                C[i] = A[i];
                continue;
            }

            if((i > last_index) && (C_size == B_size)) {
                C[i] = B[i];
                continue;
            }

            C[i] = A[i] * B[i];
        }
}

//Multiplies two sample arrays and places each sample in a specified output array
void divide(float* A, int A_size, float* B, int B_size, float *C){
       //The number of samples of the output matches whichever input has more samples
        int C_size = (A_size > B_size) ? A_size : B_size;
        int last_index = ((A_size < B_size) ? A_size : B_size) - 1;

        for(int i = 0; i < C_size; i++){
            
            //Begin duplicating samples once all unique terms have been combined
            if ((i > last_index) && (C_size == A_size)) {
                C[i] = A[i];
                continue;
            }

            if((i > last_index) && (C_size == B_size)) {
                C[i] = B[i];
                continue;
            }

            C[i] = A[i] / B[i];
        }
}

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

void ustereo(uint32_t* mono, int m_size, uint32_t* stereo, int copy){
    int s_size = (m_size * 2);

    if(!copy){
        for(int i = 0; i < s_size; i += 2){
            stereo[i] = mono[(i / 2)];
            stereo[i + 1] = 0;
        }
    } else {
         for(int i = 0; i < s_size; i++){
            stereo[i] = mono[(i / 2)];
        }
    }
}

void stereo(float* mono, int m_size, float* stereo, int copy){
    int s_size = (m_size * 2);

    if(!copy){
        for(int i = 0; i < s_size; i += 2){
            stereo[i] = mono[(i / 2)];
            stereo[i + 1] = 0;
        }
    } else {
         for(int i = 0; i < s_size; i++){
            stereo[i] = mono[(i / 2)];
        }
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
        
        //Shift the decimal point 4 places to retain floating-point precision 
        uArr[i] = temp * 100000;
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

void uCon(uint32_t* x, int x_size, uint32_t* h, int h_size, uint32_t* y) {
   
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