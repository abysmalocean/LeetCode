/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
private: 
    vector<int> dir{1, 0, -1, 0, 1};

    bool exist(vector<vector<char>>& board, 
               string& word, vector<vector<int>>& visited, 
               int index, int row, int col)
    {
        if (index >= word.length())
        {
            return true; 
        }

        for(int i = 0; i < 4; ++i)
        {
            int N_row = row + dir[i]; 
            int N_col = col + dir[i+1]; 

            if (N_row < 0 || N_row >= board.size() ||
                N_col < 0 || N_col >= board[0].size()||
                board[N_row][N_col] != word[index] || 
                visited[N_row][N_col] == 1)

            continue;

            visited[N_row][N_col] = 1; 

            if(exist(board, word, visited, index + 1, N_row, N_col)); 
            {
                cout << index + 1 << " " << N_row << " " << N_col << endl; 
                return true; 
            }

            visited[N_row][N_col] = 0; 

        }
        return false; 
    }

public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size(); 
        if (m == 0) return false; 
        int n = board[0].size(); 
        if (n == 0) return false; 

        vector<vector<int>> visited(m, vector<int>(n, 0)); 

        for (int row = 0; row < m; ++row)
        {
            for (int col = 0; col < n; ++col)
            {
                visited[row][col] = 1; 
                if (board[row][col] == word[0] && exist(board, word, visited, 1, 0, 0))
                {
                    return true; 
                }
                visited[row][col] = 0; 
            }
        }      
        return false; 
    }
};
// @lc code=end

