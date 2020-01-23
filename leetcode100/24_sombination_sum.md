# Combination Sum; 

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,

A solution set is:
[
  [7],
  [2,2,3]
]


Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

## initial Idea: 

This is a very simple DFS question. The only thing special is how to reduce the redundancy. 

## Code

```cpp
class Solution {
private: 

    void combinationSumDFS(const vector<int>& candidates, int sum, 
                          vector<vector<int>>& res, vector<int>& current, int level)
    {
        if(sum == 0) 
        {
            if (current.size() != 0)
            {
                res.push_back(current); 
            } 
            return;

        } else if(sum < 0 )
        {
            return; 
        }

        for (int i = level; i < candidates.size(); ++i)
        {
            current.push_back(candidates[i]); 
            combinationSumDFS(candidates, sum - candidates[i], res, current, i); 
            current.pop_back(); 
        }

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res; 
        vector<int> current;
        combinationSumDFS(candidates, target, res, current, 0); 
        return res;         
    }
};
```

just remember the unordered_set<vector<int>> do not work. Vector<int> do not have a proper hash function, which need to made yourself. 

```cpp
namespace std
{
    template<>
    struct hash<YourSpecialType>
    {
        // ...
    };
}
```

## Version 2; 

Each number in candidates may only be used **once** in the combination.



```cpp
class Solution {
private: 
    void combinationSumDFS(const vector<int>& candidates, int target,
                           vector<vector<int>>& res, 
                           vector<int>& current, int level)
    {
        if (target == 0 )
        {
            res.push_back(current); 
            return; 
        } else if (target < 0)
        {
            return; 
        }

        for (int i = level; i < candidates.size(); ++i)
        {
            int nextIndex = i + 1; 
            
            while(nextIndex < candidates.size() && candidates[i] == candidates[nextIndex])
            {
                ++nextIndex; 
            }

            current.push_back(candidates[i]); 
            combinationSumDFS(candidates, target - candidates[i], res, current, i+1);
            current.pop_back(); 
            i = nextIndex-1;
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res; 
        vector<int> current; 
        sort(candidates.begin(), candidates.end());
        combinationSumDFS(candidates, target, res, current, 0); 
        return res; 
        
    }
};
```

<p align = "center">   <img width = "500" src = "images/24_sombination_sum_2020-01-23-15-37-17.png "> </p>

In this case, we need to find a better way to remove the duplicated candidates.
1. sort the candidates. Make sure the duplicated elements are next to each other
2. according to the recursion tree, We only add the duplicated element once in the current level. 

