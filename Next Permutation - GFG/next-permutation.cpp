//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int ind = N-1;
        while(ind-1>=0 && arr[ind]<=arr[ind-1])
        ind--;
        if(ind==0)
        {
            reverse(arr.begin(),arr.end());
            return arr;
        }
        ind--;
        int i=N-1;
        while(arr[i]<=arr[ind])
        i--;
        swap(arr[i],arr[ind]);
        reverse(arr.begin()+ind+1,arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends