/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> table(row, vector<int>(col,0));

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (i == 0 && j == 0)
                {
                    table[i][j] = grid[i][j]; 
                } else
                {
                    int down = i - 1 >= 0? table[i-1][j] : INT_MAX;
                    int right = j - 1 >= 0? table[i][j-1] : INT_MAX;
                    table[i][j] = min(down, right) + grid[i][j]; 
                }

                
            }
        }
        /*
        for (auto& eles : table)
        {
            for (auto& ele : eles)
            {
                cout << ele << "  ";

            }
            cout << endl; 
        }
        */

        return table[row-1][col-1]; 

        
    }
};
// @lc code=end

