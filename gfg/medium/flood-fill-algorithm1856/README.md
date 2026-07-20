# Flood fill Algorithm

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a 2D grid  **image[][]**, where each  **image[i][j]**  represents the color of a pixel in the image. Also provided a coordinate  **(sr, sc)** representing the  **starting pixel**  (row and column) and a  **new color**  value  **newColor**.

Your task is to perform a  **flood fill**  starting from the pixel  **(sr, sc)**, changing its color to  **newColor**  and the color of all the connected pixels that have the same  **original color**. Two pixels are considered connected if they are adjacent  **horizontally or vertically**  (not diagonally) and have the same original color.

 **Examples:** 

```
Input: image[][] = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]], sr = 1, sc = 2, newColor = 2

Output: [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]]

Explanation: Starting from pixel (1, 2) with value 1, flood fill updates all connected pixels (up, down, left, right) with value 1 to 2, resulting in [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]].
```

```
Input: image[][] = [[0, 1, 0], [0, 1, 0]], sr = 0, sc = 1, newColor = 0
Output: [[0, 0, 0], [0, 0, 0]]
Explanation: Starting from pixel (0, 1) with value 1, flood fill changes all 4-directionally connected pixels with value 1 to 0, resulting in [[0, 0, 0], [0, 0, 0]]

```

 **Constraints:** 
1 ≤ n ≤ m ≤ 500
0 ≤ image[i][j] ≤ 10
0 ≤ newColor ≤ 10
0 ≤ sr ≤ (n-1)
0 ≤ sc ≤ (m-1)

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-20T06:41:10.573Z  

```cpp
class Solution {
  public:
    void move(vector<vector<int>>&grid,int i,int j,int og,int n)
    {
        if(i >=0 && i<grid.size() && j >= 0 && j <grid[0].size())
        {
            if(grid[i][j] != og)
            return ;
            if(og == grid[i][j])
            {
                grid[i][j] = n;
                move(grid,i-1,j,og,n);
                move(grid,i,j-1,og,n);
                move(grid,i+1,j,og,n);
                move(grid,i,j+1,og,n);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // code here
        
        int originalcolor = image[sr][sc];
        if(originalcolor != newColor)
        move(image,sr,sc,originalcolor,newColor);
        return image;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1)