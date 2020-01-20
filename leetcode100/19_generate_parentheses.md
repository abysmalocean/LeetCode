# 19 Generate Parentheses

## description

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

## Example

<p align = "center">   <img width = "500" src = "images/19_generate_parentheses_2020-01-16-14-20-30.png "> </p>

## Initial Thought

This is a very typical question for DFS. Use the DFS to generate all the cases. I did this program using only one pass. No bug in the code. However, the logic initially is not very good. I have modified it a little bit. 

Actually, there is only two cases: 

1. if left > 0: you can always add a '('. 
2. if left < right: this means we can put a '(' or not; 
   
```cpp
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

```

Time o(2^n)
space o(n) used for the stack. 

