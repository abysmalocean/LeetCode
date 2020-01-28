# Find First and Last Position of Element in Sorted Array

## Description

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

## Initial Idea: 

There will be two approached, by using the bianry search once or twice. 

### First Approach

Using the binary search once. Only search the element for the last or first. Then linear search for the rest of the elements. 

Time: Binary search $O(\log{n})$ + linear search $O(n)$. 

### Second Approach

Using Biany search twice, search both of the first and second. 

## Code

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.size() == 0 ) return {-1, -1};
        int left = 0, right = nums.size() - 1;
        int firstIndex = -1, lastIndex  = -1; 
    
        // find the first index
        while (left < right - 1)
        {
            int mid = left + ((right - left)/ 2);
            //cout << left << "  " << mid << "  "<< right << endl; 
            if (nums[mid] >= target)
            {
                right = mid; 
            } else
            {
                left = mid; 
            }
        }

        if (nums[left] == target || nums[right] == target) 
        {
            firstIndex = nums[left] == target ? left : right;  
        } else
        {
            return {-1, -1}; 
        }

        left = firstIndex; 
        right = nums.size() - 1; 
        
        while(left < right - 1)
        {
            int mid = left + ((right - left) / 2);

            if (nums[mid] <= target)
            {
                left = mid; 
            } else
            {
                right = mid; 
            }
        }

        if (nums[left] == target || nums[right == target])
        {
            if (nums[right] == target)
            { 
                return {firstIndex, right};  
            } else
            {
                return {firstIndex ,left}; 
            }
        } 

        return {-1,-1};
    }
};
```

The first code: 
- left and right are real value. And the stop condition is (left < right -1) which means when the two poiner are [n, n+1] then the search stops. Hoever, this search can not converge the exactly first or last postion. 
- also the stoping condition are according to the increncement method. 
- left = mind or right = mid; of if [left, right] = [n, n-1] the search will not stop. 


```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if (nums.size() == 0) return {-1, -1}; 
        int left = 0, right = nums.size(); 
        int firstIndex = -1; 

        while (left < right) 
        {
            int mid = left + (right - left) / 2; 
            // cout << left << "  " << mid << "  " << right << endl;
            if (nums[mid] >= target)
            {
                right = mid;
        
            } else
            {
                left = mid + 1; 
            }
        }
        if(left >= nums.size() || nums[left] != target) return {-1, -1}; 
        firstIndex = left; 

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
```

In this case
```cpp
while (left < right) 
{
    int mid = left + (right - left) / 2; 
    // cout << left << "  " << mid << "  " << right << endl;
    if (nums[mid] >= target)
    {
        right = mid;

    } else
    {
        left = mid + 1; 
    }
}
```
[n, n+1] and mid = n;
1. right = mid -> [n,n]-> convrege to n
2. left = mid + 1 -> [n+1,n+1] -> converge to n+1

However, the case converge to n+1, and n+1 is not a real value, so after converge, it must test the left < nums.size(). 
According to the moving condition, right could be the value we need, so need to it.

```cpp
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
```

Difference case apply to the second conditon. 
In this case, the right value could not be the value we need, so we need to stop at [n, n-1] and check the case n. 
