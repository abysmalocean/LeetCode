//class TreeNode {
// public:
//  int value;
//  TreeNode* left;
//  TreeNode* right;
//  TreeNode(int v) : value(v), left(NULL), right(NULL) {}
//};
class Solution {
  TreeNode* reconstruct(const vector<int> &post, 
                        int               &index,
                        int               Max, 
                        int               Min)
  {
    if (index < 0) return nullptr; 
     
    if (post[index] < Max && post[index] > Min)
    {
      TreeNode* node = new TreeNode(post[index]);
      int key = post[index]; 
      --index; 
      node->right = reconstruct(post, index, Max, key);
      node->left  = reconstruct(post, index, key, Min);
      return node; 
    } 
    return nullptr; 
  }
 public:
  TreeNode* reconstruct(vector<int> post) 
  {
    // write your solution here
    const int len = post.size();
    int index = len - 1;
    return reconstruct(post, index, INT_MAX, INT_MIN); 
  }
};
