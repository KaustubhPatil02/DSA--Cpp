#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n] = {0};
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        a[l] += 1;
        if(r+1 != n)
          a[r+1] -=l;
    }


}