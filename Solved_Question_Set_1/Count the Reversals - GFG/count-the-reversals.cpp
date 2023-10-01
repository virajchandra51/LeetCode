//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    int ans=0;
    int c=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='}')
        {
            if(c>0)
            c--;
            else{
                ans++;
                c++;
            }
        }
        else
        c++;
    }
    if(c&1) return -1;
    return ans+c/2;
    // your code here
}