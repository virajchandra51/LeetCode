//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function

long long int helper(vector<long long int> &a, int n, int st, vector<vector<long long int>> &dp)
{
    if(n==0) return 1;
    if(dp[n][st]!=-1) return dp[n][st];
    long long int w = 0;
    for(int id=st;id<3;id++)
    {
        if(n-a[id]>=0)
        {
            w+=helper(a,n-a[id],id,dp);
        }
    }
    return dp[n][st] = w;
}

long long int count(long long int n)
{
	vector<vector<long long int>> dp(n+1,vector<long long int>(3,-1));
	vector<long long int> a = {3,5,10};
// 	vector<long long int> dp(n+1,0);
// 	dp[0]=1;
// 	for(int i=1;i<=n;i++)
// 	{
// 	    if(i-3>=0)
// 	    dp[i]+=dp[i-3];
// 	    if(i-5>=0)
// 	    dp[i]+=dp[i-5];
// 	    if(i-10>=0)
// 	    dp[i]+=dp[i-10];
// 	}
// 	return dp[n];
    return helper(a,n,0,dp);
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends