#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
//476. Number Complement
/*
Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Constraints:

The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
num >= 1
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
*/

int findComplement(int num);

void main()
{

    return; 
}

int findComplement(int num){
    int output;
    int temp = 0, i = 0, count = 0;;
    int bitHigt = 0x80000000, bitFF = 0xffffffff;

    if(num <0) return 0;

    for(i=31;i>=0;i--)
    {
        if(bitHigt&num)
        {
            count = i;
            break;
        }
        bitHigt = bitHigt >> 1;
    }

    if(count == 0)
        return 0;

    output = ~num;

    temp = 0x1;
    for(i=1;i<=count;i++)
    {
        temp = temp << 1;
        temp = temp | 0x1;
    }
    output = output & temp;

    return output;
}

int findComplement_batter(int num)
{
    int mask = num;
    
    //for 32bit max 16 
    mask |= mask >> 1;
    mask |= mask >> 2;
    mask |= mask >> 4;
    mask |= mask >> 8;
    mask |= mask >> 16;

    return num ^ mask;
}
