# Regular Expression Matching

## Description

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

**Example 1:**

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

**Example 2:**

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

**Example 3:**

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

**Example 4:**

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

**Example 5:**

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

## Initial Idea

This probability a hard question for the person who just learn DP. Also this is a very classical DP question. 

1. The table size is s.length() + 1 and p.length() + 1
2. Initial row is the initial condition. 
3. T[0][0] = true; empty = empty, else = false

Also the DP table are build by: 

1. if p[i-1] == '.'
   1. this means the p[i-1] and s[j-1] must match
   2. Table[i][j] = table[i-1][j-1]
2. if p[i-1] == ''
   1. this means "x*" appear
   2. "x*" could be empty -> s[0:j-1] match p[0:i-3]->table[i][j] = table[i-2][j];
   3. "x*" could be any number of x
      1. x could be '.' match any char
      2. x == s[j]. in both of above cases, the table[i][j] = table[i][j-1]. which means s[0:j-2] match with p[:, i-1]. 
3. if p[i-1] == s[j-1]: table[i][j] = table[i-1][j-1]; 

## Code

```cpp
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int col = s.length(); 
        int row = p.length(); 

        vector<vector<bool>> table(row+1, vector<bool>(col+1,false)); 

        table[0][0] = true; 

        for (int i = 1; i < row+1; ++i)
        {
            if(p[i-1] == '*')
            {
                table[i][0] = table[i-2][0]; 
            }

            for (int j = 1; j < col+1; ++j)
            {
                if (p[i-1] == '.')
                {
                    table[i][j] = table[i-1][j-1];

                } else if (p[i-1] == '*')
                {
                    table[i][j] = table[i-2][j];
                    
                    if (p[i-2] == '.' || s[j-1] == p[i-2])
                    {
                        table[i][j] = table[i][j] || table[i][j-1]; 
                    }

                } else if (p[i-1] == s[j-1])
                {
                    table[i][j] = table[i-1][j-1]; 
                }
            }
        }
        return table[row][col]; 
        
    }
};
```