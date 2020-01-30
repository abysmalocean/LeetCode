/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if (nums.size() <= 1) return 0; 

        int level = 0, i = 0; 
        int currentMax = 0; 

        while (i <= currentMax)
        {
            ++level;
            int furthest = currentMax; 
            for (; i <= currentMax; ++i)
            {
                furthest = max(furthest, nums[i] + i); 
            }
            
            currentMax = furthest; 
            if (currentMax >= nums.size() - 1) return level; 
        }

        return -1; 

        
    }
};
// @lc code=end

