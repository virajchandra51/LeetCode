//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        map<string,int> m;
        for(auto it:B) m[it]++;
        int n = A.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(m.find(A.substr(j,i-j+1))!=m.end())
                dp[i+1] |= dp[i+1-(i-j+1)];
            }
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends