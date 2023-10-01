//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int countBT(int h) { 
        // code here
        long long int m = 1e9+7;
        vector<long long> dp(h+1,0);
        dp[1]=1;
        dp[0]=1;
        for(int i=2;i<=h;i++)
        dp[i] = ((dp[i-1]%m)*((2*dp[i-2])%m+dp[i-1]%m))%m;
        return dp[h];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends