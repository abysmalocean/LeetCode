## Container With Most Water

<p align = "center">   <img width = "500" src = "images/16_Container_With_Most_Water_2020-01-15-00-08-43.png "> </p>

<p align = "center">   <img width = "500" src = "images/16_Container_With_Most_Water_2020-01-15-00-09-01.png "> </p>

## Initial Idea

This is a typical two pointer problem: 

### Approach 1: Brute Force

In this case, we will simple consider the area for every possible pair of the lines and find out the maximum area out of those. 

```cpp
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int result = 0; 
        for (int i = 0; i < height.size(); ++i)
        {
            for (int j = height.size() - 1; j > i; --j)
            {
                int water = min(height[i], height[j]) * (j - i); 
                result = max(result, water); 
            }
        }

        return result; 
        
    }
};
```
time O(n^2)
space O(1)

However, there is a special case
When height[i] < height[j]: then we can release height[i], because this is the controler bar for the current water tank. 


### Approach 2: two pointers

```cpp
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int left = 0, right = height.size() - 1; 

        int result = 0; 

        while (left < right)
        {
            int water = min(height[left], height[right]) * (right - left); 
            if (water > result)
            {
                result = water; 
            }
            if (height[left] < height[right])
            {
                ++left; 
            } else
            {
                --right; 
            }
        }
        return result; 
        
    }
};
```

To prove this problem is kind of hard, still thinking about this. 


