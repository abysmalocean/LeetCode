/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
private:
    bool searchMatrix(const vector<vector<int>>& matrix, 
                      pair<int, int> begin, 
                      pair<int, int> end, 
                      int target)
    {
        if (begin.first > end.first || begin.second > end.second)
        {
            return false; 
        }
        
        int row = (begin.first - end.first) / 2 + end.first;
        int col = (begin.second - end.second) / 2 + end.second;

        bool right = false, left = false; 

        if (matrix[row][col] == target)
        {
            return true; 
        } else if (matrix[row][col] < target)
        {
            right = searchMatrix(matrix, {row+1, begin.second}, end, target); 
            if(right) return true; 
            left  = searchMatrix(matrix, {begin.first, col + 1}, {row, end.second}, target); 
        } else
        {
            right = searchMatrix(matrix, begin, {row - 1, end.second}, target); 
            if(right) return true; 
            left  = searchMatrix(matrix, {row, begin.second}, {end.first, col - 1}, target); 
        }

        return left;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(); 
        if (m == 0) return false; 
        int n = matrix[0].size(); 
        if (n == 0) return false; 

        pair<int, int> begin{0,0}; 
        pair<int, int> end  {m-1, n-1}; 
        return searchMatrix(matrix, begin, end, target);
        
    }
};
// @lc code=end

