#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

long long solve_linear(int* slices, int n, int len) {
    long long** dp = (long long**)malloc((n + 1) * sizeof(long long*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (long long*)calloc((len + 1), sizeof(long long));
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= len; j++) {
            long long skip = dp[i][j - 1];
            
            long long take = slices[j - 1];
            if (j >= 2) {
                take += dp[i - 1][j - 2];
            } else if (i == 1) {
                take = slices[j - 1];
            } else {
                take = 0;
            }
            
            dp[i][j] = MAX(skip, take);
        }
    }
    
    long long result = dp[n][len];
    
    for (int i = 0; i <= n; i++) free(dp[i]);
    free(dp);
    
    return result;
}

int maxSizeSlices(int* slices, int slicesSize) {
    int n = slicesSize / 3;

    long long res1 = solve_linear(slices, n, slicesSize - 1);
    long long res2 = solve_linear(slices + 1, n, slicesSize - 1);

    return (int)MAX(res1, res2);
}