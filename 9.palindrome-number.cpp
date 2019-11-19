/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; 
        if (x < 10) return true; 
        
        std::vector<int> nums; 
        while(x != 0)
        {
            nums.push_back(x%10); 
            x /= 10; 
        }
        bool result = true;
        int ptr = 0;  

        while(ptr < nums.size() - ptr - 1 )
        {
            if (nums[ptr] != nums[nums.size() - 1 - ptr])
            {
                return false; 
            }
            ++ptr; 
        }
        return true; 

    }
};
// @lc code=end

