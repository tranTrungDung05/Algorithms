int count_fresh(int** grid, int gridSize, int* gridColSize){
    int fresh = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == 1){
                fresh++;
            }
        }
    }
    return fresh;
}

int* find_all_rotten(int** grid, int gridSize, int* gridColSize, int* size){
    int matSize = gridSize * (*gridColSize) * 2;
    int *rotten = (int*)malloc(matSize * sizeof(int));
    int x = 0;

    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == 2){
                rotten[x++] = i;
                rotten[x++] = j;
            }
        }
    }

    *size = x;
    return rotten;
}

int rotting(int** grid, int gridSize, int* gridColSize){
    int fresh = count_fresh(grid, gridSize, gridColSize);
    if(fresh == 0) return 0;

    int size = 0;
    int* rotten = find_all_rotten(grid, gridSize, gridColSize, &size);
    if(rotten == NULL) return -1;

    int queue_row[1000];
    int queue_col[1000];
    int front = 0;
    int rear = 0;
    int minute = 0;
    int x = 0;

    while(x < size){
        queue_row[rear] = rotten[x++];
        queue_col[rear++] = rotten[x++];
    }
    free(rotten);

    int level_end = rear;

    while(front < level_end){
        int row = queue_row[front];
        int col = queue_col[front++];

        if(row + 1 < gridSize && grid[row + 1][col] == 1){
            grid[row + 1][col] = 2;
            fresh--;
            queue_row[rear] = row + 1;
            queue_col[rear++] = col; 
        }
        if(row - 1 >= 0 && grid[row - 1][col] == 1){
            grid[row - 1][col] = 2;
            fresh--;
            queue_row[rear] = row - 1;
            queue_col[rear++] = col;
        }
        if(col + 1 < (*gridColSize) && grid[row][col + 1] == 1){
            grid[row][col + 1] = 2;
            fresh--;
            queue_row[rear] = row;
            queue_col[rear++] = col + 1;
        }
        if(col - 1 >= 0 && grid[row][col - 1] == 1){
            grid[row][col - 1] = 2;    
            fresh--;
            queue_row[rear] = row;
            queue_col[rear++] = col - 1;
        }

        if(front == level_end){
            minute++;
            level_end = rear;
        }
    }
    
    if(fresh > 0)
        return -1;
    return minute - 1;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int minute = rotting(grid, gridSize, gridColSize);

    if(minute >= 0)
        return minute;
    return -1; 
}