//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> b;
       for(int i=0;i<n;i++)
       {
           if(b.size()==0) b.push_back(a[i]);
           else
           {
               auto it = upper_bound(b.begin(),b.end(),a[i])-b.begin();
               if(it==b.size()) b.push_back(a[i]);
               else b[it]=a[i];
           }
       }
       return b.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends