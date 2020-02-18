/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        // prefix sum
        vector<int> prefixSum(nums.size()+1);
        prefixSum[0] = 0;  

        for (int i = 0; i < nums.size(); ++i)
        {
            prefixSum[i+1] = prefixSum[i] + nums[i]; 
        }
        int res = 0;
        for (int i = 1; i < nums.size() + 1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if ((prefixSum[i] - prefixSum[j]) == k) ++res; 
            }
        }
        
        return res; 
    }
};
// @lc code=end

