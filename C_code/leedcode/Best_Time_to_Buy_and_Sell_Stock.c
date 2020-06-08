#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
121. Best Time to Buy and Sell Stock
Easy

4832

216

Add to List

Share
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

int maxProfit(int* prices, int pricesSize);
int maxProfit_2(int* prices, int pricesSize);
int main()
{
    int a[6]={7,1,5,3,6,4};
    printf("output = %d\n",maxProfit_2(a,6));
    return 0;
}

int maxProfit(int* prices, int pricesSize)
{
    int max_profits = 0;
    int i,j;

    for(i=0;i<pricesSize-1;i++)
    {
        for(j=i+1;j<pricesSize;j++)
        {
            if(prices[j]-prices[i]>max_profits)
            {
                max_profits = prices[j]-prices[i];
            }
        }
    }


    return max_profits;
}

int maxProfit_2(int* prices, int pricesSize)
{
    int max_profits = 0;
    int min_profits = 99999999;
    int i;

    for(i=0;i<pricesSize;i++)
    {
        if(prices[i]<min_profits)
            min_profits = prices[i];
        if(prices[i]-min_profits > max_profits)
            max_profits = prices[i]-min_profits;
    }


    return max_profits;
}
