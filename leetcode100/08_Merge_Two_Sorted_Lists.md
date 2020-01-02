# 21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4


This is a very simple question, just do not forget to check the null when accessing the val. However, there are several methods. 

## My solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(0); 
        ListNode* current = head; 
        
        while(l1 != NULL && l2 != NULL)
        {
            if (l1 -> val < l2 -> val)
            {
                current->next = l1;
                l1 = l1->next; 
            } else
            {
                current->next = l2; 
                l2 = l2->next; 
            }
        
            current = current->next; 
        }
        
        while(l1 != NULL)
        {
            current->next = l1; 
            l1 = l1->next; 
            current = current->next; 
        }
        
        while(l2 != NULL)
        {
            current -> next = l2; 
            l2 = l2 -> next; 
            current = current -> next; 
        }
        
        return head->next; 
        
    }
};
```

However, this program works, but it can be samplize.

```cpp
while(l1 != NULL)
{
    current->next = l1; 
    l1 = l1->next; 
    current = current->next; 
}
        
while(l2 != NULL)
{
    current -> next = l2; 
    l2 = l2 -> next; 
    current = current -> next; 
}
```
However, we do not have to scan the list one by one, we can just using a simple code to check which one is not NULL. 

```cpp
current -> next = l1 ? l1 : l2; 
```

Time Complexity : O(m+n)
space: O(1)

### Recursion

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
        {
            return l2;
        }
        else if (l2 == nullptr)
        {
            return l1; 
        }
        else if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2); 
            return l1; 
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next); 
            return l2; 
        }
        
    }
};
```
Time complesity: O(m+n)
Space : O(m+n); 

From my test, the memory space is the same with the previous one. 


