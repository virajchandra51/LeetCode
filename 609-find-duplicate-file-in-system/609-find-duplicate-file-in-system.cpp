class Solution {
public:
    map<string,vector<string>> mp;
    void extractContent(string s)
    {
        string r="";
        s+=" ";        
        string w="";
        for(auto it:s)
        {
            if(it!=' ')
                w+=it;
            else
            {
                r=w;
                w="";
                break;
            }
        }
        for(auto it:s)
        {
            if(it!=' ')
                w+=it;
            else
            {
                if(w==r)
                {
                    w="";
                    continue;
                }
                string ans=""; int id=-1;
                for(int i=0;i<w.size();i++)
                {
                    if(w[i]=='.')
                    {
                        id=i;
                        ans=w.substr(i+4);
                        break;
                    }
                }
                mp[ans].push_back(r+"/"+w.substr(0,id+4));
                w="";
            }
        }        
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        for(auto it:paths)
            extractContent(it);
        vector<vector<string>> v;
        for(auto it:mp)
        {
            if(it.second.size()>1)
                v.push_back(it.second);
        }
        return v;
    }
};