class Solution {
public:
    int binaryGap(int n) {
        int d=0; vector<int> v; int i=0;
        while(n>0)
        {
            if(n&1)
            {
                v.push_back(i);
            }
            i++;
            n/=2;
        }
        for(int i=0;i<v.size()-1;i++)
        {
            d=max(d,v[i+1]-v[i]);
        }
        return d;
    }
};