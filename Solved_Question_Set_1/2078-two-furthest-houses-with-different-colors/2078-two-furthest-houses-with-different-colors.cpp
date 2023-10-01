class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int d=-1;
        for(int i=0;i<colors.size();i++)
        {
            for(int j=i;j<colors.size();j++)
            {
                if(colors[j]!=colors[i])
                {
                    d=max(d,abs(i-j));
                }
            }
        }
        return d;
    }
};