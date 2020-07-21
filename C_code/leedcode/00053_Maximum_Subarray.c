#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

int maxSubArray(int* nums, int numsSize);
int better_maxSubArray(int* nums, int numsSize);

int main()
{
    //int a[9]={-2,1,-3,4,-1,2,1,-5,4};
    int a[2]={-2,1};
    printf("output = %d\n",maxSubArray(a,2));
    return 0;
}

int maxSubArray(int* nums, int numsSize)
{
    int start = 0;
    int end = 0;
    int tempsum = 0,sum = nums[0];
    int k = 0;


    for(start=0;start<numsSize;start++)
    {
        tempsum = 0;
        for(end=start;end<numsSize;end++)
        {
            tempsum = tempsum + nums[end];

            if(tempsum > sum)
            {
                sum = tempsum;
            }
        }
    }

    return sum;
}


int better_maxSubArray(int* nums, int numsSize)
{
    int max = nums[0];
    int local = nums[0];
    for (int i = 1; i < numsSize; i++) {
        local = (local > 0)? local + nums[i]: nums[i];
        max = (max < local)? local: max;
    }
    return max;
}
