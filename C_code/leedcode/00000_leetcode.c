#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>


int minPathSum(int** grid, int gridSize, int* gridColSize);

void main()
{
    return; 
}
void display(char**grid,int NUMBER_OF_ROWS,int NUMBER_OF_COLS)
{
    int i, j;
    for(i=0;i<NUMBER_OF_ROWS;i++)
    {
        for(j=0;j<NUMBER_OF_COLS;j++)
        {
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }
    return; 
}
/*00064
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
*/
int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    //11110
    //01010
    //10001
    //11110
    int NUMBER_OF_ROWS = gridSize;  //4
    int NUMBER_OF_COLS = gridColSize[0];  //5

}
