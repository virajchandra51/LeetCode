class Solution {
public:
    string makeFancyString(string s) {
        int c=1;
        stack<char> ss;
        ss.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            char it = s[i];
            if(it==ss.top() && c>=2)
                continue;
            else if(it!=ss.top())
            {
                ss.push(it);c=1;
            }
            else
            {
                ss.push(it);
                c++;
            }
        }
        s="";
        while(!ss.empty())
        {
            s+=(ss.top());
            ss.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};