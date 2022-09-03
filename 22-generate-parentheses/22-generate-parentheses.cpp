class Solution {
public:
    vector<string> ans;
    void G(int &n, int open, int close, string s)
    {
        if(s.size()==n*2)
        {
            ans.push_back(s);
            return;
        }
        if(open<n)
        {
            s+="(";
            G(n,open+1,close,s);
            s = s.substr(0,s.size()-1);
        }
        if(close<open)
        {
            s+=")";
            G(n,open,close+1,s);
            s = s.substr(0,s.size()-1);
            
        }
    }
    vector<string> generateParenthesis(int n) {
        G(n,0,0,"");
        return ans;
    }
};