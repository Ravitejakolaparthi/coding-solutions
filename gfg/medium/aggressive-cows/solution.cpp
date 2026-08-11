class Solution {
  public:
    bool check(int limit,int cows,vector<int>&arr){
    	// cows = cow_val;
    	cows -= 1;
    	int position = arr[0];
    	for(int i =0;i<arr.size();i++)
    	{
    		// 1 2 3 4 5 6 
    		
    		if(arr[i] - position >= limit){
    			cows--;
    			position = arr[i];
    		}
    		
    		if(cows == 0)
    		return true;
    	} 
    	return false;
    
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int low = 1;
        int high = arr.back() - arr.front();
        
        while(low <= high){
        	int mid = low + (high - low)/2;
        	if(check(mid,k,arr)){
        	       	low = mid+1;
        	}
        	else{
        	
        			high = mid-1;
        	}

            }
            return high;
        
    }
};