class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a,b;
        for(auto it:s)
        {
            if(it!='#')
                a.push(it);
            else
            {
                if(!a.empty())
                a.pop();
            }
        }
        for(auto it:t)
        {
            if(it!='#')
                b.push(it);
            else
            {
                if(!b.empty())
                b.pop();
            }
        }
        return a==b;
    }
};