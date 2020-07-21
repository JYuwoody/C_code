#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize);

void main()
{
    return; 
}

//=======================================================================
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int i = 0, total = 1;
    int count0 = 0;
    int count0_index = -1;
    *returnSize = numsSize;

    int* output = malloc(sizeof(int)*numsSize);

    for(i=0;i<numsSize;i++)
    {
        if(nums[i] != 0)
            total = total * nums[i];
        else
        {
            count0++;
            count0_index = i;
        }
        output[i] = 0; 
    }
    if(count0 >1)
        return output;

    if(count0 == 1)
    {
        output[count0_index] = total;
        return output;
    }

    for(i=0;i<numsSize;i++)
    {
        output[i] = total / nums[i];
    }


    return output;
}
//=======================================================================
