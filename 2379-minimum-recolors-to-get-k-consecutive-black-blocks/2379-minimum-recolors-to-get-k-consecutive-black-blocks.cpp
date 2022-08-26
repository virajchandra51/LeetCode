class Solution {
public:
    int c(string s)
    {
        int cc=0;
        for(auto it:s)
        {
            if(it=='W')
                cc++;
        }
        return cc;
    }
    int minimumRecolors(string blocks, int k) {
        int m=INT_MAX;
        for(int i=0;i<blocks.size()-k+1;i++)
        m=min(m,c(blocks.substr(i,k)));
        return m;
    }
};