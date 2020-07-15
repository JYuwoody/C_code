#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

int lastStoneWeight(int* stones, int stonesSize);
int lastStoneWeight_better(int* stones, int stonesSize);

void main()
{
    int stones[6] = {2,7,4,1,8,1};
    int stonesSize = 6;

    lastStoneWeight_better( stones, stonesSize);

    return; 
}

int lastStoneWeight(int* stones, int stonesSize)
{
    int i = 0, j = 0;
    int max_first = 0, max_second = 0;  //index
    int a[31] ={0};

    if(stonesSize==1)
        return stones[0];



    for(i=0;i<stonesSize;i++)
    {
        a[i] = stones[i]; 
    }

    max_first = stonesSize;
    max_second = stonesSize;

    for(i=0; i<stonesSize;i++)
    {
        //find first max and second max
        for(j=0;j<stonesSize;j++)
        {
            if(a[j]==0)
                continue;
            if (a[j]>=a[max_second])
            {
                if (a[j]>=a[max_first])
                {
                    max_second = max_first;
                    max_first = j;
                }
                else
                {
                    max_second = j;
                }
            }
        }

        //caculate
        //printf("a[max_first]=%d a[max_second]=%d\n", a[max_first], a[max_second]);
        a[max_first] = a[max_first] - a[max_second];
        //printf("stones[max_first]=%d\n",stones[max_first]);
        if(a[max_second] == 0)
        {
            return a[max_first];
        }
        a[max_second] = 0;
        max_first = max_second;

        /*
        int k=0;
        for(k=0;k<stonesSize;k++)
        {
            printf("%d ",a[k]);
        }
        printf("\n");
        */
    }
    return 0;
}

//=====================================================================
int extractMax(int* stones, int stonesSize)
{
    int max = stones[0];
    int i = 0;
    for(i=1;i<stonesSize;i++)
    {
        if(stones[i] > max)
        {
            //find max vaule
            max = stones[i];
        }
    }

    for(i=0;i<stonesSize;i++)
    {
        if(stones[i] == max)
        {
            //set zero
            stones[i] = 0;
            break;
        }
    }

    return max;
}

void insert(int* stones, int stonesSize, int value)
{
    int i = 0;
    for(i=0;i<stonesSize;i++)
    {
        if(stones[i] == 0)
        {
            stones[i] = value;
            return;
        }
    }
    return;
}

int lastStoneWeight_better(int* stones, int stonesSize)
{
    int y,x,i;

    if(stonesSize==1)
        return stones[0];
    

    for(i=0;i<stonesSize;i++)
    {
        y = extractMax(stones, stonesSize); //find first max
        x = extractMax(stones, stonesSize); //find second max
        if(x==0)
            return y;

        if(x != y)
            insert(stones, stonesSize, y-x);
    }

    return 0;
}
//=====================================================================