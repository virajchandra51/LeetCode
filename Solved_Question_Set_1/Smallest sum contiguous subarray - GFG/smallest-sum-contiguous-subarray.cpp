//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      // kadane ulta
      int m=INT_MAX;
      int s=0;
      int f=0;
      for(auto it:a)
      {
          if(it<0) f=1;
          s+=it;
          if(s>0)
          s=0;
          m=min(s,m);
      }
      if(f==0)
      {
          sort(a.begin(),a.end());
          return a[0];
      }
      return m;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends