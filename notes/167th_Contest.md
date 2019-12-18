# Weekly Contest 167

## Questions 1: 1290. Convert Binary Number in a Linked List to Integer

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

<p align = "center">   <img width = "500" src = "images/167th_Contest_2019-12-18-14-29-41.png "> </p>

<p align = "center">   <img width = "500" src = "images/167th_Contest_2019-12-18-14-29-55.png "> </p>

> The Linked List is not empty.
> Number of nodes will not exceed 30.
> Each node's value is either 0 or 1. 

```cpp
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int value = 0;

        while (head != NULL)
        {
            value <<= 1;
            value += head->val;

            head = head->next;
        }

        return value;
    }
};
```
<< is much faster than *2, but the compiler probability can optimize that, not sure for that part. 

## Question 2: 1291. Sequential Digits

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high]inclusive that have sequential digits.

- 10 <= low <= high <= 10^9
- 
<p align = "center">   <img width = "500" src = "images/167th_Contest_2019-12-18-14-39-22.png "> </p>

Testing every number will cause a TLT. 

### Approach 1, Search

Because each digit in the number is one more than the previous digits. So, it only 123, 1234 234. So we can track the last digit and do a BFS . 

```cpp
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res; 
        
        for (int i = 2; i < 10; ++i)
        {
            int test = 0; 
            int num = i;
            long tens = 10; 
            int count = i-1;
            
            while (num != 0 && test <= high)
            {
                test += num; 
                
                if (test >= low && test <= high)
                {
                    res.push_back(test);
                }
                
                num = tens * count;
                tens *= 10;
                --count; 
            }
        }
        
        sort(res.begin(), res.end()); 
        
        return res; 
    }
};
```

better version

```cpp
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int> res; 
        
        for (int i = 2; i < 10; ++i)
        {
            int value = 0;
            int tens  = 1; 

            for (int j = i; j > 0; --j)
            {
                value += j * tens;
                tens  *= 10; 
                if (value >= low && value <= high)
                {
                    res.push_back(value); 
                }
            }
        }
        sort(res.begin(), res.end()); 
        return res; 
        
    }
};
```

## Question 3: 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

Given a **m x n** matrix mat and an **integer threshold**. Return the maximum side-length of a square with a sum **less than or equal** to threshold or **return 0** if there is no such **square**.

<p align = "center">   <img width = "500" src = "images/167th_Contest_2019-12-17-13-53-04.png "> </p>

<p align = "center">   <img width = "500" src = "images/167th_Contest_2019-12-17-13-54-24.png "> </p>

> Difficulty: Medium

Constraints: 

- 1 <= m, n <= 300
- m == mat.length
- n == mat[i].length
- 0 <= mat[i][j] <= 10000
- 0 <= threshold <= 10^5

<p align = "center">   <img width = "500" src = "images/167th_Contest_2019-12-17-14-11-44.png "> </p>

```cpp
class Solution {
    int m,n; 
    
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) 
    {
        m = mat.size();
        n = mat[0].size(); 
        // create a m+1 and n+1 matrix
        // first row and first col both = 0
        vector<vector<int>> sum(m+1, vector<int>(n+1,0)); 
        
        // create prefix sum
        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1]; 
            }
        }
        
        // binary search for the side length
        int left  = 0; 
        int right = min(m,n); 
        
        auto isSquareExist = [&](int side)
        {
            for (int i = side; i < m + 1 ; ++i)
            {
                for (int j = side; j < n + 1 ; ++j)
                {
                    int sideSum = sum[i][j] - sum[i-side][j] - sum[i][j-side] + sum[i-side][j-side];
                    if (sideSum <= threshold)
                    {
                        return true; 
                    }
                }
            }
            return false; 
        };

        while(left < right)
        { 
            int mid = (left + right + 1) / 2;
            // in this case, left != mid
            if (isSquareExist(mid))
            {
                left = mid; 
            } else
            {
                right = mid - 1; 
            }
        }
        return left;
    }
};
```

For this question, the prefix sum and the square area both very typical solutions for 2D data. I need to take extra attention. 

For the binary search part, we need to take care of the range selection. 
for this question we can treat [0, max(m,n)), 0 is always a solution, and right-side value is untested. So we need to think after comparison
```cpp
is (isSquareExist(mid))
{
    left = mid; // left = mid, mid has been tested
} else
{
    right = mid - 1; // right = mid - 1, mid has been tested, and                  //it is not the answer
}
```
when left == right, means everting has been tested. But, there is a BUG in this case.

```cpp
int mid = (left + right) / 2; 
// because, the divide gets the lower bound, mid == left. 
// left has been tested, so it will stack. 
// we could
int mid = (left + right + 1) / 2; 
// in this case, the left could not left == mid, program could not get stack.

// or

int mid = left + (right - left + 1) / 2; 
// in this case, left != mid
// so 
return left; 
```

How to compare? 

```cpp
while(left < right)
{}
// left : tested
// right: not tested. 
// left == right, means everything has been tested. 
```

Need a summary for binary search! Will do it on weekend. 

## Question 4 1293. Shortest Path in a Grid with Obstacles Elimination

Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m-1, n-1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

<p align = "center">   <img width = "500" src = "images/167th_Contest_2019-12-18-15-23-59.png "> </p>


Constraints:

- grid.length == m
- grid[0].length == n
- 1 <= m, n <= 40
- 1 <= k <= m*n
- grid[i][j] == 0 or 1
- grid[0][0] == grid[m-1][n-1] == 0

Do a BFS search, and the search states are [x, y, o], o is the number of Obstacles in that path. Because the BFS always searches for the shortest path. For the path have already been searched but with a smaller Obstacles value should put into the queue again. 
For the traditional BFS, we build a set to mark the node has been seen or not. This time, we have to build a set to check the previous Obstacles number. 
If the number of Obstacles is more than the previous search result or the number of Obstacles already greater than k, we do not have to search again, we can use the previous pass. 

```cpp
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int dir[] = {0,1,0,-1,0}; 
        const int m = grid.size();
        const int n = grid[0].size(); 
        
        vector<vector<int>> seen(m, vector<int>(n,INT_MAX)); 
        queue<tuple<int, int, int>> q; 
        q.emplace(0,0,0); 
        int steps = 0; 
        seen[0][0] = 0; 
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int cx, cy, co; 
                tie(cx, cy, co) = q.front();
                q.pop(); 
                if (cx == m-1 && cy == n-1) return steps; 
                for (int i = 0; i < 4; ++i)
                {
                    int x = cx + dir[i]; 
                    int y = cy + dir[i+1]; 
                    if (x < 0 || y < 0 || x >= m || y >= n) continue; 
                    int o = co + grid[x][y];
                    
                    if (o >= seen[x][y] || o > k) continue; 
                    q.emplace(x,y,o);
                    seen[x][y] = o; 
                }
                
            }
            ++steps;
        }

        return -1; 
        
    }
};
```

This is a very good question, also can be solved by DP. I am not going to get that solution for this time. 

### C++ Language

queue<tuple<int, int, int>> q; 
int cx, cy, co; 
tie(cx, cy, co) = q.front(); 
q.emplace(x,y,o); 
q.push({x,y,o});
