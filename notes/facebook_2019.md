```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(node == nullptr) return node; 
        
        // run a bfs to get all the nodes copy
        queue<Node*> q; 
        q.push(node); 
        
        unordered_map<Node*, Node*> map; 
        
        while(!q.empty())
        {
            int size = q.size(); 
            while(size--)
            {
                Node* current = q.front(); 
                q.pop();
                map[current] = new Node(current->val, current->neighbors);
 
                for(int i = 0; i < current->neighbors.size(); ++i)
                {
                    if(map.count(current->neighbors[i]) > 0) continue; 
                    q.push(current->neighbors[i]); 
                    
                }
            }
        }
        
        for (auto& CuNode : map)
        {
            for(int i = 0; i < CuNode.first->neighbors.size(); ++i)
            {
                CuNode.second->neighbors[i] = map[CuNode.first->neighbors[i]];  
            }
        }
        
        return map[node]; 
        
    }
};
```