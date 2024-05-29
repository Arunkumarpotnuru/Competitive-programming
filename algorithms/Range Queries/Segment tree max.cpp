#include<bits/stdc++.h>
using namespace std;
void build(int ind,int low , int high,int arr[],int seg[])
{
    int mid = (low+high)/2;
    build(2*ind+1,low,mid,arr,seg);
    build(2*ind+2,mid+1,high,arr,seg);

    seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
}
int query(int ind,int low ,int high,int l,int r,int arr[],int seg[]) 
{
    if(low>= l and high<= r) return seg[ind];
    if(low> r or high<l) return INT_MIN;

    int mid = (low+high)/2;
    int left = query(2*ind+1,low,mid,l,r,arr,seg);
    int right = query(2*ind+2,mid+1,high,l,r,arr,seg);

    return max(left,right);
}
void update(int ind,int low ,int high,int node,int val,int arr[],int seg[])
{
    if(low == high)
    {
        seg[ind]+= val;
        arr[node]+= val;
    }
    else
    {
        int mid = (low+high)/2;
        if(node>= low and node<= mid) update(2*ind+1,low,mid,node,val,arr,seg);
        else update(2*ind+2,mid+1,high,node,val,arr,seg);

        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n]; // given array
    for(int i =0;i<n;i++) cin>>arr[i];

    int seg[4*n];

    build(0,0,n-1,arr,seg);// function to build the segment tree

    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r,arr,seg);
    }
}
