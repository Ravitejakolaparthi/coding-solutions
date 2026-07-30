#include<bits/stdc++.h>
using namespace std;
int main(){
    // int space = 0;
    // int tempspace = 0;
    int flag = 0;
    int skips = 3;
    for(int i = 0;i<4;i++)
    {
        for(int j = 4;j>=4-i;j--)
        {
            cout << j;
        }
        for(int l = 1;l<=6-(2*i);l++)
        {
            cout << " ";
        }
        skips = 4-i;
        for(int k = skips;k<=4;k++)
        {
            cout << k;
        }
        cout <<endl;
      }
        
    }
