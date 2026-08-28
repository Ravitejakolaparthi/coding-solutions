class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         sort(points.begin(),points.end(),
        [](const vector<int>&a,const vector<int>&b){
            return a[1] < b[1];
        });   
        int prev = points[0][1];
        int c = 1;
        // for(int i=1;i<points.size();i++){
        int curr = 0;
            for(int j=1;j<points.size();j++){
                    curr = points[j][0];
                    if(prev < curr){
                        prev = points[j][1];
                        c++;
                    }

    
                // cout << points[i][j] << " ";
            }
            // cout << endl;
        // }
        // cout << c;
        return c;
    }

};