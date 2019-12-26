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
    
    node* remove(int key)
    {
        node* current = map[key]; 
        current->prev->next = current->next; 
        current->next->prev = current->prev; 
        current->next = nullptr; 
        current->prev = nullptr;
        return current; 
    }
    
    node* insertHead(node* Node)
    {
        Node->next = head->next; 
        Node->prev = head; 
        
        head->next = Node; 
        Node->next->prev = Node; 
        return Node; 
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
        //cout << "Get key " << key << endl; 
        if (map.count(key) == 0) return -1;
        if (map[key] != head->next) 
        {
            //1. move the node from current link
            node* hitNode = remove(key); 
            //2. connect the head to this node
            insertHead(hitNode); 
        }
        return head->next->val; 
    }
    
    void put(int key, int value) 
    {
        //cout << "put key " << key << " val " << value << endl; 
        node* newNode; 
        if(map.count(key) > 0)
        {
            map[key]->val = value; 
            newNode = map[key]; 
            
            node* hitNode = remove(key);
            insertHead(newNode); 
        } else
        {
            node* newNode = new node(value, key); 
            map[key] = newNode;
            if(size == cap)
            {
                //cout << "Size full remove key " << head->prev->val << endl; 
                node* end = head->prev; 
                end->prev->next = head; 
                head->prev = end->prev; 

                map.erase(end->key);
                delete(end);
            }else
            {
                ++size; 
            }
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