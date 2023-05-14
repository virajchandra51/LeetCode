//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        int M = 1e9+7;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        for(long i=3;i<=n;i++)
        dp[i] = (dp[i-1]%M + (dp[i-2]%M)*((i-1)%M))%M;
        // for(auto it: dp) cout<<it<<" ";
        return dp[n];
        //1 2 3 4 5 6
        //1 2 4 10 26 76
    }
    
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends