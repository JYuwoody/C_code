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
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, 
                           int** secondList, int secondListSize, int* secondListColSize, 
                           int* returnSize, int** returnColumnSizes)
{
    //firstList = [[0,2],[5,10],[13,23],[24,25]], firstListSize=4, firstListColSize=[2,2,2,2]
    //secondList = [[1,5],[8,12],[15,24],[25,26]], secondListSize=4, secondListColSize[2,2,2,2]
    //ans = [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]], *returnSize = 6, *returnColumnSizes = ansColSize // [2,2,2,2,2,2]
    int** ans = NULL;
    int ansSize = 0;

    *returnSize = ansSize;
    int *ansColSize = malloc(ansSize*sizeof*(int));
    *returnColumnSizes = ansColSize;
    return ans;
}


//https://www.youtube.com/watch?v=fT49oFlbgW4&list=PLY_qIufNHc292EYDwe3B6sGYO_vQ7pOLx&index=23
