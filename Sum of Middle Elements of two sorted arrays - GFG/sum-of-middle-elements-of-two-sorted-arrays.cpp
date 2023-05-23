//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
        int l = 0;
        int h = n;
        while(l<=h)
        {
            int cut1 = (l+h)>>1;
            int cut2 = n-cut1;
            int l1 = cut1==0?INT_MIN:ar1[cut1-1];
            int l2 = cut2==0?INT_MIN:ar2[cut2-1];
            int r1 = cut1==n?INT_MAX:ar1[cut1];
            int r2 = cut2==n?INT_MAX:ar2[cut2];
            if(l1<=r2 && l2<=r1)
            return (max(l1,l2)+min(r1,r2));
            else if(l1>r2)
            h=cut1-1;
            else
            l=cut1+1;
        }
        return -1;
            
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends