class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // here from 1 1 2 3 3 4 4 -> indexes are 0 1 2 3 4 5 
        // every dup pair has a pattern 
        // pattren 1 -> Before single element is found all paired elements have even index in start
        // pattern 2 -> After single element id found all paired elements have odd index in start

        // so here i have to find last pair that has even index in start
        // Or first pair that has odd index in start

        // low is start index
        int low = 0;
        // high is size because we search in array not out side it for our single element
        int high = nums.size()-1;

        while(low < high) { // here high must not equl to low can casue TLE high always stays as low for so on time
            int mid = low + (high - low)/2;
            
            if(mid%2 == 1)
            mid--;          // i want mid as even so i can find my last pair that has even start index

            if(nums[mid] == nums[mid+1]){
                // if had found even index start has same to its next i will see for next pair is it the last
                low = mid + 2;
            }
            else{
                // if it is already odd even pair i will check its left to find single element
                high = mid; 
            }
        }
        return nums[low]; // at last it has my answer 
    }
};