#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
int isHappy(int n);
int next_n(int n);

int main()
{
    int n = 2;
    printf("%d\n",isHappy(n));

    return 0;
}

int next_n(int n)
{
    int r = 0;
    while(n!=0) 
    {
        int d = n % 10;
        n /= 10;
        r += d*d;
    }
    return r;
}

int isHappy(int n){
    int slow = n;
    int fast = n;
    
    do
    {
        //Floyd Cycle Detection Algorithm https://visualgo.net/en/cyclefinding
        slow = next_n(slow);
        fast = next_n(next_n(fast));
    }while(fast!=slow);
    
    return fast==1; //check fast is repeat or is 1.
}


