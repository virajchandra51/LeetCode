class Solution {
public:
    vector<string> ans;
    set<string> st;
    void helper(string s, int i, string curr, vector<string> a)
    {
        if(i>=s.size())
        {
            if(curr.size()!=0) return;
            if(a.size()==0)
            {
                if(st.find(curr)!=st.end())
                    ans.push_back(curr);
                return;
            }
            else {
            string t = "";
            for(int j=0;j<a.size()-1;j++)
                t= t+ (a[j]+" ");
            t+=a[a.size()-1];
            ans.push_back(t);}
            return;
        }
        curr+=s[i];
        helper(s,i+1,curr,a);
        if(st.find(curr)!=st.end())
        {
            a.push_back(curr);
            helper(s,i+1,"",a);
            a.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto it:wordDict) st.insert(it);
        vector<string> a;
        helper(s,0,"",a);
        return ans;
    }   
};