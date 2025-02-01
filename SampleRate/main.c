#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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



void add(float* A, float* B, float *C, int size){
    float time;
        for(int i = 0; i < size; i++){
        time = STEP * i;
        C[i] = A[i] + B[i];
    }
}

void print(float* arr, int size){
    float time;

    for(int i = 0; i < size; i++){
        time = STEP * i;
        printf("(%f, %f)\n", time, arr[i]);
    }
}

int main(){

    //Create array X of user-specified sample count
    float X[SAMP_COUNT];
    
    //Create 1KHz sine wave
    sine(
        //Input Array 
          X,
         //Frequency
         1000
        );
    
    //Print its values as coordinate points
    print(
          //Input Array
          X, 
          //Number of Points
          SAMP_COUNT
        );

    return 0;
}