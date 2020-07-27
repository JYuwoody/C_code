#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/*00678. Valid Parenthesis String
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
*/

bool checkValidString(char * s);

void main()
{
    return; 
}


//======================================================================
bool checkValidString(char * s)
{
    int mincount = 0; //count '('
    int maxcount = 0; //count '('
    int i = 0;
    for(i=0; i<strlen(s); i++)
    {
        if(s[i] == '(')
        {
            mincount++;
            maxcount++;
        }
        else if(s[i] == ')')
        {
            mincount--;
            maxcount--;
        }
        else if(s[i] == '*')
        {
            mincount--;
            maxcount++;
        }
        if(maxcount < 0)
        {
            return false;
        }
        if(mincount < 0)
        {
            mincount = 0;
        }
    }
    return mincount == 0;
}
//======================================================================
bool checkValidSubString_1(char * s, int i, int j, int **cache)
{
    int k = 0;

    if(i>j) return true;

    if(cache[i][j] != 0)
    {
        if(cache[i][j] == 1)
            return true;
        if(cache[i][j] == -1)
            return false;
    }

    if((s[i] == ')'))
        return false;
    else if(s[i] == '*')
    {
        //space char
        if(checkValidSubString(s, i+1, j, cache))
        {
            cache[i][j] = 1;
            return true;
        }
    }
    
    for(k=i+1;k<=j;k++)
    {
        if(s[k] == ')' || s[k] == '*')
        {
            if( checkValidSubString(s, i+1, k-1, cache) && checkValidSubString(s, k+1, j, cache) )
            {
                cache[i][j] = 1;
                return true;
            }
                
        }
    }
    cache[i][j] = -1;
    return false;
}

bool checkValidString_1(char * s)
{
    int len = strlen(s), i = 0;
    bool output;
    //cache[len][len]
    int **cache = malloc(sizeof(int*)*len); //0:not yet 1: done than true -1:done than false
    for(i=0;i<len;i++)
    {
        cache[i] = calloc(len,sizeof(int));
    }
    output = checkValidSubString(s, 0 ,strlen(s)-1, cache);
    for(i=0;i<len;i++)
    {
        free(cache[i]);
    }
    free(cache);
    return output;
}
//======================================================================

