
// sum of numbers from 1 to n is equal to tot=(n*(n+1))/2. so substracting the total sum of given numbers from tot will be the missing number
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int tot= (n*(n+1))/2,sum=0;
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        sum+=x;
    }
    cout<<tot-sum<<endl;
    return 0;
}
