# Jump Game

## Description

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.


## Initial Idea

This is a very simple question. 
ues just one additional variable, the fares place you can reach. 

## Code

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        // do not need to open additional space, just mark the true as -
        //if (nums.size() <= 1) return true; 
        //vector<int> table(nums); 
        int farest = 0; 

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i <= farest && nums[i] + i > farest)
            {
                farest = nums[i]+i;
                //if (farest >= nums.size() - 1) return true;  
            } else if (i > farest)
            {
                return false; 
            }
            
        }

        return farest >= nums.size() - 1; 


    }
};
```

## Jump game 2 

Using BFS solution, always search the maximum you can get, then search the current layer, and the farest for the next layer. 

## Code

```cpp
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if (nums.size() <= 1) return 0; 

        int level = 0, i = 0; 
        int currentMax = 0; 

        while (i <= currentMax)
        {
            ++level;
            int furthest = currentMax; 
            for (; i <= currentMax; ++i)
            {
                furthest = max(furthest, nums[i] + i); 
            }
            
            currentMax = furthest; 
            if (currentMax >= nums.size() - 1) return level; 
        }

        return -1; 

        
    }
};
```