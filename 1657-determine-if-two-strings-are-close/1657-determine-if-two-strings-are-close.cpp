class Solution {
public:
    bool closeStrings(string w1, string w2) {
        set<char> s1,s2;
        for(auto it:w1) s1.insert(it);
        for(auto it:w2) s2.insert(it);
        map<char,int> m1,m2; map<int,int> m3,m4;
        for(auto it:w1) m1[it]++;
        for(auto it:w2) m2[it]++;
        for(auto it:m1) m3[it.second]++;
        for(auto it:m2) m4[it.second]++;
        if(m3==m4 && s1==s2) return true;
        return false;
    }
};