/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> dic(wordDict.begin(), wordDict.end());

        vector<bool> table(s.length()+1, false);

        table[0] = true;  
        for (int i = 1; i < s.length()+1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (table[j] == true)
                {
                    string tmp = s.substr(j , i - j);
                    if (dic.count(tmp) > 0)
                    {
                        table[i] = true; 
                        break; 
                    }
                }
            }
            
        }

        return table.back(); 
        
    }
};
// @lc code=end

