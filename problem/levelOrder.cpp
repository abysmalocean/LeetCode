//class TreeNode {
// public:
//  int value;
//  TreeNode* left;
//  TreeNode* right;
//  TreeNode(int v) : value(v), left(NULL), right(NULL) {}
//};
class Solution {
private: 
  TreeNode* reconstruct(vector<int>  levelOrder, 
                        unordered_map<int, int>& map)
  {
    if (levelOrder.size() == 0) return nullptr; 
    int pivot = map[levelOrder[0]];
    TreeNode* root = new TreeNode(levelOrder[0]); 

    vector<int> leftInOrder, rightInOrder; 
    
    for (int i =1; i < levelOrder.size(); ++i)
    {
      if (map[levelOrder[i]] < pivot)
      {
        leftInOrder.push_back(levelOrder[i]); 
      } else
      {
        rightInOrder.push_back(levelOrder[i]); 
      }
    }
    root->left = reconstruct(leftInOrder, map); 
    root->right = reconstruct(rightInOrder, map); 
    return root; 
  }
 public:
  TreeNode* reconstruct(vector<int> inOrder, 
                        vector<int> levelOrder) {
    // write your solution here
    unordered_map<int, int> map; 
    for (int i = 0; i < inOrder.size(); ++i)
    {
      map[inOrder[i]] = i; 
    }
    return reconstruct(levelOrder, map); 
  }
};
