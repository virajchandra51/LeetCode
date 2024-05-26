class DSU {
private:
public:
    vector<int> rank, par, size;

    DSU(int n = 0) {
        rank.resize(n + 1);
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }

    int findUpar(int node) {
        if (node == par[node])
            return node;
        return par[node] = findUpar(par[node]);//path comp
    }

    void unionbyRank(int u, int v) {
        int UparU = findUpar(u);
        int UparV = findUpar(v);
        if (UparU == UparV)
            return;
        if (rank[UparU] < rank[UparV]) {
            par[UparU] = UparV;
        } else {
            par[UparV] = UparU;
            rank[UparU] += (rank[UparU] == rank[UparV]);
        }
    }

    void unionbySize(int u, int v) {
        int UparU = findUpar(u);
        int UparV = findUpar(v);
        if (UparU == UparV)
            return;
        if (size[UparU] < size[UparV]) {
            par[UparU] = UparV;
            size[UparV] += size[UparU];
        } else {
            par[UparV] = UparU;
            size[UparU] += size[UparV];
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                edges.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j});
            }
        }
        sort(edges.begin(),edges.end());
        int minDis = 0;
        DSU dsu(points.size()+1); // n
        for(auto it:edges)
        {
            if (dsu.findUpar(it[1]) == dsu.findUpar(it[2])) { // 1
                continue;
            }
            dsu.unionbySize(it[1], it[2]); // 1
            minDis += it[0];
        }
        return minDis;
    }
};