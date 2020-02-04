# 33 Minimum Path Sum

## Description

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

## Initial Idea

This is a similar question with the 32. Just a 2D DP, with forward filling. 

Table[0][0] = grid[0][0];
first row and first column should only have one path in this problem. 

Table[i][j] = min(Table[i-1][j], Table[i][j-1]) + grid[i][j]; 


## Code

```cpp
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
```

## Analysis

Time O(n^2) n is the length of grid 
Space O(n^2): could be optimized to O(n) only using a single row or column. 