class Solution {
public:
    int minRotations(string s) {
       
        int rounds =0;
        int curr = 0;
        for(int i = 0;i<s.length();i++){
            int clockwise = 0;
            int curr1 = curr;
            int dail = s[i]-'0';
            while(curr1!=dail){
                clockwise++;
                curr1++;
                if(curr1 > 9){
                curr1 = 0;
                }
                
            }
            int curr2 = curr; 
            int anticlockwise = 0;
            while(curr2!=dail){
                anticlockwise++;
                curr2--;
                if(curr2 < 0){
                curr2 = 9;
                }
            }
            rounds += min(clockwise,anticlockwise);
            curr = dail;
            // 0 1 2 3 4 5 6 7 8 9
        }               
        return rounds;
    }
};