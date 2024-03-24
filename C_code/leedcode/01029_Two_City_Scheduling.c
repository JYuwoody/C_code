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

/*1029. Two City Scheduling
01029_Two_City_Scheduling.c
Medium
Topics
Companies
A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

 

Example 1:

Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
Example 2:

Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
Output: 1859
Example 3:

Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
Output: 3086
 

Constraints:

2 * n == costs.length
2 <= costs.length <= 100
costs.length is even.
1 <= aCosti, bCosti <= 1000
*/



// Runtime: 5ms, Beats: 75.00%
// Memory: 5.89MB, Beats: 100.00%

int diff(int *l)
{
    return l[0]-l[1];
}

int cmp(const void* p1, const void* p2)
{
    int* l1 = *(const int**) p1;
    int* l2 = *(const int**) p2;

    return diff(l1) - diff(l2);
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
    qsort(costs, costsSize, sizeof(int*), cmp);
    int countA = 0;
    int ans = 0;

    for(int i=0;i<costsSize;i++)
    {
        int costsA = costs[i][0];
        int costsB = costs[i][1];

        if(countA < costsSize/2)
        {
            ans += costsA;
            countA += 1;
        }
        else
        {
            ans += costsB;
        }
    }
    return ans;
}

// python3
// # Runtime: 43ms, Beats: 57.09%
// # Memory: 16.48MB, Beats:　94.70%

// def diff(l):
//     return l[0]-l[1]

// class Solution:
//     def twoCitySchedCost(self, costs: List[List[int]]) -> int:
//         costs.sort(key=diff)
//         countA = 0
//         ans = 0
//         for costA, costB in costs:
//             if countA < len(costs)//2:
//                 ans += costA
//                 countA += 1
//             else:
//                 ans += costB
//         return ans