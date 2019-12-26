# Longest Palindromic Substring

## Description

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

<p align = "center">   <img width = "500" src = "images/05_Longest_Palindromic_Substring_2019-12-25-22-54-41.png "> </p>

For this question, I think the DP is the best solution. 
<p align = "center">   <img width = "500" src = "images/05_Longest_Palindromic_Substring_2019-12-25-23-00-13.png "> </p>

For filling the matrix, we can go from bottom to top. 

```cpp
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int len = s.length(); 
        int left = 0; 
        int max = 1; 
        
        vector<vector<int>> table(len, vector<int>(len, 0)); 
        
        for(int i = 0; i < len; ++i)
        {
            table[i][i] = 1; 
        }
        
        for (int i = len - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                table[i][j] = -1; 
                if (s[i] == s[j] && table[i+1][j-1] >= 0)
                {
                    table[i][j] = table[i+1][j-1] + 2; 
                    if (table[i][j] > max)
                    {
                        max = table[i][j]; 
                        left = i; 
                    }
                }
            }
        }
        
        return s.substr(left, max); 
        
    }
};
```

## c++ language
I was struggling about the substr api. Then I finally realize the interface is (starting, and length). 


