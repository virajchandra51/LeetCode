class Solution {
public:
    int sumBase(int n, int k) {
        int s=0;
        while(n>0)
        {
            int d = n%k;
            s+=(d);
            n=n/k;
        }
        return s;
    }
};