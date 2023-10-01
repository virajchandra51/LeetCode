class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end(),greater<int>());
        int sum=0;
        while(amount[0]>0 && amount[1]>0)
        {
            sum++;
            amount[0]--;
            amount[1]--;
            sort(amount.begin(),amount.end(),greater<int>());
        }
        return sum+amount[0];
    }
};