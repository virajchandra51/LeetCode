class Solution {
public:
    string convert(string s, int numsRows) {
        if(numsRows==1)
            return s;
        vector<string> rows(min(numsRows,(int)s.size()));
        int c = 0;
        bool goingDown = false; int i=0;
        while(i<s.size())
        {
            rows[c]+=s[i];
            i++;
            if(c==0 || c==(numsRows-1)) goingDown=!goingDown;
            c = c + (goingDown ? 1 : -1);
        }
        string ans="";
        for(auto it:rows)
            ans+=it;
        return ans;
    }
};