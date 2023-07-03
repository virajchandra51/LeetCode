//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &arr) {
        int ans = 0;
        int first = arr[0];
        int second = 1e4;
        int i = 0;
        int j = 0;
        int count = 1;
        while(j<n){
            if(count==1){
                if(arr[j]==first){
                    j++;
                }
                else{
                    second = arr[j];
                    j++;
                    count++;
                }
            }
            else{
                if(arr[j]==first){
                    j++;
                }
                else if(arr[j]==second){
                    j++;
                }
                else{
                    ans = max(ans, j-i);
                    i++;
                    first = arr[i];
                    count--;
                    j = i;
                }
            }
        }
        // cout<<j<<" "<<i<<endl;
        ans = max(ans, j-i);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends