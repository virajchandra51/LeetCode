//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        vector<int> a,b;
        for(int i = 0 ;i<(n/2);i++) a.push_back(arr[i]);
        for(int i=n/2;i<n;i++) b.push_back(arr[i]);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(auto &it:b) it*=5;
        int c=0;
        for(auto it:a)
        {
            auto i = upper_bound(b.begin(),b.end(),it)-b.begin();
            c+=i;
        }
        return c;
        // 2 8 10 5 5 10
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends