//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// 6 3 2 8 7 5, k=3
// l = 1, r = 31
// mid = 16, p = 1
// l = 1, r = 16
// mid = 8, p = 3
// l= 9, r = 16
// mid = 12, p = 2
// l = 9, r = 12
// mid = 10, p = 2
// l = 9, r = 10
// mid = 9 p = 3


class Solution{
    public:
    bool f(vector<int>& s, long mid, int n, int k)
    {
        long su = 0;
        int c=0;
        k++;
        for(int i=0;i<n;i++)
        {
            su+=s[i];
            if(su>=mid)
            {
                su=0;
                c++;
            }
        }
        if(su>=mid) c++;
        return c>=k;
    }
    int maxSweetness(vector<int>& s, int n, int k) {
    // Write your code here.
        long l = 1;
        long r = 0;
        for(auto it:s) r+=it;
        while(l<r)
        {
            long mid = (l+r)>>1;
            if(!f(s,mid,n,k))
            r=mid;
            else
            l=mid+1;
        }
        return f(s,r,n,k)?r:r-1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends