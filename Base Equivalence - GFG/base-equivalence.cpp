//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string baseEquiv(int n, int m){
        int temp = n;
        int c = 0;
        int num = 2;
        while(num<33)
        {
            while(temp>0)
            {
                temp/=num;
                c++;
            }
            if(c==m)
            return "Yes";
            c=0;
            temp=n;
            num++;
        }
        return "No";
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends