/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int row = word1.length(); 
        int col = word2.length(); 

        vector<vector<int>> table(row+1, vector<int>(col+1, 0)); 

        for (int i = 0; i < row + 1; ++i)
        {
            for (int j = 0; j < col + 1; ++j)
            {
                if (i == 0)
                {
                    table[i][j] = j; 
                }else if (j == 0)
                {
                    table[i][j] = i;
                } else
                {   
                    int replace = word1[i-1] == word2[j-1] ? 0 : 1; 
                    replace += table[i-1][j-1];  
                    
                    int remove_insert = min(table[i-1][j], table[i][j-1]) + 1;
                    table[i][j] = min(remove_insert, replace); 
                }
            }
        }
        return table[row][col]; 
        
    }
};
// @lc code=end

