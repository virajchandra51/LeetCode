//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<long long int>> dp;
    long long int helper(int coins[], int i, int N, int sum)
    {
        if(sum<0) return 0;
        if(sum==0) return 1;
        if(i>=N)
        {
            if(sum==0) return 1;
            return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        long long int nottake = helper(coins,i+1,N,sum);
        long long int take = 0;
        if(sum-coins[i]>=0)
        take+=helper(coins,i,N,sum-coins[i]);
        return dp[i][sum] = take+nottake;
    }
    long long int count(int coins[], int N, int sum) {
        dp.resize(N+1,vector<long long int>(sum+1,-1));
        return helper(coins,0,N,sum);
        // code here.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends