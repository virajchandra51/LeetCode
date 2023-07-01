//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        int xx = x;
        int yy = y;
        xx>>=(l-1);
        yy>>=(l-1);
        // cout<<xx<<endl;
        // cout<<yy<<endl;
        xx&=((1<<(r-l+1))-1);
        yy&=((1<<(r-l+1))-1);
        // cout<<xx<<endl;
        // cout<<yy<<endl;
        xx|=yy;
        xx<<=(l-1);
        x|=xx;
        return x;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends