class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int suma=0,sumb=0;
        for(auto it:aliceSizes)
            suma+=it;
        set<int> s;
        for(auto it:bobSizes){
            sumb+=it;
            s.insert(it);
        }
        for(auto it:aliceSizes)
        {
            if(s.find(it+(sumb-suma)/2)!=s.end())
            return {it,it+(sumb-suma)/2};
        }
        return {};
    }
};