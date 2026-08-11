# Aggressive Cows

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array  **arr[]**, which denotes the positions of stalls. All the positions are distinct. There are **k**  aggressive cows.

Assign the cows to the stalls such that the **minimum**  distance between any two cows is  **maximized.** 

 **Examples:** 

```
Input: arr[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3]. The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible among all valid arrangements.
```

```
Input: arr[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at arr[0], the second at arr[1], and the third at arr[4]. In this arrangement, the minimum distance between any two cows is 4 (between arr[1] and arr[4]), which is the maximum possible among all valid arrangements.
```

 **Constraints:** 
2 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 108
2 ≤ k ≤ arr.size()

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-11T10:27:02.764Z  

```cpp
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
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/aggressive-cows/1)