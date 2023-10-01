class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int c = 0;
        while(m!=n)
        {
            c++;
            m>>=1;
            n>>=1;
        }
        return m<<c;
    }
};