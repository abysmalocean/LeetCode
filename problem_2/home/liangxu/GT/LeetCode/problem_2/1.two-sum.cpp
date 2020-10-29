/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        if (nums.size() < 2) return {-1, -1}; 
        unordered_map<int, int> map; 
        // first pass of the nums array
        for (int i = 0; i < nums.size(); ++i)
        {
            map[target - nums[i]] = i; 
        }
        // second pass of the nums array
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.count(nums[i]) > 0 && map[nums[i]] != i)
            {
                return {map[nums[i]], i}; 
            }
        }

        return {-1, -1};         
    }
};
// @lc code=end

