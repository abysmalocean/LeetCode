# 2. Add Two Numbers

## Description

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

<p align = "center">   <img width = "500" src = "images/02_Add_Two_Numbers_2019-12-19-17-38-45.png "> </p>

<p align = "center">   <img width = "500" src = "images/02_Add_Two_Numbers_2019-12-19-17-42-00.png "> </p>

This question has lots of special case. 
1. carry from current number to the next. 
2. one array == nullptr
3. both of the array == nullptr, but still need to add the carry

My solution is good this time, and the code is good I think

## Code

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return l1; 
        
        int carry = 0; 
        ListNode* head = new ListNode(0);
        ListNode* current = head; 
        
        while(l1 != nullptr || l2 != nullptr || carry)
        {
            int val = carry; 
            
            if (l1) 
            {
                val += l1->val;
                l1 = l1->next; 
            }
            
            if (l2)
            {
                val += l2->val;
                l2 = l2->next; 
            }
            
            carry = 0; 
            if (val >= 10)
            {
                carry = 1; 
                val = val % 10; 
            }
            
            current->next = new ListNode(val);
            current = current->next; 
            
        }
        
        return head->next; 
    }
};
```

## Traverse the link list 

- This is very important, when you read a member from a node, we need to make sure this node is not nullptr. This is very important but forget every time. 

- Another is to move the head whenever needs it. head = head->next; 

- the dummy head is very good, however, sometimes it is not necessary.


## c++ language

I made a small mistake for this question

```cpp
ListNode head(0);
ListNode* current = &head; 

// and in side the while loop

ListNode tmp(val); 
current->next = &tmp; 
```

I got a memory leak problem and could not figure it out for a minute. If I define the variable like that, the ListNode will destruct when this function returned from the stack. Have not to practice programming for a year now, just forget how-to programming. Not good. 
