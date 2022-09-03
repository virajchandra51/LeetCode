class Solution {
public:
    vector<string> ans;
    void G(int &n, int open, int close, string s)
    {
        if(open==n && close==n)
        {
            ans.push_back(s);
            return;
        }
        if(open<n)
        {
            s+="(";
            G(n,open+1,close,s);
            s.pop_back();
        }
        if(close<open)
        {
            s+=")";
            G(n,open,close+1,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        G(n,0,0,"");
        return ans;
    }
};