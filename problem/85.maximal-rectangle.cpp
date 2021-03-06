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
        if (m == 0 ) return 0;
        int n = matrix[0].size(); 
        if (n == 0) return 0; 

        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0)); 

        for (int row = 1; row < m+1; ++row)
        {
            for (int col = 1; col < n+1; ++col)
            {
                if (matrix[row - 1][col -1] == '1')
                {
                    table[row][col] = table[row][col - 1] + matrix[row - 1][col - 1] - '0'; 
                }
            }
        } 

        int res = 0; 
        for (int row = 1; row < m+1; ++row)
        {
            for (int col = 1; col < n+1; ++col)
            {
                int height = 0, width = table[row][col]; 
                while(table[row - height][col] != 0)
                {
                    width = min(width, table[row - height][col]); 
                    res   = max(width * (height + 1), res); 
                    ++height;
                } 
            }
        }

        return res; 
        
    }
};
// @lc code=end

