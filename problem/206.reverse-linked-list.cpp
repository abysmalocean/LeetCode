/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
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
// @lc code=end

