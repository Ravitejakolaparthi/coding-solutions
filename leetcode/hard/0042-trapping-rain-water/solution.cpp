class Solution {
public:
    int trap(vector<int>& height) {
                   int drops = 0;
          int n = height.size();
          vector<int> r(n);
          int rm = -1;
          for(int i = n-1;i>=0;i--)
          {
              if(height[i] > rm)
              {
                  rm = height[i];
                  r[i] = height[i];
              }
              else
              {
                  r[i] = rm;
              }
          }
          vector<int>l(n);
          int lm = -1;
          for(int i = 0;i<n;i++)
          {
              if(height[i] > lm)
              {
                  lm = height[i];
                  l[i] = height[i];
              }
              else
              {
                  l[i] = lm;
              }
          }
          
          for(int i = 0;i<n;i++)
          {
              drops += min(l[i],r[i]) - height[i];
          }
        
    
    return drops;
    }
};