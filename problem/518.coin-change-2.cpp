/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
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
// @lc code=end

