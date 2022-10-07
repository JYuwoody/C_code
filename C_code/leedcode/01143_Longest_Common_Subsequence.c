#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
//1143. Longest Common Subsequence
/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.

*/

int longestCommonSubsequence(char * text1, char * text2);
int longestCommonSubsequence_better(char * text1, char * text2);

void main()
{

    return; 
}

int lcs(char * text1, char * text2, int m, int n)
{
    //text1 最後一個字元 1 => 屬於最長的共同子序列
    //                 2 => 不屬於最長的共同子序列

    //text2 最後一個字元 3 => 屬於最長的共同子序列
    //                 4 => 不屬於最長的共同子序列
    int a,b;

    if(m==0 || n==0)
        return 0;

    if(text1[m-1] == text2[n-1])    // 1&3
    {
        return lcs(text1, text2, m-1, n-1) + 1;
    }
    else //2&4
    {
        a = lcs(text1, text2, m-1, n);
        b = lcs(text1, text2, m, n-1);

        return a>b?a:b;
    }
}

int longestCommonSubsequence(char * text1, char * text2)
{
    int text1_len = strlen(text1);
    int text2_len = strlen(text2);
    
    return lcs(text1, text2, text1_len, text2_len);
}
//=====================================================================================
int lcs_better(char * text1, char * text2, int m, int n, int** cache)
{
    //text1 最後一個字元 1 => 屬於最長的共同子序列
    //                 2 => 不屬於最長的共同子序列

    //text2 最後一個字元 3 => 屬於最長的共同子序列
    //                 4 => 不屬於最長的共同子序列
    int a,b;

    if(m==0 || n==0)
        return 0;

    if(cache[m][n] != -1)
    {
        return cache[m][n];
    }

    if(text1[m-1] == text2[n-1])    // 1&3
    {
        return lcs_better(text1, text2, m-1, n-1, cache) + 1;
    }
    else //2&4
    {
        a = lcs_better(text1, text2, m-1, n, cache);
        b = lcs_better(text1, text2, m, n-1, cache);
        if(a>b)
        {
            cache[m][n] = a;
        }
        else
        {
            cache[m][n] = b;
        }
        
    }
    
    return cache[m][n];
}


int longestCommonSubsequence_better(char * text1, char * text2)
{
    int text1_len = strlen(text1);
    int text2_len = strlen(text2);

    // int cache[text1_len+1][text2_len+1]
    int** cache = malloc((text1_len+1)*sizeof(int*));
    int i, j, output;

    for(i=0;i<=text1_len;i++)
    {
        cache[i] = malloc((text2_len+1)*sizeof(int));
    }
    //初始化 代表還沒算過
    for(i=0;i<=text1_len;i++)
    {
        for(j=0;j<=text2_len;j++)
        {
            cache[i][j] = - 1;
        }
    }

    output = lcs_better(text1, text2, text1_len, text2_len, cache);

    for(i=0;i<=text1_len;i++)
    {
        free(cache[i]);
    }
    free(cache);
    
    return output;
}

//=====================================================================================
int longestCommonSubsequence_better2(char * text1, char * text2) //longestCommonSubsequence_better的進化
{
    int text1_len = strlen(text1);
    int text2_len = strlen(text2);
    int m, n, output, a, b;
    int i, j;
    
    // int cache[text1_len+1][text2_len+1]
    int** cache = malloc((text1_len+1)*sizeof(int*));
    for(i=0;i<=text1_len;i++)
    {
        cache[i] = calloc((text2_len+1), sizeof(int));
    }

    for(m=1;m<=text1_len;m++)
    {
        for(n=1;n<=text2_len;n++)
        {
            if(text1[m-1] == text2[n-1])    // 1&3
            {
                cache[m][n] = cache[m-1][n-1] + 1;
            } 
            else if(cache[m-1][n] > cache[m][n-1]) //2&4
            {
                cache[m][n] = cache[m-1][n];
            }
            else
            {
                cache[m][n] = cache[m][n-1];
            }
        }
    }
    output = cache[text1_len][text2_len];
    for(i=0;i<=text1_len;i++)
    {
        free(cache[i]);
    }
    free(cache);
    
    return output;
}

//=====================================================================================
