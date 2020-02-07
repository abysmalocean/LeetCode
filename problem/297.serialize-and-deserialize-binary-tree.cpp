/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
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
        //cout << res << endl;
        return res; 
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserializeDFS(const string& data, int index)
    {
        if (2*index >= data.length() || data[2*index] == '#')
        {
            return nullptr; 
        }

        TreeNode* root = new TreeNode(data[2*index] - '0'); 
        root->left  = deserializeDFS(data, (2 * index + 1));
        root->right = deserializeDFS(data, (2 * index + 2));

        return root; 
    }

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
                while(index < data.length() && data[index] != ',')
                {
                    current = current * 10 + data[index] - '0';
                    ++index;  
                }
                values.push_back(current); 
            }
            ++index; 
        }
    }

    TreeNode* deserialize(string data) 
    {
        if (data.length() == 0) return nullptr;

        // parsing
        vector<int> values; 
        parsing(data, values);
        for (auto& num : values)
        {
            cout << num << endl; 
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
                    int  leftIndex = index + 2; 
                    int rightIndex = index + 4;

                    if (leftIndex <= data.length() && data[leftIndex] != '#')
                    {
                        TreeNode* left = new TreeNode(data[leftIndex] - '0');
                        current -> left = left;
                        q.push(left); 
                    }
                    if (rightIndex <= data.length() && data[rightIndex] != '#')
                    {
                        TreeNode* right = new TreeNode(data[rightIndex] - '0'); 
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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

