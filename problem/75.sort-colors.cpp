/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int red = 0, white = 0, blue = nums.size()-1;
        
        while(white <= blue)
        {
            if (nums[white] == 0)
            {
                swap(nums[red], nums[white]);
                ++white; 
                ++red; 
            } else if(nums[white] == 1)
            {
                ++white; 
            } else if (nums[white] == 2)
            {
                swap(nums[white], nums[blue]); 
                --blue; 
            }
        }
    }
};
// @lc code=end

