# Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

<p align = "center">   <img width = "500" src = "images/06_Longest_Substring_Without_Repeating_Characters_2019-12-31-12-39-36.png "> </p>

Approached 1: Sliding window and a set

We can define a sliding window like this, 
- left: window start, include this element. 
- right: window end, not including this element, and it is the element going to test in the next step. 
[left, right); 

if the left == right, window length is 0; 
stopping condition: right == length of the string. 
using a set, to record what is in the current window. 

There will be two cases: 
- s[right] in the window. 
- s[right] not in the window. 

Case 1: in the window: 
example , h i n a b c d e a f g 
left = 0 and right = 8; 
in this case the s[right] = a is in the window, and what we need to do is to move the left pointer to the position which s[left] == s[right]. Also, when we move the pointer, we need to keep removing the s[left] element from the set. This while stopping condition is when s[left] == s[right]. Then we can move the left forward one step. 



```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        const int len = s.length(); 
        if (len <= 1) return len; 
        
        int left = 0, right = 0; 
        int maxLen = 1; 
        
        unordered_set<char> sets; 
        
        while(right < len)
        {
            if(sets.count(s[right]) > 0)
            {
                while(s[left] != s[right])
                {
                    sets.erase(s[left]); 
                    ++left; 
                }
                ++left; 
            }
            
            sets.insert(s[right]); 
            ++right; 
            maxLen = max(maxLen, right - left); 
        }
        
        return maxLen; 
    }
};
```

This is not a very hash table, let us try to use a simplified hash table. 
Set is an very expensive data structure, and we know there are only several char can be displayed in a string. 

**Commonly used tables are:**

- int[26] for Letters 'a' - 'z' or 'A' - 'Z'
- int[128] for ASCII
- int[256] for Extended ASCII


```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        const int len = s.length(); 
        if (len <= 1) return len;
        
        int left = 0, right = 0; 
        vector<int> table(128, 0); 
        int maxLen = 1; 
        
        while(right < len)
        {
            if(table[s[right]] > 0)
            {
                while(s[left] != s[right])
                {
                    --table[s[left]]; 
                    ++left; 
                }
                ++left; 
            }
            table[s[right]] = 1; 
            ++right; 
            maxLen = max(maxLen, right - left); 
        }
        
        return maxLen; 
        
    }
};
```
