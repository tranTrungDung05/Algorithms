bool checkIfExist(int* arr, int arrSize) {
    for(int i = 0; i < arrSize; i ++){
        for(int j = arrSize - 1; j >= 0; j--){
            if(i != j && arr[i] == 2 * arr[j]){
                return true;
            }
        }
    }
    return false;
}