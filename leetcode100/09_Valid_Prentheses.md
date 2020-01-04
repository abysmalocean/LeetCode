# 20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

<p align = "center">   <img width = "500" src = "images/09_Valid_Prentheses_2020-01-04-00-32-25.png "> </p>

```cpp
class Solution {
public:
    bool isValid(string s) 
    {   
        int len = s.length();
        
        stack<char> T; 
        for (int i = 0; i < len; ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                T.push(s[i]); 
            } else
            {
                if(!T.empty() && 
                   ((s[i] == ')' && T.top() == '(') ||
                   (s[i] == ']' && T.top() == '[') ||
                   (s[i] == '}' && T.top() == '{')))
                {
                    T.pop();
                } else
                {
                    return false; 
                }
            }
        }
        return T.empty() ? true : false; 
        
    }
};
```

This is a very typical stack question. 
Just do not forget to check the stack empty before access the top value. 

