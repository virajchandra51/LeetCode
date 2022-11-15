class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        for(auto it:a)
        {
            s.push(it);
            while(s.size()>1 && it<0 && s.top()==it)
            {
                int n = s.top();
                s.pop();
                int nn = s.top();
                s.pop();
                if(nn<0)
                {
                    s.push(nn);
                    s.push(n);
                    break;
                }
                if(abs(n)>nn)
                    s.push(n);
                else if(abs(n)==nn)
                {}
                 else s.push(nn);
            }
        }
        vector<int> ans;
        while(!s.empty())
            ans.push_back(s.top()),s.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};