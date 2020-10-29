//class TreeNode {
// public:
//  int value;
//  TreeNode* left;
//  TreeNode* right;
//  TreeNode(int v) : value(v), left(NULL), right(NULL) {}
//};
class Solution {
 private: 
 struct ptrs
 {
   int preL; 
   int preR; 
   int inL; 
   int inR; 
 }; 
 TreeNode*
 reconstruct(const vector<int>& inOrder, 
             const vector<int>& preOrder, 
             ptrs               ptr, 
             unordered_map<int,int> map)
  {
    if (ptr.preL > ptr.preR) return nullptr; 

    int index = map[preOrder[ptr.preL]]; 
    TreeNode* root = new TreeNode(preOrder[ptr.preL]); 

    int size = index - ptr.inL; 
    // construct the left ptrs
    ptrs leftPtr = ptr; 
    leftPtr.preL++; 
    leftPtr.preR = ptr.preL + size; 
    leftPtr.inR = index - 1; 
    root->left = reconstruct(inOrder, preOrder,leftPtr, map); 
    
    // construct the right ptrs
    ptrs rightPtr = ptr; 
    rightPtr.preL += size + 1; 
    rightPtr.inL   = index + 1; 
    root->right = reconstruct(inOrder, preOrder,rightPtr, map); 
    return root; 
  }
 public:
  TreeNode* reconstruct(vector<int> inOrder, 
                        vector<int> preOrder) {
    // write your solution here
    unordered_map<int, int> map; 
    for (int i = 0; i < inOrder.size(); ++i)
    {
      map[inOrder[i]] = i; 
    }
    ptrs ptr{0, (int)preOrder.size() - 1, 0, (int)inOrder.size() - 1}; 
    return reconstruct(inOrder, preOrder, ptr, map);
  }
};
