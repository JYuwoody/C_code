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

/*322. Coin Change
00322_Coin_Change.c
Solved
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/



// Runtime: 35 ms, Beats:26.67 %
// Memory: 10.26 MB, Beats: 23.51%
int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc(sizeof(int) * (amount + 1));
    int result = 0;

    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i) {
                dp[i] = fmin(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    result = dp[amount] > amount ? -1 : dp[amount];
    free(dp);
    return result;
}

int main() {
    int coins[] = {1, 2, 5};
    int amount = 11;
    int coinsSize = sizeof(coins) / sizeof(coins[0]);
    int result = coinChange(coins, coinsSize, amount);
    printf("Output: %d\n", result);
    return 0;
}


// ---
// python3
// # Runtime: 711ms, Beats: 88.96 %
// # Memory: 17.03MB, Beats: 43.48 %
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # Create a list to store the minimum number of coins needed for each amount
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0  # Base case: 0 coins are needed to make 0 amount
        
        # Iterate through each coin
        for coin in coins:
            # Update dp for each amount from coin to amount
            for x in range(coin, amount + 1):
                dp[x] = min(dp[x], dp[x - coin] + 1)
        
        # If dp[amount] is not infinity, return the minimum number of coins needed,
        # otherwise, return -1 indicating it's not possible to make the amount
        return dp[amount] if dp[amount] != float('inf') else -1