// The total number of ways to place two knights on an n x n board 
//can be calculated using combination formula:
// (n * n) choose 2 = (n * n) * (n * n - 1) / 2

// Next, we need to find the number of 2x3 rectangles inside the n x n board.
// The number of 2x3 rectangles in an n x n board is given by:
// (n - 1) * (n - 2) + (n - 2) * (n - 1)

// In every 2x3 rectangle, there are two possible ways to place the knights such that they attack each other.
// Therefore, the total number of ways to place two knights such that they attack each other is:
// 4 * (n - 1) * (n - 2)

// The final answer, which is the number of ways to place two knights on an n x n board 
//such that they do not attack each other, is given by:
// (n * n) * (n * n - 1) / 2 - 4 * (n - 1) * (n - 2)



#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll fun(ll k)
{
    if(k==1) return 0;
    // (n^2)C2 - 4(n-1)(n-2)
    return (k*k)*(k*k-1)/2 - 4*(k-1)*(k-2);

}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cout<<fun(i)<<endl;
}
