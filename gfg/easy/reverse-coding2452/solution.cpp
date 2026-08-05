#include <iostream>
using namespace std;
int solve(int n,int x)
{
    if(n == 0)
    return x;
    else
    x +=  n+(solve(n-1,x));
}
int main() {
    int n;
    cin >> n;
    int x = solve(n,0);

    cout << x <<endl;
    return 0;
}