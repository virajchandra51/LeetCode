class Solution {
public:
    string getHint(string s, string g) {
        map<int,int> m1,m2;
        int c = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==g[i]) c++;
            else {
                m1[s[i]-'0']++;
                m2[g[i]-'0']++;
            }
        }
        int cc = 0;
        for(auto it:m1)
        {
            if(m2.find(it.first)!=m2.end())
                cc+=min(m2[it.first],it.second);
        }
        string ans = to_string(c);
        ans+="A";
        ans+=to_string(cc);
        ans+="B";
        return ans;
    }
};