//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<vector<int>>> dp;
    int helper(int k, bool bought, int i, int n, int A[])
    {
        if(k==0 || i>=n)
        return 0;
        if(dp[i][bought][k]!=-1) return dp[i][bought][k];
        int nottake = helper(k,bought,i+1,n,A), take = INT_MIN;
        if(bought)
        take=helper(k-1,false,i+1,n,A)+A[i];
        else
        take=helper(k,true,i+1,n,A)-A[i];
        return dp[i][bought][k] = max(take,nottake);
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        dp.resize(N+1,vector<vector<int>>(3,vector<int>(K+1,-1)));
        return helper(K,false,0,N,A);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends