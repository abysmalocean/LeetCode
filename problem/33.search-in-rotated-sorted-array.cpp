/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        if (nums.size() == 0) return -1; 

        int left = 0, right = nums.size(); 

        while(left < right - 1)
        {
            int mid = left + (right - left) / 2; 
            cout << left << " " << right << endl; 
            if (nums[mid] == target)
            {
                return mid; 
            }

            if (nums[left] < nums[mid])
            {
                if (target < nums[mid])
                {
                    if (target < nums[left])
                    {
                        left = mid + 1;
                    } else
                    {
                        right = mid;
                    }
                } else
                {
                    left = mid + 1;
                }
            } else if(nums[left] > nums[mid])
            {
                if (target > nums[mid])
                {
                    if (target >= nums[left])
                    {
                        right = mid; 
                    } else
                    {
                        left = mid + 1; 
                    }
                } else
                {
                    right = mid; 
                }
            }
        }
        
        if (left < nums.size())
        {
            return nums[left] == target? left: -1;    
        }

        return -1;
    }
};
// @lc code=end

