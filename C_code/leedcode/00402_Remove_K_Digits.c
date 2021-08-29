#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*402. Remove K Digits
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/

char * removeKdigits(char * num, int k);

void main()
{
    printf("woody\n");

    return; 
}


char * removeKdigits(char * num, int k)
{

}



char * removeKdigits_FS(char * num, int k)
{   
    /*
    Runtime: 0 ms, faster than 100.00% of C online submissions for Remove K Digits.
    Memory Usage: 5.8 MB, less than 92.45% of C online submissions for Remove K Digits.
    Next challenges:
    */
    //greedy algorithm
    //num = "1432219", k = 3
    int len = strlen(num);
    int re = 0;
    int i = 0, j = 0;

    if(strlen(num) == k)
        return "0";

    /*
    for(int t=1;t<=k;t++)
    {
        for(int i=0;i<strlen(num);i++)
        {
            if(num[i]>num[i+1])
            {
                for(int j=i;j<strlen(num);j++) 
                    num[j] = num[j+1];
                break;
            }
        }
    }
    */

    j = 0;
    for(i=0;i<=len;i++)
    {
        while(j>0 && k>0 && num[i]<num[j-1])
        {
            j--;
            k--;
        }
        num[j] = num[i];
        j++;
    }

    //remove 0;  "0200" -> "200"
    i = 0;
    while(num[i] == '0')
    {
        i++;
    }
        
    if(i == strlen(num))
        return "0";

    re = strlen(num);

    for(j=0;j<=re-i;j++)
        num[j] = num[j+i];

    return num;

}


/*https://qiita.com/vc7/items/5d149f007fbae2e38c56
核心是 Greedy ，分析範例 1432219, k = 3 之後，可以推測出核心的演算法是：

從最高位開始走訪， 因為我們要取最小值（題目要求） ，所以只要高一位數字比自己還要大，如果還可以移除 (k > 0) 我們就移除高一位的數字
例如走到 143 ，比起 14 我們更希望是 13 我們把 4 移除後加上 3 ，所以這個步驟的結果是 13 。

test case 1
接著用這個核心演算法來看比較特殊的 test case : 1230, k = 3 ，解為 0

這是一個一路升冪，只有最後一個降到 0 的一個數列。

一路會走到最後一個 0 ，一位一路上都沒有符合「高一位比自己大」的條件
1230 - 123 和 120 比，我們比較想要 120 ，所以我們移除 3 ， k - 1 之後剩下 2
120 - 12 和 10 比，我們比較想要 120 ，所以我們移除 2 ， k - 1 之後剩下 1
10 - 1 和 0 比，我們比較想要 0 ，所以我們移除 1 ， k - 1 之後剩下 0
結果為 0
test case 2 - 無降冪
111111, k = 3 解應為 111

但是這個測試案例就算走完整個字串還是無法扣掉，因此我們要加上一個步驟：

當走訪完字串 k 卻沒有為 0 的話，就把最後的 k (剩餘值) 位都移除掉
因此 111111 移除最後的 3 位就是 111

test case 3 - 高位數有 0
100200, k = 1 解應為 200

走完核心演算法之後，會剩下 00200 ，而題目並不希望回傳的答案裡面會有高位數的 0 (leading zeros)

所以為了處理這個情況，在回傳之前，就必須再加上這個步驟

如果 num[0] 的內容是 0 就移除他，移除到 num[0] 不是 0 或是 num 為空為止
統整演算法
這題的思考步驟我自己是覺得有點複雜，需要考慮的邊界案例也比較多，在這邊來統整整個流程要做哪些事情。

先導處理 - 如果 k 的初始值大於 num 的長度的話必定全部扣完，因此直接回傳 "0" 。
核心 Greedy - 逐位走訪，只要高一位數字比自己還要大，如果還可以移除 (k > 0) 我們就移除高一位的數字
k 有剩餘的話，扣除最後位數
移除 leading zeros
*/