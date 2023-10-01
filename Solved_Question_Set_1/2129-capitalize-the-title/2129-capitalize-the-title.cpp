class Solution {
public:
    string capitalizeTitle(string title) {
        title+=" ";
        string ans="";
        string w="";
        for(auto it:title)
        {
            if(it!=' ')
                w+=it;
            else
            {
                if(w.size()>2)
                {
                    transform(w.begin(),w.end(),w.begin(),::tolower);
                    ans+=(char(w[0]-32)+w.substr(1)+" ");
                }
                else
                {
                    transform(w.begin(),w.end(),w.begin(),::tolower);
                    ans+=(w+" ");
                }
                w="";
            }
        }
        return ans.substr(0,ans.size()-1);
    }
};