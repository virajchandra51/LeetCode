class Solution {
public:
    int countCollisions(string directions) {
        stack<char> s;
        int c = 0;
        for(int i=0;i<directions.size()-1;i++)
        {
            if(directions[i]=='R' && directions[i+1]=='L')
            {
                c+=2;
                directions[i]='S';
                directions[i+1]='S';
            }
        }
        for(auto it:directions)
        {
            if(s.empty()) s.push(it);
            else if(it=='S')
            {
                int cc = 0;
                while(!s.empty() && s.top()=='R')
                {
                    s.pop();
                    cc++;
                    c++;
                }
                for(int i=0;i<=cc;i++) s.push('S');
            }
            else if(it=='R') s.push(it);
            else 
            {
                if(s.top()=='S')
                {
                    s.pop();
                    c++;
                    s.push('S');
                    s.push('S');
                }
            }
        }
        return c;
    }
};