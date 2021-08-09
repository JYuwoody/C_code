#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*733. Flood Fill
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], newColor < 216
0 <= sr < m
0 <= sc < n
*/

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes);

void main()
{
    printf("woody\n");

    return; 
}

struct Towmtrust
{
    int trust;
    int trusted;
};



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void rFloodFill(int** result, int row, int col, int targetvalue, int nRows, int nCols)
{
    if(row < 0 || col < 0 || row >= nRows || col >= nCols ) return;

    if(result[row][col] != targetvalue) return;

    result[row][col] = -1;

    rFloodFill(result, row-1, col, targetvalue, nRows, nCols);
    rFloodFill(result, row+1, col, targetvalue, nRows, nCols);
    rFloodFill(result, row, col-1, targetvalue, nRows, nCols);
    rFloodFill(result, row, col+1, targetvalue, nRows, nCols);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes)
{
    // image = {[1,1,1,0],
    //          [1,1,0,1],
    //          [1,0,1,0]}
    // imageSize = 3 == *returnSize
    // imageColSize : [4, 4, 4] == (** returnColumnSizes)
    // sr: 1 sc: 2 newnewColor = 2 >> old_image[1][2]=1 to new_image[1][2] = 2 than (1,2) is center near this center and same center old value change to new_image value.

    int nRows = imageSize;
    int nCols = imageColSize[0];
    int row = 0, col = 0;
    int** result = malloc(sizeof(int*)*nRows);
    int targetvalue = 0;
    
    for(row=0;row<nRows;row++)
    {
        result[row] = malloc(sizeof(int)*nCols);
    }

    for(row=0;row<nRows;row++)
    {
        for(col=0;col<nCols;col++)
        {
            result[row][col] = image[row][col];
        }
    }
    targetvalue = result[sr][sc];
    rFloodFill(result, sr, sc, targetvalue, nRows, nCols);

    for(row=0;row<nRows;row++)
    {
        for(col=0;col<nCols;col++)
        {
            if(-1 == result[row][col])
                result[row][col] = newColor;
        }
    }

    *returnSize = imageSize;
    *returnColumnSizes = malloc(sizeof(int)*nRows);
    for(row=0;row<nRows;row++)
    {
        (*returnColumnSizes)[row] = nCols;
    }
    return result;
}
