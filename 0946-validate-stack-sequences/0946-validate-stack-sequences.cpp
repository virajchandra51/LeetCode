class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        reverse(popped.begin(),popped.end());
        stack<int> s,p;
        for(auto &it:popped) s.push(it);
        int i=0;
        while(i<pushed.size())
        {
            if(i<pushed.size() && p.empty()==true)
            {
                p.push(pushed[i]);
                i++;
            }
            else if(i<pushed.size() && p.empty()==false)
            {
                while(i<pushed.size() && p.top()!=s.top())
                {
                    p.push(pushed[i]);
                    i++;
                }
                while(p.empty()==false && p.top()==s.top())
                {
                    p.pop();
                    s.pop();
                }
            }
        }
        while(p.empty()==false && p.top()==s.top())
        {
            p.pop();
            s.pop();
        }
        if(i==pushed.size() && s.empty()==false) return false;
        return true;
    }
};