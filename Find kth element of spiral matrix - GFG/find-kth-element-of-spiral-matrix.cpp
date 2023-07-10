//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
        int top = 0;
        int bottom = n-1;
        int right = m-1;
        int left = 0;
        int ele;
        while(true)
        {
            for(int i=left;i<=right;i++)
            {
                ele = a[top][i];
                // cout<<ele<<" ";
                k--;
                if(k==0) return ele;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                ele = a[i][right];
                k--;
                // cout<<ele<<" ";
                if(k==0) return ele;
            }
            right--;
            for(int i=right;i>=left;i--)
            {
                ele = a[bottom][i];
                k--;
                // cout<<ele<<" ";
                if(k==0) return ele; 
            }
            bottom--;
            for(int i=bottom;i>=top;i--)
            {
                ele = a[i][left];
                k--;
                // cout<<ele<<" ";
                if(k==0) return ele;
            }
            left++;
        }
        return -1;
 		// Your code goes here.
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends