# Unique Path

## Unique Path 1

### Description

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?


An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

### Solution

This is the same with the unique path 1 question. Just have one comparison.

### Code

```cpp
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
```
## Unique Path 2

### Description

On a 2-dimensional grid, there are 4 types of squares:

- 1 represents the starting square.  There is exactly one starting square.
- 2 represents the ending square.  There is exactly one ending square.
- 0 represents empty squares we can walk over.
- -1 represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

## Idea: 

This can be easily solved by the DFS, and counting the number of empty squares. 1 <= grid.length * grid[0].length <= 20. So it is a small problem. we also can use a table to memorize the current position [x, y, [code:current states]]; However, I do not think this is necessary. 

## Code:

class Solution {
private: 
    vector<int> dir{0, 1, 0, -1, 0};
    void uniquePathsDFS(vector<vector<int>>& grid, 
                        vector<vector<int>>& visited, 
                        int x, int y, int total, 
                        int & res)
    {
        
        if (total <= 0 || grid[x][y] == 2)
        {
            if (grid[x][y] == 2 && total <= 0)
            {
                ++res; 
            }
             
            return; 
        }

        for (int i = 0; i < 4; ++i)
        {
            int Cx = x + dir[i]; 
            int Cy = y + dir[i+1]; 
            if (Cx >= grid.size() || Cx < 0 || Cy >= grid[0].size() || Cy < 0)
                continue; 
            if (visited[Cx][Cy] == -1 && grid[Cx][Cy] != -1)
            {
                visited[Cx][Cy] = 1;
                uniquePathsDFS(grid, visited, Cx, Cy, total-1, res);  
                visited[Cx][Cy] = -1;
            }
        }
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int m = grid.size(); 
        int n = grid[0].size(); 

        vector<vector<int>> visited(m, vector<int>(n,-1));
        int start_x, start_y; 
        int total = 0; 
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    start_x = i;
                    start_y = j;
                } else  if (grid[i][j] == 0)
                {
                    ++total; 
                }
            }
        }
        int res = 0;  
        visited[start_x][start_y] = 1; 
        uniquePathsDFS(grid, visited, start_x, start_y, total+1, res); 

        return res;
        
    }
};

### Analysis

This is a O(m*n^4)
Space O(M*N) for the table