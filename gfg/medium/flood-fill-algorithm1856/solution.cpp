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