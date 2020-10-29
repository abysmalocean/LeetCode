/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
private: 
    void NQueens(int                       level, 
                 vector<vector<int> >    & T, 
                 vector<string>          & current, 
                 vector<vector<string> > & res)
    {
        int n = current.size(); 
        if ( level == n) 
        {
            res.push_back(current); 
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            int pos1 = level - (i + 1) + n; 
            int pos2 = level + (i + 1); 
            if (T[0][i]    == -1 && 
                T[1][pos1] == -1 && 
                T[2][pos2] == -1)
            {
                T[0][i]    = 0;  
                T[1][pos1] = 0;  
                T[2][pos2] = 0;

                current[level][i] = 'Q'; 
                NQueens(level+1, T, current, res); 

                current[level][i] = '.';
                T[0][i]    = -1;  
                T[1][pos1] = -1;  
                T[2][pos2] = -1;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) 
    {
       vector<vector<int>> T(3, vector<int>(2 * n, -1)); 
       vector<vector<string>> res; 
       vector<string> current(n, string(n, '.'));

       NQueens(0, T, current, res); 

       return res; 
    }
};
// @lc code=end

