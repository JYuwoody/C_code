#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/*387. First Unique Character in a String
Given a string s, return the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/

int firstUniqChar(char * s);

void main()
{


    return; 
}


int firstUniqChar(char * s)
{
    int sSize = strlen(s);
    int i, j;
    int isUnique = 1;

    for(i=0;i<sSize;i++)
    {
        isUnique = 1;
        if(s[i] == '-') continue;

        for(j=0;j<sSize;j++)
        {
            if(i != j)
            {
                if(s[i] == s[j])
                {
                    isUnique = 0;
                    s[j] = '-';
                }
            }
        }
        if(isUnique)
        {
            return i;
        }
    }

    return -1;
}

int firstUniqChar_2(char * s)
{
    int sSize = strlen(s);
    int i, j;
    int isUnique = 1;

    for(i=0;i<sSize;i++)
    {
        isUnique = 1;

        for(j=0;j<sSize;j++)
        {
            if(s[i] == s[j] && i != j)
            {
                isUnique = 0;
                break;
            }
        }
        if(isUnique)
        {
            return i;
        }
    }

    return -1;
}

int firstUniqChar_3(char * s)
{
    int sSize = strlen(s);
    int i;
    int isUnique = 1;
    int count[30] = {0};

    for(i=0;i<sSize;i++)
    {
        count[s[i]-'a']++;
    }

    for(i=0;i<sSize;i++)
    {
        if(count[s[i]-'a'] == 1)
            return i;
    }

    return -1;
}