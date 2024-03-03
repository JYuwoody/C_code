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

/*72. Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/


// recursion >>>
int min3(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min =b;
    if (c < min)
        min = c;

    return min;
}

int dominDistance_recursion(char* word1, char* word2, int len1, int len2)
{
    if(len1 == 0)
    {
        return len2;    // add len2 char to word1
    }
    if(len2 == 0)
    {
        return len1;    // add len1 char to word2
    }
    if(word1[len1-1] == word2[len2-1])
    {
        return dominDistance_recursion(word1, word2, len1-1, len2-1);
    }
    // case1: replace
    // word1: "[A]x"
    // word2: "[B]y"
    // A=>B : 5
    // word1=>word2 : 5+1
    // case2: insert
    // word1: "[A]"
    // word2: "[B]y"
    // A=>B : 5
    // word1=>word2 : 5+1
    // case3: remove
    // word1: "[A]x"
    // word2: "[B]"
    // A=>B : 5
    // word1=>word2 : 5+1    
    
    return min3(
        dominDistance_recursion(word1, word2, len1-1, len2-1),    // case1: replace
        dominDistance_recursion(word1, word2, len1, len2-1),      // case2: insert
        dominDistance_recursion(word1, word2, len1-1, len2)       // case3: remove
    ) + 1;

}
int minDistance_recursion(char* word1, char* word2) {

    return dominDistance_recursion(word1, word2, strlen(word1), strlen(word2));

}
// recursion <<<


// catch >>>
/*
Runtime: 0ms, Beats: 100.00%
Memory: 8.22MB, Beats: 7.19%
*/
int min3(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min =b;
    if (c < min)
        min = c;

    return min;
}

int dominDistance(char* word1, char* word2, int len1, int len2, int **cache)
{
    if(len1 == 0)
    {
        return len2;    // add len2 char to word1
    }
    if(len2 == 0)
    {
        return len1;    // add len1 char to word2
    }
    if(cache[len1][len2] != -1)
    {
        return cache[len1][len2];
    }
    if(word1[len1-1] == word2[len2-1])
    {
        cache[len1][len2] = dominDistance(word1, word2, len1-1, len2-1, cache);
        return cache[len1][len2];
    }
    // case1: replace
    // word1: "[A]x"
    // word2: "[B]y"
    // A=>B : 5
    // word1=>word2 : 5+1
    // case2: insert
    // word1: "[A]"
    // word2: "[B]y"
    // A=>B : 5
    // word1=>word2 : 5+1
    // case3: remove
    // word1: "[A]x"
    // word2: "[B]"
    // A=>B : 5
    // word1=>word2 : 5+1    

    cache[len1][len2] = min3(
        dominDistance(word1, word2, len1-1, len2-1, cache),    // case1: replace
        dominDistance(word1, word2, len1, len2-1, cache),      // case2: insert
        dominDistance(word1, word2, len1-1, len2, cache)       // case3: remove
    ) + 1;
    
    return cache[len1][len2];

}
int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int **cache = malloc (sizeof(int*)*(len1+1));

    for(int i=0;i<=len1;i++)
    {
        cache[i] = malloc(sizeof(int)*(len2+1));
        for(int j=0;j<=len2;j++)
        {
            cache[i][j] = -1;
        }
    }

    return dominDistance(word1, word2, strlen(word1), strlen(word2), cache);

}
// catch <<<

/*
Runtime: 5ms, Beats: 56.83%
Memory: 8.00MB, Beats: 21.58%
*/
int min3(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min =b;
    if (c < min)
        min = c;

    return min;
}

int minDistance(char* word1, char* word2) {
    int maxlen1 = strlen(word1);
    int maxlen2 = strlen(word2);
    int **cache = malloc (sizeof(int*)*(maxlen1+1));

    for(int i=0;i<=maxlen1;i++)
    {
        cache[i] = malloc(sizeof(int)*(maxlen2+1));
    }

    for(int len1=0;len1<=maxlen1;len1++)
    {
        for(int len2=0;len2<=maxlen2;len2++)
        {
            if(len1 == 0)
            {
                cache[len1][len2] = len2;    // add len2 char to word1
                continue;
            }
            if(len2 == 0)
            {
                cache[len1][len2] = len1;    // add len1 char to word2
                continue;
            }

            if(word1[len1-1] == word2[len2-1])
            {
                cache[len1][len2] = cache[len1-1][len2-1];
                continue;
            }

            cache[len1][len2] = min3(
                cache[len1-1][len2-1],    // case1: replace
                cache[len1][len2-1],      // case2: insert
                cache[len1-1][len2]       // case3: remove
            ) + 1;
        }
    }    
    int result = cache[maxlen1][maxlen2];
    for(int i=0;i<=maxlen1;i++)
    {
        free(cache[i]);
    }
    free(cache);

    return result;    
}