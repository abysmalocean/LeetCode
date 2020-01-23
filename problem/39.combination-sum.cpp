/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
private: 

    void combinationSumDFS(const vector<int>& candidates, int sum, 
                          vector<vector<int>>& res, vector<int>& current, int level)
    {
        if(sum == 0) 
        {
            if (current.size() != 0)
            {
                res.push_back(current); 
            } 
            return;

        } else if(sum < 0 )
        {
            return; 
        }

        for (int i = level; i < candidates.size(); ++i)
        {
            current.push_back(candidates[i]); 
            combinationSumDFS(candidates, sum - candidates[i], res, current, i); 
            current.pop_back(); 
        }

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res; 
        vector<int> current;
        combinationSumDFS(candidates, target, res, current, 0); 
        return res;         
    }
};
// @lc code=end

