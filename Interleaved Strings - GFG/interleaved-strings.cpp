//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    vector<vector<int>> dp;
    int helper(int i, int j, int k, int a, int b, int c, string A, string B, string C)
    {
        if(k>=c) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(A[i]==C[k] && B[j]==C[k])
        ans|=(helper(i+1,j,k+1,a,b,c,A,B,C)|helper(i,j+1,k+1,a,b,c,A,B,C));
        else if(A[i]==C[k])
        ans|=(helper(i+1,j,k+1,a,b,c,A,B,C));
        else if(B[j]==C[k])
        ans|=(helper(i,j+1,k+1,a,b,c,A,B,C));
        else ans = 0;
        return dp[i][j] = ans;
    }
    bool isInterleave(string A, string B, string C) 
    {
        dp.resize(A.size()+1,vector<int>(B.size()+1,-1));
        return helper(0,0,0,A.size(),B.size(),C.size(),A,B,C);
        //Your code here
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends