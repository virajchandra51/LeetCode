//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int r1 = -1;
	    int r2 = -1;
	    int l = 0;
	    int r = n-1;
	    while(l<=r)
	    {
	        int mid = (l+r)>>1;
	        if(arr[mid]<=x)
	        {
	            r1=mid;
	            l=mid+1;
	        }
	        else r=mid-1;
	    }
	    l = 0;
	    r = n-1;
	    while(l<=r)
	    {
	        int mid = (l+r)>>1;
	        if(arr[mid]<x)
	        {
	            r2=mid;
	            l=mid+1;
	        }
	        else r=mid-1;
	    }
	   // cout<<r1<<" "<<r2<<endl;
	    if(r1==-1) return 0;
	    return r1-r2;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends