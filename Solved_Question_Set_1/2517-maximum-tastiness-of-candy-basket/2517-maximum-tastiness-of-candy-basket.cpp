class Solution {
public:
    int check(vector<int>& price, int mid)
    {
        int c = 1;
        int i = 0;
        int j = 1;
        while(j<price.size())
        {
            if((price[j]-price[i])<mid) j++;
            else
            {
                c++;
                i=j;
                j=i+1;
            }
        }
        return c;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n = price.size();
        int l = 0;
        int r = price[n-1]-price[0];
        int ans;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(check(price,mid)<k)
            {
                r=mid-1;
            }
            else
            {
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
};