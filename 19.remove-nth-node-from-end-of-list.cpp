/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
// @lc code=end

