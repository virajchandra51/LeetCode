class Solution {
public:
    int minimumRounds(vector<int>& t) {
        map<int,int> mp;
        for(auto it: t) mp[it]++;
        int a=0;
        for(auto it: mp)
        {
            if(it.second==1) return -1;
            if(it.second%3==0) a+=(it.second/3);
            if(it.second%3==1) a+=((it.second-4)/3+2);
            if(it.second%3==2) a+=((it.second-2)/3+1);
        }
        return a;
    }
};