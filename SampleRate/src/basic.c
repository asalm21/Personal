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
