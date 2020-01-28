/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
private: 

void permuteUniqueDFS(set<vector<int>>& res, vector<int>& nums, int level)
{
    if (level == nums.size())
    {
        res.insert(nums); 
        return; 
    }
    for (int i = level; i < nums.size(); ++i)
    {
        if (i != level && nums[i] == nums[level]) continue; 
        swap(nums[i], nums[level]); 
        permuteUniqueDFS(res, nums, level + 1); 
        swap(nums[i], nums[level]);
    }
}

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        // deduplication is a problem
        sort(nums.begin(), nums.end()); 
        //vector<vector<int>> res; 
        set<vector<int>> res; 
        permuteUniqueDFS(res, nums, 0); 

        return vector<vector<int>>(res.begin(), res.end());
        
    }
};
// @lc code=end

