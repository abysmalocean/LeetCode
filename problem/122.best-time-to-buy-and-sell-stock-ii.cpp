/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
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
// @lc code=end

