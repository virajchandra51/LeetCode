class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& a) {
        sort(a.begin(),a.end());
        long long t=(long long)m;
        for(int i=0;i<a.size();i++)
        {
            if(t>=a[i])
                t+=a[i];
            else
                return false;
        }
        return true;
    }
};