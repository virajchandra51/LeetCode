class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
       map<int,int> d;
        for(auto it:deck)
            d[it]++;
        int g = d[deck[0]];
        for(auto it:d)
        g = __gcd(g,it.second);
        cout<<g<<endl;
        return g>=2;
    }
};