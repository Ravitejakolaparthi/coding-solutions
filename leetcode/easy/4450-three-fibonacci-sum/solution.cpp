
class Solution {
public:
    bool  threeFibonacciSum(int n) {
        if (n % 2 != 0) {
            return false;
        }
        
        long long target = n / 2;
        long long a = 0;
        long long b = 1;
        
        while (a <= target) {
            if (a == target) {
                return true;
            }
            long long next = a + b;
            a = b;
            b = next;
        }
        
        return false;
    }
};
