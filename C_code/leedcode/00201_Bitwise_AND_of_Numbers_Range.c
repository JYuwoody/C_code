#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*201. Bitwise AND of Numbers Range
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/

int rangeBitwiseAnd(int m, int n);

void main()
{



    return; 
}

int rangeBitwiseAnd(int m, int n)
{
    int i = 0;

    while(m != n)
    {
        m = m >> 1;
        n = n >> 1;
        i++;
    }

    return m << i;
}














