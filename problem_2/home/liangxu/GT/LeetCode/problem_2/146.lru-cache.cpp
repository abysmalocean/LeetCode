/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
private: 
    struct ListNode 
    {
        int key; 
        int value;
        ListNode* next;
        ListNode* prev;
        ListNode(int key,int value): 
        key(key), value(value), next(nullptr), prev(nullptr) 
        {}
    }; 
    
    void putLRU(ListNode* newLRU)
    {
        Table[newLRU->key] = newLRU; 
        newLRU -> next = dummyHead->next; 
        dummyHead->next->prev = newLRU; 
        dummyHead->next = newLRU; 
        newLRU->prev = dummyHead; 
    }
    
    void 
    deleteLRU()
    {
        Table.erase(dummyHead->prev->key); 
        dummyHead->prev->prev->next = dummyHead; 
        dummyHead->prev = dummyHead->prev->prev; 
    }

    ListNode* 
    removeMid(int key)
    {
        ListNode* tmp = Table[key]; 
        tmp->prev->next = tmp->next; 
        tmp->next->prev = tmp->prev; 
        tmp->next = nullptr;
        tmp->prev = nullptr; 
        return tmp; 
    }
private:
    int size = 0;
    int capacity;
    ListNode* dummyHead = nullptr;
    unordered_map<int, ListNode*> Table;
public:
    LRUCache(int capacity) : capacity(capacity)
    {
        dummyHead = new ListNode(-1, -1);
        dummyHead->next = dummyHead; 
        dummyHead->prev = dummyHead; 
    }
    
    int get(int key) 
    {
        // change the order
        if (Table.count(key) == 0)
        {
            return -1; 
        }
        ListNode* hitNode = removeMid(key); 
        putLRU(hitNode); 
        return hitNode->value; 
    }
    
    void put(int key, int value) 
    {
        if (Table.count(key) != 0)
        {
            ListNode* hitNode = removeMid(key);
            hitNode->value = value; 
            putLRU(hitNode);
        } else 
        {
            if (size < capacity)
            {
                ++size; 
                ListNode* tmp = new ListNode(key, value); 
                putLRU(tmp); 
            } else
            {
                // first delete
                deleteLRU(); 
                // insert
                ListNode* tmp = new ListNode(key, value);
                Table[key] = tmp; 
                putLRU(tmp); 
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

