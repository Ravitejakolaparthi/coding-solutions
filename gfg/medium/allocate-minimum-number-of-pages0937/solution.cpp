class Solution {
  public:
  bool check(long long int limit,int k,vector<int>&b){
			int students = 1;
			long long int currpages = 0;
			for(int i=0;i<b.size();i++){
				if(currpages + b[i] <= limit)
				currpages += b[i];
				else{
					students++;
					if(students > k){
					return false;
					}
					currpages = b[i];
				}
				}
				return true;
		}

    int findPages(vector<int> &arr, int k) {
        // code here
        long long int low= *max_element(arr.begin(),arr.end());
        long long int high = 0;
		for(int i = 0;i<arr.size();i++)
		high += arr[i]; 
		if(k>arr.size()) return -1;
			 while(low <= high){
			 long long int mid = low+ (high-low)/2;
			 // finding min of all maxes so 
			 // if we got true at first mid
			 // we go check for is there any other low
			 if(check(mid,k,arr)){
				// YEs
				high = mid-1;
			 }
			 else{
				// NO
				low = mid+1;
			 }
			 
			 }
			 return low;
    }
};