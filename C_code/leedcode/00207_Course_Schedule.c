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

/*207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first 
if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

/*Runtime 51 ms Beats 54.10% Memory 7 MB Beats 99.18%*/
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    /*
    numCourses: 2
    prerequisites: [[0,1], [1,0]]
    prerequisitesSize: 2
    */
    
    int i = 0, j =0;
    int* numPrerequisites;   
    numPrerequisites = malloc(sizeof(int)*numCourses);


    for(i=0;i<numCourses;i++)
        numPrerequisites[i] = 0;

    //numPrerequisites[i] 表示第i號課程還有多少需要先修的課
    for(j=0;j<prerequisitesSize;j++)
    {
        numPrerequisites[prerequisites[j][0]]++;
    }

    while(true)
    {
        for(i=0;i<numCourses;i++)
        {
            if(numPrerequisites[i] == 0)    //表示第i號課程已經沒有需要先修的課了
            {
                numPrerequisites[i] = -1;   //表示已修
                for(j=0;j<prerequisitesSize;j++)
                {
                    if(prerequisites[j][1] == i)
                    {
                        numPrerequisites[prerequisites[j][0]]--;
                    }
                }
            }
        }
        bool isAllFinished = true;
        for(i=0;i<numCourses;i++)
        {
             if(numPrerequisites[i] != -1)
             {
                isAllFinished =false;
             }
        }
        if(isAllFinished)
        {
            return true;
        }

        bool isAnyZero = false;
        for(i=0;i<numCourses;i++)
        {
             if(numPrerequisites[i] == 0)
             {
                isAnyZero =true;
             }
        }
        if(isAnyZero == false)
        {
            return false;
        }

    }
}