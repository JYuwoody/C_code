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
