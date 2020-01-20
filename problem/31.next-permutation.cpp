/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.size() <= 1) return; 

        // find firstDecrease index; 
        int firstD = nums.size() - 2; 
        for (;firstD >= 0; -- firstD)
        {
            if (nums[firstD] < nums[firstD+1])
            {
                break; 
            }
        }   
        int swapCand = nums.size() - 1; 
        
        if (firstD != -1)
        {
            for (swapCand = firstD+1;  swapCand < nums.size() - 1; ++swapCand)
            {
                if (nums[swapCand + 1] <= nums[firstD])
                {
                    break;
                }
            }
            swap(nums[firstD], nums[swapCand]); 
        }
        
        int left = ++firstD, right = nums.size() - 1; 

        while(left < right)
        {
            swap(nums[left++], nums[right--]);
        }
        

    }
};
// @lc code=end

