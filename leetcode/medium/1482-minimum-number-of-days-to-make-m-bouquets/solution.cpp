class Solution {
public:
    bool check(long long int limit,int m,int k,vector<int>&bloomDay){
        int flowers = 0;
        int Boquet = 0;
        for(int i = 0;i<bloomDay.size();i++){
            if(bloomDay[i] <= limit){
                flowers++;
                if(flowers == k){
                    Boquet++;
                    flowers = 0;
                }
            }
            else{
                flowers = 0;
            }
        }      
        return Boquet >= m;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int low = *min_element(bloomDay.begin(),bloomDay.end());
        long long int high = *max_element(bloomDay.begin(),bloomDay.end());
        if((long long)m*k > bloomDay.size()) return -1; 
        while(low <= high){
            long long int mid = low + (high-low)/2;
            if(check(mid,m,k,bloomDay))
            {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
        
    }
};