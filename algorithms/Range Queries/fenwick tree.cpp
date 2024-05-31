#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int sum(int i,vector<int>&fen) 
{
    int ans = 0;
    while(i>0)
    {
        ans+= fen[i];
        i = i - (i & (-i));
    }
    return ans;
}
void add(int i,int val,vector<int>&fen)
{
    while(i<fen.size())
    {
        fen[i]+= val;
        i = i+(i & (-i));
    }
}
int find(int k,vector<int>&fen)//kth order statistics
{
    int l=1,r = fen.size()-1;
    int num=0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(sum(mid,fen) >= k)
        {
            num = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    return num;
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>fen(n+1,0);
}
