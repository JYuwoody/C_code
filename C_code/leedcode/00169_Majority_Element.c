#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/*169. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/
int majorityElement(int* nums, int numsSize);

void main()
{


    return; 
}


int majorityElement(int* nums, int numsSize)
{
    int count = 0;
    int i, j;

    while(true)
    {
        i = rand() % numsSize;  //because this issue the answer count bigger than n/2. So it have more 50% to select
        count = 0;
        for(j=0;j<numsSize;j++)
        {
            if(nums[i] == nums[j])
            {
                count++;
            }

            if(count > numsSize/2)
                return nums[i];
        }

    }

    return 0;
}
//====================================================================================================
struct Entry
{
    int num;
    int count;
};

void addOne(struct Entry *countMap, int num, int hashTableSize)
{
    int hash = (num % hashTableSize + hashTableSize) % hashTableSize;

    while(true)
    {
        if(countMap[hash].count == 0)
        {
            countMap[hash].num = num;
            countMap[hash].count = 1;
            return;
        }
        if(countMap[hash].num == num)
        {
            countMap[hash].count++;
            return;
        }
        hash = (hash + 1) % hashTableSize;
    }
    
}

int majorityElement1(int* nums, int numsSize)
{
    int hashTableSize = numsSize * 2;
    int i, j;
    struct Entry countMap [hashTableSize];

    for(i=0;i<hashTableSize;i++)
    {
        countMap[i].count = 0;
    }


    for(i=0;i<numsSize;i++)
    {
        addOne(countMap, nums[i], hashTableSize);
    }

    for(i=0;i<hashTableSize;i++)
    {
        if(countMap[i].count > numsSize/2)
            return countMap[i].num;
    }

    return 0;
}
//====================================================================================================
int rangeMajorityElement(int* nums, int start, int stop)
{
    if(start == stop) return nums[start];

    int mid = start + (stop - start) / 2;
    int leftMajorityElement = rangeMajorityElement(nums, start, mid);
    int rightMajorityElement = rangeMajorityElement(nums, mid+1, stop);

    if(leftMajorityElement == rightMajorityElement)
        return leftMajorityElement;

    int leftCount = 0, rightCount = 0, i;

    for(i=start;i<=stop;i++)
    {
        if(nums[i] == leftMajorityElement)
            leftCount++;
    }
    for(i=start;i<=stop;i++)
    {
        if(nums[i] == rightMajorityElement)
            rightCount++;
    }

    if(leftCount >= rightCount)
        return leftMajorityElement;
    else
        return rightMajorityElement;
}

int majorityElement(int* nums, int numsSize)
{
    return rangeMajorityElement(nums, 0, numsSize-1);
}
