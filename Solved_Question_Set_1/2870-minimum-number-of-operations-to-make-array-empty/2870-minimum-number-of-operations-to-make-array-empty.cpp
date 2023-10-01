class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums) m[it]++;
        int c = 0;
        for(auto it:m)
        {
            if(it.second==1) return -1;
            if(it.second%3==0) c+=it.second/3;
            else if(it.second%3==1)
            {
                c+=(it.second-4)/3;
                c+=2;
            }
            else
            {
                c+=(it.second-2)/3;
                c++;
            }
        }
        return c;
    }
};