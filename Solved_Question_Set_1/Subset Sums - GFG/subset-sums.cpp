//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> v;
    void helper(vector<int> arr, int n, int i, int s)
    {
        if(i>=n) 
        {
            v.push_back(s);
            return;
        }
        helper(arr,n,i+1,s);
        helper(arr,n,i+1,s+arr[i]);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        helper(arr,N,0,0);
        return v;
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends