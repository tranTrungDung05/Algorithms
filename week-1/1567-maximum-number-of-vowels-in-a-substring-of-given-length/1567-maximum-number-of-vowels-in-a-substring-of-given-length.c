bool isVowel(char a){
    if(a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o'){
        return true;
    }
    return false;
}

int maxVowels(char* s, int k) {
    int count = 0;
    for(int i = 0; i < k; i++){
        if(isVowel(s[i]))
            count++;
    }

    int max = count;

    for(int r = k; s[r] != '\0'; r++){
        if(isVowel(s[r]))
            count++;
        if(isVowel(s[r-k]))
            count--;
        if(max < count)
            max = count;
    }
    return max;
}

