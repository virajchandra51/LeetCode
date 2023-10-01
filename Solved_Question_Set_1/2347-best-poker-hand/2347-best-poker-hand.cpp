class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<char,int> s;
        for(auto it:suits)
            s[it]++;
        if(s.size()==1)
            return "Flush";
        map<int,int> r;
        for(auto it:ranks)
            r[it]++;
        for(auto it:r)
        {
            if(it.second>2)
                return "Three of a Kind";
        }
        for(auto it:r)
        {
            if(it.second>1)
                return "Pair";
        }
        return "High Card";
        
    }
};