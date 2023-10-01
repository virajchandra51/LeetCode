class Solution {
public:
    vector<int>ans;
    long long int si=INT_MAX;
    vector<vector<long long int>>dp;
    long long int helper(vector<int>&arr, long long &target, long long int curr, long long int i, long long int &size){
        if(i>=size){
            if(curr==target)return 0;
            else{
                long long int aa=target;
                aa<<=1;
                aa|=1;
                return aa;
            }
        }
        if(dp[curr][i]!=-1)return dp[curr][i];
        long long int nottake=helper(arr, target, curr, i+1, size);
        long long int take=(((long long int)1<<i)|helper(arr, target, curr|arr[i], i+1, size));
        long long int ans;
        if(__builtin_popcountll(take)<=__builtin_popcountll(nottake))ans=take;
        else ans=nottake;
        return dp[curr][i]=ans;
    }
    vector<int> smallestSufficientTeam(vector<string>& r, vector<vector<string>>& people) {
        map<string, int>m;
        int n=r.size();
        for(int i=0;i<n;i++)m[r[i]]=i;
        long long int mm=people.size();
        vector<int>arr;
        for(auto it:people){
            long long int a=0;
            for(auto i:it){
                a|=(1<<m[i]);
            }
            arr.push_back(a);
        }
        // for(int it:arr)cout<<it<<" ";
        // cout<<endl;
        long long target=1<<n;
        target--;
        dp.resize(target+1,vector<long long int>(mm+1,-1));
        long long int temp=helper(arr, target, (long long int)0, (long long int)0, mm);
        int i=0;
        // cout<<temp<<endl;
        while(temp){
            if(temp&1)ans.push_back(i);
            temp>>=1;
            i++;
        }
        return ans;
    }
};
