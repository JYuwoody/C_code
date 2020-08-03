#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>



int numIslands(char** grid, int gridSize, int* gridColSize);

void main()
{
    
    return; 
}

int display(char**grid,int NUMBER_OF_ROWS,int NUMBER_OF_COLS)
{
    int i, j, flag = 1;
    for(i=0;i<NUMBER_OF_ROWS;i++)
    {
        for(j=0;j<NUMBER_OF_COLS;j++)
        {
            printf("%c ",grid[i][j]);
            if(grid[i][j] == '1')
                flag = 0;
        }
        printf("\n");
    }
    return flag; 
}


int numIslands(char** grid, int gridSize, int* gridColSize)
{
    //11110
    //01010
    //10001
    //11110
    int NUMBER_OF_ROWS = gridSize;  //4
    int NUMBER_OF_COLS = gridColSize[0];  //5
    int landcount = 0, i, j,si,sj;
    int allclear = 0, sideclear = 0;

    //print map
    display(grid,NUMBER_OF_ROWS,NUMBER_OF_COLS);


    for(i=0;i<NUMBER_OF_ROWS;i++)
    {
        for(j=0;j<NUMBER_OF_COLS;j++)
        {
            if(grid[i][j] == '1')
            {
                grid[i][j] = 'X';
            }
        }
    }





}
