/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
    void letterCombinations(const vector<string>& table, 
                            vector<string>& result, const string& digits, 
                            string& current, int depth)
    {
        if (depth == digits.length())
        {
            //cout << "Liang XU"<< current << endl; 
            result.push_back(current); 
            return; 
        }
        int dig = digits[depth] - '2'; 

        for (int i = 0; i < table[dig].length(); ++i)
        {
            current.push_back(table[dig][i]); 
            letterCombinations(table, result, digits, current, depth +1); 
            current.pop_back(); 
        }

    } 
public:
    vector<string> letterCombinations(string digits)

    {
        vector<string> result; 
        if (digits.length() == 0) return result;
        
        vector<string> table{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 

        string current; 

        letterCombinations(table, result, digits ,current, 0); 

        return result; 
    
    }
};
// @lc code=end

