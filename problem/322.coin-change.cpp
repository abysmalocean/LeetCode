/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
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
// @lc code=end

