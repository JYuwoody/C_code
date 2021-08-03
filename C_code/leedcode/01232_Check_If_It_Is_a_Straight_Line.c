#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*1232. Check If It Is a Straight Line
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize);

void main()
{
    printf("woody\n");

    return; 
}

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    //Triangle magnification concept
    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];
    int x2 = coordinates[1][0];
    int y2 = coordinates[1][1];
    int x3 = 0;
    int y3 = 0;
    int dx = x1-x2, dy = y1-y2, i = 0;

    for(i=2;i<coordinatesSize;i++)
    {
        x3 = coordinates[i][0];
        y3 = coordinates[i][1];
        if( dy*(x3-x1) != dx*(y3-y1) )
            return false;
    }

    return true;
}