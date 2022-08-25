class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> v(words.size(),vector<int>(26,0));
        for(int i=0;i<words.size();i++)
        {
            for(auto it:words[i])
            {
                v[i][it-'a']++;
            }
        }
        vector<string> s;
        for(int i=0;i<26;i++)
        {
            int f=1; int m=INT_MAX;
            for(int j=0;j<v.size();j++)
            {
                if(v[j][i]==0)
                {
                    f=0;break;
                }
                m=min(m,v[j][i]);
            }
            if(f)
            {
                char ch = (char)(i+97);
                string w="";
                w+=ch;
                for(int k=1;k<=m;k++)
                {
                    s.push_back(w);
                }
            }
        }
        return s;
    }
};