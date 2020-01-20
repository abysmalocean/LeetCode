/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        const int len = s.length(); 
        int maxLen = 0; 
        
        stack<int> st;
        st.push(-1);  
        
        for (int i = 0; i < len; ++i)
        {
            if(st.top() == -1 || s[i] == '(')
            {
                st.push(i);
            } else if(s[st.top()] == '(' && s[i] == ')')
            {
                st.pop();
                maxLen = max(maxLen, i - st.top());   
            } else
            {
                st.push(i); 
            }
        }

        return maxLen; 
    }

};
// @lc code=end

