//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int mat[MAX][MAX], int n, int m) {
        // Your code here
        int ans = INT_MIN;
        vector<int> v(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    v[j]++;
                else
                    v[j] = 0;
            }
            vector<int> nextS(m,m),prevS(m,-1);
            stack<int> s;
            for(int j=0;j<m;j++)
            {
                if(s.empty()==true)
                    s.push(j);
                else
                {
                    while(s.empty()==false && (v[s.top()])>(v[j]))
                    {
                        nextS[s.top()]=j;
                        s.pop();
                    }
                    s.push(j);
                }
            }
            while(!s.empty()) s.pop();
            for(int j=m-1;j>=0;j--)
            {
                if(s.empty()==true)
                    s.push(j);
                else
                {
                    while(s.empty()==false && (v[s.top()])>(v[j]))
                    {
                        prevS[s.top()]=j;
                        s.pop();
                    }
                    s.push(j);
                }
            }
            for(int j=0;j<m;j++)
            ans = max(ans,(v[j])*(nextS[j]-prevS[j]-1));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends