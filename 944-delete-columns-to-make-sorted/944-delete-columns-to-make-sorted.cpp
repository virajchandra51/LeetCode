class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int c=0;
        for(int i=0;i<strs[0].size();i++)
        {
            string s="";
            for(int j=0;j<strs.size();j++)
            {
                s+=strs[j][i];
            }
            string w=s;
            sort(w.begin(),w.end());
            if(w==s)
                c++;   
        }
        return strs[0].size()-c;
    }
};