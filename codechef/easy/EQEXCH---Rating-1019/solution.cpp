#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int>v(n);
        for(int i =0;i<n;i++)
        cin >> v[i];
        vector<int>prefix(n+1);
        prefix[0]=0;
        // prefix[1]=v[0];
        for(int i=1;i<n+1;i++)
        {
            prefix[i] = v[i-1] + prefix[i-1];
        }
        int m = 99999;
        int b = -1;
        for(int i = 0;i<n+1;i++)
        {
            m = min(m,prefix[i]);
            b = max(b,prefix[i]);
        }
        if(b - m >k)
        cout << "No\n";
        else
        cout << "Yes\n";
        
    }
    return 0;
}