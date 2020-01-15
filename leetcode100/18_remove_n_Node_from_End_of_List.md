## Remove Nth Node from End of List

Given a linked list, remove the n-th node from the end of list and return its head. 
Node: Could you do this in one pass?

<p align = "center">   <img width = "500" src = "images/18_remove_n_Node_from_End_of_List_2020-01-15-15-10-51.png "> </p>

## Initial idea: 

One pass, which needs to traversal the array to the end once. So think this, one pointer already reach to the end of the array, one pointer should pointed to the n-1 element in the array. So we need to build two pointers, one is n+1 away from the other. 

Think, the case only have one node, and this node is going to be removed from the link list. This is the reason we need to build a dummy node. 

## Code

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == nullptr) return head; 

        ListNode* dummyHead = new ListNode(0); 
        dummyHead -> next = head; 

        ListNode* fast = dummyHead; 
        ListNode* slow = dummyHead; 

        for(int i = 0; i < n+1; ++i)
        {
            fast = fast->next; 
        }

        while(fast != nullptr)
        {
            fast = fast->next; 
            slow = slow->next; 
        }

        slow->next = slow->next->next; 

        return dummyHead->next; 
        
    }
};
```

Still remember that, when access the link list element, we need to make sure it is not a null. 

