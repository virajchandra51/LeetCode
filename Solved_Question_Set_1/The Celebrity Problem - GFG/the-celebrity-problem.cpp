//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int N) 
    {
        for(int i=0;i<N;i++)
        {
            if(M[0][i]==0)
            {
                int s = 0;
                for(int j=1;j<N;j++)
                s+=M[j][i];
                if(s==(N-1)) return 0;
            }
            else
            {
                int f=0;
                int s=1;
                for(int j=1;j<N;j++)
                {
                    if(M[j][i]==0) f=1;
                    s+=M[j][i];
                }
                if(f==1 && s==(N-1))
                {
                    int ans;
                    for(int j=1;j<N;j++)
                    {
                        if(M[j][i]==0) 
                        {
                            ans=j;break;
                        }
                    }
                    int ss=0;
                    for(int j=0;j<N;j++)
                    {
                        ss+=M[ans][j];
                    }
                    if(ss==0) return ans;
                }
            }
        }
        return -1;
        // code here 
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends