//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> e)
  {
      map<int,int> mp;
      for(int i=0;i<n;i++)
      {
          if(e[i]!=-1)
             mp[e[i]]+=i;
      }
      int ans,f=-1;
      for(auto it:mp)
      {
          if(it.second>=f)
          {
              f=it.second;
              ans=it.first;
          }
      }
      if(mp.size()==0)
      return 0;
      return ans;
      // code here
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends