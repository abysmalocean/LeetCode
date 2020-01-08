# 23. Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

<p align = "center">   <img width = "500" src = "images/13_KWayMerge_2020-01-08-14-19-58.png "> </p>

## Initial idea

I programmed this question before, and it is a simple one for me. Just using a priority queue and keep rank the val in the node and the index. 

However, the priority queue comparison method took me some time to figure out. I have listed 3 methods for comparison. 



```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool cmp1 (const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    return lhs.first > rhs.first; 
}

struct cmp2
{
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        return lhs.first > rhs.first; 
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* dummyNode = new ListNode(0);
        ListNode* current = dummyNode; 
        
        auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.first > rhs.first; 
        };
        
        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype( cmp )> que(cmp); 
        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > que; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                      std::function<bool(const pair<int, int>&, const pair<int, int>&)> >
                          que(cmp1); 
        
        for (int i = 0; i < lists.size(); ++i)
        {
            if(lists[i] != nullptr)
                que.push({lists[i]->val, i}); 
        }
        
        while(!que.empty())
        {
            int index = que.top().second; 
            que.pop(); 
            current -> next = lists[index];
            current = current -> next; 
            lists[index] = lists[index]->next; 
            if (lists[index] != nullptr)
            {
                que.push({lists[index]->val, index});
            }
        }
        
        return dummyNode->next; 
        
    }
};
```

## C++ Programming

### lambda function

```cpp
auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    return lhs.first > rhs.first; 
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype( cmp )> que(cmp); 
```

### Functor

```cpp
struct cmp2
{
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        return lhs.first > rhs.first; 
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > que; 

```

### Comparison function

```cpp

bool cmp1 (const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    return lhs.first > rhs.first; 
}


priority_queue<pair<int, int>, vector<pair<int, int>>, 
                      std::function<bool(const pair<int, int>&, const pair<int, int>&)> >
                          que(cmp1); 
```

There will be a special post on priority queue, and will be post later in this month. 
