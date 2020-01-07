# Contest 170

## 1309. Decrypt String from Alphabet to Integer Mapping

Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

<p align = "center">   <img width = "500" src = "images/170th_Contest_2020-01-06-23-14-54.png "> </p>

### Constraints

- 1 <= s.length <= 1000
- s[i] only contains digits letters ('0'-'9') and '#' letter.
- s will be valid string such that mapping is always possible.

### idea

There will be 2 cases: 
1. 10# - 26# 
2. 1 - 9

So our program is going to check which case is above first then figure out the offset. 

1. 10# to 26#

i <= s.length() - 3 && 
(s[i] == '1' || s[i] == '2') && 
s[i+2] == '#'

The first condiction will make sure the s[i+2] not got an address access correct. 

2. else is 1 - 9 

### offest
- 10# - 26# -> 10 * (s[i] - '0') + s[i + 1] - '1' + 'a'; 
- 1 - 9 -> s[i] - '1' + 'a'; 

### code

```cpp
class Solution {
public:
    string freqAlphabets(string s) {
        string result; 
        
        for (int i = 0; i < s.length(); ++i)
        {
            char ch; 
            if (i <= s.length() - 3 && (s[i] == '1' || s[i] == '2') && s[i+2] == '#')
            {
                ch = 10 * (s[i] - '0') + s[i+1] - '1' + 'a'; 
                i += 2; 
                
            } else 
            {
                ch = s[i] - '1' + 'a'; 
            }
            result += ch; 
        }
        return result; 
        
    }
};
```

## 1310. XOR Queries of a Subarray

Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array containing the result for the given queries.

<p align = "center">   <img width = "500" src = "images/170th_Contest_2020-01-07-13-40-58.png "> </p>

Constraints:

- 1 <= arr.length <= 3 * 10^4
- 1 <= arr[i] <= 10^9
- 1 <= queries.length <= 3 * 10^4
- queries[i].length == 2
- 0 <= queries[i][0] <= queries[i][1] < arr.length

### Initial Idea

According to the constraints, the question has a very large input size. The algorithm complexity should constraints from O(1) to O(nlogn). 

Also this question very similarly with the prefix sum question. I just need to find out a way for the XOR edition. 

> a XOR b = c, and c XOR b = a and c XOR a = b; 
> a XOR a = 0; 

So, what we can do is to build a prefix XOR with size arr.size() + 1. Because the queries include both of the ends, and both of the ends can be equal. So if the queries are [0, 9], we need to access the element previous than pos 0. For the simplest solution just create an array with the size len + 1. 

So when we query the XOR, we search Table[first] - Table[Second+1]; 

### Code

```cpp
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        const int len = arr.size(); 
        vector<int> table(len+1, 0);
        table[0] = 0;
        
        for (int i = 1; i < len+1; ++i)
        {
            table[i] = table[i-1] ^ arr[i-1]; 
        }
        
        vector<int> res(queries.size(), 0); 
        
        for (int i = 0; i < queries.size(); ++i)
        {
            res[i] = (table[queries[i][0]] ^ table[queries[i][1]+1]); 
        }    
        return res; 
    }
};
```

### Time Complexity

If we are not using the prefix XOR, our algorithm is O(M*N), for each of the queries we need to scan the array once. 

Space :O(n) need a place to save all the prefix XOR. 

## 1311. Get Watched Videos by Your Friends

There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 

<p align = "center">   <img width = "500" src = "images/170th_Contest_2020-01-07-13-59-02.png "> </p>

<p align = "center">   <img width = "500" src = "images/170th_Contest_2020-01-07-13-59-16.png "> </p>

Constraints:

- n == watchedVideos.length == friends.length
- 2 <= n <= 100
- 1 <= watchedVideos[i].length <= 100
- 1 <= watchedVideos[i][j].length <= 8
- 0 <= friends[i].length < n
- 0 <= friends[i][j] < n
- 0 <= id < n
- 1 <= level < n
- if friends[i] contains j, then friends[j] contains i

### Initial Idea

Using the BFS to get that level, and use a counting sort to sort the Movies. The idea is quite simple, just the coding without error. 

At the contest, I have some stupid mistakes about the BFS, and I am going to summarize it here to do it again. 

### Coding

```cpp
        queue<int> q; 
        q.push(id);
        unordered_set<int> visited; 
        
        visited.insert(id); 

        int currentLevel = 0; 
        while(currentLevel != level)
        {
            int size = q.size(); 
            while(size--)
            {
                int currentNode = q.front();
                q.pop();
                
                
                for (auto& num : friends[currentNode])
                {
                    if (visited.count(num) == 0)
                    {
                        visited.insert(num);
                        q.push(num); 
                    }
                }
            }
            ++currentLevel; 
        }
```

Define the current level: the current element will be released. 

> Very important thing is the visited set. This visited set add a new element when reaching to a new node, not at the time when push out the node from a queue.

```cpp
bool cmp(const pair<string, int> lhs, const pair<string, int>rhs)
{
    if (rhs.second == lhs.second)
    {
        return lhs.first < rhs.first; 
    } else
    {
        return lhs.second < rhs.second; 
    }
}

auto cmpL = [](const pair<string, int> lhs, const pair<string, int>rhs)
{
    if (rhs.second == lhs.second)
    {
        return lhs.first < rhs.first; 
    } else
    {
        return lhs.second < rhs.second; 
    }
};

```
A compare function, I think this can be done by using the lambda function. 

Counting sort

```cpp
int size = q.size(); 
        for (int i = 0; i < size; ++i)
        {
            int currentNode = q.front(); 
            q.pop(); 
            for (string& name : watchedVideos[currentNode])
            {
                table[name]++; 
            }
        }
        
        vector<pair<string, int>> rank; 
        
        for (auto ele : table)
        {   
            rank.push_back(ele); 
        }
        
        sort(rank.begin(), rank.end(), cmpL); 
        
        for (auto ele : rank)
        {
            
            res.push_back(ele.first); 
        }
```

First count how many same element in the current level. 
Then sort the element according to the counting. 


```cpp
bool cmp(const pair<string, int> lhs, const pair<string, int>rhs)
    {
        if (rhs.second == lhs.second)
        {
            return lhs.first < rhs.first; 
        } else
        {
            return lhs.second < rhs.second; 
        }
    }

class Solution {
    
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        
        auto cmpL = [](const pair<string, int> lhs, const pair<string, int>rhs)
        {
            if (rhs.second == lhs.second)
            {
                return lhs.first < rhs.first; 
            } else
            {
                return lhs.second < rhs.second; 
            }
        };
        
        queue<int> q; 
        q.push(id);
        unordered_map<string, int> table; 
        
        unordered_set<int> visited; 
        visited.insert(id); 
        vector<string> res; 
        
        int currentLevel = 0; 
        
        while(currentLevel != level)
        {
            int size = q.size(); 
            while(size--)
            {
                int currentNode = q.front();
                q.pop();
                
                
                for (auto& num : friends[currentNode])
                {
                    if (visited.count(num) == 0)
                    {
                        visited.insert(num);
                        q.push(num); 
                    }
                }
            }
            ++currentLevel; 
        }
        
        int size = q.size(); 
        for (int i = 0; i < size; ++i)
        {
            int currentNode = q.front(); 
            q.pop(); 
            for (string& name : watchedVideos[currentNode])
            {
                table[name]++; 
            }
        }
        
        vector<pair<string, int>> rank; 
        
        for (auto ele : table)
        {   
            rank.push_back(ele); 
        }
        
        sort(rank.begin(), rank.end(), cmpL); 
        
        for (auto ele : rank)
        {
            
            res.push_back(ele.first); 
        }
        
        return res; 
        
    }
};
```

## 1312. Minimum Insertion Steps to Make a String Palindrome

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A **Palindrome String** is one that reads the same backward as well as forward.

<p align = "center">   <img width = "500" src = "images/170th_Contest_2020-01-07-14-16-18.png "> </p>

Constraints:

- 1 <= s.length <= 500
- All characters of s are lower case English letters.

### initial idea.

This is the same with edit distance question. 

the smallest case is only have one letter. 

then two letter 

1. if the letter is the same. Then the edit distance is the same with the [i+1, j-1]; 
2. if not same, we can add a letter which can be equal to any of the two candidate, and the edit distance is min(T[i+1, j], T[i,j-1]) + 1; 

```cpp
class Solution {
public:
    int minInsertions(string s) 
    {
        vector<vector<int>> table(s.length(), vector<int>(s.length(), 0));
        
        for (int i = s.length() - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < s.length(); ++j)
            {
                if (s[i] == s[j])
                {
                    table[i][j] = table[i+1][j-1]; 
                } else
                {
                    table[i][j] = min(table[i][j-1], table[i+1][j]) + 1;
                }
            }
        }
        
        return table[0][s.length() -1 ]; 
        
    }
};
```

Those 4 questions are very good I think, ready for the next one in next Saturday. 