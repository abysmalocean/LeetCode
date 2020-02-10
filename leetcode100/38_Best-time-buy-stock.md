# Best time to Buy Stock

# Best time to Buy Stock I 

### Description

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

### Idea

One of the question for my onsite interview. 
The key part is looking for the time to sell the stock. So, think if you are at pos i, what is the best time to buy or sell the stock. 

#### Method 1

At pos i is a selling point, so we need to know the best time to buy the stock. The best time is the max point before this i. So we need to keep a max value. MaxV = max(maxV, values[i]); 

#### Method 2

The pose i is the buying point, so we need to know the best time to sell the stock. So we need to know the min pos in [i+1, end]. In this case, we need to reverse scan the array, and keep a min value all the time. 

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() <= 1) return 0; 
        int buy = prices[0]; 
        int res = 0; 
        for(int i = 0; i < prices.size(); ++i)
        {
            res = max(res, prices[i] - buy); 
            buy = min(prices[i], buy); 
        }
        return res; 
        
    }
};
```

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() <= 1) return 0; 
        int sell = prices[prices.size() -1]; 
        int res = 0; 
        for (int i = prices.size()-1; i >= 0; --i)
        {
            sell = max(sell, prices[i]); 
            res = max(res, sell - prices[i]); 
        }

        return res; 
        
    }
};
```


### Analysis
Time O(n)
Space o(1)


## Best time to Buy Stock II

### Description

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

### Idea

Integration method, keep track the area under the positive curve. 
Because we can buy and sell the stock anytime, without any limitation. So, we could sell it when every we are making a little. And but it again. And we are accumulate this value. When every we are making a little bit money, we sell it. 

**Dynamic Programming**
we could use the dynamic programming. table[i] is the max money you can make for this point. 
table[i] = table[i-1]; 
table[i] = max(table[i], table[j] + value[i] - value[j]);


this is O(n^2) method
space O(n);

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() <= 1) return 0;
        int value = prices[0]; 
        int maxV = 0; 

        for (int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] > value)
            {
                maxV += prices[i] - value; 
            }
            value = prices[i]; 
        }
        return maxV; 
        
    }
};
```

### Analysis
Time O(n)
Space o(1)

