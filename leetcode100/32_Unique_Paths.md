# 31 Unique Paths

## Description

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3
Output: 28


## Initial Idea

Initially, I was think to use a formula to solve this problem. Then, I could not find a good method for that. Then, I know this could be solve by DFS. With DFS and memorization could solve this problem. So the final method is DP. 

initial table[n-1][m-1] = 1; which is the target location.

table[i][j] = table[i+1][j] + table[i][j+1]

## Code

```cpp
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
```

## analysis

This could be done better by reduce the space to O(min(n,m)); 

Time is always: O(m*n);

Also the internal matrix transerval consider the column major or row major, in oder to get the best locality. 


## Other versions

This question have other version, I do not have enough time today, we be done tomorrow. 


