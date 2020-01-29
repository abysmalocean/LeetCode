/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int prev, current;
        vector<vector<int>> cor{{0,0},{0,n-1},{n-1,n-1},{n-1,0}}; 
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1, 0}};
        vector<vector<int>> inc{{1,1}, {1,-1},{-1,-1},{-1,1}}; 

        int level = 0 ; 

        while(n > 1)
        {
            
            for (int i = 0; i < n - 1; ++i)
            {
                // 1. swap 1. 2
                swap(matrix[cor[0][0] + i * dir[0][0]][cor[0][1]+ i * dir[0][1]], 
                     matrix[cor[1][0] + i * dir[1][0]][cor[1][1]+ i * dir[1][1]]); 
                // 2. swap 3, 4
                swap(matrix[cor[2][0] + i * dir[2][0]][cor[2][1]+ i * dir[2][1]], 
                     matrix[cor[3][0] + i * dir[3][0]][cor[3][1]+ i * dir[3][1]]);
                // 3 . swap 1, 3
                swap(matrix[cor[0][0] + i * dir[0][0]][cor[0][1]+ i * dir[0][1]], 
                     matrix[cor[2][0] + i * dir[2][0]][cor[2][1]+ i * dir[2][1]]); 
            }
            // change the point
            for (int i = 0; i < 4; ++i)
            {
                cor[i][0] += inc[i][0];
                cor[i][1] += inc[i][1]; 
            }
            n -= 2; 
            ++level; 
        }
    }
};
// @lc code=end

