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
    //陣列中有兩個0，除了自己互乘都會遇到乘0
    if(count0 >1)
        return output;

    //陣列中只有1個0，記錄下第幾個index是0，他會有值，其他為0
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
int* productExceptSelf_better(int* nums, int numsSize, int* returnSize)
{
    int* res = (int *)malloc(sizeof(int)*numsSize);
    int* left = (int *)malloc(sizeof(int)*numsSize);//store the product of left of element i
    int* right = (int *)malloc(sizeof(int)*numsSize);//store the product of right of element i;
    int i;

    left[0] = 1;
    for(i = 1;i<numsSize;i++)
        left[i] = nums[i-1]*left[i-1];

    right[numsSize-1] = 1;
    for(i = numsSize-2;i>=0;i--)
        right[i] = nums[i+1]*right[i+1];

    for(i = 0;i<numsSize;i++)
        res[i] = left[i]*right[i];

    *returnSize = numsSize;    
    return res;
}

//=======================================================================
