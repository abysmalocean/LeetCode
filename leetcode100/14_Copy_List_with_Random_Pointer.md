# Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.

<p align = "center">   <img width = "500" src = "images/14_Copy_List_with_Random_Pointer_2020-01-09-14-23-07.png "> </p>

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.

## Initial idea

This is the same problem in one of the interview with FB. Just build a mapping between the old node address and the new node address. 
```cpp
unordered_map<Node*, Node*> map; 

// first is the old pointer
// second is the new address. 
// idea is using the old pointer find the new address. 
```
Not to much thing I want talk about

## Code

```cpp
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
      
        Node* dummyHead = new Node(0); 
        Node* current = dummyHead; 
        unordered_map<Node*, Node*> map;
        
        while(head != nullptr)
        {
            Node* tmp = new Node(head->val);
            tmp -> random = head->random; 
            
            map[head] = tmp; 
            current->next = tmp; 
            current = current->next; 
            head = head -> next; 
        }
        
        current = dummyHead->next;
        while(current != nullptr)
        {
            current->random = map[current->random]; 
            current = current -> next; 
        }
        
        return dummyHead->next; 
    }
};
```

## similar question Clone Graph

Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph. Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

<p align = "center">   <img width = "500" src = "images/14_Copy_List_with_Random_Pointer_2020-01-09-14-28-07.png "> </p>

- The number of nodes will be between 1 and 100.
- The undirected graph is a simple graph, which means no repeated edges and no self-loops in the graph.
- Since the graph is undirected, if node p has node q as neighbor, then node q must have node p as neighbor too.
- You must return the copy of the given node as a reference to the cloned graph.

```cpp
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
```

## Idea

This is undirected graph, which means A pointed to B and B also pointed to A. 
Different from the last question, we do not need to wait for copy all the node then recover the pointers, we can build the neighbors on the fly, only discover the node already seen. 

If a link discovered:

1. the neighbors have not discovered yet. Do nothing. 
2. the neighbors have been discovered before, we need to :
   1. add neighbors
   2. add itself ad neighbors to the neighbor

Also using a BFS to discover all the node. 


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
