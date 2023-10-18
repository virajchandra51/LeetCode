class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int l) {
        sort(tiles.begin(),tiles.end());
        int n = tiles.size();
        vector<int> v(n);
        v[0] = tiles[0][1]-tiles[0][0]+1;
        for(int i=1;i<n;i++) 
            v[i] = v[i-1]+(tiles[i][1]-tiles[i][0]+1);
        for(auto it:v) cout<<it<<" ";
        cout<<endl;
        vector<int> a(n);
        for(int i=0;i<n;i++) 
            a[i] = tiles[i][1];
        int m = -1;
        for(int i=0;i<n;i++)
        {
            auto it = lower_bound(a.begin(),a.end(),tiles[i][0]+l)-a.begin();
            if(i==0)
            {
                int ss;
                if(it!=n)
                {
                    ss = v[it];
                    if(tiles[it][0]>(tiles[i][0]+l-1))
                    {
                        ss-=(tiles[it][1]-tiles[it][0]+1);
                    }
                    else
                    {
                        ss-=(tiles[it][1]-(tiles[i][0]+l-1));
                    }
                }
                else
                {
                    ss = v[n-1];
                }
                cout<<ss<<endl;
                m=max(m,ss);
            }
            else
            {
                int ss;
                if(it!=n)
                {
                    ss = v[it]-v[i-1];
                    if(tiles[it][0]>(tiles[i][0]+l-1))
                    {
                        ss-=(tiles[it][1]-tiles[it][0]+1);
                    }
                    else
                    {
                        ss-=(tiles[it][1]-(tiles[i][0]+l-1));
                    }
                }
                else
                {
                    ss = v[n-1]-v[i-1];
                }
                cout<<ss<<endl;
                m=max(m,ss);
            }
        }
        return m;
    }
};