#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
 
/*69. Sqrt(x)
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

 

Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 */


int mySqrt(int x){
	if(x==0)return 0;
	if(x==1)return 1;
    double l=0,r=x,temp;
    while((int)r-(int)l!=0){
        temp=(r+l)/2;
        if(temp*temp>x){
            r=temp;            
        }
        else if(temp*temp<x){
            l=temp;           
        }
        else{
            return temp;
        }
    }
    return (int)temp;
}


//=================================================================================================
typedef union {
    float value;
    uint32_t v_int;
} ieee_float_shape_type;

/* Get a 32 bit int from a float. */
#define EXTRACT_WORDS(ix0, d)        \
    do {                             \
        ieee_float_shape_type ew_u;  \
        ew_u.value = (d);            \
        (ix0) = ew_u.v_int;          \
    } while (0)

int mySqrt(int n)
{ 
    int32_t sign = 0x80000000;
    int32_t ix0, m, i;

    float x = n;
    EXTRACT_WORDS(ix0, x);
    
    /* take care of zero */
    if (ix0 <= 0) {
        if ((ix0 & (~sign)) == 0)
            return x; /* sqrt(+-0) = +-0 */
        if (ix0 < 0)
            return (x - x) / (x - x); /* sqrt(-ve) = sNaN */
    }

    /* normalize x */
    m = (ix0 >> 23);
    if (m == 0) { /* subnormal x */
        for (i = 0; (ix0 & 0x00800000) == 0; i++)
            ix0 <<= 1;
        m -= i - 1;
    }
    m -= 127; /* unbias exponent */
    ix0 = (ix0 & 0x007fffff) | 0x00800000;
    if (m & 1) /* odd m, double x to make it even */
        ix0 += ix0;
    m >>= 1; /* m = [m/2] */
     
    /* binary search 'm' */
    unsigned int head = 1 << m;       // 2^m
    unsigned int tail = 1 << (m + 1);  // 2^(m+1)
    unsigned int mid = (head + tail) >> 1; // same as (2^m + 2^(m+1)) / 2
    while (1) {
        if (n > (mid + 1) * (mid + 1)) {
            head = mid; 
            mid = (head + tail) >> 1;
        } else if(n < mid * mid) {
            tail = mid; 
            mid = (head + tail) >> 1;
        } else
            break;
    }

    return mid;
}