//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        int v[10] = {2000,500,200,100,50,20,10,5,2,1};
        vector<int> ans;
        int i = 0;
        while(i<10)
        {
            int f = N/v[i];
            for(int j=0;j<f;j++)
            {
                N-=v[i];
                ans.push_back(v[i]);
            }
            i++;
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends