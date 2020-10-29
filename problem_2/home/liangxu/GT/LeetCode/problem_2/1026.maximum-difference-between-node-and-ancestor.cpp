/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
    int maxAncestorDiff(TreeNode* root, int mx = 0, int mn = 100000) 
    {
        if (root == nullptr) return mx - mn;
        mx = max(mx, root->val);
        mn = min(mn, root->val); 
        int left = maxAncestorDiff(root->left, mx, mn); 
        int right = maxAncestorDiff(root->right, mx, mn); 
        return max(left, right); 
    }
};
// @lc code=end

