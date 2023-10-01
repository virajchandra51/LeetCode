class Solution {
public:
    int brokenCalc(int n, int t) {
        int a = 0;
        while(t>n)
        {
            if(t&1) t+=1;
            else t/=2;
            a++;
        }
        return a+n-t;
    }
};