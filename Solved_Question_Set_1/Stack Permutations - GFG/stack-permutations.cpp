//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> s;
        int j = 0;
        int i = 0;
        while(i<N)
        {
            if(A[i]!=B[j])
            {
                s.push(A[i]);
                i++;
            }
            else
            {
                s.push(A[i]);
                i++;
                while(j<N && s.empty()==false && s.top()==B[j])
                {
                    s.pop();
                    j++;
                }
            }
        }
        return s.size()==0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends