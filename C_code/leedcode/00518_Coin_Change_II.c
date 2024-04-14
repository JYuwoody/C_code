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

/*518. Coin Change II
00518_Coin_Change_II.c
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/



// Runtime:  4ms, Beats: 76.19 %
// Memory: 5.85 MB, Beats: 38.10 %
// catch = [0]*(finalAmount+1)
// catch[0] = 1
// for coin in coins:
//     for amount in range(coin, finalAmount+1):
//         catch[amount] += catch[amount-coin]
// return catch[finalAmount]


int change(int finalAmount, int* coins, int coinsSize) {
    int i = 0, amount = 0, coin = 0;
    // 使用 calloc((finalAmount+1), sizeof(int)) 初始化的 catch 數組將所有元素初始化為 0
    int* catch =  calloc((finalAmount+1), sizeof(int));
    // 使用 malloc(sizeof(int)*(finalAmount+1)) 初始化的 catch 數組則不會自動初始化為 0 >>>
    // int* catch =  malloc(sizeof(int)*(finalAmount+1));
    // for(i=0;i<=finalAmount;i++)
    //     catch[i] = 0;
    // 使用 malloc(sizeof(int)*(finalAmount+1)) 初始化的 catch 數組則不會自動初始化為 0 <<<

    catch[0] = 1;
    for(i=0;i<coinsSize;i++)
    {
        coin = coins[i];
        for(amount=coin;amount<=finalAmount;amount++)
        {
            catch[amount] += catch[amount-coin];
        }
    }
    return catch[finalAmount];
}


// ---
// python3
// # Runtime:  288 ms, Beats: 44.22 %
// # Memory: 44.02 MB, Beats: 29.05 %
// def change(amount, coins, catch):
//     # amount: 5
//     #         0  1  2
//     #        -3 -2 -1
//     # coins: [1, 2, 5]
//     # coins[-1] = 5
//     # coins[0:2] = [coins[0], coins[1]], get index 0<=x<2
//     # coins[:-1] = [coins[0], coins[1]], Just like removing the last number of an array


//     # [1, 1, 1, 1, 1]
//     # change(5, [1]) == 1
//     # change(5, [1, 2]) = change(5, [1]) + change(5-2, [1, 2])

//     # change(amount, coins) == change(amount, coins[:-1]) + change(amount-coins[-1], coins)
//     if amount == 0: return 1
//     if len(coins) == 0: return 0

//     # amoumt: 5
//     # coins: [1, 2, 5]
//     # key = (amount, *coins)          # (5, 1, 2, 5)
//     key = (amount, tuple(coins))    # (5, (1, 2, 5))

//     if key in catch:
//         return catch[key]

//     result = change(amount, coins[:-1], catch)
//     if amount - coins[-1] >= 0:
//         result += change(amount-coins[-1], coins, catch)

//     catch[key] = result

//     return result

// class Solution:
//     def change(self, amount: int, coins: List[int]) -> int:
//         return change(amount, coins, {})
    

// # Runtime:  127 ms, Beats: 72.02 %
// # Memory: 25.91 MB, Beats: 58.70 %
// def change(amount, length, coins, catch):
//     if amount == 0: return 1
//     if length == 0: return 0

//     key = amount, length

//     if key in catch:
//         return catch[key]

//     result = change(amount, length-1, coins, catch)
//     if amount - coins[length-1] >= 0:
//         result += change(amount-coins[length-1], length, coins, catch)

//     catch[key] = result

//     return result

// class Solution:
//     def change(self, amount: int, coins: List[int]) -> int:
//         return change(amount, len(coins), coins, {})

// # Runtime:  127 ms, Beats: 72.02 %
// # Memory: 25.91 MB, Beats: 58.70 %
// def change(amount, length, coins, catch):
//     if amount == 0: return 1
//     if length == 0: return 0

//     key = amount, length

//     if key in catch:
//         return catch[key]

//     result = change(amount, length-1, coins, catch)
//     if amount - coins[length-1] >= 0:
//         result += change(amount-coins[length-1], length, coins, catch)

//     catch[key] = result

//     return result

// class Solution:
//     def change(self, amount: int, coins: List[int]) -> int:
//         catch[amount][len(coins)]
//         return change(amount, len(coins), coins, catch)


// # Runtime:  346 ms, Beats: 34.32 %
// # Memory: 32.14 MB, Beats: 43.63 %
// class Solution:
//     def change(self, finalAmount: int, coins: List[int]) -> int:
//         catch = [[None]*(len(coins)+1) for i in range(finalAmount+1)]
        
//         for length in range(0, len(coins)+1):
//             for amount in range(0, finalAmount+1):
//                 if amount == 0:
//                     catch[amount][length] = 1
//                     continue
//                 if length == 0 :
//                     catch[amount][length] = 0
//                     continue

//                 result = catch[amount][length-1]

//                 if amount-coins[length-1] >= 0:
//                     result += catch[amount-coins[length-1]][length]

//                 catch[amount][length] = result

//         return catch[finalAmount][len(coins)]
    
// # Runtime:  95 ms, Beats: 84.46 %
// # Memory: 16.66 MB, Beats: 95.02 %
// class Solution:
//     def change(self, finalAmount: int, coins: List[int]) -> int:
//         catch = [0]*(finalAmount+1)
//         catch[0] = 1
//         for coin in coins:
//             for amount in range(coin, finalAmount+1):
//                 catch[amount] += catch[amount-coin]


//         return catch[finalAmount]


