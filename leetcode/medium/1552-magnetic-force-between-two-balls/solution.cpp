class Solution {
public:
    bool check(long long int limit,long long int m,vector<int>&position){
        m-=1; // we always put ball in first box
        long long int start = position[0]; // we always start from first empty box
        for(int i = 1;i<position.size();i++){
            if(position[i] - start >= limit){
                m-=1;
                start = position[i]; // Because to maintain same gap between each ball;
            }
            if(m == 0)
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        long long int low = 1; // possible min distance
        long long int high = position.back() - position.front(); // possible max distance between any two balls
        while(low <= high){
            long long int mid = low + (high-low)/2;
            if(check(mid,m,position)){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return high;
    }
};