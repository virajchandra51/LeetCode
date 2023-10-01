//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int helper(int A[], int n, int i, int p)
    {
        if(i>=n) return 0;
        if(dp[i][p+1]!=-1) return dp[i][p+1];
        int nottake = helper(A,n,i+1,p);int take=INT_MIN;
        if(p==-1 || abs(A[i]-A[p])==1) take=1+helper(A,n,i+1,i);
        return dp[i][p+1]=max(nottake,take);
    }
    int longestSubsequence(int N, int A[])
    {
        dp.resize(N+1,vector<int>(N+1,-1));
        return helper(A,N,0,-1);
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends