#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
//221. Maximal Square
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize);

void main()
{

    return; 
}


//==========================================================================================
int min2(int a, int b)
{
    if(a<b)
        return a;
    return b;
}

int NoZero(char** matrix, int row , int col, int size)
{
    int  dr, dc, output = 1;
    for(dr=0;dr<size;dr++)
    {
        for(dc=0;dc<size;dc++)
        {
            if(matrix[row+dr][col+dc] == '0')
            {
                output = 0;
                return output;
            }
        }
    }
    return 1;
}

int maximalSquare_2(char** matrix, int matrixSize, int* matrixColSize)
{
    if(matrixSize == 0) return 0;
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int row, col, maxSize = 0, size;

    for(row=0;row<rows;row++)
    {
        for(col=0;col<cols;col++)
        {
            for(size=1;size<=min2(rows-row,cols-col);size++)
            {
                if(NoZero(matrix, row, col, size) && size > maxSize)
                {
                    maxSize = size;
                }
            }
            
        }
    }
    return maxSize*maxSize;
}


//==========================================================================================

int maximalSquare_logic(char** matrix, int matrixSize, int* matrixColSize)
{
    if(matrixSize == 0) return 0;
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int row, col, dr, dc, maxSize = 0, size;
    int noZero;

    for(row=0;row<rows;row++)
    {
        for(col=0;col<cols;col++)
        {
            for(size=1;size<=min2(rows-row,cols-col);size++)
            {
                noZero = 1;
                for(dr=0;dr<size;dr++)
                {
                    for(dc=0;dc<size;dc++)
                    {
                        if(matrix[row+dr][col+dc] == '0')
                        {
                            noZero = 0;
                        }
                    }
                }
                if(noZero && size > maxSize)
                {
                    maxSize = size;
                }
            }
            
        }
    }
    return maxSize*maxSize;
}
//==========================================================================================