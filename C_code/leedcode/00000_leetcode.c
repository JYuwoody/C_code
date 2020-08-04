#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>



int numIslands(char** grid, int gridSize, int* gridColSize);
void dfs(char** grid, int x, int y, int NUMBER_OF_ROWS, int NUMBER_OF_COLS);
void display(char** grid,int NUMBER_OF_ROWS,int NUMBER_OF_COLS);


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

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    //11110
    //01010
    //10001
    //11110
    int NUMBER_OF_ROWS = gridSize;  //4
    int NUMBER_OF_COLS = gridColSize[0];  //5
    int ans = 0, x, y;

    //print map
    display(grid,NUMBER_OF_ROWS,NUMBER_OF_COLS);


    return ans;     
}


//==============================================================================================
//Runtime Error
void dfs(char** grid, int x, int y, int NUMBER_OF_ROWS, int NUMBER_OF_COLS) 
{
    if (x < 0 || y < 0 || x >= NUMBER_OF_COLS || y >= NUMBER_OF_ROWS || grid[y][x] == '0')
        return;

    grid[y][x] = '0';
    dfs(grid, x + 1, y, NUMBER_OF_ROWS, NUMBER_OF_COLS);
    dfs(grid, x - 1, y, NUMBER_OF_ROWS, NUMBER_OF_COLS);
    dfs(grid, x, y + 1, NUMBER_OF_ROWS, NUMBER_OF_COLS);
    dfs(grid, x, y - 1, NUMBER_OF_ROWS, NUMBER_OF_COLS);
}

int numIslands1(char** grid, int gridSize, int* gridColSize)
{
    //11110
    //01010
    //10001
    //11110
    int NUMBER_OF_ROWS = gridSize;  //4
    int NUMBER_OF_COLS = gridColSize[0];  //5
    int ans = 0, x, y;

    if(NUMBER_OF_ROWS == 0 || NUMBER_OF_COLS == 0) return 0;

    //print map
    display(grid,NUMBER_OF_ROWS,NUMBER_OF_COLS);

    for(y=0;y<NUMBER_OF_ROWS;y++)
    {
        for(x=0;x<NUMBER_OF_COLS;x++) 
        {
            if(grid[y][x] == '1')
            {
                ans++;
                dfs(grid, x, y, NUMBER_OF_ROWS, NUMBER_OF_COLS);
            }
        }
    }

    return ans;     
}
//==============================================================================================
