class Solution {
public:
    string decodeString(string s) {
        stack<int> c;
        stack<char> w;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==']')
            {
                string t ="";
                string a ="";
                int num = c.top();
                c.pop();
                while(w.top()!='[')
                {
                    t+=w.top();
                    w.pop();
                }
                w.pop();
                reverse(t.begin(),t.end());
                for(int j=1;j<=num;j++)
                    a+=t;
                for(int j=0;j<a.size();j++)
                    w.push(a[j]);
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                int cc=0;
                while(s[i]!='[')
                    cc=cc*10+(s[i]-'0'),i++;
                i--;
                c.push(cc);
            }
            else
                w.push(s[i]);       
        }
        string ans="";
        while(!w.empty())
            ans+=w.top(),w.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};