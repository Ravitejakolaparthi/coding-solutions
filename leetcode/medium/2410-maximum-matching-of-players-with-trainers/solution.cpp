class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0;
        int j = 0;
        sort(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());
        while(i < players.size() &&  j < trainers.size()){
            if(trainers[j] >= players[i]){
                i++;
            }
            j++;
        }
        return i;
    }
};