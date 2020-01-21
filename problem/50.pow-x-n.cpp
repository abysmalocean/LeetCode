/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n == 0) return 1; 

        double res = myPow(x, abs(n/2)); 

        if (n % 2 == 0)
        {
            return n < 0? 1.0/(res*res) : res*res; 
        } else
        {
            return n < 0? 1.0/(res*res*x) : (res*res*x); 
        }
    }
};
// @lc code=end

