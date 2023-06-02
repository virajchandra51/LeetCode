//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  pair<int,int> getS(vector<int>& v)
  {
      map<int,int> m;
      int sum = 0;
      int maxi = 0;
      m[0]=-1;
      pair<int,int> res = {-1,-1};
      for(int i=0;i<v.size();i++)
      {
          sum+=v[i];
          if(m.find(sum)!=m.end())
          {
              if(i-m[sum]>maxi)
              {
                  maxi=i-m[sum];
                  res={m[sum]+1,i};
              }
          }
          else
          m[sum]=i;
      }
      return res;
  }
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      int n = a.size();
      int m = a[0].size();
      int startR=INT_MAX,endR=INT_MAX,startC=INT_MAX,endC=INT_MAX;
      int si = INT_MIN;
      for(int i=0;i<n;i++)
      {
          vector<int> v(m,0);
          for(int j=i;j<n;j++)
          {
              for(int k=0;k<m;k++)
              v[k]+=a[j][k];
              auto it = getS(v);
              if(it.first==-1) continue;
              int tr1 = i;
              int tr2 = j;
              int tc1 = it.first;
              int tc2= it.second;
              int s = (j-i+1)*(tc2-tc1+1);
              if(s>si || (s==si && tc1<startC))
              {
                  si=s;
                  startR = i;
                  endR = j;
                  startC = tc1;
                  endC = tc2;
              }
          }
      }
      vector<vector<int>> ans;
      if(startR==INT_MAX) return ans;
      for(int i=startR;i<=endR;i++)
      {
          vector<int> t;
          for(int j=startC;j<=endC;j++)
          {
              t.push_back(a[i][j]);
          }
          ans.push_back(t);
      }
      return ans;
  }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends