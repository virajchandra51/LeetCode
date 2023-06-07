//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int feasible(int A[], int N, long mid)
    {
        int c = 1;
        long long sum = 0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum>mid)
            {
                c++;
                sum=A[i];
            }
        }
        return c;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int l = INT_MIN; long r = 0;
        for(int i=0;i<N;i++)
        {l=max(l,A[i]);r+=A[i];}
        int ans;
        while(l<=r)
        {
            long mid = (l+r)>>1;
            // cout<<feasible(A,N,mid)<<" "<<mid<<endl;
            if(feasible(A,N,mid)<=M)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends