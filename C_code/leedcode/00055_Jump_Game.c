#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
//55.Jump Game： 是否可以跳到最後一格
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5
*/

bool canJump(int* nums, int numsSize);
bool canJump_better(int* nums, int numsSize);

void main()
{

    return; 
}



bool canJump(int* nums, int numsSize){
    //nums = [2,3,1,1,4] numsSize=5;
    //canReach:判斷個別位置是否可以到達
    int *canReach = calloc( numsSize, sizeof(int) );
    int i, j;

    canReach[0] = 1;

    for(i=0;i<numsSize;i++)
    {
        if(canReach[i]) //當此數不為零
        {
            for(j=1;j<=nums[i];j++)
            {
                if(i+j<numsSize)
                    canReach[i+j] = 1;
            }
        }
        
        //printf("canReach[%d]=%d\n",i,canReach[i]);
    }

    return canReach[numsSize-1];
}

bool canJump_better(int* nums, int numsSize)
{
    //找最右邊是TURE的最大值
    int maxCanReach = 0, CanReach;
    int i;

    for(i=0;i<numsSize;i++)
    {
        if(i <= maxCanReach)    // key point
        {
            CanReach = i + nums[i];
            if(CanReach > maxCanReach)
                maxCanReach = CanReach;
        }
    }
    return numsSize-1 <= maxCanReach;
}










