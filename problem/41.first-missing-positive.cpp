/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        // your algorithm should run in O(n) time and uses constant extra space. 
        // we can use the nums as extra space
        if (nums.size() == 0) return 1; 
        int index = 0; 
        while(index < nums.size())
        {
            if(nums[index] > 0 && nums[index] < index + 1 && nums[nums[index] - 1] != nums[index])
            {
                swap(nums[index], nums[nums[index] - 1]); 
            } else
            {
                ++index; 
            }
        }
        int res = 0; 
        for(; res < nums.size(); ++res)
        {
            if (nums[res] != res + 1)
            {
                break; 
            }
        }
        return res + 1; 
    }
};
// @lc code=end

