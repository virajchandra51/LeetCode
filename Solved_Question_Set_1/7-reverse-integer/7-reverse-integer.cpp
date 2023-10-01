class Solution {
public:
    int reverse(int x) {
        int m = INT_MAX;
        int mm = INT_MIN;
        int f=1;
        if(x<0)
            f=0;
        string xx = to_string(x);
        std::reverse(xx.begin(),xx.end());
        long long s = stol(xx);
        if(f==0)
            s*=-1;
        if(s>m || s<mm)
            return 0;
        else
            return s;
    }
};