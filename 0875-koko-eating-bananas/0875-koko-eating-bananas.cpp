class Solution {
public:
    int check(int k,vector<int>& piles){
        int h = 0;
        for(auto it:piles)
            h+=(ceil(it*1.0/k));
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int high = piles[n-1];
        int low = 1;
        while(low<high)
        {
            int mid = (low+high)>>1;
            if(check(mid, piles)<=h)
                high=mid;        
            else
                low=mid+1;
        }
        return high;
    }
};