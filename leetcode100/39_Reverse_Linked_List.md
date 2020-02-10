# Reverse Linked List

## Description

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

## Idea

Just remember the next point, 
for recursive way, we need to reset the current node -> next to nullptr. 

## Code

```cpp
class Solution {
public:
    ListNode* reverseListTraverse(ListNode* head) 
    {

        ListNode* current = head; 
        ListNode* prev    = nullptr; 
        
        while(current != nullptr)
        {
            ListNode* next = current->next;
            current->next = prev; 

            prev = current; 
            current = next;  
        }

        return prev; 
        
    }

    ListNode* reverseListRecursive(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head; 
        }
        ListNode* root = reverseList(head->next);
        head->next->next = head; 
        head->next = nullptr;   
        return root; 
    }
};
```

## Analysis

Time O(n), traversal the entire list
Space O(1), iterative
O(n), recursive
