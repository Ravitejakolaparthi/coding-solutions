class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count = 0;
        for(int k = 0;k<intervals.size();k++){
        for(int i = k+1;i<intervals.size();i++){
               
                if(intervals[k][0]<=intervals[i][0] && intervals[i][0] <= intervals[k][1]){
                    count++;
                }
            
        }
        }
        return count;
    }
};