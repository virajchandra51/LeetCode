//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &a) {
        stack<int> s;
        for(auto it:a)
        {
            s.push(it);
            while(s.size()>1 && it<0 && s.top()==it)
            {
                int n = s.top();
                s.pop();
                int nn = s.top();
                s.pop();
                if(nn<0)
                {
                    s.push(nn);
                    s.push(n);
                    break;
                }
                if(abs(n)>nn)
                    s.push(n);
                else if(abs(n)==nn)
                {}
                 else s.push(nn);
            }
        }
        vector<int> ans;
        while(!s.empty())
            ans.push_back(s.top()),s.pop();
        reverse(ans.begin(),ans.end());
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends