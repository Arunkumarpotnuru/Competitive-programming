// Initialize the variables 'ans' and 'curr' as 1. Iterate through the string,
// incrementing 'curr' each time 'str[i]' equals 'str[i-1]'. Update 'ans' if 'curr' is greater than 'ans';
// otherwise, reset 'curr' to 1.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int ans=1,curr=1;
    for(int i=1;i<str.length();i++)
    {
        if(str[i]==str[i-1])
        {
            curr++;
            ans= max(ans,curr);
        }
        else
        curr=1;
 
    }
    cout<<ans<<endl;
    return 0;
}
