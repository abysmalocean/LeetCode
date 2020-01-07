# 11. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

<p align = "center">   <img width = "500" src = "images/11_ Maximum_Subarray_2020-01-06-13-39-32.png "> </p>

## Approach 1: Dynamic Programming

This is a very easy DP question, and can be solve only a scan of the whole array. 

The basic idea is that, we will define out element as: 

The maximum subarray ending with the current element and include this element.

So the sub-question become whether using the previous subarray. 
- case 1, T[i-1] + nums[i] > nums[i]: using the previous array. 
- case 2, T[i-1] + nums[i] < nums[i]: only using the current array. 

let us see, ... a b c d ... and we are at b, 
proof: 

contradiction: a + b + c > b + c when a + b < b and b + c > c; 

- if a + b < b; -> a < 0; 
- if b + c > c; -> b > 0; 
- a + b + c > b + c -> a > 0 contradiction with the first contradiction. 

### My first

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxSum = 0; 
        if (nums.size() <= 0) return maxSum; 
        
        vector<int> Table(nums.size(), 0);
        Table[0] = nums[0]; 
        maxSum   = nums[0]; 
        
        for (int i = 1; i < nums.size() ; ++i)
        {
            Table[i] = max(Table[i-1] + nums[i], nums[i]); 
            maxSum = max(maxSum, Table[i]); 
        }
        
        return maxSum; 
        
        
    }
};
```

Time : O(n), scan the whole array. 
Space: O(n), need to save a array. 

Optimize space to O(1); 

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0, maxSum = 0; 
        if (nums.size() <= 0) return maxSum; 
        sum = nums[0];
        maxSum = nums[0]; 
        
        for (int i = 1; i < nums.size(); ++i)
        {
            sum = max(sum + nums[i], nums[i]); 
            maxSum = max(maxSum, sum); 
        }
        
        return maxSum; 
        
    }
};
```

## Divide Conquer Method. 

<p align = "center">   <img width = "500" src = "images/11_ Maximum_Subarray_2020-01-06-13-55-34.png "> </p>

Divide the big problem to small problem.

Now, think there will be only 3 cases. 
1. max subarray at [left, mid]
2. max subarray at [mid+1, right]
3. max sumarray include mid and cross left and right. 

### Cross array. 

- calculate the sum from mid - 1 to left, and get the max
- calculate the sum from mid + 1 to right, and get the max
- leftMax + mid + rightMax; 

### return

return max(leftMax, rightMax, crossMax); 

### Code

```cpp
class Solution {
private: 
    int Cross(vector<int>& nums, int left, int right, int mid)
    {
        int leftMax = 0, leftSum = 0;
        int rightSum = 0, rightMax = 0; 
        
        for (int i = mid - 1; i >= left; --i)
        {
            leftSum += nums[i];
            leftMax = max(leftSum, leftMax); 
        }
        
        for (int i = mid + 1; i <= right; ++i)
        {
            rightSum += nums[i];
            rightMax = max(rightSum, rightMax); 
        }
        
        return leftMax + nums[mid] + rightMax; 
    }
    
    int maxSumArray(vector<int>& nums, int left, int right)
    {
        if (left == right) return nums[left]; 
        
        int mid = left + (right - left) / 2; 
        
        int leftMax = maxSumArray(nums, left, mid); 
        int rightMax = maxSumArray(nums, mid+1, right); 
        
        int CrossMax = Cross(nums, left, right, mid); 
        
        return max(max(leftMax, rightMax), CrossMax); 
    }
    
    
public:
    int maxSubArray(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0; 
        
        return maxSumArray(nums, 0, nums.size() - 1); 
        
    }
};
```

### time and space
- Time O(nlogn) -> every level need to clacuate all the element and get the sum
- Space O(logN) keep the recursion stack. 

## Note

left + (right - left) / 2: 
right != left; 

- if left + (1) / 2 -> left; 
- if left + (2) / 2 -> left + 1; 

so, in this case mid + 1 always works

