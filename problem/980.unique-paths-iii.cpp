/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
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
// @lc code=end

