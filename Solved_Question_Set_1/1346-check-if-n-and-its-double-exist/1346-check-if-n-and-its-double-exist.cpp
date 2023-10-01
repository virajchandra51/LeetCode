class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> m;
        for(auto it:arr) m[it]++;
        if(m.find(0)!=m.end() && m[0]>1) return true;
        for(auto it:m)
        {
            if(m.find(2*it.first)!=m.end() && it.first!=0) return true;
        }
        return false;
    }
};