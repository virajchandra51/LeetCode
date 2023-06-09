//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& p) {
	    // Code here
	    vector<int> t;
	    vector<vector<int>> adj(n+1,vector<int>());
	    vector<int> in(n,0);
	    queue<int> q;
	    for(auto it:p)
	    {
	        adj[it.second].push_back(it.first);
	        in[it.first]++;
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(in[i]==0) q.push(i);
	    }
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        t.push_back(node);
	        for(auto it:adj[node])
	        {
	            in[it]--;
	            if(in[it]==0) q.push(it);
	        }
	    }
	    return t.size()==n;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends