#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/* 771. Jewels and Stones
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0
 

Constraints:

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.
*/


void main()
{

    return; 
}


int numJewelsInStones(char * jewels, char * stones){
    int jewels_len = strlen(jewels);
    int stones_len = strlen(stones);
    int j = 0, s = 0;
    int count = 0;

    for(s=0;s<stones_len;s++)
    {
        for(j=0;j<jewels_len;j++)
        {
            if(stones[s]==jewels[j])
            {
                count++;
                break; 
            }
        }
    }

    return count;
}

//ups memery to reduce j*s
int numJewelsInStones_better(char * jewels, char * stones){
    int jewels_len = strlen(jewels);
    int stones_len = strlen(stones);
    int coutJ[256] = {0};
    int output = 0, i = 0;

    for(i=0;i<jewels_len;i++)
    {
        if(coutJ[jewels[i]] == 0)
        {
            coutJ[jewels[i]]++;
        }
    }

    for(i=0;i<stones_len;i++)
    {
        if(coutJ[stones[i]] == 1)
        {
            output++;
        }
    }

    return output;
}