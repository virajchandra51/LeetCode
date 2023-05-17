//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// 18 23 32 49 51 68 71 76 79 90
// 21
// 1 2 5 6 8

class Solution{
    public:
    int removals(vector<int>& a, int k){
        //Code here
        sort(a.begin(),a.end());
        int n = a.size();
        long ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            auto it = upper_bound(a.begin(),a.end(),a[i]+k)-a.begin();
            // cout<<it<<endl;
            // if(it-i==1) continue;
            ans=min(ans,n-(it-i));
        }
        return (int)ans==INT_MAX?1:ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends