/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
private: 
    void combinationSumDFS(const vector<int>& candidates, int target,
                           vector<vector<int>>& res, 
                           vector<int>& current, int level)
    {
        if (target == 0 )
        {
            res.push_back(current); 
            return; 
        } else if (target < 0)
        {
            return; 
        }

        for (int i = level; i < candidates.size(); ++i)
        {
            int nextIndex = i + 1; 
            
            while(nextIndex < candidates.size() && candidates[i] == candidates[nextIndex])
            {
                ++nextIndex; 
            }

            current.push_back(candidates[i]); 
            combinationSumDFS(candidates, target - candidates[i], res, current, i+1);
            current.pop_back(); 
            i = nextIndex-1;
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res; 
        vector<int> current; 
        sort(candidates.begin(), candidates.end());
        combinationSumDFS(candidates, target, res, current, 0); 
        return res; 
        
    }
};
// @lc code=end

