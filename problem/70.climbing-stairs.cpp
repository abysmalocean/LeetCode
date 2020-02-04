/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) 
    {
        if (n <= 2)
        {
            return n;
        }
        int first  = 2; 
        int second = 1;
        int res; 

        n -= 2; 
        while(n--)
        {
            res = first + second; 
            second = first;
            first = res; 
        } 
        return res; 
    }
};
// @lc code=end

