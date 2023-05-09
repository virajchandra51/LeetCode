class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ans;
        int n = a.size();
        int m = a[0].size();
        int tm=0;
        int bm=n-1;
        int lm=0;
        int rm=m-1;
        while(true)
        {
            if(tm>bm) break;
            for(int i=lm;i<=rm;i++)
                ans.push_back(a[tm][i]);
            if(tm>=bm) break;
            tm++;
            for(int i=tm;i<=bm;i++)
                ans.push_back(a[i][rm]);
            rm--;
            if(lm>rm) break;
            for(int i=rm;i>=lm;i--)
                ans.push_back(a[bm][i]);
            bm--;
            // if(tm>=bm) break;
            for(int i=bm;i>=tm;i--)
                ans.push_back(a[i][lm]);
            if(lm>=rm) break;
            lm++;
        }
        // while(n*m-ans.size()!=0) ans.pop_back();
        return ans;
    }
};