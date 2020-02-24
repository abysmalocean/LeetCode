/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<pair<int, int>> s;
        heights.push_back(0); 
        s.push({-1, 0}); 

        int res = 0; 
        for (int i = 0; i < heights.size(); ++i)
        {
            int index = i + 1;
            while(s.top().first >= heights[i])
            {
                int area = (i + 1 - s.top().second) * s.top().first; 
                //cout << "area " << area << endl; 
                res = max(res, area); 
                index = s.top().second; 
                s.pop(); 
            }
            s.push({heights[i], index});
        }
        return res; 
        
    }
};
// @lc code=end

