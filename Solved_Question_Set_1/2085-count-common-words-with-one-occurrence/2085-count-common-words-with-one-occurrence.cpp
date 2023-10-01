class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int> m1,m2;
        unordered_set<string> s;
        for(auto it:words1)
            m1[it]++;
        for(auto it:words2)
            m2[it]++;
        for(auto it:m1)
        {
            if(it.second==1 && m2[it.first]==1)
                s.insert(it.first);
        }
        for(auto it:m2)
        {
            if(it.second==1 && m1[it.first]==1 && s.find(it.first)==s.end())
                s.insert(it.first);
        }
        return s.size();
    }
};