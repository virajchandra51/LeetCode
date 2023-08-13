//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// User function Template for C++
class Solution {
  public:
    long long int M = 1e9+7;
    void mult(vector<vector<long long int>> &m1, vector<vector<long long int>> &m2)
    {
        vector<vector<long long int>> temp(2,vector<long long int>(2,1));
        temp[0][0] = ((m1[0][0]%M * m2[0][0]%M)%M + (m1[0][1]%M * m2[1][0]%M)%M)%M;
        temp[0][1] = ((m1[0][0]%M * m2[0][1]%M)%M + (m1[0][1]%M * m2[1][1]%M)%M)%M;
        temp[1][0] = ((m1[1][0]%M * m2[0][0]%M)%M + (m1[1][1]%M * m2[1][0]%M)%M)%M;
        temp[1][1] = ((m1[1][0]%M * m2[0][1]%M)%M + (m1[1][1]%M * m2[1][1]%M)%M)%M;
        m1 = temp;
    }
    void mat_power(vector<vector<long long int>>& m, int n)
    {
        if(n==1) return;
        mat_power(m,n/2);
        mult(m,m);
        vector<vector<long long int>> mm = {{1,1},{1,0}};
        if(n&1)
        mult(m,mm);
    }
    long long int nthFibonacci(long long int n){
        // code here
        vector<vector<long long int>> m = {{1,1},{1,0}};
        if(n==0) return 0;
        mat_power(m,n);
        return m[0][1]%M;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends