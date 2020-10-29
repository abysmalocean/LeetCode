/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) 
    {
        const int len = s.length(); 
        if (len == 0) return true; 

        stack<char> st;
        st.push(s[0]); 
        for (int i = 1; i < len; ++i)
        {
            if (s[i] == '(' ||
                s[i] == '{' || 
                s[i] == '[' )
            {
                st.push(s[i]); 
            } else if (!st.empty())
            { 
                if((s[i] == ')' && st.top() != '(') || 
                   (s[i] == '}' && st.top() != '{') || 
                   (s[i] == ']' && st.top() != '['))
                {
                    return false; 
                }
                st.pop(); 
            } else 
            {
                return false; 
            }
        }
        return st.empty(); 
    }
};
// @lc code=end

