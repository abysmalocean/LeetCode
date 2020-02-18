# Coin Change

## Coin change 1

### Description

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.

### Idea

Define a table with size = amount + 1; the number in the table is the minimum number can get this amount. 

Table[i] = for all coin MIN(table[i - coin] + 1); 

### Code 

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> table(amount + 1, INT_MAX);
        table[0] = 0;
        for (int i = 1; i < amount+1; ++i)
        {
            for (auto& coin : coins)
            {
                if ((i - coin) >= 0)
                {
                    table[i] = table[i-coin] == INT_MAX ? table[i] : min(table[i], table[i-coin] + 1); 
                }
            }
        }
        return table[amount] == INT_MAX? -1 : table[amount]; 
        
    }
};
```

## Coin Change 2


### Description

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
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
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer

### idea

This question need to put additional attention. 

first, the duplication problem will be counted if you are using the method as coin change 1. 

However, when we define the number in the table as the number of ways to construct this amount by using [x ,y ] coins. 

When we count the table[i] += table[i - coin]; 

### Code

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<int> table(amount+1, 0); 
        table[0] = 1; 
        
        for (auto& coin : coins)
        {
            for (int i = coin; i < amount+1; ++i)
            {
                table[i] += table[i - coin];    
            }
        }
        return table.back(); 
    }
};

```

## Analysis: 

Both of the question
Time: O(amount * sizeof(coins)); 
space: O(amount)