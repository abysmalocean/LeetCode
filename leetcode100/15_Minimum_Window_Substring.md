# Minimum Window Substring


Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

Note:

- If there is no such window in S that covers all characters in T, return the empty string "".
- If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

## Initial idea: 

sliding windows method
1. moving the right pointer until the reach to a point contains all the target string. 
   - map[char]--, and it could be negative
   - only map[char] > 0, total--;
2. moving the left pointer, until reach to a point, total != 0 and s[left] in the target string. 

this method is a little bit complicated, and has lots of corner cases. 

```cpp
class Solution {
public:
    string minWindow(string s, string t) 
    {
        int right = 0, left = 0; 
        
        unordered_map<char, int> table; 
        
        for (int i = 0; i < t.length(); ++i)
        {
            ++table[t[i]];
        }
        
        int total = t.length();
        int bestR = 0, bestL = 0; 
        int bestLen = s.length();
        
        while(left < s.length() && table.count(s[left]) == 0)
        {
            ++left;
            ++right; 
        }
        
        while(right < s.length())
        {
            while(right < s.length() && total > 0)
            {
                if (table.count(s[right]) > 0)
                {
                    if(table[s[right]] > 0)
                    {
                        --total; 
                    }
                    --table[s[right]];
                }
                ++right; 
            }
            //cout << s.substr(left, right - left) <<" " << total <<endl; 
            
            
            while(left < right && !(total != 0 && table.count(s[left]) > 0))
            {
                if (total == 0 && right - left <= bestLen)
                {
                    bestR = right; 
                    bestL = left; 
                    bestLen = right - left; 
                }
                
                if (table.count(s[left]))
                {
                    if (table[s[left]] >= 0)
                    {
                        ++total; 
                    }
                    ++table[s[left]]; 
                }
                ++left; 
            }

        }
        
        return s.substr(bestL, bestR - bestL); 
    }
};
```

## Other solutions


https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems

learn this tomorrow. 
