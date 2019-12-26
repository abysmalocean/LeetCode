# 146. LRU Cache


Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

```cpp
struct node
{
    int val; 
    int key; 
    node* next; 
    node* prev;
    
    node (int _val, int _key) : 
    val(_val), key(_key)
    {
        next = nullptr; 
        prev = nullptr; 
    }
};


class LRUCache {
    unordered_map<int, node*> map; 
    node* head; 
    int cap = 0;
    int size = 0; 

    node* remove(node* current)
    {
        current->prev->next = current->next; 
        current->next->prev = current->prev; 
        return current; 
    }

    void insertHead(node* Node)
    {
        Node->next = head->next; 
        Node->prev = head; 
        
        head->next = Node; 
        Node->next->prev = Node; 
        return ; 
    }
    
    inline void
    hit(int key)
    {
        node* newNode; 
        newNode = map[key]; 
        newNode = remove(newNode);
        insertHead(newNode);
    }

public:
    LRUCache(int capacity):
    cap(capacity)
    {
        head = new node(-1, -1);
        head->next = head; 
        head->prev = head;  
    }
    
    int get(int key) 
    {
        if (map.count(key) == 0) return -1;
        if (map[key] != head->next) 
        {
            hit(key);
        }
        return head->next->val; 
    }
    
    
    void put(int key, int value) 
    {
        
        if(map.count(key) > 0)
        {
            map[key]->val = value;
            hit(key); 
        } else
        {
            node* newNode = new node(value, key); 
            map[key] = newNode;

            if(size == cap)
            {
                node* end = head->prev; 
                end->prev->next = head; 
                head->prev = end->prev; 

                map.erase(end->key);
                delete(end);
                --size; 
            }
            ++size; 
            insertHead(newNode); 
        }
        
        return; 
    }
};
```