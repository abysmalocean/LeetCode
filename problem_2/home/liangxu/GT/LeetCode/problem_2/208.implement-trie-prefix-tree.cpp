/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
private:
    struct TrieNode
    {
        bool isWord; 
        vector<TrieNode*> children;
        //vector<TrieNode*> children; 
        TrieNode(): 
        isWord(false), 
        children(vector<TrieNode*>(26, nullptr)){}
    }; 
    TrieNode* head; 
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        head = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        const int len = word.length(); 
        TrieNode* curr = head; 
        for (int i = 0; i < len; ++i)
        {
            if (curr->children[word[i] - 'a'] == nullptr)
            {
                curr->children[word[i] - 'a'] = new TrieNode(); 
            }
            curr = curr->children[word[i] - 'a']; 
        }
        curr->isWord = true; 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        const int len = word.length(); 
        TrieNode* curr = head; 
        for (int i = 0; i < len; ++i)
        {
            if (curr->children[word[i] - 'a'] == nullptr)
            {
                return false; 
            }
            curr = curr->children[word[i] - 'a']; 
        }
        return curr->isWord; 
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        const int len = prefix.length(); 
        TrieNode* curr = head; 
        for (int i = 0; i < len; ++i)
        {
            if (curr->children[prefix[i] - 'a'] == nullptr)
            {
                return false; 
            }
            curr = curr->children[prefix[i] - 'a']; 
        }
        return true; 
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

