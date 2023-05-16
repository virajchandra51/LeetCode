//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


int helper(vector<int>& p, int i, int k, bool bought, int n,vector<vector<vector<int>>> &dp)
{
    if(k==0 || i>=n) return 0;
    if(dp[i][k][bought]!=-1) return dp[i][k][bought];
    int s = helper(p,i+1,k,bought,n,dp);
    if(bought)
    s = max(s,helper(p,i+1,k-1,false,n,dp)+p[i]);
    else
    s = max(s,helper(p,i+1,k,true,n,dp)-p[i]);
    return dp[i][k][bought] = s;
}
int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    vector<vector<vector<int>>> dp;
    dp.resize(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
    return helper(price,0,2,false,n,dp);
    
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends