bool isPalindrome(char* s) {
    int len = strlen(s);

    char catch[len + 1];
    int catlen = 0;

    for(int i = 0; i < len; i++){
        if(isalnum((unsigned char)s[i])){
            catch[catlen++] = tolower((unsigned char)s[i]);
        }
    }
    catch[catlen] = '\0';

    for(int i = 0; i < catlen / 2; i++){
        if(catch[i] != catch[catlen - 1 - i])
            return false;
    }
    return true;
}