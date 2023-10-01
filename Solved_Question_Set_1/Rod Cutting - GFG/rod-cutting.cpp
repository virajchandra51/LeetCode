//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    vector<vector<int>> dp;
    int helper(int price[], int i, int rodL, int n)
    {
        if(i>=n) return 0;
        if(dp[i][rodL]!=-1) return dp[i][rodL];
        int nottake = helper(price,i+1,rodL,n);
        int take = INT_MIN;
        if((i+1)<=rodL)
        take = price[i]+helper(price,i,rodL-(i+1),n);
        return dp[i][rodL] = max(take,nottake);
    }
    int cutRod(int price[], int n) {
        //code here
        dp.resize(n+1,vector<int>(n+1,-1));
        return helper(price,0,n,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends