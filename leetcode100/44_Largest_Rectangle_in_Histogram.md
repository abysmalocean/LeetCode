# Largest Rectangle in Histogram

## Description

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

<p align = "center">   <img width = "500" src = "images/44_Largest_Rectangle_in_Histogram_2020-02-24-13-57-48.png "> </p>

## idea

This problem can be solved by using a stack to record the **Begin index of the histogram height**. Remember, it is not the current index, it should be the begin index, this index can be find when inserting this element in the stack. 

When you inserting an element in the stack. 

- Case 1: the top of the stack height is bigger. 
  In this case, it means, the previous height can be extent to the current index. So we can push the {height[i], i + 1} in the stack. 

- Case 2: The height[i] is bigger than.
  In this case, the height[i] can not extent to hights[i]. so we need to calculate the area. (i + 1 - s.top().second ) * s.top().first(); 

in the beginning wo push an {-1, 0} in the stack, this is in case the stack is empty. At last we push {0, length + 1} to pop out all the elements in the stack. 

## code

```cpp

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

```

the above code modify the heights. However, if the API trying to protect the heights. it can define it as const. 

we can use an if condition to avoid this modification. 

## Analysis

Time O(n). only one scan, every element can be insert in the stack once. 
Space O(n); the stack. 



