class Solution {
public:
    vector<string> v;
    void G(int &n, int open, int close, string s)
    {
        if(open==n && close==n)
        {
            v.push_back(s);
            return;
        }
        if(open<n)
            G(n,open+1,close,s+"(");
        if(close<open)
            G(n,open,close+1,s+")");
    }
    vector<string> generateParenthesis(int n) {
        G(n,0,0,"");
        return v;
    }
};