class Solution {
public:
    string smallestSubsequence(string s) {
        map<char,int> mp;
        for(auto it:s)
            mp[it]++;
        stack<char> ss;
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]--;
            if(v[s[i]-'a']++>0)
                continue;
            while(!ss.empty() && ss.top()>s[i] && mp[ss.top()]>0)
            {
                v[ss.top()-'a']=0;
                ss.pop();
            }
            ss.push(s[i]);    
        }
        string ans="";
        while(!ss.empty())
        {
            ans+=ss.top();
            ss.pop();
        }
        reverse(ans.begin(),ans.end());
        
        
        return ans;
    }
};