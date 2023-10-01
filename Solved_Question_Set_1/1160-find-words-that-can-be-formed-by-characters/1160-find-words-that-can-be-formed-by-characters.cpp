class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum=0;
        map<char,int> mp;
        for(auto it:chars)
            mp[it]++;
        for(auto it:words)
        {
            map<char,int> m;
            for(auto i:it)
                m[i]++;
            int f=1;
            for(auto i:m)
            {
                if(mp.find(i.first)!=mp.end() && mp[i.first]>=i.second)
                    continue;
                else
                {
                    f=0;break;
                }  
            }
            if(f)
                sum+=it.size();
        }
        return sum;
    }
};