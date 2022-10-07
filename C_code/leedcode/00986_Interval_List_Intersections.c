#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/*00986. Interval List Intersections
Medium

You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 

Example 1:


Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Example 2:

Input: firstList = [[1,3],[5,9]], secondList = []
Output: []
 

Constraints:

0 <= firstList.length, secondList.length <= 1000
firstList.length + secondList.length >= 1
0 <= starti < endi <= 109
endi < starti+1
0 <= startj < endj <= 109
endj < startj+1
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** intervalIntersection(int** A, int ASize, int* AColSize, 
                           int** B, int BSize, int* BColSize, 
                           int* returnSize, int** returnColumnSizes)
{
}



/*
Runtime: 140 ms, faster than 15.79% of C online submissions for Interval List Intersections.
Memory Usage: 55.5 MB, less than 5.26% of C online submissions for Interval List Intersections.
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

int** intervalIntersection(int** A, int ASize, int* AColSize, 
                           int** B, int BSize, int* BColSize, 
                           int* returnSize, int** returnColumnSizes)
{
    int** ans = NULL;
    int ansSize = 0;
    int i = 0, j = 0;

    while(i<ASize && j<BSize)
    {
        if(B[j][0]<=A[i][1] && A[i][0]<=B[j][1])
        {
            int* C = malloc(sizeof(int)*2);
            C[0] = max(A[i][0], B[j][0]);
            C[1] = min(A[i][1], B[j][1]);

            ansSize++;
            ans = realloc(ans, ansSize*sizeof(int*));
            ans[ansSize-1] = C;
        }
        if(A[i][1]<=B[j][1])
            i++;
        else
            j++;
    }

    *returnSize = ansSize;
    int *ansColSize = malloc(ansSize*sizeof(int));
    for(i=0;i<ansSize;i++)
    {
        ansColSize[i] = 2;
    }
    *returnColumnSizes = ansColSize;
    return ans;

}

/*
Runtime: 126 ms, faster than 31.58% of C online submissions for Interval List Intersections.
Memory Usage: 55.3 MB, less than 10.53% of C online submissions for Interval List Intersections.
*/
int** intervalIntersection1(int** A, int ASize, int* AColSize, 
                           int** B, int BSize, int* BColSize, 
                           int* returnSize, int** returnColumnSizes)
{
    //firstList = [[0,2],[5,10],[13,23],[24,25]], firstListSize=4, firstListColSize=[2,2,2,2]
    //secondList = [[1,5],[8,12],[15,24],[25,26]], secondListSize=4, secondListColSize[2,2,2,2]
    //ans = [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]], *returnSize = 6, *returnColumnSizes = ansColSize // [2,2,2,2,2,2]
    int** ans = NULL;
    int ansSize = 0;
    int i = 0, j = 0;

    while(i<ASize && j<BSize)
    {
        if(A[i][0]<=B[j][0] && B[j][1]<=A[i][1])
        {
            // A[i]:   [      ]
            // B[j]:     [  ]
            int* C = malloc(sizeof(int)*2);
            C[0] = B[j][0];
            C[1] = B[j][1];

            ansSize++;
            ans = realloc(ans, ansSize*sizeof(int*));
            ans[ansSize-1] = C;
        }
        else if(B[j][0]<=A[i][0] && A[i][1]<=B[j][1])
        {
            // A[i]:     [  ]
            // B[j]:   [      ]
            int* C = malloc(sizeof(int)*2);
            C[0] = A[i][0];
            C[1] = A[i][1];

            ansSize++;
            ans = realloc(ans, ansSize*sizeof(int*));
            ans[ansSize-1] = C;
        }
        else if(A[i][0]<=B[j][0] && B[j][0]<=A[i][1] && A[i][1]<=B[j][1])
        {
            // A[i]:  [     ]
            // B[j]:      [      ]
            int* C = malloc(sizeof(int)*2);
            C[0] = B[j][0];
            C[1] = A[i][1];

            ansSize++;
            ans = realloc(ans, ansSize*sizeof(int*));
            ans[ansSize-1] = C;
        }
        else if(B[j][0]<=A[i][0] && A[i][0]<=B[j][1] && B[j][1]<=A[i][1])
        {
            // A[i]:     [     ]
            // B[j]: [      ]
            int* C = malloc(sizeof(int)*2);
            C[0] = A[i][0];
            C[1] = B[j][1];

            ansSize++;
            ans = realloc(ans, ansSize*sizeof(int*));
            ans[ansSize-1] = C;
        }

        if(A[i][1]<=B[j][1])
            i++;
        else
            j++;
    }

    *returnSize = ansSize;
    int *ansColSize = malloc(ansSize*sizeof(int));
    for(i=0;i<ansSize;i++)
    {
        ansColSize[i] = 2;
    }
    *returnColumnSizes = ansColSize;
    return ans;
}
