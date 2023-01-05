class Solution {
public:
    //[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
    
    // 1 2 3 4 5 6 7 8 9 10
    //     3 4 5 6 7 8 9
    //       4 5 6 7 8 9 10 11
    //           6 7
    //           6 7 8 9
    //               8 9 10 11 12
    //                 9 10 11 12
    
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        for(auto it:p)
            cout<<it[0]<<" "<<it[1]<<endl;
        int n = p.size();
        if(n==1) return 1;
        int l = 0; int r = 1;
        int mn = p[0][1];
        int c = 1;
        while(r<n)
        {
            if(p[r][0]<=mn)
            {
                mn=min(mn,p[r][1]);
                r++;continue;
            }
            else
            {
                c++;
                l=r;
                mn=p[l][1];
                r++;
            }
        }
        return c;
    }
};