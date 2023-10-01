class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        map<int,int> m;
        for(auto it:bookings)
        {
            m[it[0]]+=it[2];
            m[it[1]+1]-=it[2];
        }
        vector<int> ans(n);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=m[i+1];
            ans[i]=sum;
        }
        return ans;
    }
};