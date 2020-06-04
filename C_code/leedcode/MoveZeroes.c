#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
void moveZeroes(int* nums, int numsSize);
void moveZeroes_2(int* nums, int numsSize);

void main()
{
    int numsSize = 5, i;
    int Input[5] = {0,1,0,3,12};
    moveZeroes_2(Input,numsSize);
    for (i = 0; i < numsSize; i++)
    {
        printf("Input[%d]=%d\n",i,Input[i]);
    }

    return; 
}

void moveZeroes(int* nums, int numsSize){
    int *temp_Array;
    temp_Array = malloc(sizeof(int)*numsSize);
    int end = numsSize-1;
    int start = 0,i = 0;

    for(i=0;i<numsSize;i++)
    {
        if(0==nums[i])
        {
            *(temp_Array+end) = nums[i];
            end--;
        }
        else
        {
            *(temp_Array+start) = nums[i];
            start++;
        }
        
    }
    for (i = 0; i < numsSize; i++)
    {
        nums[i] = *(temp_Array+i);
    }
    


    free(temp_Array);
    return;
}


void moveZeroes_2(int* nums, int numsSize)
{
    int j = 0,i = 0;

    for(i=0;i<numsSize;i++)
    {
        if(0 != nums[i])
        {
            nums[j] = nums[i];
            j++;
        }
    }
    for(i=j;i<numsSize;i++)
    {
        nums[i] = 0;
    }

    return;
}

