/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, int> table; 
        vector<vector<string>> res; 

        for (int i = 0; i < strs.size(); ++i)
        {
            string tmp = strs[i]; 
            sort(tmp.begin(), tmp.end()); 
            
            if (table.count(tmp) == 0)
            {
                table[tmp] = res.size();
                res.emplace_back(vector<string>());
            }
            res[table[tmp]].emplace_back(strs[i]); 
        }

        return res; 
        
    }
};
// @lc code=end

