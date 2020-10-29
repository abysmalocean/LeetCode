/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int N) 
    {
       if(N == 1 || N == 0)
       {
           return N; 
       } 
       int prev = 0, curr = 1, res = 0; 
       for (int i = 2; i <= N; ++i)
       {
           res = prev + curr;
           prev = curr; 
           curr = res; 
       }
       return res; 
    }
};
// @lc code=end

