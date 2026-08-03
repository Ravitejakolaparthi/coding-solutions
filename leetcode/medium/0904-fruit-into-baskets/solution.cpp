class Solution {
public:
    map<int,int>mp;
    void mappush(int num)
    {
       mp[num]++;
    }
    void mappop(int num)
    {
        mp[num]--;
        if(mp[num] == 0)
        mp.erase(num);
    }
    int totalFruit(vector<int>& fruits) {
       int maxval = 0;
       int j = 0;
       for(int i = 0;i<fruits.size();i++)
       {
          mappush(fruits[i]);
        //   currmax=i-j;
        //   maxval = max(currmax,maxval);
         
            while(mp.size()>2)
            {
                mappop(fruits[j]);
                j++;
                // currmax--;
            }
            
           maxval = max(i-j+1,maxval);
       
       }
    //    if(maxval >0)
    //    return maxval-1;
    //    return currmax;
    return maxval;
    }
};