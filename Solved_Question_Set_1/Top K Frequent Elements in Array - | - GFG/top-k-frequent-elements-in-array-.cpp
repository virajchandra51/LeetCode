//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto it:nums)
        m[it]++;
        vector<pair<int,int>> v(m.size());
        for(auto it:m)
        v.push_back({it.second,it.first});
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=v.size()-1;i>=(v.size()-k);i--)
        ans.push_back(v[i].second);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends