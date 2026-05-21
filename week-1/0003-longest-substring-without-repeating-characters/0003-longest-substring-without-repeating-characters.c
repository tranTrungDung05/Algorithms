int lengthOfLongestSubstring(char* s) {
    char freq[128] = {0};
    int l = 0;
    int max = 0;
    for(int r = 0; s[r] != '\0'; r++){
        freq[(int)s[r]]++;

        while(freq[(int)s[r]] > 1){
            freq[s[l]]--;
            l++;
        }
        int temp_max = r - l + 1;
        if(max < temp_max)
            max = temp_max;
    }
    return max;
}