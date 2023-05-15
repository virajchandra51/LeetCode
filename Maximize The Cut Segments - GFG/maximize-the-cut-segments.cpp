//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> dp;
    //Function to find the maximum number of cuts.
    int helper(int n, int i, vector<int> &a)
    {
        if(i>=a.size()) 
        {
            if(n==0) return 0;
            else return 0;
        }
        // if(n<0) return 0;
        if(n==0) return 0;
        if(dp[n][i]!=-1) return dp[n][i];
        int c = INT_MIN;
        for(int id=i;id<3;id++)
        {
            if(n-a[id]>=0)
            c = max(c,1+helper(n-a[id],id,a));
        }
        return dp[n][i] = c;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> a = {x,y,z};
        sort(a.begin(),a.end());
        if(a[0]>n) return 0;
        dp.resize(n+1,vector<int>(3,-1));
        return helper(n,0,a)<0?0:helper(n,0,a);
        //Your code here
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends