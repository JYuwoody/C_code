#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*
525. Contiguous Array
Medium

2175

121

Add to List

Share
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/
int findMaxLength(int* nums, int numsSize);
int findMaxLength_1(int* nums, int numsSize);
void main()
{
    int stones[100] = {0,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,0,1,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,1,1,0,1,1,1,1,0,1,1,0,0,0,1,1};
    //int stones[7] = {0,0,0,1,0,1,1};
    //int stones[7] = {1,1,1,0,1,0,0};
    int stonesSize = 100;

    findMaxLength( stones, stonesSize);

    return; 
}


//============================================================
int count(int i, int j ,int* nums,int item)
{
    int k = 0;
    int count = 0;
    for(k=i;k<=j;k++)
    {
        if(item == nums[k])
        {
            count++;
        }
    }
    return count;
}



int findMaxLength(int* nums, int numsSize)
{
    int maxlength = 0 ,temp = 0;
    int i = 0, j = 0;

    for(i=0;i<numsSize;i++)
    {
        for(j=i;j<numsSize;j++)
        {
            if(count(i,j,nums,0) == count(i,j,nums,1))
            {
                temp = j - i +1;
                if(temp > maxlength)
                    maxlength = temp;
            }
        }
    }
    printf("maxlength = %d\n", maxlength);

    return maxlength;
}

//============================================================


//============================================================
int findMaxLength_better(int* nums, int numsSize){
    int *sum = malloc(sizeof(int)*(numsSize*2+1));       
    int i = 0,j=0; 
    for ( i = 0; i < numsSize*2+1; i++)
    {
        sum[i] = -1;
    }
    
    int *tmp = &(sum[numsSize]);
    int ret = 0;
    int curSum = 0;
    for ( i = 0; i < numsSize; i++)
    {

        curSum = (nums[i] == 0 ? curSum-1 : curSum+1);
        if (tmp[curSum] == -1 && curSum != 0)
        {
            tmp[curSum] = i;
            continue;
        } else
        {
            int diff = i - tmp[curSum];
            ret = ret > diff ? ret : diff;
        }
    }
    
    free(sum);
    return ret;

}
//============================================================
