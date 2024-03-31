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

/*344. Reverse String
00344_Reverse_String.c
Easy
Topics
Companies
Hint
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
*/



// Runtime: 44ms, Beats: 56.84%
// Memory: 12.04MB, Beats: 82.25%

void reverseString(char* s, int sSize) {
    int i = 0, j = 0;
    char t ="";

    for(i=0; i<sSize/2;i++)
    {
        j = sSize-i-1;
        t = s[j];
        s[j] = s[i];
        s[i] = t;
    }
}

// ---
// python3
// # Runtime: 166ms,Beats: 75.79%
// # Memory: 20.79MB, Beats: 93.64%

// class Solution:
//     def reverseString(self, s: List[str]) -> None:
//         for i in range(len(s)//2):
//             j = len(s)-1-i
//             t = s[i]
//             s[i] = s[j]
//             s[j] = t
        