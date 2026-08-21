class Solution {
public:
	bool check(double hours,long long int limit,vector<int>&dist){
		// double hours = 0;
		int n = dist.size();
				for(int i=0;i<n-1;i++){
						
						hours -= (dist[i] + limit -1)/limit; 
                        if(hours < 0)
                        return false;
						
				}
				hours-= double(dist[n-1])/limit;
				
				return hours >= -1e-9;
		}
    int minSpeedOnTime(vector<int>& dist, double hour) {
       long long int low = 1;
       long long int high = 10000000;
        if(hour <= double(dist.size()-1))  return -1; 
        while(low <= high){
           long long int mid = low + (high-low)/2;
            if(check(hour,mid,dist) == true){
                high = mid-1;
            }           
            else {
                low = mid + 1;
            } 
        }
        return low; // low always stores the minimum value 
    }
};