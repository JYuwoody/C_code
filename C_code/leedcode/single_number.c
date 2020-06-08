#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

int signnumber(int* num, int numsSize);
int better_signnumber(int* num, int numsSize);


int main()
{
    int arrary[5] = {4,1,2,1,2};
    signnumber(arrary,5);

    return 0;
}


int signnumber(int* nums, int numsSize)
{
    int i = 0,j = 0;
    int count = 0;
    for(i=0;i<numsSize;i++)
    {
        count = 0;
        for(j=0;j<numsSize;j++)
        {
            if(i!=j)
            {
                if(nums[i]==nums[j])
                {
                    count = count + 1; 
                    nums[i] = 0;
                    nums[j] = 0;
                }
                
            }
        }
        if(count == 0 && nums[i]!=0)
        {
            printf("ans=%d\n",nums[i]);
            return nums[i];
        }
    }
    return 0;
}

int better_signnumber(int* num, int numSize)
{
    int n = num[0], i = 0;
    for(i=1;i<numSize;i++)
    {
        n^=num[i];
    }

    return n;
}

