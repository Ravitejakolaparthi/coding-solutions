
class Solution {
public:
    #define f first
    #define s second
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {               
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),
        [](const vector<int>&a,const vector<int>&b){
            return a[1] < b[1];
        });
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<2;j++){
                cout << intervals[i][j] << " ";
            }
            cout << endl;
        }
        int j = 0;
        for(int i = 1;i<n;i++){
            
            if(intervals[j][1] > intervals[i][0]){
                 cnt++;
                 
            }else{
                j = i;
            }
            
        }
        // if(n == cnt) return 1;
        return cnt;
    }
};