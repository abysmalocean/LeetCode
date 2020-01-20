/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
private: 
    void generateParenthesisDFS(int left, int right, vector<string>& res, string& current)
    {
        if (left == 0 && right == 0)
        {
            res.push_back(current); 
            return;
        }

        /*
        if (left >= right)
        {
            current.push_back('(');
            generateParenthesisDFS(left - 1, right, res, current); 
            current.pop_back(); 
        } else
        {
            if(left > 0)
            {
                current.push_back('(');
                generateParenthesisDFS(left - 1, right, res, current); 
                current.pop_back(); 
            }

            if (right > 0)
            {
                current.push_back(')');
                generateParenthesisDFS(left, right - 1, res, current); 
                current.pop_back(); 
            }
        }
        */ // this is not a very good logic

        if (left > 0)
        {
            current.push_back('(');
            generateParenthesisDFS(left - 1, right, res, current); 
            current.pop_back();
        }

        if (left < right)
        {
            current.push_back(')');
            generateParenthesisDFS(left, right - 1, res, current); 
            current.pop_back(); 
        }



    }
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res; 
        string current; 
        generateParenthesisDFS(n, n, res, current); 
        return res; 
    }
};
// @lc code=end

