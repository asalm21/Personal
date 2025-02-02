//Returns the minimum value in a floating point array
float minFloat(float* arr, int size){
    float min = arr[0];

    for(int i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }  

    return min;
}

//Fills array with ones
void floatOnes(float* arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = 1;
    }
}

//Fills array with zeroes
void floatZeros(float* arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = 0;
    }
}

//Adds two sample arrays and places each sample in a specified output array
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

void mul(float* A, int A_size, float* B, int B_size, float *C){
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