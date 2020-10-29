/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* result = new ListNode(0); 
        ListNode* current = result; 
        int inc = 0; 
        while(l1 != nullptr || l2 != nullptr)
        {
            int num1 = (l1 == nullptr ? 0 : l1->val);
            int num2 = (l2 == nullptr ? 0 : l2->val);
            int cur_num = num1 + num2 + inc;
            inc = 0; 
            if (cur_num > 9)
            {
                cur_num = cur_num - 10; 
                inc = 1; 
            }
            current->next = new ListNode(cur_num); 
            // Move every one forward
            current = current->next; 
            if ( l1 != nullptr ) {l1 = l1 -> next; }
            if ( l2 != nullptr ) {l2 = l2 -> next; }
        }
        if (inc == 1)
        {
            current->next = new ListNode(1);
        }


        return result->next; 

        
    }
};
// @lc code=end

