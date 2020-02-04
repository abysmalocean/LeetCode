# Edit Distance

## Description

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"

Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


## Initial Idea

This is one of the most commonly used question who is teaching DP. 

Using a 2D table. table[word1.length() + 1, word2.length() + 1]

There are 3 cases: 
- replace
  - if word1[i-1] == word2[j-1]:
    - replace = table[i-1][j-1];
  - replace = table[i-1][j-1] + 1; 
- delete the word1[i]
  - delete = table[i-1][j] + 1; 
- insert a char in work2[j], and the char == word[i]
  - insert = table[i][j-1] + 1; 

table[i][j] = min(replace, delete, insert); 

## code

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int row = word1.length(); 
        int col = word2.length(); 

        vector<vector<int>> table(row+1, vector<int>(col+1, 0)); 

        for (int i = 0; i < row + 1; ++i)
        {
            for (int j = 0; j < col + 1; ++j)
            {
                if (i == 0)
                {
                    table[i][j] = j; 
                }else if (j == 0)
                {
                    table[i][j] = i;
                } else
                {   
                    int replace = word1[i-1] == word2[j-1] ? 0 : 1; 
                    replace += table[i-1][j-1];  
                    
                    int remove_insert = min(table[i-1][j], table[i][j-1]) + 1;
                    table[i][j] = min(remove_insert, replace); 
                }
            }
        }
        return table[row][col]; 
        
    }
};
```

## Analysis

Time = O(word1.length * word2.length)
space = O(word1.length * world2.length)
space could be optimized to min(word1.length, word2.length); 


