typedef long long ll;
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<ll,ll>> v(n);
        for(int i=0;i<n;i++)
            v[i]={nums[i],cost[i]};
        sort(v.begin(),v.end());
        ll s1 = 0;
        for(auto it:v) s1+=(it.first*it.second);
        vector<ll> sufs(n);
        vector<ll> pres(n);
        pres[0]=0;
        for(int i=1;i<n;i++)
            pres[i]=pres[i-1]+v[i-1].second;
        sufs[n-1] = v[n-1].second;
        for(int i=n-2;i>=0;i--)
            sufs[i] = sufs[i+1]+v[i].second;
        ll s2 = -1*v[0].first*sufs[0];
        // for(auto it:v) cout<<it.first<<" "<<it.second<<endl;
        // cout<<s1<<" "<<s2<<endl;
        ll ans = s1+s2;
        // cout<<ans<<endl;
        // 1 2 3 5
        // 2 14 3 1
        for(int i=1;i<n;i++)
        {
            s1 -= ((v[i-1].first*pres[i]));
            // cout<<s1<<" h"<<endl;
            s1 += ((v[i].first*pres[i]));
            // cout<<s1<<" hh"<<endl;
            s2 += (v[i-1].first*(sufs[i]));
            s2 += (-1*v[i].first*(sufs[i]));
            ans = min(ans,s1+s2);
            // cout<<s1<<" "<<s2<<endl;
            // cout<<ans<<endl;
        }
        return ans;
    }
};