/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, 
                   vector<string>& wordDict) 
    {
        const int len = s.size(); 
        unordered_set<string> dict; 
        for (string& word : wordDict)
        {
            dict.insert(word); 
        }

        vector<bool> T(len + 1, false); 
        T[0] = true; 
        for (int i = 0; i < len + 1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (T[j] && dict.count(s.substr(j, i - j)))
                {
                    T[i] = true; 
                    break; 
                }
            }
        }
        return T[len]; 
        
    }
};
// @lc code=end

