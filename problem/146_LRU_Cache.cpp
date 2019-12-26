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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */