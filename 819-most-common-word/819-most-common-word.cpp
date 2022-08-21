class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(),::tolower);
        paragraph+=' ';
        string w="";
        map<string,int> mp;
        for(auto it: paragraph)
        {
            if(it>='a' && it<='z')
                w+=it;
            else
            {
                if(w!="")
                mp[w]++;
                w="";
            }
        }
        for(auto i:mp)
            cout<<i.first<<" "<<i.second<<endl;
        set<string> ss;
        for(auto it:banned)
            ss.insert(it);
        string s =""; int f=-1;
        for(auto it: mp)
        {
            if(it.second>=f && ss.find(it.first)==ss.end())
            {
                f=it.second;
                s=it.first;
            }
        }
        return s;
    }
};