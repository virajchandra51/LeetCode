//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> a)
    {
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(j==0)
                {
                    int m = a[i-1][j];
                    if(j+1<N)
                    m=max(m,a[i-1][j+1]);
                    a[i][j]+=m;
                }
                else if(j==(N-1))
                {
                    int m = a[i-1][j];
                    if(j-1>=0)
                    m=max(m,a[i-1][j-1]);
                    a[i][j]+=m;
                }
                else
                {
                    int m = a[i-1][j];
                    if(j-1>=0)
                    m=max(m,a[i-1][j-1]);
                    if(j+1<N)
                    m=max(m,a[i-1][j+1]);
                    a[i][j]+=m;
                }
            }
        }
        int an=INT_MIN;
        for(int i=0;i<N;i++)
        an=max(an,a[N-1][i]);
        return an;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends