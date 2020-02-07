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

    TreeNode* deserialize(string data)
    {

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
        int index = -1;
        return deserializeDFS(values, index); 

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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

