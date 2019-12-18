# Two Sum

> easy

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have
 exactly one solution, and you may not use the same element twice.

<p align = "center"> <img width = "500" src = "images/01_Two_sum_2019-12-18-12-20-58.png "> </p>

## My Solution

This is a Hash table and scans the array. 
Hash table keep the record [target-nums[i], i]; 

> runtime 8 ms 
> memory : 10.1 MB

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        if(nums.size() < 2) return {-1,-1}; 
        
        unordered_map<int,int> map; 
        map[target-nums[0]] = 0; 
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if(map.count(nums[i]) > 0) return {map[nums[i]], i}; 
            map[target-nums[i]] = i; 
        }
        return {-1,-1}; 
    }
};
```

> Time: O(n), just one scan, however, if you have a bad hash table, this turns too($n^2$)
> Space O(n), the hash table needs to take one additional space. 

## C++ language things

> find a key is the unordered_map using `map.count(key) > 0`;
this is very important, will use it in the future.

## Other Methods

### Approach 1, Brute Force.

This a very natural idea, and also very simple. A loop through element x and find if there is another value that equals to target - x. 

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return{-1,-1}; 
        
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1}; 
    }
};
```
> Runtime 140 ms
> Memory : 9.2 MB

However, this method seems time-consuming, However, in terms of space, it wins. 

> Time O(n^2): need to scan the array for each element; 
> Space O(1): No need for additional space. 

### Approach 2: Two-pass Hash Table

For approach 1, the time-consuming part is the inner loop. It require O(n) for search the 'whole array' (not whole, starting from [i, len]); 

Idea is to use a hash table help to find the elements; 

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return {-1, -1}; 
        
        unordered_map<int, int> map; 
        
        for (int i = 0; i < nums.size(); ++i)
        {
            /*
            if(map.count(nums[i]) > 0  && nums[i] * 2 == target)
            {
                return {map[nums[i]], i};
            }
            */
            map[target - nums[i]] = i; 
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if(map.count(nums[i]) > 0 && map[nums[i]] != i)
            {
                return {map[nums[i]], i}; 
            }
        }
        
        return {-1, -1 }; 
    }
};
```

This is more interesting compared with my solution in terms of analysis.

1. scan the array and add the [target - x, i]
2. scan the array the second time and find the nums[i] is in the map and find the index. 

Because the question tells us, there is exactly one solution, and can not use the same number twice. 
In the beginning, I was thinking to find the same elements which the element * 2 == target. 

```cpp
if(map.count(nums[i]) > 0 && nums[i] * 2 == target)
{
    return {map[nums[i]], i};
}
```
And this part is comment out. It is not necessary.

1. If there are two same elements and they added to the target. When scanning the array in the second time, the first element will find the second index in the map, because they map to a different index. 
2. if there one element and *2 == target. The index is the same in this case. 

So we only need to check if the element has the same index or not in the second scan. 


