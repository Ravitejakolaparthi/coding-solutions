# Allocate Minimum Pages

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array  **arr[]** of integers, where each element  **arr[i]**  represents the number of pages in the i-th book. You also have an integer  **k**  representing the number of students. The task is to allocate books to each student such that:

- Each student receives atleast one book.
- Each student is assigned a contiguous sequence of books.
- No book is assigned to more than one student.
- All books must be allocated.

The objective is to  **minimize the maximum number of pages** assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the  **smallest possible maximum**. If it is not possible to allocate books to all students, return  **-1** ;

 **Note:** Test cases are generated such that the answer always fits in a 32-bit integer.

 **Examples:** 

```
Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.
```

```
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
```

 **Constraints:** 
1 ≤ arr.size() ≤ 106
1 ≤ arr[i], k ≤ 104

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-11T06:06:41.013Z  

```cpp
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
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)