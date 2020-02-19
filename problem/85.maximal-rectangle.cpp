/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m = matrix.size(); 
        int n = matrix[0].size(); 

        vector<vector<int>> table(m + 1, vector<int>(n + 1 , 0)); 

        for (int row = 1; row < m + 1, ++row)
        {
            for (int col = 1; col < n + 1; ++col)
            {
                if (matrix[row-1][col-1] == '1')
                {
                    table[row][col] = table[row][col-1] + 1; 
                } else
                {
                    table[row][col] = table[row][col-1]; 
                }
            }
        } 
        
    }
};
// @lc code=end

