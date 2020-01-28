# Permutations

## Description

Given a collection of distinct integers, return all possible permutations.

**Example:**

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

## Initial Idea: 

Just like how human do this job; 
we will try to put [1, 2 ,3], every number as the first position. 
- if [1] are chosen as the first number, then we need to select the second one. 
- Then the same logic applied here. Then this time, we are looking a same problem but smaller. 

## Code

```cpp
class Solution {

void permuteDFS(vector<vector<int>>& res,  vector<int>& nums, int level)
{
    if (level == nums.size() - 1)
    {
        // do not have to swap the last value. 
        res.push_back(nums); 
        return; 
    }

    for (int i = level; i < nums.size(); ++i)
    {
        swap(nums[level], nums[i]); 
        permuteDFS(res, nums, level + 1); 
        // change the level by swapping 
        // to the nums behind him; 
        swap(nums[level], nums[i]); 
    }
}

/*
Always get the new number to the new postion. 
Time O(n!)
Space O(n) DFS, stack. did not count the output array. 
*/

public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res; 
        permuteDFS(res, nums, 0); 
        return res; 
    }
};
```

## Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

## Using a set

```cpp
class Solution {
private: 

void permuteUniqueDFS(vector<vector<int>>& res, vector<int>& nums, int level)
{
    if (level == nums.size() - 1)
    {
        res.push_back(nums); 
        return; 
    }

    unordered_set<int> st; 

    for (int i = level; i < nums.size(); ++i)
    {
        if (st.count(nums[i]) == 0)
        {
            swap(nums[i], nums[level]); 
            permuteUniqueDFS(res, nums, level + 1); 
            swap(nums[i], nums[level]);
            st.insert(nums[i]); 
        }
    }

}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        // deduplication is a problem
        vector<vector<int>> res; 

        permuteUniqueDFS(res, nums, 0); 

        return res;
        
    }
};
```

Using a hash table is not a good idea; try to do something else; 
what we really need is just using the same number once. Why not sort the array first, then group the numbers together. 
The check nums[i-1] == nums[i] continue; 

## Code

```cpp
void permuteUniqueDFS(vector<vector<int>>& res, vector<int> nums, int level)
{
    if (level == nums.size() - 1)
    {
        res.push_back(nums); 
        return; 
    }
    permuteUniqueDFS(res, nums, level + 1); 

    for (int i = level + 1; i < nums.size(); ++i)
    {
        if (nums[i] != nums[level])
        {
            swap(nums[i], nums[level]); 
            permuteUniqueDFS(res, nums, level + 1); 
            //swap(nums[i], nums[level]);
        }
    }
}
```

This one works: 
1. nums is not reference
2. make a copy of nums each recursion; 
3. sort the recursion each time; 

Still need more attentions to this problem. 

