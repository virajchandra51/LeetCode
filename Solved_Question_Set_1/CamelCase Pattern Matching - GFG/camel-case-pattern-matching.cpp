//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string onlS(string s)
    {
        string a = "";
        for(auto it:s)
        {
            if(it<='Z')
            a+=it;
        }
        return a;
    }
    vector<string> CamelCase(int N, vector<string> d, string p) {
        // code here
        vector<string> dd(d.size());
        for(int i=0;i<d.size();i++)
        dd[i] = onlS(d[i]);
        vector<string> ans;
        for(int i=0;i<d.size();i++)
        {
            if(dd[i].size()<p.size()) continue;
            if (dd[i].substr(0,p.size())==p) {
    ans.push_back(d[i]);
}
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0) return {"-1"};
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
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends