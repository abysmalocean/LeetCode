/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        // do not need to open additional space, just mark the true as -
        //if (nums.size() <= 1) return true; 
        //vector<int> table(nums); 
        int farest = 0; 

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i <= farest && nums[i] + i > farest)
            {
                farest = nums[i]+i;
                //if (farest >= nums.size() - 1) return true;  
            } else if (i > farest)
            {
                return false; 
            }
            
        }

        return farest >= nums.size() - 1; 


    }
};
// @lc code=end

