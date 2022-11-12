//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        long long int s = ((long long int)n*(long long int)(n+1))/2;
        long long int s1=0;
        for(int i=0;i<n;i++)
        s1+=arr[i];
        
        sort(arr,arr+n);
        long long int ans[2];
        
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1])
            {
                ans[0]=arr[i];
                ans[1]=(s-(s1-arr[i]));break;
            }
        }
        int a[2];
        a[0]=ans[0];
        a[1]=ans[1];
        int *p =a;
        return p;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends