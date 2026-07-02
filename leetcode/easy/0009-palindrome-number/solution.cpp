class Solution {
public:
        bool isPalindrome(int x) {
    int temp;
    temp=x;
    int rem;
     long long int sum=0;
    while(x>0)
    {
        rem=x%10;
        sum=sum *10+rem;
        x=x/10;
    }
    sum;
   return (temp==sum);
    
}

};