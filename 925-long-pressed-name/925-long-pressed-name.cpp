class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        string s="";
        vector<pair<char,int>> v,d;
        
        int j=0; int c=0;
        for(int i=0;i<name.size();i++)
        {
            if(name[i]==name[j])
            {
                c++;
            }
            else
            {
                j=i;
                v.push_back({name[i-1],c});
                c=1;
            }
        }
        v.push_back({name[name.size()-1],c});
        j=0,c=0;
        for(int i=0;i<typed.size();i++)
        {
            if(typed[i]==typed[j])
            {
                c++;
            }
            else
            {
                j=i;
                d.push_back({typed[i-1],c});
                c=1;
            }
        }
        d.push_back({typed[typed.size()-1],c});
        if(v.size()!=d.size())
            return false;
        else
        {
            for(int i=0;i<v.size();i++)
            {
                if(d[i].second<v[i].second || d[i].first!=v[i].first)
                    return false;
            }
            return true;
        }
        return true;
    }
};