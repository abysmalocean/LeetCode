# Programming Combination

## Class 6 Heap & Graph Search I

### K smallest number
#### Method 1, Min heap
```cpp
class Solution {
 public:
  vector<int> kSmallest(vector<int> array, 
                        int         k) 
  {
    // write your solution here
    if (k == 0) return {}; 
    priority_queue<int> que(array.begin(), array.begin() + k); 
    for (int i = k; i < array.size(); ++i)
    {
      if (array[i] < que.top())
      {
        que.pop(); 
        que.push(array[i]); 
      }
    }
    vector<int> res(k); 
    for (int i = k - 1; i >= 0; --i)
    {
      res[i] = que.top(); 
      que.pop(); 
    }
    return res; 
  }
};
```
#### Method 2, Max heap

```cpp
class Solution {
 public:
  vector<int> kSmallest(vector<int> array, int k) 
  {
    // write your solution here
    vector<int> res(k); 
    priority_queue<int, vector<int>, greater<int>> que(array.begin(), 
                                                    array.end()); 
    for (int i = 0; i < k; ++i)
    {
      res[i] = que.top();
      que.pop(); 
    }
    return res; 
  }
};
```

#### Method 3, Quick Select
```cpp
class Solution {
private: 
  void kSmallest(vector<int> & array, 
                const int    k, 
                int          begin, 
                int          end)
  {
    int left = begin; 
    int right = end; 
    if (left > right) return; 
    int pivot = array[right];
    --right;  
    while(left <= right)
    {
      if (array[left] >= pivot)
      {
        swap(array[left] , array[right]); 
        --right; 
      } else
      {
        ++left; 
      }
    }
    swap(array[end], array[left]); 

    if (left == k) return; 
    
    if (left < k) 
    {
      kSmallest(array, k, left+1, end); 
    } else
    {
      kSmallest(array, k, begin, left-1);
    }
  }
 public:
  vector<int> kSmallest(vector<int> array, 
                        int         k) 
  {
    // write your solution here
    // quick select
    kSmallest(array, k, 0, array.size()-1); 
    sort(array.begin(), array.begin() + k); 
    return {array.begin(), array.begin() + k}; 
  }
};
```

### Graph Algorithm Q1. Print Binary tree level by level

Use a counter to count the number in each layer. 
```cpp
//class TreeNode {
// public:
//  int value;
//  TreeNode* left;
//  TreeNode* right;
//  TreeNode(int v) : value(v), left(NULL), right(NULL) {}
//};
class Solution {
 public:
  vector<vector<int>> layerByLayer(TreeNode* root) {
    // write your solution here
    if (root == nullptr) return {}; 
    deque<TreeNode*> que; 
    que.push_back(root); 
    vector<vector<int>> res; 
    while(!que.empty())
    {
      int size = que.size(); 
      vector<int> current; 
      for (int i = 0 ; i < size; ++i)
      {
        TreeNode* tmp = que.front(); 
        que.pop_front(); 
        current.push_back(tmp->value); 
        if (tmp->left != nullptr)
        {
          que.push_back(tmp->left);
        }
        if (tmp->right  != nullptr)
        {
          que.push_back(tmp->right); 
        }
      }
      res.push_back(current); 
    }
    return res; 
  }
};
```

### Question 2 Bipartite
Use a BFS search level by level

```cpp
//class GraphNode {
// public:
//  int value;
//  vector<GraphNode*> neighbors;
//  GraphNode(int v) : value(v) {}
//};


class Solution {
private: 
  bool isValid(GraphNode*                      node, 
               unordered_map<GraphNode*, int> &table)
  {
    if (table[node] != -1) return true;
    int flag = 0; 
    table[node] = flag; 
    deque<GraphNode*> que; 
    que.push_back(node); 
    while(!que.empty())
    {
      int size = que.size(); 
      flag = (flag + 1) % 2; 
      for (int i = 0; i < size; ++i)
      {
        GraphNode* tmp = que.front();
        que.pop_front(); 
        for (auto& neig : tmp->neighbors)
        {
          if (table[neig] == -1)
          {
            // not visited before
            table[neig] = flag; 
            que.push_back(neig); 
          } else if (table[neig] != flag)
          {
            return false; 
          }
        }
      }
    }
    return true;
  }
        
 public:
  bool solve(vector<GraphNode*> graph) 
  {
    unordered_map<GraphNode*, int> table; 
    for (auto& node : graph)
    {
      table[node] = -1;
    }
    for (auto& node : graph)
    {
      if (!isValid(node, table)) return false; 
    }
    return true; 
  }
};
```

### Question 3: Check a binary tree is a complete binary tree

```cpp
//class TreeNode {
// public:
//  int value;
//  TreeNode* left;
//  TreeNode* right;
//  TreeNode(int v) : value(v), left(NULL), right(NULL) {}
//};
class Solution {
 public:
  bool isCompleted(TreeNode* root) {
    // write your solution here
    if (root == nullptr) return true;
    deque<TreeNode*> que; 
    bool flag = false; 
    que.push_back(root); 
    while(!que.empty())
    {
      TreeNode* tmp = que.front();
      que.pop_front();
       
      // case 1
      if (tmp -> left  == nullptr && 
          tmp -> right != nullptr) 
      {
        return false; 
      }
      // case 2; 
      else if (!flag && (tmp -> left == nullptr || 
                    tmp -> right == nullptr))
      {
        flag = true; 
      }
      // case 3
      else if (flag && (tmp -> left  != nullptr || 
                   tmp -> right != nullptr))
      {
        return false;  
      }
      // push into the queue
      if (tmp -> left != nullptr)
      {
        que.push_back(tmp->left); 
      }
      if (tmp -> right != nullptr)
      {
        que.push_back(tmp->right); 
      }
    }
    return true; 
  }
};

```

### Questions4 , find k smallest number is sorted matrix. 

```cpp
class Solution {
 struct Node
 {
   int val; 
   int row; 
   int col; 
 };
 const vector<vector<int>> dir{{0,1}, {1,0}}; 
 public:
  int kthSmallest(vector<vector<int>> matrix, 
                  int                      k) 
  {
    // write your solution here
    if (k < 0) return INT_MIN; 

    const int len_row = matrix.size(); 
    const int len_col = matrix[0].size(); 
    auto com = [](const Node& lhs, const Node& rhs)
    {
      return lhs.val > rhs.val;
    }; 
    priority_queue<Node, vector<Node>, decltype(com)> que(com); 
    que.push({matrix[0][0], 0, 0}); 
    vector<vector<int>> visited(len_row, vector<int>(len_col, -1)); 
    visited[0][0] = 1;
    int res = matrix[0][0]; 
    while(!que.empty())
    {
      Node tmp = que.top(); 
      que.pop(); 
      res = tmp.val;
      --k;
      if (k == 0) return res;  
      for (int j = 0; j < 2; ++j)
      {
        int row = tmp.row + dir[j][0]; 
        int col = tmp.col + dir[j][1]; 
        if (row < len_row && 
            col < len_col && 
            visited[row][col] == -1)
        {
          visited[row][col] = 1; 
          que.push({matrix[row][col], row, col}); 
        }
      }
    }
    return INT_MIN; 
  }
};
```

## Class 4 Graph Search Algorithm (DFS2)

### Question 1: All subsets
Find all the subsets 
Add or not add
```cpp
class Solution {
private: 
  void allsubsets(const string& input, 
                  int           level, 
                  string &      current, 
                  vector<string>&  res)
  {
    if (level == input.length()) 
    {
      res.push_back(current); 
      return; 
    }
    // not add any letters
    allsubsets(input, level + 1, current, res); 
    current.push_back(input[level]); 
    allsubsets(input, level + 1, current, res);
    current.pop_back(); 
  }
 public:
  vector<string> solve(string input) {
    vector<string> res;
    string current; 
    allsubsets(input, 0, current, res); 
    return res; 
  }
};
```

### Question 2: All Valid Permutations Of Parentheses I

Only add valid parentheses in the search space. 

```cpp
class Solution {
private: 
  void validParentheses(const int n, 
                        int left, 
                        int right,
                        string & current, 
                        vector<string>& res)
  {
    if (left > n || right > n) return; 
    if (left == n && right == n)
    {
      res.push_back(current); 
      return;
    }
    current.push_back('('); 
    validParentheses(n, 
                     left + 1, 
                     right, 
                     current, 
                     res);
    current.pop_back();
    if (left > right)
    {
      current.push_back(')'); 
      validParentheses(n, 
                       left, 
                       right + 1, 
                       current, 
                       res);
      current.pop_back();
    }
  }
 public:
  vector<string> validParentheses(int n) 
  {
    // write your solution here
    vector<string> res; 
    string current; 
    validParentheses(n, 0, 0, current, res); 
    return res; 
  }
};
```

### Questions 3: Combinations Of Coins

```cpp
class Solution {
void combinations(int target, 
                  const vector<int>& coins, 
                  int level, 
                  vector<int>& current, 
                  vector<vector<int>> &res)
{
  // check if the target is == 0, then check the bounder condictions. 

  if (target == 0) 
  {
    res.push_back(current); 
    return; 
  }
  if (target < 0 || 
      level >= coins.size()) return; 
  for (int i = 0; i <= target / coins[level]; ++i)
  {
    current[level] = i; 
    combinations(target - coins[level] * i, 
                 coins, 
                 level + 1, 
                 current, 
                 res);
  }
  current[level] = 0;
}
 public:
  vector<vector<int>> combinations(int         target, 
                                   vector<int> coins)                                 
  {
    // write your solution here
    vector<vector<int>> res; 
    vector<int> current(coins.size(), 0); 
    combinations(target, coins, 0, current, res); 
    return res; 
  }
};

```

### Questions 4: All Permutations I

swap swap! 

```cpp

class Solution {
private: 
  void permutations(string& input, 
                    int level, 
                    vector<string>& res)
  {
    if (level == input.length())
    {
      res.push_back(input); 
      return; 
    }
    for (int i = level; i < input.length(); ++i)
    {
      swap(input[level], input[i]); 
      permutations(input, level + 1, res);
      swap(input[level], input[i]); 
    }
  }
 public:
  vector<string> permutations(string input) 
  {
    // write your solution here
    vector<string> res; 
    permutations(input, 0, res); 
    return res; 
  }
};
```

## Class 8 Hash table and String I

### Question 1: top K frequent words

```cpp
class Solution {
 public:
  vector<string> topKFrequent(vector<string> combo, 
                              int            k) {
    // write your solution here
    unordered_map<string, int> table; 
    for (string& str : combo)
    {
      table[str]++; 
    }
    auto com = [](const pair<string, int> & lhs, 
                  const pair<string, int> & rhs)
    {
      return lhs.second > rhs.second; 
    };
    priority_queue<pair<string, int>, 
                   vector<pair<string,int>>, 
                   decltype(com)> que(com); 
    
    for (auto& ele : table)
    {
      if (que.size() < k)
      {
        que.push(ele);
      } else if(que.top().second < ele.second)
      {
        que.pop();
        que.push(ele); 
      }
    }
    vector<string> res;
    //for (int i = k - 1; i >= 0; --i)
    //{
    //  res[i] = que.top().first; 
    //  que.pop(); 
    //}
    while(!que.empty())
    {
      res.push_back(que.top().first); 
      que.pop(); 
    }
    reverse(res.begin(), res.end()); 

    return res; 
  }
};

```

## Cross Training 1

### Q1. 

use array[i] != array[slow-1] to check the duplication. 
 
```cpp
class Solution {
 public:
  vector<int> dedup(vector<int> array) 
  {
    // write your solution here
    const int len =  array.size(); 
    if (len == 0) return {}; 
    int slow = 1; 
    for (int i = 1; i < len; ++i)
    {
      if (array[i] != array[slow-1])
      {
        swap(array[i], array[slow]); 
        ++slow; 
      }
    }
    return {array.begin(), array.begin() + slow}; 
  }
};

```

### Q2

```cpp
class Solution {
 public:
  vector<int> dedup(vector<int> array) 
  {
    // write your solution here
    const int len = array.size(); 
    if (len <= 2) return array; 
    int slow = 2; 
    for (int i = 2; i < len; ++i)
    {
      if (array[i] != array[slow-1] || 
          array[i] != array[slow-2])
      {
        swap(array[i], array[slow]); 
        ++slow; 
      }
    }
    return {array.begin(), array.begin() + slow}; 
  }
};
```

### Question 3: Array Duplication

```cpp
class Solution {
 public:
  vector<int> dedup(vector<int> array) 
  {
    // write your solution here
    const int len = array.size(); 
    if (len <= 1) return array; 
    int fast = 0, slow = 0; 
    while (fast < len)
    {
      if (slow != 0 && 
          array[fast] == array[slow-1])
      {
        while(array[fast] == array[slow-1])
        {
          ++fast; 
        }
        --slow;
      } else
      {
        swap(array[fast], array[slow]); 
        ++fast; 
        ++slow;
      }
    }
    return {array.begin(), array.begin() + slow}; 
  }
};
```

### Question 4: Rotate a Matrix

```cpp
class Solution {
private: 
  const vector<vector<int>> dir{{0,1}, {1,0}, 
                                {0,-1}, {-1, 0}}; 
 public:
  void rotate(vector<vector<int>> &matrix, 
                     int           index = 0) 
  {
    // write your solution here
    const int len = matrix.size(); 
    int begin = index; 
    int end   = len - index - 1; 
    if (begin >= end) return;

    for (int i = 0; i < end - begin; ++i)
    {
      swap(matrix[begin + i * dir[0][0]][begin + i * dir[0][1]],
           matrix[end   + i * dir[2][0]][end   + i * dir[2][1]]); 

      swap(matrix[end   + i * dir[3][0]][begin + i * dir[3][1]],
           matrix[begin + i * dir[0][0]][begin + i * dir[0][1]]);
      
      swap(matrix[begin + i * dir[1][0]][end   + i * dir[1][1]],
           matrix[end   + i * dir[2][0]][end   + i * dir[2][1]]);
    }
    rotate(matrix, index + 1); 
  }
};
```

### Questions 5 : print a tree in Zag-zig way

```cpp
//class TreeNode {
// public:
//  int value;
//  TreeNode* left;
//  TreeNode* right;
//  TreeNode(int v) : value(v), left(NULL), right(NULL) {}
//};
class Solution {
 public:
  vector<int> zigZag(TreeNode* root) 
  {
    // write your solution here
    deque<TreeNode*> dque; 
    vector<int> res; 
    if (root == nullptr) return res; 
    dque.push_back(root); 
    bool right = true; 

    while (!dque.empty())
    {
      int size = dque.size(); 
      for (int i = 0; i < size; ++i)
      {
        if (right)
        {
          res.push_back(dque.back()->value); 
          if (dque.back()->right != nullptr)
          {
            dque.push_front(dque.back()->right ); 
          }
          if (dque.back()->left != nullptr)
          {
            dque.push_front(dque.back()->left ); 
          }
          dque.pop_back(); 
        } else
        {
          res.push_back(dque.front()->value); 
          if (dque.front() -> left != nullptr)
          {
            dque.push_back(dque.front()->left); 
          }
          if (dque.front()-> right != nullptr)
          {
            dque.push_back(dque.front()->right); 
          }
          dque.pop_front(); 
        }
      }
      right = !right; 
    }
    return res; 
  }
};
```

Second time
```cpp
//class TreeNode {
// public:
//  int value;
//  TreeNode* left;
//  TreeNode* right;
//  TreeNode(int v) : value(v), left(NULL), right(NULL) {}
//};
class Solution {
 public:
  vector<int> zigZag(TreeNode* root) {
    // write your solution here
    if (root == nullptr) return{};
    vector<int> res; 
    deque<TreeNode*> que;
    bool right = false; 
    que.push_back(root); 
    while(!que.empty())
    {
      int size = que.size(); 
      for (int i = 0; i < size; ++i)
      {
        if (right)
        {
          TreeNode* tmp = que.front();
          que.pop_front();  
          res.push_back(tmp->value);
          if (tmp->left != nullptr)
          {
            que.push_back(tmp->left); 
          }
          if (tmp->right != nullptr)
          {
            que.push_back(tmp->right); 
          }
        } else
        {
          TreeNode* tmp = que.back();
          que.pop_back();
          res.push_back(tmp->value);
          if (tmp->right != nullptr)
          {
            que.push_front(tmp->right); 
          }
          if (tmp->left != nullptr)
          {
            que.push_front(tmp->left); 
          }
        }
      }
      right = !right;
    } 
    return res; 

  }
};
```

### Question 6: Closest k element in BST
```cpp
//class TreeNode {
// public:
//  int value;
//  TreeNode* left;
//  TreeNode* right;
//  TreeNode(int v) : value(v), left(NULL), right(NULL) {}
//};
class Solution {
private: 
  void closestKValues(TreeNode*  root, 
                      double     target, 
                      int        k, 
                      deque<int> & dque)
  {
    if (root == nullptr) return;
    // In order traversal. 
    // BSt inorder traversal is sorted order. ! need to take care of this
    // property. In order traversal is important. 
    
    closestKValues(root->left, target, k, dque);
    int current = root->value; 
    if ( dque.size() < k)
    {
      dque.push_back(current); 
    } else
    {
      if (abs(current - target) < 
          abs(dque.front() - target))
      {
        dque.pop_front(); 
        dque.push_back(current); 
      } else
      {
        return; 
      }
    }
    closestKValues(root->right, target, k, dque);
  }
 public:
  vector<int> closestKValues(TreeNode* root, 
                             double    target, 
                             int       k) 
  {
    // write your solution here
    deque<int> dque; 
    closestKValues(root, target, k, dque);
    return {dque.begin(), dque.end()}; 
  }
};

```
