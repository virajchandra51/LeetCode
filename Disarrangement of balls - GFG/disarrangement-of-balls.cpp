//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long int disarrange(int N){
        // code here
        vector<long long> dp(N+1,0);
        dp[1] = 0;
        dp[2] = 1;
        long long M = 1e9+7;
        for(long long i=3;i<=N;i++)
        dp[i] = (((i-1)%M)*(dp[i-1]%M+dp[i-2]%M))%M;
        return (long int)dp[N];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends