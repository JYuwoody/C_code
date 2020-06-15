#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*
Given an array of strings, group anagrams together.
Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
All inputs will be in lowercase.
The order of your output does not matter.
*/

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes); //woody gcc ok leetcode no
char *** groupAnagrams_notme(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes); //other gcc no leetcode ko
int compare(const void *a, const void *b);



void main()
{
    char *s;
    s = "eat";
    //char ** strs = {"eat","tea","tan","ate","nat","bat"};    
    char * strs[] = {"eat","tea","tan","ate","nat","bat"};
    int* returnColumnSizes[] = {};
    int *returnSize;
    char *** A;

    A = groupAnagrams(strs, 6, returnSize, returnColumnSizes);

    return; 
}

int compare(const void *a, const void *b)//這函式是 qsort 所需的比較函式
{
      int c = *(int *)a;
      int d = *(int *)b;
      // if(c < d) {return -1;}               //傳回 -1 代表 a < b
      //else if (c == d) {return 0;}      //傳回   0 代表 a = b
      //else return 1;                          //傳回  1 代表 a>b
      if(c > d)
        return 1; 
    return 0; 
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    int stringsum[strsSize];
    int i = 0, j = 0,r = 0,c = 0;
    int temp[strsSize];
    returnSize = (int *) malloc(sizeof(int));
    //Sum each char number of string.
    for(i=0;i<strsSize;i++)
    {
        stringsum[i] = 0;
        for(j=0;j<(int)strlen(strs[i]);j++)
        {
            stringsum[i] +=(int) *(*(strs+i)+j);
        }
        //printf("stringsum[%d] = %d \n",i,stringsum[i]); 
        temp[i] = stringsum[i];
    }

    //Get returnSize
    for(i=0;i<strsSize;i++)
    {
        for(j=0;j<strsSize;j++)
        {
            if(0 == temp[i])
                break;
            if(i != j)
            {
                if(temp[i] == temp[j])
                {
                    temp[j] = 0;
                }
            }
        }

        if(0 != temp[i])
        {
            *returnSize = *returnSize + 1;
        }
    }
    //Great returnColumnSizes array
    qsort((void *)temp,strsSize, sizeof(temp[0]),compare); //都是從小到大排序
    returnColumnSizes[0] = (int *)malloc(sizeof(int )*strsSize); //*returnColumnSizes = malloc(sizeof(int)*(strsSize));
    char *** returnResult = malloc(sizeof(char**)*(*returnSize));
    r = 0;
    for(i=0;i<strsSize;i++)
    {
        if(0 == temp[i])
            continue;
        c = 0;
        
        for(j=0;j<strsSize;j++)
        {
            if(temp[i] == stringsum[j])
            {
                returnResult[r] = (char **)realloc(returnResult[r],sizeof(char*)*(c+1));
                returnResult[r][c] = (char *)malloc(sizeof(char)*(strlen((strs[j]))+1));
                strcpy(returnResult[r][c],strs[j]);
                //printf("returnResult[%d][%d]=%s\n",r,c,*returnResult[r][c]);
                printf("returnResult[%d][%d]=%s\n",r,c,returnResult[r][c]);
                c++;
            }
            
        }
        returnColumnSizes[0][r] = c;//*(*(returnColumnSizes)+r) = c;
        r++;
    }
    /*
    printf("returnResult[0][0]=%s\n",returnResult[0][0]);
    printf("returnResult[1][0]=%s\n",returnResult[1][0]);
    printf("returnResult[1][1]=%s\n",returnResult[1][1]);
    printf("returnResult[2][0]=%s\n",returnResult[2][0]);
    printf("returnResult[2][1]=%s\n",returnResult[2][1]);
    printf("returnResult[2][2]=%s\n",returnResult[2][2]);
    free(returnSize);
    */
    return returnResult;
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



int cmp(const void *a,const void *b)
{
     return(*(char *)a-*(char *)b);
}


char *** groupAnagrams_notme(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int i;
    char ** strsCpy = (char **)malloc(sizeof(char *)*strsSize);
//1、先將每個單詞按字母順序排序存放在一個新的空間strsCpy裡；
    for(i=0; i<strsSize; i++){
        strsCpy[i] = (char *)malloc(sizeof(char)*100);
        strcpy(strsCpy[i],strs[i]);
        qsort(strsCpy[i],strlen(strsCpy[i]),sizeof(strsCpy[i][0]),cmp);
    }
//2、mask指定為字母異位詞，初始值賦為-1；
    int mask[strsSize];
    memset(mask,-1,sizeof(mask));
    
    char *** ret = (char ***)malloc(sizeof(char **)*strsSize);
    returnColumnSizes[0] = (int *)malloc(sizeof(int )*strsSize);

    *returnSize = 0;

    int k,j;
//3、legnth記錄記錄ret中每一行單詞的個數，同returnColumnSizes [0]，初始值0；
    int length[strsSize];
    memset(length,0,sizeof(length));

    for(i=0; i<strsSize; i++){
        k=0;
        while(mask[k] >= 0){
            
            if(0 == strcmp(strsCpy[i],strsCpy[mask[k]])){     
                //printf("[%d][%d] ",k,length[k]);

                ret[k][length[k]] = (char *)malloc(sizeof(char)*(strlen(strs[i])+1));
                strcpy(ret[k][length[k]],strs[i]);
                //printf("%s\n",ret[k][length[k]]);
                length[k]++;
                break;
            }
            k++;
        }
        if(mask[k] < 0){
            mask[k]=i;
            //printf("[%d][0] ",k);
            ret[k] = (char **)malloc(sizeof(char *)*strsSize);
            ret[k][0] = (char *)malloc(sizeof(char)*(strlen(strs[i])+1));
            strcpy(ret[k][0],strs[i]);
            //printf("%s\n",ret[k][0]);
            length[k]++;
            (*returnSize)++;
            
        }

    }
    for(j=0; j<strsSize; j++)
        returnColumnSizes[0][j] = length[j];
    //printf("%d",*returnSize);
    return ret;
}
