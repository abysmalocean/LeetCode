/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
private: 
    void generateParenthesis(int             n, 
                             string&         current,
                             int             left, 
                             int             right, 
                             vector<string>& res)
    {
        if (right == n)
        {
            res.push_back(current); 
            return; 
        }

        if (left < n )
        {
            current.push_back('('); 
            generateParenthesis(n, current, left + 1, right, res); 
            current.pop_back(); 
        }
        if (left > right)
        {
            current.push_back(')'); 
            generateParenthesis(n, current, left , right + 1, res); 
            current.pop_back();
        }

    }
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res; 
        string current; 
        generateParenthesis(n, current, 0, 0, res); 
        return res; 
    }

};
// @lc code=end

