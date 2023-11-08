class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        vector<vector<int>> v;
        v.push_back({sx,sy});
        v.push_back({fx,fy});
        sort(v.begin(),v.end());
        if(v[1]==v[0]) return t!=1;
        int m = 0;
        m+=(v[1][0]-v[0][0]);
        m+=max(0,abs(v[1][1]-v[0][1])-(v[1][0]-v[0][0]));
        cout<<m<<endl;
        return (t>=m);
    }
};

