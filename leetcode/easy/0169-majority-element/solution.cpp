class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 0;i<nums.size();i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = 1;
            }
            else{
                mp[nums[i]]++;
            } 
        }
        int idx = 0;
        int val = 0;
        for(auto i = mp.begin();i!=mp.end();i++){
            cout << i -> first << " " << i -> second;
            if(idx < i->second){
                idx = i->second;
                val = i->first;
            }
        }
        return val;
     
    }
};