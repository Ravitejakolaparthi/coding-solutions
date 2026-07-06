class Solution {
public:
    int digitsum(int n)
    {
        int rem = 0;
        int sum = 0;
        while(n>0)
        {
            rem = n%10;
            sum += pow(rem,2);
            n /=10;
        }
        return sum;
    }
    bool isHappy(int n) {
            unordered_set<int>s;
            s.insert(n);
            while(n!=1)
            {
                n = digitsum(n);
                if(s.find(n)==s.end())
                {
                    s.insert(n);
                }
                else
                {
                    return false;
                }
            }  
            return true;  
        }
         
};