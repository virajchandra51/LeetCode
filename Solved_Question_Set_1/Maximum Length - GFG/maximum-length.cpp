//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int a, int b, int c) {
        // code here
        if(a>=b && a>=c)
        {
            if(a>(b+c)*2) return -1;
            else
            {
                return a+b+c;
            }
        }
        else if(b>=a && b>=c)
        {
            if(b>(a+c)*2) return -1;
            return a+b+c;
        }
        if(c>(a+b)*2) return -1; 
        return a+b+c;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends