class Solution {
public:
    bool check(int limit,vector<int>&piles,int h){
        int  hours= 0;
        for(int i = 0;i<piles.size();i++){
      
        hours += (piles[i] + limit - 1)/limit;
        if(hours > h)
        return false;
        }
        return true;	
    }
    int minEatingSpeed(vector<int>& piles, int h) { 
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(mid,piles,h))
            {
            // yes
            // find any other less speed is present to do 
            // decrese high
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};