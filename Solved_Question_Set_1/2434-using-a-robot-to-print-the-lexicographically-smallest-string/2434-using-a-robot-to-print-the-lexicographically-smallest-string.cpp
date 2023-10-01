class Solution {
public:
    string robotWithString(string s) {
        multiset<char> m;
        for(auto it:s)
            m.insert(it);
        stack<char> st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            m.erase(m.find(s[i]));            
            st.push(s[i]);
            while(st.empty()==false && st.top()<=(*m.begin()))
            ans+=st.top(),st.pop();
        }
        while(!st.empty())
            ans+=st.top(),st.pop();
        return ans;
    }
};