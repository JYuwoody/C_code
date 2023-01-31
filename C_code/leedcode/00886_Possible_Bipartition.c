#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

//!
//?
//todo
//@param
//* 

/*00886. Possible Bipartition
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
 

Constraints:

1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= ai < bi <= n
All the pairs of dislikes are unique.
*/

bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize){
}



//----------------------------------------------------------------

//* Runtime 168 ms Beats 97.90% Memory 14.9 MB Beats 96.50%

bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize){
    // N: 4
    // dislike: [[1,2],[1,3],[2,4]]
    // dislikeSize: 3
    if(dislikesSize == 0)
        return true;

    bool isChecked[dislikesSize];
    int label[n+1]; //label[i] is i index in whith group.
                    //label[1] is people
                    //group: -1, 1
    int x = 0;
    int y = 0;

    for(int i=0;i<dislikesSize;i++)
        isChecked[i] = false;


    // init label
    for(int i=0;i<=n;i++)
        label[i] = 0;   // label[i] == 0 not set group

    x = dislikes[0][0];
    y = dislikes[0][1];
    label[x] = -1;
    label[y] = 1;
    isChecked[0] = true;

    while(1)
    {
        bool isUpdated =false;
        for(int i=1;i<dislikesSize;i++)
        {
            if(isChecked[i]==true)
                continue;

            x = dislikes[i][0];
            y = dislikes[i][1];

            
            if(label[x]==0 && label[y]==0)
            {
                //index-x index-y not set group
                continue;
            }
            else if(label[x]!=0 && label[y]!=0)
            {
                //index-x index-y already set group
                if(label[x] == label[y])
                    return false;
                else
                {
                    isChecked[i] = true;
                }
            }
            else if(label[x]!=0 && label[y]==0)
            {
                label[y] = -label[x];
                isChecked[i] = true;
                isUpdated = true;
            }
            else if(label[x]==0 && label[y]!=0)
            {
                label[x] = -label[y];
                isChecked[i] = true;
                isUpdated = true;
            }
        }

        bool isAllChecked =true;
        for(int i=0;i<dislikesSize;i++)
        {
            if(isChecked[i] == false)
            {
                isAllChecked = false;
                break;
            }
        }

        if(isAllChecked == true) return true;
        if(isUpdated == false && isAllChecked == false)
        {
            for(int i=1;i<dislikesSize;i++)
            {
                if(isChecked[i] == false)
                {
                    x = dislikes[i][0];
                    y = dislikes[i][1];
                    label[x] = -1;
                    label[y] = 1;
                    isChecked[i]=true;
                    break;
                }
            }
        }
    }

    return false;
}