char findTheDifference(char* s, char* t) {
    int freq[26] = {0};

    for(int i = 0; s[i] != '\0'; i++){
        freq[s[i] - 'a']++;
    }

    for(int i = 0; t[i] != '\0'; i++){
        freq[t[i] - 'a']--;
        if(freq[t[i] - 'a'] < 0)
            return t[i];
    }
    return '\0';
}