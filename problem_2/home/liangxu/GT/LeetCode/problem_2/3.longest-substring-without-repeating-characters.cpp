/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        const int len = s.length(); 
        if (len <= 1) return len; 
        int right = 0, left = 0; 
        vector<int> table(128, 0);
        int result = 1; 

        int curr_len = 0; 
        while(right < len)
        {
            if (table[s[right]] > 0)
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
            result = max(result, right - left); 
        }
        return result; 

    }
};
// @lc code=end

