/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if (nums.size() == 0) return {-1, -1}; 
        int left = -1, right = nums.size()-1; 
        int firstIndex = -1; 

        while (left < right - 1) 
        {
            int mid = left + (right - left + 1) / 2; 
            // cout << left << "  " << mid << "  " << right << endl;
            if (nums[mid] >= target)
            {
                right = mid;
        
            } else
            {
                left = mid; 
            }
        }
        if(nums[right] != target) return {-1, -1}; 
        firstIndex = right; 

        right = nums.size();

        while(left < right - 1)
        {
            int mid = left + (right - left) / 2; 
            // cout << left << "  " << mid << "  " << right << endl;
            if (nums[mid] <= target)
            {
                left = mid; 
            } else
            {
                right = mid; 
            }
        }
        if(nums[left] != target) return {-1, -1}; 
        return{firstIndex, left}; 

    }
};
// @lc code=end

