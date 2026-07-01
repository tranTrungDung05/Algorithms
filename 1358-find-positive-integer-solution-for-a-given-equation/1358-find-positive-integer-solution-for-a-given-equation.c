/*
 * // This is the definition for customFunction API.
 * // You should not implement it, or speculate about its implementation
 *
 * // Returns f(x, y) for any given positive integers x and y.
 * // Note that f(x, y) is increasing with respect to both x and y.
 * // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findSolution(int (*customFunction)(int, int), int z, int* returnSize, int** returnColumnSizes) {
    int **list = NULL;
    int count = 0;

    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));

	for(int x = 1; x <= 1000; x++){
        for(int y = 1; y <= 1000; y++){
            if(customFunction(x, y) == z){
                int *ans = (int*)malloc(2 * sizeof(int));
                ans[0] = x;
                ans[1] = y;

                list = (int**)realloc(list, (count + 1) * sizeof(int*));
                list[count] = ans;

                (*returnColumnSizes)[count] = 2;
                count++;
            }
        }
    }

    *returnSize = count;
    return list;
}