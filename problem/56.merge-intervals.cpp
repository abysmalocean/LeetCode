/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
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
// @lc code=end

