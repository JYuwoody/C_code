#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
*/


bool backspaceCompare(char * S, char * T);
void getoutput(char *A, char* tA);

char* batter_process(char* str);
bool batter_backspaceCompare(char * S, char * T);

void main()
{   
    //char *S = "ab#c";char *T = "ad#c";
    //char *S = "a##c";char *T = "#a#c";
    //char *S = "ab##";char *T = "c#d#";
    //char *S = "a#c";char *T = "b";
    char *S = "bxj##tw";char *T = "bxj###tw";
    


    backspaceCompare(S,T);
    return; 
}
void getoutput(char *A, char* tA)
{
    int i = 0, curr = 0;

    for(i=0;i<strlen(A);i++)
    {
        if('#'==A[i])
        {
            if(curr > 0)
                curr--;
            tA[curr] = 0;
            //printf("tA[%d] = %c \n",curr,tA[curr]);
        
        }
        else
        {
            tA[curr] = A[i];
            curr++;
        }
        
    }
}


bool backspaceCompare(char * S, char * T)
{
    char tS[200] = {0};
    char tT[200] = {0};

    getoutput(S, tS);
    getoutput(T, tT);

    if(0 == strcmp(tS,tT))
    {
        printf("1 tS =%s tT =%s\n",tS,tT);
        return 1;
    }
    printf("0 tS =%s tT =%s\n",tS,tT);
    return 0;
}



//========================================================================
char* batter_process(char* str)
{
    int len_str = strlen(str);
    int j = 0, i =0;
    for(i=0;i<len_str;i++)
    {
        if(str[i] != '#')
        {
            str[j] = str[i];
            j++;
        }
        else
        {
            if(j > 0)
                j--;
            str[j] = 0;
        }
    }
    str[j] = '\0';
    return str;
}
bool batter_backspaceCompare(char * S, char * T)
{
    return strcmp( batter_process(S), batter_process(T)) == 0;
}
//========================================================================