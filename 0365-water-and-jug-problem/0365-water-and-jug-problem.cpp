class Solution {
public:
    bool canMeasureWater(int j1, int j2, int t) {
        if(j1+j2<t)
            return false;
        if(t%__gcd(j1,j2)==0) return true;
        return false;
    }
};