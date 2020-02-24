# Maximal Rectangle

## Description

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6

## idea

There are several solutions to this problem. 

### DP + scan

First, we can calculate the colum continuos '1's in an row. 

Then, we can scan the whole table by scan the upward. 
the width can be calculated by hight = min(table[row - height], height); 

Time: O(n^2 * m)

### DP + hist area

using the result form Largest Rectangle in Histogram. 
using the dp to build a histogram

time O(M*N)
space O(m*N)

## Code

```cpp
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
```

