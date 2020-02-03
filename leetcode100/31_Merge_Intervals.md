# merge Intervals

## Descriptions

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

## Initial Idea

This is a very common question to use the greedy algorithm. First we need to sort the intervals by the first interval index. Then try to increase the second number.
1. current = Inverval[index]; 
2. if next element in interval : current[1] <= interval[index + 1]; this means the interval can be connected together. So current[1] = max(current[1], interval[index+ 1][1]); 

Do this until the last element of the intervals; 

## Code

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs)
        {
            /*
            if(lhs[0] == rhs[0])
            {
                return lhs[1] > rhs[1]; 
            }
            */
            /* if we sort the second element 
               we can skip the element with the same first index*/
            return lhs[0] < rhs[0]; 
        };

        sort(intervals.begin(), intervals.end(), cmp); 

        vector<vector<int>> res; 
        int index = 0; 
        while(index < intervals.size())
        {
            vector<int> current(2); 
            current = intervals[index];
            ++index; 
            while(index < intervals.size() && intervals[index][0] <= current[1])
            {
                current[1] = max(current[1], intervals[index][1]);
                ++index; 
            }
            res.push_back(current); 
        }

        return res; 
    }
};
```