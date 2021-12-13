#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*438. Find All Anagrams in a String
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/


#define INT_MIN -2147483647-1

int* findAnagrams(char * s, char * p, int* returnSize);


void main()
{
    printf("woody\n");

    return; 
}
/*
 * Runtime: 84 ms, faster than 50.00% of C online submissions for Find All Anagrams in a String.
 * Memory Usage: 408.8 MB, less than 22.37% of C online submissions for Find All Anagrams in a String.
*/
int* findAnagrams2(char * s, char * p, int* returnSize)
{
    int *result = NULL;
    int resultLen = 0;
    int lenS = strlen(s);
    int lenP = strlen(p);
    int i = 0, j = 0;
    int diffCount = 0;
    int countD['z'-'a'+1] = {0};

    if(lenS < lenP)
    {
        *returnSize = resultLen;
        return result;
    }


    for(j=0;j<lenP;j++)
        countD[p[j]-'a']--;
    for(j=0;j<lenP;j++)
        countD[s[j]-'a']++;

    for(char c='a';c<='z';c++)
    {
        if(countD[c-'a'] != 0)
            diffCount++;
    }

    for(i=0; i< lenS-lenP+1;i++)
    {
        if(0 == diffCount)
        {
            result = realloc(result, (resultLen+1)*sizeof(int));
            result[resultLen] = i;
            resultLen++;
        }
        // i => i+1
        countD[s[i]-'a']--;
        if( -1 == countD[s[i]-'a'])
            diffCount++;
        if( 0 == countD[s[i]-'a'])
            diffCount--;
        
        if(i+lenP < lenS)
        {
            countD[s[i+lenP]-'a']++;
            if(countD[s[i+lenP]-'a'] == 1)
                diffCount++;
            if(countD[s[i+lenP]-'a'] == 0)
                 diffCount--;
        }
    }

    *returnSize = resultLen;
    return result;
}



/**
 * Runtime: 1260 ms, faster than 7.89% of C online submissions for Find All Anagrams in a String.
 * Memory Usage: 408.9 MB, less than 22.37% of C online submissions for Find All Anagrams in a String.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams1(char * s, char * p, int* returnSize)
{
    int *result = NULL;
    int resultLen = 0;
    int lenS = strlen(s);
    int lenP = strlen(p);
    int i = 0, j = 0;

    for(i=0; i< lenS-lenP+1;i++)
    {
        int countS['z'-'a'+1] = {0};
        int countP['z'-'a'+1] = {0};
        for(j=0;j<lenP;j++)
            countS[s[i+j]-'a']++;

        for(j=0;j<lenP;j++)
            countP[p[j]-'a']++;
        
        bool isTheSame =true;
        for(char c='a';c<='z';c++)
        {
            if(countS[c-'a'] != countP[c-'a'])
            {
                isTheSame = false;
                break;
            }
        }
        if(isTheSame)
        {
            result = realloc(result, (resultLen+1)*sizeof(int));
            result[resultLen] = i;
            resultLen++;
        }
    }


    *returnSize = resultLen;
    return result;
}