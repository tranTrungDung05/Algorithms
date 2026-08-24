/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int oldColor){
    if(sr < 0 || sr >= imageSize || sc < 0 || sc >= *imageColSize)  return;

    if(image[sr][sc] == color || image[sr][sc] != oldColor) return;

    image[sr][sc] = color;

    dfs(image, imageSize, imageColSize, sr + 1, sc, color, oldColor);
    dfs(image, imageSize, imageColSize, sr - 1, sc, color, oldColor);
    dfs(image, imageSize, imageColSize, sr, sc + 1, color, oldColor);
    dfs(image, imageSize, imageColSize, sr, sc - 1, color, oldColor);

}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    *returnColumnSizes = malloc(sizeof(int) * imageSize);

    int oldColor = image[sr][sc];

    for(int i = 0; i < imageSize; i++){
        (*returnColumnSizes)[i] = *imageColSize;
    }

    dfs(image, imageSize, imageColSize, sr, sc, color, oldColor);

    *returnSize = imageSize;
    for(int i = 0; i < imageSize; i++){
        (*returnColumnSizes)[i] = *imageColSize;
    }

    return image;
}