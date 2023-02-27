#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

//!
//?
//todo
//@param
//* 

/*00338. Counting Bits
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*Runtime 46 ms Beats 79.50% Memory 10.3 MB Beats 84.10%*/
int* countBits_2(int n, int* returnSize)
{
    int *ret = malloc(sizeof(int)*(n+1));
    int i = 0;
    *returnSize = n+1;

    ret[0] = 0;
    for(i=1;i<=n;i++)
    {
        ret[i] = ret[i/2] + (( i & 1 ) > 0);
    }
    return ret;
}
/*Runtime 51 ms Beats 45.98% Memory 10.5 MB Beats 60.15%*/
int* countBits_1(int n, int* returnSize)
{
    int *ret = malloc(sizeof(int)*(n+1));
    int count = 0, i = 0, offset = 0, mask = 0x01;
    *returnSize = n+1;

    for(i=0;i<=n;i++)
    {
        count = 0;
        for(offset=30;offset>=0;offset--)
        {
            mask = 0x01 << offset;
            if((i&mask)>0)
            {
                count++;
            }
        }
        ret[i] = count;
    }
    return ret;
}