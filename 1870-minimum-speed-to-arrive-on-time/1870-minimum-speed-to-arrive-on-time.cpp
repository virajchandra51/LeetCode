class Solution {
public:
    double check(int mid, vector<int>& dis, int n)
    {
        double c = 0.0;
        for(int i=0;i<n-1;i++)
        {
            c+=(ceil(dis[i]*1.0/mid*1.0));
        }
        c+=((dis[n-1]*1.0/mid*1.0));
        return c;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour<n-1) return -1;
        int l = 1;
        int r = 1e9;
        int ans;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(check(mid,dist,n)<=hour)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};