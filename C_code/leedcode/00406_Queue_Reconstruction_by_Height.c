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

/*406. Queue Reconstruction by Height
00406_Queue_Reconstruction_by_Height.c
Medium
Topics
Companies
Hint
You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

 

Example 1:

Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
Example 2:

Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 

Constraints:

1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
It is guaranteed that the queue can be reconstructed.
*/



// Runtime: 42 ms, Beats: 80.00 %
// Memory: 10.73 MB, Beats: 20.00 %

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *pa, const void *pb)
{
    // *pa before *pb return -
    // *pa after *pb return +
    // *pa same *pb return 0

    const int* a = *(const int**)pa;
    const int* b = *(const int**)pb;

    if(a[0] == b[0])
        return a[1]-b[1];
    
    return b[0] - a[0];
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes) {
    // people = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
    // peopleSize = 6
    // peopleColSize = [2, 2, 2, 2, 2, 2]
    // (* returnColumnSizes) =[2, 2, 2, 2, 2, 2]
    // (*returnSize) = 6
    int i = 0, j = 0;

    qsort(people, peopleSize, sizeof(int*), cmp);

    int** answer = malloc(peopleSize*sizeof(int*));

    for(i=0;i<peopleSize;i++)
    {
        answer[i] = malloc(2*sizeof(int));
    }

    for(i=0;i<peopleSize;i++)
    {
        for(j=i;j>people[i][1];j--)
        {
            answer[j][0] = answer[j-1][0];
            answer[j][1] = answer[j-1][1];
        }
        answer[people[i][1]][0] = people[i][0];
        answer[people[i][1]][1] = people[i][1];
    }


    *returnSize = peopleSize;
    *returnColumnSizes = malloc(peopleSize*sizeof(int));
    for(i=0;i<peopleSize;i++)
    {
        (*returnColumnSizes)[i] = 2;
    }

    return answer;
}




// ---
// python3
// # for all Permutation:
// #     if This Permutation ticks all the boxes:
// #         return result

// # people = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]

// # ..., [<7, ?], [7, 0], [<7, ?], [7, 1], , [<7, ?]
// # ..., [<6, ?], [7, 0], [<6, ?], [6, 1], [<6, ?], [7, 1], [<6, ?]

// # first step sort taller
// # [7, 0], [7, 1], [6, 1], [5, 0], [5, 2], [4, 4]
// # use k([hj, kj]) to insert the queue

// # Runtime: 78 ms,Beats: 88.92%
// # Memory: 17.13 MB, Beats: 45.82%
// class Solution:
//     def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
//         people.sort(key=lambda l: (-l[0], l[1]))
//         # print(people)

//         answer = []
//         for l in people:
//             # l: [7, 1]
//             answer.insert(l[1], l)

//         # []
//         # [7, 0]
//         # [7, 0], [7, 1]
//         # [7, 0], [6, 1], [7, 1]
//         # [5, 0], [7, 0], [6, 1], [7, 1]
//         # [5, 0], [7, 0], [5, 2], [6, 1], [7, 1]
//         # [5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]
//         return answer

