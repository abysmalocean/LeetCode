/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
private: 

void permuteUniqueDFS(vector<vector<int>>& res, vector<int>& nums, int level)
{
    if (level == nums.size() - 1)
    {
        res.push_back(nums); 
        return; 
    }
    
    unordered_set<int> st; 

    permuteUniqueDFS(res, nums, level + 1); 
    sort(nums.begin() + level + 1, nums.end()); 
    st.insert(nums[level]); 
    
    for (int i = level + 1; i < nums.size(); ++i)
    {
        cout << nums[i] << "  "; 
    }
    cout << endl; 

    for (int i = level + 1; i < nums.size(); ++i)
    {
        if (nums[i] != nums[i-1])
        {
            if (st.count(nums[i] != 0)) cout << nums[i] << " have problem" << endl; 
            st.insert(nums[i]); 
            swap(nums[i], nums[level]); 
            permuteUniqueDFS(res, nums, level + 1); 
            swap(nums[i], nums[level]); 
        }
    }

}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        // deduplication is a problem
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> res; 
        permuteUniqueDFS(res, nums, 0); 

        return res;
        
    }
};
// @lc code=end

