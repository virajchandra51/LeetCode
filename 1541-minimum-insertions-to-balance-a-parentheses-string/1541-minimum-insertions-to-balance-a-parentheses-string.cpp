class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int count = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push(s[i]);
            else
            {
                if(i+1<s.size() && s[i+1]==')')
                    i++;
                else count++;
                if(st.size()>0) st.pop();
                else
                {
                    count++;
                }
            }
        }
        count+=(2*st.size());
        return count;
    }
};