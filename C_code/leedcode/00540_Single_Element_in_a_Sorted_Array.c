#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*540. Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

int singleNonDuplicate(int* nums, int numsSize);

void main()
{
    printf("woody\n");

    return; 
}



int singleNonDuplicate(int* nums, int numsSize)
{

}

int singleNonDuplicate_hu(int* nums, int numsSize)
{
    /*
    Runtime: 6 ms, faster than 80.49% of C online submissions for Single Element in a Sorted Array.
    Memory Usage: 6.5 MB, less than 84.15% of C online submissions for Single Element in a Sorted Array.
    */
    int i = 0, j = numsSize-1;
    //[1,1,2,3,3,4,4,8,8]
    if(numsSize == 1)
        return nums[0];

    while(i <= j)
    {
        if(nums[i+1] == nums[i])
        {
            i = i + 2;
        }
        else
        {
            if(nums[i+1] == nums[i+2])
                return nums[i];
            if(i != 0)
            {
                if(nums[i] == nums[i-1])
                    return nums[i+1];
            }
            else
                return nums[0];
        }
        if(nums[j-1] == nums[j])
        {
            j = j - 2;
        }
        else
        {
            if(nums[j-1] == nums[j-2])
                return nums[j];
            if(j != numsSize-1)
            {
                if(nums[j] == nums[j+1])
                    return nums[i-1];
            }
            else
                return nums[numsSize-1];
        }
    }
    return nums[0];
}

int singleNonDuplicate_xor(int* nums, int numsSize)
{
    /*
    Runtime: 8 ms, faster than 80.49% of C online submissions for Single Element in a Sorted Array.
    Memory Usage: 6.9 MB, less than 21.95% of C online submissions for Single Element in a Sorted Array.
    */
    int i = 0, n = 0;

    for(i=0;i<numsSize;i++)
        n ^= nums[i];
    
    return n;
}
