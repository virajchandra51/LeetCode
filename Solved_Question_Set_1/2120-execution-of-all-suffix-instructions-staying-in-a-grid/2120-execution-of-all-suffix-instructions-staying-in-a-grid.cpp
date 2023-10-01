class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> v;
        for(int i=0;i<s.size();i++)
        {
            int c=0; int x = startPos[0], y = startPos[1];
            for(int j=i;j<s.size();j++)
            {
                if(s[j]=='R')
                {
                    if(y+1<n)
                    {
                        y++;c++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(s[j]=='L')
                {
                    if(y-1>=0)
                    {
                        y--;c++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(s[j]=='U')
                {
                    if(x-1>=0)
                    {
                        x--;c++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(s[j]=='D')
                {
                    if(x+1<n)
                    {
                        x++;c++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            v.push_back(c);
        }
        return v;
    }
};