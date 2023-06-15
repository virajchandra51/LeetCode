//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	vector<vector<int>> dp;
	int helper(int coins[], int m, int v, int i)
	{
	    if(i>=m)
	    {
	        if(v==0) return 0;
	        return 1e9;
	    }
	    if(v==0) return 0;
	    if(dp[v][i]!=1e9) return dp[v][i];
	    int nottake = helper(coins,m,v,i+1);
	    int take = 1e9;
	    if(coins[i]<=v)
	    take = 1+helper(coins,m,v-coins[i],i);
	    return dp[v][i] = min(take,nottake);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    dp.resize(V+1,vector<int>(M+1,1e9));
	    int ans = helper(coins,M,V,0);
	    if(ans==1e9) return -1;
	    return ans;
	    // Your code goes here
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends