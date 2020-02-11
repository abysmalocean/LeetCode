# Meeting Room 2

## Description

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1

## Idea

This question spends me lots of time. I was not be able to figure this myself. I check the answers. 

The basic idea is always keep a min heap and check the ending time of the current priority queue. Scan the array, if the current element in the array's starting time is smaller than the smallest element in the queue. Then we know, we can free the top meeting. 

## Code

```cpp
struct minHeapCmp
{
    bool operator()(const vector<int>& lhs, const vector<int>& rhs)
    {
        return lhs[1] > rhs[1]; 
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs)
        {
            if (lhs[0] == rhs[0])
            {
                return lhs[1] < rhs[1]; 
            }
            return lhs[0] < rhs[0]; 
        }; 
        
        sort(begin(intervals), end(intervals), cmp); 
        
        priority_queue<vector<int>, vector<vector<int>>, minHeapCmp> q; 
        
        int rooms = 0; 
        for (auto& ele : intervals)
        {
            if(q.empty()) 
            {
                q.push(ele);
            } else
            {
                //cout << q.top()[0] << " " << q.top()[1] << endl; 
                if (q.top()[1] <= ele[0])
                {
                    q.pop();
                }
                q.push(ele); 
            }
            rooms = max(rooms,(int)q.size()); 
            
        }

        return rooms; 
        
        
    }
};
```

modified version

```cpp
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs)
        {
            if (lhs[0] == rhs[0])
            {
                return lhs[1] < rhs[1]; 
            }
            return lhs[0] < rhs[0]; 
        }; 
        
        sort(begin(intervals), end(intervals), cmp); 
        
        priority_queue<int, vector<int>, greater<int>> q; 
        int rooms = 0; 
        
        for (auto& ele : intervals)
        {
            if (q.empty())
            {
                q.push(ele[1]); 
            } else
            {
                if(q.top() <= ele[0])
                {
                    q.pop(); 
                }
                q.push(ele[1]); 
            }
            rooms = max(rooms, (int)q.size()); 
        }
        return rooms; 
    }
};
```