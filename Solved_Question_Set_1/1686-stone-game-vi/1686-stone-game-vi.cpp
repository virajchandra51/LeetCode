class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<a.size();i++)
            v.push_back({a[i]+b[i],{a[i],b[i]}});
        sort(v.rbegin(),v.rend());
        int aa = 0;
        int bb = 0;
        int f = 1;
        for(int i=0;i<v.size();i++)
        {
            if(f)
                aa+=v[i].second.first;
            else
                bb+=v[i].second.second;
            f=!f;
        }
        if(aa==bb) return 0;
        if(aa>bb) return 1;
        return -1;
    }
};