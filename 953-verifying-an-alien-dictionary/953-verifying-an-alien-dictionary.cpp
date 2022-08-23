class Solution {
public:
    bool isL(string& a,string& b,map<char,int> &mp)
    {
        int i=0,j=0;
        while(i<a.size() && j<b.size())
        {
            if(mp[a[i]]<mp[b[j]])
                return true;
            else if(mp[a[i]]==mp[b[i]])
            {
                i++;j++;
            }
            if(mp[a[i]]>mp[b[j]])
                return false;
        }
        cout<<i<<endl;
        return i==a.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> mp;
        for(int i=0;i<order.size();i++)
            mp[order[i]]=i+1;
        for(int i=0;i<words.size()-1;i++)
        {
            if(isL(words[i],words[i+1],mp)==false)
                return false;
        }
        return true;
    }
};