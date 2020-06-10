#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/** 49. Group Anagrams
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
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
    /*
    //strs == ["abc","tea","tan","ate","nat","bat"]
    printf("*strs = %s\n",*strs);  //abc
    printf("**strs = %c\n",**strs); //a
    printf("*(*strs+1) = %c\n",*(*strs+1)); //b
    printf("*(*strs+2) = %c\n",*(*strs+2)); //c
    printf("*(strs+1) = %s\n",*(strs+1));  //tea
    printf("strlen(*strs) = %d \n", (int)strlen(*strs)); //3
    */
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
    
    return;

}
