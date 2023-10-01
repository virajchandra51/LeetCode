//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        if(N<M) return -1;
        int c=1;
        int food = N;
        while(S--)
        {
            food-=M;
            if(food<M && S%7!=0)
            {
                food+=N;
                if(S!=0)
                c++;
            }
            if(food<0) return -1;
            // cout<<food<<" "<<c<<endl;
        }
        return c;
    } 
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends