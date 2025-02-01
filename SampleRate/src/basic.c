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