int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    int col = gridColSize[0];

    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == 1){
                if(i == 0 || grid[i - 1][j] == 0) count++;  
                if(i == gridSize - 1 || grid[i + 1][j] == 0) count++;
                if(j == col - 1 || grid[i][j + 1] == 0) count++;
                if(j == 0 || grid[i][j - 1] == 0) count++;
            }
        }
    }
    return count;
}