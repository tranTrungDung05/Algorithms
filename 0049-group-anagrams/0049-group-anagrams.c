/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct basket{
    char basketId[26]; 
    char **wordCard; 
    int wordCount;
} basket;

char* compare_to_alphabet(char *hash, char *wordCard){
    for(int i = 0; wordCard[i] != '\0'; i++){ 
        hash[wordCard[i] - 'a']++;
    }
    return hash;
}

bool comp_2_hash(char *hash1, char *hash2){
    for(int i = 0; i < 26; i++){ 
        if(hash1[i] != hash2[i]){
            return false;
        }
    }
    return true;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    basket *baskets = malloc(strsSize * sizeof(basket)); 
    int basketCount = 0;
    bool find_match = 0;

    for(int i = 0; i < strsSize; i++){
        char hash[26] = {0};
        compare_to_alphabet(hash, strs[i]); 
        
        for(int j = 0; j < basketCount; j++){
            if(comp_2_hash(baskets[j].basketId, hash)){
                int count = baskets[j].wordCount;
                baskets[j].wordCard = realloc(baskets[j].wordCard, (count + 1) * sizeof(char*));
                
                baskets[j].wordCard[count] = strs[i];
                baskets[j].wordCount++;
                find_match = 1;
                break; 
            }
        }
        
        if(!find_match){
            for(int n = 0; n < 26; n++){
                baskets[basketCount].basketId[n] = hash[n];
            }
            baskets[basketCount].wordCard = malloc(1 * sizeof(char*));
            baskets[basketCount].wordCard[0] = strs[i];
            baskets[basketCount].wordCount = 1; 
            basketCount++;
        }
        find_match = 0;
    }

    *returnSize = basketCount;
    *returnColumnSizes = malloc(basketCount * sizeof(int));
    char ***return_arr = malloc(basketCount * sizeof(char**));

    for(int i = 0; i < basketCount; i++) {
        (*returnColumnSizes)[i] = baskets[i].wordCount;
        return_arr[i] = baskets[i].wordCard;
    }

    free(baskets); 
    return return_arr;
}