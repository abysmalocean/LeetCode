/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        vector<string> res; 
        const int len = words.size(); 
        if( k <= 0 || len <= 0) return res; 

        unordered_map<string, table> table; 

        for (auto& word : words)
        {
            table[word]++; 
        }

        auto comp = [](pair<string, int> lhs, 
                       pair<string, int> rhs)
                    {
                        return lhs.second > rhs.second; 
                    };
        priority_queue<pair<string, int>,
                       vector<pair<string, int>>, 
                       decltype(comp)> que(comp); 
        for (auto& item : table)
        {
            if(que.size() < k)
            {
                que.push(item); 
            } else if(item.second > que.top().second)
            {
                que.pop();
                que.push(item); 
            }
        }

        for (int i = 0; i < k; ++i)
        {
            res.push_back(que.top().first); 
            que.pop(); 
        }

        return res; 
    }
};
// @lc code=end

