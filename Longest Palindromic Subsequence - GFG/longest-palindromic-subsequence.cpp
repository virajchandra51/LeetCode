//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string a) {
        //code here
        int n = a.size();
        string b = a;
        reverse(b.begin(),b.end());
        int dp[2][n+1];
        bool bi;
        for(int i=0;i<=n;i++)
        {
            bi = i&1;
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0) dp[bi][j]=0;
                else if(a[i-1]==b[j-1]) dp[bi][j]=1+dp[1-bi][j-1];
                else dp[bi][j] = max(dp[1-bi][j],dp[bi][j-1]);
            }
        }
        return dp[bi][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends