# First missing Positive

## Description

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.

## Idea 

This is a very tricky question. Using O(n) and constant extra space is look impossible at first. In this kinds of question, we have to think how to use the original array and its index. The original array and its index can help us to identify the first missing positive value. However, how to move the element must pay attention. 

## Move condition

what condition make us to move a number to front? 
1. number > 0
2. nums[index] < index + 1;
3. nums[nums[index] - 1] != nums[index]

First, the nums < 0, we do not need to pay attention. 
Second, if the number is less than the current index + 1. Because the index of the nums start with 0, positive number is start with 1. So there is 1 difference. The correct is nums[i] == i + 1. [1, 2, 3 ,4]. So, if some number is less than this index + 1. we need to move it. If nums[index] == index + 1, we do not have to move, this is the right position for this number.
Third, if the previous number is already have this condition (nums[index] == index + 1) we do not have to move it. Also, if we moved it, it will cause a dead loop. Because, we are always try to find a number (nums[index] > index + 1 or nums[index] <= 0); 

## Code

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        // your algorithm should run in O(n) time and uses constant extra space. 
        // we can use the nums as extra space
        if (nums.size() == 0) return 1; 
        int index = 0; 
        while(index < nums.size())
        {
            if(nums[index] > 0 && nums[index] < index + 1 && nums[nums[index] - 1] != nums[index])
            {
                swap(nums[index], nums[nums[index] - 1]); 
            } else
            {
                ++index; 
            }
        }
        int res = 0; 
        for(; res < nums.size(); ++res)
        {
            if (nums[res] != res + 1)
            {
                break; 
            }
        }
        return res + 1; 
    }
};
```