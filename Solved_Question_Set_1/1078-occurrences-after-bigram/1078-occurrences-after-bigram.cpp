class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        text+=" "; string w="";
        vector<string> v,ans;
        for(auto it:text)
        {
            if(it!=' ')
                w+=it;
            else{
                v.push_back(w);
                w="";
            }
        }
        for(int i=2;i<v.size();i++)
        {
            if(v[i-2]==first && v[i-1]==second)
                ans.push_back(v[i]);
        }
        return ans;
    }
};