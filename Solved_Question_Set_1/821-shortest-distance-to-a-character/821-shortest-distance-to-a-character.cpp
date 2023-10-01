class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> o;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]==c)
            o.push_back(i);
        }
        vector<int> res;
        for(int i=0;i<s.size();i++)
        {
            int m=INT_MAX;
            for(int j=0;j<o.size();j++)
                m=min(m,abs(i-o[j]));
            res.push_back(m);
        }
        return res;
    }
};