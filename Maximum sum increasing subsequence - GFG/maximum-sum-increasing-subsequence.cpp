//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
 	 int solveMem(int curr, int prev, int arr[], int n,vector<vector<int>>&dp)
    {
       if(curr >= n) return 0;
       
       if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
       
       int incl = 0;
       if(prev == -1 || arr[curr] > arr[prev]) 
        incl = arr[curr] + solveMem(curr+1,curr,arr,n,dp);
        
       int excl = 0 + solveMem(curr+1, prev,arr,n,dp);
       
       return dp[curr][prev+1] = max(incl,excl);
    }
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
	    return solveMem(0,-1,arr,n,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends