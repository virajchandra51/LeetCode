//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool helper(int a[], int n, int k, int currsum, int st, vector<int> &vis, int tar)
    {
        if(k==0)
        return true;
        if(currsum==tar)
        return helper(a,n,k-1,0,0,vis,tar);
        for(int i=st;i<n;i++)
        {
            if(vis[i] || currsum+a[i]>tar) continue;
            vis[i]=1;
            if(helper(a,n,k,currsum+a[i],i,vis,tar)==true) return true;
            vis[i]=0;
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        // doing this by currsum and visited array
        int tar = 0;
        for(int i=0;i<n;i++)
        tar+=a[i];
        if(k>tar) return false;
        if(tar%k!=0) return false;
        tar/=k;
        vector<int> vis(n,0);
        return helper(a,n,k,0,0,vis,tar);
        //Your code here
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends