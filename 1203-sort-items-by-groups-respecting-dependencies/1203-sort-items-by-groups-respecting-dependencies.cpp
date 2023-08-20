class Solution {
public:
    // kahn's Algorithm
    vector<int> topoSort( vector<int> adj[], vector<int> &inDegree ){

        vector<int> ans;
        queue<int> q;

        // for each loop will not work
        for(int i = 0; i<inDegree.size() ; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        while( !q.empty() ){
            int node = q.front();
            q.pop();
            ans.push_back( node );

            for( auto &it : adj[node] ){
                inDegree[it]--;
                if( inDegree[it] == 0 ) q.push( it );
            }
        }

        return ans ;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        // step 1 : assign group to items having group -1;
        for( int i=0 ; i<n ; i++ ){
            if( group[i] == -1 ) group[i] = m++;
        }

        // step 2 : make 2 graphs, ItemGraph, GroupGraph
        vector<int> itemAdj[n];
        vector<int> groupAdj[m];

        vector<int> itemIndegree( n, 0 );
        vector<int> grpIndegree( m, 0 );

        for( int i=0 ; i<n ; i++ ){
            for( auto &it : beforeItems[i] ){
                // item adjacency 
                int u = it;
                int v = i;
                itemAdj[u].push_back(v);
                itemIndegree[v]++;

                // group adjacency
                int grpU = group[it];
                int grpV = group[i];
                if( grpU != grpV ){ 
                    groupAdj[grpU].push_back( grpV );
                    grpIndegree[grpV]++; 
                }
            }
        }

        // step 3 : create a topoSort for both the graphs
        vector<int> itemTopoSort = topoSort( itemAdj, itemIndegree );
        if( itemTopoSort.size() != n ) return {};

        vector<int> grpTopoSort = topoSort( groupAdj, grpIndegree );
        if( grpTopoSort.size() != m ) return {};

        // step 4 : make an hashmap of {group, item}
        // itemTopoSort helps in finding out the order within the items
        unordered_map<int, vector<int>> mp;
        for( auto &it : itemTopoSort ){
            mp[group[it]].push_back(it);
        }

        vector<int> ans;

        // step 5 : generate ans with the help of grpTopoSort
        // grpTopoSort helps in finding out the order within the groups
        for( auto &gp : grpTopoSort ){
            for( auto &it : mp[gp] ){
                ans.push_back( it );
            }
        }

        return ans;
    }
};