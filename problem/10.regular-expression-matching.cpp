/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int col = s.length(); 
        int row = p.length(); 

        vector<vector<bool>> table(row+1, vector<bool>(col+1,false)); 

        table[0][0] = true; 

        for (int i = 1; i < row+1; ++i)
        {
            if(p[i-1] == '*')
            {
                table[i][0] = table[i-2][0]; 
            }

            for (int j = 1; j < col+1; ++j)
            {
                if (p[i-1] == '.')
                {
                    table[i][j] = table[i-1][j-1];

                } else if (p[i-1] == '*')
                {
                    table[i][j] = table[i-2][j];
                    
                    if (p[i-2] == '.' || s[j-1] == p[i-2])
                    {
                        table[i][j] = table[i][j] || table[i][j-1]; 
                    }

                } else if (p[i-1] == s[j-1])
                {
                    table[i][j] = table[i-1][j-1]; 
                }
            }
        }
        return table[row][col]; 
        
    }
};
// @lc code=end

