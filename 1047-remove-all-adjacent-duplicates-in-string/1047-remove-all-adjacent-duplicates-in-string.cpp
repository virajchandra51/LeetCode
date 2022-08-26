class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> ss;
        for(auto it:s)
        {
            if(ss.size()<1)
                ss.push(it);
            else
            {
                if(ss.top()==it)
                    ss.pop();
                else
                    ss.push(it);
            }
        }
        string w="";
        while(!ss.empty())
        {
            w+=ss.top();
            ss.pop();
        }
        reverse(w.begin(),w.end());
        return w;
    }
};