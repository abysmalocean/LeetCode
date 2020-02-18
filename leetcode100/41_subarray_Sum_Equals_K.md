# Subarray Sum Equals K

## Description

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2

Output: 2

Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

## idea

This is a traditional question using the prefix sum. 

Why we want to use the prefix sum? 
The brute force will take $O(n^2)$ to get all the subarray. However, to calculate the sum of those subarrays need to take $O(n) * O(n^2)$. So the total is an $O(n^3)$ algorithm. However, total space is constant. 

However, we can reduce the sum calculation time to a constant time look up. We are using a prefix sum table. The number in the table is the sum value from [0, current]. So the total sum for a subarray [i, j] can be calculated by table[j] - table[i-1]. I could be 0, 0 - 1, out of bound. So we can increase the size of the table, and make the first one always 0. 

**Attention**, be careful about the prefix sum. If the number are very big, this method will be explode.

## Code

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        // prefix sum
        vector<int> prefixSum(nums.size()+1);
        prefixSum[0] = 0;  

        for (int i = 0; i < nums.size(); ++i)
        {
            prefixSum[i+1] = prefixSum[i] + nums[i]; 
        }
        int res = 0;
        for (int i = 1; i < nums.size() + 1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if ((prefixSum[i] - prefixSum[j]) == k) ++res; 
            }
        }
        
        return res; 
    }
};
```

## Analysis

Time O(n^2): the time for search all the subarrays. 
space O(n) : save the prefix table; 

