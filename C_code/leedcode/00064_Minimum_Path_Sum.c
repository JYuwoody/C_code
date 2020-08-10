#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

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
            printf("%d ",grid[i][j]);
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
    int x, y;

    if(NUMBER_OF_ROWS == 0)
        return;
    
    for(y=0;y<NUMBER_OF_ROWS;y++)
    {
        for(x=0;x<NUMBER_OF_COLS;x++)
        {
            if(y == 0 && x == 0)
                continue;
            if(y == 0)
                grid[y][x] += grid[y][x-1]; 
            else if(x==0)
                grid[y][x] += grid[y-1][x];
            else
            {
                if(grid[y][x-1]<grid[y-1][x])
                    grid[y][x] += grid[y][x-1];
                else
                    grid[y][x] += grid[y-1][x];
            } 
        }
    }

    return  grid[y-1][x-1];
}

/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                if (i == 0) 
                    grid[i][j] += grid[i][j - 1];
                else if (j == 0)
                    grid[i][j] += grid[i - 1][j];
                else
                    grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
            }
        
        return grid[m - 1][n - 1];
    }    
};
*/