#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    vector<long long int>arr(n,0);
    for(int i=0;i<n;i++)
    cin>>arr[i];
 
    long long int ans=0,curr=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<curr)
        {
            ans+= (curr-arr[i]);
            
        }
        else
        {
            curr= arr[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
