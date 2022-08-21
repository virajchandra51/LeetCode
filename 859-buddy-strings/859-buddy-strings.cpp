class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s==goal)
        {
            map<char,int> mp;
            for(auto it:s)
                mp[it]++;
            for(auto it:mp)
            {
                if(it.second>1)
                    return true;
            }
            return false;
        }
        else
        {
            if(s.size()!=goal.size())
                return false;
            else
            {
                int i1=-1,i2=-1;
                for(int i=0;i<s.size();i++)
                {
                    if(s[i]!=goal[i])
                    {
                        i1=i;break;
                    }
                }
                for(int i=0;i<s.size();i++)
                {
                    if(s[i]!=goal[i] && i!=i1)
                    {
                        i2=i;break;
                    }
                }
                if(i1!=-1 && i2!=-1)
                {
                    swap(s[i1],s[i2]);
                    if(s==goal)
                        return true;
                    else
                        return false;
                }
                else
                    return false;
            }
        }
    }
};