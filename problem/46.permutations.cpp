/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {

void permuteDFS(vector<vector<int>>& res,  vector<int>& nums, int level)
{
    if (level == nums.size() - 1)
    {
        res.push_back(nums); 
        return; 
    }

    for (int i = level; i < nums.size(); ++i)
    {
        swap(nums[level], nums[i]); 
        permuteDFS(res, nums, level + 1); 
        swap(nums[level], nums[i]); 
    }
}

/*
Always get the new number to the new postion. 
Time O(n!)
Space O(n) DFS, stack. did not count the output array. 
*/

public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res; 
        permuteDFS(res, nums, 0); 
        return res; 
    }
};
// @lc code=end

