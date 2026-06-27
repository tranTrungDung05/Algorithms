bool isPerfectSquare(int num) {
    if(num == 1) 
        return true;
    else if(num == 0) 
        return false;

    for(long long i = 2; i < num; i++){
        if(i * i == num){
            printf("%d", i);
            return true;
        }
    }
    return false;
}