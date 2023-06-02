//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalin(string s, int i, int j)
    {
        while(j<=i)
        {
            if(s[i]!=s[j]) return false;
            i--;j++;
        }
        return true;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++)
        {
            int a = INT_MAX;
            for(int j=0;j<=i;j++)
            {
                if(isPalin(str,i,j))
                {
                    if(j==0)
                    a=min(a,0);
                    else
                    a=min(a,1+dp[j]);
                }
            }
            dp[i+1]=a;
        }
        // for(auto it:dp) cout<<it<<" ";
        // cout<<endl;
        return dp[n];
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends