/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int result = 0; 
        for (int i = 0; i < height.size(); ++i)
        {
            for (int j = height.size() - 1; j > i; --j)
            {
                int water = min(height[i], height[j]) * (j - i); 
                result = max(result, water); 
            }
        }

        return result; 
        
    }
};
// @lc code=end

