class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n,vector<int>(n,-1));
        int tm=0;
        int bm=n-1;
        int lm=0;
        int rm=n-1;
        int k=1;
        while(true)
        {
            if(tm>bm) break;
            for(int i=lm;i<=rm;i++)
                a[tm][i]=pow(k++,1);
            if(tm>=bm) break;
            tm++;
            for(int i=tm;i<=bm;i++)
                a[i][rm]=pow(k++,1);
            rm--;
            if(lm>rm) break;
            for(int i=rm;i>=lm;i--)
                a[bm][i]=pow(k++,1);
            bm--;
            for(int i=bm;i>=tm;i--)
                a[i][lm]=pow(k++,1);
            if(lm>=rm) break;
            lm++;
        }
        return a;
    }
};