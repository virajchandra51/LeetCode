//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<vector<vector<int>>> dp;
    int helper(int n, int k, int t, vector<int>& coins, int i, vector<vector<vector<int>>> &dp)
    {
        if(t<0) return 0;
        if(i==n)
        {
            if(k==0 && t==0) return 1;
            else return 0;
        }
        if(k==0)
        {
            if(t==0) return 1;
            else return 0;
        }
        if(t==0)
        {
            if(k==0) return 1;
            else return 0;
        }
        if(dp[i][k][t]!=-1) return dp[i][k][t];
        int take = helper(n,k-1,t-coins[i],coins,i,dp);
        return dp[i][k][t] = take | helper(n,k,t,coins,i+1,dp);
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        dp.resize(N+1,vector<vector<int>>(K+1,vector<int>(target+1,-1)));
        return helper(N,K,target,coins,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends