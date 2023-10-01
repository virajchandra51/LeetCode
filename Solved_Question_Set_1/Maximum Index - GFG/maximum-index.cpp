//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int>left(n), right(n);
        left[0]= arr[0];
        for(int i=1; i<n; i++){
            left[i]= min(arr[i], left[i-1]);
        }
        right[n-1]= arr[n-1];
         for(int j=n-2; j>=0; j--){
            right[j]= max(arr[j], right[j+1]);
        }
        int i =0, j=0, maxdiff=0;
        while(j<n and i<n){
            if(arr[i]<= right[j]){
                maxdiff= max(maxdiff, j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        if(maxdiff==0) return 0;
        else  return maxdiff;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends