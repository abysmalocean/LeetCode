# Rotate Image

## Description

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

## Initial Idea

This question can be solved by recursion method, if you can divide the problem to a smaller one. 

The key question is hwo to divide the problem to a smaller problem. 

1. we know the image has 4 sides
2. how to divide 4 edge to one edge? 
3. after the 4 edges, how to reduce the size of the original matrix;

- we group n-1 element on each of the side. For example 1 2 3 4 5, on the first edge, we will group the [1, 2, 3, 4] as a basic group, 1 is the corner point, and 5 is the leading point for the next group [5, 10 ,15, 20]; 

- So, 4 corners, and the first corner increase {[0,1] * i}; second {-1, 0} * i}, when we do the swap.  
- After finish this level, the first corner will change to cor1 + {1,1}; cor2 + {-1, 1};
- During the swap, we can do a 3 swaps, or we save the curren value to a tmp place; only create 2 additional space; 

## Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int prev, current;
        vector<vector<int>> cor{{0,0},{0,n-1},{n-1,n-1},{n-1,0}}; 
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1, 0}};
        vector<vector<int>> inc{{1,1}, {1,-1},{-1,-1},{-1,1}}; 

        int level = 0 ; 

        while(n > 1)
        {
            
            for (int i = 0; i < n - 1; ++i)
            {
                prev = matrix[cor[3][0] + i * dir[3][0]][cor[3][1] + i * dir[3][1]]; 
                for (int j = 0; j < 4; ++j)
                {
                    current = matrix[cor[j][0] + i * dir[j][0]][cor[j][1] + i * dir[j][1]]; 
                    matrix[cor[j][0] + i * dir[j][0]][cor[j][1] + i * dir[j][1]] = prev;
                    prev = current; 
                } 
            }
            // change the point
            for (int i = 0; i < 4; ++i)
            {
                cor[i][0] += inc[i][0];
                cor[i][1] += inc[i][1]; 
            }
            n -= 2; 
            ++level; 
        }
    }
};
```

## Other solutions

3 swap method. 
1. swap{1, 2}
2. swap{3, 4}
3. swap{1, 3}

1 2 
4 3

after first two

2 1
3 4

4 1 
3 2 

```cpp
 
for (int i = 0; i < n - 1; ++i)
{
    // 1. swap 1. 2
    swap(matrix[cor[0][0] + i * dir[0][0]][cor[0][1]+ i * dir[0][1]], 
         matrix[cor[1][0] + i * dir[1][0]][cor[1][1]+ i * dir[1][1]]); 
    // 2. swap 3, 4
    swap(matrix[cor[2][0] + i * dir[2][0]][cor[2][1]+ i * dir[2][1]], 
         matrix[cor[3][0] + i * dir[3][0]][cor[3][1]+ i * dir[3][1]]);
    // 3 . swap 1, 3
    swap(matrix[cor[0][0] + i * dir[0][0]][cor[0][1]+ i * dir[0][1]], 
         matrix[cor[2][0] + i * dir[2][0]][cor[2][1]+ i * dir[2][1]]); 
}

};
```