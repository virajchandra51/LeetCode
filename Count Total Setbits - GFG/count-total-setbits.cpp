//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long n) {
        // code here
        long long s = ceil(n/2.0);
        long long nn = n;
        n>>=1;
        long long j=4;
        long long k=2;
        while(n>0)
        {
            s += ((nn/j)*k);
            long long ns = nn - (nn/j)*j +1;
            ns-=k;
            if(ns>0)
            s+=ns;
            k*=2;
            j*=2;
            n>>=1;
        }
        return s;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends