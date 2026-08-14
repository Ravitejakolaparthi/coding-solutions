class Solution {
public:
    bool check(long long limit,long long int k,vector<int>&candies){
        long long int students = 0;
        for(int i = 0;i<candies.size();i++){
            students += candies[i]/limit;
        }
        return students >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long int low = 1;
        long long int high = *max_element(candies.begin(),candies.end());
        while(low <= high){
            long long int mid = low + (high-low)/2;
            if(check(mid,k,candies)){
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;

    }
};