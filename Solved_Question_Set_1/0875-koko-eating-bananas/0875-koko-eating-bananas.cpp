class Solution {
public:
    long long check(long k,vector<int>& piles){
        long long h = 0;
        for(auto it:piles)
        {
            long long v = it;
            h+=(ceil(v*1.0/k));
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int high = piles[n-1];
        int low = 1;
        int ans;
        while(low<=high)
        {
            long mid = (low+high)>>1;
            // cout<<mid<<endl;
            if(check(mid, piles)<=h)
            {
                ans = mid;
                high = mid-1;
            }       
            else
            {
                low=mid+1;
            } 
        }
        return ans;
    }
};