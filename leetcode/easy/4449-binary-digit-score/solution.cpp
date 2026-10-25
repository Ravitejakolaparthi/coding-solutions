class Solution {
public:
    int countsetbits(int n){
        int count  = 0;
        while(n > 0){
            if(n&1 == 1){
                count++;
            }
          n =   n >> 1;
        }
        return count;
    }
    int calculateScore(int a, int b) {
       int s1 = countsetbits(a);
       int s2 = countsetbits(b);
        if(s1 >= s2) return s1*s2;
        else return s2/s1;
    }
};