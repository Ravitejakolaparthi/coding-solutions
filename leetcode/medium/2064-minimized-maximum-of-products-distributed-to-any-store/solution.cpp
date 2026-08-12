class Solution {
public:
     bool check(int limit,int n,vector<int>&q){
            for(int i = 0;i<q.size();i++){
                n -= (q[i] + limit - 1)/limit;
                if(n < 0) return false;
            }
            return true;
        }
    int minimizedMaximum(int n, vector<int>& quantities) {
       int low = 1;
       int high = *max_element(quantities.begin(),quantities.end());
       while(low <= high){
        int mid = low  + (high - low)/2;
        if(check(mid,n,quantities)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
       }
       return low;

    }

};