#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/*00451. Sort Characters By Frequency
Medium

4744

191

Add to List

Share
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

char * frequencySort(char * s){

  
}

//-----------------------------------------------------------//
/*
Runtime: 479 ms, faster than 5.00% of C online submissions for Sort Characters By Frequency.
Memory Usage: 6.7 MB, less than 47.50% of C online submissions for Sort Characters By Frequency.
*/
int *globalCoubt;
int cmp(const char *x, char *y, int *count)
{
  int diff = globalCoubt[*y] - globalCoubt[*x];
  if(diff == 0)
  {
    return *x-*y;
  }
  return diff;
}

char * frequencySort_2(char * s)
{
  int i = 0, k = 0, count[128] = {0};
  char t;

  //count char times
  for(i=0;i<strlen(s);i++)
  {
    count[s[i]] = count[s[i]] + 1;
  }
  globalCoubt = count;

  qsort(s, strlen(s), sizeof(char), cmp);

  return s; 
}

//-----------------------------------------------------------//
char * frequencySort_1(char * s)
{
  int i = 0, k = 0, count[128] = {0};
  char t;

  //count char times
  for(i=0;i<strlen(s);i++)
  {
    count[s[i]] = count[s[i]] + 1;
  }

  //sort char
  for(k=0;k+1<strlen(s);k++)
  {
    for(i=0;i+1<strlen(s);i++)
    {
      if(count[s[i]] < count[s[i+1]] || count[s[i]] == count[s[i+1]] && s[i] > s[i+1])
      {
        t = s[i];
        s[i] = s[i+1];
        s[i+1] = t;
      }
    }
  }

    return s; 
}

//https://www.youtube.com/watch?v=fYzTbc2rx44&list=PLY_qIufNHc292EYDwe3B6sGYO_vQ7pOLx&index=22