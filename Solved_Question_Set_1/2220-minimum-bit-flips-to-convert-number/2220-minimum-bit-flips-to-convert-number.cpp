class Solution {
public:
    int minBitFlips(int start, int goal) {
        int c=0;
        while(goal>0 || start>0)
        {
            c+=((goal&1)^(start&1));
            goal/=2;
            start/=2;
        }
        return c;
    }
};