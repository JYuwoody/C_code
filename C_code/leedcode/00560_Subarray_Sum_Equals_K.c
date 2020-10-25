#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
//560. Subarray Sum Equals K
/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/


int subarraySum(int* nums, int numsSize, int k);
int subarraySum_wf(int* nums, int numsSize, int k);
int subarraySum_better(int* nums, int numsSize, int k);

void main()
{


    return; 
}



int subarraySum(int* nums, int numsSize, int k)
{
    int count = 0;
    int i = 0, sum = 0, j = 0;

    for(i=0;i<numsSize;i++)
    {
        sum = 0;
        for(j=i;j<numsSize;j++)
        {
            sum += nums[j];
            if(sum == k)
            {
                count++;
            }
        }
    }

    return count;

}


int subarraySum_wf(int* nums, int numsSize, int k)
{
    int count = 0;
    int i = 0, temp = 0, j = 0;

    for(i=0;i<numsSize;i++)
    {
        j = 0;
        temp = 0;
        while((i+j) < numsSize)
        {
            temp += nums[i+j];
            j++;

            if(temp == k)
            {
                count++;
            }   
        }
    }

    return count;
}
//=======================================================================================
#define CAPACITY 100000

struct Entry
{
    int sum;
    int counter;
};

int getIndex(int sum)
{
    return (sum % CAPACITY + CAPACITY ) % CAPACITY;
}
void addOne(struct Entry** counter, int sum)
{
    int i = getIndex(sum);
    while(counter[i] != NULL)
    {
        if(counter[i]->sum == sum)
        {
            counter[i]->counter++;
            return;
        }
        i = getIndex(i+1);
    }
    struct Entry* entry = malloc(sizeof(struct Entry));
    entry->sum = sum;
    entry->counter = 1;
    counter[i] = entry;
    return;
}

int query(struct Entry** counter, int sum)
{
    int i = getIndex(sum);
    while(counter[i] != NULL)
    {
        if(counter[i]->sum == sum)
        {
            return counter[i]->counter;
        }
        i = getIndex(i+1);
    }
    return 0;
}

int subarraySum_better(int* nums, int numsSize, int k)
{
    //HashTable
    struct Entry** counter = calloc(CAPACITY, sizeof(struct Entry*));

    int sum = 0, j = 0;
    int totalcount = 0;
    int target = 0;

    for(j=0;j<numsSize;j++)
    {
        addOne(counter, sum);
        sum += nums[j];
        target = sum - k;
        totalcount += query(counter, target);
    }
    free(counter);

    return totalcount;
}
/*
    //sum[0] = 0
    //sun[i] = nums[0] + nums[1] + ... + nums[i-1]
    if(sum[j+1] == k + sum[i]) // sum[i] = sum[j+1] - k // targer =  sum[j+1] - k
    {
        counter++
    }

sum(i,j+1) = sum(0,j+1)-sum(0,i)

if(sum(i,j+1) == k) //
{
    counter++
}
sum[j+1]-sum[i]
if(sum[j+1]-sum[i]== k) //
{
    counter++
}
if(sum[i] == sum[j+1] - k) //
{
    counter++
}
*/
//=======================================================================================
