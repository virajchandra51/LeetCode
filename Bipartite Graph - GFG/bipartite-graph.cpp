//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, int parent, int color, vector<int>&colora, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        colora[node] = color;
        for(auto it:adj[node])
        {
            if(it==parent) continue;
            // cout<<it<<endl;
            if(!vis[it])
            {
                if(dfs(it,node,!color,colora,adj,vis)==false) return false;
            }
            else
            {
                if(colora[it]!=-1 && colora[it]==colora[node])
                {
                    // cout<<it<<node<<endl;
                    return false;
                }
                // return false;
            }
        }
        return true;
    }
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    int color = 0;
	    vector<int> vis(n+1,0);
	    vector<int> colora(n+1,-1);
	    for(int i=0;i<n;i++)
	    {
	        if(!vis[i])
	        {
	            if(dfs(i,-1,color,colora,adj,vis)==false)
	            {
                    // cout<<i<<endl;
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends