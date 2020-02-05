/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size(); 
        int n = obstacleGrid[0].size(); 

        vector<vector<int>> table(m+1, vector<int>(n+1, 0));
        table[0][1] = 1; 

        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                if (obstacleGrid[i-1][j-1] == 0 && table[i - 1][j] < INT_MAX - table[i][j - 1])
                {
                    table[i][j] = table[i-1][j] + table[i][j-1]; 
                }
            }
        } 
        return table[m][n]; 
        
    }
};
// @lc code=end

