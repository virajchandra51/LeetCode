class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> m1,m2;
        vector<string> ans;
        s1+=" ";
        s2+=" ";
        string w="";
        for(auto it:s1)
        {
            if(it!=' ')
                w+=it;
            else
            {
                m1[w]++;
                w="";
            }
        }
        w="";
        for(auto it:s2)
        {
            if(it!=' ')
                w+=it;
            else
            {
                m2[w]++;
                w="";
            }
        }
        for(auto it:m1)
        {
            if(it.second==1 && m2.find(it.first)==m2.end())
                ans.push_back(it.first);
        }
        
        for(auto it:m2)
        {
            if(it.second==1 && m1.find(it.first)==m1.end())
                ans.push_back(it.first);
        }
        return ans;
    }
};
