class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = speed.size();
        // if(n == 1) return 1;
        int currsp = speed[n-1];
        int currpos = position[n-1];
        int count = 1;
        for(int i = n - 2;i>=0;i--){
           if((speed[i] < currsp) && distance < abs(position[i+1]-position[i])){
                count++;
                currpos = position[i];
                currsp = speed[i];
           }else if(speed[i] == currsp)
           {
                if(position[i] != currpos && distance < abs(position[i+1]-position[i])){
                    count++;
                }
           }
        }
        return count;

    }
};