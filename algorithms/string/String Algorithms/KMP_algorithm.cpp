/*
Knuth-Morris-Pratt (KMP) Algorithm for Pattern Searching
The Knuth-Morris-Pratt (KMP) algorithm is a powerful string searching algorithm that efficiently finds occurrences of a pattern within a text. 
It is renowned for its linear time complexity, making it highly efficient for large datasets.

LPS (Longest Prefix Suffix) Array
One of the key components of the KMP algorithm is the Longest Prefix Suffix (LPS) array. This array is instrumental 
in determining how far the algorithm can skip characters in the text without rechecking them.
The LPS array essentially helps in avoiding unnecessary comparisons by utilizing the information about the previously matched characters.

*/
//below lps function returns the lps array for the given string

#include<bits/stdc++.h>
using namespace std;

vector<int> lps(string s)
{
    int n = s.size();
    vector<int> lps(n,0);
    int pref =0;
    int suff = 1;
    while(suff < n)
    {
        if(s[pref] == s[suff])
        {
            lps[suff] = 1 + pref;
            suff++;
            pref++;
        }
        else
        {
            if(pref == 0)
            {
                lps[suff] = 0;
                suff++;
            }
            else
            {
                pref = lps[pref - 1];
            }
        }
    }
    return lps;
}

int main()
{
    string str;
    cin>>str;
    vector<int> lps_array = lps(str);
    
    for(auto x: lps_array)
    cout<<x<<" ";
}
