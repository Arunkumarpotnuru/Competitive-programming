// If n=1, the answer will be {1}, which represents an edge case.
// For n=2 and n = 3, there will be no valid permutations.
// For n=4, there will be two permutations: {2, 4, 1, 3} and {3, 1, 4, 2}.

// Consider {2, 4, 1, 3}.
// To generate more permutations, iterate from 5 to n inclusively, 
// and add i to the left if i is even; otherwise, add it to the right side.
// In this way, we can create valid permutations.

#include<bits/stdc++.h>
using namespace std;
vector<int> fun(int n)
{
    if(n==1) return {1};
    if(n==2 or n==3) return{};
    vector<int>arr = {2,4,1,3};
    vector<int>odd,even;
    
    vector<int>ans;
    for(int i=6;i<=n;i=i+2)
    ans.push_back(i);

    for(auto x: arr) ans.push_back(x);

    for(int i=5;i<=n;i=i+2)
    ans.push_back(i);

    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>ans = fun(n);
    if(ans.size()==0)
    cout<<"NO SOLUTION"<<endl;
    else
    {
        for(int x: ans)
        cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
