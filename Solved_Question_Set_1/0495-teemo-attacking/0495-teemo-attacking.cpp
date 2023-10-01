class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        sort(t.begin(),t.end());
        int c=0;
        if(t.size()==1)
        {
            return d;
        }
        for(int i=1;i<t.size();i++)
        {
            if((t[i-1]+d-1)<t[i])
            {
                c+=d;
            }
            else
            {
                c+=(t[i]-t[i-1]);
            }
        }
        return c+d;
    }
};