class Solution {
public:
    int countAsterisks(string s) {
        vector<int> v;
        v.push_back(0);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='|')
                v.push_back(i);
        }
        v.push_back(s.size()-1);
        int c=0;
        for(int i=0;i<v.size();i+=2)
        {
            for(int j=v[i];j<=v[i+1];j++)
            {
                if(s[j]=='*')
                    c++;
            }
        }
        return c;
    }
};