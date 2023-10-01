//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool canBe(vector<int> &a, int n, int k, int pla)
    {
        int fi = a[0]; int cnt = 1;
        for(int i=1;i<n;i++)
        {
            if(a[i]-fi>=pla)
            {
                fi=a[i];
                cnt++;
            }
            if(cnt==k)
            return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int l = 1;
        int h = stalls[n-1]-stalls[0];
        int res;
        while(l<=h)
        {
            int mi = (l+h)>>1;
            if(canBe(stalls,n,k,mi))
            {
                res=mi;
                l=mi+1;
            }
            else
            {
                h=mi-1;
            }
        }
        return res;
        // Write your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends