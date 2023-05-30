//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<char,int> m;
        for(auto it:s) m[it]++;
        priority_queue<int> q;
        for(auto it:m)
        q.push(it.second);
        while(k--)
        {
            int a = q.top();
            q.pop();
            a--;
            if(a>0)
            q.push(a);
        }
        int ans=0;
        while(!q.empty())
        {
            ans+=(pow(q.top(),2));
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends