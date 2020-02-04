# Sort Colors

## Description

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

## Initial Idea

color sort: 

need to define the three points carefully. 

red -> pointed to the number which is the next position for red, the pointed number could be tested 1, or untested. 

white -> is the pointer for the next position of white element. The pointed number have not been tested. 

blue -> the next position for blue; and the number have not been tested. 

**Stop Condition**
we know the region white and blue are untested region, so when blue == white, the pointed element still not been tested yet. So the stopping condition is white = blue + 1; this means all the elements have been tested. 

**Conditions**
There is a special conditions. 
if red == white. swap[ nums[red], nums[white] ] we need to increase both red and white pointers. 
if red < white, swap[ nums[red], nums[white] ], we also need to increase both of the pointers also. 

## Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int red = 0, white = 0, blue = nums.size()-1;
        
        while(white <= blue)
        {
            if (nums[white] == 0)
            {
                swap(nums[red], nums[white]);
                ++white; 
                ++red; 
            } else if(nums[white] == 1)
            {
                ++white; 
            } else if (nums[white] == 2)
            {
                swap(nums[white], nums[blue]); 
                --blue; 
            }
        }
    }
};
```

## Analysis

Time: O(n)
space : O(1)


