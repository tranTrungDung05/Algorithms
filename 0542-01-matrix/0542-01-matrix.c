/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = matSize;
    *returnColumnSizes = (int*)malloc(matSize * sizeof(int*));
    
    int **dist = (int**)malloc(matSize * sizeof(int*));

    for(int i = 0; i < matSize; i++){
        dist[i] = (int*)malloc(matColSize[0] * sizeof(int));
        (*returnColumnSizes)[i] = matColSize[i];
        for(int j = 0; j < matColSize[i]; j++){
                dist[i][j] = 100000;
        }
    }

    int queueRow[10002];
    int queueCol[10002];
    int head = 0;
    int tail = 0;

    for(int i = 0; i < matSize; i++){
        for(int j = 0; j < matColSize[i]; j++){
            if(mat[i][j] == 0){
                dist[i][j] = 0;

                queueRow[tail] = i;
                queueCol[tail] = j;
                tail++;
            }
        }
    }

    int dr[] = {0, 0, -1, 1};
    int dc[] = {-1, 1, 0, 0};

    while(head < tail){
        int currRow = queueRow[head];
        int currCol = queueCol[head];
        head++;

        for(int i = 0; i < 4; i++){
            int newRow = currRow + dr[i];
            int newCol = currCol + dc[i];

            if(newRow < matSize && newRow >= 0 && newCol >= 0 && newCol < matColSize[0]){
                if(dist[newRow][newCol] > dist[currRow][currCol] + 1){
                    dist[newRow][newCol] = dist[currRow][currCol] + 1;

                    queueRow[tail] = newRow;
                    queueCol[tail] = newCol;
                    tail++;
                }
            }
        }
    }
    return dist;
}
