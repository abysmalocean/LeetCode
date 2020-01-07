# Product of Array Except Self

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

<p align = "center">   <img width = "500" src = "images/12_Product_Array_Except_Self_2020-01-07-13-26-44.png "> </p>

**Note**: Please solve it without division and in O(n).

**Follow up:**
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

## Initial idea

This is a very simple question without the Note. Just multiple every element in the array and divide the current number. However, with the **Note** the problem become a bit more difficult.

We can multiply the pre-fix product without the current number by doing: 

res[i] = res[i-1] * nums[i-1]; 

and the initial value is 1; 

Then we can scan the array twice by backward. Now, because we want to use less space, and also we do not need to save the product value to somewhere. We can just keep a number of this product. 

product = 1; 

product *= nums[i+1]; 
res[i] *= product; 

Done: 

## Code

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res(nums.size(), 1); 
        
        if (nums.size() == 0) return res; 
        
        for (int i = 1; i < nums.size(); ++i)
        {
            res[i] = res[i-1] * nums[i-1]; 
        }
        
        int product = 1; 
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            product = product * nums[i+1]; 
            res[i] = product * res[i]; 
            
        }
        
        return res; 
        
    }
};
```