class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int count = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push(s[i]); // If I have a '(' store it
            else
            {
                if(i+1<s.size() && s[i+1]==')')
                {
                    if(st.size()>0)
                    {
                        st.pop();
                    }
                    else
                    {
                        count++;
                    }
                    i++;
                }
                else 
                {
                    if(st.size()>0)
                    {
                        st.pop();
                    }
                    else
                    {
                        count++;
                    }
                    count++;
                }
            }
        }
        count+=(2*st.size());
        return count;
    }
};