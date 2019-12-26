# LeetCode 1293. Shortest Path in a Grid with Obstacles Elimination

<p align = "center">   <img width = "500" src = "images/LeetCode 1293. Shortest Path in a Grid with Obstacles Elimination_2019-12-24-00-55-11.png "> </p>

```cpp
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int ans = 0; 
        int current = 0;
        stack<int> st; 
        
        while(current < height.size())
        {
            while(!st.empty() && height[st.top()] < height[current])
            {
                int top = st.top();
                st.pop(); 
                if (st.empty()) break; 
                int distance = current - st.top() - 1; 
                int bounded_height = min(height[current], height[st.top()]) - height[top]; 
                ans += distance * bounded_height; 
            }
            st.push(current++); 
        }
        return ans; 
    }
};
```

```cpp
class Solution {
public:
    int trap(vector<int>& height) 
    {
        if(height.size() <= 0) return 0;  
        vector<int> left(height.size(), 0), right(height.size(), 0); 
        left[0] = height[0]; 
        right[height.size() - 1] = height[height.size() - 1];
        
        
        for (int i = 1; i < height.size(); ++i)
        {
            left[i] = max(left[i-1], height[i]);
            right[height.size() - 1 - i] = max(right[height.size() - i], height[height.size() - 1 - i]); 
        }
        
        int count = 0; 
        for (int i = 0; i < height.size(); ++i)
        {
            count += min(left[i], right[i]) - height[i];
        }
        
        return count; 
    }
};
```

