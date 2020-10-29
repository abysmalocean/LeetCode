/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution 
{
    const vector<vector<int>> dirs{{0,1}, {0,-1}, {1, 0}, {-1, 0}}; 
    struct TrieNode
    {
        bool isWord; 
        vector<TrieNode*> children;
        TrieNode(): 
        isWord(false), 
        children(vector<TrieNode*>(26, nullptr)) 
        {}
    }; 
    TrieNode* root; 
    void insert(const string &word)
    {
        const int len = word.length(); 
        TrieNode* current = root; 
        for (int i = 0; i < len; ++i)
        {
            if (current->children[word[i] - 'a'] == nullptr)
            {
                current->children[word[i] - 'a'] = new TrieNode(); 
            }
            current = current->children[word[i] - 'a']; 
        }
        current->isWord = true; 
    }
    void findWords(vector<vector<char>> & board, 
                   int i, int j,
                   TrieNode* head, 
                   string & current,
                   vector<vector<int>> visited, 
                   vector<string> & res )
    {
        if(i >= board.size()    || 
           j >= board[0].size() ||
           visited[i][j] != -1    ||
           head == nullptr)
        {
            return; 
        }
        char ch = board[i][j]; 
        if (head->children[ch - 'a'] == nullptr) return; 
        head = head->children[ch - 'a'];
        
        current.push_back(ch);
        if (head->isWord)
        {
            res.push_back(current); 
        }
        visited[i][j] = 1;

        for (const auto& dir : dirs)
        {
            int row = i + dir[0]; 
            int col = j + dir[1];
            findWords(board, row, col, head, current, visited, res);

        }
        current.pop_back(); 
        visited[i][j] = -1;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, 
                             vector<string>      & words) 
    {
        root = new TrieNode(); 
        for (auto& word : words)
        {
            insert(word); 
        }
        int len_row = board.size(); 
        int len_col = board[0].size(); 
        vector<string> res; 
        string current; 
        vector<vector<int>> visited(len_row, vector<int>(len_col, -1));
        TrieNode* head = root; 
        for (int i = 0; i < len_row; ++i)
        {
            for (int j = 0; j < len_col; ++j)
            {
                findWords(board, i, j, head, current, visited, res); 
            }
        }
        unordered_set<string> stringSet;
        for (auto& s : res)
        {
            stringSet.insert(s); 
        } 
        vector<string> result; 
        for (auto& s : stringSet)
        {
            result.push_back(s); 
        }
        return result; 
    }
};
// @lc code=end

