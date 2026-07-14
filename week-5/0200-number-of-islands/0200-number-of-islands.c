void dfs(char** grid, int gridSize, int* gridColSize, int d, int c){
    if (d < 0 || d >= gridSize || c < 0 || c >= gridColSize[d] || grid[d][c] == '0') {
        return;
    }

    grid[d][c] = '0';

    dfs(grid, gridSize, gridColSize, d, c - 1); 
    dfs(grid, gridSize, gridColSize, d, c + 1); 
    dfs(grid, gridSize, gridColSize, d - 1, c); 
    dfs(grid, gridSize, gridColSize, d + 1, c); 
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int islands = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] == '1'){
                islands++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }   
    return islands;
}