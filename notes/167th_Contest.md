# Weekly Contest 167

## Questions 1: 

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

For this question, the prefix sum and the square area both very typical solution for 2D data. Need to take extra attention. 

For binary search part, need to take care the range selection. 
for this question we can treat [0, max(m,n)), 0 is always a solution, and right side value is untested. So we need to think after comparison
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

