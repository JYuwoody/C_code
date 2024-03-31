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

/*528. Random Pick with Weight
00528_Random_Pick_with_Weight.c
Solved
Medium
Topics
Companies
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
 

Example 1:

Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.
Example 2:

Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output
[null,1,1,1,1,0]

Explanation
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // return 1. It is returning the second element (index = 1) that has a probability of 3/4.
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 0. It is returning the first element (index = 0) that has a probability of 1/4.

Since this is a randomization problem, multiple answers are allowed.
All of the following outputs can be considered correct:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
and so on.
 

Constraints:

1 <= w.length <= 104
1 <= w[i] <= 105
pickIndex will be called at most 104 times.
*/



// Runtime: 97ms, Beats: 93.10%
// Memory: 28.13MB, Beats: 72.41%

typedef struct {
    int* a;
    int aSize;
} Solution;


Solution* solutionCreate(int* w, int wSize) {
    Solution* self = malloc(sizeof(Solution));
    int i = 0;
    self->a = malloc(sizeof(int)*wSize);
    self->aSize = wSize;
    self->a[0] = w[0];

    for(i=1;i<wSize;i++)
    {
        self->a[i] = self->a[i-1] + w[i];
    }

    return self;
}

int solutionPickIndex(Solution* self) {
    int d = rand() % self->a[self->aSize-1];
    int l = 0, r = self->aSize;
    int mid = 0;

    while(l < r)
    {
        mid = (l+r) / 2;
        if(d < self->a[mid])
        {
            if(mid == 0 || d >= self->a[mid-1])
            {
                return mid;
            }
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

void solutionFree(Solution* obj) {
    free(obj->a);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);
 
 * solutionFree(obj);
*/



// ---
// python3
// # Runtime: 2431ms,Beats: 18.67%
// # Memory: 21.10MB, Beats: 55.70%
// class Solution:

//     def __init__(self, w: List[int]):
//         a = [None] * len(w)
//         a[0] = w[0]
//         for i in range(1, len(w)):
//             a[i] = a[i-1] + w[i]

//         self.__a = a

//     def pickIndex(self) -> int:
//         # d = random.randrange(self.__a(len(self.__a)-1))
//         d = random.randrange(self.__a[-1])  # a的最後一個 = len(self.__a)-1 = -1
//         for i, c in enumerate(self.__a):
//             if d < c:
//                 return i


// # Runtime: 164ms,Beats: 46.59%
// # Memory: 21.18MB, Beats: 55.70%
// class Solution:

//     def __init__(self, w: List[int]):nb 
//         a = []
//         a.append(w[0])
//         for i in range(1, len(w)):
//             a.append(a[-1] + w[i])
//         self.__a = a

//     def pickIndex(self) -> int:
//         # d = random.randrange(self.__a(len(self.__a)-1))
//         d = random.randrange(self.__a[-1])  # a的最後一個 = len(self.__a)-1 = -1
//         l, r = 0, len(self.__a)

//         while l< r:
//             mid = (l+r)//2
//             if d < self.__a[mid]:
//                 if mid == 0 or d >= self.__a[mid-1]:
//                     return mid
//                 r = mid
//             else:
//                 l = mid+1