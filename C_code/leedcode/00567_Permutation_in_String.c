#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*567. Permutation in String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/


#define INT_MIN -2147483647-1

bool checkInclusion(char * s1, char * s2);


void main()
{
    printf("woody\n");

    return; 
}

/* woody follow 438
Runtime: 4 ms, faster than 79.31% of C online submissions for Permutation in String.
Memory Usage: 6.3 MB, less than 12.07% of C online submissions for Permutation in String.
*/
bool checkInclusion(char * s1, char * s2)
{
    int lens1 = strlen(s1);
    int lens2 = strlen(s2);
    int i, j, diffCount = 0;
    char c;

    int countMap['z'-'a'+1] = {0};

    bool isTheSame = true;

    if(lens1>lens2) 
        return false;

    for(j=0;j<lens1;j++)
        countMap[s1[j]-'a']--;
    for(j=0;j<lens1;j++)
        countMap[s2[j]-'a']++;

    for(char c='a';c<='z';c++)
    {
        if(countMap[c-'a'] != 0)
            diffCount++;
    }

    for(i=0; i< lens2-lens1+1;i++)
    {
        if(0 == diffCount)
        {
            return true;
        }
        // i => i+1
        countMap[s2[i]-'a']--;
        if( -1 == countMap[s2[i]-'a'])
            diffCount++;
        if( 0 == countMap[s2[i]-'a'])
            diffCount--;
        
        if(i+lens1 < lens2)
        {
            countMap[s2[i+lens1]-'a']++;
            if(countMap[s2[i+lens1]-'a'] == 1)
                diffCount++;
            if(countMap[s2[i+lens1]-'a'] == 0)
                 diffCount--;
        }
    }
    return false;
}

/*
Runtime: 112 ms, faster than 32.76% of C online submissions for Permutation in String.
Memory Usage: 6.2 MB, less than 41.95% of C online submissions for Permutation in String.
*/
bool checkInclusion1(char * s1, char * s2)
{
    int lens1 = strlen(s1);
    int lens2 = strlen(s2);
    int i, j;
    char c;

    int countS1Map['z'-'a'+1] = {0};
    bool isTheSame = true;

    for(j=0;j<lens1;j++)
        countS1Map[s1[j]-'a']++;

    for(i=0;i<lens2-lens1+1;i++)
    {
        int countS2Map['z'-'a'+1] = {0};
        for(j=i;j<lens1+i;j++)
            countS2Map[s2[j]-'a']++;

        isTheSame = true;

        for(c='a';c<='z';c++)
        {
            if(countS1Map[c-'a'] != countS2Map[c-'a'])
            {
                isTheSame = false;
                break;
            }
        }
        if(isTheSame)
            return true;
    }
    return false;
}