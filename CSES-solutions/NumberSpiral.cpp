// if d is odd
//
//                         ^ increses 
//                         |
//                         |
//  decreases <--------(d,d)

// if d is even
//
//                         ^ decreses 
//                         |
//                         |
//  increses <--------(d,d)

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll fun(ll x,ll y)
{
    ll d = max(x,y); // bottom- right corner index of square
    ll e = min(x,y);
    if(x==y) return 1+ (d-1)*d;

    if(d%2==0)
    {
        if(x<d)
        {
            return 1+ (d-1)*d-(d-e); // bottom- right corner index value - (d-e);
        }
        else
        {
            return 1+ (d-1)*d+(d-e);  // bottom- right corner index value + (d-e);
        }
    }
    else
    {
        if(x<d)
        {
            return 1+ (d-1)*d+(d-e);  // bottom- right corner index value + (d-e);
        }
        else
        {
            return 1+ (d-1)*d-(d-e);  // bottom- right corner index value + (d-e);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;

        cout<<fun(x,y)<<endl;
    }
}
