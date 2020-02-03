/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        if (m <= 0 || n <= 0) return 0; 
        if (m == 1 || n == 1) return 1; 
        vector<vector<int>> table(n+1, vector<int>(m+1, 0)); 

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if((i == n - 1) && (j == m - 1) )
                {
                    table[i][j] = 1; 
                } else
                {
                    table[i][j] = table[i+1][j] + table[i][j+1]; 
                }
            }
        }
        /*
        for (auto & eles : table)
        {
            for (auto & ele : eles)
            {
                cout << ele << "  "; 
            }
            cout << endl; 
        }
        */

        return table[0][0]; 
        
    }
};
// @lc code=end

