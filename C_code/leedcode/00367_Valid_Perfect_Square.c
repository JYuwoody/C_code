#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*367. Valid Perfect Square
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
 

Constraints:

1 <= num <= 2^31 - 1
*/


bool isPerfectSquare(int num);

void main()
{
    printf("woody\n");

    return; 
}

bool isPerfectSquare(int num)
{
    int left = 1, right = INT_MAX, target = num;
    long long mid = 0;

    while(left < right)
    {
        mid = left + (right - left) / 2;

        if( mid*mid == target )
            return true;

        if( mid*mid < target)
            left = mid + 1;
        else    
            right = mid;
    }
    
    return false;
}