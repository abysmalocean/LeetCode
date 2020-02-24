# Word Break

## Description

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

## Idea

This is a dynamic programming and hash table question. 
First to build a hash table to store all the strings. 
Second to build a memorized table to record from [0, i] is valid or not. 

So out job is
1. separate [0, i] to [0 j] [j + 1, i]; 

for [0, j] to can check the table, because we should have all the information from 0 to i - 1, and we also need to check the substring [j + 1, i] is in the dictionary or not. 

## code

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> dic(wordDict.begin(), wordDict.end());

        vector<bool> table(s.length()+1, false);

        table[0] = true;  
        for (int i = 1; i < s.length()+1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (table[j] == true)
                {
                    string tmp = s.substr(j , i - j);
                    if (dic.count(tmp) > 0)
                    {
                        table[i] = true; 
                        break; 
                    }
                }
            }            
        }
        return table.back();         
    }
};
```

## Analysis

Time: O(n^2), linear scan and look back ward. 
However, it depends on the algorithm to cut the substring. if the method take o(n), then the total time is O(n^3)

Space: O(n). n is the number of char in string or the number of string in WordDict. 

