# Search in the rotated array

uppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

## initial idea: 

this is a very traditional binary search question. 
Only difference is the array is rotated. 

Instead of one situation after compare with mid, there will be two situations: 

- pivot element is larger than the first element in the array [the part of array from the first element to the pivot one is non-totated]
  - if the target is in that non-rotate part: go left end = mid - 1; 
  - other wist go right start = mid + 1; 
- pivot element is smaller than the first element of the array,[the rotation index is somewhere between 0 and mid] that means that the part of array from the pivot element to the last one is non-rotated. 
  - if target is in that non-rotated part as well: go end = mid + 1
  - otherwise go left stat  = mid - 1; 

## my code

my code in this version is not very good. 

```cpp
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
```

This code is not very efficient
- first, the right index is not open.
- and the right not decrease case by any case. 
- so the last condition [left left + 1]

So I made the code to left < right - 1
- in this case the last case is [left, left + 2]
- and the mid is [left + 1]
- and the result could be [left+2 left+2] and [left, left+1] and the left value is based on the previous step. 
- in this case the left value could be == right, which means the value could out of bound. this is the reason I have put the bounder check at the end. 

This could lead to a summary for the binary search. 



