class Solution {
public:
    vector<char>albs = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string givestring(int n){
        vector<int>arr;
        int m = n;
        int rem = 0;
        while(n>0 && arr.size() < 25){
            rem = n%2;
            arr.push_back(rem);
            n = n/2;
        }
        int Z = m/pow(2,25);
        string ans ="";
        for(int i = 0;i<arr.size() && i < albs.size()-1;i++){
            
            if(arr[i] == 1){
                ans.push_back(albs[i]);
            }
        }
        
        while(Z>0){
            ans.push_back('z');
            Z--;
            }   
                                  
      reverse(ans.begin(),ans.end());       
        return ans;
    }
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string>v(n);
        for(int i = 0;i<n;i++){
            v[i] = givestring(nums[i]);
        }
        return v;
    }
};