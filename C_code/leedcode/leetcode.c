#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>


char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes);

void main()
{
    char *s;
    s = "eat";
    //char ** strs = {"eat","tea","tan","ate","nat","bat"};    
    char * strs[] = {"eat","tea","tan","ate","nat","bat"};
    int* returnSize;
    int* returnColumnSizes[] = {};

    groupAnagrams(strs, 6, returnSize, returnColumnSizes);

    return; 
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    int stringsum[strsSize];
    int i = 0, j = 0,len = 0;
    int temp[strsSize];
    for(i=0;i<strsSize;i++)
    {
        stringsum[i] = 0;
        temp[i] = 0;
        for(j=0;j<(int)strlen(*(strs+i));j++)
        {
            stringsum[i] +=(int) *(*(strs+i)+j);
        }
        printf("stringsum[%d] = %d \n",i,stringsum[i]); 
    }

}


char *** think_step(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    // strs == ["eat","tea","tan","ate","nat","bat"]
    /*output
    [
        ["ate","eat","tea"],
        ["nat","tan"],
        ["bat"]
    ]
    // strs == ["eat","tea","tan","ate","nat","bat"]
    printf("*strs = %s\n",*strs);  //abc
    printf("**strs = %c\n",**strs); //a
    printf("*(*strs+1) = %c\n",*(*strs+1)); //b
    printf("*(*strs+2) = %c\n",*(*strs+2)); //c
    printf("*(strs+1) = %s\n",*(strs+1));  //tea
    printf("strlen(*strs) = %d \n", (int)strlen(*strs)); //3
    */
    char *** returnResult = malloc(sizeof(char**)*3);
    returnResult[0] = malloc(sizeof(char*)*3);
    returnResult[1] = malloc(sizeof(char*)*2);
    returnResult[2] = malloc(sizeof(char*)*1);

    returnResult[0][0] = malloc(sizeof(char*)*strlen("ate")+1);
    strcpy(returnResult[0][0], "ate");

    returnResult[0][1] = malloc(sizeof(char*)*strlen("eat")+1);
    strcpy(returnResult[0][1], "eat");

    returnResult[0][2] = malloc(sizeof(char*)*strlen("tea")+1);
    strcpy(returnResult[0][2], "tea");

    returnResult[1][0] = malloc(sizeof(char*)*strlen("nat")+1);
    strcpy(returnResult[1][0], "nat");

    returnResult[1][1] = malloc(sizeof(char*)*strlen("tan")+1);
    strcpy(returnResult[1][1], "tan");

    returnResult[2][0] = malloc(sizeof(char*)*strlen("bat")+1);
    strcpy(returnResult[2][0], "bat");

    *returnSize = 3;
    *returnColumnSizes = malloc(sizeof(int)*3);
    (*returnColumnSizes)[0] = 3;
    (*returnColumnSizes)[1] = 2;
    (*returnColumnSizes)[2] = 1;

    return returnResult;

}
