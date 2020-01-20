
# Longest Valid Parentheses

## Description: 

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

## Initial idea:

This is a very good question, and it can be solved by many methods. The initial method I have used is DP. However, the method I have used caused O(n^3) which is very slow, got LTE. 
This question can be solve by O(n), and constant space. 

## Approaches

### DP1

Build a table T[len][len]; 

T[i][j] = T[i-1][j+1]
However, in case "()()" this method will not work. 
we need another level search
T[i] and T0[index]  + T[index+1] and T[j]: 
So this is a method with O(n^3) and space O(n^2); 

```cpp
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        const int len = s.length(); 

        vector<vector<bool>> table(len, vector<bool>(len, true));
        int maxLen = 0; 
        
        for (int i = 0; i < len; ++i)
        {
            table[i][i] = false; 
        }

        for (int i = len - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                table[i][j] = false; 
                if((j - i + 1)%2 == 0 && s[i] == '(' && s[j] == ')')
                {
                    if(table[i+1][j-1])
                    {
                        table[i][j] = true; 
                    } else if((j - i + 1) > 2)
                    {
                        for (int index = i + 1; index < j; ++index)
                        {
                            if(table[i][index] && table[index+1][j])
                            {
                                table[i][j] = true;
                                break;  
                            }
                        }
                    }
                }
                if(table[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1; 
                }
            }
        }
        
        return maxLen; 
    }
};
```

### DP 2

This is a much better approach. 

DP[i] = table[i-1] + table[previous] + 2; 


```cpp
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        const int len = s.length(); 
        int maxLen = 0; 

        vector<int> table(len,0); 

        for (int i = 1; i < len; ++i)
        {
            int preIndex = table[i-1] == 0 ? i-1 : i - table[i - 1] - 1; 

            if (preIndex >= 0 && s[i] == ')' && s[preIndex] == '(')
            {
                int previous = preIndex - 1 >= 0 ? table[preIndex-1] : 0; 
                table[i] = table[i-1] + previous + 2; 
                maxLen = max(maxLen, table[i]); 
            }
        }
        return maxLen; 
    }

};
```

### Stack

Using the stack is little bit tracky. 
Just remeber to keep an -1 in side the stack, and check if the stack top is -1. 

if ('(' and ')') match first is to pop the top of the stack. 
Then the element left is the index of the latest element valide the parentheses order. 

```cpp
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
```

### scan method will discussed later. 
