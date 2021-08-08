#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: n = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Constraints:

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n
*/

int findJudge(int n, int** trust, int trustSize, int* trustColSize);

void main()
{
    printf("woody\n");

    return; 
}

struct Towmtrust
{
    int trust;
    int trusted;
};
int findJudge(int n, int** trust, int trustSize, int* trustColSize)
{
    /*
    Runtime: 136 ms, faster than 96.77% of C online submissions for Find the Town Judge.
    Memory Usage: 16.5 MB, less than 8.06% of C online submissions for Find the Town Judge.
    */
    struct Towmtrust town_trust[1001];
    int i = 0, j = 0;
    int temp = 0;

    for(i=1;i<=n;i++)
    {
        town_trust[i].trust = 0;
        town_trust[i].trusted = 0;
    }

    for(i=0;i<trustSize;i++)
    {
        temp = trust[i][1];
        town_trust[temp].trusted++;
        temp = trust[i][0];
        town_trust[temp].trust++;
    }


    for(i=1;i<=n;i++)
    {
        if( n-1 == town_trust[i].trusted && 0 == town_trust[i].trust)
        {
            return i;
        }
    }

    return -1;
}

int findJudge_hu(int n, int** trust, int trustSize, int* trustColSize)
{
    /*
    Runtime: 160 ms, faster than 16.13% of C online submissions for Find the Town Judge.
    Memory Usage: 16.5 MB, less than 32.26% of C online submissions for Find the Town Judge.
    Next challenges:
    */
    int i = 0, j = 0;
    int town_trust[1001] = {0};
    int temp = 0;
  

    for(i=0;i<trustSize;i++)
    {
        temp = trust[i][1];
        town_trust[temp]++;
    }

    for(i=1;i<=n;i++)
    {
        if(town_trust[i] == n-1)
        {
            for(j=0;j<trustSize;j++)
            {
                if(trust[j][0] == i)
                    return -1;
            }
            return i;
        }
    }

    return -1;
}