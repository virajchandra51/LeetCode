class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        map<char,int> m1,m2;
        for(auto it:word1)
            m1[it]++;
        for(auto it:word2)
            m2[it]++;
        for(auto it:m1)
        {
            if(m2.find(it.first)!=m2.end() && abs(m2[it.first]-it.second)<=3)
                continue;
            else if(it.second<=3)
                continue;
            else
                return false;
        }
        for(auto it:m2)
        {
            if(m1.find(it.first)!=m1.end() && abs(m1[it.first]-it.second)<=3)
                continue;
            else if(it.second<=3)
                continue;
            else
                return false;
        }
            return true;
    }
};