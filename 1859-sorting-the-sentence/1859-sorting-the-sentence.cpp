class Solution {
public:
    string sortSentence(string s) {
        map<int,string> mp;
        string w="";
        s+=' ';
        for(auto it:s)
        {
            if(it!=' ')
                w+=it;
            else
            {
                mp[w[w.size()-1]-48] = w.substr(0,w.size()-1);
                w="";
            }
        }
        s="";
        for(auto it:mp)
            s+=(it.second+" ");
        return s.substr(0,s.size()-1);
    }
};