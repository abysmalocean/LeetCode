# Serialize and Deserialize Binary Tree

## Description

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

## BFS Idea

the serialize part is not hard, just using BFS traverse the tree. When every have a NULL, push a '#' instead of a number. 

```cpp
string serializeBFS(TreeNode* root) 
    {
        // serialize using a BFS
        string res;
        if(root == nullptr) return res; 

        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* current = q.front(); 
                q.pop(); 
                if (current == NULL)
                {
                    res.push_back('#'); 
                } else
                {
                    res += to_string(current->val);
                    q.push(current->left); 
                    q.push(current->right); 
                    
                }
                res.push_back(','); 
            }
        }
        // remove the trining , and #
        res.pop_back(); 
        while(res.back() == '#')
        {
            res.pop_back();
            res.pop_back();
        }
        res.push_back(',');
        return res; 
        
    }
```

However, the descerialize part is a little bit confuse. However, just keep a simple rum, whenever a TreeNode* has been push out from the queue, then we can get the next two element to append to this node. If the pushed node is a NULL, do nothing. 


```cpp
   TreeNode* deserializeBFS(string data) 
    {
        if (data.length() == 0) return nullptr;

        // parsing
        vector<int> values; 
        //parsing(data, values);
        /*
        for (auto& num : values)
        {
            cout << num << endl; 
        }
        */
        int begin = 0; 
        auto end = data.find(',');

        while(end != string::npos)
        {
            string tmp = data.substr(begin, end - begin); 
            if (!tmp.compare("#")) 
            {
                values.push_back(INT_MAX); 
            } else
            {
                values.push_back(std::stoi(tmp)); 
            }
            begin = end + 1;  
            end = data.find(',', begin); 
        }
        

        queue<TreeNode*> q; 
        TreeNode* root = new TreeNode(values[0]); 
        int index = 0 ; 
        
        q.push(root); 
        while(!q.empty())
        {
            int size = q.size(); 
            while(size--)
            {
                TreeNode* current = q.front(); 
                q.pop();
                if (current != nullptr)
                {
                    int  leftIndex = index + 1; 
                    int rightIndex = index + 2;

                    if (leftIndex < values.size() && 
                        values[leftIndex] != INT_MAX)
                    {
                        TreeNode* left = new TreeNode(values[leftIndex]);
                        current -> left = left;
                        q.push(left); 
                    }
                    if (rightIndex < values.size() && 
                        values[rightIndex] != INT_MAX)
                    {
                        TreeNode* right = new TreeNode(values[rightIndex]); 
                        current -> right = right; 
                        q.push(right); 
                    }
                    index = rightIndex;
                }
            }
        }
        
        
        return root; 
    }
};
```

## DFS Idea

```cpp
void serializeDFS(TreeNode* root, string& res)
    {
        if (root == nullptr)
        {
            res.push_back('#'); 
            res.push_back(','); 
            return; 
        }
        res += to_string(root->val);
        res.push_back(','); 
        // go left
        serializeDFS(root->left, res); 
        serializeDFS(root->right, res); 
    }

string serialize(TreeNode* root)
{
    string res; 
    serializeDFS(root, res); 
    //cout << res << endl; 
    return res; 
} 

TreeNode* deserializeDFS(vector<int>& values, int& index)
    {
        ++index; 
        //cout << index << endl; 
        if (values[index] == INT_MAX)
        {
            return nullptr; 
        } else
        {
            TreeNode* root = new TreeNode(values[index]); 
            if(index < values.size())
            {
                root->left = deserializeDFS(values, index); 
            }
            if (index < values.size())
            {
                root->right = deserializeDFS(values, index); 
            }
            return root; 
        
        }
        return nullptr; 
    } 
```

## Parsing

The string need to be parsed in the beginning or in the middle of the execution. I prefer to do it in the beginning. However, this cost some of the additional space. But the locality do increase. I have tow parsing code, one is pure parsing and another get the idea from the string::find

```c++
if (data.length() == 0) return nullptr;
vector<int> values;
int begin = 0; 
auto end = data.find(',');

while(end != string::npos)
{
    string tmp = data.substr(begin, end - begin); 
    if (!tmp.compare("#")) 
    {
        values.push_back(INT_MAX); 
    } else
    {
        values.push_back(std::stoi(tmp)); 
    }
    begin = end + 1;  
    end = data.find(',', begin); 
}
```

```cpp
void parsing(string& data, vector<int>& values)
{
    int index = 0; 
    while(index < data.length())
    {
        if (data[index] == '#')
        {
            values.push_back(INT_MAX);
            ++index; 
        } else 
        {
            int current = 0;
            int sign    = 1; 
            if (data[index] == '-')
            {
                sign = -1;
                ++index; 
            }
            while(index < data.length() && data[index] != ',')
            {
                current = current * 10 + data[index] - '0';
                ++index;  
            }
            values.push_back(current*sign); 
        }
        ++index; 
    }
}
```
## C++ Language

About the string::find("string or char you want to find", begin index); 

string::find(..) != string::npos

and substr(begin, length); 


This is a very good question, I have spent two days for all the BFS and DFS figured out, and the parsing. 


