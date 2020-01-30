# Group Anagrams

29/100

## Description

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

## Initial Idea

This is like a counting sort, just need to sort the string first. Then use the hash table to find out the anagrams. 

## Code

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, int> table; 
        vector<vector<string>> res; 
        for (int i = 0; i < strs.size(); ++i)
        {
            string tmp = strs[i]; 
            sort(tmp.begin(), tmp.end()); 
            
            if (table.count(tmp) == 0)
            {
                table[tmp] = res.size();
                // here must add a vector in the res, otherwise this element is not exist
                res.push_back(vector<string>());
            }
            res[table[tmp]].push_back(strs[i]); 
        }
        return res;         
    }
};
```

## C++ language

adding a empty vector<string> to vector<vector<stirng>>; 

res.emplace_back(vector<string>()); 
