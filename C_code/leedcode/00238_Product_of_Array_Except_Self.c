#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*
238. Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

int* productExceptSelf(int* nums, int numsSize, int* returnSize);

void main()
{
    return; 
}

//=======================================================================
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize)    //my is faster better_1 and better_2
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
int* productExceptSelf_better1(int* nums, int numsSize, int* returnSize)
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
int* productExceptSelf_better2(int* nums, int numsSize, int* returnSize)
{
    int* output = (int *)malloc(sizeof(int)*numsSize);
    int left = 1;
    int i = 0;
    //int* right = (int *)malloc(sizeof(int)*numsSize+1); output replace

    *returnSize = numsSize;
    

    /*
    for(i=0;i<numsSize;i++)
    {
        left[i] = left[i-1] * nums[i-1];
    }
    */
    output[numsSize-1] = 1;
    for(i=numsSize-2;i>=0;i--)
    {
        output[i] = output[i+1] * nums[i+1];
    }
    

    for(i=0;i<numsSize;i++)
    {
        output[i] = left * output[i];
        left = left * nums[i];
    }

    return output;
}

//=======================================================================
