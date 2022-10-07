#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/*01035. Uncrossed Lines
Medium

1863

28

Add to List

Share
You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j], and
the line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.

 

Example 1:


Input: nums1 = [1,4,2], nums2 = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.
Example 2:

Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
Output: 2
 

Constraints:

1 <= nums1.length, nums2.length <= 500
1 <= nums1[i], nums2[j] <= 2000

*/


#define max(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b;       \
})

#define min(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b;       \
})




/*
Runtime: 164 ms, faster than 8.33% of C online submissions for Uncrossed Lines.
Memory Usage: 5.8 MB, less than 100.00% of C online submissions for Uncrossed Lines.
*/
int maxUncrossedLines(int* A, int MaxASize, int* B, int MaxBSize)
{
    int **cache = malloc(sizeof(int*)*2); // catche[ASize] [BSize]
    for(int i=0;i<=1;i++)
    {
        cache[i] = malloc(sizeof(int*)*(MaxBSize+1));
    }
    for(int ASize=0; ASize<=MaxASize;ASize++)
    {
        for(int BSize=0; BSize<=MaxBSize;BSize++)
        {
            if(ASize == 0) 
            {   
                cache[ASize][BSize] = 0;
                continue;
            }

            int case1 = cache[(ASize-1)%2][BSize];
            int case2 = 0;
            {
                int i = ASize - 1;
                for(int j=BSize-1;j>=0;j--)
                {
                    if(A[i] == B[j])
                    {
                        case2 = 1 + cache[i%2][j];
                        break;
                    }
                } 
            }
            cache[ASize%2][BSize] = max(case1, case2);
        }
    }

    return cache[MaxASize%2][MaxBSize];
}





/*
Runtime: 25 ms, faster than 33.33% of C online submissions for Uncrossed Lines.
Memory Usage: 11.2 MB, less than 8.33% of C online submissions for Uncrossed Lines.
*/
int cachemaxUncrossedLines1(int* A, int ASize, int* B, int BSize, int** cache)
{
    if(ASize == 0) return 0;

    //-1: not cache
    if(cache[ASize][BSize] != -1) return cache[ASize][BSize];

    //最後一個不選
    int case1 = cachemaxUncrossedLines1(A, ASize-1, B, BSize, cache);
    //最後一個選
    int case2 = 0;
    {
        int i = ASize - 1;
        for(int j=BSize-1;j>=0;j--)
        {
            if(A[i] == B[j])
            {
                case2 = 1 + cachemaxUncrossedLines1(A, i, B, j, cache);
                break;
            }
        } 
    }

    cache[ASize][BSize] = max(case1, case2);
    return cache[ASize][BSize];
}


int maxUncrossedLines1(int* A, int ASize, int* B, int BSize)
{
    int **cache = malloc(sizeof(int*)*(ASize+1)); // catche[ASize] [BSize]
    for(int i=0;i<=ASize;i++)
    {
        cache[i] = malloc(sizeof(int*)*(BSize+1));
        for(int j=0;j<=BSize;j++)
        {
            cache[i][j] = -1;
        }
    }
    cachemaxUncrossedLines1(A, ASize, B, BSize, cache);


    return cache[ASize][BSize];
}


/****************************************************************/

int maxUncrossedLines2(int* A, int ASize, int* B, int BSize)
{
    if(ASize == 0) return 0;
    int case1 = maxUncrossedLines2(A, ASize-1, B, BSize-1);
    int case2 = 0;
    {
        int i = ASize - 1;
        for(int j=BSize-1;j>=0;j--)
        {
            if(A[i] == B[j])
            {
                case2 = 1 + maxUncrossedLines2(A, i, B, j);
                break;
            }
        } 
    }

    return max(case1, case2);
}
